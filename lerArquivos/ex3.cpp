#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char linha[1024]; 
    FILE *txt;
    int inParagraph = 0;  // verificar se � um par�grafo.

    if ((txt = fopen("arquivo_texto.txt", "r")) == NULL)
    {
        printf("Erro ao abrir arquivo");
        return 1; 
    }
    
    while (fgets(linha, sizeof(linha), txt) != NULL) 
    {
        // Verifica se a linha lida est� vazia
        if (strcmp(linha, "\n") == 0) 
        {
            if (inParagraph) 
            {
                // Se est� no meio de um par�grafo e encontramos uma linha em branco, imprime uma linha em branco
                printf("\n");
                inParagraph = 0;  // Terminamos o par�grafo
            }
        }
        else 
        {
            // Se a linha n�o est� vazia, imprime a linha
            printf("%s", linha);
            inParagraph = 1;  // Estamos em um par�grafo
        }
    }
    
    fclose(txt);
    return 0;
}

