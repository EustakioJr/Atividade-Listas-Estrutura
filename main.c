#include <stdio.h>
#include <stdlib.h>
#include "Funcionario.h"

int main(int argc, char *argv[]) {
	int escolha;
	int matricula;
	Lista* lista;
		
	do{
		//system("cls");
		printf("\n\nBem-vindo a interface de usuario!\n");
		//1- Cria Lista
		printf("Digite 1 para criar uma lista.\n");
		//2- Desaloca Lista
		printf("Digite 2 para desalocar uma lista.\n");
		//3- Adiciona Funcionario
		printf("Digite 3 para adicionar um funcionario na lista.\n");
		//4- Remove Funcionario
		printf("Digite 4 para remover um funcionario na lista.\n");
		//5- Busca Funcionario
		printf("Digite 5 para buscar um funcionario na lista.\n");
		//6- Imprime Funcionario
		printf("Digite 6 para imprimir um funcionario.\n");
		//7- Imprime a Lista
		printf("Digite 7 para imprimir a lista.\n");
		//0- Sair
		printf("Digite 0 para sair.\n");
		printf("Escolha a opção que deseja realizar:");
		scanf("%d", &escolha);
		printf("%d", escolha);
		
		switch(escolha){
			case 1: //Entra nessa opção ao escolher a opção de criar a lista.
				lista= criarLista();
				break;
			case 2://Entra nessa opção ao escolher a opção de desalocar(excluir) a lista.
				desalocaLista(lista);
				break;
			
			case 3://Entra nessa opção ao escolher a opção de inserir um elemento na lista.
				insereElemento(lista);
				break;
			case 4://Entra nessa opção ao escolher a opção de remover um elemento da lista.
				printf("Digite a matricula:");
				scanf("%d", &matricula);
				removeElemento(matricula, lista);
				break;
			case 5://Entra nessa opção ao escolher a opção de buscar um elemento da lista.
				printf("Digite a matricula:");
				scanf("%d", &matricula);
				imprimeFuncionario(matricula, lista);
				break;
			case 6://Entra nessa opção ao escolher a opção de imprimir um elemento da lista.
				printf("Digite a matricula:");
				scanf("%d", &matricula);
				imprimeFuncionario(matricula, lista);
				break;
			case 7://Entra nessa opção ao escolher a opção de imprimir a lista escolhida.
				imprimeLista(lista);
				break;
			case 0:
				break;
			default:
				printf("Opcao invalida!");
		}
	}while(escolha != 0);
	
	return 0;
}
