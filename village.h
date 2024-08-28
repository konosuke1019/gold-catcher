#pragma once
#include "DxLib.h"

class Village
{
public:
	//�R���X�g���N�^&�f�X�g���N�^
	Village();
	~Village();

	//�֐�
	void Draw();

	//���f���n���h���̎擾.
	int GetModelHandle() const { return HouseHandle[15]; }
	const VECTOR& GetPos() const { return pos; }
	const VECTOR& GetDir() const { return dir; }

private:
	int HouseHandle[15];
	int GroundHandle[5];
	int GuardHandle[2];
	VECTOR pos;
	VECTOR dir;

	// �ÓI�萔.
	static const float Scale;
	static const float GroundScale;
};