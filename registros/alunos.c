#include <stdio.h>

#define MAX_ALUNOS 1

struct Aluno {
    char nome[50];
    int matricula;
    float notas[4];
    int faltas;
};

struct Aluno alunos[MAX_ALUNOS];

void lerDadosAluno(int i) {
    printf("Digite o nome do aluno: ");
    scanf("%s", alunos[i].nome);
    
    printf("Digite o número de matrícula do aluno: ");
    scanf("%d", &alunos[i].matricula);
    
    printf("Digite as 4 notas do aluno: ");
    for (int i = 0; i < 4; i++) {
        scanf("%f", &alunos[i].notas[i]);
    }
    
    printf("Digite o número de faltas do aluno: ");
    scanf("%d", &alunos[i].faltas);
}

void escreverDadosAluno(int i) {
    printf("Nome: %s\n", alunos[i].nome);
    printf("Matrícula: %d\n", alunos[i].matricula);
    printf("Notas: ");
    for (int i = 0; i < 4; i++) {
        printf("%.2f ", alunos[i].notas[i]);
    }
    printf("\n");
    printf("Faltas: %d\n", alunos[i].faltas);
}

float calcularMedia(int i) {
    float soma = 0;
    for (int i = 0; i < 4; i++) {
        soma += alunos[i].notas[i];
    }
    return soma / 4;
}

void escreverSituacao(int i) {
    float media = calcularMedia(i);
    int faltas = alunos[i].faltas;
    
    if (media >= 7 && faltas <= 15) {
        printf("Situação: Aprovado\n");
    } else if (media >= 5 && faltas <= 15) {
        printf("Situação: Recuperação\n");
    } else {
        printf("Situação: Reprovado\n");
    }
}

int main() {
    for (int i = 0; i < MAX_ALUNOS; i++) {
        lerDadosAluno(i);
    }
    
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("Dados do aluno %d:\n", i+1);
        escreverDadosAluno(i);
        escreverSituacao(i);
        printf("\n");
    }
    
    return 0;
}