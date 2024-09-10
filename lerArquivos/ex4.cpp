#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINHA 1024
#define NUM_PALAVRAS 3

void contarOcorrencias(char *linha, int *contadores);

void paraMinusculas(char *str);

int main() {
    char linha[MAX_LINHA];
    FILE *txt;
    int contadores[NUM_PALAVRAS] = {0}; // Contadores para "Direito", "Dever", "Deveres"

    if ((txt = fopen("arquivo_texto.txt", "r")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    while (fgets(linha, MAX_LINHA, txt)) {
        contarOcorrencias(linha, contadores);
    }

    fclose(txt);

    printf("Ocorrências:\n");
    printf("Direito: %d\n", contadores[0]);
    printf("Dever: %d\n", contadores[1]);
    printf("Deveres: %d\n", contadores[2]);

    return 0;
}

void contarOcorrencias(char *linha, int *contadores) {
    char *palavras[NUM_PALAVRAS] = {"direito", "dever", "deveres"};
    char linhaMinusculas[MAX_LINHA];
    paraMinusculas(linha); // Converte a linha para minúsculas
    strncpy(linhaMinusculas, linha, MAX_LINHA);

    for (int i = 0; i < NUM_PALAVRAS; i++) {
        char *ptr = linhaMinusculas;
        while ((ptr = strstr(ptr, palavras[i])) != NULL) {
            contadores[i]++;
            ptr += strlen(palavras[i]);
        }
    }
}

void paraMinusculas(char *str) {
    while (*str) {
        *str = tolower((unsigned char) *str);
        str++;
    }
}

