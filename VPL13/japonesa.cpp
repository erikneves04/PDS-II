#include "japonesa.hpp"

std::string Japonesa::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */
   
    std::string qtd = std::to_string(m_qtd);
    std::string sushis = std::to_string(_sushi);
    std::string temakis = std::to_string(_temaki);
    std::string hots = std::to_string(_hots);

  return qtd+"X Comida japonesa - "+_combinado+", "+sushis+" sushis, "+temakis+" temakis e "+hots+".";
}

Japonesa::Japonesa(const std::string& combinado, int sushis, int temakis, int hots, int qtd, float valor_unitario) 
{
  _combinado = combinado;
  _sushi = sushis;
  _temaki = temakis;
  _hots = hots;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}