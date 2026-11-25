#include <stdio.h>
#include <stdlib.h>

#include "trabalho2.h"

int menu(void);

int menu(void)
{
    int op;
    int resultado;
    int caractere;

    printf("\nDigite a opcao desejada\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Listar numeros de todas as estruturas\n");
    printf("3 - Listar numeros ordenados por estrutura\n");
    printf("4 - Listar todos os numeros de forma ordenada\n");
    printf("5 - Excluir um elemento\n");
    printf("6 - Aumentar o tamanho de uma estrutura auxiliar\n");
    printf("7 - Sair\n");
    printf("Opcao: ");

    resultado = scanf("%d", &op);

    if (resultado == EOF)
        return -1;

    if (resultado != 1)
    {
        while ((caractere = getchar()) != '\n' && caractere != EOF)
        {
            /* limpeza da entrada */
        }
        return -2;
    }

    if (op < 1 || op > 7)
    {
        /* Descarta o restante da linha quando a opcao e invalida. */
        while ((caractere = getchar()) != '\n' && caractere != EOF)
        {
            /* limpeza da entrada */
        }
    }

    return op;
}

int main(void)
{
    inicializar();

    int op;
    int sair = 0;
    int retorno;

    while (!sair)
    {
        op = menu();

        if (op == -1)
        {
            sair = 1;
            break;
        }

        switch (op)
        {
        case 1:
        {
            /* Inserir elemento (um por vez). */
            int posicao;
            int tamanho;
            int valor;
            int capacidade;
            int caractere;

            printf("Informe a posicao da estrutura principal (1..10): ");
            if (scanf("%d", &posicao) != 1)
            {
                printf("Entrada invalida. Informe um numero inteiro.\n");
                while ((caractere = getchar()) != '\n' && caractere != EOF)
                {
                    /* limpeza da entrada */
                }
                break;
            }

            capacidade = getCapacidadeEstruturaAuxiliar(posicao);

            if (capacidade == POSICAO_INVALIDA)
            {
                printf("Posicao invalida. Utilize uma posicao entre 1 e 10.\n");
                break;
            }

            if (capacidade == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Essa posicao ainda nao possui estrutura auxiliar.\n");
                printf("Informe o tamanho da estrutura auxiliar: ");
                if (scanf("%d", &tamanho) != 1)
                {
                    printf("Entrada invalida. Informe um numero inteiro.\n");
                    while ((caractere = getchar()) != '\n' && caractere != EOF)
                    {
                        /* limpeza da entrada */
                    }
                    break;
                }

                retorno = criarEstruturaAuxiliar(posicao, tamanho);
                if (retorno != SUCESSO)
                {
                    if (retorno == TAMANHO_INVALIDO)
                        printf("Tamanho invalido. Informe um tamanho maior que zero.\n");
                    else if (retorno == SEM_ESPACO_DE_MEMORIA)
                        printf("Nao foi possivel alocar memoria para a estrutura.\n");
                    else
                        printf("Nao foi possivel criar a estrutura. Codigo: %d\n", retorno);
                    break;
                }

                printf("Estrutura auxiliar criada com sucesso.\n");
            }
            else if (capacidade > 0)
            {
                printf("Estrutura auxiliar existente. Capacidade: %d\n", capacidade);
            }

            printf("Informe o numero que deseja inserir: ");
            if (scanf("%d", &valor) != 1)
            {
                printf("Entrada invalida. Informe um numero inteiro.\n");
                while ((caractere = getchar()) != '\n' && caractere != EOF)
                {
                    /* limpeza da entrada */
                }
                break;
            }

            retorno = inserirNumeroEmEstrutura(posicao, valor);

            if (retorno == SUCESSO)
                printf("Numero inserido com sucesso.\n");
            else if (retorno == SEM_ESPACO)
                printf("Nao ha espaco disponivel nessa estrutura auxiliar.\n");
            else if (retorno == SEM_ESTRUTURA_AUXILIAR)
                printf("Nao existe estrutura auxiliar nessa posicao.\n");
            else
                printf("Nao foi possivel inserir o numero. Codigo: %d\n", retorno);

            break;
        }

        case 2:
        {
            /* Listar os numeros de todas as estruturas. */
            int posicao;
            int capacidade;
            int qtd;
            int i;

            printf("\nNumeros de todas as estruturas auxiliares:\n");

            for (posicao = 1; posicao <= 10; posicao++)
            {
                capacidade = getCapacidadeEstruturaAuxiliar(posicao);

                if (capacidade == SEM_ESTRUTURA_AUXILIAR)
                {
                    printf("Posicao %d: sem estrutura auxiliar.\n", posicao);
                }
                else if (capacidade == POSICAO_INVALIDA)
                {
                    printf("Posicao %d: invalida.\n", posicao);
                }
                else
                {
                    qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);
                    printf("Posicao %d | Tamanho: %d | Elementos: ", posicao, capacidade);

                    if (qtd == ESTRUTURA_AUXILIAR_VAZIA)
                    {
                        printf("estrutura vazia");
                    }
                    else if (qtd > 0)
                    {
                        int vetorAux[qtd];

                        retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
                        if (retorno == SUCESSO)
                        {
                            for (i = 0; i < qtd; i++)
                            {
                                printf("%d", vetorAux[i]);
                                if (i < qtd - 1)
                                    printf(", ");
                            }
                        }
                        else
                        {
                            printf("erro ao recuperar os dados");
                        }
                    }
                    else
                    {
                        printf("erro ao consultar quantidade");
                    }

                    printf("\n");
                }
            }

            break;
        }

        case 3:
        {
            /* Listar os numeros ordenados de cada estrutura auxiliar. */
            int posicao;
            int capacidade;
            int qtd;
            int i;

            printf("\nNumeros ordenados por estrutura auxiliar:\n");

            for (posicao = 1; posicao <= 10; posicao++)
            {
                capacidade = getCapacidadeEstruturaAuxiliar(posicao);

                if (capacidade == SEM_ESTRUTURA_AUXILIAR)
                {
                    printf("Posicao %d: sem estrutura auxiliar.\n", posicao);
                }
                else
                {
                    qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);
                    printf("Posicao %d | Tamanho: %d | Elementos ordenados: ", posicao, capacidade);

                    if (qtd == ESTRUTURA_AUXILIAR_VAZIA)
                    {
                        printf("estrutura vazia");
                    }
                    else if (qtd > 0)
                    {
                        int vetorAux[qtd];

                        retorno = getDadosOrdenadosEstruturaAuxiliar(posicao, vetorAux);
                        if (retorno == SUCESSO)
                        {
                            for (i = 0; i < qtd; i++)
                            {
                                printf("%d", vetorAux[i]);
                                if (i < qtd - 1)
                                    printf(", ");
                            }
                        }
                        else
                        {
                            printf("erro ao recuperar os dados ordenados");
                        }
                    }
                    else
                    {
                        printf("erro ao consultar quantidade");
                    }

                    printf("\n");
                }
            }

            break;
        }

        case 4:
        {
            /* Listar todos os numeros de forma ordenada. */
            int posicao;
            int qtd;
            int total = 0;
            int i;

            for (posicao = 1; posicao <= 10; posicao++)
            {
                qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);
                if (qtd > 0)
                    total += qtd;
            }

            if (total == 0)
            {
                printf("Nao existem numeros armazenados nas estruturas auxiliares.\n");
            }
            else
            {
                int vetorAux[total];

                retorno = getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorAux);
                if (retorno == SUCESSO)
                {
                    printf("Todos os numeros em ordem crescente: ");
                    for (i = 0; i < total; i++)
                    {
                        printf("%d", vetorAux[i]);
                        if (i < total - 1)
                            printf(", ");
                    }
                    printf("\n");
                }
                else
                {
                    printf("Nao foi possivel recuperar os numeros. Codigo: %d\n", retorno);
                }
            }

            break;
        }

        case 5:
        {
            /* Excluir a primeira ocorrencia de um numero especifico. */
            int posicao;
            int valor;
            int caractere;

            printf("Informe a posicao da estrutura principal (1..10): ");
            if (scanf("%d", &posicao) != 1)
            {
                printf("Entrada invalida. Informe um numero inteiro.\n");
                while ((caractere = getchar()) != '\n' && caractere != EOF)
                {
                    /* limpeza da entrada */
                }
                break;
            }

            printf("Informe o numero que deseja excluir: ");
            if (scanf("%d", &valor) != 1)
            {
                printf("Entrada invalida. Informe um numero inteiro.\n");
                while ((caractere = getchar()) != '\n' && caractere != EOF)
                {
                    /* limpeza da entrada */
                }
                break;
            }

            retorno = excluirNumeroEspecificoDeEstrutura(posicao, valor);

            if (retorno == SUCESSO)
                printf("Primeira ocorrencia do numero excluida com sucesso.\n");
            else if (retorno == POSICAO_INVALIDA)
                printf("Posicao invalida. Utilize uma posicao entre 1 e 10.\n");
            else if (retorno == SEM_ESTRUTURA_AUXILIAR)
                printf("Nao existe estrutura auxiliar nessa posicao.\n");
            else if (retorno == ESTRUTURA_AUXILIAR_VAZIA)
                printf("A estrutura auxiliar esta vazia.\n");
            else if (retorno == NUMERO_INEXISTENTE)
                printf("O numero informado nao foi encontrado.\n");
            else
                printf("Nao foi possivel excluir o numero. Codigo: %d\n", retorno);

            break;
        }

        case 6:
        {
            /* Aumentar o tamanho de uma estrutura auxiliar existente. */
            int posicao;
            int tamanhoExtra;
            int novaCapacidade;
            int caractere;

            printf("Informe a posicao da estrutura auxiliar (1..10): ");
            if (scanf("%d", &posicao) != 1)
            {
                printf("Entrada invalida. Informe um numero inteiro.\n");
                while ((caractere = getchar()) != '\n' && caractere != EOF)
                {
                    /* limpeza da entrada */
                }
                break;
            }

            printf("Informe quantas posicoes extras deseja adicionar: ");
            if (scanf("%d", &tamanhoExtra) != 1)
            {
                printf("Entrada invalida. Informe um numero inteiro.\n");
                while ((caractere = getchar()) != '\n' && caractere != EOF)
                {
                    /* limpeza da entrada */
                }
                break;
            }

            if (tamanhoExtra <= 0)
            {
                printf("A quantidade de posicoes extras deve ser maior que zero.\n");
                break;
            }

            retorno = modificarTamanhoEstruturaAuxiliar(posicao, tamanhoExtra);

            if (retorno == SUCESSO)
            {
                novaCapacidade = getCapacidadeEstruturaAuxiliar(posicao);
                printf("Estrutura auxiliar aumentada com sucesso.\n");
                printf("Nova capacidade: %d\n", novaCapacidade);
            }
            else if (retorno == POSICAO_INVALIDA)
                printf("Posicao invalida. Utilize uma posicao entre 1 e 10.\n");
            else if (retorno == SEM_ESTRUTURA_AUXILIAR)
                printf("Nao existe estrutura auxiliar nessa posicao.\n");
            else if (retorno == SEM_ESPACO_DE_MEMORIA)
                printf("Nao foi possivel alocar memoria para aumentar a estrutura.\n");
            else
                printf("Nao foi possivel aumentar a estrutura. Codigo: %d\n", retorno);

            break;
        }

        case 7:
        {
            sair = 1;
            finalizar();
            printf("Programa encerrado.\n");
            break;
        }

        default:
        {
            printf("Opcao invalida. Escolha uma opcao de 1 a 7.\n");
            break;
        }
        }
    }

    if (op != 7)
        finalizar();

    return 0;
}
