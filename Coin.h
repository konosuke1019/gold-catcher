#pragma once
#include "Dxlib.h"
const int coinmaxnum = 100;
const int coinradius = 0.04;

/// <summary>
/// �R�C���N���X
/// </summary>
class Coin
{
public:
	Coin();
	~Coin();

	//�ϐ�
	bool	Visible;
	bool	hitflg;
	bool    DownFlg;
	int		BaseHandle;
	int		Handle;
	int		rand;
	int		nowstate;
	int		diff;
	float	rad;
	VECTOR	pos;

	//�֐�
	void Init();
	void Update(int state, int time, int judge);
	void Draw(int state);

	// ���f���n���h���̎擾.
	int GetCoinHandle() const { return BaseHandle; }
	const float Getradius() { return coinradius; }

private:
	static const float Scale;
};