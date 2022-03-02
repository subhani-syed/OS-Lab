#include<stdio.h>
int main(){
    int nob,nop;
    printf("Enter the number of Blocks: ");
    scanf("%d",&nob);
    int block_size[nob];
    for(int i=0;i<nob;i++){
        printf("Enter Size of Block-%d: ",i+1);
        scanf("%d",&block_size[i]);
    }
    printf("Enter the number of Processes: ");
    scanf("%d",&nop);
    int process_size[nop];
    for(int i=0;i<nop;i++){
        printf("Enter Size of Process-%d: ",i+1);
        scanf("%d",&process_size[i]);
    }
    int available[nob];
    for(int i=0;i<nob;i++){
        available[i] = 1;
    }
    int frag[nob];
    int block_alloc[nop];
    printf("Process\t\tBlock Allocated\tProcessSize\tFrag\n");
    
    for(int i=0;i<nop;i++){
        int flag = 0;
        int block_allocated = -1;
        int fragment = 9999999;
        for(int j=0;j<nob;j++){
            if(available[j]){
                if(block_size[j] - process_size[i]<fragment){
                    block_allocated = j;
                    fragment = block_size[j] - process_size[i];
                    flag =1;
                }
            }
        }
        frag[i] = block_size[block_allocated] - process_size[i];
        available[block_allocated] = 0;
        block_alloc[i] = block_allocated;
        printf("%d\t\t",i+1);
        if(flag==0){
            printf("Not Allocated\t\t");
            printf("%d\n",process_size[i]);
        }else{
            printf("%d\t\t",block_alloc[i]);
            printf("%d\t\t",process_size[i]);
            printf("%d\n",frag[i]);
        }
    }
    return 0;
}