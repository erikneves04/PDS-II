#ifndef PONTO_H
#define PONTO_H

class Ponto2D
{
    private:
        double _x;
        double _y;
    public:
        Ponto2D();
        Ponto2D(double x, double y);
        double calcular_distancia(Ponto2D ponto);
        void mover(double dx, double dy);
        double GetX();
        double GetY();
};

#endif