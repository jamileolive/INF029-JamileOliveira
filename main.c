#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TamanhoAlunos 3

#define CADASTRO_SUCESSO -1
#define NAO_LOCALIZADO -2
#define LOCAL_SUCESSO -3
#define EXCLUIDO_SUCESSO -4

typedef struct {
    int matricula;
    char nome[50];
    char sexo;
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    char cpf[12];

} cadastroAlunos;  

	//	protótipo das funções
    int cadastroGeral();
    int menuAlunos();
    int cadastrarAlunos (cadastroAlunos listaAlunos[], int qtdAlunos);
	void listarAluno (cadastroAlunos listaAlunos[], int qtdAlunos);
	int atualizarAluno (cadastroAlunos listaAlunos[], int qtdAlunos);
    int excluirAluno(cadastroAlunos listaAlunos[], int qtdAlunos);
	
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
				int cadastro = cadastrarAlunos (listaAlunos, qtdAlunos);
                if(cadastro == CADASTRO_SUCESSO){
                qtdAlunos++;
                printf("\nAluno cadastrado com sucesso!\n");
                }

        		break;
            	}

            	case 2 :{
				listarAluno (listaAlunos, qtdAlunos);
        		break;
            	}

				case 3:{
					
				int localizado = atualizarAluno (listaAlunos, qtdAlunos);
				
				if (localizado == NAO_LOCALIZADO) {
					printf("\nAluno não econtrado!\n");
				} else if(localizado == LOCAL_SUCESSO) {
					printf("Aluno atualizado com sucesso!\n ");
				}
				    
				break;
				}

				case 4:{
				 
                 int excluido = excluirAluno(listaAlunos, qtdAlunos);

                  if (excluido == EXCLUIDO_SUCESSO) {
                    printf("Aluno excluido com sucesso!\n");
                    qtdAlunos--;
                  } 

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
 
 int cadastrarAlunos (cadastroAlunos listaAlunos[], int qtdAlunos){
 	
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
        scanf("%s", listaAlunos[qtdAlunos].cpf);
       
            return CADASTRO_SUCESSO;
  }
  
  void listarAluno(cadastroAlunos listaAlunos[], int qtdAlunos){
  	printf("\nLista de alunos: \n");
    for (int i = 0; i < qtdAlunos; i++){
    printf("\nMatricula: %d\n", listaAlunos[i].matricula);
    printf("Nome: %s\n", listaAlunos[i].nome);
    printf("Sexo: %c\n", listaAlunos[i].sexo);
    printf("Data de nascimento: %d/%d/%d\n", listaAlunos[i].diaNascimento, 
											 listaAlunos[i].mesNascimento, 
											 listaAlunos[i].anoNascimento);
    printf("CPF: %s\n", listaAlunos[i].cpf);
    }
    
  }
  
  int atualizarAluno (cadastroAlunos listaAlunos[], int qtdAlunos){
  		printf("\nAtualizar aluno\n");
				
				listarAluno(listaAlunos, qtdAlunos);
				
				    int matricula;
				    
				    printf("\nDigite a matricula do aluno: ");
				    scanf("%d", &matricula);
				    
				    int localizado = 0;
				    
				    for(int i = 0; i < qtdAlunos; i++){
				    	
				    	if (matricula == listaAlunos[i].matricula){
				    			printf("Digite a matricula: \n");
				    scanf("%d",&listaAlunos[i].matricula);
				    getchar();
				    
			        printf("Digite o nome: ");
			        fgets(listaAlunos[i].nome, 50, stdin);
			        int tam = 0;
			        while (listaAlunos[i].nome[tam] != '\0'){
			        	tam++;
					} if (tam > 0 && listaAlunos[i].nome[tam - 1] == '\n'){
						listaAlunos[i].nome[tam - 1] = '\0';
					}
					
			        printf("Digite o sexo (F/M): ");
			        scanf(" %c", &listaAlunos[i].sexo);
			        
			        printf("Digite a data de nascimento DD/MM/AAAA: ");
			        scanf("%d/%d/%d",	&listaAlunos[i].diaNascimento, 
										&listaAlunos[i].mesNascimento, 
										&listaAlunos[i].anoNascimento);
			        
			        printf("Digite o CPF (somente numeros): ");
			        scanf("%s", listaAlunos[i].cpf);
			        
			        localizado = 1;
			    	break;
						}						
					}
					if (!localizado){
						return NAO_LOCALIZADO;
					} else {
						return LOCAL_SUCESSO;
					}
  }
  int excluirAluno(cadastroAlunos listaAlunos[], int qtdAlunos){

    printf("\nExcluir aluno\n");

    int matricula;
    int localizado = 0;

    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);

    for (int i = 0; i < qtdAlunos; i++){

        if (matricula == listaAlunos[i].matricula){
            for (int j = i; j < qtdAlunos - 1; j++){
                listaAlunos[j].matricula = listaAlunos[j + 1].matricula;
                strcpy(listaAlunos[j].nome, listaAlunos[j + 1].nome);
                listaAlunos[j].sexo = listaAlunos[j + 1].sexo;
                listaAlunos[j].diaNascimento = listaAlunos[j + 1].diaNascimento;
                listaAlunos[j].mesNascimento = listaAlunos[j + 1].mesNascimento;
                listaAlunos[j].anoNascimento = listaAlunos[j + 1].anoNascimento;
                strcpy(listaAlunos[j].cpf, listaAlunos[j + 1].cpf);
            }
            localizado = 1;
            break;
        }
    }
    if (localizado){
        return EXCLUIDO_SUCESSO;
    } else {
        return NAO_LOCALIZADO;
    }
}