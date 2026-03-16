#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_thread_data
{
    int segundos;
    int id;
    pthread_mutex_t *mutex;
} t_thread_data;


void *funcion_prueba(void *arg)
{
    t_thread_data *data = (t_thread_data *)arg;
    int i = data->segundos;
    int id = data->id;

    printf("\033[%i;0H", id);
    printf("Thread %i: empezando, esperando %i segundos\n", id, i);
    fflush(stdout);
    int j = i;
    while (j > 0)
    {
        pthread_mutex_lock(data->mutex);
        printf("\033[%i;0H", id);          // Ir a la línea del thread
        printf("\033[2K");                  // Limpiar la línea
        printf("Thread %i: %i segundos restantes", id, j);
        fflush(stdout);
        pthread_mutex_unlock(data->mutex);
        usleep(1 * 1000000);
        j--;
    }
    pthread_mutex_lock(data->mutex);
    printf("\033[%i;0H", id);
    printf("\033[2K");
    printf("Thread %i: terminado!\n", id);
    fflush(stdout);
    pthread_mutex_unlock(data->mutex);
    return (NULL);
}

int main(void)
{
    pthread_t cum;
    pthread_t cum2;
    pthread_mutex_t mutex;

    pthread_mutex_init(&mutex, NULL);
    printf("\033[2J\033[H");
    fflush(stdout);

    t_thread_data data1 = {5, 1, &mutex};
    t_thread_data data2 = {10, 3, &mutex};

    pthread_create(&cum, NULL, funcion_prueba, &data1);
    pthread_create(&cum2, NULL, funcion_prueba, &data2);
    pthread_join(cum, NULL);
    pthread_join(cum2, NULL);

    pthread_mutex_destroy(&mutex);
}
