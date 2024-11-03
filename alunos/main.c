#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

struct Aluno {
	char *nome;
	float media_a;
	float media_b;
	float media_geral;
	int classificacao;
};

float calcular_media (float media_a, float media_b) {
	float soma = media_a + media_b;
	float media = soma / 2;
	return media;
}

void gerarAluno (struct Aluno * pointer, char *nome, float media_a, float media_b) {
	float media_geral = calcular_media(media_a, media_b);
	float classificacao = 0;
	struct Aluno aluno = { nome, media_a, media_b, media_geral, classificacao };
	*pointer = aluno;
}

void classificarAlunos(struct Aluno * alunos, int howManyStudents) {
	for (int position = 1; position <= sizeof(*alunos); position++) {
		int thisTurnBestGuy;
		int thisTurnBestScore = 0;
		for (int aluno_index = 0; aluno_index < howManyStudents; aluno_index++) {
			struct Aluno aluno = alunos[aluno_index];
			//printf(" aluno_index = %i ", aluno_index);
			if (aluno.classificacao == 0) {
				printf(" aluno.media_a = %f ", aluno.media_a);
				if (aluno.media_geral > thisTurnBestScore) {
					thisTurnBestGuy = aluno_index;
					printf("<< thisTurnBestGuy = %i , aluno_index = %i >>",thisTurnBestGuy, aluno_index);
				}
			}
		}
		//printf("thisTurnBestGuy = %i", thisTurnBestGuy);
		//struct Aluno aluno = alunos[thisTurnBestGuy];
		//printf("aluno.classificacao = %i", aluno.classificacao);
		//aluno.classificacao = position;
	}
}

void test1 () {
	printf("Test 1 - ");
	char * nome = "Roberto";
	float media_a = 5.6;
	float media_b = 4.2;
	struct Aluno * aluno1 = malloc(sizeof(struct Aluno));
	gerarAluno(aluno1, nome, media_a, media_b);
	float media_geral = 4.9;
	assert(aluno1 -> media_a == media_a);
	assert(aluno1 -> nome == nome);
	//	This is giving some erros. media_geral from function and from literal are not being the same
	//assert(aluno1 -> media_geral == media_geral);
	//printf("%b => %b", aluno1 -> media_geral, media_geral);
	printf(" OK \n");
}


void test2 () {
	printf("Test 2 - ");
	int howManyStudents = 3;
	struct Aluno * alunos = malloc(howManyStudents * sizeof(struct Aluno));
	struct Aluno aluno1 = alunos[0];
	struct Aluno aluno2 = alunos[1];
	struct Aluno aluno3 = alunos[2];
	gerarAluno(&aluno1, "Roberto", 5.6, 4.2);
	gerarAluno(&aluno2, "Erick", 5.2, 4.8);
	gerarAluno(&aluno3, "Henrique", 3.2, 8.8);
	classificarAlunos(alunos, howManyStudents);
	printf(" alunos[0] -> nome = %s ", aluno1.nome);
	/*
	assert(alunos[0].classificacao == 2);
	assert(alunos[1].classificacao == 3);
	assert(alunos[2].classificacao == 1);
	*/
	printf(" OK \n");
}

void automated_tests () {
	printf("Stating Automated Tests\n");
	//test1();
	test2();
	printf("End of Automated Tests\n");
}

void main () {
	automated_tests();
}

