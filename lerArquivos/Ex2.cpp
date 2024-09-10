#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  

int main() {
    char caractere;

    FILE *txt;
    FILE *txtAlterado;

    if ((txt = fopen("arquivo_texto.txt", "r")) == NULL) {
        printf("Erro ao abrir o arquivo");
        return 1; 
    }

    if ((txtAlterado = fopen("texto_Alterado.txt", "w")) == NULL) {
        printf("Erro ao criar o arquivo Texto_Alterado.txt");
        fclose(txt); 
        return 1;
    }

    // Ler caractere por caractere do arquivo
    while ((caractere = fgetc(txt)) != EOF) {
        if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u' ||
            caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U') {
            caractere = toupper(caractere);  // Converter para maiúscula
        }

        printf("%c", caractere);

        fputc(caractere, txtAlterado);
    }

    fclose(txt);
    fclose(txtAlterado);

    system("pause"); 
    return 0; 
}

