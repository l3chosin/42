#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <limits.h>

#define MAX_NUMBERS 10000
#define MAX_ARG_LEN 100000

int file_exists_and_executable(const char *filename) {
    struct stat st;
    return (stat(filename, &st) == 0) && (st.st_mode & S_IXUSR);
}

void generate_numbers(int *arr, int count, int min, int max) {
    for (int i = 0; i < count; i++) {
        long long range = (long long)max - (long long)min + 1;
        int num = min + (int)((((long long)rand() << 15) | rand()) % range);
        arr[i] = num;
    }
}

int main() {
    if (!file_exists_and_executable("./push_swap")) {
        printf("Error: push_swap no existe o no es ejecutable.\n");
        return 1;
    }
    if (!file_exists_and_executable("./checker_linux")) {
        printf("Error: checker_linux no existe o no es ejecutable.\n");
        return 1;
    }

    srand(time(NULL));

    while (1) {
        int count;
        char input[32];
        printf("\n¿Cuántos números aleatorios quieres generar? (Ctrl+C para salir): ");
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Error leyendo entrada.\n");
            continue;
        }
        // Elimina todos los \r y \n al final de la cadena
        size_t len = strlen(input);
        while (len > 0 && (input[len-1] == '\n' || input[len-1] == '\r')) {
            input[len-1] = 0;
            len--;
        }
        if (strlen(input) == 0) {
            printf("Cantidad inválida.\n");
            continue;
        }
        if (sscanf(input, "%d", &count) != 1 || count <= 0 || count > MAX_NUMBERS) {
            printf("Cantidad inválida.\n");
            continue;
        }

        int *numbers = malloc(count * sizeof(int));
        if (!numbers) {
            printf("Error de memoria.\n");
            continue;
        }

        generate_numbers(numbers, count, INT_MIN, INT_MAX);

        // Construir el argumento y la línea de números para el archivo
        char arg[MAX_ARG_LEN] = "";
        char numbers_line[MAX_ARG_LEN] = "Números utilizados: ";
        for (int i = 0; i < count; i++) {
            char buf[32];
            snprintf(buf, sizeof(buf), "%d ", numbers[i]);
            strncat(arg, buf, MAX_ARG_LEN - strlen(arg) - 1);
            strncat(numbers_line, buf, MAX_ARG_LEN - strlen(numbers_line) - 1);
        }
        free(numbers);

        // Ejecutar push_swap y guardar movimientos en archivo "out"
        char push_swap_cmd[MAX_ARG_LEN * 2];
        snprintf(push_swap_cmd, sizeof(push_swap_cmd), "./push_swap %s", arg);

        FILE *ps_fp = popen(push_swap_cmd, "r");
        if (!ps_fp) {
            printf("Error ejecutando push_swap.\n");
            continue;
        }
        FILE *out_fp = fopen("out", "w");
        if (!out_fp) {
            printf("Error creando archivo out.\n");
            pclose(ps_fp);
            continue;
        }
        // Escribir la lista de números al principio del archivo
        fprintf(out_fp, "%s\n", numbers_line);

        int move_count = 0;
        char line[128];
        while (fgets(line, sizeof(line), ps_fp)) {
            fputs(line, out_fp); // Escribe cada movimiento en el archivo "out"
            move_count++;
        }
        fclose(out_fp);
        pclose(ps_fp);

        // Ejecutar checker_linux leyendo solo los movimientos (saltando la primera línea)
        char checker_cmd[MAX_ARG_LEN * 2];
        snprintf(checker_cmd, sizeof(checker_cmd), "tail -n +2 out | ./checker_linux %s", arg);

        FILE *ch_fp = popen(checker_cmd, "r");
        if (!ch_fp) {
            printf("Error ejecutando checker_linux.\n");
            continue;
        }
        char result[16];
        if (fgets(result, sizeof(result), ch_fp)) {
            printf("Resultado: %s", result);
            printf("Movimientos: %d\n", move_count);
            printf("Movimientos guardados en archivo 'out'.\n");
        }
        pclose(ch_fp);
    }

    return 0;
}
