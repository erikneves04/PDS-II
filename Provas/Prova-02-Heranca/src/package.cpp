#include <string>
#include "package.h"

Package::Package(unsigned int peso, unsigned int custoPorQuilo, std::string nome, std::string endereco)
{
    _nome = nome;
    _endereco = endereco;
    _peso = peso;
    _custoPorQuilo = custoPorQuilo;
}

double Package::calculate_cost()
{
    return _peso * _custoPorQuilo;
}

std::string Package::GetDestinatario()
{
    return _nome;
}