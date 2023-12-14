#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

bool isnum(char* n) {
    for(int i = 0; i < (int)strlen(n); ++i)
        if(!isdigit(n[i]) && n[i] != ' ')
            return false;
    return true;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    // Проверка запуска с переменной среды, включающей отладочный вывод.
    // Пример запуска с установкой переменной LAB2DEBUG в 1:
    // $ LAB2DEBUG=1 ./lab2abcNXXXXX 5 5

    char *DEBUG = getenv("LAB2DEBUG");
    if (DEBUG) {
        fprintf(stderr, "Включен вывод отладочных сообщений\n");
    }

    //
    // Тут может быть ваш код. В этом файле Вы можете поменять все, что угодно.
    // Главное - чтобы потом все правильно работало ;-)
    //

    //char *newInput;
    int m = 0, n = 0;
    char* standartOpType = "-m";

    bool set_matrix = false;

    if(argc < 2) {
        printf("Ошибка: отсутствуют обязательные аргументы");
        return EXIT_FAILURE;
    }
    char *opType = argv[1];
    if(isnum(opType) && argc == 3) {
        m = atoi(opType);
        opType= "";
        if(isnum(argv[2]))
            n = atoi(argv[2]);
        else {
            printf("Ошибка: '%s' не является числом\n", argv[2]);
            return EXIT_FAILURE;
        }
        printf("m = %d, n = %d\n", m, n);
    }
    else if(strcmp(opType, standartOpType) == 0) {
        set_matrix = true;
        if(isnum(argv[2]))
            m = atoi(argv[2]);
        else {
            printf("Ошибка: '%s' не является числом\n", argv[2]);
            return EXIT_FAILURE;
        }

        if(isnum(argv[3]))
            n = atoi(argv[3]);
        else {
            printf("Ошибка: '%s' не является числом\n", argv[3]);
            return EXIT_FAILURE;
        }
    }
    else if(strcmp(opType, standartOpType) != 0) {
        printf("Ошибка: опция '%s' не поддерживается.", opType);
        return EXIT_FAILURE;
    }

    if(!(m > 0 && n > 0)){
        printf("Ошибка: '%d' не является натуральным числом", m <= 0 ? m : n);
        return EXIT_FAILURE;
    }

    short matrix[m][n];
    if(set_matrix){
        printf("Введите строки матрицы:\n");
        fflush(stdout);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char q[5];
                scanf("%s", q);
                if(isnum(q))
                    matrix[i][j] = atoi(q);
                else{
                    printf("Ошибка: '%s' не является числом\n", q);
                    return EXIT_FAILURE;
                }
            }
        }
    }
    else{
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                matrix[i][j] = (short)(rand() % RAND_MAX);
    }

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
    int q = scanf("%hd %hd %hd %hd", &p1, &p2, &p3, &p4);
    if(q != 4){
        printf("Вы неправильно ввели матрицу P");
        return EXIT_FAILURE;
    }

    printf("Матрица P:\n%hd %hd\n%hd %hd\n", p1, p2, p3, p4);
    fflush(stdout);

    for(int i = 0; i < m - 1; ++i){
        for(int j = 0; j < m - 1; ++j){
            if(matrix[i][j] == p1 && matrix[i][j + 1] == p2 && matrix[i + 1][j] == p3 && matrix[i + 1][j + 1] == p4){
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
    printf("Результат:\n");
    for(int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%hd ", matrix[i][j]);
        printf("\n");
    }
    return EXIT_SUCCESS;
}
