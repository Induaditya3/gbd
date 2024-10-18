// Compile with:
// gcc -g3 threads.c -o prog -lpthread
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // for usleep

#define NTHREADS 10000

// Global variable
int counter = 0;
// Custom data type for a lock
// This lock, has exactly '1' key to it.
pthread_mutex_t fridgeLock = PTHREAD_MUTEX_INITIALIZER;

// Thread with variable arguments
void *thread(void *vargp){
    usleep(500);
    // I'm protecting the shared resource
    // (i.e. 'counter') with a lock that only
    // one thread at a time can access.
    pthread_mutex_lock(&fridgeLock);
        counter = counter + 1;    
    pthread_mutex_unlock(&fridgeLock);

    return NULL;
}

int main(){
        // Store our Pthread ID
        pthread_t tid[NTHREADS];
        // Create and execute the thread
		for(int i=0; i < NTHREADS; i++){
        	pthread_create(&tid[i], NULL, thread, NULL);
		}
		for(int i=0; i < NTHREADS; i++){
        // Wait in 'main' thread until thread executes
        	pthread_join(tid[i],NULL);
		}
        // Execute our main
        printf("Counter = %d\n",counter);
        // end program
        return 0;
}
