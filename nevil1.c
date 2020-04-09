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
void child(int argc,char *argv[])
{
	int fd, i, ch; 
    
    for (i = 1; i < argc; i++) {                    /*iterate the loop for total argument count.*/
        
        fd = open(argv[1],O_RDONLY);            /*open the file in READONLY mode*/
        
        if(fd < 0) { 
            perror("open"); 
            goto OUT; 
        } 
        
        while(read(fd,&ch,1))                   /*Read one byte at a time*/
            
            write(STDOUT_FILENO,&ch,1);     /*Write the byte on Stdout*/
        
        close(fd);                              /*close the file discriptor*/
    }
    OUT: 
        return -1;
	
}
 
int main()
{ 
	parent();
    
 
    return 0;

}