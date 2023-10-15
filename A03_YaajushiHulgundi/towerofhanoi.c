#include <stdio.h>

void tower(int disc, int source, int dest, int temp) { //number of discs, original peg it was on, peg it needs to get to and a temp
    if (disc == 1) { //if there's only one disc it only has to move it once. 
        printf("move disc from %d to %d\n", source, dest);
        return;
    }
    tower(disc - 1, source, temp, dest); //move the second last disc from the source to the temp peg as a way of keeping it away temporarily. 
    printf("move disc from %d to %d\n", source, dest);
    tower(disc - 1, temp, dest, source); 
}

int main() {
    int source = 1, dest = 3, temp = 2; //source is initial so 1. dest is final peg so 3. temp is a middleman that helps organise discs so 2. 
    int sourcedisc = 3;

    tower(sourcedisc, source, dest, temp);

    return 0;
}
