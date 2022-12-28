#include<stdio.h>
#include<limits.h>
typedef struct pageTable
{
    int frame , valid , accessTime ;
}pageTable;
int search(int frame[],int key,int n)
{
    int ind = -1 , i ;
    for(i=0;i<n;i++){
        if(frame[i]==key){
            ind = i ;
            break;
        }
    }
    return ind ;
}
int lruSearch(pageTable PT[],int n)
{
    int frame_ind = -1 , ind=-1 , min_lru = INT_MAX  , i ;
    for(i=0;i<n;i++)
    {
        if(PT[i].valid == 1 && PT[i].accessTime < min_lru){
            ind = i ;
            frame_ind = PT[i].frame ;
            min_lru = PT[i].accessTime ;
        }
    }
    PT[ind].valid = 0 ; // updating PT
    return frame_ind ;
}
int main()
{
    int n , i , j , n_frame ;
    printf("Enter No. of Pages Requests : ");
    scanf("%d",&n);
    int page[n] ; 
    printf("Enter %d Pages Requests \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&page[i]);
    }
    pageTable PT[50]  ; int size =50 ;
    for(i=0;i<size;i++){
        PT[i].valid = 0 ;
    }
    printf("Enter No. of Frames : ");
    scanf("%d",&n_frame);
    int frame[n_frame] ;
    for(i=0;i<n_frame;i++){
        frame[i] = -1;
    }
    int pageFault = 0 , hit = 0 , flag = 0 , current = 0 ;
    for(i=0;i<n;i++)
    {
        int ind = search(frame,page[i],n_frame) ; 
        if(ind==-1)
        {
            //page fault 
            pageFault++ ;
            if(flag==0 && current < n_frame)
            {
                frame[current] = page[i] ;
                PT[page[i]].valid = 1 ;
                PT[page[i]].frame = current ;
                PT[page[i]].accessTime = i ;
                
                current++ ;
                if(current==n_frame){
                    flag = 1 ;
                }
            }
            else
            {
                int lru_ind = lruSearch(PT,size);
                frame[lru_ind] = page[i] ;
                PT[page[i]].accessTime = i ;
                PT[page[i]].valid = 1 ;
                PT[page[i]].frame = lru_ind ;
                current++;
            } 
        }
        else{
            hit++ ;
            PT[page[i]].accessTime = i ;
        }
        printf("Frame : ");
        for(j=0;j<n_frame;j++){
            printf("%d ",frame[j]) ;
        }
        printf("\n");
    }
    printf("Number of Page Faults : %d \n",pageFault) ;
    printf("Number of Page Hits : %d \n",hit) ;
    return 0 ;
}