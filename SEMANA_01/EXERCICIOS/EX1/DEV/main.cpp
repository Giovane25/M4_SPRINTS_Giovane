#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>

using namespace std;



int equaçãoSensor()
{

    float medida, resultado;
    cout << "Coloque uma medida em metros : ";
    cin >> medida;
    resultado = (101 - 1) * medida / 100;
    cout << "A diferença de porcentagem é " << resultado;

    return 0;
}

int leituraSensor(int min_v, int max_v)
{
    int read, writing = 1;
    while (writing)
    {
        cout << "Informar o valor  (Min = " << min_v << " Max = " << max_v << ") : ";
        cin >> read;
        if (read >= min_v && read <= max_v)
        {
            return read;
            writing = 0;
        }
        else
        {
            cout << "Valor\n";
        }
    }
    return read;
}

int armazenado(int value, int *array, int plenght, int posAtualVetor)
{
    int position = posAtualVetor;
    *(array + posAtualVetor) = value;

    position++;
    return position;
}

string caminhoCurto(int *vetorMov, int *maiorDir)
{

    int verify = 0;
    string side;
    *maiorDir = *vetorMov;

    for (int i = 0; i < 4; i++)
    {
        if (vetorMov[i] > *maiorDir)
        {
            *maiorDir = vetorMov[i];
            verify = i;
        }
    }
    switch (verify)
    {
    case 0:
        side = "Direita";
        break;
    case 1:
        side = "Esquerda";
        break;
    case 2:
        side = "Frente";
        break;
    case 3:
        side = "Tras";
        break;
    }

    return side;
}

int indentificandoComando()
{
    char answer;
    puts("preseguir? (Y/N): ");
    cin >> answer;
    answer = toupper(answer);

    if (answer == 'Y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dirige(int *v, int maxv)
{
    int maxVetor = maxv;
    int *vetorMov = v;
    int posAtualVetor = 0;
    int dirigindo = 1;
    while (dirigindo)
    {
        int min_v = 0, max_v = 830;
        for (int i = 0; i < 4; i++)
        {
            int medida = leituraSensor(min_v, max_v);
            medida = equaçãoSensor();
            posAtualVetor = armazenado(medida, vetorMov, maxVetor, posAtualVetor);
        }
        dirigindo = indentificandoComando();
    }
    return posAtualVetor;
}

void percorre(int *v, int tamPercorrido)
{
    int *vetorMov = v;
    int maiorDir = 0;

    for (int i = 0; i < tamPercorrido; i += 4)
    {
        string direcao = caminhoCurto(&(vetorMov[i]), &maiorDir);
        cout << "Movimento " << direcao << " distancia = " << maiorDir << "\n";
    }
}

int main(int argc, char **argv)
{
    int maxVetor = 100;
    int vetorMov[maxVetor * 4];
    int posAtualVet = 0;

    posAtualVet = dirige(vetorMov, maxVetor);

    percorre(vetorMov, posAtualVet);

    return 0;
}