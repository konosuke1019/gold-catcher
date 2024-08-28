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
	boardGraph = LoadGraph("data/board.png");
	paperGraph = LoadGraph("data/paper.png");
	coinGraph = LoadGraph("data/coin.png");
	billGraph = LoadGraph("data/bill.png");
	boxGraph = LoadGraph("data/box.png");
	lastscore = 0;
}

/// <summary>
/// デストラクタ
/// </summary>
UI::~UI()
{
	//画像を削除
	DeleteGraph(TitleGraph);
	DeleteGraph(TitleBackGraph);
	DeleteGraph(boardGraph);
	DeleteGraph(paperGraph);
	DeleteGraph(coinGraph);
	DeleteGraph(billGraph);
	DeleteGraph(boxGraph);
}

/// <summary>
/// 描画
/// </summary>
void UI::Draw(int state,int score)
{
	switch (state)
	{

	//タイトル画面
	case STATE_START:

		//タイトルの描画
		DrawGraph(0,0,TitleBackGraph,true);
		DrawGraph(300, 200,TitleGraph, true);
		SetFontSize(50);
		//DrawFormatString(550, 600, (255, 255, 0), "HI SCORE : $%d", maxscore);
		//ボタンの点滅
		ButtonCount++;
		if (ButtonCount < 20)
		{
			DrawString(550, 600, "TAP SPACE KEY", GetColor(255, 255, 0));
		}
		if (ButtonCount > 35)
		{
			ButtonCount = 0;
		}
		break;
	case STATE_CHUT:
		DrawString(550, 10, "チュートリアル中・・・", GetColor(255, 255, 0));
		DrawString(550, 70, "SPACE KEY で GAME START!", GetColor(255, 255, 0));
		DrawRotaGraph(1400, 400, 0.5, 0, paperGraph, true);
		//DrawRotaGraph()
		DrawRotaGraph(800, 960, 0.4, 0, boardGraph, true);
		DrawString(300, 810, "十字キーの左右移動でプレイヤーを動かそう！", (255, 255, 255));
		break;
	//ゲーム中
	case STATE_GAME:
		break;

	//リザルト画面
	case STATE_END:
		//仮描画
		SetFontSize(90);
		DrawString(700, 400, "今回のスコア", (255, 255, 255), true);
		if (lastscore < score)
		{
			lastscore++;
		}
		DrawFormatString(700, 500, (255, 255, 255), "$%d", lastscore);
		//ボタンの点滅
		ButtonCount++;
		if (ButtonCount < 20)
		{
			SetFontSize(50);
			DrawString(700, 700, "TAP SPACE KEY\nRETURN TO START", GetColor(255, 255, 0));
		}
		if (ButtonCount > 35)
		{
			ButtonCount = 0;
		}
		break;

	//その他
	default:
		break;
	}
}
