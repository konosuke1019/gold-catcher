#include "DxLib.h"
#include "king.h"
const float King::Scale = 0.001f;		// �X�P�[��

/// <summary>
/// �R���X�g���N�^
/// </summary>
King::King() : KingHandle(-1)
{
	KingHandle = MV1LoadModel("data/king.mv1");
	pos = VGet(0, 0, 0);
	velocity = VGet(0, 0, 0);
	dir = VGet(0, 0, 1);
	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(KingHandle, pos);
	// 3D���f���̃X�P�[������
	MV1SetScale(KingHandle, VGet(Scale, Scale, Scale));
	AttachIndex = MV1AttachAnim(KingHandle, 0, -1, FALSE);
	AnimTime = MV1GetAnimTotalTime(KingHandle, AttachIndex);
	AnimAddTime = 0;
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
King::~King()
{
	MV1DeleteModel(KingHandle);
}

/// <summary>
/// �A�j���[�V�����Ǘ�
/// </summary>
void King::Update()
{
	//�A�j���[�V����
	AnimAddTime++;
	if (AnimAddTime >= AnimTime)
	{
		AnimAddTime = 0;
	}
	MV1SetAttachAnimTime(KingHandle, AttachIndex, AnimAddTime);
	MV1SetPosition(KingHandle, pos);
}

/// <summary>
/// �`��
/// </summary>
void King::Draw()
{
	MV1DrawModel(KingHandle);
}