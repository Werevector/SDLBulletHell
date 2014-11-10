#pragma once
#include "Bullet.h"

class PlayerBulletA : public Bullet{


public:
	PlayerBulletA(float, float, float, float);
	void Draw();
	void Update(GameTimer&);

protected:

};