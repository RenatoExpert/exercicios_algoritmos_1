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

struct Aluno gerarAluno (char *nome, float media_a, float media_b) {
	float media_geral = calcular_media(media_a, media_b);
	float classificacao;
	struct Aluno aluno = { nome, media_a, media_b, media_geral, classificacao };
	return aluno;
}

void classificarAlunos(struct Aluno *alunos) {
	for (int position = 1; position <= sizeof(alunos); position++) {
		int thisTurnBestGuy;
		int thisTurnBestScore = 0;
		for (int aluno_index = 0; aluno_index < sizeof(alunos); aluno_index++) {
			struct Aluno aluno = alunos[aluno_index];
			if (aluno.classificacao == 0) {
				if (aluno.media_geral > thisTurnBestScore) {
					thisTurnBestGuy = aluno_index;
				}
			}
		}
		alunos[thisTurnBestGuy].classificacao = position;
	}
}

struct Aluno *criarAlunos (int *num_alunos) {
	*num_alunos = 3;
	struct Aluno *alunos = malloc(*num_alunos * sizeof(struct Aluno));
	alunos[0] = gerarAluno("Roberto", 5.6, 4.2);
	alunos[1] = gerarAluno("Erick", 5.2, 4.8);
	alunos[2] = gerarAluno("Henrique", 3.2, 8.8);
	classificarAlunos(alunos);
	return alunos;
}

void test1 () {
	int num_alunos;
	struct Aluno *alunos = criarAlunos(&num_alunos);
	assert(alunos[0].classificacao == 2);
	assert(alunos[1].classificacao == 3);
	assert(alunos[2].classificacao == 1);
}

void automated_tests () {
	test1();
}

void main () {
	automated_tests();
}

