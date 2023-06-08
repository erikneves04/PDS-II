#ifndef CELULAR_H
#define CELULAR_H

#include <string>

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes de um celular.
 */
class Celular
{
    public:
        /**
         * @brief Construtor padrao que inicializa todas as variaveis da classe.
         *
         * @param modelo Modelo do celular. Ex: Galaxy s20.
         * @param fabricante Fabricante do celular. Ex: Samsung.
         * @param armazenamento Memoria interna total compartilhada. Ex: 4GB.
         * @param memoria Memoria RAM do celular. Ex: 4GB.
         * @param peso Peso em Kg do celular. Ex: 0.180Kg.
         * @param cor Cor do celular. Ex: branco.
         * @param qtd Quantidade de celulares do lote. Ex: 10 unidades.
         * @param valor Valor unitario do celular. Ex: R$ 756.25.
         */
        Celular(std::string modelo,
                std::string fabricante,
                int armazenamento,
                int memoria,
                double peso,
                std::string cor,
                int qtd,
                float valor);

        /**
         * @brief Implementa a sobrecarga do operador logico menor que ('<').
         * Utilizado na ordenacao dos objetos da classe.
         *
         * @param other Instancia de outro objeto da classe.
         * @return true Retorna true quando o objeto atual for 'menor' que o other
         * @return false Retorna false quando o objeto atual for 'maior' que o other
         */
        bool operator<(const Celular &other);

    public:
        std::string _modelo;
        std::string _fabricante;
        std::string _cor;
        int _armazenamento;
        int _memoria;
        int _qtd;
        int _id;
        double _peso;
        float _valor;

    private:
        static int _ultimo_Id;
        // TODO: Declare aqui uma variavel estatica para atribuir os codigos dos
        // celulares. Lembre-se que o primeiro celular recebe o codigo 1, o
        // segundo recebe o codigo 2, e assim sucessivamente.
};

#endif