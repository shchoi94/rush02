#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"

void ft_read_dict(char *pathname,char *buff, int *len)
{
	int fd;
	int len_dict;

	fd = open(pathname, O_RDONLY);//읽기 전용//성공시 파일디스크립터 반환, 실패시 -1 반환
	if (fd == -1)
	{
		//파일 읽기 실패시..처리 사항
	}
	len_dict = read(fd, buff, 1000);//read함수는 읽어들인 바이트수를 반환한다.
	*len = len_dict;
	close(fd);//파일을 닫는다.
}

t_data *ft_str_parsing(char *str, int line)
{
	int i;
	int j;
	int k;
	t_data *data_arr;

	data_arr = (t_data *)malloc(sizeof(t_data) * (line + 1));//dict 줄수 만큼 data_arr배열크기로 동적할당

	i = 0;
	j = -1;
	printf("%d\n", line);
	while(++j < line)
	{
		while (str[i] == '\n')
			i++;
		while(!(str[i] >= '0' && str[i] <= '9'))
		{
			return (0);
		}
		k = 0;
		while(str[i] >= '0' && str[i] <= '9')
			data_arr[j].key[k++] = str[i++];
		data_arr[j].key[k] = '\0';
		printf("key : %s, ", data_arr[j].key);
		while (str[i] == ' ')
			i++;
		if (str[i] == ':')
			i++;
		else
			return (0);
		while (str[i] == ' ')
			i++;
		k = 0;
		while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			data_arr[j].val[k++] = str[i++];
		data_arr[j].val[k] = '\0';
		printf("val : %s\n", data_arr[j].val);
	}
	*data_arr[line].key =  0;
	return (data_arr);
}
