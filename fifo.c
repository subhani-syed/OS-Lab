#include<stdio.h>
int main(){
    int nop;
    printf("Enter the Number Of Pages: ");
    scanf("%d",&nop);
    int pages[nop];
    printf("Enter the Page Numbers: ");
    for(int i=0;i<nop;i++){
        scanf("%d",&pages[i]);
    }
    int nof;
    int faults=0;
    int pointer= 0;
    printf("Enter the Number of Frames: ");
    scanf("%d",&nof);
    int frames[nof];
    for(int i=0;i<nof;i++){
        frames[i] = -1;
    }
    printf("Ref String \tFrames\n");
    for(int i=0;i<nop;i++){
        printf("%d\t\t",pages[i]);
        int found = 0;
        for(int j=0;j<nof;j++){
            if(frames[j]==pages[i]){
                found =1;
            }
        }
        if(found==0){
            faults++;
            frames[pointer] = pages[i];
            pointer=(pointer+1)%nof;
            for(int i=0;i<nof;i++){
                printf("%d\t",frames[i]);
            }
        }
        printf("\n");
    }
    printf("Total Faults is : %d",faults);
    return 0;
}