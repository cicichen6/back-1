#include <stdio.h>
#include <stdlib.h>

#define NUM 5

//创建队列结构
typedef struct{
    int *data;
    int front;
    int rear;
}SqQueue;

 void initQ(SqQueue *Q);
 int enQueue(SqQueue *Q,int e);
 int deQueue(SqQueue *Q,int *e);

//初始化队列
void initQ(SqQueue *Q){
    Q->data = (int*)malloc(NUM * sizeof(int));
    //Q->data[] = {0};
    Q->front = Q->rear = 0;
}

//入队
int enQueue(SqQueue *Q,int e){
    if((Q->rear+1)%NUM == Q->front){
        printf("FULL!");
        return -1;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear +1)%NUM;
    return 1;
}

//出队
int deQueue(SqQueue *Q,int *e){
    if(Q->front == Q->rear){
        printf("EMPTY!");
        return -1;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1)%NUM;
}

int main(){
    int ii = 3;
    int kk = 4;
    int *p = &ii;
    SqQueue *Qnew;
    initQ(Qnew);
    enQueue(Qnew,ii);
    enQueue(Qnew,kk);
    deQueue(Qnew,&ii);
    for(int jj = 0;jj < NUM;jj++){
        printf("%d",Qnew->data[jj]);
    }
    return 0;
}









