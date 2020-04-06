#include<stdio.h>
#include<unistd.h> /*for STDOUT_FILENO*/
#include<stdlib.h> 
#include<fcntl.h> /*for open*/
#include<sys/types.h>

void parent()
{
	pid_t fd;
	fd=fork();
	if(fd<0)
	child();
	else if(fd==0)
	printf("Child process not created");
	
	
}

 
int main()
{ 
	parent();
    
 
    return 0;

}
