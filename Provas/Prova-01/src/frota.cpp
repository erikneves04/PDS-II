#include "../include/frota.h"

void Frota::adicionar_carro(Carro *carro) 
{
    _carros.push_back(carro);
}

Carro* Frota::alocar_carro() 
{
    if (_carros.empty()) 
        throw zero_carros_disponiveis_e();
    
    Carro* alocado = _carros.front();
    _carros.pop_front();

    _carros_alocados[alocado->get_id()] = alocado;

    return alocado;
}

void Frota::cadastrar_carro(std::string cor, unsigned int id)
{
    for(auto carro : _carros)
    {
        if (id == carro->get_id())
            throw id_ja_existe_e();
    }

    Carro* novoCarro = new Carro(cor, id);
    
    adicionar_carro(novoCarro);
}

void Frota::limpar_carros_cadastrados()
{
    for(auto carro : _carros)
    {
        delete(carro);
    }

    for(auto carro : _carros_alocados)
    {
        delete(carro.second);
    }
}