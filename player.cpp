#include "DxLib.h"
#include "Player.h"
#include "money.h"

// �ÓI�萔
// ���x�i1=1m�A60fps�Œ�Ƃ��āA����10km�j
// 10000m �� ���� �� �� �� �b �� �t���[��
const float Player::Speed = static_cast<float>(10000.0 / 60.0 / 60.0 / 60.0);
const float Player::Scale = 0.001f;		// �X�P�[��

/// <summary>
/// �R���X�g���N�^
/// </summary>
Player::Player(): AnimHandle(-1)
{
	// �R�c���f���̓ǂݍ���
	//modelHandle = MV1LoadModel("data/player.mv1");
	AnimHandle= MV1LoadModel("data/ply.mv1");

	position = VGet(0, -0.3, -0.2);
	velocity = VGet(0, 0, 0);
	dir = VGet(0, 0, 1);
	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(AnimHandle, position);
	// 3D���f���̃X�P�[������
	MV1SetScale(AnimHandle, VGet(Scale, Scale, Scale));
	AttachIndex = MV1AttachAnim(AnimHandle, 0, -1, FALSE);
	AnimTime = MV1GetAnimTotalTime(AnimHandle, AttachIndex);
	AnimAddTime = 0;
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Player::~Player()
{
	// ���f���̃A�����[�h.
	MV1DeleteModel(AnimHandle);
}

/// <summary>
/// �X�V
/// </summary>
void Player::Update()
{
	// ����
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	// �P���ɕ����]��
	dir = VGet(0, 0, 0);

	//�E
	if (Key & PAD_INPUT_RIGHT)
	{
		dir = VAdd(dir, VGet(1, 0, 0));
		MV1SetRotationXYZ(AnimHandle, VGet(0.0f, -90.0f, 0.0f));
	}
	//��
	else if (Key & PAD_INPUT_LEFT)
	{
		dir = VAdd(dir, VGet(-1, 0, 0));
		MV1SetRotationXYZ(AnimHandle, VGet(0.0f, 90.0f, 0.0f));
	}
	else
	{
		AnimAddTime = 18;
	}
	// �[�����Z����
	if (VSquareSize(dir) > 0)
	{
		// ���K��
		dir = VNorm(dir);
	}

	//��ʊO����
	if (position.y < -0.2)
	{
		position.y = -0.2;
	}
	if (position.x < -0.4)
	{
		position.x = -0.4;
	}
	if (position.x > 0.4)
	{
		position.x = 0.4;
	}

	// �|�W�V�������X�V.
	velocity = VScale(VScale(dir,0.2), Speed);
	position = VAdd(position, velocity);

	// �͂������I������x���V�e�B�̕����Ƀf�B���N�V�����𒲐�.
	if (VSize(velocity) != 0)
	{
		dir = VNorm(velocity);
	}

	//printfDx("%f %f %f\n", dir.x, dir.y, dir.z);
	//printfDx("player %f,%f,%f\n", position.x, position.y, position.z);
	// ��]
	//MV1SetRotationXYZ(modelHandle, VGet(0.0f, -90.0f, 0.0f));
	//MV1SetRotationXYZ(AnimHandle, VGet(0.0f, -90.0f, 0.0f));

	AnimAddTime++;
	if (AnimAddTime >= AnimTime)
	{
		AnimAddTime = 0;
	}
	MV1SetAttachAnimTime(AnimHandle, AttachIndex, AnimAddTime);
	MV1SetPosition(AnimHandle, position);
}

/// <summary>
/// �`��
/// </summary>
void Player::Draw()
{
	// �R�c���f���̕`��
	//MV1DrawModel(modelHandle);
	MV1DrawModel(AnimHandle);
	SetFontSize(20);
	DrawFormatString(10, 10, (255, 255, 255), "%f,%f,%f", position.x, position.y, position.z);
	DrawBox(position.x*1000 + 750, position.y*1000 + 650, position.x*1000 + 850, position.y*1000 + 700, (255, 255, 255), false);
}