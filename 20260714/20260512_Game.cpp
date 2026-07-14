#include "Dxlib.h"

int WINAPI WinMain(HINSTANCE hI,HINSTANCE hP,LPSTR lpC,int nC)
{
	int module1;

	VECTOR pos = VGet(600.0f,300.0f,-400.0f);
	int key;
	enum  Direction{DOWN,LEFT,UP,RIGHT } direction = DOWN;

	MATRIX mat1, mat2;

	ChangeWindowMode(TRUE);
	SetGraphMode(1200,800,32);
	if (DxLib_Init() == -1) return -1;

	module1 = MV1LoadModel("Player/PC.mv1");
	if (module1 == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE)==0)
	{
		if (CheckHitKey(KEY_INPUT_DOWN)) { pos.z -= 4.0f; direction = DOWN; }
		if (CheckHitKey(KEY_INPUT_UP)) { pos.z += 4.0f; direction = UP; }
		if (CheckHitKey(KEY_INPUT_LEFT)) { pos.x -= 4.0f; direction = LEFT; }
		if (CheckHitKey(KEY_INPUT_RIGHT)) { pos.x += 4.0f; direction = RIGHT; }

		ClearDrawScreen();
		DrawBox(0,0,1200,800,GetColor(255,255,255),TRUE);

		//Y軸の回転行列をセットする
		mat1 = MGetRotY(1.57f * direction);
		//平行移動行列をセットする
		mat2 = MGetTranslate(pos);
		//モデルの座標変換用行列をセットする
		MV1SetMatrix(module1, MMult(mat1,mat2));

		MV1DrawModel(module1);

		ScreenFlip();
	}

	DxLib_End();

	return 0;

}