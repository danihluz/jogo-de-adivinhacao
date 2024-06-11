#include <stdio.h>
#define NUMERO_DE_TENTATIVAS 5

typedef struct {
    int tentativa_numero;
    int chute;
    int acertou;
    int maior;
    int menor;
} tentativa;

int main () {
    printf("Bem-vindo ao nosso programa de adivinhação\n");
    printf("Neste jogo você terá cinco tentativas para adivinhar qual é o número secreto. Vamos lá?\n");

    int numerosecreto = 14;
    tentativa tentativas[NUMERO_DE_TENTATIVAS];
    int tentativas_realizadas = 0;

    for (int i = 0; i < NUMERO_DE_TENTATIVAS; i++) {
        int chute;

        printf("Tentativa %i de %i\n", i + 1, NUMERO_DE_TENTATIVAS);
        printf("Qual é o seu chute?\n");
        int deu_certo = scanf("%i", &chute);

        int acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;
        int menor = chute < numerosecreto;

        if (chute < 0) {
            printf("Você não pode digitar números negativos\n");
            i--;
            continue;
        }
        
        tentativas[i].tentativa_numero = i + 1;
        tentativas[i].chute = chute;
        tentativas[i].acertou = acertou;
        tentativas[i].maior = maior;
        tentativas[i].menor = menor;

        tentativas_realizadas++;

        if (acertou) {
            printf("Parabéns, você acertou!\n");
            break;
        } else if (maior) {
            printf("Seu chute foi maior que o número secreto\n");
        } else {
            printf("Seu chute é menor que o número secreto\n");
        }
    }

    printf("Fim de jogo!\n");
    printf("Aqui estão suas tentativas:\n");

    for (int i = 0; i < tentativas_realizadas; i++) {
        printf("Tentativa %d: O chute foi %d, Acertou? = %s, O número é maior que 14? = %s, O número é menor que 14? = %s\n",
               tentativas[i].tentativa_numero,
               tentativas[i].chute,
               tentativas[i].acertou ? "Sim" : "Não",
               tentativas[i].maior ? "Sim" : "Não",
               tentativas[i].menor ? "Sim" : "Não");
    }

    return 0;
}
