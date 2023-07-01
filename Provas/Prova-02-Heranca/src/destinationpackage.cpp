#include <map>
#include <string>
#include <vector>

#include "package.h"
#include "destinationpackages.h"

void DestinationPackages::add_package(Package* g)
{
    std::string destinatario = g->GetDestinatario();
    if (_destinatarios.count(destinatario) < 1)
        _destinatarios[destinatario] = std::vector<Package*>();
    
    _destinatarios[destinatario].push_back(g);
}

double DestinationPackages::custo_total()
{
    double total = 0;

    for(auto pair : _destinatarios)
    {
        std::vector<Package*> packages = pair.second;
        for(Package* package : packages)
        {
            total += package->calculate_cost();
        }
    }

    return total;
}

double DestinationPackages::custo_total(std::string destinatario)
{
    if (_destinatarios.count(destinatario) < 1)
        return 0;

    double total = 0;
    std::vector<Package*> packages = _destinatarios[destinatario];
    
    for(Package* package : packages)
    {
        total += package->calculate_cost();
    }

    return total;
}