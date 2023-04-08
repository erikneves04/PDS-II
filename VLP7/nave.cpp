#include <iostream>

#include "includes/nave.hpp"
#include "includes/ponto.hpp"

Nave::Nave()
{
    _energia = 100;
    _forca = 1;
    _posicao = Ponto2D();
}

Nave::Nave(Ponto2D posicao)
{
    _energia = 100;
    _forca = 1;
    _posicao = posicao;
}


Nave::Nave(Ponto2D posicao, double forca)
{
    _energia = 100;
    _posicao = posicao;
    _forca = forca;
}

void Nave::mover(double dx, double dy)
{
    _posicao.mover(dx, dy);
}

double Nave::calcular_distancia(Nave nave)
{
    return _posicao.calcular_distancia(nave._posicao);
}

int Nave::determinar_indice_nave_mais_proxima(Nave naves[], int n)
{
    int index = -1;
    double minDistance = -1;

    for(int i=0; i<n; i++)
    {
        double currentDistance = calcular_distancia(naves[i]);
        if (currentDistance != 0)
        {
            if (minDistance == -1 || currentDistance < minDistance)
            {
                index = i;
                minDistance = currentDistance;
            }
        }
    }

    return index;
}

void Nave::atacar(Nave naves[], int n)
{
    int target = determinar_indice_nave_mais_proxima(naves, n);

    double distancia = calcular_distancia(naves[target]);
    double dano = (_forca * 100)/distancia;

    if (dano > 30)
        dano = 30;

    naves[target]._energia -= dano;    
    
    if (naves[target]._energia <= 50)
        std::cout << "Energia baixa!" << std::endl;
}

void Nave::imprimir_status()
{
    std::cout << _posicao.GetX() << " " << _posicao.GetY() << " " << _energia << std::endl;
}