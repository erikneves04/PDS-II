#include <string>
#include "quadrado.h"

Quadrado::Quadrado(std::string cor, int lado)
{
    _nome = "quadrado";
    _cor = cor;
    _lado = lado;
}

double Quadrado::get_area()
{
    return _lado * _lado;
}

double Quadrado::get_perimetro()
{
    return 4 * _lado;
}

std::string Quadrado::get_cor()
{
    return _cor;
}

std::string Quadrado::get_nome()
{
    return _nome;
}