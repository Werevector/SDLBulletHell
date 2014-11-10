#include "BulletHandler.h"

BulletHandler::BulletHandler(){

}

void BulletHandler::RenderBullets(){
	
	for(int i = 0; i < enemyBulletVector.size(); i++){
			enemyBulletVector[i]->Draw();
	}

	for(int i = 0; i < playerBulletVector.size(); i++){
			playerBulletVector[i]->Draw();
	}

}

void BulletHandler::UpdateBullets(GameTimer& gTimer){

	for(int i = 0; i < enemyBulletVector.size(); i++){
			enemyBulletVector[i]->Update(gTimer);
			
			if(enemyBulletVector[i]->isOutsideBounds()){
				enemyBulletVector.erase(enemyBulletVector.begin() + i);
			}
	}

	for(int i = 0; i < playerBulletVector.size(); i++){
			playerBulletVector[i]->Update(gTimer);
			
			if(playerBulletVector[i]->isOutsideBounds()){
				playerBulletVector.erase(playerBulletVector.begin() + i);
			}
	}

	std::cout << "  " << enemyBulletVector.size();
	std::cout << "  " << playerBulletVector.size() << "\n";
}

void BulletHandler::AddShotBullet(Bullet bullet){
}

std::vector<Bullet*>& BulletHandler::GetBulletPointers(){
	return enemyBulletVector;
}

std::vector<Bullet*>& BulletHandler::GetPlayerBulletPointers(){
	return playerBulletVector;
}