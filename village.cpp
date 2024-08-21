#include "DxLib.h"
#include "village.h"
const float Village::Scale = 0.0005f;		// スケール
const float Village::GroundScale = 0.001f;		// スケール

/// <summary>
/// コンストラクタ
/// </summary>
Village::Village()
{
	HouseHandle[0] = MV1LoadModel("data/build1.mv1");
	HouseHandle[1] = MV1LoadModel("data/build2.mv1");
	HouseHandle[2] = MV1LoadModel("data/build3.mv1");
	HouseHandle[3] = MV1LoadModel("data/build4.mv1");
	HouseHandle[4] = MV1LoadModel("data/build1.mv1");
	HouseHandle[5] = MV1LoadModel("data/build2.mv1");
	HouseHandle[6] = MV1LoadModel("data/build3.mv1");
	GroundHandle = MV1LoadModel("data/ground.mv1");
	MV1SetPosition(HouseHandle[0], VGet(-1, 0, 0.5));
	MV1SetPosition(HouseHandle[1], VGet(-0.3, 0, 1));
	MV1SetPosition(HouseHandle[2], VGet(0.5, 0, 0.5));
	MV1SetPosition(HouseHandle[3], VGet(1, 0, 0.2));
	MV1SetPosition(HouseHandle[4], VGet(-0.3, 0, 1));
	MV1SetPosition(HouseHandle[5], VGet(0.5, 0, 0.5));
	MV1SetPosition(HouseHandle[6], VGet(1, 0, 0.2));
	MV1SetPosition(GroundHandle, VGet(0, -1.5, 0));
	// 3Dモデルのスケール決定
	for (int i = 0; i < 7; i++)
	{
		MV1SetScale(HouseHandle[i], VGet(Scale, Scale, Scale));
	}
	MV1SetScale(GroundHandle, VGet(GroundScale, GroundScale, GroundScale));
}

/// <summary>
/// デストラクタ
/// </summary>
Village::~Village()
{
	for (int i = 0; i < 7; i++)
	{
		MV1DeleteModel(HouseHandle[i]);
	}
	MV1DeleteModel(GroundHandle);
}

void Village::Draw()
{
	MV1DrawModel(GroundHandle);
	for (int i = 0; i < 7; i++)
	{
		MV1DrawModel(HouseHandle[i]);
	}
}