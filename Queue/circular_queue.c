#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int element;
typedef struct{
    element data[MAX];
    int front, rear;
}QueueType;

void error(char *message){
    printf("%s\n", message);
    exit(1);
}

void init_queue(QueueType *q){
    q->front = 0;
    q->rear = 0;
}

int is_empty(QueueType *q){
    return q->front == q->rear;
}

int is_full(QueueType *q){
    return (q->rear + 1) % MAX == q->front;
}

void queue_print(QueueType *q){
    if(!is_empty(q)){
        int i = q->front;
        
        do{
            i = (i+1) % MAX;
            printf("%d | ", q->data[i]);
            if(i == q->rear)
                break;
        }while(i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType *q, element item){
    if(is_full(q)){
        printf("큐 포화 에러\n");
    }
    else{
        q->rear = (q->rear + 1) % MAX;
        q->data[(q->rear)] = item;
    }
}

int dequeue(QueueType *q){
    if(is_empty(q)){
        printf("큐 공백 에러\n");
    }
    else{
        q->front = (q->front+1) % MAX;
        return q->data[q->front];
    }
}

int main(){
    QueueType queue;
    int element;

    init_queue(&queue);
    printf("--데이터 추가 단계--\n");
    while(!is_full(&queue)){
        printf("값 : ");
        scanf("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
    }
    printf("큐는 포화상태입니다\n");

    printf("--데이터 삭제 단계--\n");
    while(!is_empty(&queue)){
        element = dequeue(&queue);
        printf("꺼내진 정수 : %d \n", element);
        queue_print(&queue);
    }

    printf("큐는 공백상태입니다.\n");

    return 0;
}