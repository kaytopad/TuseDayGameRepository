#pragma once
#include "DxLib.h"

class Animation
{
public:

    Animation();
    ~Animation();

    bool Load(int model);

    void Update();

    void PlayRun();
    void PlayIdle();

private:

    int playerModel;

    int idleModel;
    int runModel;

    int attachIndex;

    float playTime;
    float totalTime;

    bool running;
};