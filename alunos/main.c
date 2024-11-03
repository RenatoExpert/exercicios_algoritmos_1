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

void criarAlunos () {
	struct Aluno alunos[] = {
		gerarAluno("Roberto", 5.6, 4.2),
		gerarAluno("Erick", 5.2, 4.8),
		gerarAluno("Henrique", 3.2, 8.8)
	};
}

void main () {
	criarAlunos();
}

