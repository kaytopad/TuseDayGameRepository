#pragma once
class Example
{
public:
	//持っているデータ
	int hp;
	int playerX, playerY;
	int attack;

	//プレイヤーができること
	void Move();
	void Attack();
	void Damage(int damage);
	void ShowStatus();


};

