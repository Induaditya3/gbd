// lesson.c
#include <stdio.h>      // Input/Ouput
#include <stdbool.h>    // For 'bool'
#include <stdint.h>     // For fixed-width types

// Type definitions for function pointers
typedef void(*void_void)(void);

// Global Structures
struct _callback{
    void_void Input;
}CallBack;

// Some 'dummy' functions
void glClear(){
    // ...
}

void glSetClearColor(int32_t mask){
    // ...
}

void Flip(){
    // ...
}

void SwapBuffers(bool doSwap){
    // ...
    // Call internal function
    Flip();
}

void InputHandler(){
    printf("Processing input...\n");
}

void SetInputCallBack(void_void func){
   CallBack.Input = func; 
}

// Entry point to program
int main(){

    // Setup any callback functions
    // from the global callback struct
    SetInputCallBack(InputHandler);

    // Main Application loop
    bool isRunning=true;
    long long cycles =0;
    while(isRunning){
        // Process user input
        CallBack.Input();

        // Setup stateful machine
        glClear();
        glSetClearColor(0xAABBCCFF);

        // For double-buffered displays
        // swap front and back buffer
        SwapBuffers(true);
        // Increment internal cycle counter
        ++cycles;
        // For DEMO purposes only
        // another function call to Flip()
        Flip(); 
        // Print out cycle number
        printf("cycle number:%lld \n",cycles);
    }

    return 0;
}
