#include <string>
#include "twodaypackage.h"

TwoDayPackage::TwoDayPackage(unsigned int peso, unsigned int custoPorQuilo, double taxaFixa, std::string nome, std::string endereco)
    : Package(peso, custoPorQuilo, nome, endereco)
{
    _taxaFixa = taxaFixa;
}

double TwoDayPackage::calculate_cost()
{
    double custoBase = Package::calculate_cost();
    return custoBase + _taxaFixa;
}