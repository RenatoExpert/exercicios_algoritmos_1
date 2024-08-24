//  Jogue usando https://portugol.dev/
programa {
  inclua biblioteca Util
  inclua biblioteca Matematica
  inteiro tesouro = 2
  inteiro parede = 1
  inteiro espaco = 0
  funcao inicio() {
    //  Desenhando mapa vazio
    inteiro mapa[5][5]
    para(inteiro i = 0; i < 5; i++) {
      para(inteiro j = 0; j < 5; j++) {
        mapa[i][j] = parede
      }
    }
    //  Criando tesouro
    inteiro tesouro_x = Util.sorteia (0, 4)
    inteiro tesouro_y = Util.sorteia (0, 4)
    mapa[tesouro_y][tesouro_x] = tesouro
    //  Sortear posicao original
    inteiro inicio_x = tesouro_x
    inteiro inicio_y = tesouro_y
    enquanto (Matematica.valor_absoluto(inicio_x - tesouro_x) < 2 e Matematica.valor_absoluto(inicio_y - tesouro_y) < 2) {
      inicio_x = Util.sorteia (0, 4)
      inicio_y = Util.sorteia (0, 4)
    }
    //  Simulando trilha
    logico trilha_pronta = falso
    inteiro passos
    inteiro caminho[25][2]
    enquanto (nao trilha_pronta) {
      inteiro posicao_x = inicio_x
      inteiro posicao_y = inicio_y
      passos = 0
      para (inteiro i = 0; i < 25; i++) {
        se (mapa[posicao_y][posicao_x] != tesouro) {
          passos++
          caminho[i][1] = posicao_x
          caminho[i][0] = posicao_y
          inteiro direcao = Util.sorteia (0, 1)
          se (direcao == 1) {
            inteiro mover_x = Util.sorteia (-1, 1)
            posicao_x += mover_x
            se(posicao_x < 0) {
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
      se (passos < 25 e passos > 5) {
        trilha_pronta = verdadeiro
      }
    }
    //  Pintando trilha
    para (inteiro i = 0; i < passos; i++) {
      escreva(i)
      mapa[caminho[i][0]][caminho[i][1]] = espaco
    }
    //  Jogando
    inteiro posicao_x = inicio_x
    inteiro posicao_y = inicio_y
    enquanto (mapa[posicao_y][posicao_x] != tesouro) {
      para(inteiro s = 0; s < 50; s++) { escreva("\n") }
      escreva("_______________ \n")
      para(inteiro i = 4; i >= 0; i--) {
        cadeia linha = "|"
        para(inteiro j = 0; j < 5; j++) {
          cadeia char = ""
          se((posicao_y == i) e (posicao_x == j)) {
            char = "シ"
          } senao {
            inteiro valor = mapa[i][j]
            se (valor == 0) {
              char = "  "
            } se (valor == 1) {
              char = "キ"
            } se (valor == 2) {
              char = "ロ"
            }
          }
          linha = linha + char + " "
        }
        escreva(linha + "| \n")
      }
      escreva("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾")
      caracter input
      leia(input)
      se (input == "w") {
          se (mapa[posicao_y + 1][posicao_x] == espaco ou mapa[posicao_y + 1][posicao_x] == tesouro) {
            posicao_y++
          }
      } se (input == "s") {
          se (mapa[posicao_y - 1][posicao_x] == espaco ou mapa[posicao_y - 1][posicao_x] == tesouro) {
            posicao_y--
          }
      } se (input == "a") {
          se (mapa[posicao_y][posicao_x - 1] == espaco ou mapa[posicao_y][posicao_x - 1] == tesouro) {
            posicao_x--
          }
      } se (input == "d") {
          se (mapa[posicao_y][posicao_x + 1] == espaco ou mapa[posicao_y][posicao_x + 1] == tesouro) {
            posicao_x++
          }
      }
    }
    escreva("Você ganhou! Seu prêmio: 0 reais")
  }
}
