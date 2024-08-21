#pragma once

class King
{
public:
	King();
	~King();

	void Update();
	void Draw();
	// モデルハンドルの取得.
	int GetModelHandle() const { return KingHandle; }
	const VECTOR& GetPos() const { return pos; }
	const VECTOR& GetDir() const { return dir; }
	VECTOR pos;

private:
	int		KingHandle;		//アニメーション
	int		AttachIndex;
	float	AnimTime;
	float	AnimAddTime;
	VECTOR	velocity;		// 移動力.
	VECTOR	dir;			// 回転方向.

	// 静的定数.
	static const float Speed;
	static const float Scale;
};