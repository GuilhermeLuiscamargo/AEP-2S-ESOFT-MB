#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

#define TOTAL_VACINAS 15

typedef struct {
    int tipo;
    int situacao;
} RegistroVacina;

typedef struct {
    int id;
    int faixaEtaria;
    int etapaEscolar;
    RegistroVacina vacinas[TOTAL_VACINAS];
    int quantidadeVacinas;
} Aluno;

const char *nomesVacinas[TOTAL_VACINAS] = {
    "Dengue",
    "Triplice viral (sarampo, caxumba e rubeola)",
    "Varicela (catapora)",
    "Triplice bacteriana (DTP)",
    "Poliomielite (VIP)",
    "Febre amarela",
    "Hepatite B",
    "Dupla adulto (dT - difteria e tetano)",
    "HPV (papilomavirus humano)",
    "Meningococica ACWY",
    "Meningococica C",
    "Influenza (gripe)",
    "Covid-19",
    "Hepatite A",
    "Pneumococica conjugada"
};

const char *nomesSituacoes[2] = {
    "Em dia", "Pendente"
};

// Limpa o terminal no Windows (Dev-C++).
void limparTela(void) {
    system("cls");
}

void menu(void) {
    printf("\n========== SISTEMA DE SITUACAO VACINAL ==========\n");
    printf("1 - Registrar aluno\n2 - Consultar alunos\n3 - Atualizar aluno\n4 - Excluir aluno\n5 - Sair\n");
}

int validarOpcao(int minimo, int maximo) {
    int opcao, leitura, c;
    do {
        opcao = 0;
        printf("Opcao: ");
        leitura = scanf("%d", &opcao);
        while ((c = getchar()) != '\n' && c != EOF) {}
        if (leitura == EOF || c == EOF) return -1;
        if (leitura != 1 || opcao < minimo || opcao > maximo)
            printf("\nOpcao invalida! Digite novamente.\n");
    } while (leitura != 1 || opcao < minimo || opcao > maximo);
    return opcao;
}

void exibirAluno(Aluno aluno) {
    int i;
    printf("\nIdentificador: ALUNO-%d\n", aluno.id);
    printf("Faixa etaria: ");
    switch (aluno.faixaEtaria) {
        case 1: printf("4 a 6 anos\n"); break;
        case 2: printf("7 a 10 anos\n"); break;
        case 3: printf("11 a 14 anos\n"); break;
        case 4: printf("15 a 18 anos\n"); break;
    }
    printf("Etapa escolar: ");
    switch (aluno.etapaEscolar) {
        case 1: printf("Educacao Infantil\n"); break;
        case 2: printf("Fundamental: 1 ao 3 ano\n"); break;
        case 3: printf("Fundamental: 4 ao 5 ano\n"); break;
        case 4: printf("Fundamental: 6 ao 9 ano\n"); break;
        case 5: printf("Ensino Medio: 1 a 3 serie\n"); break;
    }
    printf("Vacinas registradas: %d\n", aluno.quantidadeVacinas);
    for (i = 0; i < aluno.quantidadeVacinas; i++) {
        printf("%d - %s | Situacao: %s\n", i + 1,
               nomesVacinas[aluno.vacinas[i].tipo - 1],
               nomesSituacoes[aluno.vacinas[i].situacao - 1]);
    }
}

