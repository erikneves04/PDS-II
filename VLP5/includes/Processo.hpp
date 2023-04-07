#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Processo
{
    private:
        int _id;
        int _priority;
        std::string _name;
    
    public:
        Processo(int id, std::string name, int priority);
        void imprimir_dados();
        int GetPriority();
        int GetId();
};

#endif