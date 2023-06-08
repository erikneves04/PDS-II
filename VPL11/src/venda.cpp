#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <list>

void Venda::adicionaCelular(const Celular& celular) 
{
    m_celulares.push_back(celular);
}

void Venda::ordena() 
{
    m_celulares.sort();
}

void Venda::recarregaEstoque(int cod, int qtd) 
{
    for(Celular cel : m_celulares)
    {
        if (cel._id == cod)
        {
            cel._qtd += qtd;
            break;
        }     
    }
}

void Venda::efetuaVenda(int cod, int qtd) 
{
    for(Celular& cel : m_celulares)
    {
        if (cel._id == cod)
        {
            if (cel._qtd >= qtd)
                cel._qtd -= qtd;
            break;
        }     
    }
}

void Venda::aplicaDesconto(const std::string& fabricante, float desconto) 
{
    for(Celular cel : m_celulares)
    {
        if (cel._fabricante == fabricante)
        {
            cel._valor -= ((cel._valor/100) * desconto);
        }     
    }
}

void Venda::removeModelo(int cod) 
{
    for (auto it = m_celulares.begin(); it != m_celulares.end(); ++it) {
        if (it->_id == cod) {
            m_celulares.erase(it);
            break;
        }
    }
}

std::string doubleToCurrency(double number) {
    std::ostringstream oss;
    oss << "R$" << std::fixed << std::setprecision(2) << number;
    std::string currency = oss.str();
    //currency.replace(currency.find("+"), 1, "");

    return currency;
}

void Venda::imprimeEstoque() const 
{
    for(Celular celular : m_celulares)
    {
        if (celular._qtd > 0)
        {
            std::string qtdFlag = (celular._qtd == 1) ? "restante" : "restantes";
            celular._cor[0] = std::toupper(celular._cor[0]);

            std::cout << celular._fabricante << " " << celular._modelo << ", ";
            std::cout << celular._armazenamento << "GB, " << celular._memoria << "GB RAM, ";
            std::cout << (celular._peso * 1000) << " gramas, " << celular._cor << ", ";
            std::cout << celular._qtd << " " << qtdFlag << "," << doubleToCurrency(celular._valor) << std::endl;
        }
    }
}