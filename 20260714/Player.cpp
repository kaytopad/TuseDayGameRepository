#include "Camera.h"
#include "Player.h"
#include "20260714_Config.h"
#include <cmath>

void Camera::Update(const Player& player)
{
    VECTOR pos = player.GetPosition();

    float angle = player.GetAngle();

    VECTOR eye;

    eye.x = pos.x - sinf(angle) * Config::CAMERA_DISTANCE;
    eye.z = pos.z - cosf(angle) * Config::CAMERA_DISTANCE;
    eye.y = pos.y + Config::CAMERA_HEIGHT;

    VECTOR target;

    target = pos;

    target.y += 80;

    SetCameraPositionAndTarget_UpVecY(eye, target);
}