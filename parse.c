#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"

char *ft_read_dict(char *pathname, int *len)
{
	int fd;
	int len_dict;
	char buff[1000];

	fd = open(pathname, O_RDONLY);//읽기 전용//성공시 파일디스크립터 반환, 실패시 -1 반환
	if (fd == -1)
	{
		//파일 읽기 실패시..처리 사항
	}
	len_dict = read(fd, buff, 1000);//read함수는 읽어들인 바이트수를 반환한다.
	*len = len_dict;
	close(fd);//파일을 닫는다.
	return (buff);
}

t_data *ft_dict_to_data(char *arr, int line)
{
	int i;
	int j;
	char *pos;
	char *find;
	t_data *data_arr;
	data_arr = (t_data *) malloc(sizeof(t_data) * line);//dict 줄수 만큼 data_arr배열크기로 동적할당
	pos = arr;
	i = 0;
	j = 0;
	while (j < line)
	{
		while (pos[i] != ' ')
		{
			if(pos[i]<'0' || pos[i]>'9')
			{
				return (0);
			}
			i++;
		}
		find = &pos[i];
		*find = '\0';
		ft_strcpy(data_arr[j].key, pos);
		pos = ++find;
		i = 0;
		while (pos[i] != ':')
		{
			if(pos[i]!=' ')
				return (0);
			i++;
		}
		while(!((pos[i]>='a' && pos[i]<='z') || (pos[i]>='A'&&pos[i]<='Z')))
		{
			if(pos[i]!=' ')
				return (0);
			i++;
		}
		pos=&pos[i];
		i=0;
		while(pos[i]!='\n')
		{
			if(!((pos[i]>='a' && pos[i]<='z') || (pos[i]>='A'&&pos[i]<='Z')))
				return (0);
			i++;
		}
		find = &pos[i];
		*find = '\0';
		ft_strcpy((data_arr[j].value), pos);
		j++;
		pos=++find;
	}
	return (data_arr);
}
