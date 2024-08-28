#pragma once
#include "DxLib.h"
const int billmaxnum = 50;
const int billradius = 0.04;

/// <summary>
/// ���D�N���X
/// </summary>
class Bill
{
public:
	Bill();
	~Bill();

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
	const float Getradius() { return billradius; }

private:
	static const float Scale;
};

