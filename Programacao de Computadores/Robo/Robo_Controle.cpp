#include <iostream>
#include <ctime>
using namespace std;

int tamanho = 20;

void gerar_tabuleiro(int pos_robo[], int pos_com[], bool form_robo)
{
  string tabuleiro[tamanho][tamanho];
  for (int i = 0; i < tamanho; i++)
  {
    for (int j = 0; j < tamanho; j++)
    {
      if (i == pos_robo[1] && j == pos_robo[0])
      {
        if (form_robo == false)
          cout << "@ ";
        if (form_robo == true)
          cout << "$ ";
      }
      else if (i == pos_com[1] && j == pos_com[0])
        cout << "O ";
      else
        cout << "+ ";
    }
    cout << endl;
  }
}

bool meta(bool form_robo);
int direita(int pos_robo);
int esquerda(int pos_robo);
int cima(int pos_robo);
int baixo(int pos_robo);

/* gerar_tabuleiro = só gerar o tabuleiro
criar_robo = gerar posicao random do robo
direcao = mover robo e atualizar sua posicao 

*/

int main()
{
  int pos_robo[2], pos_com[2];
  bool form_robo = false;
  srand(time(NULL));
  pos_robo[0] = rand() % 19;
  pos_robo[1] = rand() % 19;
  do
  {
    pos_com[0] = rand() % 19;
    pos_com[1] = rand() % 19;
  } while (pos_com[0] == pos_robo[0] && pos_com[1] == pos_robo[1]);
  gerar_tabuleiro(pos_robo, pos_com, form_robo);
  char input;
  do
  {
    if (pos_com[0] == pos_robo[0] && pos_com[1] == pos_robo[1])
      break;

    cin >> input;

    if (input == 'a')
      pos_robo[0] = esquerda(pos_robo[0]);

    if (input == 'd')
      pos_robo[0] = direita(pos_robo[0]);

    if (input == 's')
      pos_robo[1] = baixo(pos_robo[1]);

    if (input == 'w')
      pos_robo[1] = cima(pos_robo[1]);
    if (input == 'm')
      form_robo = meta(form_robo);
    gerar_tabuleiro(pos_robo, pos_com, form_robo);
  } while (input != 'q');
  cout << "Programa encerrado." << endl;
}

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

bool meta(bool form_robo)
{
  form_robo = !form_robo;
  return form_robo;
}