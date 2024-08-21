#pragma once
#include "DxLib.h"

class Player
{
public:
	Player();				// コンストラクタ.
	~Player();				// デストラクタ.

	void Update();			// 更新.
	void Draw();			// 描画.

	int point = 0;

	// モデルハンドルの取得.
	int GetModelHandle() const { return AnimHandle; }
	const VECTOR& GetPos() const { return position; }
	const VECTOR& GetDir() const { return dir; }
	VECTOR	position;			// ポジション.

private:
	int		modelHandle;	// モデルハンドル.
	int		AnimHandle;		// アニメーション
	int		AttachIndex;

	float	AnimTime;
	float	AnimAddTime;
	VECTOR	velocity;		// 移動力.
	VECTOR	dir;			// 回転方向.

	// 静的定数.
	static const float Speed;
	static const float Scale;
};