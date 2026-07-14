#include "Dxlib.h"

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int model1, anim_nutral, anim_run, attachidx;
	float anim_totaltime, playtime = 0.0f;

	VECTOR pos = VGet(600.0f, 300.0f, -400.0f);
	int key;
	enum Direction{DOWN,LEFT,UP,RIGHT} direction = DOWN;
	MATRIX mat1, mat2;

	ChangeWindowMode(TRUE);
	SetGraphMode(1200, 800, 32);
	if (DxLib_Init() == -1){return -1;}

	model1 = MV1LoadModel("Player/PC.mv1");
	if (model1 ==-1){return -1;}

	anim_nutral = MV1LoadModel("Player/Anim_Neutral.mv1");
	if (anim_nutral == -1){return -1;}
	
	anim_run = MV1LoadModel("Player/Anim_Run.mv1");
	if (anim_run == -1){return -1;}
	
	attachidx = MV1AttachAnim(model1, 0,anim_nutral);
	anim_totaltime = MV1GetAttachAnimTotalTime(model1, attachidx);

	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		playtime += 0.5f;
		if (playtime > anim_totaltime) { playtime = 0.0f; }
		MV1SetAttachAnimTime(model1, attachidx, playtime);

		if (CheckHitKey(KEY_INPUT_DOWN)) { pos.z -= 4.0f; direction = DOWN; }
		if (CheckHitKey(KEY_INPUT_UP)) { pos.z += 4.0f; direction = UP; }
		if (CheckHitKey(KEY_INPUT_LEFT)) { pos.x -= 4.0f; direction = LEFT; }
		if (CheckHitKey(KEY_INPUT_RIGHT)) { pos.x += 4.0f; direction = RIGHT; }

		ClearDrawScreen();
		DrawBox(0, 0, 1200, 800, GetColor(255, 255, 255), TRUE);

		MV1SetRotationXYZ(model1, VGet(0.0f, 1.57f * direction, 0.0f));
		MV1SetPosition(model1, pos);

		MV1DrawModel(model1);

		ScreenFlip();
	}
	DxLib_End();
	return 0;
}