#include <brackets.h>

signs	*ft_lstnew(char a, char b)
{
	signs *new;

	new = (signs *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new.s = a;
	new.check = b;
	new->next = NULL;
	return (new);
}

signs *add_list(char a, signs st)
{
	signs *add;

	add = ft_lstnew(a, st.check);
	st->next = add;
}
char tabga[] = { '(', '{', '[', '\0' };
char tabdr[] = { ')', '}', ']', '\0' };

int check(char s)
{
	int i = 0;

	while (tabga[i] != '\0')
	{
		if (tabga[i] == s || tabdr[i] == s)
			return 1;
		i++;
	}
	return 0;
}

int main(int ac, char **av)
{
	signs *start;

	av++;
	while (**av != '\0')
	{
		if (check(**av))
		{
			if (start != NULL)
				start = ft_lstnew(**av, **av);
			else
			{
				start->next = add_list(**av, start);

			(*av)++;
		}
	}
}
