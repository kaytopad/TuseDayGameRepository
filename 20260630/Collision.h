#pragma once
#include "Character.h"

class Collision
{
public:
	//====================================
	// 当たり判定
	//====================================
	static bool CheckHit(const Character& a,const Character& b);
	//====================================
	// 押し出し
	//====================================
	static void PushBack(Character& a,const Character& b);
};