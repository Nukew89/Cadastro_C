#include <stdio.h>
#include <string.h>
#include <conio.h>
#define SIZE 200


char nome[SIZE][50];
char email[SIZE][50];
int cpf[SIZE];
int op; // variavel para armazenar minha opcoes;

void cadastro(); //a funï¿½ï¿½o nï¿½o irï¿½ retornar nenhum valor
void pesquisa();
void lista();

int main(void){  


	do{
		system("cls");
		printf("\n---Menu---\n1 - Cadastrar\n2 - Listar todos\n3 - Pesquisar\n4 - Sair");
		scanf("%d", &op);
		switch(op){      //para fazer a comparação
		
			case 1:
				cadastro(); // chama a funcao cadastro;
				break;
			
			case 2:
				lista();
				break;
			
			case 3:
				pesquisa();
				break;
				
			case 4:
				system("exit");
				break;
				
			default:  //se nao digitar nenhuma das opcoes, sera mostrado opcao invalida.
				printf("Opcao Invalida");
				getchar();
				getchar();
				break;
			
		}
	}while(op!=4);
}

void lista(){
	int i;
	for(i=0; i<SIZE; i++){
		
		if(cpf[i]>0){
			
			printf("\nNome: %s\nEmail: %s\nCPF: %d", nome[i], email[i], cpf[i]);
			
		}else{
			break;
		}
	}
	getchar();
	getchar();
}
void cadastro()
{
	static int linha;
	do
	{
		printf("\nDigite o nome: "); //%s = para String e %d para Inteiro..
		scanf("%s", &nome[linha]);
		printf("\nDigite o email: ");
		scanf("%s", &email[linha]);
		printf("\nDigite o cpf: ");
		scanf("%d", &cpf[linha]);
		printf("\nDigite 1 para continuar ou outro valor para sair ");
		scanf("%d", &op);
		linha++; //primeira vez que for executado, linha sera = 0

	} while (op == 1);

} // fim da funcao cadastro

void pesquisa()
{
	int cpfPesquisa;
	char emailPesquisa[50];
	int i;

	do
	{
		printf("\nDigite 1 para pesquisar o cpf ou 2 para pesquisar o email");
		scanf("%d", op);

		switch (op)
		{
		case 1:

			printf("\nDigite o CPF: ");
			scanf("%d", cpfPesquisa);
			for (i = 0; i < SIZE; i++)
			{
				if (cpf[i] == cpfPesquisa)
				{
					printf("\nNome: %s\nEmail: %s\nCPF: %d", nome[i], email[i], cpf[i]);
				}
			}

			break;

		case 2:
			printf("\nDigiete o E-mail");
			scanf("%s", emailPesquisa);
			for (i = 0; i < SIZE; i++)
			{
				if (strcmp(email[i], emailPesquisa) == 0)
				{
					printf("\nNome: %s\nEmail: %s\nCPF: %d", nome[i], email[i], cpf[i]);
				}
			}

			break;
		default:
			printf("\n Opcao invalida");

			break;
		}
		printf("\nDigite 1 para continuar pesquisando ");
		scanf("%d", &op);

	} while (op == 1);
}
