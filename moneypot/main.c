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
	int requestedValue = 30000;
	int entryValue = 3000;
	struct OrderRequest loan1 = { requestedValue, entryValue, &client1 };
	struct OrderResponse response = requestLoan(loan1);
	assert(!response.approved);
	printf("OK \n");
}

void autotest () {
	printf("Running automatic tests...\n");
	test1();
	test2();
	printf("Automatic Tests completed\n");
}

void play_interactive () {
}

void main (int argc, char *argv[]) {
	autotest();
	exit(EXIT_SUCCESS);
}


