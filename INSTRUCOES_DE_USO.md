# Instruções de uso — Sistema de Situação Vacinal

Este manual explica como **abrir, compilar, executar e utilizar** o sistema de verificação da situação vacinal dos alunos, desenvolvido em **C99** para a AEP de Engenharia de Software.

## 1. Requisitos

- Computador com **Windows**.
- **Dev-C++** instalado, com compilador **GCC** configurado e suporte à linguagem C99.
- Arquivo-fonte do sistema em formato `.c`.

> **Atenção:** se o Dev-C++ não tiver um compilador GCC instalado ou configurado corretamente, a compilação não será concluída. A aparência dos menus do programa pode variar conforme a versão do Dev-C++.

## 2. Baixar o projeto

1. Acesse o repositório: https://github.com/GuilhermeLuiscamargo/AEP-2S-ESOFT-MB
2. Clique em **Code → Download ZIP**.
3. Extraia o arquivo ZIP para uma pasta do computador.
4. Localize o arquivo-fonte do sistema (`.c`).

Também é possível baixar diretamente o arquivo `.c` pelo repositório.

## 3. Abrir o código no Dev-C++

1. Abra o **Dev-C++**.
2. Selecione **Arquivo → Abrir** (*File → Open*).
3. Navegue até a pasta onde o projeto foi extraído.
4. Selecione o arquivo `.c` do sistema e confirme a abertura.
5. Confira se o código aparece no editor.

**Não é necessário criar um projeto novo:** o programa pode ser compilado diretamente a partir do arquivo `.c`.

## 4. Compilar e executar

1. Com o arquivo `.c` aberto, selecione **Executar → Compilar e Executar** (*Execute → Compile & Run*).
2. Em versões do Dev-C++, o atalho costuma ser **F11**.
3. Aguarde a compilação. Se não houver erros, o terminal abrirá com o menu principal.
4. Digite o número da opção desejada e pressione **Enter**.

Se o Dev-C++ solicitar um local para salvar o arquivo antes de compilar, escolha uma pasta e confirme. Se aparecer uma mensagem de erro, verifique a configuração do compilador GCC e se o arquivo foi aberto como código C.

## 5. Menu principal

Ao executar o sistema, será exibido o menu:

```text
========== SISTEMA DE SITUACAO VACINAL ==========
1 - Registrar aluno
2 - Consultar alunos
3 - Atualizar aluno
4 - Excluir aluno
5 - Sair
Opcao:
```

Para escolher uma funcionalidade, digite o número correspondente e pressione **Enter**.

## 6. Registrar aluno — opção 1

1. Selecione **1 - Registrar aluno**.
2. Informe a **faixa etária** (uma opção entre 1 e 4).
3. Informe a **etapa escolar** (uma opção entre 1 e 5).
4. Informe quantas vacinas deseja registrar (**1 a 15**).
5. Para cada vacina, escolha uma das **15 vacinas disponíveis**.
6. Informe sua situação: **1 - Em dia** ou **2 - Pendente**.
7. Após o cadastro, anote o identificador gerado, por exemplo, `ALUNO-1`.

O sistema não permite registrar a mesma vacina duas vezes para o mesmo aluno.

## 7. Consultar alunos — opção 2

Selecione **2 - Consultar alunos**. O submenu oferece:

- **1 - Consulta individual:** informe o número do ID do aluno (por exemplo, `1` para `ALUNO-1`). O sistema exibirá faixa etária, etapa escolar, vacinas e respectivas situações.
- **2 - Consulta geral:** visualize todos os alunos cadastrados, com seus IDs e vacinas registradas.
- **3 - Voltar:** retorna ao menu principal.

## 8. Atualizar aluno — opção 3

1. Selecione **3 - Atualizar aluno**.
2. Digite o número do ID do registro que deseja modificar.
3. Confira os dados apresentados.
4. Escolha uma das opções disponíveis:

   - **1:** alterar faixa etária;
   - **2:** alterar etapa escolar;
   - **3:** alterar a situação de uma vacina;
   - **4:** adicionar uma nova vacina;
   - **5:** remover uma vacina cadastrada;
   - **6:** voltar ao menu principal.

O identificador do aluno permanece o mesmo após as alterações.

## 9. Excluir aluno — opção 4

1. Selecione **4 - Excluir aluno**.
2. Informe o número do ID do aluno que deseja excluir.
3. Confira os dados do registro localizado.
4. Escolha **1 - Confirmar exclusao** para apagar o registro ou **2 - Cancelar** para mantê-lo.

**A exclusão remove o registro inteiro do aluno**, não apenas uma vacina. Para retirar somente uma vacina, utilize a **opção 5 do menu de atualização**.

Os IDs dos demais alunos não são alterados, e os identificadores excluídos não são reutilizados durante a mesma execução.

## 10. Sair — opção 5

Selecione **5 - Sair** para encerrar o programa.

**Importante:** os dados são armazenados apenas na memória RAM. Ao fechar o sistema, todos os registros cadastrados durante aquela execução são perdidos.

## 11. Validações e dúvidas frequentes

- **Opção inválida:** digite um número dentro do intervalo apresentado pelo menu.
- **Aluno não encontrado:** confira o ID informado e se o aluno ainda está cadastrado.
- **Vacina já cadastrada:** escolha outra vacina para o mesmo aluno.
- **Erro de compilação:** confira se o GCC está instalado e configurado no Dev-C++.
- **Os registros desapareceram após fechar o programa:** esse é o comportamento esperado da versão atual, que não possui armazenamento permanente.

## 12. Finalidade do sistema

O sistema é um projeto acadêmico relacionado ao **Programa Saúde na Escola (PSE)**. Ele utiliza identificadores anônimos e não solicita nome, CPF ou outros dados pessoais dos estudantes. Não substitui o acompanhamento realizado por profissionais de saúde.
