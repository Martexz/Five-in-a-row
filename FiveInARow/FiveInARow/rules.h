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
				int len[4] = { 0,0,0,0 };    // 四个方向的长度
				for (int k = 0; k < 4; k++)
				{
					// 原理同寻找最佳位置
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
						// 如果满五子
						if (NowColor == PlayerColor)
						{
							win = PlayerColor; // 玩家胜
						}
						if (NowColor == 1 - PlayerColor)
						{
							win = 1 - PlayerColor; // 电脑胜
						}
					}
				}
				if ((!isinit) && FindBestSeat(PlayerColor).num == 0 && FindBestSeat(1 - PlayerColor).num == 0)
				{
					// 如果不是开局且双方无最佳位置
					win = 2; // 平局
				}
			}
		}
	}
}

void MainGame()
{
	int prei = 0, prej = 0;
	
}