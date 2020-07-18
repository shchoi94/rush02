#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	int fd;
	if(argc==2)
	{
		fd=open("numbers.dict",O_RDWR);
		if(fd==-1)
			printf("file not open\n");
	}
return 0;
}
