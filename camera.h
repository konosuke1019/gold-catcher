#pragma once
#define M_PI 3.14

class Player;

/// <summary>
/// �J����
/// </summary>
class Camera
{
public:
	Camera();							// �R���X�g���N�^.
	~Camera();							// �f�X�g���N�^.

	void Update(const Player& player);	// �X�V.

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }

private:
	float	fov;
	VECTOR	pos;

	constexpr static float DefaultFov = 60.0f;	// �f�t�H���g��fov
	constexpr static float FovRange = 30.0f;	// fov�̕ω���
	constexpr static float PosChangeSpeed = 0.03f;	// pos�̕ω��X�s�[�h
};
