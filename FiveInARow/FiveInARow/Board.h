#pragma once
#include <graphics.h>

class seat
{
public:
	int i, j, num;
	seat(): i(0), j(0), num(0) {}
};

class board
{
public:
	int x = 0, y = 0;
	int value = -1; // 1->black  0->white  -1->null
	int mode;
	bool isnew = false; // �Ƿ���ѡ���
	int num = 0;
	COLORREF base_color = WHITE; // ����ɫ

	void draw();
};

board box[19][19];

void draw();