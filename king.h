#pragma once

class King
{
public:
	King();
	~King();

	void Update(int state);
	void Draw(int state);
	// ���f���n���h���̎擾.
	int GetModelHandle() const { return KingHandle; }
	const VECTOR& GetPos() const { return pos; }
	const VECTOR& GetDir() const { return dir; }

private:
	int		KingHandle;		//�A�j���[�V����
	int		MoneyHandle[3];
	int		AttachIndex;
	float	AnimTime;
	float	AnimAddTime;
	float   coinTime;
	bool	kingcoinflg[3];
	VECTOR	velocity;		// �ړ���.
	VECTOR  pos;
	VECTOR  moneypos[3];
	VECTOR	dir;			// ��]����.

	// �ÓI�萔.
	static const float Speed;
	static const float Scale;
	static const float CoinScale;
};