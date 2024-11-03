#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

struct Customer {
	char *name;
	int incomePerMonth;
	bool isGoodPayer;
	bool hasStability;
};

struct OrderRequest {
	int requestedValue;
	int entryValue;
	struct Customer* requester;
};

struct OrderResponse {
	struct OrderRequest* request;
	bool approved;
};

bool rule1 (struct OrderRequest request) {
	int tertia = request.requester -> incomePerMonth * 30 / 100;
	bool pass = request.requestedValue < tertia;
	return pass;
}

bool rule2 (struct OrderRequest request) {
	bool pass = request.requester -> isGoodPayer;
	return pass;
}

bool rule3 (struct OrderRequest request) {
	bool pass = request.requester -> hasStability;
	return pass;
}

bool rule4 (struct OrderRequest request) {
	bool pass = request.requestedValue < 10 * request.entryValue;
	return pass;
}

struct OrderResponse requestLoan (struct OrderRequest request) {
	bool r1 = rule1(request);
	bool r2 = rule2(request);
	bool r3 = rule3(request);
	bool r4 = rule4(request);
	bool approved = r1 && r2 && r3 && r4;
	struct OrderResponse response = { &request, approved };
	return response;
}

void test1 () {
	printf("Running test1... \t");
	char name[30] = "John Smith";
	int incomePerMonth = 300000;
	bool isGoodPayer = true;
	bool hasStability = true;
	struct Customer client1 = { name, incomePerMonth, isGoodPayer, hasStability };
	//	Subtest 1
	int requestedValue1 = 30000;
	int entryValue1 = 3500;
	struct OrderRequest loan1 = { requestedValue1, entryValue1, &client1 };
	struct OrderResponse response1 = requestLoan(loan1);
	assert(response1.approved);
	//	Subtest 2
	int requestedValue2 = 30000;
	int entryValue2 = 2500;
	struct OrderRequest loan2 = { requestedValue2, entryValue2, &client1 };
	struct OrderResponse response2 = requestLoan(loan2);
	assert(!response2.approved);
	printf("OK \n");
}

void test2 () {
	printf("Running test2... \t");
	char name[30] = "Jenipher";
	int incomePerMonth = 1000;
	bool isGoodPayer = true;
	bool hasStability = true;
	struct Customer client1 = { name, incomePerMonth, isGoodPayer, hasStability };
	//	Subtest 1
	int requestedValue1 = 30000;
	int entryValue1 = 3000;
	struct OrderRequest loan1 = { requestedValue1, entryValue1, &client1 };
	struct OrderResponse response1 = requestLoan(loan1);
	assert(!response1.approved);
	//	Subtest 2
	int requestedValue2 = 30;
	int entryValue2 = 5;
	struct OrderRequest loan2 = { requestedValue2, entryValue2, &client1 };
	struct OrderResponse response2 = requestLoan(loan2);
	assert(response2.approved);
	printf("OK \n");
}

void autotest () {
	printf("Running automatic tests...\n");
	test1();
	test2();
	printf("Automatic Tests completed\n");
}

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

void play_interactive() {
    struct Customer client;

    // Pergunta o nome do cliente
    printf("What is your name? ");
    scanf("%99s", client.name);  // Garantir que o nome não exceda o tamanho do buffer

    // Pergunta se o cliente é bom pagador
    client.isGoodPayer = ask_bool("Are you a good payer?");

    // Pergunta se o cliente tem estabilidade financeira
    client.hasStability = ask_bool("Do you have a good stability?");

    // Pergunta sobre a renda mensal do cliente
    printf("What is your current income per month? ");
    scanf("%d", &client.incomePerMonth);  // Corrige a leitura de renda mensal

    // Coleta valores para a solicitação do empréstimo
    int requestedValue, entryValue;
    printf("Enter the requested loan value: ");
    scanf("%d", &requestedValue);

    printf("Enter the entry value: ");
    scanf("%d", &entryValue);

    // Cria a solicitação de empréstimo e avalia a resposta
    struct OrderRequest request = {requestedValue, entryValue, &client};
    struct OrderResponse response = requestLoan(request);

    // Exibe o resultado da solicitação
    const char *approvationString = response.approved ? "Approved" : "Denied";
    printf("Your loan request was %s.\n", approvationString);
}

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


