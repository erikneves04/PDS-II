#ifndef NAVE_H
#define NAVE_H

#include "ponto.hpp"

class Nave
{
    private:
        Ponto2D _posicao;
        double _forca;
        double _energia;
    public:
        Nave();
        Nave(Ponto2D posicao);
        Nave(Ponto2D posicao, double forca);

        void mover(double dx, double dy);
        double calcular_distancia(Nave nave);
        int determinar_indice_nave_mais_proxima(Nave naves[], int n);
        void atacar(Nave naves[], int n);
        void imprimir_status();
};

#endif