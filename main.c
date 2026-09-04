#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int matricula;
    char nome[50];
    char sexo;
    int dia;
    int mes;
    int ano;
    int cpf;

} cadastroAlunos; 

int main(){
    cadastroAlunos listaAlunos[3];

    int sair = 0;
    int qtdAlunos = 0;

    while(!sair){

        printf("\nDigite a opcao: \n");
        printf("0 - Sair \n");
        printf("1 - Inserir \n");
        printf("2 - Listar \n");
        printf("3 - Atualizar \n");
        printf("4 - Deletar \n\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao){
            case 0 : {
                sair = 1;
                break;
            }
            case 1:{
                printf("Digite a matricula: \n");
                scanf("%d",&listaAlunos[qtdAlunos].matricula);
                printf("Digite o nome: \n");
                scanf("%s", listaAlunos[qtdAlunos].nome);
                printf("Digite o sexo (F/M): \n");
                scanf(" %c", &listaAlunos[qtdAlunos].sexo);
                printf("Digite a data de nascimento DD/MM/AAAA: \n");
                scanf("%d/%d/%d", &listaAlunos[qtdAlunos].dia, &listaAlunos[qtdAlunos].mes, &listaAlunos[qtdAlunos].ano);
                printf("Digite o CPF (somente numeros): \n");
                scanf("%d", &listaAlunos[qtdAlunos].cpf);
                qtdAlunos++;
                break;
            }
            case 2: {
                printf("\nLista de alunos: \n");
                for (int i = 0; i < qtdAlunos; i++){
                    printf("\nMatricula: %d\n", listaAlunos[i].matricula);
                    printf("Nome: %s\n", listaAlunos[i].nome);
                    printf("Sexo: %c\n", listaAlunos[i].sexo);
                    printf("Data de nascimento: %d/%d/%d\n", listaAlunos[i].dia, listaAlunos[i].mes, listaAlunos[i].ano);
                    printf("CPF: %d\n", listaAlunos[i].cpf);
                    }
                    break;
            }
                case 3: {
                    printf("Atualizar aluno: \n");
                    break;
            }
                case 4: {
                    printf("Deletar aluno: \n");
                    break;
            }
                default: printf("Opcao invalida! \n");
            }    
            
        }
        return 0;
    }  