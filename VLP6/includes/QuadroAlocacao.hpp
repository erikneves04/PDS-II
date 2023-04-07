#ifndef QUADRO_ALOCACAO_H
#define QUADRO_ALOCACAO_H

#include <string>
#include <map>
#include <vector>
#include "Disciplina.hpp"
#include "Alocacao.hpp"

class QuadroAlocacao
{
    private:
        std::map<std::string, std::vector<Alocacao>> _alocacoes;
        std::map<std::string, Disciplina> _disciplinas;
    public:
        QuadroAlocacao(); 
        void inserir_alocacao(std::string codigo, std::string nome, std::string dia, std::string horario, std::string sala);
        std::vector<Disciplina> recuperar_disciplinas_mais_ofertadas();
        void imprimir_alocacao_completa();
        void remover_alocacao_disciplina(std::string codigo, std::string horario);
};

#endif