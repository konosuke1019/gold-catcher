#pragma once
#include "Dxlib.h"
#include "player.h"

class Money :public Player
{
public:
	Money();
	~Money();

	void Update(Player&player);			// �X�V.
	void Draw();						// �`��.
	// ���f���n���h���̎擾.
	int GetModelHandle() const { return modelHandle[3]; }
	bool hitflg = false;
	int rand = 0;
private:
	int		modelHandle[3];	// ���f���n���h��.
	VECTOR	pos[3];			// �|�W�V����.
};