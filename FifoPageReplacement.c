#include<stdio.h>
#include<stdbool.h>
bool search(int frames[],int n_frames,int key){
    int i ;
    for(i=0;i<n_frames;i++){
        if(frames[i]==key){
            return true ;
        }
    }
    return false ;
}
int main()
{
    int n , i , j ,  m , n_frame ;
    printf("Enter No. of Page Requests : ");
    scanf("%d",&n) ;
    int pages[n] ;
    printf("Enter %d Requests \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&pages[i]) ;
    }
    printf("Enter No. of Frames : ");
    scanf("%d",&n_frame) ;
    int frames[n_frame] ;
    for(i=0;i<n_frame;i++){
        frames[i] = -1 ;
    }
    int ind = 0 , hit = 0, miss = 0 ;
    for(i=0;i<n;i++){
        bool ans = search(frames,n_frame,pages[i]) ;
        if(ans==false){
            frames[ind] = pages[i] ;
            ind = (ind+1)%n_frame ;
            miss++;
        }
        else{
            hit++;
        }
        printf("Frame : ");
        for(j=0;j<n_frame;j++){
            printf("%d ",frames[j]) ;
        }
        printf("\n");
    }
    printf("No. of Hit  = %d \n",hit) ;
    printf("No. of Miss = %d \n",miss) ;
    printf("Hit Ratio   = %.3f \n",(float)hit*100/(float)n) ;
    printf("Miss Ratio  = %.3f \n",(float)miss*100/(float)n) ;
    return 0 ;
}