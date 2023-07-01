#include <cmath>
#include <string>
#include "circulo.h"

#define PI (3.14159265358979323846)

Circulo::Circulo(std::string cor, int raio)
{
    _nome = "circulo";
    _cor = cor;
    _raio = raio;
}

double Circulo::get_area()
{
    return PI * pow(_raio, 2);
}

double Circulo::get_perimetro()
{
    return 2 * PI * _raio;
}

std::string Circulo::get_cor()
{
    return _cor;
}

std::string Circulo::get_nome()
{
    return _nome;
}