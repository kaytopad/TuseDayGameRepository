#include "Player.h"
#include "Config.h"
#include "Dxlib.h"

#include<cmath>
using namespace std;
//コンストラクタ
Player::Player() :x(0.0f), y(Config::PLAYER_HALF_SIZE), z(0.0f){}

//更新
void Player::Update(float deltaTime)
{
	float moveX = 0.0f;
	float moveZ = 0.0f;

	if (CheckHitKey(KEY_INPUT_W))moveZ += 1.0f;
	if (CheckHitKey(KEY_INPUT_S))moveZ -= 1.0f;
	if (CheckHitKey(KEY_INPUT_A))moveX -= 1.0f;
	if (CheckHitKey(KEY_INPUT_D))moveX += 1.0f;

	const float leagth = sqrt(moveX*moveX + moveZ*moveZ);

	if (leagth > 0.0f)
	{
		moveX /= leagth;
		moveZ /= leagth;

		x += moveX * Config::PLAYER_MOVE_SPEED * deltaTime;
		z += moveZ * Config::PLAYER_MOVE_SPEED * deltaTime;
	}

	const float limit = Config::FIELD_HALF_SIZE - Config::PLAYER_HALF_SIZE;

	if (x < -limit) x = -limit;
	if (x > limit) x = limit;
	if (z < -limit) z = -limit;
	if (z > limit) z = limit;

}


void Player::Draw() const
{
	const VECTOR minPos = VGet(x - Config::PLAYER_HALF_SIZE, y - Config::PLAYER_MOVE_SPEED, z - Config::PLAYER_HALF_SIZE);
	const VECTOR maxPos = VGet(x + Config::PLAYER_HALF_SIZE, y + Config::PLAYER_MOVE_SPEED, z + Config::PLAYER_HALF_SIZE);

	const int blue = GetColor(50,120,255);

	DrawCube3D(minPos,maxPos,blue,blue,TRUE);
}

float Player::GetX() const { return x; }
float Player::GetY() const { return y; }
float Player::GetZ() const { return z; }
