#include "Enemy.h"
#include "YSpeedBullet.h"
#include "Bullet.h"

class SpreadEnemy : public Enemy{

public:

	SpreadEnemy(int,int,float,float,float);
	
	//void Draw();
	void Update(std::vector<Bullet*>&, Player& player, GameTimer);

protected:

	void Shoot(std::vector<Bullet*>&, GameTimer&);


};