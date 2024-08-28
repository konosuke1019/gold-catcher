#include "DxLib.h"
#include "king.h"
#include "UI.h"
const float King::Scale = 0.003f;		// スケール
const float King::CoinScale = 0.01f;

/// <summary>
/// コンストラクタ
/// </summary>
King::King() : KingHandle(-1)
{
	//王様画像のロード
	KingHandle = MV1LoadModel("data/king.mv1");
	//王様が投げているお金の画像のロード
	for (int i = 0; i < 3; i++)
	{
		MoneyHandle[i] = MV1LoadModel("data/truecoin.mv1");
	}
	//position設定
	moneypos[0] = VGet(0, 1.3, 1.3);
	moneypos[1] = VGet(0, 1.3, 1.3);
	moneypos[2] = VGet(0, 1.3, 1.3);
	// ３Dモデルのポジション設定
	for (int i = 0; i < 3; i++)
	{
		MV1SetPosition(MoneyHandle[i], moneypos[i]);
		MV1SetRotationXYZ(MoneyHandle[i], VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f));
		MV1SetScale(MoneyHandle[i], VGet(CoinScale, CoinScale, CoinScale));
		kingcoinflg[i] = false;
	}

	pos = VGet(0, 0.8, 1.3);
	velocity = VGet(0, 0, 0);
	dir = VGet(0, 0, 1);
	// ３Dモデルのポジション設定
	MV1SetPosition(KingHandle, pos);
	// 3Dモデルのスケール決定
	MV1SetScale(KingHandle, VGet(Scale, Scale, Scale));
	AttachIndex = MV1AttachAnim(KingHandle, 0, -1, FALSE);
	AnimTime = MV1GetAnimTotalTime(KingHandle, AttachIndex);
	AnimAddTime = 0;
	coinTime = 0;
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
void King::Update(int state)
{
	if (state == STATE_END)
	{
		//アニメーション
		AnimAddTime += 2;
		if (AnimAddTime >= AnimTime)
		{
			AnimAddTime = 0;
		}
		MV1SetAttachAnimTime(KingHandle, AttachIndex, AnimAddTime);
		MV1SetPosition(KingHandle, VGet(-0.4, 0, -0.1));
	}
	else
	{
		//アニメーション
		AnimAddTime += 2;
		if (AnimAddTime >= AnimTime)
		{
			AnimAddTime = 0;
		}
		MV1SetAttachAnimTime(KingHandle, AttachIndex, AnimAddTime);
		if (state == STATE_GAME)
		{
			coinTime++;
			if (kingcoinflg[2] == false)
			{
				moneypos[0] = VAdd(moneypos[0], VGet(0, 0.02, 0));
				moneypos[1] = VAdd(moneypos[1], VGet(-0.007, 0.017, 0));
				moneypos[2] = VAdd(moneypos[2], VGet(0.007, 0.017, 0));
			}
			if (coinTime < 30)
			{
				for (int i = 0; i < 3; i++)
				{
					MV1SetPosition(MoneyHandle[i], moneypos[i]);
					if (moneypos[i].y > 2)
					{
						moneypos[i] = VGet(0, 1.3, 1.3);
					}
					kingcoinflg[i] = true;
				}
				coinTime = 0;
			}
			for (int i = 0; i < 3; i++)
			{
				kingcoinflg[i] = false;
			}
		}
	}
}

/// <summary>
/// 描画
/// </summary>
void King::Draw(int state)
{
	MV1DrawModel(KingHandle);
	if (state == STATE_GAME)
	{
		for (int i = 0; i < 3; i++)
		{
			MV1DrawModel(MoneyHandle[i]);
		}
	}
}