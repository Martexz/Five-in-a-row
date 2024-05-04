#include "enemy.h"

seat FindBestSeat(int color)
{
	int Score[3][5] = {
		{ 0, 20, 360, 5800, 92840 }, 
		{ 0, 0, 20, 360, 92840 },    
		{ 0, 0, 0, 0, 92840 }        
	};
	seat bestseat;              
	int Max_num[361] = { 0 }; 
	int Max_x[361] = { 0 };      
	int Max_y[361] = { 0 };     
	int num = 0;             
	int res;             // 输出的最佳分数位置
	int nowi = 0;               
	int nowj = 0;               
	int len[4];              // 四个方向的长度
	int enemy[4];            // 四个方向的敌子
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (box[i][j].value == -1)
			{
				box[i][j].value = color; // 尝试下在这里
				for (int k = 0; k < 4; k++)
				{
					len[k] = 0;
					enemy[k] = 0;
					nowi = i;
					nowj = j;
					while (nowi <= 18 && nowj <= 18 && nowi >= 0 && nowj >= 0 && box[nowi][nowj].value == color)
					{
						len[k]++;
						nowj += dx[k];
						nowi += dy[k];
					}
					if (box[nowi][nowj].value == 1 - color || nowi < 0 || nowj < 0 || nowi > 18 || nowj > 18)
					{
						enemy[k]++;
					}
					nowi = i;
					nowj = j;
					while (nowi <= 18 && nowj <= 18 && nowi >= 0 && nowj >= 0 && box[nowi][nowj].value == color)
					{
						len[k]++;
						nowj -= dx[k];
						nowi -= dy[k];
					}
					if (box[nowi][nowj].value == 1 - color || nowi < 0 || nowj < 0 || nowi > 18 || nowj > 18)
					{
						enemy[k]++;
					}
					len[k] -= 2; 
					if (len[k] > 4)
					{
						len[k] = 4;
					}
					box[i][j].num += Score[enemy[k]][len[k]] * 4 + !(!len[k]) * 20;//加分
					len[k] = 0;
					enemy[k] = 0;
				}
				// 敌人
				box[i][j].value = 1 - color;
				for (int k = 0; k < 4; k++)
				{
					len[k] = 0;
					enemy[k] = 0;
					nowi = i;
					nowj = j;
					while (nowi <= 18 && nowj <= 18 && nowi >= 0 && nowj >= 0 && box[nowi][nowj].value == 1 - color)
					{
						len[k]++;
						nowj += dx[k];
						nowi += dy[k];
					}
					if (box[nowi][nowj].value == color || nowi < 0 || nowj < 0 || nowi > 18 || nowj > 18)
					{
						enemy[k]++;
					}
					nowi = i;
					nowj = j;
					while (nowi <= 18 && nowj <= 18 && nowi >= 0 && nowj >= 0 && box[nowi][nowj].value == 1 - color)
					{
						len[k]++;
						nowj -= dx[k];
						nowi -= dy[k];
					}
					if (box[nowi][nowj].value == color || nowi < 0 || nowj < 0 || nowi > 18 || nowj > 18)
					{
						enemy[k]++;
					}
					len[k] -= 2;
					if (len[k] > 4)
					{
						len[k] = 4;
					}
					box[i][j].num += Score[enemy[k]][len[k]];
					len[k] = 0;
					enemy[k] = 0;
				}
				box[i][j].value = -1;
			}
			if (box[i][j].num == Max_num[0])
			{
				Max_num[num] = box[i][j].num;
				Max_y[num] = i;
				Max_x[num] = j;
				num++;
			}
			if (box[i][j].num > Max_num[0])
			{
				for (int k = 0; k < num; k++)
				{
					Max_num[k] = 0;
					Max_y[k] = 0;
					Max_x[k] = 0;
				}
				num = 0;
				Max_num[num] = box[i][j].num;
				Max_y[num] = i;
				Max_x[num] = j;
				num++;
			}
		}
	}
	srand(time(NULL));
	res = rand() % num;
	bestseat.i = Max_y[res];
	bestseat.j = Max_x[res];
	bestseat.num = Max_num[res];

	return bestseat;
}