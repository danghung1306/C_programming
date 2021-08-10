#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>

#define TIMEOUT 10

#define BUFFER_LENGHT 10

int main()
{
	struct timeval t_v;
	fd_set readfds;
	int ret = -1;
	
	// Khoi tao tap hop readfds
	FD_ZERO(&readfds);
	
	// ADD STDIN file descriptor into readfds
	FD_SET(STDIN_FILENO, &readfds);
	
	//setup timeout counter
	t_v.tv_sec = TIMEOUT;
	t_v.tv_usec = 0;
	
	//Block stdin untill stdin already to read.
	
	//Rally file description writefds & exceptfds by NULL
	ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &t_v);
	
	if (ret == -1)
	{
		perror("Select error:\n");
		return 1;
	}
	else if(ret)
	{
		printf("Request timeout\n");
		return 0;
	}
	else
	{
	// check whether stdin in readfds or not?
		if(FD_ISSET(STDIN_FILENO, &readfds))
		{
			char *buffer = (char*)malloc(sizeof(char)*(BUFFER_LENGHT+ 1));
			int len = -1;
			
			len = read(STDIN_FILENO,buffer, BUFFER_LENGHT);
			
			if(-1 == len)
			{
				perror("Read error\n");
				return 1;	
			}
			else
			{
				buffer[len + 1] = '\0';
				printf("The string is read from key_board: %s\n", buffer);
				return 0;
			}
		}
		else
		{
			return 1;
		}
	}
}
