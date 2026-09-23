#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TamAlunos 3
#define TamProfessores 3
#define TamDisciplinas 3
#define qtdMatriculadosDisciplina 3

#define CADASTRO_SUCESSO -1
#define NAO_LOCALIZADO -2
#define LOCAL_SUCESSO -3
#define EXCLUIDO_SUCESSO -4

typedef struct{
    int dia;
    int mes;
    int ano;

} Data;

typedef struct {
    int matricula;
    char nome[50];
    char sexo;
    Data dataDeNascimento;
    char cpf[12];

} cadastroAlunos;  

typedef struct {
    int id;
    char nome[50];
    char sexo;
    Data dataDeNascimentoProf;
    char cpf[12];
} cadastroProfessores; 

typedef struct {
    int id;
    char nome[50];
    int semestre;
    char professor[50];
    int qtdAlunosMatriculados;

} cadastroDisciplinas; 

	//	protótipo das funções
    int cadastroGeral();

    int menuAlunos();
    int cadastrarAlunos (cadastroAlunos listaAlunos[], int qtdAlunos);
	void listarAluno (cadastroAlunos listaAlunos[], int qtdAlunos);
	int atualizarAluno (cadastroAlunos listaAlunos[], int qtdAlunos);
    int excluirAluno(cadastroAlunos listaAlunos[], int qtdAlunos);
    
    int menuProfessores();
    int cadastrarProfessores (cadastroProfessores listaProfessores[], int qtdProfessores);
	void listarProfessores(cadastroProfessores listaProfessores[], int qtdProfessores);
    int atualizarProfessor(cadastroProfessores listaProfessores[], int qtdProfessores);
    int excluirProfessor(cadastroProfessores listaProfessores[], int qtdProfessores);

    int menuDisciplinas();
    int cadastrarDisciplinas(cadastroDisciplinas listaDisciplinas[], int qtdDisciplinas);
    void listarDisciplinas(cadastroDisciplinas listaDisciplinas[], int qtdDisciplinas);
    int atualizarDisciplina(cadastroDisciplinas listaDisciplinas[], int qtdDisciplinas);
    int excluirDisciplina(cadastroDisciplinas listaDisciplinas[], int qtdDisciplinas);

    int menuRelatorios();
    void listaAlunosOrdemNome (cadastroAlunos listaAlunos[], int qtdAlunos);
    void listaAlunoPorSexo (cadastroAlunos listaAlunos[], int qtdAlunos);
    void listaAlunoOrdemDataNascimento (cadastroAlunos listaAlunos[], int qtdAlunos);
    void listaProfessorOrdemNome (cadastroProfessores listaProfessores[], int qtdProfessores);
    void listaProfPorSexo (cadastroProfessores listaProfessores[], int qtdProfessores);
    void listaProfOrdemDataNascimento (cadastroProfessores listaProfessores[], int qtdProfessores);

