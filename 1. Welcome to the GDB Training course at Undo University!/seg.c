#include <stdio.h>
#include <unistd.h>

int main(){

    printf("Hello everyone!\n");
    sleep(2);
    printf("I have an important message for you\n");
    sleep(2);
    printf("*Hint* it's about debugging\n");
    sleep(2);
    int* p=NULL;
    *p = 7;

    return 0;
}
