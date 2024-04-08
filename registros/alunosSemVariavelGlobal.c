#include <stdio.h>

#define MAX_ALUNOS 1

struct Aluno {
    char nome[50];
    int matricula;
    float notas[4];
    int faltas;
};


void lerDadosAluno(struct Aluno* alunos, int i) {

    printf("Digite o nome do aluno: ");
    scanf("%s", alunos[i].nome);
    
    printf("Digite o número de matrícula do aluno: ");
    scanf("%d", &alunos[i].matricula);
    
    printf("Digite as 4 notas do aluno: ");
    for (int j = 0; j < 4; j++) {
        scanf("%f", &alunos[i].notas[j]);
    }
    
    printf("Digite o número de faltas do aluno: ");
    scanf("%d", &alunos[i].faltas);
}

void escreverDadosAluno(struct Aluno* alunos, int i) {
    printf("Nome: %s\n", alunos[i].nome);
    printf("Matrícula: %d\n", alunos[i].matricula);
    printf("Notas: ");
    for (int j = 0; j < 4; j++) {
        printf("%.2f ", alunos[i].notas[j]);
    }
    printf("\n");
    printf("Faltas: %d\n", alunos[i].faltas);
}

float calcularMedia(struct Aluno* alunos, int i) {
    float soma = 0;
    for (int j = 0; j < 4; j++) {
        soma += alunos[i].notas[j];
    }
    return soma / 4;
}


void escreverSituacao(struct Aluno* alunos, int i) {
    float media = calcularMedia(alunos, i);
    int faltas = alunos[i].faltas;
    
    if (media >= 7 && faltas <= 15) {
        printf("Situação: Aprovado\n");
    } else if (media >= 5 && faltas <= 15) {
        printf("Situação: Recuperação\n");
    } else {
        printf("Situação: Reprovado\n");
    }
}

int main() {) {
    struct Aluno alunos[MAX_ALUNOS];
    
    for (int i = 0; i < MAX_ALUNOS; i++) {
        lerDadosAluno(alunos, i);
    }
    
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("Dados do aluno %d:\n", i+1);
        escreverDadosAluno(alunos, i);
        escreverSituacao(alunos, i);
        printf("\n");
    }
    
    return 0;
}
