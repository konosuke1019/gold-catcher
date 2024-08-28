// 2016 Takeru Yui All Rights Reserved.
#include "DxLib.h"
#include <vector>
#include "Map.h"
#include "Player.h"
#include "Camera.h"
#include "math.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Camera::Camera()
	: fov (60.0f)
	,pos (VGet(0, 0, 0))
{
	//���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(0.1f, 1000.0f);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Camera::~Camera()
{
	// �����Ȃ�.
}

/// <summary>
/// �X�V
/// </summary>
void Camera::Update(const Player& player)
{
	VECTOR playerPos = player.GetPos();
	VECTOR cameraPos = VGet(player.position.x,0,-0.5);
	// �������鎋�_�́A�J�����ƕ��s�ɂ܂�����z=0�n�_
	VECTOR lookPos = VGet(player.position.x, 0, 50.0f);

	//FOV(����p)
	SetupCamera_Perspective(fov * (static_cast<float>(M_PI)) * 180.0f);

	pos = cameraPos;
	/*printfDx("%f,%f,%f", cameraPos.x, cameraPos.y, cameraPos.z);
	printfDx(" look %f,%f,%f\n", lookPos.x, lookPos.y, lookPos.z);*/
	//DrawFormatString(10, 20, (255, 255, 255), "camera %f,%f,%f", cameraPos.x, cameraPos.y, cameraPos.z);
	//DrawFormatString(10, 30, (255, 255, 255), "look %f,%f,%f", cameraPos.x, cameraPos.y, cameraPos.z);
	// �J�����Ɉʒu�𔽉f.
	SetCameraPositionAndTarget_UpVecY(pos, lookPos);
}