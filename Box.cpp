#include "DxLib.h"
#include "Box.h"
#include "money.h"
#include "UI.h"

const float Box::Scale = 0.01;//仮

/// <summary>
/// コンストラクタ
/// </summary>
Box::Box()
{
	BaseHandle = MV1LoadModel("data/truecoin.mv1");
}

/// <summary>
/// デストラクタ
/// </summary>
Box::~Box()
{
	MV1DeleteModel(BaseHandle);
}

/// <summary>
/// 初期化
/// </summary>
void Box::Init()
{
	Handle = MV1DuplicateModel(BaseHandle);
	DownFlg = false;
	diff += 0.5;
	rand = GetRand(8);
	if (rand < 5)
	{
		rand *= -1;
	}
	pos = VGet(rand * 0.1, 2.0 + diff, -0.2);
	MV1SetScale(Handle, VGet(Scale, Scale, Scale));
	Visible = false;
	MV1SetPosition(Handle, pos);
	hitflg = false;
}

/// <summary>
/// アップデート
/// </summary>
/// <param name="state">現在のステート</param>
/// <param name="time">現在の残り時間</param>
/// <param name="judge">当たっているかの判定</param>
void Box::Update(int state, int time, int judge)
{
	rad += 5;
	//チュートリアル
	if (state == STATE_CHUT)
	{
		Visible = false;
		if (pos.y > -2.0)
		{
			pos.y -= 0.01;
		}
		else if (pos.y <= -2.0)
		{
			pos.y == 2.0;
		}
		MV1SetPosition(Handle, VGet(0.0, pos.y, -0.2));

		//回転
		MV1SetRotationXYZ(Handle, VGet(0.0f, rad * DX_PI_F / 180.0f, 0.0f));
		// プレイヤーからボールまでの距離を計算
		// 半径の合計よりも短かったら当たっている
		if (judge == true)
		{
			pos.y == 2.0;
		}
	}
	//その他
	else
	{
		if (pos.y > -2.0)
		{
			DownFlg = true;
		}
		if (DownFlg == true)
		{
			pos.y -= 0.01;
		}
		else if (pos.y <= -2.0)
		{
			Visible = true;
		}
		MV1SetPosition(Handle, pos);

		//回転
		MV1SetRotationXYZ(Handle, VGet(0.0f, rad * DX_PI_F / 180.0f, 0.0f));
		// プレイヤーからボールまでの距離を計算
		// 半径の合計よりも短かったら当たっている

		if (judge == true)
		{
			SetFontSize(90);
			//DrawString(100, 100, "当たった", (255, 255, 255), false);
			Visible = true;
			hitflg = true;
		}
		if (hitflg == true)
		{
			hitflg = false;
		}
	}
}

/// <summary>
/// 描画
/// </summary>
/// <param name="state">現在のステート</param>
void Box::Draw(int state)
{
	if (Visible == false)
	{
		MV1DrawModel(Handle);
		DrawSphere3D(pos, boxradius, 100, (255, 255, 255), (255, 255, 255), false);
		if (state == STATE_CHUT)
		{
			Visible == true;
		}
	}
}
	