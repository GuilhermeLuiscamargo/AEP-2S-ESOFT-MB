#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main() {
    int codigo[MAX];
    int quantidadePrevista[MAX];
    int situacao[MAX];
    int quantidadeEfetiva[MAX];
    
    int totalRegistros = 0;
    int codigoBusca;
    int posicao = -1;
    int i;
    
    codigo[0] = 101;
    quantidadePrevista[0] = 30;
    situacao[0] = 1;
    quantidadeEfetiva[0] = 0;
    totalRegistros = 1;

    printf("===== ALTERAR REGISTRO =====\n\n");

    if (totalRegistros == 0) {
        printf("Nenhum registro cadastrado.\n");
        return 0;
    }

    printf("Digite o codigo do registro que deseja alterar: ");
    scanf("%d", &codigoBusca);

    for (i = 0; i < totalRegistros; i++) {
        if (codigo[i] == codigoBusca) {
            posicao = i;
        }
    }

    if (posicao == -1) {
        printf("Registro nao encontrado!\n");
        return 0;
    }

    printf("\nRegistro encontrado na posicao %d!\n", posicao);
    
    printf("Digite o novo codigo: ");
    scanf("%d", &codigo[posicao]);

    printf("Digite a nova quantidade prevista: ");
    scanf("%d", &quantidadePrevista[posicao]);

    printf("\nSituacao da acao:\n");
    printf("1 - Planejada\n");
    printf("2 - Realizada\n");
    printf("3 - Cancelada\n");
    printf("Escolha a opcao: ");
    scanf("%d", &situacao[posicao]);

    if (situacao[posicao] == 2) {
        printf("Digite a quantidade efetiva de participantes: ");
        scanf("%d", &quantidadeEfetiva[posicao]);
    } else {
        quantidadeEfetiva[posicao] = 0;
    }

    printf("\nRegistro alterado com sucesso!\n\n");

    printf("===== DADOS ATUALIZADOS =====\n");
    printf("Codigo: %d\n", codigo[posicao]);
    printf("Quantidade Prevista: %d\n", quantidadePrevista[posicao]);
    printf("Situacao: %d\n", situacao[posicao]);
    printf("Quantidade Efetiva: %d\n", quantidadeEfetiva[posicao]);

    return 0;
}
