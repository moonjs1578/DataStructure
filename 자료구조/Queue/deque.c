#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
typedef struct{
    element data[MAX];
    int front, rear;
}DequeueType;

void error(char *message){
    printf("%s", message);
    exit(1);
}
void init_dequeue(DequeueType *q){
    q->front = q->rear = 0;
}
int is_empty(DequeueType *q){
    return q->front == q->rear;
}
int is_full(DequeueType *q){
    return q->front == (q->rear + 1) % MAX;
}
void deque_print(DequeueType *q){
    int i = q->front;
    if(is_empty(q)){
        printf("EMPTY\n");
        return;
    }
    do{
        i = (i+1) % MAX;
        printf("%d | ", q->data[i]);
        if(i == q->rear) break;
    }while(i != q->front);
    printf("\n");
}
void add_rear(DequeueType *q, element item){
    if(is_full(q)) error("FULL\n");
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = item;
}
element delete_front(DequeueType *q){
    if(is_empty(q)) error("EMPTY\n");
    q->front = (q->front + 1) % MAX;
    return q->data[q->front];
}
element get_front(DequeueType *q){
    if(is_empty(q)) error("EMPTY\n");
    return q->data[(q->front+1) % MAX];
}
void add_front(DequeueType *q, element item){
    if(is_full(q)) error("FULL\n");
    q->data[q->front] = item;
    q->front = (q->front - 1 + MAX) % MAX;
}
element delete_rear(DequeueType *q){
    if(is_empty(q)) error("EMPTY\n");
    int prev = q->rear;
    q->rear = (q->rear - 1 + MAX) % MAX;
    return q->data[prev];
}
element get_rear(DequeueType *q){
    if(is_empty(q)) error("EMPTY\n");
    return q->data[q->rear];
}

int main(){
    DequeueType queue;
    init_dequeue(&queue);

    for(int i=0; i<3; i++){
        add_front(&queue, i);
        deque_print(&queue);
    }

    for(int i=0; i<3; i++){
        delete_rear(&queue);
        deque_print(&queue);
    }
    return 0;
}
