#include <iostream>
#include <string>
#include <vector>

#include "includes/Alocacao.hpp"
#include "includes/Disciplina.hpp"
#include "includes/QuadroAlocacao.hpp"
#include "avaliacao_basica_escalonador.hpp"

using namespace std;

int main()
{
    QuadroAlocacao quadro;

    bool isValidCommand = true;
    while(isValidCommand){
        string command;
        cin >> command;

        if (command == "a") {
            string nome, codigo, horario, dia, sala;
            cin >> codigo >> nome >> dia >> horario >> sala;
            
            quadro.inserir_alocacao(codigo, nome, dia, horario, sala);
        } 
        else if (command == "m") 
        {
            vector<Disciplina> maisOfertadas = quadro.recuperar_disciplinas_mais_ofertadas();
            for(Disciplina disciplina : maisOfertadas)
            {
                disciplina.imprimir_alocacao();
            }
            
        } 
        else if (command == "r") 
        {
            string codigo, horario;
            cin >> codigo >> horario;

            quadro.remover_alocacao_disciplina(codigo, horario);
        } 
        else if (command == "p") 
        {
            quadro.imprimir_alocacao_completa();
        } 
        else if (command == "b") 
        {
            avaliacao_basica();
        }
        else 
        {
            isValidCommand = false;
        }
    }

    return 0;
}