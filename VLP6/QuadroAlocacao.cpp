#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

#include "includes/Alocacao.hpp"
#include "includes/Disciplina.hpp"
#include "includes/QuadroAlocacao.hpp"

QuadroAlocacao::QuadroAlocacao()
{

}

void QuadroAlocacao::inserir_alocacao(std::string codigo, std::string nome, std::string dia, std::string horario, std::string sala)
{
    Disciplina disciplina = Disciplina(codigo, nome);

    if (_disciplinas.count(codigo) != 0)
    {
        disciplina = _disciplinas[codigo];
    }
    else
    { 
       _disciplinas[codigo] = disciplina; 
    }

    Alocacao alocacao = Alocacao(dia, horario, sala);
    _disciplinas[codigo].inserir_alocacao(dia, horario, sala);

    _alocacoes[codigo].push_back(alocacao);
}

bool CompareAlocacaoVector(const std::pair<std::string, std::vector<Alocacao>>& p1, const std::pair<std::string, std::vector<Alocacao>>& p2) {
    return p1.second.size() > p2.second.size();
}

std::vector<Disciplina> QuadroAlocacao::recuperar_disciplinas_mais_ofertadas()
{    
    std::map<std::string, std::vector<Alocacao>> disAlocacoes;

    for(std::pair<std::string, Disciplina> pair : _disciplinas)
    {
        Disciplina dis = pair.second;
        for(Alocacao aloc : dis.GetAlocacoes())
            disAlocacoes[dis.GetCodigo()].push_back(aloc);
    }

    std::vector<std::pair<std::string, std::vector<Alocacao>>> sortedMap(disAlocacoes.begin(), disAlocacoes.end());
    std::sort(sortedMap.begin(), sortedMap.end(), CompareAlocacaoVector);

    std::vector<Disciplina> disciplinasMaisOfertadas;


    // eu sei que isso é horrivel porém estava cansado...
    int lastLenght = -1;
    for(std::pair<std::string, std::vector<Alocacao>> pair : sortedMap)
    {
        Disciplina disciplina = _disciplinas[pair.first];

        int size = disciplina.GetAlocacoes().size();
        
        if (lastLenght == -1)
            lastLenght = size;
        else if (lastLenght != size)
            break;

        disciplinasMaisOfertadas.push_back(disciplina);
    }
    return disciplinasMaisOfertadas;
}

void QuadroAlocacao::imprimir_alocacao_completa()
{
    std::vector<std::string> keys;
    for(std::pair<std::string, Disciplina> pair: _disciplinas)
    {
        keys.push_back(pair.first);
    }

    std::sort(keys.begin(), keys.end());
    for(std::string key : keys)
    {
        Disciplina disciplina = _disciplinas[key];        
        for(Alocacao aloc : disciplina.GetSortedAlocacoes())
            std::cout << disciplina.GetCodigo() << " " << disciplina.GetNome() << " " << aloc.GetDia() << " " << aloc.GetHorario() << " " << aloc.GetSala() << std::endl;
    }
}

void QuadroAlocacao::remover_alocacao_disciplina(std::string codigo, std::string horario)
{
    _disciplinas[codigo].remover_alocacao(horario);

    std::vector<Alocacao> alocacoes = _alocacoes[codigo];

    alocacoes.erase(std::remove_if(alocacoes.begin(), alocacoes.end(),
                                   [horario](const Alocacao& aloc) {
                                       return aloc.GetHorario() == horario;
                                   }),
                    alocacoes.end());
}