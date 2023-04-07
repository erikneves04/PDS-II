#include <iostream>
#include "includes/Processo.hpp"

using namespace std;

Processo::Processo(int id, std::string name, int priority)
{
    _id = id;
    _priority = priority;
    _name = name;
}

void Processo::imprimir_dados()
{
    cout << _id << " " << _name << " " << _priority << endl;
}

int Processo::GetPriority()
{
    return _priority;
}

int Processo::GetId()
{
    return _id;
}