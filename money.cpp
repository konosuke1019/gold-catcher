#include "DxLib.h"
#include "money.h"
#include "player.h"
#include <time.h>

enum Itemkind
{
	COIN,
	DOLLAR,
	CASE
};

Money::Money()
{
	// ３Ｄモデルの読み込み
	for (int i = 0; i < 3; i++)
	{
		modelHandle[i] = LoadGraph("data/money/coin.png");//当たり判定確認用
	}
	//rand = srand((unsigned)time(NULL));
	pos[0] = VGet(400, 0, 0);
	pos[1] = VGet(800, -50, 0);
	pos[2] = VGet(1200, -100, 0);

	// ３Dモデルのポジション設定
	for (int i = 0; i < 3; i++)
	{
		MV1SetPosition(modelHandle[i], pos[i]);
	}
	// 3Dモデルのスケール決定
	//MV1SetScale(modelHandle, VGet(Scale, Scale, Scale));
	/*AttachIndex = MV1AttachAnim(modelHandle, 0, -1, FALSE);
	AnimTime = MV1GetAnimTotalTime(modelHandle, AttachIndex);
	AnimAddTime = 0;*/
}

Money::~Money()
{
	// モデルのアンロード.
	//MV1DeleteModel(modelHandle);
	for (int i = 0; i < 3; i++)
	{
		MV1DeleteModel(modelHandle[i]);
	}
}

//アップデート
void Money::Update(Player&player)
{
	for (int i = 0; i < 3; i++)
	{
		if (pos[i].y < 800)
		{
			pos[i].y += 10;
		}
		else if (pos[i].y = 800)
		{
			pos[i].y = 0;
		}
		//printfDx("%f,%f,%f\n", pos[i].x, pos[i].y, pos[i].z);

		// エネミーとの当たり判定
		if (((player.position.x - 45 > pos[i].x - 25 && player.position.x - 45 < pos[i].x + 25) ||
			(pos[i].x - 25 > player.position.x - 45 && pos[i].x - 25 < player.position.x + 25)) &&
			((player.position.y + 570 > pos[i].y - 25 && player.position.y + 570 < pos[i].y + 25) ||
				(pos[i].y - 25 > player.position.y + 700 && pos[i].y + 25 < player.position.y + 700)))
		{
			printfDx("当たった\n");
			//どのお金か判別し、スコアを加算する
		}
	}
}

void Money::Draw()
{
	for (int i = 0; i < 3; i++)
	{
		DrawRotaGraph(pos[i].x, pos[i].y, 0.1, 0, modelHandle[i], true);
		DrawBox(pos[i].x - 25, pos[i].y - 25, pos[i].x + 25, pos[i].y + 25, (255, 255, 255), false);
	}
}