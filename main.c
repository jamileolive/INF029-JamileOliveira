#include<stdio.h>
#include<stdlib.h>
#define TamanhoAlunos 3

typedef struct {
    int matricula;
    char nome[50];
    char sexo;
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    int cpf;

} cadastroAlunos;  

	//	protótipo das funções
    int cadastroGeral();
    int menuAlunos();
    void cadastrarAlunos (cadastroAlunos listaAlunos[], int qtdAlunos);

int main(){
    	
    cadastroAlunos listaAlunos[TamanhoAlunos]; 
    int opcaoAluno;
    int sairAluno = 0;
	int qtdAlunos = 0;
		 
    int opcao;
    int sair = 0;

        while (!sair){
            
        opcao = cadastroGeral();
        
        switch (opcao){

            case 0 :{
                sair = 1;
                break;
            }
              case 1 :{
              	   			
                while (!sairAluno){
                opcaoAluno = menuAlunos();	
                
				switch (opcaoAluno)	{
					
				case 0 :{
                sairAluno = 1;
                break;
            	}
				case 1 :{
				cadastrarAlunos (listaAlunos, qtdAlunos);
                qtdAlunos++;
        		break;
            	}
					
			}	
		}
				
                break;
            }
            case 2 :{
                printf("\nProfessores\n");
                break;
            }
            case 3 :{
                printf("\nDisciplinas\n");
                break;
            }
                default: printf("\nOpcao invalida! \n");
            } 


         }

         return 0;
 }
 
 int cadastroGeral(){
 	
 		int opcao;
 		
 		printf("\n Cadastro Escolar \n");
        printf("Digite a opcao: \n");
        printf("0 - Sair \n");
        printf("1 - Alunos \n");
        printf("2 - Professores \n");
        printf("3 - Disciplinas \n");
        
        scanf("%d", &opcao);
        
        return opcao;
 }
 
 int menuAlunos(){
 	
 	int opcaoAluno;
 	
 		printf("\nDigite a opcao: \n");
        printf("0 - Voltar ao menu principal \n");
        printf("1 - Inserir aluno \n");
        printf("2 - Listar alunos \n");
        printf("3 - Atualizar aluno \n");
        printf("4 - Deletar aluno \n\n");

        scanf("%d", &opcaoAluno);
        
        return opcaoAluno;
 }
 
 void cadastrarAlunos (cadastroAlunos listaAlunos[], int qtdAlunos){
 	
	  	printf("Digite a matricula: \n");
	    scanf("%d",&listaAlunos[qtdAlunos].matricula);
	    getchar();
	    
        printf("Digite o nome: \n");
        fgets(listaAlunos[qtdAlunos].nome, 50, stdin);
        int tam = 0;
        while (listaAlunos[qtdAlunos].nome[tam] != '\0'){
        	tam++;
		} if (tam > 0 && listaAlunos[qtdAlunos].nome[tam - 1] == '\n'){
			listaAlunos[qtdAlunos].nome[tam - 1] = '\0';
		}
		
        printf("Digite o sexo (F/M): \n");
        scanf(" %c", &listaAlunos[qtdAlunos].sexo);
        
        printf("Digite a data de nascimento DD/MM/AAAA: \n");
        scanf("%d/%d/%d",	&listaAlunos[qtdAlunos].diaNascimento, 
							&listaAlunos[qtdAlunos].mesNascimento, 
							&listaAlunos[qtdAlunos].anoNascimento);
        
        printf("Digite o CPF (somente numeros): \n");
        scanf("%d", &listaAlunos[qtdAlunos].cpf);
       

  }