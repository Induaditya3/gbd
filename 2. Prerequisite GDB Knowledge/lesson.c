// lesson.c
#include <stdio.h>
#include <stdbool.h>

bool IsEven(int input){
    return input%2==0;
}

int main(){
    
    unsigned int counter= 42;
    for(int i=0; i < 1000; i++){
        if(IsEven(i)){
            counter++;
            printf("counter = %d\n",counter);
        }
    }

    return 0;
}
