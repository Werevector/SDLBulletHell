#include "Player.h";

Player::Player(){
	
	pTexture.loadFromFile("Textures\\PlayerFairy.png");

	playerPositionX = Graphics::SCREEN_WIDTH/2;
	playerPositionY = Graphics::SCREEN_HEIGHT/1.5;
	
	hitboxSize = 5;
	
	hitbox.x = playerPositionX;
	hitbox.y = playerPositionY;
	hitbox.h = hitboxSize;
	hitbox.w = hitboxSize;

	renderQuad.h = 60;
	renderQuad.w = 60;

	playerSpeed = 150;

	isDead = false;

	lastShot = 0;

}

void Player::Update(GameTimer& pTimer, std::vector<Bullet*>& playerBulletVectors){
	if(!isDead){	
		HandleMovement(pTimer.DeltaTime());
	
		if(shoot&&lastShot==0){
			Shoot(playerBulletVectors, pTimer);
		}
		lastShot++;
		if(lastShot>4){
			lastShot=0;
		}
	}
}

void Player::HandleMovement(float deltaTime) {
	
	//Checking for focus
	if(focus){
		playerSpeed = 150;
	}else{
		playerSpeed = 500;
	}

	//Creating vectors
	float VectorLength = 0;
	float vectorX = 0;
	float vectorY = 0;

	//Checking all the key flags
	if(mUpp && hitbox.y > 0){
		vectorY -= 1;
	}
	
	if(mDown && hitbox.y < (Graphics::SCREEN_HEIGHT - hitbox.h)){
		vectorY += 1;
	}
	
	if(mLeft && hitbox.x > 0){
		vectorX -= 1;
	}
	
	if(mRight && hitbox.x < (Graphics::SCREEN_WIDTH - hitbox.h)){
		vectorX += 1;
	}

	//Find vector length with pytagoras
	VectorLength = sqrt((vectorX * vectorX) + (vectorY * vectorY));
	
	
	//Normalise vectors
	if(VectorLength != 0){
		vectorX /= VectorLength;
		vectorY /= VectorLength;
	}

	//Update position
	playerPositionX += vectorX*playerSpeed*deltaTime;
	playerPositionY += vectorY*playerSpeed*deltaTime;

	hitbox.y = playerPositionY;
	hitbox.x = playerPositionX;
	
	//Reset
	ResetFlags();
	
}

void Player::Shoot(std::vector<Bullet*>& playerBulletVectors, GameTimer& pTime){
	
	//Insert bullets to vector
	playerBulletVectors.push_back(new PlayerBulletA( GetPlayerCenterX(), GetPlayerCenterY(), pTime.TotalTime(), 1.57));
	
}

void Player::Draw(){
	if(!isDead){

		pTexture.renderFromCenter(GetPlayerCenterX(), GetPlayerCenterY(), &renderQuad );

	}
}

void Player::ResetFlags(){
	mUpp=false;
	mDown=false;
	mLeft=false;
	mRight=false;
}

int Player::GetPlayerX(){
	return playerPositionX;
}

int Player::GetPlayerY(){
	return playerPositionY;
}

int Player::GetPlayerCenterX(){
	return (playerPositionX+(hitbox.w/2));
}

int Player::GetPlayerCenterY(){
	return (playerPositionY+(hitbox.h/2));
}

SDL_Rect Player::GetHitBox(){
	return hitbox;
}