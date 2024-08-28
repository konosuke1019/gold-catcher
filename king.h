#pragma once

class King
{
public:
	King();
	~King();

	void Update(int state);
	void Draw(int state);
	// モデルハンドルの取得.
	int GetModelHandle() const { return KingHandle; }
	const VECTOR& GetPos() const { return pos; }
	const VECTOR& GetDir() const { return dir; }

private:
	int		KingHandle;		//アニメーション
	int		MoneyHandle[3];
	int		AttachIndex;
	float	AnimTime;
	float	AnimAddTime;
	float   coinTime;
	bool	kingcoinflg[3];
	VECTOR	velocity;		// 移動力.
	VECTOR  pos;
	VECTOR  moneypos[3];
	VECTOR	dir;			// 回転方向.

	// 静的定数.
	static const float Speed;
	static const float Scale;
	static const float CoinScale;
};