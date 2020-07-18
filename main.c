#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"

int ft_strlen(char *str)
{
	int len;
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int ft_is_space(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n' ||
		ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	else
		return (0);
}

int ft_atol(char *str)
{
	int pos;
	int i;
	long long num;
	pos = 1;
	i = 0;
	num = 0;
	while (ft_is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pos *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (pos * num);
}

int ft_strcmp(char *str1, char *str2)
{
	int i;
	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int ft_valid_arg(char *str)
{
	int i;
	long long num;
	num = ft_atol(str);
	if (num < 0)
		return (0);
	else
	{
		i = 0;
		while (!(str[i] >= '0' && str[i] <= '9'))
			i++;
		if (str[i] == 0)
			return (0);
		while (str[i])
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (0);
			i++;
		}
	}
	return (1);
}

void ft_print_value(char *arg, t_data *data_arr)
{
	int i;
	i = 0;
	while (data_arr)
	{
		if (ft_strcmp(arg, data_arr[i].key) == 0)
			ft_putstr(data_arr[i].val);
		i++;
	}
}

void ft_check_dict_info(char* arr, int *size, int *line)
{
	int i;
	int newline;
	*size = ft_strlen(arr);
	newline = 0;
	i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == '\n' && arr[i - 1] != '\n')
			newline++;
		i++;
	}
	*line = newline + 1;
}

void ft_strcpy(char *dest, char *src)
{
	char *start_dest;
	start_dest = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;
}

t_data  *ft_get_data_arr(char *dict)
{
	int size=0;
	int line=0;
	char str[1000];
	t_data *data;
	ft_read_dict(dict,str, &size);
	ft_check_dict_info(str, &size, &line);
	data = ft_dict_to_data(dict, line);
	return (data);
}

int main(int argc, char **argv)
{
	char *dict;
	char *arg;
	t_data *data_arr;
	if (argc == 1 || argc > 3)
		return (0);
	else if (argc == 2)
	{
		dict = "numbers.dict";
		arg = argv[1];
	}
	else if (argc == 3)
	{
		dict = argv[1];
		arg = argv[2];
	}
	if (!ft_valid_arg(arg))
	{
		ft_putstr("Error\n");
		return (0);
	}
	data_arr = ft_get_data_arr(dict);
	ft_print_value(arg, data_arr);
	free(data_arr);
	return (0);
}

