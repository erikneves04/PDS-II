#include "../include/sistema.h"
#include <exception>

#include <iostream>

Sistema::Sistema() 
{
    _preco_corrida = 5;    
}

Sistema::Sistema(double preco_corrida) 
{
    if (preco_corrida <= 0)
        throw preco_invalido_e();

    _preco_corrida = preco_corrida;    
}

Sistema::~Sistema() 
{
    _frota.limpar_carros_cadastrados();
    limpar_todos_os_clientes();
}


Cliente* Sistema::cadastra_cliente(std::string nome) 
{
    if (_clientes.count(nome) > 0)
        throw cliente_ja_existe_e();
    
    Cliente *cliente = new Cliente(nome);
    _clientes[nome] = cliente;

    return cliente;
}

void Sistema::adicionar_carro(std::string cor, unsigned int id) 
{
    _frota.cadastrar_carro(cor, id);
}

void Sistema::adicionar_carro(Carro* carro) 
{
    _frota.adicionar_carro(carro);
}

Carro* Sistema::busca_uber(std::string nome)
{
    if (_clientes.count(nome) == 0) 
        throw cliente_nao_existe_e();

    Cliente* cliente = _clientes.at(nome);
    
    if (cliente->get_saldo() < _preco_corrida) 
        throw sem_saldo_e();
      
    Carro* carro = _frota.alocar_carro();
    
    carro->seta_ocupado();
    cliente->remover_saldo(_preco_corrida);

    return carro;
}

void Sistema::limpar_todos_os_clientes()
{
    for(auto cliente : _clientes)
    {
        delete(cliente.second);
    }
}