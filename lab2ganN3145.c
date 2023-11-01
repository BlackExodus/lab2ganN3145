#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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


    int m, n;
    scanf("-m %d %d", &m, &n);

    short matrix[m][n];

    short p1, p2, p3, p4;
    scanf("%hd %hd %hd %hd", &p1, &p2, &p3, &p4);

    int x = -1, y = -1;

    for(int i = 0; i < m - 1; i++) {
        for(int j = 0; j < n - 1; ++j) {
            if(matrix[i][j] == p1 && matrix[i][j + 1] == p2 && matrix[i + 1][j] == p3 && matrix[i + 1][j + 1] == p4){
                x = j;
                y = i;
                goto success;
            }
        }
    }

    printf("No P matrix, sorry :(\n");
    return EXIT_FAILURE;

    success:
    printf("x = %d, y = %d\n", x, y);
    
    return EXIT_SUCCESS;
}
