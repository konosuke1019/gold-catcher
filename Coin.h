#pragma once
#include "Dxlib.h"
const int coinmaxnum = 100;
const int coinradius = 0.04;

/// <summary>
/// コインクラス
/// </summary>
class Coin
{
public:
	Coin();
	~Coin();

	//変数
	bool	Visible;
	bool	hitflg;
	bool    DownFlg;
	int		BaseHandle;
	int		Handle;
	int		rand;
	int		nowstate;
	int		diff;
	float	rad;
	VECTOR	pos;

	//関数
	void Init();
	void Update(int state, int time, int judge);
	void Draw(int state);

	// モデルハンドルの取得.
	int GetCoinHandle() const { return BaseHandle; }
	const float Getradius() { return coinradius; }

private:
	static const float Scale;
};