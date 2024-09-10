#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
    char buffer[MAX_SIZE];
    FILE *txt;
    FILE *output;

    // Abrir o arquivo original para leitura
    if ((txt = fopen("arquivo_texto.txt", "r")) == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        return 1;
    }

    // Ler o conteúdo do arquivo para o buffer
    size_t size = fread(buffer, 1, MAX_SIZE - 1, txt);
    if (size == 0) {
        printf("Erro ao ler o arquivo ou arquivo vazio\n");
        fclose(txt);
        return 1;
    }
    buffer[size] = '\0'; // Adiciona o terminador de string

    fclose(txt);

    // Inverter o conteúdo do buffer
    char inverted[MAX_SIZE];
    for (size_t i = 0; i < size; i++) {
        inverted[i] = buffer[size - 1 - i];
    }
    inverted[size] = '\0'; // Adiciona o terminador de string

    // Abrir o arquivo de saída para escrita
    if ((output = fopen("arquivo_texto_invertido.txt", "w")) == NULL) {
        printf("Erro ao abrir o arquivo de saída\n");
        return 1;
    }

    // Escrever o conteúdo invertido no arquivo de saída
    fwrite(inverted, 1, size, output);

    fclose(output);

    printf("Arquivo invertido gerado com sucesso.\n");

    return 0;
}

