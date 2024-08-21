#pragma once
#define M_PI 3.14

class Player;

/// <summary>
/// カメラ
/// </summary>
class Camera
{
public:
	Camera();							// コンストラクタ.
	~Camera();							// デストラクタ.

	void Update(const Player& player);	// 更新.

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }

private:
	float	fov;
	VECTOR	pos;

	constexpr static float DefaultFov = 60.0f;	// デフォルトのfov
	constexpr static float FovRange = 30.0f;	// fovの変化幅
	constexpr static float PosChangeSpeed = 0.03f;	// posの変化スピード
};
