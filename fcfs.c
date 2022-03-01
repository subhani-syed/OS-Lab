#include<stdio.h>
struct process{
    int number;
    int burst_time;
    int waiting_time;
    int turnaound_time;
};
int main(){
    printf("Enter the number of process: ");
    int n;
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
        printf("Enter The Burst Time of Process-%d: ",i+1);
        p[i].number = i;
        scanf("%d",&p[i].burst_time);
    }
    printf("Process No\t\tBurst Time\t\tWaiting Time\t\tTurn_AroundTime\n");
    p[0].waiting_time=0;
    for(int i=1;i<n;i++){
        p[i].waiting_time = p[i-1].burst_time+p[i-1].waiting_time;
    }
    for(int i=0;i<n;i++){
        p[i].turnaound_time = p[i].burst_time+p[i].waiting_time;
    }
    float avg_wt=0,avg_tat=0;
    for(int i=0;i<n;i++){
        avg_wt = avg_wt + p[i].waiting_time;
        avg_tat = avg_tat + p[i].turnaound_time;
    }
    for(int i=0;i<n;i++){
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1,p[i].burst_time,p[i].waiting_time,p[i].turnaound_time);
    }
    printf("\nAvg Waiting Time : %f",avg_wt/n);
    printf("\nAvg TurnAround Time : %f",avg_tat/n);
    return 0;
}