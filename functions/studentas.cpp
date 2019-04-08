#include "../headers/studentas.h"

void Studentas::set_exam (int a){
    egzaminas = a;
}

void Studentas::set_mark(int a){
    nd.emplace_back(a);
}

double Studentas::ndSum(int x){
    double sum=0;
    for(int z = 0; z < x ; z++) {
        sum +=  nd[z];
    }
    return sum;
}

double Studentas::mediana(int x, int y){
    double med;
    sort(nd.begin(), nd.end());
    if (y % 2 == 0)
    {
        med =  (nd[x / 2 - 1] + nd[x / 2]) / 2.0;
    }
    else
    {
        med = nd[x / 2];
    }
    return med;
}

/*Studentas::Studentas(){

}*/