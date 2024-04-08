#include <stdio.h>

#define MAX_ALUNOS 5

struct Aluno {
    char nome[50];
    char telefone[15];
    int idade;
    char contato[50];
};

void lerInformacoesAluno(int i, struct Aluno alunos[]) {
    printf("Digite o nome do aluno %d:   ", i + 1);
    scanf("%s", alunos[i].nome);
    
    printf("Digite o telefone de emergencia do aluno: ");
    scanf("%s", alunos[i].telefone);
    
    printf("Digite a idade do aluno: ");
    scanf("%d", &alunos[i].idade);
    
    printf("Digite o contato de emergencia do aluno: ");
    scanf("%s", alunos[i].contato);
}

void imprimirDadosAluno(int i, struct Aluno alunos[]) {
    printf("Aluno %d:\n", i + 1);
    printf("Nome: %s\n", alunos[i].nome);
    printf("Telefone de emergencia: %s\n", alunos[i].telefone);
    printf("Idade: %d\n", alunos[i].idade);
    printf("Contato de emergencia: %s\n", alunos[i].contato);
}

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    
    for (int i = 0; i < MAX_ALUNOS; i++) {
        lerInformacoesAluno(i, alunos);
    }
    
    for (int i = 0; i < MAX_ALUNOS; i++) {
        imprimirDadosAluno(i, alunos);
    }
    
    return 0;
}