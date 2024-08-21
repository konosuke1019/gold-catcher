#pragma once
#include "DxLib.h"

class Village
{
public:
	//コンストラクタ&デストラクタ
	Village();
	~Village();

	//関数
	void Draw();

	//モデルハンドルの取得.
	int GetModelHandle() const { return HouseHandle[7]; }
	const VECTOR& GetPos() const { return pos; }
	const VECTOR& GetDir() const { return dir; }

private:
	int HouseHandle[7];
	int GroundHandle;
	VECTOR pos;
	VECTOR dir;

	// 静的定数.
	static const float Scale;
	static const float GroundScale;
};