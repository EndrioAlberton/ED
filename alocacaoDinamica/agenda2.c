#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTROS 100

typedef struct {
    char nome[100];
    char telefone[20];
    char celular[20];
    char endereco[200];
    char aniversario[20];
} Contato;

void inserirContato(Contato **agenda, int *numContatos) {
    if (*numContatos >= MAX_REGISTROS) {
        printf("A agenda está cheia. Não é possível adicionar mais contatos.\n");
        return;
    }

    Contato *novoContato = (Contato *)malloc(sizeof(Contato));
    if (novoContato == NULL) {
        printf("Erro ao alocar memória para o novo contato.\n");
        return;
    }

    printf("Digite o nome: ");
    fgets((*novoContato).nome, sizeof((*novoContato).nome), stdin);
    (*novoContato).nome[strcspn((*novoContato).nome, "\n")] = '\0'; // Remover o caractere de nova linha

    printf("Digite o telefone: ");
    fgets((*novoContato).telefone, sizeof((*novoContato).telefone), stdin);
    (*novoContato).telefone[strcspn((*novoContato).telefone, "\n")] = '\0'; // Remover o caractere de nova linha

    printf("Digite o celular: ");
    fgets((*novoContato).celular, sizeof((*novoContato).celular), stdin);
    (*novoContato).celular[strcspn((*novoContato).celular, "\n")] = '\0'; // Remover o caractere de nova linha

    printf("Digite o endereço: ");
    fgets((*novoContato).endereco, sizeof((*novoContato).endereco), stdin);
    (*novoContato).endereco[strcspn((*novoContato).endereco, "\n")] = '\0'; // Remover o caractere de nova linha

    printf("Digite o aniversário: ");
    fgets((*novoContato).aniversario, sizeof((*novoContato).aniversario), stdin);
    (*novoContato).aniversario[strcspn((*novoContato).aniversario, "\n")] = '\0'; // Remover o caractere de nova linha

    agenda[*numContatos] = novoContato;
    (*numContatos)++;
}

void visualizarContato(Contato **agenda, int numContatos) {
    int posicao;

    printf("Digite a posição do contato que deseja visualizar (1 a %d): ", numContatos);
    scanf("%d", &posicao);
    getchar();
    if (posicao < 1 || posicao > numContatos) {
        printf("Posição inválida.\n");
        return;
    }

    printf("Nome: %s\n", (*agenda[posicao - 1]).nome);
    printf("Telefone: %s\n", (*agenda[posicao - 1]).telefone);
    printf("Celular: %s\n", (*agenda[posicao - 1]).celular);
    printf("Endereço: %s\n", (*agenda[posicao - 1]).endereco);
    printf("Aniversário: %s\n", (*agenda[posicao - 1]).aniversario);
}

int main() {
    Contato *agenda[MAX_REGISTROS] = {NULL};
    int numContatos = 0;
    int opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir contato\n");
        printf("2. Visualizar contato\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserirContato(agenda, &numContatos);
                break;
            case 2:
                visualizarContato(agenda, numContatos);
                break;
            case 3:
                printf("Encerrando programa.\n");
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }
    } while (opcao != 3);

    // Liberar memória alocada para os contatos
    for (int i = 0; i < numContatos; i++) {
        free(agenda[i]);
    }

    return 0;
}
