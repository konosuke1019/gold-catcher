#include "DxLib.h"
#include "money.h"
#include "player.h"
#include "Coin.h"
#include "Bill.h"
#include "Box.h"
#include "UI.h"
#include <time.h>

/// <summary>
/// コンストラクタ
/// </summary>
Money::Money()
{	
	for (int i = 0; i < coinmaxnum; i++)
	{
		coin[i].Init();
	}
	/*for (int i = 0; i < billmaxnum; i++)
	{
		bill[i].Init();
	}
	for (int i = 0; i < boxmaxnum; i++)
	{
		box[i].Init();
	}*/
	point = 0;
}

/// <summary>
/// デストラクタ
/// </summary>
Money::~Money()
{
	//モデルのアンロード
	for (int i = 0; i < coinmaxnum; i++)
	{
		MV1DeleteModel(coin[i].Handle);
	}
	/*for (int i = 0; i < billmaxnum; i++)
	{
		MV1DeleteModel(bill[i].Handle);
	}
	for (int i = 0; i < boxmaxnum; i++)
	{
		MV1DeleteModel(box[i].Handle);
	}*/
}

/// <summary>
/// アップデート
/// </summary>
/// <param name="player">プレイヤー</param>
/// <param name="time">現在の残り時間</param>
/// <param name="state">現在のステート</param>
void Money::Update(Player&player,int time,int state)
{
	for (int i = 0; i < coinmaxnum; i++)
	{
		coin[i].Update(state,time, Collision(player.position, Playerradius, coin[i].pos, coinradius));
	}
	/*for (int i = 0; i < billmaxnum; i++)
	{
		coin[i].Update(state, time, Collision(player.position, Playerradius, bill[i].pos, billradius));
	}
	for (int i = 0; i < boxmaxnum; i++)
	{
		coin[i].Update(state, time, Collision(player.position, Playerradius, box[i].pos, billradius));
	}*/
}

/// <summary>
/// 当たり判定
/// </summary>
/// <param name="position1">位置１</param>
/// <param name="radius1">円の当たり判定短型の半径</param>
/// <param name="position2">位置２</param>
/// <param name="radius2">円の当たり判定短型の半径</param>
/// <returns>当たっているかどうかの判定</returns>
bool Money::Collision(VECTOR position1, float radius1,VECTOR position2, float radius2)
{
	// 球の中心点からの距離を計算
    VECTOR diff = VSub(position1, position2);
    float distance = VDot(diff, diff);                  // 2乗

    // 両方の半径の長さを計算
    float radiusSum = radius1 + radius2;
    float radiusSumSquared = radiusSum * radiusSum;     // 2乗

    // 中心点間の距離よりも半径の和の方が近いなら当たっている
    if (distance <= radiusSumSquared)
    {
        return true;        // 当たった
    }
    else
    {
        return false;       // 当たってない
    }
}

/// <summary>
/// 描画
/// </summary>
void Money::Draw(int state)
{
	for (int i = 0; i <coinmaxnum; i++)
	{
		coin[i].Draw(state);
	}
	/*for (int i = 0; i < billmaxnum; i++)
	{
		bill[i].Draw(state);
	}
	for (int i = 0; i < boxmaxnum; i++)
	{
		box[i].Draw(state);
	}*/
	if(state!=STATE_CHUT)
	{
		DrawFormatString(1100, 10, (255, 255, 255), "MONEY:$%d", point);
	}
}