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
	// �R�c���f���̓ǂݍ���
	for (int i = 0; i < 3; i++)
	{
		modelHandle[i] = LoadGraph("data/money/coin.png");//�����蔻��m�F�p
	}
	//rand = srand((unsigned)time(NULL));
	pos[0] = VGet(400, 0, 0);
	pos[1] = VGet(800, -50, 0);
	pos[2] = VGet(1200, -100, 0);

	// �RD���f���̃|�W�V�����ݒ�
	for (int i = 0; i < 3; i++)
	{
		MV1SetPosition(modelHandle[i], pos[i]);
	}
	// 3D���f���̃X�P�[������
	//MV1SetScale(modelHandle, VGet(Scale, Scale, Scale));
	/*AttachIndex = MV1AttachAnim(modelHandle, 0, -1, FALSE);
	AnimTime = MV1GetAnimTotalTime(modelHandle, AttachIndex);
	AnimAddTime = 0;*/
}

Money::~Money()
{
	// ���f���̃A�����[�h.
	//MV1DeleteModel(modelHandle);
	for (int i = 0; i < 3; i++)
	{
		MV1DeleteModel(modelHandle[i]);
	}
}

//�A�b�v�f�[�g
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

		// �G�l�~�[�Ƃ̓����蔻��
		if (((player.position.x - 45 > pos[i].x - 25 && player.position.x - 45 < pos[i].x + 25) ||
			(pos[i].x - 25 > player.position.x - 45 && pos[i].x - 25 < player.position.x + 25)) &&
			((player.position.y + 570 > pos[i].y - 25 && player.position.y + 570 < pos[i].y + 25) ||
				(pos[i].y - 25 > player.position.y + 700 && pos[i].y + 25 < player.position.y + 700)))
		{
			printfDx("��������\n");
			//�ǂ̂��������ʂ��A�X�R�A�����Z����
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