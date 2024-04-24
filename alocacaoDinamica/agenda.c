#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[40];
    char telefone[15];
} contato;

int main(int argc, char *argv[]) {
    contato *teste;

    // Verifica se a alocação de memória foi bem-sucedida
    teste = (contato*)malloc(sizeof(contato));
    if (teste == NULL) {
        printf("Falha ao alocar memória.\n");
        return 1; // Retorna 1 para indicar falha
    }

    printf("Digite seu nome: ");
    gets((*teste).nome);

    strcpy((*teste).telefone, "1234567");

    printf("Nome = %s\nTelefone = %s\n", (*teste).nome, (*teste).telefone);

    free(teste);
    return 0; // Retorna 0 para indicar sucesso
}
