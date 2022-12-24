#include<stdio.h>
#include<stdbool.h>
typedef struct process
{
    int pid , at , bt , st , ct , tat , wt , rt , rem_bt ;
}process;
bool comp(const void* p1,const void *p2)
{
    process *ps1 = (process*) p1 ;
    process *ps2 = (process*) p2 ;
    return ps1->at > ps2->at ;
}
int findMax(int a,int b){
    return a>b ? a : b ;
}
int main() 
{
    int n , i , q ;
    printf("Enter No. of Processes : ");
    scanf("%d",&n) ;
    process p[n] ; // array of processes 
    printf("Enter %d Process Details (Pid AT BT) \n",n);
    for(i=0;i<n;i++){
        scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt) ;
        p[i].rem_bt = p[i].bt ;
    }
    printf("Enter Time Quanta : ");
    scanf("%d",&q) ;
    qsort(p,n,sizeof(process),comp) ;
    int curr_time = 0 , idle = 0 , completed = 0 , ind  ;
    float avg_tat = 0 , avg_wt = 0 , avg_rt  = 0;
    int queue[100] , front , rear ;
    front = rear  = 0 ;
    queue[0] = 0 ; // first process
    bool visited[100] ;
    for(i=0;i<100;i++){
        visited[i] = false ;
    }
    visited[0] = true ;
    while(completed!=n)
    {
        ind = queue[front] ;
        front ++ ;
        if(p[ind].rem_bt == p[ind].bt){
            p[ind].st = findMax(curr_time,p[ind].at) ;
            curr_time = p[ind].st ;
        }
        if(p[ind].rem_bt - q > 0){
            p[ind].rem_bt = p[ind].rem_bt - q ;
            curr_time =  curr_time + q ;
        }
        else{
            int t = p[ind].rem_bt ;
            p[ind].rem_bt = p[ind].rem_bt - t ;
            curr_time = curr_time + t ;
            p[ind].ct = curr_time ;
            p[ind].tat = p[ind].ct - p[ind].at ;
            p[ind].wt = p[ind].tat - p[ind].bt ;
            p[ind].rt = p[ind].st - p[ind].at ;
            
            avg_tat += p[ind].tat ;
            avg_wt += p[ind].wt ;
            avg_rt += p[ind].rt ;
            completed++ ;
        }
        for(i=0;i<n;i++){
            if(p[i].rem_bt>0  && p[i].at<=curr_time && visited[i]==false){
                queue[++rear] = i ;
                visited[i] = true ;
            }
        }
        if(p[ind].rem_bt>0){
            queue[++rear] = ind ;
        }
        if(front>rear){
            for(i=1;i<n;i++){
                if(p[i].rem_bt>0){
                    queue[++rear] = i ;
                    break;
                }
            }
        }
    }
    printf("Pid\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].tat,p[i].wt,p[i].rt) ;
    }
    avg_tat = avg_tat/(float)n ;
    avg_wt = avg_wt/(float)n ;
    avg_rt = avg_rt/(float)n ;
    printf("CPU Idle Time =  %d \n",idle) ;
    printf("Average TAT Time =  %.3f \n",avg_tat) ;
    printf("Average WT  Time =  %.3f \n",avg_wt) ;
    printf("Average RT  Time =  %.3f \n",avg_rt) ;
    return 0 ;
}