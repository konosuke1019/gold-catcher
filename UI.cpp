#include "DxLib.h"
#include "UI.h"
#include "camera.h"
#include "player.h"
#include "king.h"
#include "money.h"
#include "Map.h"

/// <summary>
/// コンストラクタ
/// </summary>
UI::UI()
{
	TitleGraph = LoadGraph("data/Title.png");
	TitleBackGraph = LoadGraph("data/skymoney.png");
	ButtonGraph = LoadGraph("data/button");
}

/// <summary>
/// デストラクタ
/// </summary>
UI::~UI()
{
	//画像を削除
	DeleteGraph(TitleGraph);
	DeleteGraph(TitleBackGraph);
	DeleteGraph(ButtonGraph);
}

/// <summary>
/// 描画
/// </summary>
void UI::Draw(int state)
{
	switch (state)
	{
	//タイトル画面
	case STATE_START:

		//タイトルの描画
		DrawGraph(0,0,TitleBackGraph,true);
		DrawGraph(300, 200,TitleGraph, true);

		//ボタンの点滅
		ButtonCount++;
		if (ButtonCount < 20)
		{
			SetFontSize(50);
			DrawString(550, 600, "TAP SPACE KEY", GetColor(255, 255, 0));
		}
		if (ButtonCount > 35)
		{
			ButtonCount = 0;
		}
		break;

	case STATE_GAME:
		//DrawFormatString(20, 20, (255, 255, 255), "MONEY:%d",score);
		break;
	//リザルト画面
	case STATE_END:

		//仮描画
		SetFontSize(90);
		DrawString(400, 400, "今回のスコア", (255, 255, 255), true);
		DrawString(500, 500, "リザルト", (255, 255, 255), true);
		break;

	default:
		break;
	}
}
