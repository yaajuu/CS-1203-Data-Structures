#include <stdio.h>
#include <stdlib.h>

typedef struct node { //defines a structure that is called node
    int data; //data holds whatever number you give it 
    struct node *next; //next is the pointer to the next node
} NODE, *NODEPTR;
NODEPTR front, rear; //instead of writing struct node everytime we can use NODE. *NODEPTR can declare pointers to different nodes

typedef struct queue { //defines a structure called queue
    NODEPTR front, rear; //contains front and rear: these are also pointers
} QUEUE;
QUEUE q = {NULL, NULL}; //in the original queue q, since we have no elements and its empty, both front and rear are NULL because it's empty

NODEPTR createNode(int val) {  //function creates a node thats called val
    NODEPTR p; //p is a pointer that will point to a new node
    p = (NODEPTR) malloc(sizeof(struct node)); //gives a space of memory for the new node and finds the size of the memory
    p->data = val; //the data part of the new p to the value that is passed to 'val'
    p->next = NULL; //since the node doesn't point to anything the 'next' pointer is given NULL
    return p;
}

int delete(QUEUE *q) { //removes the data from the front of the queue and moves the rest of the queue up by 1
    NODEPTR temp; //temp is a temporary pointer that holds the value of the node 
    int elm; //variable that holds the value of the element that is going to be deleted
    if (q->front == NULL) return -1; //if queue is empty it returns an error number
    else {
        temp = q->front; //moves temp so it is the pointer for the front of th node
        q->front = q->front->next; //the front pointer points to the node after the front pointer 
        elm = temp->data; //it stores the value of the data of the node that has been deleted
        free(temp);
        if (q->front == NULL)
            q->rear = NULL;
        return elm;
    }
}

void insert(QUEUE *q, int elm) { //inserts an element 
    NODEPTR temp = createNode(elm); // creates a pointer called temp and a new node called elm 
    if (q->front == NULL) {
        q->front = temp; 
        q->rear = temp;//if queue is empty both front and rear pointers will point to temp meaning it is the only element
    }
    else {
        q->rear->next = temp; //puts temp to the rear of the queue
        q->rear = temp;
    }
}

void printQueue(QUEUE q) { //prints the queue from front to rear
    NODEPTR temp;
    if (q.front == NULL) {
        printf("Queue empty\n");
        return;
    }
    printf("<- F "); //shows that this is the front of the queue
    for (temp = q.front; temp != NULL; temp = temp->next) //starts with temp being at the front of the node and as long as there are still elements to print, temp gets updated
        printf("%d ", temp->data);
    printf("<- R\n"); //shows that it is the rear
}

int main() {
    int elm, menu;

    while (1) { //infinite while loop thats terminated when you choose exit
        printf("0. exit, 1. delete, 2. insert, 3. print. input choice? : ");
        scanf("%d", &menu);
        switch (menu) {
            case 0:
                exit(0); //exits the loop
            case 1:
                printf("deleted value %d\n", delete(&q)); //deletes element at front 
                break;
            case 2:
                printf("element you want to insert: "); 
                scanf("%d", &elm);
                insert(&q, elm); //inserts element
                break;
            case 3:
                printQueue(q); //prints out the queue
                break;
            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}
