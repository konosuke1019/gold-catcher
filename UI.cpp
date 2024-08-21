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
	ButtonGraph = LoadGraph("data/button");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
UI::~UI()
{
	//�摜���폜
	DeleteGraph(TitleGraph);
	DeleteGraph(TitleBackGraph);
	DeleteGraph(ButtonGraph);
}

/// <summary>
/// �`��
/// </summary>
void UI::Draw(int state)
{
	switch (state)
	{
	//�^�C�g�����
	case STATE_START:

		//�^�C�g���̕`��
		DrawGraph(0,0,TitleBackGraph,true);
		DrawGraph(300, 200,TitleGraph, true);

		//�{�^���̓_��
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
	//���U���g���
	case STATE_END:

		//���`��
		SetFontSize(90);
		DrawString(400, 400, "����̃X�R�A", (255, 255, 255), true);
		DrawString(500, 500, "���U���g", (255, 255, 255), true);
		break;

	default:
		break;
	}
}
