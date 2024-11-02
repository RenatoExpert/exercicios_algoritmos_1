#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Customer {
	char name[30];
	int incomePerMonth;
	bool isGoodPayer;
	bool hasStability;
}

struct LoanOrder {
	int requestedValue;
	int entryValue;
	struct Customer requester;
}

struct OrderResponse {
	struct LoanOrder request;
	bool approved;
}

bool rule1 (struct LoanOrder order) {
	int tertia = order.requester.incomePerMonth * 30 / 100;
	return order.requestedValue < tertia;
}

struct OrderResponse requestLoan (struct LoanOrder request) {
	bool r1 = rule1(request);
	bool response = r1;
	return response;
}

void test1 () {
	printf("Running test1... \t");
	char name[30] = "John Smith";
	int incomePerMonth = 300000;
	bool isGoodPayer = true;
	bool hasStability = true;
	struct Customer client1 = { name, incomePerMonth, isGoodPayer, hasStability };
	int requestedValue = 30000;
	int entryValue = 3000;
	struct LoanOrder loan1 = { requestedValue, entryValue, client1 };
	struct OrderResponse response = requestLoan(loan1);
	assert(response.approved);
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


