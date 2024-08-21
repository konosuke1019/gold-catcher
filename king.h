#pragma once

class King
{
public:
	King();
	~King();

	void Update();
	void Draw();
	// ���f���n���h���̎擾.
	int GetModelHandle() const { return KingHandle; }
	const VECTOR& GetPos() const { return pos; }
	const VECTOR& GetDir() const { return dir; }
	VECTOR pos;

private:
	int		KingHandle;		//�A�j���[�V����
	int		AttachIndex;
	float	AnimTime;
	float	AnimAddTime;
	VECTOR	velocity;		// �ړ���.
	VECTOR	dir;			// ��]����.

	// �ÓI�萔.
	static const float Speed;
	static const float Scale;
};