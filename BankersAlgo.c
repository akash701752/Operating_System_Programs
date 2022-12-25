#include<stdio.h>
#include<stdbool.h>
typedef struct process
{
    int pid , allocated[3] , maxNeed[3] , need[3] ;
    bool status ;
}process;
int findProcess(process p[], int curr_avail[],int res,int n)
{
    int i , j , ind = -1 ;
    for(i=0;i<n;i++){
        if(p[i].status == false){
            int count = 0 ; bool flag = true ;
            for(j=0;j<res;j++){
                if(p[i].need[j]>curr_avail[j]){
                    flag = false ;
                    break ;
                }
                else{
                   count++ ;
                }
            }
            if(count==res){
                ind = i ;
                break;
            }
        }
    }
    return ind  ;
}
int main() 
{
    int n , i , j ,  res = 3 ;
    printf("Enter No. of Processes : ");
    scanf("%d",&n) ;
    process p[n] ; // array of processes 
    int maxAvail[res] , totalAllocated[res]  , curr_avail[res] ;
    printf("Enter MAximum Availabilty of Resourses \n");
    for(i=0;i<res;i++){
        scanf("%d",&maxAvail[i]) ;
        totalAllocated[i] = 0 ;
    }
    printf("Enter %d Process Details (Pid Allocated MaxNeed) \n",n);
    for(i=0;i<n;i++)
    {
        //printf("Enter Pid : ") ;
        scanf("%d",&p[i].pid) ; //pid
        // printf("Enter Allocated Resourse for %d Resource : ",res) ;
        for(j=0;j<res;j++){
            scanf("%d",&p[i].allocated[j]) ;
            totalAllocated[j] += p[i].allocated[j] ; // for finding total allocated proces
        }
        //printf("Enter Max Requirement for %d Resource : ",res) ;
        for(j=0;j<res;j++){
            scanf("%d",&p[i].maxNeed[j]) ;
        }
        for(j=0;j<res;j++){
            p[i].need[j] = p[i].maxNeed[j] - p[i].allocated[j] ;
        }
        p[i].status = false ;
    }
    // Calculating Current Resource Available
    printf("Curren available : ");
    for(i=0;i<res;i++){
        curr_avail[i] = maxAvail[i] - totalAllocated[i] ;
        printf("%d  ",curr_avail[i]);
    }
    printf("\n") ;
    int completed = 0 , sequence[n] , k = 0 , flag = 0 ;
    printf("Need Array \n") ;
    for(i=0;i<n;i++)
    {
        printf("%d  ",p[i].pid) ;
        for(j=0;j<res;j++){
            printf("%d  ",p[i].need[j]) ;
        }
        printf("\n") ;
    }
    while(completed!=n)
    {
        int ind = findProcess(p,curr_avail,res,n) ;
        if(ind!=-1)
        {
            p[ind].status = true ;
            for(j=0;j<res;j++){
                curr_avail[j] = curr_avail[j] + p[ind].allocated[j] ;
            }
            sequence[k++] = ind ;
            completed++ ;
        }
        else{
            printf("!!!! Deadlock !!!! \n") ;
            flag = 1 ;
            break ;
        }
    }

    if(flag==0){
        printf("The Sequence is : ") ;
        for(i=0;i<n;i++){
            printf("%d  ",sequence[i]) ;
        }
    }
    return 0 ;
}