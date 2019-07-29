#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Funcionario.h"

struct funcionario {
	struct funcionario* anterior;
	int matricula;
	char nome[50];
	char endereco[100];
	char cpf[14];
	char estadoCivil[20];
	char nascimento[10];
	char escolaridade[30];
	char cargo[20];
	float salario;
	char dataAdmissao[10];
	struct funcionario* proximo;
};

typedef struct funcionario Funcionario;

struct lista{
	Funcionario* no;
};

typedef struct lista Lista;

Lista* criarLista (){
	Lista* lista = (Lista*) malloc(sizeof(Lista));
	lista->no = NULL;
	printf("Lista criada.\n");
	return lista;
};

void desalocaLista(Lista* lista){
	while (lista->no != NULL){
		if (lista->no->proximo != NULL){
			lista->no = lista->no->proximo;
			free(lista->no->anterior);
		}else{
			free(lista->no);
		}
	}
	printf("Lista deletada.");
};

void insereElemento(Lista* lista){
	Funcionario* novo = (Funcionario*)malloc(sizeof(Funcionario));
	system("cls");
	printf("PREENCHA OS CAMPOS ABAIXO:\n");
	printf("--------------------------------\n\n");
	
	printf("Digite a matricula:");
	fflush(stdin);
	scanf("%d", &novo->matricula);
	
	printf("Digite o nome do funcionario:");
	fflush(stdin);
	gets(novo->nome);
	
	printf("Digite o endereço do funcionario:");
	fflush(stdin);
	gets(novo->endereco);
	
	printf("Digite o CPF do funcionario:(simbolos inclusos)");
	fflush(stdin);
	gets(novo->cpf);
	
	printf("Digite o estado civil do funcionario:");
	fflush(stdin);
	gets(novo->estadoCivil);
	
	printf("Digite a data de nascimento do funcionario:(Barras inclusos)");
	fflush(stdin);
	gets(novo->nascimento);
	
	printf("Digite a escolaridade do funcionario:");
	fflush(stdin);
	gets(novo->escolaridade);
	
	printf("Digite o cargo do funcionario:");
	fflush(stdin);
	gets(novo->cargo);
	
	printf("Digite o salario do funcionario:");
	scanf("%f", &novo->salario);
	fflush(stdin);
	
	printf("Digite a data de admissão do funcionario:(Barras inclusas)");
	fflush(stdin);
	gets(novo->dataAdmissao);
	
	novo->proximo = NULL;
	novo->anterior = NULL;
	
	
	if(lista->no == NULL){
		lista->no = novo;
	}
	else{
		Funcionario* aux = lista->no;
		
		int comp = strcmp(aux->nome,novo->nome);
	
		while(comp<=0 && aux->proximo!=NULL){
			aux=aux->proximo;
			comp = strcmp(aux->nome,novo->nome);
		}

		comp = strcmp(aux->nome,novo->nome);
		
		if(comp != 0){
			aux->proximo = novo;
			novo->anterior = aux;
		}
		else if(comp>0 && aux->anterior == NULL){
			novo->proximo = aux;
			aux->anterior = novo;
			lista->no= novo;
		}		
		else{
			Funcionario* anterior = aux->anterior;
			anterior->proximo = novo;
			novo->anterior = anterior;
			novo->proximo = aux;
			aux->anterior = novo;
		}
	}
};

void removeElemento(int matricula,Lista* lista){
	system("cls");
	if(lista->no == NULL){
		printf("-------------------------------------------\n");
		printf("LISTA DE FUNCIONARIOS VAZIA!	\n");
		printf("-------------------------------------------\n");
	}
	else{
		
		Funcionario* aux = lista->no;
		if (lista->no->matricula == matricula && lista->no->proximo == NULL){
			if(lista->no->proximo == NULL){
				free(lista->no);
				lista->no = NULL;
			}else{
				lista->no = aux->proximo;
				lista->no->anterior = NULL;
				free(aux);
			}
		} else{
			aux = buscaFuncionario(lista, matricula);
			
			if(aux == NULL){
				printf("-------------------------------------------\n");
				printf("FUNCIONARIO NAO ENCONTRADO!	\n");
				printf("-------------------------------------------\n");
			} else if(aux->matricula==matricula && aux->proximo==NULL){
				aux->anterior->proximo == NULL;
				free(aux);
			} else {
				aux->anterior->proximo = aux->proximo;
				aux->proximo->anterior = aux->anterior;
				free(aux);
			}
		}
	}
	
};

void imprimeDadosFuncionario(Funcionario* func){
	printf("FUNCIONARIO %s:\n", func->nome);
	printf("--------------------------------\n\n");
	printf("MATRICULA:		%d\n", func->matricula);
	printf("ENDERECO:		%s\n", func->endereco);
	printf("CPF:			%s\n", func->cpf);
	printf("ESTADO CIVIL:		%s\n", func->estadoCivil);
	printf("DATA DE NASCIMENTO:	%s\n", func->nascimento);
	printf("ESCOLARIDADE:		%s\n", func->escolaridade);
	printf("CARGO:			%s\n", func->cargo);
	printf("SALARIO:		%0.2f\n", func->salario);
	printf("DATA DE EMISSAO:	%s\n\n", func->dataAdmissao);
	
};

void imprimeFuncionario(int matricula, Lista* lista){
	system("cls");
	if(lista->no == NULL){
		printf("-------------------------------------------\n");
		printf("LISTA DE FUNCIONARIOS VAZIA!	\n");
		printf("-------------------------------------------\n");
	}
	else{
		Funcionario* func = buscaFuncionario(lista, matricula);
		if(func == NULL){
			printf("-------------------------------------------\n");
			printf("FUNCIONARIOS NAO ENCONTRADO!	\n");
			printf("-------------------------------------------\n");
		}else{
			imprimeDadosFuncionario(func);
		}		
	}
	system("pause");
	
};

void imprimeLista(Lista* lista){
	system("cls");
	if(lista->no == NULL){
		printf("-------------------------------------------\n");
		printf("LISTA DE FUNCIONARIOS VAZIA!	\n");
		printf("-------------------------------------------\n");
	}
	else{
		printf("-------------------------------------------\n");
		printf("LISTA DE FUNCIONARIOS	\n");
		printf("-------------------------------------------\n\n");
		Funcionario* func = lista->no;
		
		do{
			imprimeDadosFuncionario(func);
			func = func->proximo;
		}while(func->proximo != NULL);
	}
	system("pause");
};

Funcionario* buscaFuncionario(Lista* lista, int matricula){
	if(lista->no == NULL){
		return NULL;
	} else{
		Funcionario* aux = lista->no;
		
		while(aux->matricula != matricula && aux->proximo != NULL){
			aux=aux->proximo;
		}
		if(aux->matricula==matricula){
			return aux;
		} else{
			return NULL;
		}
	}
};

