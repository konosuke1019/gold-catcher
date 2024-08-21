#pragma once
#include "DxLib.h"

class WorldSprite;

/// <summary>
/// スカイドーム
/// </summary>
class Map
{
public:
	//コンストラクタ&デストラクタ
	Map();
	~Map();

	//変数
	int rote = 0;

	//関数
	void Load();
	void Update();
	void Draw();
	
	//モデルハンドル
	int SkyHundle;
	
	//ポジション
	VECTOR pos;
};