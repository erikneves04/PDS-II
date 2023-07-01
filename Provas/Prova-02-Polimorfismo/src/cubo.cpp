#include <cmath>
#include <string>
#include "cubo.h"

Cubo::Cubo(std::string cor, int lado)
{
    _nome = "cubo";
    _cor = cor;
    _lado = lado;
}

double Cubo::get_volume()
{
    return pow(_lado, 3);
}

std::string Cubo::get_cor()
{
    return _cor;
}

std::string Cubo::get_nome()
{
    return _nome;
}