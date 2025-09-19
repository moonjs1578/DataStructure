#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct{
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void queue_init(QueueType *q){
    q->front = q->rear = 0;
}

int is_empty(QueueType *q){
    return q->front == q->rear;
}

int if_full(QueueType *q){
    return (q->rear + 1) % MAX_QUEUE_SIZE = q->front;
}

void enqueue(QueueType *q, element item){
    if(is_full(q)){
        error("큐가 포화상태입니다");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q))

    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

#define MAX_VERICES 50
typedef struct GraphType{
    int n;
    int adj_mat[MAX_VERICES][MAX_VERICES];
}GraphType;
int visited[MAX_VERICES];

void graph_init(GraphType *g){
    int r, c;
    g->n =0;
    for(r=0; )
}

void bfs_mat(GraphType *g, int v){
    int w;
    QueueType q;
    queue_init(&q);
    visited[v] = TRUE;
    enqueue(&q, v);
    whlie(!is_empty(&q)){
        v = dequeue(&q);
        for(w = 0; w < g->n; w++){
            if(g->adj_mat[v][w] && !visited[w]){
                visited[w] = TRUE;
                enqueue(&q, w);
            }
        }
    }
}