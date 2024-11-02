#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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

struct OrderResponse requestLoan (struct OrderRequest request) {
	bool r1 = rule1(request);
	struct Customer *customer = request.requester;
	printf("customer.incomePerMonth %d", customer -> incomePerMonth);
	printf("request.requestedValue %d", request.requestedValue);
	bool approved = r1;
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
	printf("income %d \n", client1.incomePerMonth);
	int requestedValue = 30000;
	int entryValue = 3000;
	struct OrderRequest loan1 = { requestedValue, entryValue, &client1 };
	struct OrderResponse response = requestLoan(loan1);
	//assert(response.approved);
	printf("OK \n");
}

void autotest () {
	printf("Running automatic tests...\n");
	test1();
	printf("Automatic Tests completed\n");
}

void play_interactive () {
}

void main (int argc, char *argv[]) {
	autotest();
	exit(EXIT_SUCCESS);
}


