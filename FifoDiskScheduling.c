#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n , i , head , head_move = 0 ;
    printf("Enter No. of Requests : ");
    scanf("%d",&n) ;
    int req[n] ;
    printf("Enter %d Reuests \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter Head Position : ");
    scanf("%d",&head);
    for(i=0;i<n;i++){
        head_move += abs(head - req[i]) ;
        head = req[i] ;
    }
    printf("Number of Head Movement = %d \n",head_move) ;
    printf("Average  Head  Movement = %.2f \n",(float)head_move/(float)n) ;
    return 0 ;
}