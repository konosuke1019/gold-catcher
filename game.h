#pragma once
#include "DxLib.h"

class GAME
{
public:
	
	//�t���O
	bool keyOn = false;
	bool prevKeyOn = false;
	bool keyRelease = false;

	//�ϐ�
	int state;
	int time = 0;

	//�R���X�g���N�^&�f�X�g���N�^
	GAME();
	~GAME();

	//������
	void Init();
	//state�؂�ւ�
	void ChangeState();
	//�A�b�v�f�[�g
	void Update();
	//�`��
	//void Draw();
};