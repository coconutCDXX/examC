#include "header.h"

int main(int ac, char **av)
{
	int i = 0, rad, i2;
	char **tab;

	if (ac == 1)
	{
		write(1, "\n", 1);
		return 0;
	}
	rad = ac - 1;
	tab = (char**)malloc(sizeof(char*) * rad);
	while (i < rad)
	{
		*tab = (char*)malloc(sizeof(char) * rad + 1);
		i++;
		tab++;
	}
	tab = tab - i;
	av++;
	for (i = 0; i < rad; av++)
	{
		for (i2 = 0; i2 < rad; i2++)
		{
			tab[i][i2] = **av;
			(*av)++;
		}
		(*av) = (*av) - i2;
		i++;
	}
	for (i = 0; i < rad; i++)
	{
		for (i2 = 0; i2 < rad; i2++)
		{			
			if (check(tab, tab[i][i2], i, i2, rad))
			{
				write(1, "Success\n", 8);
				return 0;
			}
		}
	}
	write(1, "Fail\n", 5);
	return 0;
}

