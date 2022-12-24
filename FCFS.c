#include<stdio.h>
#include<stdbool.h>
typedef struct process
{
    int pid , at , bt , st , ct , tat , wt , rt  ;
}process;
bool comp(const void* p1,const void *p2)
{
    process *ps1 = (process*) p1 ;
    process *ps2 = (process*) p2 ;
    return ps1->at > ps2->at ;
}
int main() 
{
    int n , i ;
    printf("Enter No. of Processes : ");
    scanf("%d",&n) ;
    process p[n] ; // array of processes 
    printf("Enter %d Process Details (Pid AT BT) \n",n);
    for(i=0;i<n;i++){
        scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt) ;
    }
    qsort(p,n,sizeof(process),comp) ;
    int curr_time = 0 , idle = 0 ;
    float avg_tat = 0 , avg_wt = 0 , avg_rt  = 0;
    for(i=0;i<n;i++)
    {
        int extra ;
        if(p[i].at <= curr_time){
            p[i].st = curr_time ;
            p[i].ct = curr_time + p[i].bt ;
        }
        else{
            extra  = p[i].at - curr_time; 
            idle += extra ;
            p[i].st = curr_time + extra ;
            p[i].ct = curr_time + extra + p[i].bt ;
        }
        curr_time = p[i].ct ;
        p[i].tat = p[i].ct - p[i].at ; // TAT = CT -AT
        p[i].wt = p[i].tat - p[i].bt ; // WT  = TAT -BT
        p[i].rt = p[i].st - p[i].at ; // RT = ST -AT

        avg_tat += p[i].tat ;
        avg_wt += p[i].wt ;
        avg_rt += p[i].rt ;
    } 
    printf("Pid\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].tat,p[i].wt,p[i].rt) ;
    }
    avg_tat = avg_tat/(float)n ;
    avg_wt = avg_wt/(float)n ;
    avg_rt = avg_rt/(float)n ;
    int len_cycle = p[n-1].ct - p[0].at ;
    float cpu_utilization = (len_cycle-idle)*100/(float)len_cycle ;
    printf("CPU Idle Time =  %d \n",idle) ;
    printf("Average TAT Time =  %.3f \n",avg_tat) ;
    printf("Average WT  Time =  %.3f \n",avg_wt) ;
    printf("Average RT  Time =  %.3f \n",avg_rt) ;
    printf("CPU Utilization  =  %.3f \n",cpu_utilization) ;
    return 0 ;
}