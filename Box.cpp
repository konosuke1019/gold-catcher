#include "DxLib.h"
#include "Box.h"
#include "money.h"
#include "UI.h"

const float Box::Scale = 0.01;//��

/// <summary>
/// �R���X�g���N�^
/// </summary>
Box::Box()
{
	BaseHandle = MV1LoadModel("data/truecoin.mv1");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Box::~Box()
{
	MV1DeleteModel(BaseHandle);
}

/// <summary>
/// ������
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
/// �A�b�v�f�[�g
/// </summary>
/// <param name="state">���݂̃X�e�[�g</param>
/// <param name="time">���݂̎c�莞��</param>
/// <param name="judge">�������Ă��邩�̔���</param>
void Box::Update(int state, int time, int judge)
{
	rad += 5;
	//�`���[�g���A��
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

		//��]
		MV1SetRotationXYZ(Handle, VGet(0.0f, rad * DX_PI_F / 180.0f, 0.0f));
		// �v���C���[����{�[���܂ł̋������v�Z
		// ���a�̍��v�����Z�������瓖�����Ă���
		if (judge == true)
		{
			pos.y == 2.0;
		}
	}
	//���̑�
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

		//��]
		MV1SetRotationXYZ(Handle, VGet(0.0f, rad * DX_PI_F / 180.0f, 0.0f));
		// �v���C���[����{�[���܂ł̋������v�Z
		// ���a�̍��v�����Z�������瓖�����Ă���

		if (judge == true)
		{
			SetFontSize(90);
			//DrawString(100, 100, "��������", (255, 255, 255), false);
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
/// �`��
/// </summary>
/// <param name="state">���݂̃X�e�[�g</param>
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
	