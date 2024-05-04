#include "rules.h"

void iswin()
{
	bool isinit = true;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (box[i][j].value != -1)
			{
				isinit = false;
				int NowColor = box[i][j].value;
				int len[4] = { 0,0,0,0 };    // �ĸ�����ĳ���
				for (int k = 0; k < 4; k++)
				{
					int nowi = i;
					int nowj = j;
					while (nowi <= 18 && nowj <= 18 && nowi >= 0 && nowj >= 0 && box[nowi][nowj].value == NowColor)
					{
						len[k]++;
						nowj += dx[k];
						nowi += dy[k];
					}
					nowi = i;
					nowj = j;
					while (nowi <= 18 && nowj <= 18 && nowi >= 0 && nowj >= 0 && box[nowi][nowj].value == 1 - NowColor)
					{
						len[k]++;
						nowj -= dx[k];
						nowi -= dy[k];
					}
				}
				for (int k = 0; k < 4; k++)
				{
					if (len[k] >= 5) {
						if (NowColor == PlayerColor)
						{
							win = PlayerColor; // ���ʤ
						}
						if (NowColor == 1 - PlayerColor)
						{
							win = 1 - PlayerColor; // ����ʤ
						}
					}
				}
				if ((!isinit) && FindBestSeat(PlayerColor).num == 0 && FindBestSeat(1 - PlayerColor).num == 0)
				{
					// ������ǿ�����˫�������λ��
					win = 2; // ƽ��
				}
			}
		}
	}
}

void init()
{
	IMAGE bk;
	loadimage(&bk, "./resources/bk.png");
	putimage(0, 0, &bk);
	IMAGE tbox;
	loadimage(&tbox, "./resources/textbox.png");
	drawimg(&tbox, 250, 630);

	win = -1;
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
		{
			box[i][j].num = 0;
			box[i][j].value = -1;
		}
}

void MainGame()
{
	int prei = 0, prej = 0;
	srand(time(0));
	PlayerColor = rand() % 2; // �����ɫ

	setfillcolor(RGB(255, 205, 150));
	solidrectangle(40, 25, 645, 630);
	settextstyle(50, 40, _T("�����ĺ�-65W"));
	settextcolor(0);

	if (PlayerColor == 0)
	{
		outtextxy(276, 638, _T("��Ұ���"));
		NextPlayer = 1;
	}
	else
	{
		outtextxy(276, 638, _T("��Һ���"));
		NextPlayer = 0;
	}
	draw();

	while (true)
	{
	NEXTPLAYER:
		if (NextPlayer == 0) // �������
		{
			auto mouse = GetMouseMsg();
			for (int i = 0; i < 19; i++)
				for (int j = 0; j < 19; j++)
				{
					if (mouse.x > box[i][j].x && mouse.x < box[i][j].x + 30
						&& mouse.y > box[i][j].y && mouse.y < box[i][j].y + 30
						&& box[i][j].value == -1)
					{
						if (mouse.mkLButton)
						{
							box[i][j].value = PlayerColor;
							box[i][j].isnew = true;
							prei = prej = -1;
							NextPlayer = 1;
							goto DRAW;
						}

						box[prei][prej].isnew = false;
						box[prei][prej].draw();
						box[i][j].isnew = true;
						box[i][j].draw();
						prei = i, prej = j;
					}
				}
		}
		else // ��������
		{
			seat best = FindBestSeat(1 - PlayerColor);

			if (best.num == 0) // �տ���
			{
				int i = 9, j = 9;
				while (box[i][j].value != -1)
					i--, j++;
				box[i][j].value = 1 - PlayerColor;
				box[i][j].isnew = true;
			}
			else
			{
				box[best.i][best.j].value = 1 - PlayerColor;
				box[best.i][best.j].isnew = true;
			}
			NextPlayer = 0;
			goto DRAW;
		}
	}
DRAW:
	iswin();
	draw();

	if (win == -1)
	{
		Sleep(500);
		goto NEXTPLAYER;
	}

	settextcolor(RGB(0, 255, 0));
	settextstyle(30, 15, _T("��������"));
	Sleep(1000);
	IMAGE flag;
	switch (win)
	{
	case 0:
		loadimage(&flag, "./resources/white_win.png");
		drawimg(&flag, 300, 300);
		break;
	case 1:
		loadimage(&flag, "./resources/black_win.png");
		drawimg(&flag, 300, 300);
		break;
	case 2:
		outtextxy(320, 320, _T("ƽ�֣�"));
		break;
	}
	Sleep(5000);
	return;
}