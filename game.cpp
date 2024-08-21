#include "game.h"
#include "DxLib.h"
#include "player.h"
#include "money.h"
#include "king.h"
#include "Map.h"
#include "UI.h"
#include "camera.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
GAME::GAME()
{
	
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
GAME::~GAME()
{
	
}

/// <summary>
/// ������
/// </summary>
void GAME::Init()
{
	//�X�^�[�g��ʂɂ���
	state = STATE_START;
}

/// <summary>
/// state�؂�ւ�
/// </summary>
void GAME::ChangeState()
{
	//�������Ԃ��~�߂�.
	WaitTimer(500);

	// �X�e�[�g���؂�ւ�����u�Ԃ̓L�[��������������Z�b�g.
	keyOn = false;
	keyRelease = false;
	//�X�e�[�g
	state = state;
	// �X�e�[�g���؂�ւ�����u�ԁA�K�v�Ȃ珉�����Ȃǂ̏������s��
	switch (state)
	{
		// �^�C�g��.
	case STATE_START:
		Init();
		time = 0;
		break;
		// �Q�[����.
	case STATE_GAME:
		break;
		// �N���A���.
	case STATE_END:
		break;
		// ���̑�
	default:
		break;
	}
}

/// <summary>
/// �A�b�v�f�[�g
/// </summary>
void GAME::Update()
{
	//�L�[�������u�Ԃ����.
	if (keyOn)
	{
		if (CheckHitKey(KEY_INPUT_SPACE) == 0)
		{
			keyOn = false;
			keyRelease = true;
		}
	}
	else if (prevKeyOn == false && CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		keyRelease = false;
		keyOn = true;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		prevKeyOn = true;
	}
	else
	{
		prevKeyOn = false;
	}

	switch (state)
	{
	case STATE_START:
		// �L�[���͂���������Q�[���J�n�̏�Ԃ�
		if (keyRelease)
		{
			state = STATE_GAME;
			ChangeState();
			time = 0;
		}
		break;
	case STATE_GAME:
		break;
	}
}