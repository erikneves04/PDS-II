#include <cmath>
#include <string>
#include "triangulo.h"

Triangulo::Triangulo(std::string cor, int lado1, int lado2, int lado3)
{
    _nome = "triangulo";
    _cor = cor;
    
    _lado_1 = lado1;
    _lado_2 = lado2;
    _lado_3 = lado3;
}

double Triangulo::get_area()
{
    double semiperimetro = get_perimetro() / 2;
    double area = sqrt(semiperimetro * (semiperimetro - _lado_1) * (semiperimetro - _lado_2) * (semiperimetro - _lado_3));
    return area;
}

double Triangulo::get_perimetro()
{
    return _lado_1 + _lado_2 + _lado_3;
}

std::string Triangulo::get_cor()
{
    return _cor;
}

std::string Triangulo::get_nome()
{
    return _nome;
}