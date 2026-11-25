#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

struct EstruturaAuxiliar {
    int *numeros;
    int capacidade;
    int quantidade;
};


struct EstruturaAuxiliar *vetorPrincipal[TAM] = {NULL};

//Prototipos de funcoes auxiliares internas
static void ordenarVetor(int vetor[], int quantidade);
static int totalElementos(void);
static void liberarTudo(void);
static int tamanhoAlocavel(int capacidade);


int ehPosicaoValida(int posicao)
{
    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    return SUCESSO;
}


static void ordenarVetor(int vetor[], int quantidade)
{
    int i;
    int j;
    int temporario;

    for (i = 0; i < quantidade - 1; i++) {
        for (j = 0; j < quantidade - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temporario = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temporario;
            }
        }
    }
}


static int totalElementos(void)
{
    int i;
    int total = 0;

    for (i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL)
            total += vetorPrincipal[i]->quantidade;
    }

    return total;
}


static int tamanhoAlocavel(int capacidade)
{
    size_t maiorQuantidade;

    if (capacidade < 1)
        return 0;

    
    maiorQuantidade = (size_t)-1 / sizeof(int);

    if ((size_t) capacidade > maiorQuantidade)
        return 0;

    return 1;
}


static void liberarTudo(void)
{
    int i;

    for (i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL) {
            free(vetorPrincipal[i]->numeros);
            vetorPrincipal[i]->numeros = NULL;

            free(vetorPrincipal[i]);
            vetorPrincipal[i] = NULL;
        }
    }
}


void dobrar(int *x)
{
    unsigned int maiorValorSemSinal;
    int maiorValorInt;
    int limite;

    if (x == NULL)
        return;

    
    maiorValorSemSinal = (unsigned int)-1;
    maiorValorInt = (int)(maiorValorSemSinal / 2);
    limite = maiorValorInt / 2;

   
    if (*x > limite || *x < -limite)
        return;

    *x = (*x) * 2;
}

