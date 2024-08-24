//	Consulte o arquivo LEIAME.md

programa {
	//	Importando bibliotecas
	inclua biblioteca Util
	inclua biblioteca Matematica

	//	Definindo algumas opções gerais do programa
	inteiro espaco = 0
	inteiro parede = 1
	inteiro tesouro = 2
	inteiro armadilha = 3

	//	Definindo "sprites"
	//	cadeia exibicao_tesouro = "ロ"
	//	inicialmente, estava exibindo o tesouro com o caractere acima
	//	Alterei para espaço apenas para adequar aos requisitos dados pelo professor	
	cadeia exibicao_espaco = "  "
	cadeia exibicao_parede = "キ"
	cadeia exibicao_tesouro = exibicao_espaco
	cadeia exibicao_armadilha = exibicao_espaco
	cadeia exibicao_personagem = "シ"

	funcao inicio() {
		escreva("Iniciando... \n")

		//	Desenhando mapa com apenas paredes
		escreva("Gerando partida... 1/6 \n")
		inteiro mapa[5][5]
		para(inteiro i = 0; i < 5; i++) {
			para(inteiro j = 0; j < 5; j++) {
				mapa[i][j] = parede
			}
		}

		//	Sorteando uma posição para o tesouro
		escreva("Gerando partida... 2/6 \n")
		inteiro tesouro_x = Util.sorteia (0, 4)
		inteiro tesouro_y = Util.sorteia (0, 4)
		mapa[tesouro_y][tesouro_x] = tesouro

		//	Sorteando posicao inicial
		//	Esse loop evita que o tesouro e o personagem sejam sorteados muito próximos um do outro
		escreva("Gerando partida... 3/6 \n")
		inteiro inicio_x
		inteiro inicio_y
		inteiro proximidade_minima = 2
		logico teste_x = verdadeiro
		logico teste_y = verdadeiro
		enquanto (teste_x ou teste_y) {
			inicio_x = Util.sorteia (0, 4)
			inicio_y = Util.sorteia (0, 4)
			teste_x = Matematica.valor_absoluto(inicio_x - tesouro_x) < proximidade_minima
			teste_y = Matematica.valor_absoluto(inicio_y - tesouro_y) < proximidade_minima
		}

		//	Simulando trilha
		escreva("Gerando partida... 4/6 \n")
		logico trilha_pronta = falso
		inteiro passos
		inteiro caminho[25][2]
		enquanto (nao trilha_pronta) {
			//	Simulando uma trilha aleatória até o tesouro
			//	porém sem gerar alterações no mapa ainda
			inteiro posicao_x = inicio_x
			inteiro posicao_y = inicio_y
			passos = 0
			inteiro maximo_possivel = 25
			inteiro maximo_desejado = 15
			inteiro minimo_desejado = 10
			para (inteiro i = 0; i < maximo_possivel; i++) {
				se (mapa[posicao_y][posicao_x] != tesouro) {
					//	Um bot irá simular um trajeto aleatório até encontrar o tesouro
					passos++
					caminho[i][1] = posicao_x
					caminho[i][0] = posicao_y
					inteiro direcao = Util.sorteia (0, 1)
					//	A direção vai dizer se ele irá mover, nesse turno, no eixo x ou y
					se (direcao == 1) {
						inteiro mover_x = Util.sorteia (-1, 1)
						posicao_x += mover_x
						se (posicao_x < 0) {
							posicao_x = 0
						} se (posicao_x > 4) {
							posicao_x = 4
						}
					} senao {
						inteiro mover_y = Util.sorteia (-1, 1)
						posicao_y += mover_y
						se (posicao_y < 0) {
							posicao_y = 0
						} se (posicao_y > 4) {
							posicao_y = 4
						}
					}
				}
			}
			se (passos < maximo_desejado e passos > minimo_desejado) {
				//	Se a trilha não atender ao padrão de máximo e mínimo de casas vazias
				//	terá de ser redesenhada
				trilha_pronta = verdadeiro
			}
		}

		//  Abrindo os espaços vazios para a trilha
		escreva("Gerando partida... 5/6 \n")
		para (inteiro i = 0; i < passos; i++) {
			mapa[caminho[i][0]][caminho[i][1]] = espaco
		}

		//	Gerando armadilhas
		escreva("Gerando partida... 6/6 \n")
		inteiro armadilhas_presentes = 0
		inteiro armadilhas_desejadas = 5
		enquanto (armadilhas_presentes < armadilhas_desejadas) {
			inteiro sorteia_x = Util.sorteia (0, 4)
			inteiro sorteia_y = Util.sorteia (0, 4)
			se (mapa[sorteia_y][sorteia_x] == parede) {
				mapa[sorteia_y][sorteia_x] = armadilha
				armadilhas_presentes++
			}
		}

		//	Jogando
		escreva("Hora de jogar! \n")
		inteiro posicao_x = inicio_x
		inteiro posicao_y = inicio_y
		enquanto (mapa[posicao_y][posicao_x] != tesouro) {
			//	Criando linhas vazias para ter um efeito análogo a limpar a tela
			para(inteiro s = 0; s < 50; s++) { escreva("\n") }
			//	Borda superior do mapa
			escreva("_______________ \n")
			para(inteiro i = 4; i >= 0; i--) {
				//	Borda esquerda
				cadeia linha = "|"
				para(inteiro j = 0; j < 5; j++) {
					//	Escolhendo um "sprite" para cada posição
					cadeia char = ""
					se ((posicao_y == i) e (posicao_x == j)) {
						char = exibicao_personagem
					} senao {
						inteiro valor = mapa[i][j]
						se (valor == espaco) {
							char = exibicao_espaco
						} se (valor == parede) {
							char = exibicao_parede
						} se (valor == tesouro) {
							char = exibicao_tesouro
						} se (valor == armadilha) {
							char = exibicao_armadilha
						}
					}
					//	Concatenando o sprite à linha
					//	Este espaço é para não desalinhar com os caracteres katakana
					linha = linha + char + " "
				}
				//	Adicionando a borda da direita e trocando de linha
				linha = linha + "| \n"
				escreva(linha)
			}
			//	Borda inferior
			escreva("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾")

			//	Lendo o comando do usuário
			//	e utilizando os controles tradicionais WSAD de jogos
			caracter input
			leia(input)
			se (input == "w") {
				//	Essa lógica evita sair do mapa ou colidir com uma parede
				se (mapa[posicao_y + 1][posicao_x] == espaco ou mapa[posicao_y + 1][posicao_x] == tesouro) {
					posicao_y++
				} se (mapa[posicao_y + 1][posicao_x] == armadilha) {
					posicao_x = inicio_x
					posicao_y = inicio_y
				}
			} se (input == "s") {
				se (mapa[posicao_y - 1][posicao_x] == espaco ou mapa[posicao_y - 1][posicao_x] == tesouro) {
					posicao_y--
				} se (mapa[posicao_y - 1][posicao_x] == armadilha) {
					posicao_x = inicio_x
					posicao_y = inicio_y
				}
			} se (input == "a") {
				se (mapa[posicao_y][posicao_x - 1] == espaco ou mapa[posicao_y][posicao_x - 1] == tesouro) {
					posicao_x--
				} se (mapa[posicao_y][posicao_x - 1] == armadilha) {
					posicao_x = inicio_x
					posicao_y = inicio_y
				}
			} se (input == "d") {
				se (mapa[posicao_y][posicao_x + 1] == espaco ou mapa[posicao_y][posicao_x + 1] == tesouro) {
					posicao_x++
				} se (mapa[posicao_y][posicao_x + 1] == armadilha) {
					posicao_x = inicio_x
					posicao_y = inicio_y
				}
			}
		}
		escreva("Você ganhou! Seu prêmio: 0 reais")
	}
}
