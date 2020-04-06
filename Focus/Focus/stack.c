#include <stdio.h>
#include <stdlib.h>

/*
 * Data structure to represent the various elements
 * of the stack
 */
struct stack_elem{
    int data;
    struct stack_elem *next;
} stack;


/*
 * This method adds an element on top of the stack
 * 
 * Input
 * value: the integer value contained in the element to be pushed to the stack
 * top: a pointer to the top of the stack
 * 
 * Output
 * Returns the new top of the stack pointing to the newly added element
 */
struct stack_elem * push(int value, struct stack_elem *top){
    struct stack_elem *curr = top;
    top = malloc(sizeof(stack));
    top->data = value;
    top->next = curr;
    return top;
}

/*
 * This method prints the value of the topmost element of the stack
 * and removes the element from the stack
 * 
 * Input
 * top: a pointer to the top of the stack
 * 
 * Output
 * Returns the new top of the stack after the topmost element is removed
 */
struct stack_elem * pop(struct stack_elem *top){
    struct stack_elem *curr = top;
    if(curr!=NULL){
        top = curr->next;
        printf("Stack Data: %d\n", curr->data);
        free(curr);
    }
    return top;
}


int main(int argc, char** argv) {
    
    //pointer to the top of the stack
    struct stack_elem *top = NULL;
    //pointer to the current element of the stack
    struct stack_elem *curr = NULL;
    
    printf("Pushing 3 elements to the stack\n");
    
    /*
     * Push 3 elements in the stack
     */
    top = push(1, top);
    printf("Stack Data: %d\n", top->data);
    
    top = push(2, top);
    printf("Stack Data: %d\n", top->data);
    
    top = push(3, top);
    printf("Stack Data: %d\n", top->data);
    
    /*
     * Pops 3 elements from the stack
     */
    top = pop(top);
    top = pop(top);
    top = pop(top);
    
    return 0;
}


HEAD[2][5]=push1(HEAD[2][5],2,GREEN);
HEAD[2][5]=  push1(HEAD[2][5], 3,RED);
HEAD[2][5]=  push1(HEAD[2][5], 5,RED);
printf("\n try 1: %d", HEAD[2][5]->num_pieces);
board[2][5].num_pieces=HEAD[2][5]->num_pieces;
board[2][5].color22=HEAD[2][5]->color22;
printf("\n Updated array: %d,,%d\n", board[2][5].num_pieces,board[2][5].color22);
struct square *temp=HEAD[2][5];
HEAD[2][5]=pop(HEAD[2][5]);
HEAD[2][5]=pop(HEAD[2][5]);
HEAD[2][5]=pop(HEAD[2][5]);
while(temp!=NULL){
printf("%d-> ",temp->num_pieces);
temp=temp->next;
}
temp=HEAD[2][5];
printf("\n");
while(temp!=NULL){
printf("%d-> ",temp->color22);
temp=temp->next;
}
