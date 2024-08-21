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
	MV1SetScale(SkyHundle, VGet(0.01, 0.01, 0.01));
}

/// <summary>
/// アップデート
/// </summary>
void Map::Update()
{
	rote++;
	rote /= 10;
	MV1SetRotationXYZ(SkyHundle, VGet(0.0f, 0.0f + rote, 0.0f));
}

/// <summary>
/// 描画
/// </summary>
void Map::Draw()
{
	MV1DrawModel(SkyHundle);
}