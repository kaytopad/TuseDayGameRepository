#pragma once
#include "Dxlib.h"
#include "Object3D.h"
const int STAGE_MODEL_NUM = 3;
const int OBJECT_NUM = 5;

class Object3D;

class Stage
{
private:
	
	int stageModels[STAGE_MODEL_NUM];

	VECTOR stagePosition[STAGE_MODEL_NUM];

	Object3D* objects[OBJECT_NUM];
public:
	Stage();
	~Stage();

	bool Load();

	void Draw();

	bool CheckCollision(VECTOR playerPosition,float playerRadius);
};

