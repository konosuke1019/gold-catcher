#include "DxLib.h"
#include "king.h"
const float King::Scale = 0.001f;		// スケール

/// <summary>
/// コンストラクタ
/// </summary>
King::King() : KingHandle(-1)
{
	KingHandle = MV1LoadModel("data/king.mv1");
	pos = VGet(0, 0, 0);
	velocity = VGet(0, 0, 0);
	dir = VGet(0, 0, 1);
	// ３Dモデルのポジション設定
	MV1SetPosition(KingHandle, pos);
	// 3Dモデルのスケール決定
	MV1SetScale(KingHandle, VGet(Scale, Scale, Scale));
	AttachIndex = MV1AttachAnim(KingHandle, 0, -1, FALSE);
	AnimTime = MV1GetAnimTotalTime(KingHandle, AttachIndex);
	AnimAddTime = 0;
}

/// <summary>
/// デストラクタ
/// </summary>
King::~King()
{
	MV1DeleteModel(KingHandle);
}

/// <summary>
/// アニメーション管理
/// </summary>
void King::Update()
{
	//アニメーション
	AnimAddTime++;
	if (AnimAddTime >= AnimTime)
	{
		AnimAddTime = 0;
	}
	MV1SetAttachAnimTime(KingHandle, AttachIndex, AnimAddTime);
	MV1SetPosition(KingHandle, pos);
}

/// <summary>
/// 描画
/// </summary>
void King::Draw()
{
	MV1DrawModel(KingHandle);
}