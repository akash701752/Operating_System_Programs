#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n , low ,high , i , j , ind , k=0 , head , head_move = 0 ;
    printf("Enter No. of Requests : ");
    scanf("%d",&n);
    int req[n] , seq[n];
    printf("Enter %d Requests \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&req[i]) ;
    }
    printf("Head Position : ");
    scanf("%d",&head) ;
    printf("Enter Low and High Value : ");
    scanf("%d%d",&low,&high) ;
    for(i=0;i<n;i++){
        int min = i ;
        for(j=i+1;j<n-1;j++){
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
    for(i=0;i<n;i++){
        if(req[i]>=head){
            ind = i ;
            break ;
        }
    }
    for(i=ind;i<n;i++){
        seq[k++] = req[i] ;
    }
    for(i=0;i<ind;i++){
        seq[k++] = req[i] ;
    }
    head_move += abs(high-head) ;
    head_move += abs(high-low) ;
    head_move += abs(req[ind-1]-low) ;
    printf("Sequence : ");
    for(i=0;i<n;i++){
        printf("%d ",seq[i]);
    }
    printf("\nTotal Head Movements : %d \n",head_move) ;
    return 0 ;
}