#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

int tamanho = 20;

void gerar_tabuleiro(int pos_predador[], int pos_presa[]);

int main()
{
    int pos_predador[2], pos_presa[2];
    srand(time(NULL));

    //Gera os índices do predador
    pos_predador[1] = rand() % 19;
    do
    {
        pos_predador[0] = rand() % 19;
    } while (pos_predador[0] == 10); //Evita que ele apareça na barreira

    //Gera os índices da presa
    pos_presa[1] = rand() % 19;
    if (pos_predador[0] > 10)
        pos_presa[0] = rand() % 9;

    else
        //Garante que cada parte surja em um lado oposto do tabuleiro
        pos_presa[0] = rand() % (19 - 11 + 1) + 11;

    gerar_tabuleiro(pos_predador, pos_presa);

    //Laço para quando o predador surge no lado direito
    while (pos_predador[0] > pos_presa[0])
    {
        //Move o predador para contornar a barreira
        while (pos_predador[0] - 1 == 10 && pos_predador[1] > 2)
        {
            pos_predador[1]--;
            gerar_tabuleiro(pos_predador, pos_presa);
            sleep(1); //Tempo de latência entre cada função
        }
        pos_predador[0]--;
        gerar_tabuleiro(pos_predador, pos_presa);
        sleep(1);
    }

    while (pos_predador[0] < pos_presa[0]) //Laço para quando o predador surge no lado esquerdo
    {
        //Move o predador para contornar a barreira
        while (pos_predador[0] + 1 == 10 && pos_predador[1] > 2)
        {
            pos_predador[1]--;
            gerar_tabuleiro(pos_predador, pos_presa);
            sleep(1); //Tempo de latência entre cada função
        }
        pos_predador[0]++;
        gerar_tabuleiro(pos_predador, pos_presa);
        sleep(1);
    }

    //Faz o movimento vertical final até a presa
    while (pos_predador[1] < pos_presa[1])
    {
        pos_predador[1]++;
        gerar_tabuleiro(pos_predador, pos_presa);
        sleep(1);
    }

    //Faz o movimento vertical final até a presa
    while (pos_predador[1] > pos_presa[1])
    {
        pos_predador[1]--;
        gerar_tabuleiro(pos_predador, pos_presa);
        sleep(1);
    }
}

void gerar_tabuleiro(int pos_predador[], int pos_presa[])
{
    string tabuleiro[tamanho][tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (i == pos_predador[1] && j == pos_predador[0])
                cout << "% ";
            else if (i == pos_presa[1] && j == pos_presa[0])
                cout << "$ ";
            else if (i > 2 && j == 10) //Imprime a barreira
                cout << "| ";
            else
                cout << "+ ";
        }
        cout << endl;
    }
    cout << endl;
}