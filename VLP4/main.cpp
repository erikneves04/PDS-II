#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

class Complexo 
{
    private:
        double _real;
        double _imag;

    public:
        double modulo() 
        {
            return sqrt(_real * _real + _imag * _imag);
        }

        Complexo conjugado() 
        {
            Complexo numero;
            numero.SetValues(_real, _imag * (-1));

            return numero;
        }

        Complexo inverso() 
        {
            Complexo numero;
            double thisModule = modulo();
            
            double realInverso = _real / thisModule / thisModule;
            double imagInverso = _imag * (-1) / thisModule / thisModule;

            numero.SetValues(realInverso, imagInverso);

            return numero;
        }

        Complexo soma(Complexo y) 
        {
            Complexo resultado;
            
            double real = _real + y._real;
            double imag = _imag + y._imag;

            resultado.SetValues(real, imag);
            return resultado;
        }

        Complexo subtrair(Complexo y) 
        {
            Complexo resultado;
            
            double real = _real - y._real;
            double imag = _imag - y._imag;

            resultado.SetValues(real, imag);
            return resultado;
        }

        Complexo multiplicar(Complexo y) 
        {
            Complexo resultado;
            
            double real = _real * y._real;
            double imag = _imag * y._imag;

            resultado.SetValues(real, imag);
            return resultado;
        }

        Complexo dividir(Complexo y) 
        {
            return multiplicar(y.inverso());
        }

        double GetReal()
        {
            return _real;
        }

        double GetImag()
        {
            return _imag;
        }
        
        void SetValues(double real, double imag)
        {
            _real = real;
            _imag = imag;
        }
};

double CalculaDelta(double a, double b, double c)
{
    return std::pow(b, 2) - 4 * a * c;
}

Complexo CalculaRaiz(double delta, double a, double b, bool positiva)
{
    Complexo resultado;
    if (delta >= 0)
    {
        double deltaSqrt = sqrt(delta);
        if (!positiva)
            deltaSqrt *= -1;

        double real = (-b + deltaSqrt) / (2 * a);
        resultado.SetValues(real, 0);

        return resultado;
    }

    double deltaSqrt = sqrt(-delta);
    if (!positiva)
        deltaSqrt *= -1;

    double real = (-b) / (2 * a);
    double imag = deltaSqrt / (2 * a);

    resultado.SetValues(real, imag);

    return resultado;
}

pair<Complexo, Complexo> raizes(double a, double b, double c) 
{
    double delta = CalculaDelta(a, b, c);
    Complexo x1 = CalculaRaiz(delta, a, b, true);
    Complexo x2 = CalculaRaiz(delta, a, b, false);
    return make_pair(x1, x2);
}

int main () 
{
    cout << "Digite os coeficientes da equação f(x) = ax^2 + bx + c:" << endl;

    double a, b, c;
    cin >> a >> b >> c;

    pair<Complexo, Complexo> r = raizes(a, b, c);

    cout << "(" << r.first.GetReal() << ", " << r.first.GetImag() << ") "
        << "(" << r.second.GetReal() << ", " << r.second.GetImag() << ")" << endl;

    return 0;
}