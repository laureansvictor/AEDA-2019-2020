#include "frota.h"
#include <string>

using namespace std;


void Frota::adicionaVeiculo(Veiculo *v1)
{
    veiculos.push_back(v1);
}

int Frota::numVeiculos() const
{
    return veiculos.size();
}

int Frota::menorAno() const
{
    if (numVeiculos() == 0) return 0;
    vector<Veiculo *>::const_iterator it = veiculos.begin();
    int menor=(*it)->getAno();
    it++;
    for(it; it != veiculos.end(); it++)
    {
        if ((*it)->getAno() < menor)
        {
            menor = (*it)->getAno();
        }
    }
    return menor;
}

ostream & operator<<(ostream & o, const Frota & f) {
    vector<Veiculo *>::const_iterator it = f.veiculos.begin();
    while(it!=f.veiculos.end())
    {
        (*it)->info(o);
        it++;
    }
    return o;
}

float Frota::totalImposto() const
{
    if(veiculos.size() == 0) return 0;
    float total=0;
    vector<Veiculo *>::const_iterator it = veiculos.begin();
    while(it !=veiculos.end())
    {
        total +=(*it)->calcImposto();
        it++;
    }
    return total;
}

vector<Veiculo *> Frota::operator() (int a) const
{
    vector<Veiculo *> veiculosAno;
    if (veiculos.size()==0) return veiculosAno;
    vector<Veiculo *>::const_iterator it = veiculos.begin();
    while(it!=veiculos.end())
    {
        if ((*it)->getAno() == a)
            veiculosAno.push_back(*it);
        it++;
    }
    return veiculosAno;
}
