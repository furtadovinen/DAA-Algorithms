#include<stdio.h> 
#include<stdlib.h>
#include<pthread.h> 
#include<semaphore.h> 
#include<unistd.h>


#define Num_phil 6 
#define THINKING 3 
#define HUNGRY 2 
#define EATING 0 
#define LEFT (philosopher - 1) % Num_phil 
#define RIGHT (philosopher + 1) % Num_phil 

sem_t mutex; 
sem_t S[Num_phil] = {0, 0, 0, 0, 0}; 

void pickup(int); 
void putdown(int); 

int state[Num_phil]; 
int count = 6;
int phil[Num_phil] = { 1, 2, 3, 4, 5 };

void* philospher(void* num) 
{ 
	while (count > 0) { 
		int* i = num; 
		pickup(*i); 
		sleep(2); 
		putdown(*i); 
		count--;
	} 
} 

void test(int philosopher) 
{ 
	if (state[philosopher] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) { 
		state[philosopher] = EATING; 
		printf("Philosopher %d takes fork %d and %d\n", philosopher , LEFT , philosopher ); 	
		printf("Philosopher %d is Eating\n", philosopher );  
		sem_post(&S[philosopher]); 
	} 
} 

void pickup(int philosopher) 
{ 
	sem_wait(&mutex);
	state[philosopher] = HUNGRY; 
	printf("Philosopher %d is Hungry\n", philosopher );  
	test(philosopher); 
	sem_post(&mutex); 
	sem_wait(&S[philosopher]); 
} 

void putdown(int philosopher) 
{ 
	sem_wait(&mutex); 
	state[philosopher] = THINKING; 
	printf("Philosopher %d putting fork %d and %d down\n", philosopher , LEFT , philosopher ); 
	printf("Philosopher %d is thinking\n", philosopher ); 
	test(LEFT); 
	test(RIGHT); 
	sem_post(&mutex); 
} 



int main() 
{ 
	int i; 
	pthread_t thread_id[Num_phil]; 
	sem_init(&mutex, 0, 1); 
	for (i = 1; i < Num_phil; i++) {  
		pthread_create(&thread_id[i], NULL, philospher, &phil[i]); 
		printf("Philosopher %d is thinking\n", i ); 
	} 

	for (i = 1; i < Num_phil; i++) 
		pthread_join(thread_id[i], NULL); 
} 
