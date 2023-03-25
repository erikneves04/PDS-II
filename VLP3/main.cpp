#include <iostream>
#include <cmath>

/**
 * @brief Calcula o fatorial de um numero inteiro
 *
 * Esta funcao nao faz tratamento de erros: se o numero passado como parametro
 * for igual ou menor a zero, entao ela retorna o valor 1.
 *
 * @param arg O numero cujo fatorial sera calculado
 * @return unsigned O valor do fatorial de arg. Se arg for igual ou menor a
 * zero, entao o valor retornado deve ser 1.
 */
unsigned factorial(int arg)
{
    if (arg <= 0)
        return 1;

    int result = 1;

    for (int i = arg; i > 1; i--)
        result *= i;

    return result;
}

/**
 * @brief Conta a quantidade de inteiros em um certo interval.
 *
 * O intervalo eh formado por dois numeros de ponto flutuante (doubles). A
 * contagem eh inclusiva. Assim, entre 1.0 e 3.0 existem tres inteiros
 * (1, 2 e 3), mas entre 0.2 e 0.9 nao existe nenhum.
 *
 * @param start O inicio do intervalo
 * @param end O final do interval
 * @return unsigned O numero de inteiros contidos dentro do intervalo
 * (inclusive)
 */
unsigned interval(double start, double end)
{
    int count = 0;

    for(int i = ceil(start); i <= floor(end); i++)
    {
        count++;
    }

    return count;
}

int main()
{
    char test = 0;
    std::cin >> test;
    switch (test)
    {
        case 'f':
        {
            int arg = 0;
            std::cin >> arg;
            std::cout << factorial(arg) << std::endl;
        }
        break;
        case 'i':
        {
            double arg0 = 0;
            double arg1 = 0;
            std::cin >> arg0 >> arg1;
            std::cout << interval(arg0, arg1) << std::endl;
        }
        break;
    }
}