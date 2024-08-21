#pragma once
#include "DxLib.h"

class Player
{
public:
	Player();				// �R���X�g���N�^.
	~Player();				// �f�X�g���N�^.

	void Update();			// �X�V.
	void Draw();			// �`��.

	int point = 0;

	// ���f���n���h���̎擾.
	int GetModelHandle() const { return AnimHandle; }
	const VECTOR& GetPos() const { return position; }
	const VECTOR& GetDir() const { return dir; }
	VECTOR	position;			// �|�W�V����.

private:
	int		modelHandle;	// ���f���n���h��.
	int		AnimHandle;		// �A�j���[�V����
	int		AttachIndex;

	float	AnimTime;
	float	AnimAddTime;
	VECTOR	velocity;		// �ړ���.
	VECTOR	dir;			// ��]����.

	// �ÓI�萔.
	static const float Speed;
	static const float Scale;
};