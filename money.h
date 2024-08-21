#pragma once
#include "Dxlib.h"
#include "player.h"

class Money :public Player
{
public:
	Money();
	~Money();

	void Update(Player&player);			// 更新.
	void Draw();						// 描画.
	// モデルハンドルの取得.
	int GetModelHandle() const { return modelHandle[3]; }
	bool hitflg = false;
	int rand = 0;
private:
	int		modelHandle[3];	// モデルハンドル.
	VECTOR	pos[3];			// ポジション.
};