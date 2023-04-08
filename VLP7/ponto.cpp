#include <iostream>
#include <cmath>
#include "includes/ponto.hpp"

Ponto2D::Ponto2D()
{
    _x = 0;
    _y = 0;
}

Ponto2D::Ponto2D(double x, double y)
{
    _x = x;
    _y = y;
}

double Ponto2D::calcular_distancia(Ponto2D ponto)
{
    return std::sqrt(std::pow(_x - ponto._x, 2) + std::pow(_y - ponto._y, 2));
}

void Ponto2D::mover(double dx, double dy)
{
    _x += dx;
    _y += dy;
}

double Ponto2D::GetX()
{
    return _x;
}

double Ponto2D::GetY()
{
    return _y;
}