#include <stdio.h>
#define NUMERO_DE_TENTATIVAS 5

int main () {
  printf ("Bem-vindo ao nosso programa de adivinhação\n");
  printf("Neste jogo você terá cinco tentativas para adivinhar qual é o número secreto. Vamos lá?\n");

  int numerosecreto = 14;
  
  for (int i = 1; i<= NUMERO_DE_TENTATIVAS; i++) {
    
    int chute;
    
    printf("Tentativa %i de %i\n", i, NUMERO_DE_TENTATIVAS);
    printf("Qual é o seu chute?\n");
    int deu_certo = scanf("%i", &chute);

    int acertou = (chute == numerosecreto);
    int maior = chute > numerosecreto;
    int menor = chute < numerosecreto;

    if (chute < 0) {
      printf ("Você não pode digitar números negativos\n");
      i--;
      continue;
    }
    
    else if (acertou) {
      printf("Parabéns, você acertou!\n");
      break;
    }
      
    else if (maior) {
      printf("Seu chute foi maior que o número secreto\n"); 
    }

    else {
      printf("Seu chute é menor que o número secreto\n");
    }
  }
  printf("Fim de jogo!\n");
}