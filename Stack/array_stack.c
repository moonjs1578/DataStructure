#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int element;
typedef struct{
    element data[MAX];
    int top;
}StackType;

void init_stack(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == MAX-1);
}

void push(StackType *s, element item){
    if(is_full(s)){
        printf("스택 포화 에러\n");
        return;
    }
    else{
        s->data[++(s->top)] = item;
    }
}

element pop(StackType *s){
    if(is_empty(s)){
        printf("스택 공백 에러\n");
    }
    else{
        return s->data[(s->top)--];
    }
}

element peek(StackType *s){
    if(is_empty(s)){
        printf("스택 공백 애러\n");
    }
    else{
        return s->data[s->top];
    }
}

int main(){
    StackType s;

    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    return 0;
}