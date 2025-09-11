#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct{
    int key;
}element;
typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

HeapType *create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType *h){
    h->heap_size = 0;
}

void insert_max_heap(HeapType *h, element item){
    int i;
    i = ++(h->heap_size);

    while((i!=1) && (item.key > h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2];
        i/=2;
    }
    // (i!=1조건은 루트노드로 갔을 때 반복문을 종료하기 위함)
    h->heap[i]= item;
}

element delete_max_heap(HeapType *h){
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while(child <= h->heap_size){
        if((child < h->heap_size) && (h->heap[child].key) < h->heap[child+1].key)
            child++;
        if(temp.key >= h->heap[child].key)
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}
/*
비유 (쉽게 이해)
루트에 구멍이 생김 (루트 값을 꺼냈으니 빈 자리)
마지막 노드를 손에 들고 있음 (temp)
구멍을 아래로 내려보내면서 (자식 중 큰 값 끌어올림)
temp가 들어갈 자리를 찾으면 그 자리에 꽂음
*/
int main(){
    element e1 = {10}, e2 = {5}, e3={30};
    element e4, e5, e6;
    HeapType *heap;

    heap = create();
    init(heap);

    insert_max_heap(heap, e1);
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);

    e4 = delete_max_heap(heap);
    printf("< %d >", e4.key);
    e5 = delete_max_heap(heap);
    printf("< %d >", e5.key);
    e6 = delete_max_heap(heap);
    printf("< %d > \n", e6.key);

    free(heap);

    return 0;
}