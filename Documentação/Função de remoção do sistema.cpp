void removerCadastro(Aluno alunos[], int *totalAlunos) {
    int identificador, indice = -1, confirmacao;

    if (*totalAlunos == 0) {
        printf("\n[AVISO] A lista de alunos esta vazia.\n");
        return;
    }

    printf("\n----------------------------------------\n");
    printf("         REMOCAO DE CADASTRO\n");
    printf("----------------------------------------\n");
    printf("Informe o ID numerico do cadastro: ");

    identificador = validarOpcao(1, INT_MAX - 1);
    if (identificador == -1) return;

    for (int i = 0; i < *totalAlunos; i++) {
        if (alunos[i].id == identificador) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n[NAO LOCALIZADO] Nenhum cadastro corresponde ao ID %d.\n", identificador);
        return;
    }

    printf("\n[CADASTRO LOCALIZADO]\n");
    exibirAluno(alunos[indice]);
    printf("\nATENCAO: esta operacao remove o cadastro e suas vacinas.\n");
    printf("1) Prosseguir com a remocao\n2) Manter o cadastro\n");

    confirmacao = validarOpcao(1, 2);
    if (confirmacao == -1) return;

    if (confirmacao == 2) {
        printf("\n[CANCELADO] O cadastro foi preservado.\n");
        return;
    }

    for (int i = indice; i < *totalAlunos - 1; i++) {
        alunos[i] = alunos[i + 1];
    }

    (*totalAlunos)--;
    printf("\n[CONCLUIDO] Cadastro ALUNO-%d removido.\n", identificador);
}
