#include <stdio.h>
#include <malloc.h>

typedef struct _node{
    int key;
    struct _node *next;
} node;

node *head, *tail;

void init_stack(void) {
    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));
    head->next = tail;
    tail->next = tail;
}

int push(int k){
    node *t;
    if ((t = (node*)malloc(sizeof(node))) == NULL) {
        printf("\n   Out of memory....");
        return -1;
    }

    t->key = k;
    t->next = head->next;
    head->next = t;
    return k;
}

int pop(void){
    node *t;
    int i;
    if (head->next == tail) {
        printf("\n   Stack underflow");
        return -1;
    }
    t = head->next;
    i = t->key;
    head->next = t->next;
    free(t);
    return i;
}

void clear_stack(void){
    node *t, *s;
    t = head->next;
    while (t != tail) {
        s = t;
        t = t->next;
        free(s);
    }
    head->next = tail;
}

void print_stack(void){

    node *t;
    t = head->next;
    printf("\n Stack contents : TOP ------> Bottom \n");
    while (t != tail) {
        printf("%-6d", t->key);
        t = t->next;
    }
}

int main(void){

    int i;
    init_stack();

    printf("\nPush 5,4,7,8,2,1");
    push(5);
    push(4);
    push(7);
    push(8);
    push(2);
    push(1);
    print_stack();

    printf("\nPop");
    i = pop();
    print_stack();
    printf("\n   popping value is %d", i);

    printf("\nPush 3, 2, 5, 7, 2");
    push(3);
    push(2);
    push(5);
    push(7);
    push(2);
    print_stack();

    printf("\nNow stack is full, push 3");
    push(3);
    print_stack();

    printf("\nInitialize stack");
    init_stack();
    print_stack();

    printf("\nNow stack is empty, pop");
    i = pop();
    print_stack();
    printf("\n    popping value is %d", i);

    return 0;
}
