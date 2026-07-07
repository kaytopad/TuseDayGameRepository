#include <iostream>
#include "20260707_Header1_imai.h"
using namespace std;

void AddArray(int ary[], int size)
{
	//変数宣言
	int i;
	//10個数値を入力
	for ( i = 0; i < size; i++)
	{
		//入力チェック関数を呼び出し入力する
		ary[i] = InputCheck(MIN, MAX);
	}

}

int InputCheck(int min, int max)
{
	int num;

	while (true)
	{
		cin >> num;
		if (min > num || max < num)
		{
			cout << "入力した値に誤りがあります。再度入力してください\n";
		}
		else
		{
			break;
		}

	}
	return num;
}