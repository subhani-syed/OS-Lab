  #include<stdio.h>
 int main(){
     int n;
     printf("Enter the number of process: ");
     scanf("%d",&n);
     int memory;
     printf("Enter the size of memory: ");
     scanf("%d",&memory);
     for(int i=0;i<n;i++){
         printf("Enter the size of process %d : ",i+1);
         int process_size;
         scanf("%d",&process_size);
         if(process_size<=memory){
             printf("Memory Allocated is %d\n",memory);
             memory = memory - process_size;
             printf("Remaining Memory is %d \n",memory);
             printf("External Fragmentation is %d \n",memory);
         }else{
             printf("Memory Not Allocated for process %d\n",i+1);
             printf("External Fragmentation is %d \n",memory);
         }
     }
     return 0;
 }