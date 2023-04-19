#define INT1 2
#define INT2 3
#define INT3 4
#define INT4 5
const int Botao1 = 9;   //botao no pino 9
const int Botao2 = 10;  //botao no pino 10
const int Botao3 = 11;  //botao no pino 11
const int Botao4 = 12;  //botao no pino 12
int estadoBotao1;       //Variavel para ler o status do pushbutton 1
int estadoBotao2;       //Variavel para ler o status do pushbutton 2
int estadoBotao3;       //Variavel para ler o status do pushbutton 3
int estadoBotao4;       //Variavel para ler o status do pushbutton 4
int tamanho = 10;       //sempre coloque o tamanho do vetor aqui nesta variável para facilitar uma mudança rápida no tamanho dele
int instrucoes[10];     //vetor de inteiros para salvar quais as instruções a serem segudas após execução
int i = 0;              //variável para os laços FOR

void setup() {
  pinMode(INT1, OUTPUT);
  pinMode(INT2, OUTPUT);
  pinMode(INT3, OUTPUT);
  pinMode(INT4, OUTPUT);
  pinMode(Botao1, INPUT);  //Pino com botão será entrada
  pinMode(Botao2, INPUT);  //Pino com botão será entrada
  pinMode(Botao3, INPUT);  //Pino com botão será entrada
  pinMode(Botao4, INPUT);  //Pino com botão será entrada
  zera();                  //zera a lista de passos
}

void loop() {

  estadoBotao1 = digitalRead(Botao1);  //le o estado do botão - HIGH OU LOW
  estadoBotao2 = digitalRead(Botao2);  //le o estado do botão - HIGH OU LOW
  estadoBotao3 = digitalRead(Botao3);  //le o estado do botão - HIGH OU LOW
  estadoBotao4 = digitalRead(Botao4);  //le o estado do botão - HIGH OU LOW

  //verifica se o botão está pressionado e adiciona um passo nas instruções
  if (estadoBotao1 == HIGH) {
    instrucoes[i] = 1;            //adiciona um passo nas instruções
    i++;
    //verifica quando o botão deixa de ser pressionado para continuar a execução
    while (estadoBotao1 == HIGH) {
      estadoBotao1 = digitalRead(Botao1);  //le o estado do botão
    }
  }

  //verifica se o botão está pressionado e adiciona um passo nas instruções
  if (estadoBotao2 == HIGH) {

    instrucoes[i] = 2;  //adiciona um passo nas instruções
    i++;
    //verifica quando o botão deixa de ser pressionado para continuar a execução
    while (estadoBotao2 == HIGH) {
      estadoBotao2 = digitalRead(Botao2);  //le o estado do botão
    }
  }

  if (estadoBotao3 == HIGH) {

    instrucoes[i] = 3;  //adiciona um passo nas instruções
    i++;
    //verifica quando o botão deixa de ser pressionado para continuar a execução
    while (estadoBotao3 == HIGH) {
      estadoBotao3 = digitalRead(Botao3);  //le o estado do botão
    }
  }

  if (estadoBotao4 == HIGH) {
    leitura();                    //executa os passos salvos
    zera();                       //zera a lista de passos
  1}
}

void leitura() {
  for (i = 0; i < tamanho; i++) {
    if (instrucoes[i] == 1) {
      forward();
      delay(300);
      Stop();
      delay(300);
    }
    if (instrucoes[i] == 2) {
      left();
      delay(300);
      Stop();
      delay(300);
    }

    if (instrucoes[i] == 3) {
      right();
      delay(300);
      Stop();  
      delay(300);
    }
    //verifica se acabaram o número de passos dados e encerra o laço FOR

    if (instrucoes[i] == 0) {
      break;  //encerra o laço FOR
    }
  }
  i = 0;
}

//zera os passos
void zera() {
  for (i = 0; i < tamanho; i++) {
    instrucoes[i] = 0;
  }
  i = 0;
}

void forward() {
  digitalWrite(INT1, LOW);
  digitalWrite(INT2, HIGH);
  digitalWrite(INT3, HIGH);
  digitalWrite(INT4, LOW);
}

void backward() {
  digitalWrite(INT1, HIGH);
  digitalWrite(INT2, LOW);
  digitalWrite(INT3, LOW);
  digitalWrite(INT4, HIGH);
}

void left() {
  digitalWrite(INT1, HIGH);
  digitalWrite(INT2, LOW);
  digitalWrite(INT3, HIGH);
  digitalWrite(INT4, LOW);
}

void right() {
  digitalWrite(INT1, LOW);
  digitalWrite(INT2, HIGH);
  digitalWrite(INT3, LOW);
  digitalWrite(INT4, HIGH);
}

void Stop() {
  digitalWrite(INT1, LOW);
  digitalWrite(INT2, LOW);
  digitalWrite(INT3, LOW);
  digitalWrite(INT4, LOW);
}