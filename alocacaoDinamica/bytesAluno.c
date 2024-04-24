#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    char nome[150];
    char telefone[15];
    int idade;
    char contato[150];
} aluno;

void leitura(aluno *a){
    printf("Digite o nome do aluno: ");
    gets((*a).nome);
    printf("Digite a idade do aluno: ");
    scanf("%d",&(*a).idade);
    getchar(); // Limpar o buffer do teclado
    printf("Nome do Contato de emergencia: ");
    gets((*a).contato);
    printf("Digite o Telefone do Contato: ");
    gets(a->telefone);
}

void imprime(aluno a){
    printf("Nome: %s\t Idade: %d anos\n",a.nome,a.idade);
    printf("Contato: %s \tTelefone:%s\n",a.contato,a.telefone);
}

int main(int argc, char *argv[]) {
    aluno* alunos[MAX]; 
    int i, num;
    size_t tamanho_do_vetor_alunos, tamanho_da_variavel_aluno;

    // Cálculo do tamanho do vetor alunos
    tamanho_do_vetor_alunos = MAX * sizeof(aluno*);
    // Tamanho de uma variável do tipo aluno
    tamanho_da_variavel_aluno = sizeof(aluno);

    printf("Tamanho do vetor alunos: %zu bytes\n", tamanho_do_vetor_alunos);
    printf("Tamanho de uma variável do tipo aluno: %zu bytes\n", tamanho_da_variavel_aluno);
    // Tamanho total alocado para o programa
    printf("Tamanho total alocado para o programa: %zu bytes\n", tamanho_do_vetor_alunos + (MAX * tamanho_da_variavel_aluno));

    // Alocação de memória para cada aluno e leitura dos dados
    for(i = 0; i < MAX; i++) {
        alunos[i] = (aluno*)malloc(sizeof(aluno));
        if(alunos[i] != NULL)
            leitura(alunos[i]);
    }

    // Impressão dos dados de um aluno baseado no número digitado pelo usuário
    do {
        printf("Digite um numero de 1 a %d:", MAX);
        scanf("%d",&num);
        imprime(*alunos[num - 1]);
    } while(num);

    // Liberação de memória alocada para cada aluno
    for(i = 0; i < MAX; i++) {
        if(alunos[i] != NULL)
            free(alunos[i]);
    }

    return 0;
}
