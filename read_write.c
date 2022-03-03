#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
sem_t wrt,mutex;
int rc= 0;
void *reader(void *r){
    sem_wait(&mutex);
    rc++;
    if(rc==1) sem_wait(&wrt);
    sem_post(&mutex);
    printf("Reader %d is reading\n",*(int*)r);
    sleep(2);
    sem_wait(&mutex);
    rc--;
    if(rc==0) sem_post(&wrt);
    sem_post(&mutex);
    printf("Reader %d has left\n",*(int*)r);
}
void *writer(void *w){
    sem_wait(&mutex);
    printf("Writer %d has entered\n",*(int *)w);
    sleep(2);
    sem_post(&mutex);
    printf("Writer %d has left\n",*(int *)w);
}
int main(){
    pthread_t re[5],wr[5];
    sem_init(&wrt,0,1);
    sem_init(&mutex,0,1);
    int a[5] = {1,2,3,4,5};
    for(int i=0;i<5;i++){
        pthread_create(&re[i],NULL,reader,(void *)&a[i]);
        pthread_create(&wr[i],NULL,writer,(void *)&a[i]);
    }
    for(int i=0;i<5;i++){
        pthread_join(re[i],NULL);
    }for(int i=0;i<5;i++){
        pthread_join(wr[i],NULL);
    }
    return 0;
}