/*
Objetivo: criar estrutura auxiliar na posicao 'posicao',
com tamanho 'tamanho'.

Retorno (int):
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - ja tem estrutura na posicao
    POSICAO_INVALIDA - posicao invalida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - sem espaco de memoria
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int indice;
    struct EstruturaAuxiliar *novaEstrutura;

    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    if (tamanho < 1 || !tamanhoAlocavel(tamanho))
        return TAMANHO_INVALIDO;

    indice = posicao - 1;

    if (vetorPrincipal[indice] != NULL)
        return JA_TEM_ESTRUTURA_AUXILIAR;

    novaEstrutura = (struct EstruturaAuxiliar *) malloc(sizeof(struct EstruturaAuxiliar));
    if (novaEstrutura == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    novaEstrutura->numeros = (int *) malloc((size_t) tamanho * sizeof(int));
    if (novaEstrutura->numeros == NULL) {
        free(novaEstrutura);
        return SEM_ESPACO_DE_MEMORIA;
    }

    novaEstrutura->capacidade = tamanho;
    novaEstrutura->quantidade = 0;

    vetorPrincipal[indice] = novaEstrutura;

    return SUCESSO;
}

/*
Objetivo: inserir numero 'valor' em estrutura auxiliar da posicao 'posicao'.

Retorno (int):
    SUCESSO - inserido com sucesso
    SEM_ESPACO - nao tem espaco
    SEM_ESTRUTURA_AUXILIAR - nao tem estrutura auxiliar
    POSICAO_INVALIDA - posicao invalida para estrutura auxiliar
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int indice;
    struct EstruturaAuxiliar *estrutura;

    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    indice = posicao - 1;
    estrutura = vetorPrincipal[indice];

    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (estrutura->quantidade >= estrutura->capacidade)
        return SEM_ESPACO;

    estrutura->numeros[estrutura->quantidade] = valor;
    estrutura->quantidade++;

    return SUCESSO;
}

/*
Objetivo: excluir o ultimo numero da estrutura auxiliar da posicao 'posicao'.
Esta e uma exclusao logica: a capacidade da estrutura nao diminui.

Retorno (int):
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - nao tem estrutura auxiliar
    POSICAO_INVALIDA - posicao invalida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int indice;
    struct EstruturaAuxiliar *estrutura;

    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    indice = posicao - 1;
    estrutura = vetorPrincipal[indice];

    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (estrutura->quantidade == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    estrutura->quantidade--;

    return SUCESSO;
}

/*
Objetivo: excluir a primeira ocorrencia do numero 'valor' da estrutura auxiliar
na posicao 'posicao'. Os numeros posteriores sao movidos para as posicoes
anteriores. Esta e uma exclusao logica: a capacidade nao diminui.

Retorno (int):
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - nao tem estrutura auxiliar
    NUMERO_INEXISTENTE - numero nao existe
    POSICAO_INVALIDA - posicao invalida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int indice;
    int i;
    int j;
    struct EstruturaAuxiliar *estrutura;

    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    indice = posicao - 1;
    estrutura = vetorPrincipal[indice];

    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (estrutura->quantidade == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    for (i = 0; i < estrutura->quantidade; i++) {
        if (estrutura->numeros[i] == valor) {
            for (j = i; j < estrutura->quantidade - 1; j++)
                estrutura->numeros[j] = estrutura->numeros[j + 1];

            estrutura->quantidade--;
            return SUCESSO;
        }
    }

    return NUMERO_INEXISTENTE;
}

/*
Objetivo: retornar os numeros da estrutura auxiliar da posicao 'posicao'.
Os numeros devem ser armazenados em vetorAux.

Retorno (int):
    SUCESSO - recuperado com sucesso
    SEM_ESTRUTURA_AUXILIAR - nao tem estrutura auxiliar
    POSICAO_INVALIDA - posicao invalida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int indice;
    int i;
    struct EstruturaAuxiliar *estrutura;

    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    indice = posicao - 1;
    estrutura = vetorPrincipal[indice];

    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorAux == NULL && estrutura->quantidade > 0)
        return SEM_ESPACO_DE_MEMORIA;

    for (i = 0; i < estrutura->quantidade; i++)
        vetorAux[i] = estrutura->numeros[i];

    return SUCESSO;
}

/*
Objetivo: retornar os numeros ordenados da estrutura auxiliar da posicao
'posicao'. Os numeros devem ser armazenados em vetorAux, sem alterar a
ordem original dos elementos na estrutura auxiliar.
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno;
    int indice;

    retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
    if (retorno != SUCESSO)
        return retorno;

    indice = posicao - 1;
    ordenarVetor(vetorAux, vetorPrincipal[indice]->quantidade);

    return SUCESSO;
}

/*
Objetivo: retornar os numeros de todas as estruturas auxiliares.
Os numeros devem ser armazenados em vetorAux.
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int i;
    int j;
    int indiceVetor = 0;
    int total = totalElementos();

    if (total == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    if (vetorAux == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    for (i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL) {
            for (j = 0; j < vetorPrincipal[i]->quantidade; j++)
                vetorAux[indiceVetor++] = vetorPrincipal[i]->numeros[j];
        }
    }

    return SUCESSO;
}

/*
Objetivo: retornar os numeros ordenados de todas as estruturas auxiliares.
Os numeros devem ser armazenados em vetorAux, sem alterar os vetores originais.
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int total = totalElementos();
    int retorno;

    if (total == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    if (retorno != SUCESSO)
        return retorno;

    ordenarVetor(vetorAux, total);

    return SUCESSO;
}

/*
Objetivo: modificar a capacidade da estrutura auxiliar da posicao 'posicao'
para capacidade atual + 'novoTamanho'. A capacidade final deve ser >= 1.
Elementos que nao couberem apos uma diminuicao sao descartados.
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int indice;
    int novaCapacidade;
    int maiorValorInt;
    unsigned int maiorValorSemSinal;
    int *novosNumeros;
    struct EstruturaAuxiliar *estrutura;

    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    indice = posicao - 1;
    estrutura = vetorPrincipal[indice];

    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    /*
     * Calcula manualmente o maior valor positivo de int, sem limits.h.
     * O tipo unsigned nao possui sinal; seu maior valor dividido por 2
     * corresponde ao limite positivo do int correspondente.
     */
    maiorValorSemSinal = (unsigned int)-1;
    maiorValorInt = (int)(maiorValorSemSinal / 2);

    /* Evita que a soma ultrapasse o maior valor que int pode armazenar. */
    if (novoTamanho > 0 && novoTamanho > maiorValorInt - estrutura->capacidade)
        return NOVO_TAMANHO_INVALIDO;

    novaCapacidade = estrutura->capacidade + novoTamanho;

    if (novaCapacidade < 1)
        return NOVO_TAMANHO_INVALIDO;

    if (!tamanhoAlocavel(novaCapacidade))
        return NOVO_TAMANHO_INVALIDO;

    novosNumeros = (int *) realloc(estrutura->numeros,
                                   (size_t) novaCapacidade * sizeof(int));
    if (novosNumeros == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    estrutura->numeros = novosNumeros;
    estrutura->capacidade = novaCapacidade;

    if (estrutura->quantidade > novaCapacidade)
        estrutura->quantidade = novaCapacidade;

    return SUCESSO;
}

