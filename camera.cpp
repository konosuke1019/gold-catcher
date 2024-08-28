// 2016 Takeru Yui All Rights Reserved.
#include "DxLib.h"
#include <vector>
#include "Map.h"
#include "Player.h"
#include "Camera.h"
#include "math.h"

/// <summary>
/// コンストラクタ
/// </summary>
Camera::Camera()
	: fov (60.0f)
	,pos (VGet(0, 0, 0))
{
	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(0.1f, 1000.0f);
}

/// <summary>
/// デストラクタ
/// </summary>
Camera::~Camera()
{
	// 処理なし.
}

/// <summary>
/// 更新
/// </summary>
void Camera::Update(const Player& player)
{
	VECTOR playerPos = player.GetPos();
	VECTOR cameraPos = VGet(player.position.x,0,-0.5);
	// 注視する視点は、カメラと平行にまっすぐz=0地点
	VECTOR lookPos = VGet(player.position.x, 0, 50.0f);

	//FOV(視野角)
	SetupCamera_Perspective(fov * (static_cast<float>(M_PI)) * 180.0f);

	pos = cameraPos;
	/*printfDx("%f,%f,%f", cameraPos.x, cameraPos.y, cameraPos.z);
	printfDx(" look %f,%f,%f\n", lookPos.x, lookPos.y, lookPos.z);*/
	//DrawFormatString(10, 20, (255, 255, 255), "camera %f,%f,%f", cameraPos.x, cameraPos.y, cameraPos.z);
	//DrawFormatString(10, 30, (255, 255, 255), "look %f,%f,%f", cameraPos.x, cameraPos.y, cameraPos.z);
	// カメラに位置を反映.
	SetCameraPositionAndTarget_UpVecY(pos, lookPos);
}