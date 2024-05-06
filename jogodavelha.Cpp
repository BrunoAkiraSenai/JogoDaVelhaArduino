int velha; 
int linha;
int coluna;
bool haVencedor;
int tabuleiro[9];
int index;
  
  void setup() {
   
  Serial.begin(9600);
  for (int linha = 0; linha <= 2; linha++){
  for(int coluna= 0; coluna <= 2; coluna++){
    tabuleiro[linha][coluna] = 0;
  }
 }
  for(int linha = 0; linha <=2 ; linha++){
    if(linha == 1 | linha == 2)
  Serial.println("");
 }
 for(int coluna = 0;coluna<=2 ; coluna++){
  Serial.println(tabuleiro[linha][coluna]);
 }
  
 Serial.println("");
 Serial.println("digite sua jogada");
}
void loop() {


    haVencedor = false;
  
    // Limpar/zerar o tabuleiro
    

    for (index = 0; index <= 8; index++) {
        tabuleiro[index] = 0;
    }
    string jogada;

    // Iniciar o jogo, definir quem joga primeiro
    int jogadorDaVez;

    jogadorDaVez = 1;

    // Anotar/Registrar a jogada, do primeiro jogador
    velha = 1;
    // Limpar/zerar o tabuleiro
   
 


 

    // Anotar/Registrar a jogada, do primeiro jogador
  
          
            // Converter a jogada texto em dois inteiros linha e coluna.
            // Simula a função Serial.parseInt() do Arduino
            linha = toInt(jogada[0]);

            // CORRIGIR O ERRO DE DIGITAÇÃO
            coluna = toInt(jogada[2]);
            Serial.println ("Linha: "  linha  "; Coluna: "  coluna)  ;

            // Verificar se a posição 'jogada' é valida
            if (tabuleiro[3 * linha + coluna] == 0) {
                tabuleiro[3 * linha + coluna] = jogadorDaVez;
                if (tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez || tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez || tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
                    haVencedor = true;
                } else {

                    // Verificar a jogada vencedora nas colunas.
                    if (tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez || tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
                        haVencedor = true;
                    } else {

                        // Verificar a jogada vencedora nas diagonais.
                        if (tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) {
                            haVencedor = true;
                        } else {

                            // Trocar o jogador
                            if(jogadorDaVez == 1){
                                jogadorDaVez = 2;
                            } else {
                                jogadorDaVez = 1;
                            }
                        }
                    }
                }
                velha = velha + 1;
            } else {
                Serial.println("Posição ocupada, jogue novamente !!!");

                // Informar ao Jogador 1 que a posição está preenchida, é inválida e ele precisa informar um posição válida.
            }
        } else {
            Serial.println ( "Jogada inválida !!!");
        }

        // Verificar a jogada vencedora nas linhas.
     while (!haVencedor && velha <= 9);

    // Verificar o tabuleiro, se houve ganhador ou empate, finalizar o jogo.
    if (haVencedor) {
        Serial.println("Parabéns pela a vitória, jogador " && jogadorDaVez);
    } else {
        Serial.println("Deu VELHA!!!");
    }
      {
    Serial.print(tabuleiro[0]);
    Serial.print(tabuleiro[1]);
    Serial.print(tabuleiro[2]);
    Serial.print(tabuleiro[3]);
    Serial.print(tabuleiro[4]);
    Serial.print(tabuleiro[5]);
    Serial.print(tabuleiro[6]);
    Serial.print(tabuleiro[7]);
    Serial.print(tabuleiro[8]);

    return 0;
}

int getValArrayInt(int linha, int coluna, int matriz[], int qtdeLinhas) {
    int valor;

    valor = matriz[qtdeLinhas * linha + coluna];
    
    return valor;
}

bool validaPosicao(string entrada) {
    bool entradaValida;

    entradaValida = false;
    Serial.println(entrada.length());
    if (entrada.length() == 3) {
        Serial.println("Comprimento da string igual  3");
        if (entrada[0] == "0" || entrada[0] == "1" || entrada[0] == "2") {
            Serial.println(entrada[0])  ;
            if (entrada[2] == "0" || entrada[2] == "1" || entrada[2] == "2") {
                Serial.println(entrada[2]);
                entradaValida = true;
            }
            }
        }
    }
    
    return entradaValida;


// The following implements type conversion functions.
string toString (double value) { //int also
    stringstream temp;
    temp  value;
    return temp.str();
  
}

int toInt (string text) {
    return atoi(text.c_str());
}

double toDouble (string text) {
    return atof(text.c_str());
}