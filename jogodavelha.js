function main() {
    // Criar o tabuleiro e jogadores, zerar as variaveis.
    // 
    // 0: Posição vazia
    // 1: Jogada na posição do jogador 1
    // 2: Jogada na posição do jogador 2
    var velha;
    var haVencedor;

    haVencedor = 0;
    var tabuleiro = Array(9);

    // Limpar/Zerar o tabuleiro
    var index;

    for (index = 0; index <= 8; index++) {
        tabuleiro[index] = 0;
    }
    var jogador1;

    jogador1 = "Jogador1";
    var jogador2;

    jogador2 = "Jogador2";
    var jogada;

    // iniciar o jogo, definir quem joga primeiro
    var jogadorDaVez;

    jogadorDaVez = 1;
    var linha;
    var coluna;
    var resultadoValidaTabuleiro;

    // Anotar/registrar a jogada do primeiro jogador
    velha = 1;
    do {
        console.log (tabuleiro[0].toString() + tabuleiro[1] + tabuleiro[2]);
        console.log (tabuleiro[3].toString() + tabuleiro[4] + tabuleiro[5]);
        console.log (tabuleiro[6].toString() + tabuleiro[7] + tabuleiro[8]);
        jogada = "";
        console.log ("Digite a posição da sua peça JOGADOR " + jogadorDaVez);
        jogada = window.prompt('Enter a value for jogada');
        if (validaposicao(jogada)) {

            // Simula a função Serial.parseInt() do Arduino
            linha = parseInt(jogada.charAt(0));
            coluna = parseInt(jogada.charAt(2));
            console.log ("Linha:" + linha + "; Coluna:" + coluna);

            // verificar se a posição 'jogada' é válida
            // Verificar jogada vencedora nas linhas
            // Converter a jogada texto em dois inteiros linha e colunas
            if (tabuleiro[3 * linha + coluna] == 0) {
                tabuleiro[3 * linha + coluna] = jogadorDaVez;
                resultadoValidaTabuleiro = validaTabuleiro(tabuleiro, jogadorDaVez);
                if (resultadoValidaTabuleiro != 2) {
                    if (jogadorDaVez == 1) {
                        jogadorDaVez = 2;
                    } else {
                        jogadorDaVez = 1;
                    }
                }
                velha = velha + 1;
            } else {

                // informar ao jogador 1 que a posição está preenchida, é invalida e ele precisa informar uma posição válida
                console.log ("posição ocupada, jogue novamente JOGADOR " + jogadorDaVez + "!!!");
            }

            // Verificar o tabuleiro, Se houver ganhador ou empate, finalizar o jogo
        } else {
            console.log ("numero invalido, digite uma casa novamente");
        }

        // Verificar jogada vencedora nas linhas
    } while (resultadoValidaTabuleiro == 0 && velha <= 9);
    if (resultadoValidaTabuleiro == 2) {
        console.log ("O vencedor do jogo foi o JOGADOR " + jogadorDaVez);
    } else {
        console.log ("velha!!");
    }
    console.log (tabuleiro[0].toString() + tabuleiro[1] + tabuleiro[2]);
    console.log (tabuleiro[3].toString() + tabuleiro[4] + tabuleiro[5]);
    console.log (tabuleiro[6].toString() + tabuleiro[7] + tabuleiro[8]);
}

function validaposicao(entrada) {
    var entradaValida;

    entradaValida = false;
    console.log (entrada.length());
    if (entrada.length() == 3) {
        if (entrada.charAt(0) == "0" || entrada.charAt(0) == "1" || entrada.charAt(0) == "2") {
            if (entrada.charAt(2) == "0" || entrada.charAt(2) == "1" || entrada.charAt(2) == "2") {
                entradaValida = true;
            }
        }
    }
    
    return entradaValida;
}

function validaTabuleiro(tabuleiro, jogadorDaVez) {
    var resultado;

    resultado = 0;
    console.log (jogadorDaVez);
    if (tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez || tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez || tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
        resultado = 2;
    } else {
        if (tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez || tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
            resultado = 2;
        } else {
            if (tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) {
                resultado = 2;
            }
        }
    }
    
    return resultado;
}
