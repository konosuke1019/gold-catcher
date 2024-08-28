#include "DxLib.h"
#include "money.h"
#include "player.h"
#include "Coin.h"
#include "Bill.h"
#include "Box.h"
#include "UI.h"
#include <time.h>

/// <summary>
/// �R���X�g���N�^
/// </summary>
Money::Money()
{	
	for (int i = 0; i < coinmaxnum; i++)
	{
		coin[i].Init();
	}
	/*for (int i = 0; i < billmaxnum; i++)
	{
		bill[i].Init();
	}
	for (int i = 0; i < boxmaxnum; i++)
	{
		box[i].Init();
	}*/
	point = 0;
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Money::~Money()
{
	//���f���̃A�����[�h
	for (int i = 0; i < coinmaxnum; i++)
	{
		MV1DeleteModel(coin[i].Handle);
	}
	/*for (int i = 0; i < billmaxnum; i++)
	{
		MV1DeleteModel(bill[i].Handle);
	}
	for (int i = 0; i < boxmaxnum; i++)
	{
		MV1DeleteModel(box[i].Handle);
	}*/
}

/// <summary>
/// �A�b�v�f�[�g
/// </summary>
/// <param name="player">�v���C���[</param>
/// <param name="time">���݂̎c�莞��</param>
/// <param name="state">���݂̃X�e�[�g</param>
void Money::Update(Player&player,int time,int state)
{
	for (int i = 0; i < coinmaxnum; i++)
	{
		coin[i].Update(state,time, Collision(player.position, Playerradius, coin[i].pos, coinradius));
	}
	/*for (int i = 0; i < billmaxnum; i++)
	{
		coin[i].Update(state, time, Collision(player.position, Playerradius, bill[i].pos, billradius));
	}
	for (int i = 0; i < boxmaxnum; i++)
	{
		coin[i].Update(state, time, Collision(player.position, Playerradius, box[i].pos, billradius));
	}*/
}

/// <summary>
/// �����蔻��
/// </summary>
/// <param name="position1">�ʒu�P</param>
/// <param name="radius1">�~�̓����蔻��Z�^�̔��a</param>
/// <param name="position2">�ʒu�Q</param>
/// <param name="radius2">�~�̓����蔻��Z�^�̔��a</param>
/// <returns>�������Ă��邩�ǂ����̔���</returns>
bool Money::Collision(VECTOR position1, float radius1,VECTOR position2, float radius2)
{
	// ���̒��S�_����̋������v�Z
    VECTOR diff = VSub(position1, position2);
    float distance = VDot(diff, diff);                  // 2��

    // �����̔��a�̒������v�Z
    float radiusSum = radius1 + radius2;
    float radiusSumSquared = radiusSum * radiusSum;     // 2��

    // ���S�_�Ԃ̋����������a�̘a�̕����߂��Ȃ瓖�����Ă���
    if (distance <= radiusSumSquared)
    {
        return true;        // ��������
    }
    else
    {
        return false;       // �������ĂȂ�
    }
}

/// <summary>
/// �`��
/// </summary>
void Money::Draw(int state)
{
	for (int i = 0; i <coinmaxnum; i++)
	{
		coin[i].Draw(state);
	}
	/*for (int i = 0; i < billmaxnum; i++)
	{
		bill[i].Draw(state);
	}
	for (int i = 0; i < boxmaxnum; i++)
	{
		box[i].Draw(state);
	}*/
	if(state!=STATE_CHUT)
	{
		DrawFormatString(1100, 10, (255, 255, 255), "MONEY:$%d", point);
	}
}