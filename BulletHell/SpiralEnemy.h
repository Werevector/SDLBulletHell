#include "Enemy.h"

class SpiralEnemy : public Enemy{

public:

	SpiralEnemy(int,int,float,float,float);
	void Shoot(std::vector<Bullet>&, GameTimer&);
	void Draw();
	void Update(GameTimer);

protected:

};