int linha;
int coluna;
bool haVencedor = false;
int jogadorDaVez = 1;
int velha = 1;
int j;

//criação do tabuleiro
int tabuleiro[3][3] = {
  { 0, 0, 0 },
  { 0, 0, 0 },
  { 0, 0, 0 }
};

//função para verificar se a jogada é valida ou não
boolean verificarJogada(int linha, int coluna) {
  boolean jogadaValida = false;
  if (linha == 0 || linha == 1 || linha == 2) {
    if (coluna == 0 || coluna == 1 || coluna == 2) {
      jogadaValida = true;
    }
  }
  return jogadaValida;
}

void setup() {
  Serial.begin(9600);

  //zerador detabuleiro
  for (int linha = 0; linha <= 2; linha++) {
    for (int coluna = 0; coluna <= 2; coluna++) {
      tabuleiro[linha][coluna] = 0;
    }
  }

//onde escreve o tabuleiro no serial
  for (int linha = 0; linha <= 2; linha++) {
    if (linha == 1 | linha == 2) {
      Serial.println("");
    }
    for (int coluna = 0; coluna <= 2; coluna++) {
      Serial.print(tabuleiro[linha][coluna]);
    }
  }
  Serial.println("");
  Serial.print("Digite sua jogada jogador");
  Serial.println(jogadorDaVez);
}


void loop() {
  haVencedor = false;

 //zerador detabuleiro
  for (int linha = 0; linha <= 2; linha++) {
    for (int coluna = 0; coluna <= 2; coluna++) {
      tabuleiro[linha][coluna] = 0;
    }
  }

//onde escreve o tabuleiro no serial
  for (int linha = 0; linha <= 2; linha++) {
    if (linha == 1 | linha == 2) {
      Serial.println("");
    }
    for (int coluna = 0; coluna <= 2; coluna++) {
      Serial.print(tabuleiro[linha][coluna]);
    }
  }


  do {
    while (!Serial.available())
      ;

    String entrada = Serial.readString();
    Serial.println("");
    Serial.println(entrada);

    linha = entrada.substring(0, 1).toInt();
    coluna = entrada.substring(2, 3).toInt();

    if (verificarJogada(linha, coluna) == true) {
      if (tabuleiro[linha][coluna] == 0) {
        tabuleiro[linha][coluna] = jogadorDaVez;

        //zera a matriz do tabuleiro
        for (int linha = 0; linha <= 2; linha++) {
          if (linha == 1 || linha == 2) {
            Serial.println("");
          }
          for (int coluna = 0; coluna <= 2; coluna++) {
            Serial.print(tabuleiro[linha][coluna]);
          }
        }

       //verifica as jogadas nas linhas,colunas e diagonal
        if ((tabuleiro[0][0] == jogadorDaVez && tabuleiro[0][1] == jogadorDaVez && tabuleiro[0][2] == jogadorDaVez) || (tabuleiro[1][0] == jogadorDaVez && tabuleiro[1][1] == jogadorDaVez && tabuleiro[1][2] == jogadorDaVez) || (tabuleiro[2][0] == jogadorDaVez && tabuleiro[2][1] == jogadorDaVez && tabuleiro[2][2] == jogadorDaVez) || (tabuleiro[0][0] == jogadorDaVez && tabuleiro[1][0] == jogadorDaVez && tabuleiro[2][0] == jogadorDaVez) || (tabuleiro[0][1] == jogadorDaVez && tabuleiro[1][1] == jogadorDaVez && tabuleiro[2][1] == jogadorDaVez) || (tabuleiro[0][2] == jogadorDaVez && tabuleiro[1][2] == jogadorDaVez && tabuleiro[2][2] == jogadorDaVez) || (tabuleiro[0][0] == jogadorDaVez && tabuleiro[1][1] == jogadorDaVez && tabuleiro[2][2] == jogadorDaVez) || (tabuleiro[0][2] == jogadorDaVez && tabuleiro[1][1] == jogadorDaVez && tabuleiro[2][0] == jogadorDaVez)) {
          haVencedor = true;
          j = 1;
        }
      
      //troca de jogadores
        if (jogadorDaVez == 1 && haVencedor == false) {
          jogadorDaVez = 2;
        } else if (jogadorDaVez == 2 && haVencedor == false) {
          jogadorDaVez = 1;
        }
        
        //contador de velha
        velha = velha + 1;
        Serial.print("\nContagem velha=");
        Serial.println(velha);
        //Serial.println("");
        Serial.print("Faca sua jogada jogador");
        Serial.println(jogadorDaVez);
    
    //quando o lugar da jogada estiver ocupado 
      } else {
        Serial.println("Posicao ocupada.");
        Serial.print("Jogue novamente jogador");
        Serial.println(jogadorDaVez);
      }
    //quando a jogada for invalida
    } else {

      Serial.println("Jogada invalida.");
      Serial.print("Jogue novamente jogador");
      Serial.println(jogadorDaVez);
    }

  //enquanto haVencedor não for diferente e velha <9 vai voltar diretamento para o (do)
  } while (!haVencedor && velha <= 9);
  if (velha == 9) {
    j = 2;
  }
  switch (j) {
    case 1:
      Serial.print("voce venceu ");
      Serial.print(jogadorDaVez);
      Serial.println("");
      velha = 1;
      break;
    case 2:
      Serial.println("velha!!");
      velha = 1;
      break;
  }
}