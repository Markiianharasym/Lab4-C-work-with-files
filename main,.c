#include <stdio.h>
#include <stdlib.h>


int main(void) {
    char read[100];
    int linenumber = 0;
    FILE* file;
    FILE* fina;

    file = fopen("text.txt", "r");
    fina = fopen("final.txt", "w");
    if (file == NULL || fina == NULL) {
        perror("Opening file error!");
        exit(0);
    }

    int elements = 0;
    int sums = 0;


    while (fgets(read, sizeof(read), file) != NULL) {


        for (int i = 0; read[i] != '\0'; i++) {
            if (read[i] == '(') {
                elements = 1;
            }
            else if (read[i] == ')') {
                elements = 0;
            }
            else if (elements) {
                printf("Symbol in (%c):  Numerical value : %c\n", read[i], read[i]);
                sums += read[i];
                fputc(read[i], fina);

            }
        }
    }

    fclose(file);
    fclose(fina);

    printf("\n");
    printf("Sums numerical values = %d\n", sums);

    return 0;
}

