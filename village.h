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
	int GetModelHandle() const { return HouseHandle[5]; }

private:
	int HouseHandle[5];
	VECTOR pos;
};