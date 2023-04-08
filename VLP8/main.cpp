#include <iostream>

using namespace std;

int main(){

    // 1) Declare uma variável do tipo inteiro e atribua o valor '10'
    int inteiro = 10;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *inteiroPointer = nullptr;

    // 3) Declare um vetor de inteiros e inicialize com valores de 9 a 0 (nessa ordem)
    int inteiros[] = {9,8,7,6,5,4,3,2,1,0};

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &inteiro << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << inteiro << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &inteiroPointer << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << inteiroPointer << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << inteiros << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &inteiros[0] << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << inteiros[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    inteiroPointer = &inteiro;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << inteiroPointer << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *inteiroPointer << endl;

    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (2)
    cout << (inteiroPointer == &inteiro) << endl;

    // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *inteiroPointer = 5;

    // 16) Imprima o VALOR da variável declarada em (1)
    cout << inteiro << endl;

    // 17) Atribua o ENDEREÇO apontado pela variável (3) à variável declarada em (2)
    inteiroPointer =  inteiros;

    // 18) Imprima o VALOR da variável declarada em (2)
    cout << inteiroPointer << endl;

    // 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *inteiroPointer << endl;

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    inteiroPointer = &inteiros[0];

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << inteiroPointer << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *inteiroPointer << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for(int i=0; i<10; i++)
    {
        (*inteiroPointer) = (*inteiroPointer) * 10;
        inteiroPointer++;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for(int i=0; i<10; i++)
    {
        cout << inteiros[i];

        if (i == 9)
            cout << endl;
        else
            cout << " ";
    }

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    for(int value : inteiros)
    {
        cout << value;

        if (value == inteiros[9])
            cout << endl;
        else
            cout << " ";
    }

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    inteiroPointer =  &inteiros[0];
    for(int i=0; i<10; i++)
    {
        cout << *inteiroPointer;

        if (i == 9)
            cout << endl;
        else
            cout << " ";

        inteiroPointer++;
    } 

    // 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)
    inteiroPointer = &inteiros[4];

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << inteiroPointer << endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *inteiroPointer << endl;

    // 30) Imprima o VALOR guardado no: ENDEREÇO do ponteiro (2) decrementado de 4
    cout << *(inteiroPointer - sizeof(int)) << endl;

    // 31) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int ** pointerPointer = &inteiroPointer;

    // 32) Imprima o VALOR da variável declarada em (31)
    cout << pointerPointer << endl;

    // 33) Imprima o ENDEREÇO da variável declarada em (31)
    cout << &pointerPointer << endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO apontado por (31)
    cout << *pointerPointer << endl;

    // 35) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (31)
    cout << **pointerPointer << endl;
    
    return 0;
}