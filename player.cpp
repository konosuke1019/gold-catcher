#include "DxLib.h"
#include "Player.h"
#include "money.h"

// 静的定数
// 速度（1=1m、60fps固定として、時速10km）
// 10000m ÷ 時間 ÷ 分 ÷ 秒 ÷ フレーム
const float Player::Speed = static_cast<float>(10000.0 / 60.0 / 60.0 / 60.0);
const float Player::Scale = 0.001f;		// スケール

/// <summary>
/// コンストラクタ
/// </summary>
Player::Player(): AnimHandle(-1)
{
	// ３Ｄモデルの読み込み
	AnimHandle= MV1LoadModel("data/ply.mv1");
	position = VGet(0, -0.2, -0.2);
	velocity = VGet(0, 0, 0);
	dir = VGet(0, 0, 1);

	// ３Dモデルのポジション設定
	MV1SetPosition(AnimHandle, position);
	
	// 3Dモデルのスケール決定
	MV1SetScale(AnimHandle, VGet(Scale, Scale, Scale));
	AttachIndex = MV1AttachAnim(AnimHandle, 0, -1, FALSE);
	AnimTime = MV1GetAnimTotalTime(AnimHandle, AttachIndex);
	AnimAddTime = 0;
}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player()
{
	// モデルのアンロード.
	MV1DeleteModel(AnimHandle);
}

/// <summary>
/// 更新
/// </summary>
void Player::Update()
{
	// 入力
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	
	// 単純に方向転換
	dir = VGet(0, 0, 0);
	//右
	if (Key & PAD_INPUT_RIGHT)
	{
		dir = VAdd(dir, VGet(1, 0, 0));
		MV1SetRotationXYZ(AnimHandle, VGet(0.0f, -90.0f, 0.0f));
	}
	//左
	else if (Key & PAD_INPUT_LEFT)
	{
		dir = VAdd(dir, VGet(-1, 0, 0));
		MV1SetRotationXYZ(AnimHandle, VGet(0.0f, 90.0f, 0.0f));
	}
	else
	{
		AnimAddTime = 18;
	}
	// ゼロ除算避け
	if (VSquareSize(dir) > 0)
	{
		// 正規化
		dir = VNorm(dir);
	}

	//画面外処理
	if (position.x < -1.0)
	{
		position.x = -1.0;
	}
	if (position.x > 1.0)
	{
		position.x = 1.0;
	}

	// ポジションを更新.
	velocity = VScale(VScale(dir, 0.5), Speed);
	position = VAdd(position, velocity);

	// 力をかけ終わったベロシティの方向にディレクションを調整.
	if (VSize(velocity) != 0)
	{
		dir = VNorm(velocity);
	}

	//printfDx("%f %f %f\n", dir.x, dir.y, dir.z);
	//printfDx("player %f,%f,%f\n", position.x, position.y, position.z);
	// 回転
	//MV1SetRotationXYZ(modelHandle, VGet(0.0f, -90.0f, 0.0f));
	//MV1SetRotationXYZ(AnimHandle, VGet(0.0f, -90.0f, 0.0f));

	AnimAddTime++;
	if (AnimAddTime >= AnimTime)
	{
		AnimAddTime = 0;
	}
	MV1SetAttachAnimTime(AnimHandle, AttachIndex, AnimAddTime);
	MV1SetPosition(AnimHandle, position);
}

/// <summary>
/// 描画
/// </summary>
void Player::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(AnimHandle);
	DrawSphere3D(VGet(position.x, position.y + 0.07, position.z), Playerradius, 100, (255, 255, 255), (255, 255, 255), false);
}