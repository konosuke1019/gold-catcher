#pragma once
#include "DxLib.h"

class WorldSprite;

/// <summary>
/// �X�J�C�h�[��
/// </summary>
class Map
{
public:
	//�R���X�g���N�^&�f�X�g���N�^
	Map();
	~Map();

	//�ϐ�
	int rote = 0;

	//�֐�
	void Load();
	void Update();
	void Draw();
	
	//���f���n���h��
	int SkyHundle;
	
	//�|�W�V����
	VECTOR pos;
};