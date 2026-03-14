
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_thread_data
{
    int segundos;
    int id;
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
        printf("\033[%i;0H", id);          // Ir a la línea del thread
        printf("\033[2K");                  // Limpiar la línea
        printf("Thread %i: %i segundos restantes", id, j);
        fflush(stdout);
        usleep(1 * 1000000);
        j--;
    }

    printf("\033[%i;0H", id);
    printf("\033[2K");
    printf("Thread %i: terminado!\n", id);
    fflush(stdout);
    return (NULL);
}

int main(void)
{
    pthread_t cum;
    pthread_t cum2;

    printf("\033[2J\033[H");
    fflush(stdout);

    t_thread_data data1 = {5, 1};
    t_thread_data data2 = {10, 3};

    pthread_create(&cum, NULL, funcion_prueba, &data1);
    pthread_create(&cum2, NULL, funcion_prueba, &data2);
    pthread_join(cum, NULL);
    pthread_join(cum2, NULL);
}
