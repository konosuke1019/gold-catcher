#pragma once
#include "Dxlib.h"
#include "player.h"
#include "Coin.h"
#include "Bill.h"
#include "Box.h"
//const float coinradius = 0.04;
//const float coinradius = 0.04;


/// <summary>
/// �����̃N���X
/// </summary>
class Money :public Player
{
public:
	Coin coin[coinmaxnum];
	Bill bill[billmaxnum];
	Box  box [boxmaxnum];

	Money();
	~Money();

	//�ϐ�
	float rad;
	int nowtime;
	int point;
	int gamestate;

	//�֐�
	void Update(Player& player, int time, int state);		// �X�V.
	bool Collision(VECTOR position1, float radius1, VECTOR position2, float radius2);
	void Draw(int state);								// �`��.

private:
};