#include <iostream>
#include <ctime>
using namespace std;
int tamanho = 20;

void gerar_tabuleiro(int pos_robo[], int pos_alvo[], bool form_robo);
bool meta(bool form_robo);
int direita(int pos_robo);
int esquerda(int pos_robo);
int cima(int pos_robo);
int baixo(int pos_robo);

int main()
{
  int pos_robo[2], pos_alvo[2];
  bool form_robo = false;

  //Gera a posição do robô aleatoriamente
  srand(time(NULL));
  pos_robo[0] = rand() % 19;
  pos_robo[1] = rand() % 19;

  do
  {
    //Gera posições do alvo
    pos_alvo[0] = rand() % 19;
    pos_alvo[1] = rand() % 19;
  } while (pos_alvo[0] == pos_robo[0] && pos_alvo[1] == pos_robo[1]);

  gerar_tabuleiro(pos_robo, pos_alvo, form_robo);
  char input;

  do
  {
    //Recebe o comando do usuário e coloca em minúsculo
    cin >> input;
    input = tolower(input);

    if (input == 'a')
      pos_robo[0] = esquerda(pos_robo[0]);

    else if (input == 'd')
      pos_robo[0] = direita(pos_robo[0]);

    else if (input == 's')
      pos_robo[1] = baixo(pos_robo[1]);

    else if (input == 'w')
      pos_robo[1] = cima(pos_robo[1]);

    else if (input == 'm')
      form_robo = meta(form_robo);

    gerar_tabuleiro(pos_robo, pos_alvo, form_robo);
  }
  //Verifica as condições de fechamento do programa.
  while (input != 'q' && ((pos_robo[0] != pos_alvo[0]) || (pos_robo[1] != pos_alvo[1])));
  cout << "Programa encerrado." << endl;
}

void gerar_tabuleiro(int pos_robo[], int pos_alvo[], bool form_robo)
{
  string tabuleiro[tamanho][tamanho];
  for (int i = 0; i < tamanho; i++)
  {
    for (int j = 0; j < tamanho; j++)
    {
      if (i == pos_robo[1] && j == pos_robo[0])
      {
        //Verifica a metamorfose
        if (form_robo)
          cout << "$ ";

        else
          cout << "@ ";
      }
      //Imprime o alvo
      else if (i == pos_alvo[1] && j == pos_alvo[0])
        cout << "O ";
      else
        cout << "+ ";
    }
    cout << endl;
  }
}

//Define os limites que não podem ser ultrapassados |For all|
//no tabuleiro e altera a posição do robo caso o limite não tenha sido atingido
int direita(int pos_robo)
{
  if (pos_robo < 19)
    pos_robo++;
  else
    cout << " Limite alcancado " << endl;
  return pos_robo;
}

int esquerda(int pos_robo)
{
  if (pos_robo > 0)
    pos_robo--;
  else
    cout << " Limite alcancado " << endl;
  return pos_robo;
}

int cima(int pos_robo)
{
  if (pos_robo > 0)
    pos_robo--;
  else
    cout << " Limite alcancado " << endl;
  return pos_robo;
}

int baixo(int pos_robo)
{
  if (pos_robo < 19)
    pos_robo++;
  else
    cout << " Limite alcancado " << endl;
  return pos_robo;
}

bool meta(bool form_robo) //Função de metamorfose.
{
  form_robo = !form_robo;
  return form_robo;
}