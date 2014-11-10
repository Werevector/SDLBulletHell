#pragma once
#include "Bullet.h"

class YSpeedBullet : public Bullet{


public:
	YSpeedBullet(float, float, float, float);
	void Draw();
	void Update(GameTimer&);

protected:

};