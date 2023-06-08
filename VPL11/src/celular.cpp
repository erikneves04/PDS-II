#include "../include/celular.hpp"

int Celular::_ultimo_Id = 0;

Celular::Celular(std::string modelo,
                 std::string fabricante,
                 int armazenamento,
                 int memoria,
                 double peso,
                 std::string cor,
                 int qtd,
                 float valor) 
{
    _modelo = modelo;
    _fabricante = fabricante;
    _cor = cor;
    _armazenamento = armazenamento;
    _memoria = memoria;
    _peso = peso;
    _qtd = qtd;
    _valor = valor;

    _ultimo_Id++;
    _id = _ultimo_Id;
}

bool Celular::operator<(const Celular& other) 
{
    std::string thisColumn = _fabricante + " " + _modelo;
    std::string otherColumn = other._fabricante + " " + other._modelo;

    return thisColumn < otherColumn;
}