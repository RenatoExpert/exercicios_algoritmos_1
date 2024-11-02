programa {
	inclua biblioteca Util
	funcao inteiro ask (cadeia pergunta, cadeia opcoes[]) {
		inteiro answer
		logico valid_answer = falso
		enquanto (nao valid_answer) {
			se (nao pergunta) {
				escreva(pergunta + "\n")
			}
			inteiro length = Util.numero_elementos(opcoes)
			//	Print Options
			para (inteiro i = 0; i < length; i++) {
				cadeia opcao = opcoes[i]
				cadeia text = "[ " + (i+1) + " ]  " + opcao + "\n"
				escreva(text)
			}
			//	Answer
			leia(answer)
			se (answer <= length) {
				cadeia answer_label = opcoes[answer - 1]
				escreva(answer_label + "\n")
				valid_answer = verdadeiro
			} senao {
				escreva("Opção Invalida -- Invalid Option -- 不正な -- Ungültige Auswahl")
			}
		}
		retorne answer - 1
	}

	funcao inteiro choose_language () {
		cadeia pergunta = ""
		cadeia opcoes[4]
		opcoes[0] = "Português"
		opcoes[1] = "English"
		opcoes[2] = "日本語"
		opcoes[3] = "Deutsch"
		retorne ask(pergunta, opcoes)
	}

	funcao preface (inteiro tonge) {
		se (tonge == 0) {
			escreva("Iniciando aventura...\n")
			escreva("Leia as instruções com atenção e selecione as respostas utilizando os números apresentados\n")
		} senao se (tonge == 1) {
			escreva("Starting a new adventure...\n")
			escreva("Read the instructions carefully and choose the answer by picking its respective number\n")
		} senao se (tonge == 2) {
			escreva("新しい冒険を始める\n")
			escreva("説明書を読んでください、数字で答えを選んでください\n")
		} senao se (tonge == 3) {
			escreva("Eine neue Geschichte beginnt...\n")
			escreva("Lesen Sie die Anleitung sorgfältig und wählen Sie die Antwort mit der entsprechenden Nummer\n")
		}
	}

	funcao inteiro choose_path (inteiro tonge) {
		inteiro answer
		cadeia pergunta
		cadeia opcoes[3]
		se (tonge == 0) {
			pergunta = "Escolha qual caminho seguir"
			opcoes[0] = "Caminho das sombras"
			opcoes[1] = "Caminho da luz"
			opcoes[2] = "Caminho das criaturas"
		} senao se (tonge == 1) {
			pergunta = "Choose which path to follow"
			opcoes[0] = "Path of Shadows"
			opcoes[1] = "Path of Light"
			opcoes[2] = "Path of Creatures"
		} senao se (tonge == 2) {
			pergunta = "どの道を選びますか"
			opcoes[0] = "影の道"
			opcoes[1] = "光の道"
			opcoes[2] = "生き物の道"
		} senao se (tonge == 3) {
			pergunta = "Wähle den Weg, dem du folgen möchtest"
			opcoes[0] = "Weg der Schatten"
			opcoes[1] = "Weg des Lichts"
			opcoes[2] = "Weg der Kreaturen"
		}
		answer = ask(pergunta, opcoes)
		retorne answer
	}

	funcao logico ask_charade (inteiro tonge, inteiro path) {
		inteiro answer
		cadeia pergunta
		cadeia opcoes[3]
		se (path == 0) {
			se (tonge == 0) {
				escreva("Seguindo pelo caminho das sombras, você encontrou uma criatura mágica guardiã do caminho, que exige um enigma para deixá-lo passar.\n")
				pergunta = "\"Quem sou eu? Tenho olhos, mas não vejo. Tenho boca, mas não falo. O que sou?\""
				opcoes[0] = "Uma caneca"
				opcoes[1] = "Uma caveira"
				opcoes[2] = "Uma borboleta"
			} senao se (tonge == 1) {
				escreva("Following the path of shadows, you encounter a magical creature guarding the way, which requires a riddle to let you pass.\n")
				pergunta = "\"Who am I? I have eyes but cannot see. I have a mouth but cannot speak. What am I?\""
				opcoes[0] = "A mug"
				opcoes[1] = "A skull"
				opcoes[2] = "A butterfly"
			} senao se (tonge == 2) {
				escreva("影の道を進むと、道を守る魔法の生き物に出会い、通るためには謎を解く必要があります。")
				pergunta = "私は誰でしょう？目があっても見えない。口があっても話せない。私は何でしょう？"
				opcoes[0] = "マグカップ"
				opcoes[1] = "頭蓋骨"
				opcoes[2] = "蝶"
			} senao se (tonge == 3) {
				escreva("Auf dem Weg der Schatten triffst du auf ein magisches Wesen, das den Weg bewacht und ein Rätsel verlangt, um dich passieren zu lassen.\n")
				pergunta = "\"Wer bin ich? Ich habe Augen, aber ich sehe nicht. Ich habe einen Mund, aber ich spreche nicht. Was bin ich?\""
				opcoes[0] = "Ein Becher"  // Uma caneca
				opcoes[1] = "Ein Schädel"  // Uma caveira
				opcoes[2] = "Ein Schmetterling"  // Uma borboleta
			}
		} senao se (path == 1) {
			se (tonge == 0) {
				escreva("Esse caminho é iluminado por raios de sol que filtram entre as copas das árvores\n")
				pergunta = "Você encontrou uma ponte quebrada sobre um rio turbulento. O que você vai fazer?"
				opcoes[0] = "Procurar um desvio seguro"
				opcoes[1] = "Tentar atravessar a ponte quebrada"
			} senao se (tonge == 1) {
				escreva("This path is lit by sunlight filtering through the treetops\n")
				pergunta = "You found a broken bridge over a rushing river. What will you do?"
				opcoes[0] = "Look for a safe detour"
				opcoes[1] = "Try to cross the broken bridge"
			} senao se (tonge == 2) {
				escreva("この道は木々の間から差し込む日差しで照らされています\n")
				pergunta = "激しい川の上に壊れた橋を見つけました。どうしますか？"
				opcoes[0] = "安全な迂回路を探す"
				opcoes[1] = "壊れた橋を渡ろうとする"
			} senao se (tonge == 3) {
				escreva("Dieser Weg wird von Sonnenstrahlen erleuchtet, die durch die Baumkronen scheinen\n")
				pergunta = "Du hast eine kaputte Brücke über einen reißenden Fluss gefunden. Was wirst du tun?"
				opcoes[0] = "Einen sicheren Umweg suchen"
				opcoes[1] = "Versuchen, die kaputte Brücke zu überqueren"
			}
		} senao se (path == 2) {
			se (tonge == 0) {
				escreva("Esse caminho é repleto de sons estranhos e pegadas misteriosas no chão.\n")
				pergunta = "Você se depara com uma criatura mágica adormecida bloqueando o caminho. O que você vai fazer?"
				opcoes[0] = "Acordar a criatura"
				opcoes[1] = "Passar pela criatura com cuidado"
			} senao se (tonge == 1) {
				escreva("This path is filled with strange sounds and mysterious footprints on the ground.\n")
				pergunta = "You encounter a sleeping magical creature blocking the way. What will you do?"
				opcoes[0] = "Wake the creature"
				opcoes[1] = "Carefully pass by the creature"
			} senao se (tonge == 2) {
				escreva("この道には奇妙な音と地面に不思議な足跡があります。\n")
				pergunta = "道を塞いでいる眠っている魔法の生き物に出会いました。どうしますか？"
				opcoes[0] = "生き物を起こす"
				opcoes[1] = "慎重に生き物のそばを通り過ぎる"
			} senao se (tonge == 3) {
				escreva("Dieser Weg ist voller seltsamer Geräusche und mysteriöser Fußspuren auf dem Boden.\n")
				pergunta = "Du triffst auf ein schlafendes magisches Wesen, das den Weg versperrt. Was wirst du tun?"
				opcoes[0] = "Das Wesen wecken"
				opcoes[1] = "Vorsichtig an dem Wesen vorbeigehen"
			}
		}
		answer = ask(pergunta, opcoes)
		logico didWin = answer == 1
		retorne didWin
	}

	funcao lostMessage (inteiro tonge) {
		se (tonge == 0) {
			escreva("Sua decisão não foi acertiva e ocasionou em uma fatalidade.\n")
			escreva("Você perdeu o jogo.\n")
		} senao se (tonge == 1) {
			escreva("Your decision was not correct and led to a fatal outcome.\n")
			escreva("You have lost the game.\n")
		} senao se (tonge == 2) {
			escreva("あなたの決断は正しくなく、致命的な結果を引き起こしました。\n")
			escreva("あなたはゲームに負けました。\n")
		} senao se (tonge == 3) {
			escreva("Deine Entscheidung war nicht richtig und führte zu einem fatalen Ausgang.\n")
			escreva("Du hast das Spiel verloren.\n")
		}
	}

	funcao inteiro getScore (inteiro path) {
		inteiro score
		escolha (path) {
			caso 0:
				score = 100
				pare
			caso 1:
				score = 50
				pare
			caso 2:
				score = 75
				pare
			caso contrario:
				escreva("Opção Inválida \n")
				pare
		}
		retorne score
	}

	funcao result (inteiro tonge, inteiro path, logico didWin) {
		se (didWin) {
			inteiro score = getScore(path)
			se (tonge == 0) {
				escreva("Você fez uma boa decisão e finalizou o jogo com " + score + " pontos .\n")
			} senao se (tonge == 1) {
				escreva("You made a good decision and finished the game with " + score + " points.\n")
			} senao se (tonge == 2) {
				escreva("あなたは良い決断を下し、" + score + "ポイントでゲームを終了しました。\n")
			} senao se (tonge == 3) {
				escreva("Sie haben eine gute Entscheidung getroffen und das Spiel mit " + score + " Punkten beendet.\n")
			}
		} senao {
			lostMessage(tonge)
		}
	}


	funcao endGame (inteiro tonge) {
		se (tonge == 0) {
			escreva("Fim do jogo.\n")
		} senao se (tonge == 1) {
			escreva("End of the game.\n")
		} senao se (tonge == 2) {
			escreva("ゲームの終了です。\n")
		} senao se (tonge == 3) {
			escreva("Spielende.\n")
		}
	}

	funcao inicio () {
		inteiro tonge = choose_language()
		preface(tonge)
		inteiro path = choose_path(tonge)
		logico didWin = ask_charade(tonge, path)
		result(tonge, path, didWin)
		endGame(tonge)
	}
}

