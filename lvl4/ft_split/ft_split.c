#include <stdlib.h>

int is_space(char a)
{
	if(a  == ' ' || a == '\t' || a == '\n')
		return 1;
	else
		return 0;
}

char **ft_split(char *str)
{
	int i = 0, word = 0, leng = 0, wordi;
	char **split;

	while (str[i] != '\0')
	{
		while (is_space(str[i]))
			i++;
		if (str[i] == '\0')
			break;
		while (!(is_space(str[i])) && str[i] != '\0')
			i++;
		word++;
	}
	if (word == 0)
		return NULL;
	split = (char**)malloc(sizeof(char*) * word);
	for (i = 0; str[i];)
	{
		leng = 0;
		while (is_space(str[i]))
			i++;
		if (str[i] == '\0')
			break;
		while (!(is_space(str[i])) && str[i] != '\0')
		{
			i++;
			leng++;
		}
		*split = (char*)malloc(sizeof(char) * leng + 1);
		split++;
	}
	split = split - word;
	wordi = 0;
	for (i = 0; word > 0; word--)
	{
		while (is_space(str[i]))
			i++;
		for (leng = -1; is_space(str[i]) == 0 && str[i] != '\0'; i++) 
			split[wordi][++leng] = str[i];
		split[wordi][leng + 1] = '\0';
		wordi++;
	}
	return split;
}

