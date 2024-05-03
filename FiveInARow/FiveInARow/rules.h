#pragma once

#include "enemy.h"

int win = -1;
int NextPlayer = 0;
int PlayerColor = 0;

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
					// ԭ��ͬѰ�����λ��
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
						// ���������
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

void MainGame()
{
	int prei = 0, prej = 0;
	
}