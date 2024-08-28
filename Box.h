#pragma once
#include "DxLib.h"
const int boxmaxnum = 10;
const int boxradius = 0.05;//��

/// <summary>
/// �󔠃N���X
/// </summary>
class Box//:public Coin
{
public:
	Box();
	~Box();

	//�ϐ�
	bool	Visible;
	bool	hitflg;
	bool    DownFlg;
	int		BaseHandle;
	int		Handle;	//coin
	int		rand;
	int		nowstate;
	int		diff;
	float	rad;
	VECTOR	pos;

	void Init();
	void Update(int state, int time, int judge);
	void Draw(int state);

	// ���f���n���h���̎擾.
	int GetBoxHandle() const { return BaseHandle; }
	const float Getradius() { return boxradius; }

private:
	static const float Scale;
};

