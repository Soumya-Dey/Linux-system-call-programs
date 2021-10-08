#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fdOld, fdNew;
	char ch;

	fdOld = open("sample-old.txt", O_RDONLY);
	fdNew = open("sample-new.txt", O_RDWR  | O_CREAT);
	
	while(read(fdOld, &ch, 1))
	{
		if(ch >= '0' && ch <= '9') ch = '#';

		write(fdNew, &ch, 1);	
	}

 	close(fdOld);
 	close(fdNew);
 	return 0;
}