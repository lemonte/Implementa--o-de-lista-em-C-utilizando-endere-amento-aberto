#include "listas.h"

// FUNCOES DA LISTA

void inicializaLista(TNo *l, int tamanho_lista)
{
	int i;
	for (i = 0; i < tamanho_lista; i++)
	{
		l[i].flag = 0;
		l[i].valor = -1;
	}
}

int gerarHash(int entrada, int tamanho_vetor)
{ // funcao para gerar valor hash do tipo inteiro
	return ((entrada) % tamanho_vetor);
}

int colisao(int entrada, int tamanho)
{
	return 1 + gerarHash(entrada, tamanho - 1);
}

int reHash(int entrada, int hash, int tamanho_lista)
{
	return gerarHash((colisao(entrada, tamanho_lista) + hash), tamanho_lista);
}

int inserirElemento()
{
	int entrada = -1;
	scanf(" %d", &entrada);
	return entrada;
}

void adicionarElementoNaLista(TNo *l, int tamanho_lista, int entrada)
{
	int hash = gerarHash(entrada, tamanho_lista);
	if (l[hash].valor != -1)
	{
		hash = colisao(entrada, tamanho_lista);
	}
	while (l[hash].valor != -1)
	{
		hash = reHash(entrada, hash, tamanho_lista);
	}
	l[hash].flag = 1;
	l[hash].valor = entrada;
}

void buscarElementoNaLista(TNo *lista, int tamanho_lista)
{
	printf("Digite o elemento que deseja buscar: ");
	int entrada = inserirElemento();
	int hash = gerarHash(entrada, tamanho_lista);
	if (lista[hash].flag == 0)
	{
		printf("Elemento nao encontrado na lista");
		return;
	}
	if (lista[hash].valor == entrada)
	{
		printf("\n");
		printf("posicao do vetor -> %d |||", hash);
		printf("valor -> %d", lista[hash].valor);
		printf("\n");
		return;
	}
	hash = colisao(entrada, tamanho_lista);
	if (lista[hash].valor == entrada)
	{
		printf("\n");
		printf("posicao do vetor -> %d |||", hash);
		printf("valor -> %d", lista[hash].valor);
		printf("\n");
		return;
	}
	while (lista[hash].flag != 0)
	{
		if (lista[hash].valor == entrada)
		{
			printf("\n");
			printf("posicao do vetor -> %d |||", hash);
			printf("valor -> %d", lista[hash].valor);
			printf("\n");
			return;
		}
		hash = reHash(entrada, hash, tamanho_lista);
	}
	printf("##### ELEMENTO NAO ENCONTRADO DA LISTA #######");
	return;
}

void removeElementoDaLista(TNo *lista, int tamanho_lista)
{
	printf("Digite o elemento que deseja remover: ");
	int entrada = inserirElemento();
	int hash = gerarHash(entrada, tamanho_lista);
	if (lista[hash].flag == 0)
	{
		printf("Elemento nao encontrado na lista");
		return;
	}
	if (lista[hash].valor == entrada)
	{
		printf("\n");
		printf("posicao do vetor -> %d |||", hash);
		printf("valor -> %d", lista[hash].valor);
		printf("\n");
		printf("##### ELEMENTO REMOVIDO DA LISTA #######");
		printf("\n");
		lista[hash].valor = -1;
		return;
	}
	hash = colisao(entrada, tamanho_lista);
	if (lista[hash].valor == entrada)
	{
		printf("\n");
		printf("posicao do vetor -> %d |||", hash);
		printf("valor -> %d", lista[hash].valor);
		printf("\n");
		printf("##### ELEMENTO REMOVIDO DA LISTA #######");
		printf("\n");
		lista[hash].valor = -1;
		return;
	}
	while (lista[hash].flag != 0)
	{
		if (lista[hash].valor == entrada)
		{
			printf("\n");
			printf("posicao do vetor -> %d |||", hash);
			printf("valor -> %d", lista[hash].valor);
			printf("\n");
			printf("##### ELEMENTO REMOVIDO DA LISTA #######");
			printf("\n");
			lista[hash].valor = -1;
			return;
		}
		hash = reHash(entrada, hash, tamanho_lista);
	}
	printf("##### ELEMENTO NAO ENCONTRADO DA LISTA #######");
	return;
}