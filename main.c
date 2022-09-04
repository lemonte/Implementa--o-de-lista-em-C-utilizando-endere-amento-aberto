#include "controlador_lista.h"

// FUNCOES DE TELA
void opcoesMenu()
{
	printf("\n ==== MENU ===== \n");
	printf("\n ==== 1 - INSERIR ===== \n");
	printf("\n ==== 2 - LISTAR ===== \n");
	printf("\n ==== 3 - REMOVER ===== \n");
	printf("\n ==== 4 - CONSULTAR ELEMENTO ===== \n");
	printf("\n ==== 5 - SAIR ===== \n");
}

int tamanho_lista()
{
	printf("Digite o tamanho da lista: ");
	return inserirElemento();
}

void mostrarTodaLista(TNo *l, int tamanho_vetor)
{
	int i = 0;
	for (i = 0; i < tamanho_vetor; i++)
	{
		if (l[i].valor > -1)
		{
			printf("\n");
			printf("posicao do vetor -> %d || ", i);
			printf("valor -> %d || ", l[i].valor);
			printf("flag -> %d || ", l[i].flag);
			printf("\n");
		}
	}
}

int menu(int tamanho_vetor, TNo l[])
{
	int opcao = -1;
	do
	{
		opcoesMenu();
		opcao = inserirElemento();
		switch (opcao)
		{
		case 1:
			printf("Digite o elemento que deseja inserir: ");
			int entrada = inserirElemento();
			adicionarElementoNaLista(l, tamanho_vetor, entrada);
			printf("\n\n##### ELEMENTO ADICIONADO ###### \n\n");
			break;
		case 2:
			printf("\n\n##### LISTA DE ELEMENTOS ######\n\n");
			mostrarTodaLista(l, tamanho_vetor);
			break;
		case 3:
			removeElementoDaLista(l, tamanho_vetor);
			// removerDaLista(l, tamanho_vetor);
			break;
		case 4:
			buscarElementoNaLista(l, tamanho_vetor);
			printf("\n\n##### CONSULTAR ELEMENTO ######\n\n");
			// consultarNaLista(l, tamanho_vetor);
			break;
		case 5:
			printf("Saindo do programa");
			break;
		}
	} while (opcao != 5);
	return 0;
}

void salvarArquivo(TNo l[], int tamanho_lista)
{
	int result;

	// inicinalizando arquivo

	FILE *newArq;
	newArq = fopen("1kchaves.txt", "wt");
	if (newArq == NULL) // Se não conseguiu criar o arquivo
	{
		printf("Problemas na CRIACAO do arquivo\n");
		return;
	}

	// escrever no arquivo os dados

	int i;
	for (i = 0; i < tamanho_lista; i++)
	{ // percorrer toda a lista e salvar os valores no arquivo
		if (l[i].valor != -1)
		{
			result = fprintf(newArq, "%d\n", l[i].valor);
		}
	}
	if (result == EOF)
		printf("Erro na Gravacao\n");
	fclose(newArq);
}

int main(int argc, const char *argv[])
{
	// iniciando arquivo

	FILE *arq;
	char *result;
	int i = 0;
	arq = fopen("1kchaves.txt", "rt");

	// erro na abertura do arquivo
	if (arq == NULL)
	{
		printf("Problemas na abertura do arquivo\n");
		return 1;
	}

	// inserir o tamanho da lista que deseja
	int tamanho_vetor = tamanho_lista();

	// carregar lista na memória
	TNo *l;
	l = (TNo *)malloc(tamanho_vetor * sizeof(TNo));
	inicializaLista(l, tamanho_vetor);

	// inserir todos os dados que deseja inserir na memória
	while (!feof(arq))
	{
		string valor;
		result = fgets(valor, 40, arq);
		int valor_inserir = 0;
		sscanf(valor, "%d", &valor_inserir);
		if (result)
		{
			// printf("%d", valor_inserir);
			adicionarElementoNaLista(l, tamanho_vetor, valor_inserir); // adicionando elemento na lista
			printf("%d \n", valor_inserir);
		}
	}
	fclose(arq);										 // fechando o arquivo
	menu(tamanho_vetor, l);					 // mostrando o menu
	salvarArquivo(l, tamanho_vetor); // salvando no arquivo
	return 0;
}
