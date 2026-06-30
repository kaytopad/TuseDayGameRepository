#pragma once
#include "Character.h"

class Game
{
private:
	// プレイヤーと敵
    Character player;
    Character enemy;

    // 床描画
    void DrawFloor();

public:
	// 初期化
    void Init();
	// 更新
    void Update();
	// 描画
    void Draw();
};