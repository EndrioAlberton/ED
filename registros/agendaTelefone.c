#include <stdio.h>

typedef struct {
    char nome[50];
    char telefone[11];
    char celular[11];
} Contato;

int main()
{
    Contato agenda[3];
    int numContato;

    for (int i = 0; i < 1; i++)
    {
        printf("Digite o nome do contato %d: ", i + 1);
        scanf("%s", agenda[i].nome);
        printf("Digite o telefone do contato %d: ", i + 1);
        scanf("%s", agenda[i].telefone);
        printf("Digite o celular do contato %d: ", i + 1);
        scanf("%s", agenda[i].celular);
    }

    for(;;) 
    {
        printf("Digite o numero contato você deseja visualizar? ");
        scanf("%d", &numContato);
        numContato = numContato-1;
        if (numContato >= 0 && numContato < 3){
            printf("Contato %d\n", numContato+1);
            printf("Nome: %s\n", agenda[numContato].nome);
            printf("Telefone: %s\n", agenda[numContato].telefone);
            printf("Celular: %s\n", agenda[numContato].celular);
        }else {
            printf("Contato não encontrado\n");
            break;
        }
    } 
    return 0;
}
