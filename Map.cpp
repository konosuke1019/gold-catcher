#include<vector>
#include "Map.h"
#include "DxLib.h"
#include "UI.h"
#include "game.h"

/// <summary>
/// コンストラクタ
/// </summary>
Map::Map()
{
	//なし
}

/// <summary>
/// デストラクタ
/// </summary>
Map::~Map()
{
	MV1DeleteModel(SkyHundle);
}

/// <summary>
/// ロード
/// </summary>
void Map::Load()
{
	// とりあえずマップロード
	SkyHundle = MV1LoadModel("data/skydome.mv1");
	pos = VGet(0, 0, 0);
	MV1SetScale(SkyHundle, VGet(0.5, 0.5, 0.5));
}

/// <summary>
/// 描画
/// </summary>
void Map::Draw()
{
	MV1DrawModel(SkyHundle);
}