void registrar(Aluno **alunos, int *quantidade, int *capacidade, int *proximoId) {
    Aluno novo = {0};
    int valor, i, j, repetida;

    printf("\n========== NOVO REGISTRO ==========\n");
    printf("\nSelecione a faixa etaria:\n");
    printf("1 - 4 a 6 anos\n2 - 7 a 10 anos\n3 - 11 a 14 anos\n4 - 15 a 18 anos\n");
    valor = validarOpcao(1, 4);
    if (valor == -1) return;
    novo.faixaEtaria = valor;

    printf("\nSelecione a etapa escolar:\n");
    printf("1 - Educacao Infantil\n2 - Fundamental: 1 ao 3 ano\n3 - Fundamental: 4 ao 5 ano\n4 - Fundamental: 6 ao 9 ano\n5 - Ensino Medio: 1 a 3 serie\n");
    valor = validarOpcao(1, 5);
    if (valor == -1) return;
    novo.etapaEscolar = valor;

    printf("\nQuantas vacinas deseja registrar? (1 a 15)\n");
    valor = validarOpcao(1, TOTAL_VACINAS);
    if (valor == -1) return;
    novo.quantidadeVacinas = valor;

    for (i = 0; i < novo.quantidadeVacinas; i++) {
        printf("\n========== VACINA %d DE %d ==========\n", i + 1, novo.quantidadeVacinas);
        do {
            printf("\nSelecione a vacina:\n");
            for (j = 0; j < TOTAL_VACINAS; j++)
                printf("%d - %s\n", j + 1, nomesVacinas[j]);
            valor = validarOpcao(1, TOTAL_VACINAS);
            if (valor == -1) return;
            repetida = 0;
            for (j = 0; j < i; j++) {
                if (novo.vacinas[j].tipo == valor) {
                    repetida = 1;
                    break;
                }
            }
            if (repetida) printf("\nEssa vacina ja foi registrada para este aluno. Escolha outra.\n");
        } while (repetida);
        novo.vacinas[i].tipo = valor;

        printf("\nSituacao de %s:\n", nomesVacinas[valor - 1]);
        printf("1 - Em dia\n2 - Pendente\n");
        valor = validarOpcao(1, 2);
        if (valor == -1) return;
        novo.vacinas[i].situacao = valor;
    }

    if (*proximoId == INT_MAX) {
        printf("\nLimite de IDs atingido.\n");
        return;
    }
    if (*quantidade >= *capacidade - 1) {
        if (*capacidade == INT_MAX || (size_t)(*capacidade + 1) > SIZE_MAX / sizeof(Aluno)) {
            printf("\nLimite de memoria atingido.\n");
            return;
        }
        int novaCapacidade = *capacidade + 1;
        Aluno *temporario = realloc(*alunos, (size_t)novaCapacidade * sizeof(Aluno));
        if (temporario == NULL) {
            printf("\nErro ao aumentar a memoria.\n");
            return;
        }
        *alunos = temporario;
        *capacidade = novaCapacidade;
    }
    novo.id = *proximoId;
    (*alunos)[*quantidade] = novo;
    (*quantidade)++;
    (*proximoId)++;
    printf("\nRegistro realizado com sucesso!\nIdentificador: ALUNO-%d\n", novo.id);
}

void consultaIndividual(Aluno alunos[], int quantidade) {
    int id, c, i;
    if (quantidade == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }
    printf("\nInforme o numero do ID do aluno: ");
    if (scanf("%d", &id) != 1) {
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("\nID invalido.\n");
        return;
    }
    while ((c = getchar()) != '\n' && c != EOF) {}
    for (i = 0; i < quantidade; i++) {
        if (alunos[i].id == id) {
            limparTela();
            printf("\n========== CONSULTA INDIVIDUAL ==========\n");
            exibirAluno(alunos[i]);
            return;
        }
    }
    printf("\nAluno nao encontrado.\n");
}

void consultaGeral(Aluno alunos[], int quantidade) {
    int i, j;
    if (quantidade == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }
    limparTela();
    printf("\n========== CONSULTA GERAL ==========\n");
    for (i = 0; i < quantidade; i++) {
        printf("\nALUNO-%d | %d vacina(s) registrada(s)\n", alunos[i].id, alunos[i].quantidadeVacinas);
        for (j = 0; j < alunos[i].quantidadeVacinas; j++) {
            printf("  %d - %s | %s\n", j + 1,
                   nomesVacinas[alunos[i].vacinas[j].tipo - 1],
                   nomesSituacoes[alunos[i].vacinas[j].situacao - 1]);
        }
    }
}

