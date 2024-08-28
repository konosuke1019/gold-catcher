#pragma once
#include "Dxlib.h"
#include "player.h"
#include "Coin.h"
#include "Bill.h"
#include "Box.h"
//const float coinradius = 0.04;
//const float coinradius = 0.04;


/// <summary>
/// お金のクラス
/// </summary>
class Money :public Player
{
public:
	Coin coin[coinmaxnum];
	Bill bill[billmaxnum];
	Box  box [boxmaxnum];

	Money();
	~Money();

	//変数
	float rad;
	int nowtime;
	int point;
	int gamestate;

	//関数
	void Update(Player& player, int time, int state);		// 更新.
	bool Collision(VECTOR position1, float radius1, VECTOR position2, float radius2);
	void Draw(int state);								// 描画.

private:
};