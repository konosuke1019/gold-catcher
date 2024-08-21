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
	int GetModelHandle() const { return HouseHandle[7]; }
	const VECTOR& GetPos() const { return pos; }
	const VECTOR& GetDir() const { return dir; }

private:
	int HouseHandle[7];
	int GroundHandle;
	VECTOR pos;
	VECTOR dir;

	// �ÓI�萔.
	static const float Scale;
	static const float GroundScale;
};