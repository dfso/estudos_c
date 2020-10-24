#include <stdio.h>
#include <stdlib.h>

#define TAM 30  // tamanho do vetor


int main()
{
    char msg[TAM];
    char crypt[TAM];

    int i;

    printf("Digite a frase que sera' criptografada: ");
    scanf("%[^\n]s", msg);

    for(i=0; i<TAM; i++) {
        crypt[i] = msg[i] - 16;
    }

    printf("\n\nMensagem original: %s\n\n", msg);
    printf("Mensagem criptografada: %s\n\n", crypt);

    for(i=0; i<TAM; i++)
        crypt[i] = crypt[i] + 16;
    printf("Mensagem original: %s\n\n", crypt);

    return 0;
    
}
