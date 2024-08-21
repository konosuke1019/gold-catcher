#include<vector>
#include "Map.h"
#include "DxLib.h"
#include "UI.h"
#include "game.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Map::Map()
{
	//�Ȃ�
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Map::~Map()
{
	MV1DeleteModel(SkyHundle);
}

/// <summary>
/// ���[�h
/// </summary>
void Map::Load()
{
	// �Ƃ肠�����}�b�v���[�h
	SkyHundle = MV1LoadModel("data/skydome.mv1");
	pos = VGet(0, 0, 0);
	MV1SetScale(SkyHundle, VGet(0.01, 0.01, 0.01));
}

/// <summary>
/// �A�b�v�f�[�g
/// </summary>
void Map::Update()
{
	rote++;
	rote /= 10;
	MV1SetRotationXYZ(SkyHundle, VGet(0.0f, 0.0f + rote, 0.0f));
}

/// <summary>
/// �`��
/// </summary>
void Map::Draw()
{
	MV1DrawModel(SkyHundle);
}