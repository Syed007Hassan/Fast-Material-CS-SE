#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	int fd, retval;
	char buffer[] = "TESTDATA";
	
	fd = open("/tmp/myfifo",O_RDONLY);
	retval = read(fd, buffer, sizeof(buffer));
	fflush(stdin);
	write(1, buffer, sizeof(buffer));
	printf("\n");	
	close(fd);
	return 0;
}
