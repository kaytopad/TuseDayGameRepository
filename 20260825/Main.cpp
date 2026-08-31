#include <iostream>
#include "Example.h"
#include "Dog.h"
using namespace std;

int main(void)
{
	cout << "犬の名前を入力してください\n";

	string dogName;

	cin >> dogName;

	
	Dog dog(dogName);

	dog.ShowProfile();

	//プレイヤークラスを実体化（インスタンス化）
	//Example example;

	//example.hp = 100;
	//example.attack = 20;
	//example.playerX = 0;
	//example.playerY = 0;
	//example.ShowStatus();

	//example.Move();
	//example.Attack();
	//example.Damage(30);

	//example.ShowStatus();

	return 0;
}