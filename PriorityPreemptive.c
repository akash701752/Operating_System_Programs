#include<stdio.h>
#include<limits.h>
typedef struct process
{
    int pid , at , bt , st , ct , tat , wt , rt ,rem_bt , status , pri ;
}process;
int findProcess(process p[],int curr_time,int n)
{
    int ind = -1 , pri = INT_MAX , i ; // min priority
    for(i=0;i<n;i++)
    {
        if(p[i].status!=2 && p[i].at<=curr_time){
            if(p[i].pri < pri){
                pri = p[i].pri ;
                ind = i ;
            }
            if(p[i].pri==pri){
                if(p[i].at<p[ind].at){
                    pri = p[i].pri ;
                    ind = i ;
                }
            }
        }
    }
    return ind ;
}
int main() 
{
    int n , i ;
    printf("Enter No. of Processes : ");
    scanf("%d",&n) ;
    process p[n] ; // array of processes 
    printf("Enter %d Process Details (Pid AT BT PRI) \n",n);
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&p[i].pid,&p[i].at,&p[i].bt,&p[i].pri) ;
        p[i].rem_bt = p[i].bt ;
        p[i].status = 0 ;
    }
    int curr_time = 0 , completed = 0 ;
    float avg_tat = 0 , avg_wt = 0 , avg_rt  = 0;
    while(completed!=n)
    {
        int ind = findProcess(p,curr_time,n) ;
        if(ind!=-1){
            if(p[ind].status==0){
                p[ind].st = curr_time ;
                p[ind].status = 1 ;
            }
            p[ind].rem_bt -- ;
            curr_time++ ;
            if(p[ind].rem_bt==0){
                p[ind].ct = curr_time ;
                p[ind].tat = p[ind].ct - p[ind].at ;
                p[ind].wt = p[ind].tat - p[ind].bt ;
                p[ind].rt = p[ind].st - p[ind].at ;
                p[ind].status = 2 ;

                avg_tat += p[ind].tat ;
                avg_wt += p[ind].wt ;
                avg_rt += p[ind].rt ;
                completed ++ ;
            }
        }
        else{
            curr_time ++ ;
        }
    }
    printf("Pid\tAT\tBT\tPRI\tST\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].pri,p[i].st,p[i].ct,p[i].tat,p[i].wt,p[i].rt) ;
    }
    avg_tat = avg_tat/(float)n ;
    avg_wt = avg_wt/(float)n ;
    avg_rt = avg_rt/(float)n ;
    printf("Average TAT Time =  %.3f \n",avg_tat) ;
    printf("Average WT  Time =  %.3f \n",avg_wt) ;
    printf("Average RT  Time =  %.3f \n",avg_rt) ;
    return 0 ;
}