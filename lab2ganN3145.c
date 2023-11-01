#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    // Проверка запуска с переменной среды, включающей отладочный вывод.
    // Пример запуска с установкой переменной LAB2DEBUG в 1:
    // $ LAB2DEBUG=1 ./lab2abcNXXXXX 5 5
    char *DEBUG = getenv("LAB2DEBUG");
    if (DEBUG) {
        fprintf(stderr, "Включен вывод отладочных сообщений\n");
    }

    if ((argc != 4 || strcmp(argv[1], "-m")) && (argc != 3)) {
        fprintf(stderr, "Usage: %s [-m] число_строк число_столбцов\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    //
    // Тут может быть ваш код. В этом файле Вы можете поменять все, что угодно.
    // Главное - чтобы потом все правильно работало ;-)
    //

    int m = atoi(argv[2]), n = atoi(argv[3]);
    //printf("Your matrix dimensions: %d and %d\n", m, n);
    printf("Введите строки матрицы:\n");
    fflush(stdout);

    short matrix[m][n];
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%hd", &matrix[i][j]);


    printf("Исходная матрица:\n");
    for(int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%hd ", matrix[i][j]);
        printf("\n");
    }
    fflush(stdout);

    printf("Введите матрицу P 2*2:\n");
    fflush(stdout);
    short p1, p2, p3, p4;
    scanf("%hd %hd %hd %hd", &p1, &p2, &p3, &p4);

    printf("Матрица P:\n%hd %hd\n%hd %hd\n", p1, p2, p3, p4);
    fflush(stdout);

    int x = -1, y = -1;
    for(int i = 0; i < m - 1; ++i){
        for(int j = 0; j < m - 1; ++j){
            if(matrix[i][j] == p1 && matrix[i][j + 1] == p2 && matrix[i + 1][j] == p3 && matrix[i + 1][j + 1] == p4){
                x = j, y = i;
                matrix[i][j] = pow(matrix[i][j], 2);
                matrix[i][j+1] = pow(matrix[i][j+1], 2);
                matrix[i+1][j] = pow(matrix[i+1][j], 2);
                matrix[i+1][j+1] = pow(matrix[i+1][j+1], 2);

                goto success;
            }
        }
    }

    printf("Соответствий не найдено ¯\\_(ツ)_/¯");
    return EXIT_FAILURE;

    success:
    printf("Соотвествие найдено!\nX = %x, Y = %d\n", x, y);
    printf("Обновленная матрица:\n");
    for(int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%hd ", matrix[i][j]);
        printf("\n");
    }
    
    return EXIT_SUCCESS;
}
