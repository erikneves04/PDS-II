#ifndef ALOCACAO_H
#define ALOCACAO_H

#include <string>

class Alocacao
{
    private:
        std::string _dia;
        std::string _horario;
        std::string _sala;

    public:
        Alocacao();
        Alocacao(std::string dia, std::string horario, std::string sala);
        void imprimir_dados();
        std::string GetHorario() const;
        std::string GetDia();
        std::string GetSala();
};

#endif