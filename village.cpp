#include "DxLib.h"
#include "village.h"
const float Village::Scale = 0.001f;		// スケール
const float Village::GroundScale = 0.005f;		// スケール

/// <summary>
/// コンストラクタ
/// </summary>
Village::Village()
{
	//家
	HouseHandle[0] = MV1LoadModel("data/build1.mv1");
	HouseHandle[1] = MV1LoadModel("data/build2.mv1");
	HouseHandle[2] = MV1LoadModel("data/build3.mv1");
	HouseHandle[3] = MV1LoadModel("data/build4.mv1");
	HouseHandle[4] = MV1LoadModel("data/build1.mv1");
	HouseHandle[5] = MV1LoadModel("data/build2.mv1");
	HouseHandle[6] = MV1LoadModel("data/build3.mv1");
	HouseHandle[7] = MV1LoadModel("data/build4.mv1");
	HouseHandle[8] = MV1LoadModel("data/build1.mv1");
	HouseHandle[9] = MV1LoadModel("data/build2.mv1");
	HouseHandle[10] = MV1LoadModel("data/build3.mv1");
	HouseHandle[11] = MV1LoadModel("data/build4.mv1");
	HouseHandle[12] = MV1LoadModel("data/build1.mv1");
	HouseHandle[13] = MV1LoadModel("data/build2.mv1");
	HouseHandle[14] = MV1LoadModel("data/build3.mv1");

	MV1SetPosition(HouseHandle[10], VGet(-4.5, 0, 1.4));
	MV1SetPosition(HouseHandle[6], VGet(-3.9, 0, 1.4));
	MV1SetPosition(HouseHandle[7], VGet(-2.7, 0, 1.25));
	MV1SetPosition(HouseHandle[5], VGet(-1.7, 0.08, 1.45));
	MV1SetPosition(HouseHandle[0], VGet(-0.8, 0.4, 0.9));
	MV1SetPosition(HouseHandle[1], VGet(0.4, 0.08, 1.45));
	MV1SetPosition(HouseHandle[3], VGet(0.95, -0.1, 1.25));
	MV1SetPosition(HouseHandle[2], VGet(1.9, 0, 1.3));
	MV1SetPosition(HouseHandle[4], VGet(2.8, 0.4, 0.9));
	MV1SetPosition(HouseHandle[8], VGet(3.5, 0, 1.4));
	MV1SetPosition(HouseHandle[9], VGet(4.2, 0, 1.4));
	MV1SetPosition(HouseHandle[11], VGet(5.5, 0, 1.4));
	MV1SetPosition(HouseHandle[12], VGet(6.5, 0, 1.4));
	MV1SetPosition(HouseHandle[13], VGet(0.9, -0.2, 2.4));
	MV1SetPosition(HouseHandle[14], VGet(-0.2, -0.1, 2.4));

	//地面
	for (int i = 0; i < 5; i++)
	{
		GroundHandle[i] = MV1LoadModel("data/ground.mv1");
	}
	MV1SetPosition(GroundHandle[0], VGet(0, -0.9, 0.5));
	MV1SetPosition(GroundHandle[1], VGet(-2.5, -0.9, 0.5));
	MV1SetPosition(GroundHandle[2], VGet(2.5, -0.9, 0.5));
	MV1SetPosition(GroundHandle[3], VGet(-5.0, -0.9, 0.5));
	MV1SetPosition(GroundHandle[4], VGet(5.0, -0.9, 0.5));

	//ガード
	for (int i = 0; i < 2; i++)
	{
		GuardHandle[i] = MV1LoadModel("data/GuardRail1.mv1");
		MV1SetRotationXYZ(GuardHandle[i], VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f));
	}
	MV1SetPosition(GuardHandle[0], VGet(-1.5, -0.4, 0.3));
	MV1SetPosition(GuardHandle[1], VGet(1.5, -0.4, 0.3));
	
	// 3Dモデルのスケール決定
	for (int i = 0; i < 15; i++)
	{
		MV1SetScale(HouseHandle[i], VGet(Scale, Scale, Scale));
	}
	for (int i = 0; i < 5; i++)
	{
		MV1SetScale(GroundHandle[i], VGet(GroundScale, GroundScale, GroundScale));
	}
	for (int i = 0; i < 2; i++)
	{
		MV1SetScale(GuardHandle[i], VGet(Scale, Scale, Scale));
	}
}

/// <summary>
/// デストラクタ
/// </summary>
Village::~Village()
{
	for (int i = 0; i < 15; i++)
	{
		MV1DeleteModel(HouseHandle[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		MV1DeleteModel(GroundHandle[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		MV1DeleteModel(GuardHandle[i]);
	}
}

/// <summary>
/// 描画
/// </summary>
void Village::Draw()
{
	for (int i = 0; i < 15; i++)
	{
		MV1DrawModel(HouseHandle[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		MV1DrawModel(GroundHandle[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		MV1DrawModel(GuardHandle[i]);
	}
}