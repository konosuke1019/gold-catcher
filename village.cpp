#include "DxLib.h"
#include "village.h"

/// <summary>
/// コンストラクタ
/// </summary>
Village::Village()
{
	HouseHandle[0] = MV1LoadModel("");
	HouseHandle[1] = MV1LoadModel("");
	HouseHandle[2] = MV1LoadModel("");
	HouseHandle[3] = MV1LoadModel("");
	HouseHandle[4] = MV1LoadModel("");
	MV1SetPosition(HouseHandle[0], VGet(0, 0, 0));
	MV1SetPosition(HouseHandle[1], VGet(0, 0, 0));
	MV1SetPosition(HouseHandle[2], VGet(0, 0, 0));
	MV1SetPosition(HouseHandle[3], VGet(0, 0, 0));
	MV1SetPosition(HouseHandle[4], VGet(0, 0, 0));
}

/// <summary>
/// デストラクタ
/// </summary>
Village::~Village()
{
	for (int i = 0; i < 5; i++)
	{
		MV1DeleteModel(HouseHandle[i]);
	}
}

void Village::Draw()
{
	for (int i = 0; i < 5; i++)
	{
		MV1DrawModel(HouseHandle[i]);
	}
}