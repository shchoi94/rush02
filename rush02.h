#ifndef RUSH02_H
#define RUSH02_H

/*#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>*/

typedef struct s_data
{
	char key[100];
	char value[100];
} t_data;

int ft_strlen(char *str);
void ft_strcpy(char *dest, char *src);

#endif

