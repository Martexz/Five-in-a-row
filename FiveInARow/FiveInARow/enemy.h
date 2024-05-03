#pragma once
#include "Board.h"
#include <ctime>
#include <cstdlib>

int dx[4] = { 1, 0, 1, 1 };
int dy[4] = { 0, 1, 1, -1 };

seat FindBestSeat(int color)
{

	int Score[3][5] = {
		{0, 20, 360, 5800, 92840},
		{0, 0, 20, 360, 92840},
		{0, 0, 0, 0, 92840}
	};

	seat bestseat;
	int Max_num[361] = { 0 };
	int Max_x[361] = { 0 };
	int Max_y[361] = { 0 };
	int num = 0;
	int result; // ×î¼ÑÎ»ÖÃ
	int now_i = 0, now_j = 0;
	int len[4], enemy[4];

	for (int i = 0 ; i < 19; i ++)
		for (int j = 0; j < 19; j++)
		{
			if (box[i][j].value == -1)
			{
				box[i][j].value = color;
				for (int k = 0; k < 4; k++)
				{
					len[k] = 0;
					enemy[k] = 0;
					now_i = i;
					now_j = j;

					while (0 <= now_i && now_i <= 18 && 0 <= now_j && now_j <= 18 && box[now_i][now_j].value == color)
					{
						len[k]++;
						now_i += dx[k];
						now_j += dy[k];
					}
					if (box[now_i][now_j].value == 1 - color || now_i < 0 || now_i > 18 || now_j < 0 || now_j > 18)
						enemy[k]++;

					now_i = i;
					now_j = j;

					while (0 <= now_i && now_i <= 18 && 0 <= now_j && now_j <= 18 && box[now_i][now_j].value == color)
					{
						len[k]++;
						now_i -= dx[k];
						now_j -= dy[k];
					}
					if (box[now_i][now_j].value == 1 - color || now_i < 0 || now_i > 18 || now_j < 0 || now_j > 18)
						enemy[k]++;
					len[k] -= 2;
					if (len[k] > 4) len[k] = 4;

					box[i][j].num += Score[enemy[k]][enemy[k]];
					len[k] = enemy[k] = 0;
				}

				box[i][j].value = 1 - color;
				for (int k = 0; k < 4; k++)
				{
					len[k] = 0;
					enemy[k] = 0;
					now_i = i;
					now_j = j;

					while (0 <= now_i && now_i <= 18 && 0 <= now_j && now_j <= 18 && box[now_i][now_j].value == color)
					{
						len[k]++;
						now_i += dx[k];
						now_j += dy[k];
					}
					if (box[now_i][now_j].value == 1 - color || now_i < 0 || now_i > 18 || now_j < 0 || now_j > 18)
						enemy[k]++;

					now_i = i;
					now_j = j;

					while (0 <= now_i && now_i <= 18 && 0 <= now_j && now_j <= 18 && box[now_i][now_j].value == color)
					{
						len[k]++;
						now_i -= dx[k];
						now_j -= dy[k];
					}
					if (box[now_i][now_j].value == 1 - color || now_i < 0 || now_i > 18 || now_j < 0 || now_j > 18)
						enemy[k]++;
					len[k] -= 2;
					if (len[k] > 4) len[k] = 4;

					box[i][j].num += Score[enemy[k]][enemy[k]];
					len[k] = enemy[k] = 0;
				}
				box[i][j].value = -1;
			}
			if (box[i][j].num == Max_num[0])
			{
				Max_num[num] = box[i][j].num;
				Max_x[num] = i, Max_y[num] = j;
				num++;
			}

			if (box[i][j].num > Max_num[0])
			{
				for (int k = 0; k < num; k++)
				{
					Max_num[k] = Max_x[k] = Max_y[k] = 0;
				}
				num = 0;
				Max_num[num] = box[i][j].num;
				Max_x[num] = i, Max_y[num] = j;
				num++;
			}
		}

	srand(time(NULL));
	result = rand() % num;
	bestseat.i = Max_y[result];
	bestseat.j = Max_x[result];
	bestseat.num = Max_num[result];

	return bestseat;
}
