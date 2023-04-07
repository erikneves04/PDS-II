#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <vector>
#include <map>
#include "Alocacao.hpp"

class Disciplina
{
    private:
        std::string _codigo;
        std::string _nome;
        std::vector<Alocacao> _alocacoes;
    public:
        Disciplina();
        Disciplina(std::string codigo, std::string nome);
        void inserir_alocacao(std::string dia, std::string horario, std::string sala);
        void remover_alocacao(std::string horario);
        void imprimir_alocacao();
        std::string GetCodigo();
        std::string GetNome();
        std::vector<Alocacao> GetAlocacoes();
        std::vector<Alocacao> GetSortedAlocacoes();
};

#endif