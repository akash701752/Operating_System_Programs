#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("Fork Implementation \n");
    printf("Before Fork \n");
    fork() ;
    printf("After Fork \n");
    fork();
    printf("Process Id = %d \n",getpid()) ;
    return 0 ;
}
