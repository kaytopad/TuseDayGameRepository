#include "Game.h"

bool Game::Init()
{
    player.Load();

    return true;
}

void Game::Update()
{
    player.Update();

    camera.Update(player);
}

void Game::Draw()
{
    ClearDrawScreen();

    DrawBox(0, 0, 1200, 800, GetColor(255, 255, 255), TRUE);

    player.Draw();

    ScreenFlip();
}