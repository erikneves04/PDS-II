#include <iostream>
#include "includes/Alocacao.hpp"

Alocacao::Alocacao(){}
Alocacao::Alocacao(std::string dia, std::string horario, std::string sala)
{
    _dia = dia;
    _horario = horario;
    _sala = sala;
}

void Alocacao::imprimir_dados()
{
    std::cout << _dia << " " << _horario << " " << _sala << std::endl;
}

std::string Alocacao::GetHorario() const
{
    return _horario;
}

std::string Alocacao::GetDia()
{
    return _dia;
}

std::string Alocacao::GetSala()
{
    return _sala;
}