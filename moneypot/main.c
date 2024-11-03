#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

// Estrutura para armazenar informações sobre o cliente
struct Customer {
	char *name;	      // Nome do cliente
	int incomePerMonth;      // Renda mensal do cliente
	bool isGoodPayer;	// Indicador se o cliente é um bom pagador
	bool hasStability;       // Indicador se o cliente possui estabilidade financeira
};

// Estrutura para armazenar os detalhes de uma solicitação de empréstimo
struct OrderRequest {
	int requestedValue;      // Valor solicitado para o empréstimo
	int entryValue;	  // Valor de entrada para o empréstimo
	struct Customer* requester;  // Ponteiro para o cliente solicitante
};

// Estrutura para armazenar a resposta para uma solicitação de empréstimo
struct OrderResponse {
	struct OrderRequest* request;  // Ponteiro para a solicitação original
	bool approved;		 // Indicador de aprovação do empréstimo
};

// Regras para avaliar uma solicitação de empréstimo

// Verifica se o valor solicitado é inferior a 30% da renda mensal
bool rule1 (struct OrderRequest request) {
	int tertia = request.requester -> incomePerMonth * 30 / 100;
	bool pass = request.requestedValue < tertia;
	return pass;
}

// Verifica se o cliente é um bom pagador
bool rule2 (struct OrderRequest request) {
	bool pass = request.requester -> isGoodPayer;
	return pass;
}

// Verifica se o cliente tem estabilidade financeira
bool rule3 (struct OrderRequest request) {
	bool pass = request.requester -> hasStability;
	return pass;
}

// Verifica se o valor solicitado é inferior a 10 vezes o valor de entrada
bool rule4 (struct OrderRequest request) {
	bool pass = request.requestedValue < 10 * request.entryValue;
	return pass;
}

// Função principal para processar a solicitação de empréstimo
struct OrderResponse requestLoan (struct OrderRequest request) {
	bool r1 = rule1(request);    // Verifica se passa na regra 1
	bool r2 = rule2(request);    // Verifica se passa na regra 2
	bool r3 = rule3(request);    // Verifica se passa na regra 3
	bool r4 = rule4(request);    // Verifica se passa na regra 4
	bool approved = r1 && r2 && r3 && r4;  // Aprova somente se passar em todas as regras
	struct OrderResponse response = { &request, approved };
	return response;
}

// Função de teste para verificar regras com valores predefinidos
void test1 () {
	printf("Running test1... \t");
	char name[30] = "John Smith";
	int incomePerMonth = 300000;
	bool isGoodPayer = true;
	bool hasStability = true;
	struct Customer client1 = { name, incomePerMonth, isGoodPayer, hasStability };
	
	// Subteste 1: cliente atendendo a todas as condições de aprovação
	int requestedValue1 = 30000;
	int entryValue1 = 3500;
	struct OrderRequest loan1 = { requestedValue1, entryValue1, &client1 };
	struct OrderResponse response1 = requestLoan(loan1);
	assert(response1.approved);  // Deve ser aprovado
	
	// Subteste 2: valor de entrada não atende a regra 4
	int requestedValue2 = 30000;
	int entryValue2 = 2500;
	struct OrderRequest loan2 = { requestedValue2, entryValue2, &client1 };
	struct OrderResponse response2 = requestLoan(loan2);
	assert(!response2.approved);  // Deve ser negado
	printf("OK \n");
}

// Segundo conjunto de testes com diferentes valores e cliente
void test2 () {
	printf("Running test2... \t");
	char name[30] = "Jenipher";
	int incomePerMonth = 1000;
	bool isGoodPayer = true;
	bool hasStability = true;
	struct Customer client1 = { name, incomePerMonth, isGoodPayer, hasStability };
	
	// Subteste 1: valor solicitado excede a capacidade do cliente
	int requestedValue1 = 30000;
	int entryValue1 = 3000;
	struct OrderRequest loan1 = { requestedValue1, entryValue1, &client1 };
	struct OrderResponse response1 = requestLoan(loan1);
	assert(!response1.approved);  // Deve ser negado
	
	// Subteste 2: valores dentro das regras estabelecidas
	int requestedValue2 = 30;
	int entryValue2 = 5;
	struct OrderRequest loan2 = { requestedValue2, entryValue2, &client1 };
	struct OrderResponse response2 = requestLoan(loan2);
	assert(response2.approved);  // Deve ser aprovado
	printf("OK \n");
}

// Executa todos os testes automaticamente
void autotest () {
	printf("Running automatic tests...\n");
	test1();
	test2();
	printf("Automatic Tests completed\n");
}

// Função auxiliar que pergunta uma resposta de sim/não ao usuário
bool ask_bool(const char *question) {
	bool boolAnswer = false;
	bool goodAnswer = false;
	int attempts = 0;
	
	// Limpeza de buffer de entrada para evitar problemas com quebras de linha
	while (getchar() != '\n');
	while (!goodAnswer && attempts < 4) {
		printf("%s [y/n]: ", question);
		char charAnswer = getchar();
		
		if (charAnswer == 'y' || charAnswer == 'Y') {
			boolAnswer = true;
			goodAnswer = true;
		} else if (charAnswer == 'n' || charAnswer == 'N') {
			boolAnswer = false;
			goodAnswer = true;
		} else {
			printf("Invalid answer. Please respond with 'y' or 'n'.\n");
			attempts++;
		}
	}
	if (!goodAnswer) {
		printf("Maximum attempts reached. Assuming 'no'.\n");
	}
	return boolAnswer;
}

// Função interativa para coletar dados do usuário e avaliar a solicitação de empréstimo
void play_interactive() {
    struct Customer client;

    // Pergunta o nome do cliente e armazena
    printf("What is your name? ");
    scanf("%99s", client.name);  // Garantir que o nome não exceda o tamanho do buffer

    // Pergunta se o cliente é bom pagador
    client.isGoodPayer = ask_bool("Are you a good payer?");

    // Pergunta se o cliente tem estabilidade financeira
    client.hasStability = ask_bool("Do you have a good stability?");

    // Pergunta sobre a renda mensal do cliente e armazena o valor
    printf("What is your current income per month? ");
    scanf("%d", &client.incomePerMonth);  // Captura corretamente a renda mensal

    // Solicita valores para o pedido de empréstimo
    int requestedValue, entryValue;
    printf("Enter the requested loan value: ");
    scanf("%d", &requestedValue);

    printf("Enter the entry value: ");
    scanf("%d", &entryValue);

    // Cria a solicitação de empréstimo e verifica aprovação
    struct OrderRequest request = {requestedValue, entryValue, &client};
    struct OrderResponse response = requestLoan(request);

    // Exibe o resultado da avaliação de empréstimo ao usuário
    const char *approvationString = response.approved ? "Approved" : "Denied";
    printf("Your loan request was %s.\n", approvationString);
}

// Função principal para executar testes automáticos ou o modo interativo
void main (int argc, char *argv[]) {
	bool autotest_mode = true;
	bool interactive_mode = true;
	if (autotest_mode) {
		autotest();
	}
	if (interactive_mode) {
		play_interactive();
	}
	exit(EXIT_SUCCESS);
}

