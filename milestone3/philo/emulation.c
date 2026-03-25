#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;

    /* Aqui me falta ya hacer las acciones de los filosofos :D */
    printf("El filosofo %i ha nacido!\n", philo->id);
    philo_sleep(philo);
    printf("El filosofo %i ha muerto!\n", philo->id);
    return (NULL);
}

void start_emulation(t_table sim)
{
    int i;

    i = 0;
    while (i < sim.n_philos)
    {
        pthread_create(&sim.philosopher[i].philo_thread, NULL, philo_routine, &sim.philosopher[i]);
        i++;
    }
    i = 0;
    while (i < sim.n_philos)
    {
        pthread_join(sim.philosopher[i].philo_thread, NULL);
        i++;
    }
}
