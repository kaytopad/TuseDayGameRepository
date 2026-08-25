#include <iostream>
#include "Example.h"
using namespace std;

void Example::Move()
{
	playerX += 10;
}

void Example::Attack()
{
	cout << "UŒ‚—Í:" << attack << "UŒ‚‚µ‚Ü‚µ‚½B\n";
}

void Example::Damage(int damage)
{
	hp -= damage;

	if (hp < 0)
	{
		hp = 0;
	}
}

void Example::ShowStatus()
{
	cout << "HP:" << hp << endl;
	cout << "Player,XÀ•W:" << playerX << endl;
	cout << "Player,YÀ•W:" << playerY << endl;
	cout << "UŒ‚—Í:" << attack << endl;
}