int main(){

    int opcao;
    int sair = 0;

    cadastroAlunos listaAlunos[TamAlunos]; 
    int opcaoAluno;
    int sairAluno = 0;
	int qtdAlunos = 0;

    cadastroProfessores listaProfessores[TamProfessores];
    int opcaoProfessor;
    int sairProfessor = 0;
    int qtdProfessores = 0;

    cadastroDisciplinas listaDisciplinas[TamDisciplinas];
    int opcaoDisciplina;
    int sairDisciplina = 0;
    int qtdDisciplinas = 0;


    int opcaoRelatorio;
    int sairRelatorio = 0;
    

        while (!sair){
            
        opcao = cadastroGeral();
        
        switch (opcao){

            case 0 :{
                sair = 1;
                break;
            }
              case 1 :{
              	 printf("\nAlunos\n"); 

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
					printf("\nAluno nao encontrado!\n");
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
                  } else if (excluido == NAO_LOCALIZADO) {
                    printf("\nAluno nao existente!\n");

                  }

                  break;
                  }
                  default: {
                    printf("\nOpcao invalida!\n");
                  }
			
				}          	
					
			}

            break;	
		}
                
            case 2 :{
                printf("\nProfessores\n");

                while (!sairProfessor){
                    opcaoProfessor = menuProfessores();

                    switch (opcaoProfessor) {

                        case 0: {
                            sairProfessor = 1;
                            break;
                        }
                        case 1: {
                            int cadastro = cadastrarProfessores (listaProfessores, qtdProfessores);
                            if(cadastro == CADASTRO_SUCESSO){
                                qtdProfessores++;
                                printf("\nProfessor cadastrado com sucesso!\n");
                            }
                            break;
                        }
                        case 2: {
                            listarProfessores(listaProfessores, qtdProfessores);
                            break;
                        }
                        case 3:{
                            int atualizacao = atualizarProfessor(listaProfessores, qtdProfessores);
                            if (atualizacao == NAO_LOCALIZADO) {
                                printf("\nProfessor nao encontrado!\n");
                            } else if (atualizacao == LOCAL_SUCESSO) {
                                printf("\nProfessor atualizado com sucesso!\n");
                            }
                            break;
                        }
                        case 4: {

                            int excluido = excluirProfessor(listaProfessores, qtdProfessores);

                            if (excluido == EXCLUIDO_SUCESSO) {
                                printf("\nProfessor excluido com sucesso!\n");
                                qtdProfessores--;
                            } else if (excluido == NAO_LOCALIZADO) {
                                printf("\nProfessor nao existente!\n");
                            }
                            break;
                        }
                        default: {
                            printf("\nOpcao invalida!\n");
                        }
                    }
                }
                break;
            }
            case 3 :{
                printf("\nDisciplinas\n");
                while (!sairDisciplina){
                    opcaoDisciplina = menuDisciplinas();

                    switch (opcaoDisciplina){

                        case 0: {
                            sairDisciplina = 1;
                            break;
                        }
                        case 1: {
                        int cadastro = cadastrarDisciplinas(listaDisciplinas, qtdDisciplinas);
                        if(cadastro == CADASTRO_SUCESSO){
                            qtdDisciplinas++;
                            printf("\nDisciplina cadastrada com sucesso!\n");
                        }
                        break;
                        }
                        case 2: {
                        listarDisciplinas(listaDisciplinas, qtdDisciplinas);
                        break;
                        }
                        case 3: {
                        int atualizacao = atualizarDisciplina(listaDisciplinas, qtdDisciplinas);
                        if (atualizacao == LOCAL_SUCESSO) {
                            printf("\nDisciplina atualizada com sucesso!\n");
                        } else if (atualizacao == NAO_LOCALIZADO) {
                            printf("\nDisciplina nao encontrada!\n");   
                        }
                        break;
                    }
                        case 4: {
                        int exclusao = excluirDisciplina(listaDisciplinas, qtdDisciplinas);
                        if (exclusao == EXCLUIDO_SUCESSO) {
                            printf("\nDisciplina excluida com sucesso!\n");
                            qtdDisciplinas--;
                        } else if (exclusao == NAO_LOCALIZADO) {
                            printf("\nDisciplina nao encontrada!\n");
                        }
                        break;
                        }
                        default: {
                            printf("\nOpcao invalida!\n");
                        }
                    }
                }
                break;
            }
            case 4 :{
                printf("\nRelatorios\n");
                while (!sairRelatorio){
                    opcaoRelatorio = menuRelatorios();

                    switch (opcaoRelatorio){
                        case 0: {
                            sairRelatorio = 1;
                            break;
                        }
                        case 1: {
                        listaAlunosOrdemNome (listaAlunos, qtdAlunos);
                        break;
                        }
                        case 2:{
                        //lista de aluno ordenado por parte do nome.
                        break;
                        }
                        case 3:{
                        listaAlunoPorSexo (listaAlunos, qtdAlunos);
                        break;
                        }
                        case 4:{
                        listaAlunoOrdemDataNascimento (listaAlunos, qtdAlunos);
                        break;
                        }
                        case 5:{
                        listaProfessorOrdemNome (listaProfessores, qtdProfessores);
                        break;
                        }
                        case 6:{
                        //lista de professor ordenado por parte do nome.
                        break;
                        }
                        case 7:{
                        listaProfPorSexo (listaProfessores, qtdProfessores);
                        break;
                        }
                        case 8:{
                        listaProfOrdemDataNascimento (listaProfessores, qtdProfessores);
                        break;
                        }
                        case 9:{
                        // Lista de disciplinas com alunos matriculados.
                        break;
                        }
                        case 10:{
                        //Lista de alunos matriculados em pelo menos 3 disciplinas.
                        break;
                        }
                        case 11:{
                        //Lista de disciplinas que extrapolam 40 vagas.
                        break;
                        }
                        case 12:{
                        //Aniversariante do mês.
                        break;
                        }
                        default: {
                            printf("\nOpcao invalida!\n");
                        }
                    }
                }
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
        printf("4 - Relatorios \n");
        
        scanf("%d", &opcao);
        
        return opcao;
 }
 
 int menuAlunos(){
 	
 	int opcaoAluno;
 	
 		printf("\nDigite a opcao: \n");
        printf("0 - Voltar ao menu principal \n");
        printf("1 - Cadastrar aluno \n");
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
        scanf("%d/%d/%d",	&listaAlunos[qtdAlunos].dataDeNascimento.dia, 
							&listaAlunos[qtdAlunos].dataDeNascimento.mes, 
							&listaAlunos[qtdAlunos].dataDeNascimento.ano);
        
        printf("Digite o CPF (somente numeros): \n");
        scanf("%s", listaAlunos[qtdAlunos].cpf);
         while (listaAlunos[qtdAlunos].cpf[tam] != '\0'){
        	tam++;
		} if (tam > 0 && listaAlunos[qtdAlunos].cpf[tam - 1] == '\n'){
			listaAlunos[qtdAlunos].cpf[tam - 1] = '\0';
		}
       
            return CADASTRO_SUCESSO;
  }
  
  void listarAluno(cadastroAlunos listaAlunos[], int qtdAlunos){
  	printf("\nLista de alunos: \n");
    for (int i = 0; i < qtdAlunos; i++){
    printf("\nMatricula: %d\n", listaAlunos[i].matricula);
    printf("Nome: %s\n", listaAlunos[i].nome);
    printf("Sexo: %c\n", listaAlunos[i].sexo);
    printf("Data de nascimento: %d/%d/%d\n", listaAlunos[i].dataDeNascimento.dia, 
											 listaAlunos[i].dataDeNascimento.mes, 
											 listaAlunos[i].dataDeNascimento.ano);
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
			        scanf("%d/%d/%d",	&listaAlunos[i].dataDeNascimento.dia, 
										&listaAlunos[i].dataDeNascimento.mes, 
										&listaAlunos[i].dataDeNascimento.ano);
			        
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
                listaAlunos[j].dataDeNascimento.dia = listaAlunos[j + 1].dataDeNascimento.dia;
                listaAlunos[j].dataDeNascimento.mes = listaAlunos[j + 1].dataDeNascimento.mes;
                listaAlunos[j].dataDeNascimento.ano = listaAlunos[j + 1].dataDeNascimento.ano;
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

 int menuProfessores(){
 	
 	int opcaoProfessor;
 	
 		printf("\nDigite a opcao: \n");
        printf("0 - Voltar ao menu principal\n");
        printf("1 - Cadastrar professor\n");
        printf("2 - Listar professores\n");
        printf("3 - Atualizar professor\n");
        printf("4 - Deletar professor\n\n");

        scanf("%d", &opcaoProfessor);
        
        return opcaoProfessor;
 }

 int cadastrarProfessores (cadastroProfessores listaProfessores[], int qtdProfessores){

    printf("Digite o ID do professor: \n");
    scanf("%d", &listaProfessores[qtdProfessores].id);
    getchar();

    printf("Digite o nome: \n");
    fgets(listaProfessores[qtdProfessores].nome, 50, stdin);
    int tam = 0;
    while (listaProfessores[qtdProfessores].nome[tam] != '\0'){
        tam++;
    } if (tam > 0 && listaProfessores[qtdProfessores].nome[tam-1] == '\n'){
        listaProfessores[qtdProfessores].nome[tam-1] = '\0';
    }

    printf("Digite o sexo (F/M): \n");
    scanf(" %c", &listaProfessores[qtdProfessores].sexo);
    getchar();

    printf("Digite a data de nascimento DD/MM/AAAA: \n");
    scanf("%d/%d/%d", &listaProfessores[qtdProfessores].dataDeNascimentoProf.dia,
                         &listaProfessores[qtdProfessores].dataDeNascimentoProf.mes,
                         &listaProfessores[qtdProfessores].dataDeNascimentoProf.ano);
    getchar();

    printf("Digite o CPF (somente numeros): \n");
    fgets(listaProfessores[qtdProfessores].cpf, 15, stdin);
    tam = 0;
    while (listaProfessores[qtdProfessores].cpf[tam] != '\0'){
        tam++;
    } if (tam > 0 && listaProfessores[qtdProfessores].cpf[tam-1] == '\n'){
        listaProfessores[qtdProfessores].cpf[tam-1] = '\0';
    }

    return CADASTRO_SUCESSO;
 }

 void listarProfessores(cadastroProfessores listaProfessores[], int qtdProfessores){
    printf("\nLista de professores: \n");
    for (int i = 0; i < qtdProfessores; i++){
        printf("\nID: %d\n", listaProfessores[i].id);
        printf("Nome: %s\n", listaProfessores[i].nome);
        printf("Sexo: %c\n", listaProfessores[i].sexo);
        printf("Data de nascimento: %d/%d/%d\n", listaProfessores[i].dataDeNascimentoProf.dia,
                                                 listaProfessores[i].dataDeNascimentoProf.mes,
                                                 listaProfessores[i].dataDeNascimentoProf.ano);
        printf("CPF: %s\n", listaProfessores[i].cpf);
    }
    
 }

 int atualizarProfessor(cadastroProfessores listaProfessores[], int qtdProfessores){
    printf("\nAtualizar professor\n");

    listarProfessores(listaProfessores, qtdProfessores);

    int id;
    printf("\nDigite o ID do professor: ");
    scanf("%d", &id);

    int localizado = 0;

    for(int i = 0; i < qtdProfessores; i++){
        if (id == listaProfessores[i].id){
            printf("Digite o ID do professor: \n");
            scanf("%d", &listaProfessores[i].id);
            getchar();

            printf("Digite o nome: \n");
            fgets(listaProfessores[i].nome, 50, stdin);
            int tam = 0;
            while (listaProfessores[i].nome[tam] != '\0'){
                tam++;
            } if (tam > 0 && listaProfessores[i].nome[tam-1] == '\n'){
                listaProfessores[i].nome[tam-1] = '\0';
            }

            printf("Digite o sexo (F/M): \n");
            scanf(" %c", &listaProfessores[i].sexo);
            getchar();

            printf("Digite a data de nascimento DD/MM/AAAA: \n");
            scanf("%d/%d/%d", &listaProfessores[i].dataDeNascimentoProf.dia,
                                 &listaProfessores[i].dataDeNascimentoProf.mes,
                                 &listaProfessores[i].dataDeNascimentoProf.ano);
            getchar();

            printf("Digite o CPF (somente numeros): \n");
            fgets(listaProfessores[i].cpf, 15, stdin);
            tam = 0;
            while (listaProfessores[i].cpf[tam] != '\0'){
                tam++;
            } if (tam > 0 && listaProfessores[i].cpf[tam-1] == '\n'){
                listaProfessores[i].cpf[tam-1] = '\0';
            }

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

int excluirProfessor(cadastroProfessores listaProfessores[], int qtdProfessores){

    printf("\nExcluir professor\n");

    int id;
    int localizado = 0;

    printf("Digite o ID do professor: ");
    scanf("%d", &id);

    for (int i = 0; i < qtdProfessores; i++){

        if (id == listaProfessores[i].id){
            for (int j = i; j < qtdProfessores - 1; j++){
                listaProfessores[j].id = listaProfessores[j + 1].id;
                strcpy(listaProfessores[j].nome, listaProfessores[j + 1].nome);
                listaProfessores[j].sexo = listaProfessores[j + 1].sexo;
                listaProfessores[j].dataDeNascimentoProf.dia = listaProfessores[j + 1].dataDeNascimentoProf.dia;
                listaProfessores[j].dataDeNascimentoProf.mes = listaProfessores[j + 1].dataDeNascimentoProf.mes;
                listaProfessores[j].dataDeNascimentoProf.ano = listaProfessores[j + 1].dataDeNascimentoProf.ano;
                strcpy(listaProfessores[j].cpf, listaProfessores[j + 1].cpf);
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

int menuDisciplinas(){
    int opcaoDisciplina;

    printf("\nDigite a opcao: \n");
    printf("0 - Voltar ao menu principal\n");
    printf("1 - Cadastrar disciplina\n");
    printf("2 - Listar disciplinas\n");
    printf("3 - Atualizar disciplina\n");
    printf("4 - Excluir disciplina\n\n");

    scanf("%d", &opcaoDisciplina);

    return opcaoDisciplina;
}

int cadastrarDisciplinas(cadastroDisciplinas listaDisciplinas[], int qtdDisciplinas){
    printf("Digite o ID da disciplina: \n");
    scanf("%d", &listaDisciplinas[qtdDisciplinas].id);
    getchar();

    printf("Digite o nome da disciplina: \n");
    fgets(listaDisciplinas[qtdDisciplinas].nome, 50, stdin);
    int tam = 0;
    while (listaDisciplinas[qtdDisciplinas].nome[tam] != '\0') {
        tam++;
    }
    if (tam > 0 && listaDisciplinas[qtdDisciplinas].nome[tam - 1] == '\n') {
        listaDisciplinas[qtdDisciplinas].nome[tam - 1] = '\0';
    }

    printf("Digite o semestre: \n");
    scanf("%d", &listaDisciplinas[qtdDisciplinas].semestre);
    getchar();

    printf("Digite o nome do professor: \n");
    fgets(listaDisciplinas[qtdDisciplinas].professor, 50, stdin);
    tam = 0;
    while (listaDisciplinas[qtdDisciplinas].professor[tam] != '\0') {
        tam++;
    }
    if (tam > 0 && listaDisciplinas[qtdDisciplinas].professor[tam - 1] == '\n') {
        listaDisciplinas[qtdDisciplinas].professor[tam - 1] = '\0';
    }

    return CADASTRO_SUCESSO;
}

void listarDisciplinas(cadastroDisciplinas listaDisciplinas[], int qtdDisciplinas){
    printf("\nLista de disciplinas: \n");
    for (int i = 0; i < qtdDisciplinas; i++) {
        printf("\nID: %d\n", listaDisciplinas[i].id);
        printf("Nome: %s\n", listaDisciplinas[i].nome);
        printf("Semestre: %d\n", listaDisciplinas[i].semestre);
        printf("Professor: %s\n", listaDisciplinas[i].professor);
    }
}

int atualizarDisciplina(cadastroDisciplinas listaDisciplinas[], int qtdDisciplinas){
    printf("\nAtualizar disciplina\n");

    listarDisciplinas(listaDisciplinas, qtdDisciplinas);

    int id;
    printf("\nDigite o ID da disciplina: ");
    scanf("%d", &id);

    int localizado = 0;

    for (int i = 0; i < qtdDisciplinas; i++) {
        if (id == listaDisciplinas[i].id) {
            printf("Digite o ID da disciplina: \n");
            scanf("%d", &listaDisciplinas[i].id);
            getchar();

            printf("Digite o nome da disciplina: \n");
            fgets(listaDisciplinas[i].nome, 50, stdin);
            int tam = 0;
            while (listaDisciplinas[i].nome[tam] != '\0') {
                tam++;
            }
            if (tam > 0 && listaDisciplinas[i].nome[tam - 1] == '\n') {
                listaDisciplinas[i].nome[tam - 1] = '\0';
            }

            printf("Digite o semestre: \n");
            scanf("%d", &listaDisciplinas[i].semestre);
            getchar();

            printf("Digite o nome do professor: \n");
            fgets(listaDisciplinas[i].professor, 50, stdin);
            tam = 0;
            while (listaDisciplinas[i].professor[tam] != '\0') {
                tam++;
            }
            if (tam > 0 && listaDisciplinas[i].professor[tam - 1] == '\n') {
                listaDisciplinas[i].professor[tam - 1] = '\0';
            }

            localizado = 1;
            break;
        }
    }
    if (!localizado) {
        return NAO_LOCALIZADO;
    } else {
        return LOCAL_SUCESSO;
    }
}

int excluirDisciplina(cadastroDisciplinas listaDisciplinas[], int qtdDisciplinas){
    printf("\nExcluir disciplina\n");

    int id;
    int localizado = 0;

    printf("Digite o ID da disciplina: ");
    scanf("%d", &id);

    for (int i = 0; i < qtdDisciplinas; i++) {
        if (id == listaDisciplinas[i].id) {
            for (int j = i; j < qtdDisciplinas - 1; j++) {
                listaDisciplinas[j].id = listaDisciplinas[j + 1].id;
                strcpy(listaDisciplinas[j].nome, listaDisciplinas[j + 1].nome);
                listaDisciplinas[j].semestre = listaDisciplinas[j + 1].semestre;
                strcpy(listaDisciplinas[j].professor, listaDisciplinas[j + 1].professor);
            }
            localizado = 1;
            break;
        }
    }
    if (localizado) {
        return EXCLUIDO_SUCESSO;
    } else {
        return NAO_LOCALIZADO;
    }
}

int menuRelatorios(){
    int opcaoRelatorio;

    printf("\nRelatorios\n");
    printf("Digite a opcao: \n");
    printf("0 - Voltar ao menu principal\n");
    printf("1 - Lista de alunos ordenados por nome \n");
    printf("2 - Lista de alunos (por parte do nome) \n");
    printf("3 - Lista de alunos por sexo \n");
    printf("4 - Lista de alunos por data de nascimento \n");
    printf("5 - Lista de professores ordenados por nome \n");
    printf("6 - Lista de professores (por parte do nome) \n");
    printf("7 - Lista de professores por sexo \n");
    printf("8 - Lista de professores por data de nascimento \n");
    printf("9 - Lista de disciplinas com alunos matriculados \n");
    printf("10 - Lista de alunos matriculados em menos de 3 disciplinas \n");
    printf("11 - Lista de disciplinas que extrapolam 40 vagas \n");
    printf ("12 - Aniversariantes do mes \n");

    scanf("%d", &opcaoRelatorio);
    
    return opcaoRelatorio;

}

void listaAlunosOrdemNome (cadastroAlunos listaAlunos[], int qtdAlunos){
    if(qtdAlunos == 0){
        printf("\nNao ha alunos cadastrados.\n");
        return; 
    }

    cadastroAlunos listaOrdenada[TamAlunos];
    for(int i = 0; i < qtdAlunos; i++){
        listaOrdenada[i] = listaAlunos[i];
    }

    for (int i = 0; i < qtdAlunos - 1; i++){
         for (int j = 0; j < qtdAlunos - 1 - i; j++){
            if (strcmp (listaOrdenada[j].nome , listaOrdenada[j + 1].nome) > 0){

                cadastroAlunos aux = listaOrdenada[j];
                listaOrdenada[j] = listaOrdenada[j + 1];
                listaOrdenada[j + 1] = aux;
            }
    
    printf("\nAlunos ordenados por nome: \n");
    for (int i = 0; i < qtdAlunos; i++){
    printf("\nMatricula: %d\n", listaOrdenada[i].matricula);
    printf("Nome: %s\n", listaOrdenada[i].nome);
    printf("Sexo: %c\n", listaOrdenada[i].sexo);
    printf("Data de nascimento: %d/%d/%d\n", listaOrdenada[i].dataDeNascimento.dia, 
											 listaOrdenada[i].dataDeNascimento.mes, 
											 listaOrdenada[i].dataDeNascimento.ano);
    printf("CPF: %s\n", listaOrdenada[i].cpf);
    }

        }
    }
}

void listaAlunoPorSexo (cadastroAlunos listaAlunos[], int qtdAlunos){

    if (qtdAlunos == 0){
        printf("\nNao ha alunos cadastrados.\n");
        return;
    }

    char caracterFM;
    printf("Digite a opcao F ou M: ");
    scanf(" %c", &caracterFM);

    char caracterProcurado = toupper(caracterFM);
    if(caracterProcurado != 'F' && caracterProcurado != 'M'){
        printf("Opcao invalida! Digite F ou M.");
        while (getchar() != '\n');
        return;
    }

    int encontrado = 0;
    
    printf("\nLista de alunos do sexo %c \n", caracterProcurado);
    for (int i = 0; i < qtdAlunos; i++){
        if (listaAlunos[i].sexo == caracterProcurado){
            printf("\nMatricula: %d\n", listaAlunos[i].matricula);
            printf("Nome: %s\n", listaAlunos[i].nome);
            printf("Sexo: %c\n", listaAlunos[i].sexo);
            printf("Data de nascimento: %d/%d/%d\n", listaAlunos[i].dataDeNascimento.dia, 
											 listaAlunos[i].dataDeNascimento.mes, 
											 listaAlunos[i].dataDeNascimento.ano);
            printf("CPF: %s\n", listaAlunos[i].cpf);

            encontrado++;
            }
            
        }
        if(encontrado == 0){
            printf("\nNenhum aluno do sexo %c foi encontrado.\n", caracterProcurado);
        } else {
            printf("\nTotal de alunos do sexo %c encontrados: %d.\n", caracterProcurado, encontrado);
        }
        while (getchar() != '\n');
    
}

int organizarDatas (Data d1, Data d2){
    if (d1.ano != d2.ano){
        return d1.ano - d2.ano;
    } if (d1.mes != d2.mes){
        return d1.mes - d2.mes;
    } else {
        return d1.dia - d2.dia;
    }
}

void listaAlunoOrdemDataNascimento (cadastroAlunos listaAlunos[], int qtdAlunos){

     if (qtdAlunos == 0){
        printf("\nNao ha alunos cadastrados.\n");
        return;
    }

    cadastroAlunos ordenadoData[TamAlunos];
    for(int i = 0; i < qtdAlunos; i++){
        ordenadoData[i] = listaAlunos[i];
    }

    for (int i = 0; i < qtdAlunos - 1; i++){
         for (int j = 0; j < qtdAlunos - 1 - i; j++){
            if(organizarDatas(ordenadoData[j].dataDeNascimento, 
                            ordenadoData[j+1].dataDeNascimento) > 0){
                cadastroAlunos aux = ordenadoData[j];
                ordenadoData[j] = ordenadoData[j+1];
                ordenadoData[j+1] = aux;
            }
         }
    }

    printf("\nAlunos por ordem de data de nascimento: \n");
     for (int i = 0; i < qtdAlunos; i++){
    printf("\nMatricula: %d\n", ordenadoData[i].matricula);
    printf("Nome: %s\n", ordenadoData[i].nome);
    printf("Sexo: %c\n", ordenadoData[i].sexo);
    printf("Data de nascimento: %d/%d/%d\n", ordenadoData[i].dataDeNascimento.dia, 
											 ordenadoData[i].dataDeNascimento.mes, 
											 ordenadoData[i].dataDeNascimento.ano);
    printf("CPF: %s\n", ordenadoData[i].cpf);
    }

}

void listaProfessorOrdemNome (cadastroProfessores listaProfessores[], int qtdProfessores){
    if(qtdProfessores == 0){
        printf("\nNao ha professores cadastrados.\n");
        return; 
    }

    cadastroProfessores listaOrdenadaProf[TamProfessores];
    for(int i = 0; i < qtdProfessores; i++){
        listaOrdenadaProf[i] = listaProfessores[i];
    }

    for (int i = 0; i < qtdProfessores - 1; i++){
         for (int j = 0; j < qtdProfessores - 1 - i; j++){
            if (strcmp (listaOrdenadaProf[j].nome , listaOrdenadaProf[j + 1].nome) > 0){

                cadastroProfessores aux = listaOrdenadaProf[j];
                listaOrdenadaProf[j] = listaOrdenadaProf[j + 1];
                listaOrdenadaProf[j + 1] = aux;
            }

    printf("\nProfessores ordenados por nome: \n");
    for (int i = 0; i < qtdProfessores; i++){
    printf("\nMatricula: %d\n", listaOrdenadaProf[i].id);
    printf("Nome: %s\n", listaOrdenadaProf[i].nome);
    printf("Sexo: %c\n", listaOrdenadaProf[i].sexo);
    printf("Data de nascimento: %d/%d/%d\n", listaOrdenadaProf[i].dataDeNascimentoProf.dia, 
											 listaOrdenadaProf[i].dataDeNascimentoProf.mes, 
											 listaOrdenadaProf[i].dataDeNascimentoProf.ano);
    printf("CPF: %s\n", listaOrdenadaProf[i].cpf);
    }

        }
    }
}

void listaProfPorSexo (cadastroProfessores listaProfessores[], int qtdProfessores){

    if (qtdProfessores == 0){
        printf("\nNao ha professores cadastrados.\n");
        return;
    }

    char caracterFM;
    printf("Digite a opcao F ou M: ");
    scanf(" %c", &caracterFM);

    char caracterProcurado = toupper(caracterFM);
    if(caracterProcurado != 'F' && caracterProcurado != 'M'){
        printf("Opcao invalida! Digite F ou M.");
        while (getchar() != '\n');
        return;
    }

    int encontrado = 0;
    
    printf("\nLista de professores do sexo %c \n", caracterProcurado);
    for (int i = 0; i < qtdProfessores; i++){
        if (listaProfessores[i].sexo == caracterProcurado){
            printf("\nMatricula: %d\n", listaProfessores[i].id);
            printf("Nome: %s\n", listaProfessores[i].nome);
            printf("Sexo: %c\n", listaProfessores[i].sexo);
            printf("Data de nascimento: %d/%d/%d\n", listaProfessores[i].dataDeNascimentoProf.dia, 
											 listaProfessores[i].dataDeNascimentoProf.mes, 
											 listaProfessores[i].dataDeNascimentoProf.ano);
            printf("CPF: %s\n", listaProfessores[i].cpf);

            encontrado++;
            }
            
        }
        if(encontrado == 0){
            printf("\nNenhum professor do sexo %c foi encontrado.\n", caracterProcurado);
        } else {
            printf("\nTotal de professor do sexo %c encontrados: %d.\n", caracterProcurado, encontrado);
        }
        while (getchar() != '\n');
    
}

void listaProfOrdemDataNascimento (cadastroProfessores listaProfessores[], int qtdProfessores){

     if (qtdProfessores == 0){
        printf("\nNao ha professores cadastrados.\n");
        return;
    }

    cadastroProfessores ordenadoData[TamAlunos];
    for(int i = 0; i < qtdProfessores; i++){
        ordenadoData[i] = listaProfessores[i];
    }

    for (int i = 0; i < qtdProfessores - 1; i++){
         for (int j = 0; j < qtdProfessores - 1 - i; j++){
            if(organizarDatas(ordenadoData[j].dataDeNascimentoProf, 
                            ordenadoData[j+1].dataDeNascimentoProf) > 0){
                cadastroProfessores aux = ordenadoData[j];
                ordenadoData[j] = ordenadoData[j+1];
                ordenadoData[j+1] = aux;
            }
         }
    }

    printf("\nProfessores por ordem de data de nascimento: \n");
     for (int i = 0; i < qtdProfessores; i++){
    printf("\nMatricula: %d\n", ordenadoData[i].id);
    printf("Nome: %s\n", ordenadoData[i].nome);
    printf("Sexo: %c\n", ordenadoData[i].sexo);
    printf("Data de nascimento: %d/%d/%d\n", ordenadoData[i].dataDeNascimentoProf.dia, 
											 ordenadoData[i].dataDeNascimentoProf.mes, 
											 ordenadoData[i].dataDeNascimentoProf.ano);
    printf("CPF: %s\n", ordenadoData[i].cpf);
    }

}