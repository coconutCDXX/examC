#include "header.h"

int blocker(char a)
{
	if (a == 'Q' || a == 'P' || a == 'B' || a == 'R')
		return 1;
	else
		return 0;
}


int check(char **t, char c, int x, int y, int rad)
{
	int i = 1;
	int i2 = 1;
	
	if (c == 'P')
	{
		if (x == 0)
			return 0;
		if (t[x + 1][y - 1] == 'K' || t[x - 1][y - 1] == 'K')
			return 1;
	}
	if (c == 'R' || c == 'Q')
	{		
		while (x + i < rad)
		{
			if (t[x + i][y] == 'K')
				return 1;
			if (x + i >= rad)
			{
				i = rad + i;
				break;
			}
			if (blocker(t[x + i][y]))
				i = rad + 1;
			i++;
		}
		i = 1;
		while (y + i < rad)
		{
			if (t[x][y + i] == 'K')
				return 1;
			if (y + i >= rad)
			{
				i = rad + i;
				break;
			}
			if (blocker(t[x][y + i]))
				i = rad + 1;
			i++;
		}
		i = -1;
		while (x + i >= 0)
		{
			if (t[x + i][y] == 'K')
			   return 1;
			if (x + i < 0)
			{
				i = (-1) * rad - 1;
				break;
			}
			if (blocker(t[x + i][y]))
				i = (-1) * rad - 1;
			i--;
		}
		i = -1;
		while (y + i >= 0)
		{
			if (t[x][y + i] == 'K')
				return 1;
			if (y + i < 0)
			{
				i = (-1) * rad - 1;
				break;
			}
			if (blocker(t[x][y + i]))
				i = (-1) * rad - 1;
			i--;
		}
	}
	if (c == 'B' || c == 'Q')
	{
		i = 1;
		while (x + i < rad && y + i < rad)
		{
			if (t[x + i][y + i] == 'K')
				return 1;
			if (x + 1 >= rad || y + i >= rad)
			{
				i = rad + i;
				break;
			}
			if (blocker(t[x + i][y + i]))
				i = rad + 1;
			i++;
		}
		i = -1;
		while (x + i >= 0 && y + i2 < rad)
		{
			if (t[x + i][y + i2] == 'K')
				return 1;
			i--;
			if (x + i < 0 || y + i2 >= rad)
			{
				i = (-1) * rad - 1;
				break;
			}
			if (blocker(t[x + i][y + i2]))
				i = (-1) * rad - 1;
			i2++;
		}
		i = 1;
		i2 = -1;
		while (x + i < rad && y + i2 >= 0)
		{
			if (t[x + i][y + i2] == 'K')
				return 1;
			i++;
			if (x + i >= rad || y + i2 < 0)
			{
				i = rad + 1;
				break;
			}
			if (blocker(t[x + i][y + i2]))
				i = rad + 1;
			i2--;
		}
		i = -1;
		while (x + i >= 0 && y + i >= 0)
		{
			if (t[x + i][y + i] == 'K')
				return 1;
			if (x + i < 0 || y + i < 0)
			{
				i = (-1) * rad - 1;
				break;
			}
			if (blocker(t[x + i][y + i]))
				i = (-1) * rad - 1;
			i--;
		}
	}
	return 0;
}
























