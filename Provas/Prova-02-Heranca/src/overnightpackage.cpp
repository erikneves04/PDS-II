#include <string>
#include "overnightpackage.h"

OverNightPackage::OverNightPackage(unsigned int peso, unsigned int custoPorQuilo, double taxaPorQuilo, std::string nome, std::string endereco)
    : Package(peso, custoPorQuilo, nome, endereco)
{
    _taxaPorQuilo = taxaPorQuilo;
}

double OverNightPackage::calculate_cost()
{
    double custoBase = Package::calculate_cost();
    double taxaTotal = _taxaPorQuilo * _peso;
    return custoBase + taxaTotal;
}