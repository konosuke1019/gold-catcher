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
	AnimHandle= MV1LoadModel("data/ply.mv1");
	position = VGet(0, -0.2, -0.2);
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
	if (position.x < -1.0)
	{
		position.x = -1.0;
	}
	if (position.x > 1.0)
	{
		position.x = 1.0;
	}

	// �|�W�V�������X�V.
	velocity = VScale(VScale(dir, 0.5), Speed);
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
	MV1DrawModel(AnimHandle);
	DrawSphere3D(VGet(position.x, position.y + 0.07, position.z), Playerradius, 100, (255, 255, 255), (255, 255, 255), false);
}