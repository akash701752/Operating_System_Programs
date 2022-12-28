#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n , i , j , ind , completed = 0 , head , high , low ;
    printf("Enter No. of Requests : ");
    scanf("%d",&n);
    int req[n] , seq[n]; 
    printf("Enter %d requests \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter Head Position : ");
    scanf("%d",&head);
    printf("Enter Low and High Value  : ");
    scanf("%d%d",&low,&high);
    int head_move = 0 ;
    //Sort
    for(i=0;i<n-1;i++)
    {
        int min = i ;
        for(j=i+1;j<n;j++){
            if(req[j]<req[min]){
                min = j ;
            }
        }
        if(min!=i){
            int temp = req[min] ;
            req[min] = req[i] ;
            req[i] = temp ;
        }
    }
    //Finding Greater value than cuurrent head ;
    for(i=0;i<n;i++){
        if(req[i]>head){
            ind = i ;
            break;
        }
    }
    j=0;
    for(i=ind;i<n;i++){
        head_move += abs(head-req[i]) ;
        seq[j++] = req[i] ;
        head = req[i] ;
    }
    head_move += abs(high-head) ;
    head = high ; // direction is towards higher value
    for(i=ind-1;i>=0;i--){
        head_move += abs(head-req[i]) ;
        seq[j++] = req[i];
        head = req[i] ;
    }
    printf("Seek Sequence : ");
    for(i=0;i<n;i++){
        printf("%d ",seq[i]) ;
    }
    printf("\nNo. of Head Movements : %d \n",head_move);
    printf("Average Head Movements : %.3f \n",(float)head_move/(float)n);
    return 0 ;
}