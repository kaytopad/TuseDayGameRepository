#pragma once

#include "Player.h"
#include "Camera.h"

class Game
{
public:

    bool Init();

    void Update();

    void Draw();

private:

    Player player;

    Camera camera;
};