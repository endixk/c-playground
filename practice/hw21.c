#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(struct Node *new, int data){
    new = (struct Node *) malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void P21_1(int iargc, int *iargv){
    struct Node *head = NULL, *curr = NULL;
    head = createNode(head, iargv[0]);
    curr = head;
    for(int i = 1; i < iargc; i++){
        struct Node *next = NULL;
        next = createNode(next, iargv[i]);
        curr->next = next;
        curr = next;
    }

    // define tail
    struct Node *tail = NULL;
    for(tail = head; tail->next != NULL; tail = tail->next);

    // move head
    tail->next = head;
    curr = head->next;
    head->next = NULL;

    // move remains
    while(curr != tail){
        struct Node *temp = curr->next;
        tail->next = curr;
        curr->next = head;
        head = curr;
        curr = temp;
    }

    head = tail;
    curr = head;
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

struct Stack {
    int top;
    unsigned int capacity;
    char *array;
};

struct Stack *createStack(unsigned int capacity){
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *) malloc(stack->capacity * sizeof(char));
    return stack;
}

void push(struct Stack *stack, char item){
    if(stack->top == stack->capacity - 1){
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

char pop(struct Stack *stack){
    if(stack->top == -1){
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->array[stack->top--];
}

char peek(struct Stack *stack){
    if(stack->top == -1){
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->array[stack->top];
}

void P21_2(char *str){
    struct Stack *stack = createStack(100);
for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            push(stack, str[i]);
        }
        else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
            char top = peek(stack);
            if(top == '(' && str[i] == ')' || top == '[' && str[i] == ']' || top == '{' && str[i] == '}'){
                pop(stack);
            }
            else{
                printf("Invalid\n");
                return;
            }
        }
    }
}