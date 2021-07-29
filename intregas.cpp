//intregas 

//Declaração de bibliotecas 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

//Formação da struct
struct cadastro{
	int pedido;
	char nome[30];
	float valor;
	char rua[40];
	int qtdkit;
	int numero;
	int horario;
	char prioritario[2];
	struct cadastro *ante;
	struct cadastro *prox;
};
typedef struct cadastro fila;

//Função principal
main()
{
	//Declaração de variáveis globais
	int opcao, ped=0;
	char resposta;
	char prioridade [2]= "n";
	
	
	//Inserindo cadastro null

	fila *inicio = (fila *) malloc (sizeof(fila));

	if(!inicio) {
		printf("Inicio da fila nao foi criado.");
		exit(0);
	}

	inicio->pedido= NULL;
	inicio->nome[0] = NULL;
	inicio->valor = NULL;
	inicio->rua[0] = NULL;
	inicio->numero = NULL;
	inicio->horario = NULL;
	inicio->prioritario[0] = NULL;
	inicio->prox = NULL;
	inicio->ante = NULL;
	
	do {
		//menu principal
		printf("Ola seja bem vindo ao Intregas");
		printf("\nMENU PRINCIPAL");
		printf("\nOpcao 1 --- Inserir cliente prioritario e nao prioritario no final da fila.");
		printf("\nOpcao 2 --- Inserir cliente nao prioritario no inicio da fila");
		printf("\nOpcao 3 --- Inserir cliente prioritario no inicio da fila");
		printf("\nOpcao 4 --- Imprimir todos os pedidos");
		printf("\nOpcao 5 --- Imprimir pedido especifico");
		printf("\nOpcao 6 --- Cancelar algum pedido");	
		printf("\nOpcao 7 --- ajuda");
		printf("\nOpcao 8 --- Sair do programa\n");
		printf("\nOpcao: ");
		scanf("%i",&opcao);

		system("cls");

		switch(opcao) {

			case 1: { //Inserir cliente não prioritário no final da fila
				
				// OPÇÃO DE INSERIR

				do {
					fila *novo = (fila *) malloc (sizeof(fila));

					if(!novo) {
						printf("Não foi possível criar a nova caixa.");
						exit(0);
					}

					novo->pedido= NULL;
					novo->nome[0] = NULL;
					novo->valor = NULL;
					novo->rua[0] = NULL;
					novo->numero = NULL;
					novo->horario = NULL;
					novo->prioritario[0]= NULL;
					novo->prox = NULL;
					novo->ante = NULL;

					fflush(stdin);
					printf("Entre com o nome do cliente: ");
					gets (novo->nome);
					
					fflush(stdin);
					printf("Entre com a rua do cliente: ");
					gets (novo->rua);

					printf("Entre com o numero da casa do cliente: ");
					scanf("%i", &novo->numero);

					printf("Entre com a quantidade de kits: ");
					scanf("%i", &novo->qtdkit);
					
					fflush(stdin);
					printf("Esse pedido e prioritario?<n/s>");
					gets (novo->prioritario);
				
					printf("Entre com a hora da entrega:");
					scanf("%i", &novo->horario);
					//condição para que o usuario nao coloque um numero nao existente 
					while(novo->horario<0 or novo->horario>24)
					{
						novo->horario = NULL;
						printf("Nao existe esse horario, digite novamente:");
						scanf("%i", &novo->horario);		
					}
					
					//incerção do pedido automáticamente 
					novo->valor = 120 * novo->qtdkit;
					novo->pedido = ped;
					ped ++;
					
					//Condição para o primeiro da fila
					if(inicio->prox == NULL) 
						{
						 inicio->prox = novo;
						 novo->ante = inicio;
						 novo->prox = inicio;
						 inicio->ante = novo;
						}
					
					//Inserindo prioritário no final da fila dos prioritário
					else
					{
						//condiçãopara inserir prioritario no final da fila
						 if(strcmp(prioridade,novo->prioritario)!=0)						    
					    {
					    	fila *temp;
					    	temp = inicio->prox;
					    	
					    	//condição para o prioritario ser o primeiro da fila
					    	if(temp->prox == inicio)
					    	{ 
					    		if(strcmp(prioridade,temp->prioritario)==0)
					    		{
					    			novo->prox = temp;
					    			novo->ante = inicio;
					    			inicio->prox = novo;
					    			temp->ante = novo;
								}
								
								else if(strcmp(prioridade,temp->prioritario)!=0)
								{
									novo->prox = temp->prox;
							    	temp->prox = novo;
							    	novo->ante = inicio;	
								 	temp->ante = novo;
								}
					    			
							}
					    	
					    	//Inserindo prioritário no final da fila 
					    	else 
							{
								while(strcmp (prioridade,temp->prioritario)!=0 )
					    		temp=temp->prox;
					    	
					    		fila *temp0 = temp->ante;
						    	novo->prox = temp;
						    	novo->ante = temp0;
								temp0->prox = novo;
								temp->ante = novo;
							}
						}
						
						//condição para inserir um não prioritariion no final da fila 
						else if(strcmp(prioridade,novo->prioritario)==0) 
						{
							if(inicio->prox != NULL) 
						    {
								fila *temp;
								temp = inicio->prox;
		
								while(temp->prox != inicio) 
								temp = temp->prox;
								
								novo->prox = temp->prox;
						    	temp->prox = novo;
						    	novo->ante = temp;	
							 	inicio->ante = novo;	
						    }	
						}
					}
		
					printf("Fazer outro pedido?<S/N>: ");
					resposta = getche();
					system("cls");

				} while(toupper(resposta) == 'S');

				break;
			}

			case 2: { //Inserir cliente não prioritário no inicío da fila 
				
				fila *novo = (fila *) malloc (sizeof(fila));
					
				if(!novo) 
				{
					printf("Não foi possível criar a nova caixa.");
					exit(0);
				}

				novo->pedido= NULL;
				novo->nome[0] = NULL;
				novo->valor = NULL;
				novo->rua[0] = NULL;
				novo->numero = NULL;
				novo->horario = NULL;
				novo->prioritario [0]= NULL;
				novo->prox = NULL;
				novo->ante = NULL;

				fflush(stdin);
				printf("Entre com o nome do cliente: ");
				gets (novo->nome);
					
				fflush(stdin);
				printf("Entre com a rua do cliente: ");
				gets (novo->rua);

				printf("Entre com o numero da casa do cliente: ");
				scanf("%i", &novo->numero);

				printf("Entre com a quantidade de kits: ");
				scanf("%i", &novo->qtdkit);
				
				strcpy(novo->prioritario,prioridade);
					
				printf("Entre com a hora da entrega:");
				scanf("%i", &novo->horario);
				while(novo->horario<0 or novo->horario>24)
				{
					novo->horario = NULL;
					printf("Nao existe esse horario, digite novamente:");
					scanf("%i", &novo->horario);		
				}
					
				novo->valor = 120 * novo->qtdkit;
				novo->pedido = ped;
				ped ++;
				
				//Verificando de existem so nao prioritarios na fila
				fila *temp = inicio->prox;
				while(strcmp (prioridade,temp->prioritario)!=0)
				temp = temp->prox;
				
				//incerção de um novo cliente
				fila *temp0;
				temp0 = temp->ante;
				novo->prox = temp0->prox;
				novo->ante = temp0;
				temp0->prox = novo;	
				temp->ante = novo;
			    
					
				system("pause");
				system("cls");

			break;
			}
			
			case 3: { //Inserir cliente prioritário no inicio da fila
			
				//Inserir variavel local
				char priorit[2] = "s";
				fila *novo = (fila *) malloc (sizeof(fila));
					
				if(!novo) 
				{
					printf("Não foi possível criar a nova caixa.");
					exit(0);
				}

				novo->pedido= NULL;
				novo->nome[0] = NULL;
				novo->valor = NULL;
				novo->rua[0] = NULL;
				novo->numero = NULL;
				novo->horario = NULL;
				novo->prioritario [0]= NULL;
				novo->prox = NULL;
				novo->ante = NULL;

				fflush(stdin);
				printf("Entre com o nome do cliente: ");
				gets (novo->nome);
					
				fflush(stdin);
				printf("Entre com a rua do cliente: ");
				gets (novo->rua);

				printf("Entre com o numero da casa do cliente: ");
				scanf("%i", &novo->numero);

				printf("Entre com a quantidade de kits: ");
				scanf("%i", &novo->qtdkit);
				
				strcpy(priorit,novo->prioritario);
					
				printf("Entre com a hora da entrega:");
				scanf("%i", &novo->horario);
				while(novo->horario<0 or novo->horario>24)
				{
					novo->horario = NULL;
					printf("Nao existe esse horario, digite novamente:");
					scanf("%i", &novo->horario);		
				}
					
				novo->valor = 120 * novo->qtdkit;
				novo->pedido = ped;
				ped ++;
				
				fila *temp = inicio->prox;
				if(strcmp (prioridade,temp->prioritario)!=0)
				{
					novo->prox = inicio->prox;	
					novo->ante = inicio;
					temp->ante = novo;
				    inicio->prox = novo;		
				}
				
				system("pause");
				system("cls");

				break;
			}
			
			case 4: //Imprimir todos os pedidos 
			{
				if(inicio->prox == NULL)
				{
					printf("Nao existe nenhum cliente na fila\n");
					system("pause");
					system("cls");
					break;
				}
				
				fila *temp;
				temp = inicio->prox;
				while(temp != inicio) 
				{
					printf("Numero do pedido : #00%i\n",temp->pedido);
					printf("Nome do cliente: %s\n",temp->nome);
					printf("Valor a ser recebido: %f\n",temp->valor);
					printf("Endereço: %s, %i\n",temp->rua,temp->numero);
					printf("Horário de entrega: %i:00\n",temp->horario);
					system("pause");
					system("cls");

					temp = temp->prox;
				}
				
				break;
			}
			case 5: //Imprimir pedido específico 
			{
				//Declarção de variaveis locais 
				int pedidoaux;
				
				printf("Inserir pedido do cliente que quer imprimir: \n");
				scanf("%i", &pedidoaux); //Pedidoaux e uma variavel de controle para encontrar o pedido específico
				system("pause");
				system("cls");


				fila *temp = inicio->prox;

				while(temp != inicio) {
					if(pedidoaux == temp->pedido) 
					{
						printf("Numero do pedido : #00%i\n",temp->pedido);
						printf("Nome do cliente: %s\n",temp->nome);
						printf("Valor a ser recebido: %f\n",temp->valor);
						printf("Endereço: %s, %i\n",temp->rua,temp->numero);
						printf("Horário de entrega: %i:00\n",temp->horario);
						system("pause");
						system("cls");
					}

					temp = temp->prox;
				}
				break;
			}
			
			case 6: //Cancelar algum pedido
			{
				//Declaração de variáveis
				int pedidoaux;
				
				printf("O pedido que deseja cancelar:  ");
				scanf("%i", &pedidoaux);
				system("pause");
				system("cls");
			
				//Exclusão de aluno
				fila *temp = inicio->prox;
				fila *temp0;
				
				//Estrutura de repetição para passar por todos clientes da fila
				while(temp != inicio) 
				{		
					//A condição para excluir cliente da fila	
					if(pedidoaux == temp->pedido )
					{
						//Condição para quando for o ultimo item da fila
						if(temp->prox == inicio)
						{
							temp0 = temp->ante;
							temp0->prox = inicio;
							inicio->ante = temp0;
							free(temp);	
							
							if(inicio->prox == NULL)
							{
								printf("Acabou os clientes da fila!");
								break;
							}
						}
						
						//exclusão dos demais itens
						else
						{	
							
							if(inicio->prox == NULL)
							{
								printf("Acabou os clientes da fila!");
								break;
							}
									
							temp0 = temp->ante;
							temp0->prox = temp->prox;
							fila *temp1 = temp->prox;
							temp1->ante = temp0;
							free(temp);
							break;
						}
					}
					temp = temp->prox;		
				}
				break;
			}
				
			case 7: //Menu de ajuda 
				{
					//Declaração de variaveis locais
						int opc;
						
						
					do{
				
						printf("Bem vindo ao Intregas\n");
						printf("Esta precisando de ajuda?\n");
						printf("Aqui temos um menu que pode facilitar o uso do software :D\n");
						
						printf("\n");
						
						printf("\nOpcao 1 --- Sobre inserir cliente no final da fila.");
						printf("\nOpcao 2 --- Sobre inserir cliente nao prioritario no inicio da fila");
						printf("\nOpcao 3 --- Sobre inserir cliente prioritário no inicio da fila");
						printf("\nOpcao 4 --- Sobre imprimir todos os pedidos");
						printf("\nOpcao 5 --- Sobre imprimir pedido especifico");
						printf("\nOpcao 6 --- Sobre cancelar algum pedido");	
						printf("\nOpcao 7 --- Motivacao");
						printf("\nOpcao 8 --- Sair do menu ajuda");
						printf("\nOpcao: ");
						scanf("%i",&opc);
						
						system("cls");
						
						switch(opc)
						{
							case 1:
							{
								printf("Nesta opcao voce podera inserir qualquer cliente sendo ele prioritario ou nao.\n");
								printf("no final da fila.\n");
								printf("\n");
								system("pause");
								system("cls");
								break;
						
							}
							
							case 2:
							{
								printf("Nesta opcao voce podera inserir qualquer cliente no inicio da fila dos nao prioritarios.\n");
								printf("\n");
								system("pause");
								system("cls");
								break;
							}
							
							case 3:
							{
								printf("Nesta opcao voce podera inserir qualquer cliente no inicio da fila dos  prioritarios.\n");
								printf("\n");
								system("pause");
								system("cls");
								break;
							}
							
							case 4:
							{
								printf("Nesta opcao voce podera quais sao os pedidos da sua loja\n");
								printf("em uma ordem de prioritarios e nao prioritarios.\n");
								printf("\n");
								system("pause");
								system("cls");
								break;
							}
							
							case 5:
							{
								printf("Muitas vezes sua fila pode estar muito cheia e voce quer encontrar um pedido especifico\n");
								printf("Nesta opcao voce podera verificar o pedido do cliete sem precisar ficar procurando.\n");
								printf("\n");
								system("pause");
								system("cls");
								break;
							}
							
							case 6:
							{
								printf("Quando algum cliente cancelar o pedido ou for atendido com sucesso\n");
								printf("voce pode tirar o pedido da fila usando essa opcao.\n");
								printf("\n");
								system("pause");
								system("cls");
								break;
							}
							
							case 7:
							{
								printf("A motivacao para escolher esse nicho foi porque eu trabalho em um acougue\n");
								printf("e nesse acougue tem um produto chamado kit mistura, na qual esta sendo vendido por\n");
								printf("marketing digital, dai eu pensei em fazer uma plataforma para os clientes pedirem e ir\n");
								printf("direto para o acogue, porem nao tenho conhecimento suficiente para desenvolver essa plataforma.\n");
								printf("Entao pensei em comecar com o que ja sei, e fiz esse software pensando em um acogueiro \n");
								printf("recebendo os pedidos e excluindo os que ja foram feitos.\n");
								printf("\n");
								system("pause");
								system("cls");
								
								break;
							}
							
							system("cls");
						}
					}while(opc != 8);
				
					system("cls");
					break;
				}
					
					

			case 8: {
				exit(0);
				break;
			}
		}

	} while(true);

	system("pause");
}

//Link para youtube
//https://www.youtube.com/watch?v=slObw47CG0g
