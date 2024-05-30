#pragma once
#include "DxLib.h"

class Player;
class Enemy;

class Collision
{
public:
	Collision();
	~Collision();
	
	void HitPlayerToEnemy(Player& player, Enemy& enemy);
	const float OBJECT_HIT_BUF = 0.5f;

private:



};







