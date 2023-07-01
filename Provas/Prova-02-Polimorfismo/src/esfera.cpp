#include <cmath>
#include <string>
#include "esfera.h"

#define PI (3.14159265358979323846)

Esfera::Esfera(std::string cor, int raio)
{
    _nome = "esfera";
    _cor = cor;
    _raio = raio;
}

double Esfera::get_volume()
{
    return (4.0 / 3.0) * PI * pow(_raio, 3);
}

std::string Esfera::get_cor()
{
    return _cor;
}

std::string Esfera::get_nome()
{
    return _nome;
}