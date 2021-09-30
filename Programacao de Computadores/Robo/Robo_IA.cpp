#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

int tamanho = 20;

void gerar_tabuleiro(int pos_robo[], int pos_com[]);

int main()
{
    int pos_robo[2], pos_com[2];
    srand(time(NULL));
    do
    {
        pos_robo[0] = rand() % 19;
        pos_robo[1] = rand() % 19;
    } while (pos_robo[0] == 10);

    pos_com[1] = rand() % 19;
    if (pos_robo[0] > 10)
        pos_com[0] = rand() % 9;

    else
        pos_com[0] = rand() % (19 - 11 + 1) + 11;

    gerar_tabuleiro(pos_robo, pos_com);

    while (pos_robo[0] > pos_com[0])
    {
        while (pos_robo[0] - 1 == 10 && pos_robo[1] > 2)
        {
            pos_robo[1]--;
            gerar_tabuleiro(pos_robo, pos_com);
            sleep(1);
        }
        pos_robo[0]--;
        gerar_tabuleiro(pos_robo, pos_com);
        sleep(1);
    }
    while (pos_robo[0] < pos_com[0])
    {
        while (pos_robo[0] + 1 == 10 && pos_robo[1] > 2)
        {
            pos_robo[1]--;
            gerar_tabuleiro(pos_robo, pos_com);
            sleep(1);
        }
        pos_robo[0]++;
        gerar_tabuleiro(pos_robo, pos_com);
        sleep(1);
    }
    while (pos_robo[1] < pos_com[1])
    {
        pos_robo[1]++;
        gerar_tabuleiro(pos_robo, pos_com);
        sleep(1);
    }
    while (pos_robo[1] > pos_com[1])
    {
        pos_robo[1]--;
        gerar_tabuleiro(pos_robo, pos_com);
        sleep(1);
    }
}

void gerar_tabuleiro(int pos_robo[], int pos_com[])
{
    string tabuleiro[tamanho][tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (i == pos_robo[1] && j == pos_robo[0])
                cout << "% ";
            else if (i == pos_com[1] && j == pos_com[0])
                cout << "$ ";
            else if (i > 2 && j == 10)
                cout << "| ";
            else
                cout << "+ ";
        }
        cout << endl;
    }
    cout << endl;
}