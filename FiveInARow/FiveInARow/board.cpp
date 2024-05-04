#include "board.h"

void board::draw()
{
	COLORREF TheFillColor = getfillcolor();
	setlinestyle(PS_SOLID, 2);
	setfillcolor(base_color);
	solidrectangle(x, y, x + 30, y + 30);
	if (isnew) // ����ѡ���
	{
		setlinecolor(LIGHTGRAY);
		line(x + 1, y + 2, x + 8, y + 2);
		line(x + 2, y + 1, x + 2, y + 8);
		line(x + 29, y + 2, x + 22, y + 2);
		line(x + 29, y + 1, x + 29, y + 8);
		line(x + 2, y + 29, x + 8, y + 29);
		line(x + 2, y + 22, x + 2, y + 29);
		line(x + 29, y + 29, x + 22, y + 29);
		line(x + 29, y + 22, x + 29, y + 29);
	}
	setlinecolor(BLACK);
	switch (mode) // ���̵ľ���λ��
	{
	case 0: // center
		line(x + 15, y, x + 15, y + 30);
		line(x - 1, y + 15, x + 30, y + 15);
		break;

	case 1: // left
		line(x + 14, y + 15, x + 30, y + 15);
		setlinestyle(PS_SOLID, 3);
		line(x + 15, y, x + 15, y + 30);
		setlinestyle(PS_SOLID, 2);
		break;

	case 2: // right
		line(x - 1, y + 15, x + 15, y + 15);
		setlinestyle(PS_SOLID, 3);
		line(x + 15, y, x + 15, y + 30);
		setlinestyle(PS_SOLID, 2);
		break;

	case 3: // up
		line(x + 15, y + 15, x + 15, y + 30);
		setlinestyle(PS_SOLID, 3);
		line(x - 1, y + 15, x + 30, y + 15);
		setlinestyle(PS_SOLID, 2);
		break;

	case 4: // down
		line(x + 15, y, x + 15, y + 15);
		setlinestyle(PS_SOLID, 3);
		line(x - 1, y + 15, x + 30, y + 15);
		setlinestyle(PS_SOLID, 2);
		break;
	case 5: // left_down
		setlinestyle(PS_SOLID, 3);
		line(x + 15, y, x + 15, y + 15);
		line(x + 15, y + 15, x + 30, y + 15);
		setlinestyle(PS_SOLID, 2);
		break;
	case 6: // right_down
		setlinestyle(PS_SOLID, 3);
		line(x + 15, y, x + 15, y + 15);
		line(x - 1, y + 15, x + 15, y + 15);
		setlinestyle(PS_SOLID, 2);
		break;
	case 7: // right_up
		setlinestyle(PS_SOLID, 3);
		line(x - 1, y + 15, x + 15, y + 15);
		line(x + 15, y + 15, x + 15, y + 30);
		setlinestyle(PS_SOLID, 2);
		break;
	case 8: // left_up
		setlinestyle(PS_SOLID, 3);
		line(x + 15, y + 15, x + 30, y + 15);
		line(x + 15, y + 15, x + 15, y + 30);
		setlinestyle(PS_SOLID, 2);
		break;
	case 9:
		line(x + 15, y, x + 15, y + 30);
		line(x - 1, y + 15, x + 30, y + 15);
		setfillcolor(BLACK);
		setlinestyle(PS_SOLID, 1);
		fillcircle(x + 15, y + 15, 4);
		break;
	}

	switch (value)
	{
	case 0: // white
		setfillcolor(WHITE);
		setlinestyle(PS_SOLID, 1);
		fillcircle(x + 15, y + 15, 13);
		break;
	case 1: // black
		setfillcolor(BLACK);
		setlinestyle(PS_SOLID, 1);
		fillcircle(x + 15, y + 15, 13);
		break;
	}
	setfillcolor(TheFillColor);
}

void draw()
{
	int mode = 0;
	int num = 0;

	// ����
	TCHAR strnum[19][3] = { _T("1"), _T("2") , _T("3") , _T("4"), _T("5") , _T("6"), _T("7"), _T("8"), _T("9"), _T("10"), _T("11"), _T("12") ,_T("13") ,_T("14"),_T("15") ,_T("16") ,_T("17"),_T("18"),_T("19") };
	TCHAR strabc[19][3] = { _T("A"),_T("B") ,_T("C") ,_T("D"),_T("E") ,_T("F") ,_T("G"),_T("H"),_T("I"),_T("J"), _T("K"),_T("L") ,_T("M") ,_T("N"),_T("O") ,_T("P") ,_T("Q"),_T("R"),_T("S") };

	for (int i = 0, s = 0; i < 570; i += 30, s++)
	{
		for (int j = 0, t = 0; j < 570; j += 30, t++)
		{
			box[s][t].base_color = RGB(255, 205, 150);
			box[s][t].x = 65 + j;
			box[s][t].y = 50 + i;
			box[s][t].num = 0;

			if (!s && !t)
				mode = 8;
			else if (!s && t == 18)
				mode = 7;
			else if (s == 18 && t == 18)
				mode = 6;
			else if (s == 18 && t == 0)
				mode = 5;
			else if (s == 18)
				mode = 4;
			else if (s == 0)
				mode = 3;
			else if (t == 18)
				mode = 2;
			else if (t == 0)
				mode = 1;
			else if ((s == 3 && t == 3) || (s == 3 && t == 15) || (s == 15 && t == 3) || (s == 15 && t == 15) || (s == 3 && t == 9) || (s == 9 && t == 3) || (s == 15 && t == 9) || (s == 9 && t == 15) || (s == 9 && t == 9))
				mode = 9;
			else
				mode = 0;

			box[s][t].mode = mode;
			box[s][t].draw();
			if (box[s][t].isnew = true)
				box[s][t].isnew = false;
		}
	}

	LOGFONT font;
	font.lfQuality = ANTIALIASED_QUALITY;
	gettextstyle(&font);
	settextstyle(0, 0, NULL);

	for (int i = 0; i < 19; i++)
	{
		outtextxy(75 + num, 35, strnum[i]);
		outtextxy(53, 55 + num, strabc[i]);
		num += 30;
	}
	settextstyle(&font);
}