void consultar(Aluno alunos[], int quantidade) {
    int opcao;
    do {
        printf("\n========== CONSULTAR ALUNOS ==========\n");
        printf("1 - Consulta individual\n2 - Consulta geral\n3 - Voltar\n");
        opcao = validarOpcao(1, 3);
        if (opcao == -1) return;
        switch (opcao) {
            case 1: limparTela(); consultaIndividual(alunos, quantidade); break;
            case 2: limparTela(); consultaGeral(alunos, quantidade); break;
            case 3: break;
        }
    } while (opcao != 3);
}

void atualizar(Aluno alunos[], int quantidade) {
    int id, posicao = -1, opcao, valor, i, j, indice, repetida;

    if (quantidade == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\n========== ATUALIZAR ALUNO ==========\n");
    printf("\nInforme o numero do ID do aluno que deseja alterar:\n");
    id = validarOpcao(1, INT_MAX - 1);
    if (id == -1) return;

    for (i = 0; i < quantidade; i++) {
        if (alunos[i].id == id) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("\nAluno nao encontrado!\n");
        return;
    }

    printf("\nAluno encontrado!\n");
    exibirAluno(alunos[posicao]);

    do {
        printf("\n========== MENU DE ATUALIZACAO ==========\n");
        printf("1 - Alterar faixa etaria\n2 - Alterar etapa escolar\n3 - Alterar situacao de uma vacina\n4 - Adicionar nova vacina\n5 - Remover vacina cadastrada\n6 - Voltar\n");
        opcao = validarOpcao(1, 6);
        if (opcao == -1) return;

        switch (opcao) {
            case 1:
                printf("\nSelecione a nova faixa etaria:\n");
                printf("1 - 4 a 6 anos\n2 - 7 a 10 anos\n3 - 11 a 14 anos\n4 - 15 a 18 anos\n");
                valor = validarOpcao(1, 4);
                if (valor == -1) return;
                alunos[posicao].faixaEtaria = valor;
                printf("\nFaixa etaria atualizada com sucesso!\n");
                break;

            case 2:
                printf("\nSelecione a nova etapa escolar:\n");
                printf("1 - Educacao Infantil\n2 - Fundamental: 1 ao 3 ano\n3 - Fundamental: 4 ao 5 ano\n4 - Fundamental: 6 ao 9 ano\n5 - Ensino Medio: 1 a 3 serie\n");
                valor = validarOpcao(1, 5);
                if (valor == -1) return;
                alunos[posicao].etapaEscolar = valor;
                printf("\nEtapa escolar atualizada com sucesso!\n");
                break;

            case 3:
                printf("\nSelecione a vacina cuja situacao deseja alterar:\n");
                for (i = 0; i < alunos[posicao].quantidadeVacinas; i++) {
                    printf("%d - %s | %s\n", i + 1,
                           nomesVacinas[alunos[posicao].vacinas[i].tipo - 1],
                           nomesSituacoes[alunos[posicao].vacinas[i].situacao - 1]);
                }
                indice = validarOpcao(1, alunos[posicao].quantidadeVacinas);
                if (indice == -1) return;
                printf("\nSelecione a nova situacao:\n");
                printf("1 - Em dia\n2 - Pendente\n");
                valor = validarOpcao(1, 2);
                if (valor == -1) return;
                alunos[posicao].vacinas[indice - 1].situacao = valor;
                printf("\nSituacao vacinal atualizada com sucesso!\n");
                break;

            case 4:
                if (alunos[posicao].quantidadeVacinas >= TOTAL_VACINAS) {
                    printf("\nEste aluno ja possui as 15 vacinas cadastradas.\n");
                    break;
                }
                do {
                    printf("\nSelecione a vacina que deseja adicionar:\n");
                    for (i = 0; i < TOTAL_VACINAS; i++)
                        printf("%d - %s\n", i + 1, nomesVacinas[i]);
                    valor = validarOpcao(1, TOTAL_VACINAS);
                    if (valor == -1) return;
                    repetida = 0;
                    for (i = 0; i < alunos[posicao].quantidadeVacinas; i++) {
                        if (alunos[posicao].vacinas[i].tipo == valor) {
                            repetida = 1;
                            break;
                        }
                    }
                    if (repetida)
                        printf("\nEssa vacina ja esta cadastrada para este aluno.\n");
                } while (repetida);
                j = alunos[posicao].quantidadeVacinas;
                alunos[posicao].vacinas[j].tipo = valor;
                printf("\nSelecione a situacao de %s:\n", nomesVacinas[valor - 1]);
                printf("1 - Em dia\n2 - Pendente\n");
                valor = validarOpcao(1, 2);
                if (valor == -1) return;
                alunos[posicao].vacinas[j].situacao = valor;
                alunos[posicao].quantidadeVacinas++;
                printf("\nVacina adicionada com sucesso!\n");
                break;

            case 5:
                if (alunos[posicao].quantidadeVacinas == 0) {
                    printf("\nNenhuma vacina cadastrada para remover.\n");
                    break;
                }
                printf("\nSelecione a vacina que deseja remover:\n");
                for (i = 0; i < alunos[posicao].quantidadeVacinas; i++)
                    printf("%d - %s\n", i + 1,
                           nomesVacinas[alunos[posicao].vacinas[i].tipo - 1]);
                indice = validarOpcao(1, alunos[posicao].quantidadeVacinas);
                if (indice == -1) return;
                for (i = indice - 1; i < alunos[posicao].quantidadeVacinas - 1; i++)
                    alunos[posicao].vacinas[i] = alunos[posicao].vacinas[i + 1];
                alunos[posicao].quantidadeVacinas--;
                printf("\nVacina removida com sucesso!\n");
                break;

            case 6:
                printf("\nRetornando ao menu principal.\n");
                break;
        }
    } while (opcao != 6);
}

void apagar(Aluno alunos[], int *quantidade) {
    int id, posicao = -1, opcao, i;

    if (*quantidade == 0) {
        printf("\nNenhum aluno cadastrado para exclusao.\n");
        return;
    }

    printf("\n========== EXCLUIR ALUNO ==========\n");
    printf("\nInforme o numero do ID do aluno que deseja excluir:\n");

    id = validarOpcao(1, INT_MAX - 1);
    if (id == -1) return;

    for (i = 0; i < *quantidade; i++) {
        if (alunos[i].id == id) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("\nAluno nao encontrado!\n");
        return;
    }

    printf("\n========== REGISTRO ENCONTRADO ==========\n");
    exibirAluno(alunos[posicao]);

    printf("\nDeseja realmente excluir este aluno?\n");
    printf("1 - Confirmar exclusao\n2 - Cancelar\n");

    opcao = validarOpcao(1, 2);
    if (opcao == -1) return;

    if (opcao == 2) {
        printf("\nExclusao cancelada.\n");
        return;
    }

    for (i = posicao; i < *quantidade - 1; i++) {
        alunos[i] = alunos[i + 1];
    }

    (*quantidade)--;

    printf("\nAluno ALUNO-%d excluido com sucesso!\n", id);
}

int main(void) {
    int quantidade = 0, capacidade = 5, proximoId = 1;
    int opcao;
    Aluno *alunos = malloc((size_t)capacidade * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    do {
        menu();
        opcao = validarOpcao(1, 5);
        if (opcao == -1) break;
        switch (opcao) {
            case 1: limparTela(); registrar(&alunos, &quantidade, &capacidade, &proximoId); break;
            case 2: limparTela(); consultar(alunos, quantidade); break;
            case 3: limparTela(); atualizar(alunos, quantidade); break;
            case 4: limparTela(); apagar(alunos, &quantidade); break;
            case 5: printf("\nEncerrando o programa.\n"); break;
        }
    } while (opcao != 5);
    free(alunos);
    return 0;
}
