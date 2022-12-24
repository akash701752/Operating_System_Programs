#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("Fork Even Odd Sum Implementation \n");
    int n ;
    printf("Enter Size : ");
    scanf("%d",&n) ;
    int arr[n] , i , even =0 , odd = 0 ;
    printf("Enter %d Elements \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int pid = fork() ;
    if(pid!=0){
        for(i=0;i<n;i++){
            if(arr[i]%2!=0){
                odd += arr[i] ;
            }
        }
        printf("Sum of Odd Numbers : %d \n",odd);
    }
    else{
        for(i=0;i<n;i++){
            if(arr[i]%2==0){
                even += arr[i] ;
            }
        }
        printf("Sum of Even Numbers : %d \n",even);
    }
    return 0 ;
}
