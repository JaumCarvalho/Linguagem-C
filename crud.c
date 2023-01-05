#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tProduto{
	int codigo;
	char descricao[30];
	float valor;
};

int menu();

void main(){
	const int TAM = 6;
	int i, opcao, codigo, found, qtdProduto=0;
	struct tProduto produtos[TAM];
	do{
		opcao = menu();
		switch (opcao){
			case 1:
				printf("\n\n*** Inclusao ***\n\n");
				
				if(qtdProduto<TAM){
					printf("Digite o codigo...: ");
					scanf("%d",&produtos[qtdProduto].codigo);
					printf("Digite a descricao: ");
					scanf("%s",&produtos[qtdProduto].descricao);
					printf("Digite o valor....: ");
					scanf("%f",&produtos[qtdProduto].valor);
					qtdProduto++;
				}else{
					printf("Vetor cheio!");
				}
				break;
			case 2:
				printf("\n\n*** Consulta ***\n\n");
				
				printf("Digite o codigo...: ");
				scanf("%d",&codigo);
				found = 0;
				for(i=0;i<qtdProduto;i++){
					if(codigo == produtos[i].codigo){
						printf("DESCRICAO | VALOR\n");
						printf("   %s     | %.2f\n", produtos[i].descricao, produtos[i].valor);
						found = 1;
					}
				}
				if(!found){
					printf("\nCodigo nao encontrado!\n");
				}
				
				
				break;
			case 3:
				printf("\n\n*** Listagem ***\n\n");
				int i;
				printf("CODIGO | DESCRICAO | VALOR\n");
				for(i=0;i<qtdProduto;i++){
					
					printf("   %d   |    %s     |  %.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].valor);
				}
	
				break;
			case 4:
				printf("\n\n*** Alteracao ***\n\n");
				
				printf("Digite o codigo...: ");
				scanf("%d",&codigo);
				found = 0;
				for(i=0;i<qtdProduto;i++){
					if(codigo == produtos[i].codigo){
						printf("\nDESCRICAO | VALOR\n");
						printf("   %s     | %.2f\n", produtos[i].descricao, produtos[i].valor);
						found = 1;
						printf("Digite a descricao: ");
						scanf("%s",&produtos[i].descricao);
						printf("Digite o valor....: ");
						scanf("%f",&produtos[i].valor);

						
					}
				}
				if(!found){
					printf("\nCodigo nao encontrado!\n");
				}
				
				break;
			case 5:
				printf("\n\n*** Exclusao ***\n\n");
				
				printf("Digite o codigo...: ");
				scanf("%d",&codigo);
				found = 0;
				for(i=0;i<qtdProduto;i++){
					if(codigo == produtos[i].codigo){
						printf("\nDESCRICAO | VALOR\n");
						printf("   %s     | %.2f\n", produtos[i].descricao, produtos[i].valor);
						found = 1;
						produtos[i] = produtos[qtdProduto-1];
						qtdProduto--;
					}
				}
				if(!found){
					printf("\nCodigo nao encontrado!\n");
				}
				break;
			case 6:
				system("cls");
		}
	}while(opcao != 0);
}

int menu(){
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Inclusao\n");
	printf("2. Consulta\n");
	printf("3. Listagem\n");
	printf("4. Alteracao\n");
	printf("5. Exclusao\n");
	printf("6. Limpar a tela\n");
	printf("0. Sair\n");
	printf("Escolha sua opcao: ");
	scanf("%d",&op);
	return op;
}
