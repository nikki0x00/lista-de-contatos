#include <stdio.h>
#include <string.h>

void adicionar(int i, char telefones[][11]) {
    if (i == 100) {
        printf("--- ERRO: Agenda cheia, não é possivel adicionar mais contatos ---\n");
        return;
    }
    
     printf("Por favor digite o número a ser adicionado\n");
     scanf("%10s", telefones[i]);
     printf("--- Numero '%s' adicionado ---\n", telefones[i]);
}

void listar(int i, char telefones[][11]) {
    printf("--- Lista de Contatos (%d itens) ---\n", i);
        for (int n = 0; n < i; n++) {
        printf("Telefone %d: %s\n", n+1 , telefones[n]);
        }
        printf("-----------------------------------\n");
}

void remover(int i, char telefones[][11]) {
    int pos;
    listar(i, telefones); // Mostra a lista para o usuário escolher qual remover
    printf("Digite o numero do contato que deseja remover:");
    scanf("%d", &pos);
    
    if (pos >= 1 && pos <= i) {
        // Desloca os elementos para preencher o espaco
        for (int n = pos - 1; n < i - 1; n++) {
            strcpy(telefones[n], telefones[n+1]);
        }
        printf("--- Contato removido com sucesso ---\n");
    } else {
        printf("--- ERRO: Posicao invalida ---\n");
    }
}

int main() {
 char telefones[100][11];
 int i = 0, opc, ativo = 1;

 printf("--- Boas vindas a agenda de contatos da Nikki ---\n");
 
while (ativo == 1) {
 printf("1 Adicionar, 2 Listar, 3 Remover, 4 Desligar\n");
 scanf("%d", &opc);

 switch (opc) {
     case 1:
      adicionar(i, telefones);
      i++;
      break;
     case 2:
      listar(i, telefones);
      break;
     case 3:
      remover(i, telefones);
      i--;
      break;
     case 4:
      ativo = 0;
      printf("Desligando...");
      break;
     default:
      printf("opção invalida, tente novamente\n");
 }
 while ((getchar()) != '\n');
}
    return 0;
}