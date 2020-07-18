#ifndef RUSH02_H
#define RUSH02_H
//#define DICT	"numbers.dict"
/*#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data
{
	char key[100];
	char val[100];
} t_data;

int ft_strlen(char *str);
void ft_strcpy(char *dest, char *src);
void ft_read_dict(char *pathname, char *buff, int *len);
t_data *ft_str_parsing(char *str, int line);
#endif