/*
Objetivo: retornar a quantidade de elementos preenchidos da estrutura auxiliar.

Retorno (int):
    POSICAO_INVALIDA - posicao invalida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um numero int > 0 correspondente a quantidade de elementos preenchidos
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int indice;

    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    indice = posicao - 1;

    if (vetorPrincipal[indice] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[indice]->quantidade == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return vetorPrincipal[indice]->quantidade;
}

/* Retorna a capacidade da estrutura auxiliar ou um codigo de erro. */
int getCapacidadeEstruturaAuxiliar(int posicao)
{
    int indice;

    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    indice = posicao - 1;

    if (vetorPrincipal[indice] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    return vetorPrincipal[indice]->capacidade;
}

/*
Objetivo: montar uma lista encadeada com cabecote contendo todos os numeros
presentes em todas as estruturas auxiliares.

Retorno (No*):
    NULL, caso nao tenha nenhum numero ou ocorra falha de alocacao
    No*, ponteiro para o inicio da lista com cabecote
*/
No *montarListaEncadeadaComCabecote(void)
{
    int i;
    int j;
    No *cabecote;
    No *ultimo;

    if (totalElementos() == 0)
        return NULL;

    cabecote = (No *) malloc(sizeof(No));
    if (cabecote == NULL)
        return NULL;

    cabecote->conteudo = 0;
    cabecote->prox = NULL;
    ultimo = cabecote;

    for (i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] == NULL)
            continue;

        for (j = 0; j < vetorPrincipal[i]->quantidade; j++) {
            No *novoNo = (No *) malloc(sizeof(No));

            if (novoNo == NULL) {
                destruirListaEncadeadaComCabecote(&cabecote);
                return NULL;
            }

            novoNo->conteudo = vetorPrincipal[i]->numeros[j];
            novoNo->prox = NULL;
            ultimo->prox = novoNo;
            ultimo = novoNo;
        }
    }

    return cabecote;
}

/* Copia para vetorAux os valores dos nos, ignorando o cabecote. */
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    int i = 0;
    No *atual;

    if (inicio == NULL || vetorAux == NULL)
        return;

    atual = inicio->prox;
    while (atual != NULL) {
        vetorAux[i] = atual->conteudo;
        i++;
        atual = atual->prox;
    }
}

/* Destroi a lista encadeada e deixa o ponteiro recebido como NULL. */
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *atual;
    No *proximo;

    if (inicio == NULL || *inicio == NULL)
        return;

    atual = *inicio;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *inicio = NULL;
}

/*
Objetivo: inicializar o programa.
Prepara o vetor principal deixando todas as posicoes sem estrutura auxiliar.
Nao utiliza arquivos; os dados existem somente durante a execucao do programa.
*/
void inicializar(void)
{
    /*
     * Libera qualquer estrutura que ja esteja alocada.
     * Na primeira chamada, as posicoes ja comecam como NULL por inicializacao
     * global; esta chamada tambem permite reinicializar o programa com seguranca.
     */
    liberarTudo();
}

/*
Objetivo: finalizar o programa.
Libera toda a memoria dinamica utilizada pelas estruturas auxiliares.
Os dados nao sao preservados depois que o programa e encerrado.
*/
void finalizar(void)
{
    liberarTudo();
}