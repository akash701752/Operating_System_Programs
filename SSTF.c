#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>
int search(int req[],bool visited[],int head,int n)
{
    int ind =-1 , min_seek = INT_MAX , i ;
    for(i=0;i<n;i++){
        if(visited[i]==false && abs(head-req[i])<min_seek){
            min_seek = abs(head-req[i]) ;
            ind = i ;
        }
    }
    return ind;
}
int main()
{
    int n , i , completed = 0 , head;
    printf("Enter No. of Requests : ");
    scanf("%d",&n);
    int req[n] ; bool visited[n] ;
    printf("Enter %d requests \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
        visited[i] = false ;
    }
    printf("Enter Head Position : ");
    scanf("%d",&head);
    int head_move = 0 , seq[n] , k = 0;
    while(completed!=n)
    {
        int ind = search(req,visited,head,n) ;
        if(ind!=-1){
            visited[ind] = true ;
            seq[k++] = req[ind] ;
            head_move += abs(head-req[ind]) ;
            head = req[ind] ;
            completed++ ;
        }
    }
    printf("Seek Sequence : ");
    for(i=0;i<n;i++){
        printf("%d ",seq[i]) ;
    }
    printf("\nNo. of Head Movements : %d \n",head_move);
    printf("Average Head Movements : %.3f \n",(float)head_move/(float)n);
    return 0 ;
}