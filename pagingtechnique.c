#include<stdio.h>
#include<stdlib.h>
int main(){
    int log;
    printf("ENter the logical Addres space: ");
    scanf("%d",&log);
    printf("ENter page Size: ");
    int psize;
    scanf("%d",&psize);
    printf("Enter Physical Address Space: ");
    int pha;
    scanf("%d",&pha);
    int nop = log/psize;
    int fsize = psize;
    int nof = pha/fsize;
    printf("The number of  Pages : %d\n",nop);
    printf("The number of  Frames : %d\n",nof);
    int frame_no[nof];
    int alloc[nof];
    for(int i=0;i<nof;i++){
        alloc[i] = 0;
    }
    for(int i=0;i<nop;i++){
        int temp = rand()%nof;
        while(alloc[temp]==1){
            temp = rand()%nof;
        }
        alloc[temp] = 1;
        frame_no[i] = temp;
    }
    printf("Page No\t\tFrameNo\t\tBase Address\n");
    for(int i=0;i<nop;i++){
        printf("%d\t\t%d\t\t%d\n",i,frame_no[i],frame_no[i]*psize);
    }
    return 0;
}