#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *txt;
    char nome[100];
    int idade;
    int i;

    // Abrindo o arquivo para escrita
    printf("Digite o nome e a idade de 10 pessoas para gravar no arquivo lista.txt\n");
    txt = fopen("lista.txt", "w");
    if (txt == NULL) {
        printf("Erro ao abrir o arquivo"); 
        return 1; 
    }

    // Loop para ler os nomes e idades
    for (i = 0; i < 10; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(nome, sizeof(nome), stdin);

        printf("Digite a idade da pessoa %d: ", i + 1);
        if (scanf("%d", &idade) != 1) {
            fprintf(stderr, "Entrada inválida para idade.\n");
            fclose(txt);
            return 1;
        }
        
        // Limpar o buffer de entrada
        while (getchar() != '\n'); 

        // Escrever no arquivo
        fprintf(txt, "Nome: %s, Idade: %d\n", nome, idade);
    }

    fclose(txt);

    printf("Dados gravados com sucesso no arquivo lista.txt\n");

    return 0;
}

