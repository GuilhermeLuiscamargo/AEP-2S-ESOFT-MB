programa
{
    funcao inicio()
    {
        inteiro opcao
        inteiro faixa_etaria
        inteiro ano_escolar
        inteiro vacina
        inteiro situacao
        inteiro id
        inteiro novo_registro

        id = 0

        faca
        {
            escreva("\n===== MENU =====\n")
            escreva("1 - Registrar situacao vacinal\n")
            escreva("2 - Ler registro vacinal ou resumo geral\n")
            escreva("3 - Alterar dados de registro\n")
            escreva("4 - Apagar registro\n")
            escreva("5 - Sair do sistema\n")
            escreva("Escolha uma opcao: ")
            leia(opcao)

            escolha (opcao)
            {
                caso 1:

                    faca
                    {
                        escreva("\nInforme a faixa etaria: ")
                        leia(faixa_etaria)

                        se (faixa_etaria < 0)
                        {
                            escreva("\nFaixa etaria invalida!\n")
                        }
                    }
                    enquanto (faixa_etaria < 0)


                    faca
                    {
                        escreva("\nInforme o ano escolar: ")
                        leia(ano_escolar)

                        se (ano_escolar < 1 ou ano_escolar > 9)
                        {
                            escreva("\nAno escolar invalido!\n")
                        }
                    }
                    enquanto (ano_escolar < 1 ou ano_escolar > 9)


                    faca
                    {
                        escreva("\nSelecione a vacina:\n")
                        escreva("1 - Vacina 1\n")
                        escreva("2 - Vacina 2\n")
                        escreva("3 - Vacina 3\n")
                        escreva("Opcao: ")
                        leia(vacina)

                        se (vacina < 1 ou vacina > 3)
                        {
                            escreva("\nVacina invalida!\n")
                        }
                    }
                    enquanto (vacina < 1 ou vacina > 3)


                    faca
                    {
                        escreva("\nInforme a situacao da vacina:\n")
                        escreva("1 - Em dia\n")
                        escreva("2 - Pendente\n")
                        escreva("Opcao: ")
                        leia(situacao)

                        se (situacao < 1 ou situacao > 2)
                        {
                            escreva("\nSituacao invalida!\n")
                        }
                    }
                    enquanto (situacao < 1 ou situacao > 2)


                    id = id + 1

                    escreva("\nID anonimo gerado: ", id)
                    escreva("\nRegistro realizado com sucesso!\n")

                    escreva("\nDeseja realizar um novo registro?\n")
                    escreva("1 - Sim\n")
                    escreva("2 - Nao\n")
                    escreva("Opcao: ")
                    leia(novo_registro)

                    enquanto (novo_registro == 1)
                    {
                        escreva("\n===== NOVO REGISTRO =====\n")

                        escreva("Informe a faixa etaria: ")
                        leia(faixa_etaria)

                        escreva("Informe o ano escolar: ")
                        leia(ano_escolar)

                        escreva("Selecione a vacina: ")
                        leia(vacina)

                        escreva("Informe a situacao da vacina: ")
                        leia(situacao)

                        id = id + 1

                        escreva("\nID anonimo gerado: ", id)
                        escreva("\nRegistro realizado com sucesso!\n")

                        escreva("\nDeseja realizar outro registro?\n")
                        escreva("1 - Sim\n")
                        escreva("2 - Nao\n")
                        escreva("Opcao: ")
                        leia(novo_registro)
                    }

                    pare


                caso 2:

                    escreva("\n===== CONSULTA =====\n")
                    escreva("Consultar registro vacinal ou exibir resumo geral.\n")
                    escreva("Funcao em desenvolvimento.\n")

                    pare


                caso 3:

                    escreva("\n===== ALTERACAO =====\n")
                    escreva("Selecionar registro para alteracao.\n")
                    escreva("Atualizar dados do registro.\n")
                    escreva("Funcao em desenvolvimento.\n")

                    pare


                caso 4:

                    escreva("\n===== EXCLUSAO =====\n")
                    escreva("Selecionar registro para exclusao.\n")
                    escreva("Deseja confirmar a exclusao?\n")
                    escreva("1 - Sim\n")
                    escreva("2 - Nao\n")
                    escreva("Opcao: ")
                    leia(novo_registro)

                    se (novo_registro == 1)
                    {
                        escreva("\nRegistro apagado com sucesso!\n")
                    }
                    senao
                    {
                        escreva("\nExclusao cancelada.\n")
                    }

                    pare


                caso 5:

                    escreva("\nSaindo do sistema...\n")

                    pare


                caso contrario:

                    escreva("\nOpcao invalida! Tente novamente.\n")
            }
        }
        enquanto (opcao != 5)

        escreva("\nSistema encerrado.\n")
    }
}