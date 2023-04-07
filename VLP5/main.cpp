#include <iostream>
#include "includes/Processo.hpp"
#include "includes/ListaProcessos.hpp"
#include <string>
#include "avaliacao_basica_escalonador.hpp"

using namespace std;

int main()
{
    ListaProcessos taskManager = ListaProcessos();

    bool isValidCommand = true;
    while(isValidCommand){
        string command;
        cin >> command;

        if (command == "a") {
            int id, priority;
            string name;
            cin >> id >> name >> priority;
            taskManager.adicionar_processo(Processo(id, name, priority));
        } else if (command == "m") {
            taskManager.remover_processo_maior_prioridade();
        } else if (command == "n") {
            taskManager.remover_processo_menor_prioridade();
        } else if (command == "r") {
            int id;
            cin >> id;
            taskManager.remover_processo_por_id(id);
        } else if (command == "p") {
            taskManager.imprimir_lista();
        } else if (command == "b") {
            avaliacao_basica();
        }else {
            isValidCommand = false;
        }
    }

    return 0;
}