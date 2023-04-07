#include <iostream>
#include "includes/Alocacao.hpp"
#include "includes/Disciplina.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <map>

Disciplina::Disciplina(){}
Disciplina::Disciplina(std::string codigo, std::string nome)
{
    _codigo = codigo;
    _nome = nome;
}

void Disciplina::inserir_alocacao(std::string dia, std::string horario, std::string sala)
{
    Alocacao alocacao = Alocacao(dia, horario, sala);
    _alocacoes.push_back(alocacao);
}

void Disciplina::remover_alocacao(std::string horario)
{
    auto it = _alocacoes.begin();

    while (it != _alocacoes.end())
    {
        if (it->GetHorario() == horario)
        {
            it = _alocacoes.erase(it);
        }
        else
        {
            ++it;
        }
    }
}


void Disciplina::imprimir_alocacao()
{
    for(Alocacao aloc : GetSortedAlocacoes())
        std::cout << _codigo << " " << _nome << " " << aloc.GetDia() << " " << aloc.GetHorario() << " " << aloc.GetSala() << std::endl;
}

std::vector<Alocacao> Disciplina::GetSortedAlocacoes()
{
    std::vector<Alocacao> alocacoesOrdenadas = _alocacoes;
    std::sort(alocacoesOrdenadas.begin(), alocacoesOrdenadas.end(),
              [](const Alocacao& a, const Alocacao& b) { return a.GetHorario() < b.GetHorario(); });

    return alocacoesOrdenadas;
}

std::string Disciplina::GetCodigo()
{
    return _codigo;
}

std::string Disciplina::GetNome()
{
    return _nome;
}

std::vector<Alocacao> Disciplina::GetAlocacoes()
{
    return _alocacoes;
}