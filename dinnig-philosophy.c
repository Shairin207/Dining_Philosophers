#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THINKING 0
#define HUNGRY 1
#define EATING 2

pthread_mutex_t *forks;
pthread_mutex_t mutex;
int *state;
int num_philosophers;
int num_iterations;

void test(int philosopher) {
    if (state[philosopher] == HUNGRY && 
        state[(philosopher + num_philosophers - 1) % num_philosophers] != EATING &&
        state[(philosopher + 1) % num_philosophers] != EATING) {
        
        state[philosopher] = EATING;
        pthread_mutex_unlock(&forks[philosopher]);
    }
}

void pickup_forks(int philosopher) {
    pthread_mutex_lock(&mutex);
    state[philosopher] = HUNGRY;
    test(philosopher);
    pthread_mutex_unlock(&mutex);
    pthread_mutex_lock(&forks[philosopher]);
}

void return_forks(int philosopher) {
    pthread_mutex_lock(&mutex);
    state[philosopher] = THINKING;
    test((philosopher + num_philosophers - 1) % num_philosophers);
    test((philosopher + 1) % num_philosophers);
    pthread_mutex_unlock(&mutex);
}

void *philosopher(void *num) {
    int philosopher = *(int *)num;
    for (int i = 0; i < num_iterations; i++) {
        printf("Philosopher %d is thinking.\n", philosopher);
        sleep(1);
        pickup_forks(philosopher);
        printf("Philosopher %d is eating.\n", philosopher);
        sleep(1); 
        return_forks(philosopher);
        printf("Philosopher %d is being polite and releasing forks.\n", philosopher);
        sleep(1); 
    }
    return NULL;
}

int main() {
    int i;
    do {
    
    printf(" *********************************************************************************\t\t\n");
        printf("Enter the number of philosophers (odd number only):\t ");
        scanf("%d", &num_philosophers);
        if (num_philosophers % 2 == 0) {
          printf(" \n*********************************************************************************\t\t\n");
            printf("WRONG INPUT!!!Please enter an odd number.\n");
        }
    } while (num_philosophers % 2 == 0);

    printf("Enter the number of iterations:\t");
    scanf("%d", &num_iterations);

    pthread_t philosophers[num_philosophers];
    int philosopher_ids[num_philosophers];
    forks = malloc(num_philosophers * sizeof(pthread_mutex_t));
    state = malloc(num_philosophers * sizeof(int));

    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < num_philosophers; i++) {
        pthread_mutex_init(&forks[i], NULL);
        state[i] = THINKING;
    }

    for (i = 0; i < num_philosophers; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }

    for (i = 0; i < num_philosophers; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (i = 0; i < num_philosophers; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    pthread_mutex_destroy(&mutex);
    free(forks);
    free(state);

    return 0;
}
