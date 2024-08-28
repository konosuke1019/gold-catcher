#pragma once
#include "DxLib.h"
const float Playerradius = 0.04;

class Player
{
public:
	Player();				// コンストラクタ.
	~Player();				// デストラクタ.

	void Update();			// 更新.
	void Draw();			// 描画.

	int point = 0;
	int x1=750;
	int x2=850;
	int y1=550;
	int y2=700;

	// モデルハンドルの取得.
	int GetModelHandle() const { return AnimHandle; }
	const VECTOR& GetPos() const { return position; }
	const VECTOR& GetDir() const { return dir; }
	VECTOR	position;			// ポジション.

	const float Getradius() const { return Playerradius; };

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