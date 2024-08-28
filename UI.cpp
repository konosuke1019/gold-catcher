#include "DxLib.h"
#include "UI.h"
#include "camera.h"
#include "player.h"
#include "king.h"
#include "money.h"
#include "Map.h"

/// <summary>
/// �R���X�g���N�^
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
/// �f�X�g���N�^
/// </summary>
UI::~UI()
{
	//�摜���폜
	DeleteGraph(TitleGraph);
	DeleteGraph(TitleBackGraph);
	DeleteGraph(boardGraph);
	DeleteGraph(paperGraph);
	DeleteGraph(coinGraph);
	DeleteGraph(billGraph);
	DeleteGraph(boxGraph);
}

/// <summary>
/// �`��
/// </summary>
void UI::Draw(int state,int score)
{
	switch (state)
	{

	//�^�C�g�����
	case STATE_START:

		//�^�C�g���̕`��
		DrawGraph(0,0,TitleBackGraph,true);
		DrawGraph(300, 200,TitleGraph, true);
		SetFontSize(50);
		//DrawFormatString(550, 600, (255, 255, 0), "HI SCORE : $%d", maxscore);
		//�{�^���̓_��
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
		DrawString(550, 10, "�`���[�g���A�����E�E�E", GetColor(255, 255, 0));
		DrawString(550, 70, "SPACE KEY �� GAME START!", GetColor(255, 255, 0));
		DrawRotaGraph(1400, 400, 0.5, 0, paperGraph, true);
		//DrawRotaGraph()
		DrawRotaGraph(800, 960, 0.4, 0, boardGraph, true);
		DrawString(300, 810, "�\���L�[�̍��E�ړ��Ńv���C���[�𓮂������I", (255, 255, 255));
		break;
	//�Q�[����
	case STATE_GAME:
		break;

	//���U���g���
	case STATE_END:
		//���`��
		SetFontSize(90);
		DrawString(700, 400, "����̃X�R�A", (255, 255, 255), true);
		if (lastscore < score)
		{
			lastscore++;
		}
		DrawFormatString(700, 500, (255, 255, 255), "$%d", lastscore);
		//�{�^���̓_��
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

	//���̑�
	default:
		break;
	}
}
