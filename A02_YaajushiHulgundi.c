#include <stdio.h>
#include <stdlib.h>

typedef struct node { //define dtructure called node
    int info; //variable 
    struct node* LEFT;
    struct node* RIGHT; //both LEFT AND RIGHT are pointers to nodes
} NODE;

typedef struct stack { //defining a structure called a stack
    int sptr; //variable that is a stackpointer  
    NODE** s_array; //points to an array of node pointers
} STACK;

int empty(STACK* s) {
    return s->sptr == -1; //returns invalid number if stack is empty
}

NODE* POP(STACK* s) {
    return s->s_array[(s->sptr)--]; //pops the last element from the stack and decrements from the last element that was popped
}

void init(STACK* s) {
    s->sptr = -1;
    s->s_array = (NODE**)malloc(sizeof(NODE*)); //initialises the stack by setting the stack pointer to point to an empty stack. malloc assigns memory to the stack
}

int PUSH(STACK* s, NODE* element) {
    s->s_array[++(s->sptr)] = element;
    return 1; //adds a new element to the stack and gets the right position of the node in the stack array
}

void inorder(NODE* root) {
    if (root == NULL) return; 

    STACK st; //a stack to keep track of the nodes
    init(&st); 

    NODE* current = root; //starts with the root node and goes down the left subtree. 
    while (current != NULL || !empty(&st)) {
        while (current != NULL) {
            PUSH(&st, current); //pushes the current node onto the stack and moves on 
            current = current->LEFT; //moves to the left child of the node. 
        }

        current = POP(&st);
        printf("%d ", current->info);
        current = current->RIGHT;// if the traversal leads to a end or leaf node, it pops and prints the node and goes to the right side. 
    }
 
    free(st.s_array); //frees up space that was stored memory. 
}

int main() {
    NODE* root = malloc(sizeof(struct node));
    root->info = 6;
    root->LEFT = malloc(sizeof(struct node));
    root->RIGHT = malloc(sizeof(struct node));
    root->RIGHT->info = 3;
    root->LEFT->info = 2;
    root->LEFT->LEFT-> = malloc(sizeof(struct node));
    root->LEFT->LEFT = 4;
    root->LEFT->RIGHT = NULL;
    root->RIGHT->LEFT = NULL;
    root->RIGHT->RIGHT = NULL;

    inorder(root); //starts the process at the root and moves left first.

    free(root->LEFT);
    free(root->RIGHT);
    free(root);

    return 0;
}
