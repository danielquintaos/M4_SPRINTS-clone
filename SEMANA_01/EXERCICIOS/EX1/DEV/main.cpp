#include <iostream>
#include <string>
#include <stdio.h>

void setup()


using namespace std;

// 1 -  Faça uma função que recebe uma certa medida e a ajusta percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor

double adjust_value(double value, double min, double max, double percent) {
  double range = max - min;
  double adjustment = range * percent / 100;
  double result = value + adjustment;

  if (result < min) {
    result = min;
  } else if (result > max) {
    result = max;
  }

  return result;
}

int main() {
  double value = 10.0;
  double min = 5.0;
  double max = 15.0;
  double percent = 50.0;
  double result = adjust_value(value, min, max, percent);

  printf("Resultado: %f\n", result);
  return 0;
}


// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor
double read_sensor() {
  double value;
  printf("Insira o valor lido pelo sensor: ");
  scanf("%lf", &value);
  return value;
}

int main1() {
  double value = read_sensor();
  printf("Valor lido pelo sensor: %f\n", value);
  return 0;
}


// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor


void store_measurement(int *array, int index, int value) {
  array[index] = value;
}

int main2() {
  int array[10];
  int index = 3;
  int value = 42;
  store_measurement(array, index, value);
  printf("Valor armazenado no vetor: %d\n", array[index]);
  return 0;
}


// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.

void distanceToSides(int distance[4]) {
  for (int i = 0; i < 4; i++) {
    printf("Distancia para lado %d: %d\n", i + 1, distance[i]);
  }
}

int main3() {
  int distance[4] = {2, 3, 4, 5};
  distanceToSides(distance);
  return 0;
}


// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso
bool funcPergunta(){
   char resp;
   printf("Você deseja continuar o mapeamento? (S/N)");
   cin >> resp;
   if(toupper(resp) == 'N'){
      return false;
   }
   return true;
}


// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas
void loop()

#define SENSOR_VALUES 4
#define MAX_DISTANCE 100
#define MIN_DISTANCE 0

// Function to adjust a given measurement within a minimum and maximum value
int adjustMeasurement(int measurement, int minValue, int maxValue) {
  int result = measurement;
  if (result < minValue) {
    result = minValue;
  } else if (result > maxValue) {
    result = maxValue;
  }
  return result;
}

// Function to read a value from the keyboard
int readSensorValue() {
  int value;
  printf("Enter sensor value: ");
  scanf("%d", &value);
  return value;
}

// Function to store a given integer value in a provided array
void storeValueInArray(int value, int values[], int position) {
  values[position] = value;
}

int main4() {
  int sensorValues[SENSOR_VALUES];
  int i;
  char stopRequest[4];

  // Continuously loop until user sends a stop request
  while (1) {
    for (i = 0; i < SENSOR_VALUES; i++) {
      int rawValue = readSensorValue();
      int adjustedValue = adjustMeasurement(rawValue, MIN_DISTANCE, MAX_DISTANCE);
      storeValueInArray(adjustedValue, sensorValues, i);
    }

    // Print the stored values
    printf("Stored values: ");
    for (i = 0; i < SENSOR_VALUES; i++) {
      printf("%d ", sensorValues[i]);
    }
    printf("\n");

    // Check for a stop request from the user
    printf("Enter 'stop' to stop the loop: ");
    scanf("%s", stopRequest);
    if (strcmp(stopRequest, "stop") == 0) {
      break;
    }
  }

  return 0;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento
#define NUM_SENSORS 4

int read_sensors(int sensors[]) {
    for (int i = 0; i < NUM_SENSORS; i++) {
        printf("Insira a distancia do sensor %d: ", i + 1);
        scanf("%d", &sensors[i]);
    }
}

int find_max_distance(int sensors[]) {
    int max_distance = 0;
    int max_index = 0;

    for (int i = 0; i < NUM_SENSORS; i++) {
        if (sensors[i] > max_distance) {
            max_distance = sensors[i];
            max_index = i;
        }
    }

    return max_index;
}

int main5() {
    int sensors[NUM_SENSORS];
    int max_index;

    read_sensors(sensors);

    max_index = find_max_distance(sensors);

    printf("O robo move em direcao ao sensor %d\n", max_index + 1);

    return 0;
}