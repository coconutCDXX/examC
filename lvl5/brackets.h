#ifndef BRACKETS_H
# define BRACKETS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct 	b_list
{
	char s;
	char check;
	b_list *next;
} 				signs;

signs	*ft_lstnew(char a, char b);
signs	*add_list(char a, signs st);
int		check(char s);

#endif
