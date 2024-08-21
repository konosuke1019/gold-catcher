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
	int GetModelHandle() const { return HouseHandle[5]; }

private:
	int HouseHandle[5];
	VECTOR pos;
};