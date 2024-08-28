#pragma once
#include "DxLib.h"
const int billmaxnum = 50;
const int billradius = 0.04;

/// <summary>
/// お札クラス
/// </summary>
class Bill
{
public:
	Bill();
	~Bill();

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
	const float Getradius() { return billradius; }

private:
	static const float Scale;
};

