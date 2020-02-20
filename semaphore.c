#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>


/*This is the global variable which can be accessed by both the thread (child created by parent) and a process(parent).*/
int a =10;

sem_t semaphore_id;

void th_fn()
{

 sem_wait(&semaphore_id);
 a++;
 sem_post(&semaphore_id);
 printf("\n  in thread %d", a);

}

int main()
{

pthread_t id;

/* int sem_init(sem_t *sem, int pshared, unsigned int value);
   The pshared argument indicates whether this semaphore is to be shared between the threads of a process, or between processes.
   
   If pshared has the value 0, then the semaphore is shared between the threads of a process.

   If pshared is nonzero, then the semaphore is shared between processes.

   The value argument specifies the initial value for the semaphore.

   semaphore_id can be accessed by both the parent and the child because, the thread points to the same memory mappings as parent.
*/
sem_init(&semaphore_id, 0, 1);

pthread_create(&id, NULL, (void *)&th_fn,NULL );

 sem_wait(&semaphore_id);
a++;
 sem_post(&semaphore_id);
printf("\n hi in process %d", a);

/* if i dint put sleep parent process will exit first. Here we are using pthread_join function instead of sleep */
//sleep(2);

//wait(0); //use it for fork() to execute the child first.
pthread_join(id, NULL); // it will execute the child first.

return 0;

}

/* NOTE: Dont think there is no use of the semaphore, since the child is executed first and then the parent is executed because of pthread_join API

   Semaphore is used in the below scenario here:
   when a++ is being executed in the parent context, the scehuler can switch the context to the child context. suppose the a++ instruction is executed in
   3 steps. then the scheduler can switch the context any time. i.e. after execution of step 1 or step 2 or step 3. If the the scheduler will switch the 
   context after step 1) or step 2), then the vale of the a will be inconsistent.

   Therefore to execute the step 1) 2) 3) at a time without a context switch in between, we gaurd it with sem_wait and sem_post api.
   This kind of execution is called atomic execution.

*/
