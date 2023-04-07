#include "includes/ListaProcessos.hpp"
#include "includes/Processo.hpp"

using namespace std;
    
int ListaProcessos::FindPositionForPriority(int priority)
{
    int i;

    for(i=0; i<_processList.size(); i++)
    {
        if (priority > _processList[i].GetPriority())
            break;
    }

    return i;
}

Processo ListaProcessos::RemoveForIndex(int index)
{
    Processo process = _processList[index];

    _processList.erase(_processList.begin() + index);
    
    return process;
}

ListaProcessos::ListaProcessos()
{
    _processList = vector<Processo>();
}

void ListaProcessos::adicionar_processo(Processo process)
{
    int position = FindPositionForPriority(process.GetPriority());

    vector<Processo>::iterator it;
    it = _processList.begin() + position;

    _processList.insert(it, process);
}

Processo ListaProcessos::remover_processo_maior_prioridade()
{
    return RemoveForIndex(0);
}

Processo ListaProcessos::remover_processo_menor_prioridade()
{
    int index = _processList.size() - 1;
    return RemoveForIndex(index);
}

Processo ListaProcessos::remover_processo_por_id(int id)
{
    int index = -1;

    for(int i=0; i < _processList.size(); i++)
    {
        if (_processList[i].GetId() == id)
        {
            index = i;
            break;
        }
    }

    return RemoveForIndex(index);
}

void ListaProcessos::imprimir_lista()
{
    for(Processo process : _processList)
        process.imprimir_dados();
}