#include <iostream>
#include <string>
#include <math.h>
#include <ClassP.h>

#include "../headers/ClassP.h"
using namespace std;

double Isotope::getA() const {
    return A;
}

void Isotope::setA(double A) {
    if (A>=0)
        Isotope::A = A;
    else {
        Isotope::A = 0;
        cout<<"Definition of A is not correct"<<endl;
    };
}

double Isotope::getZ() const {
    return Z;
}

void Isotope::setZ(double Z) {
    if (Z>=0)
        Isotope::Z = Z;
    else {
        Isotope::Z = 0;
        cout<<"Definition of Z is not correct"<<endl;
    }
}

const string &Isotope::getName() const {
    return name;
}

void Isotope::setName(const string &name) {
    Isotope::name = name;
}

Isotope::Isotope(double A, double Z, const string &name) : name(name) {
    if (Z<A) {
        setA(A);
        setZ(Z);
    }
    else{
        cout<<"Definitions of A and Z are not correct"<<endl;
        setA(0);
        setZ(0);
    }

}

void Isotope::Print() {
    cout<<getName()<<": "<<endl;
    cout<<getA()<<" | "<<getZ()<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////


const string &Element::getName() const {
    return name;
}

void Element::setName(const string &name) {
    Element::name = name;
}

int Element::getN() const {
    return n;
}

void Element::setN(int n) {
    Element::n = n;
}

const vector<Isotope> &Element::getV() const {
    return V;
}

void Element::setV(const vector<Isotope> &V) {
    Element::V = V;
}

Element::Element(const string &name, int n) : name(name), n(n){}

void Element::AddIsotope(Isotope Is, double f) {
    V.push_back(Is);
    F.push_back(f);
}

void Element::Print() {
    cout<<getName()<<": "<<endl;

    cout<<"Изотопный состав:"<<endl;
    for (int i=0;i<n;i++)
        V[i].Print();

    cout<<"Концентрации изотопов в элементе:"<<endl;
    for (int i=0;i<n;i++)
        cout<<F[i]<<" ";
    cout<<endl;
}

const vector<double> &Element::getF() const {
    return F;
}

void Element::setF(const vector<double> &F) {
    Element::F = F;
}

void Element::Check() {
    float S=0;
    for (int i=0;i<n;i++)
        S=S+F[i];
    if ((F.size()==n)&&(V.size()==n)&&(S=100)){
        cout<<"Element is checked. Everything is absolutely amazing!"<<endl;
    }
    else {
        cout<<"Element is checked.Smth wrong. Check it again"<<endl;
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

Material::Material(const string &name, int n, float density) : name(name), n(n), density(density) {}

void Material::AddElement(Element El, double f) {
    V.push_back(El);
    F.push_back(f);
}

void Material::Check() {
    float S=0;
    for (int i=0;i<n;i++)
        S=S+F[i];
    // if ((F.size()==n)&&(V.size()==n)&&(S=100)){
    if ((F.size()==n)&&(V.size()==n)&&(S=100)){
        cout<<"Material is checked. Everything is absolutely amazing!"<<endl;
    }
    else {
        cout<<"Material is checked.Smth wrong. Check it again"<<endl;
    }
}

void Material::Print() {
    cout<<name<<": "<<endl;
    cout<<"Плотность: "<<density<<endl;

    cout<<"Элементный состав:"<<endl;
    for (int i=0;i<n;i++)
        V[i].Print();

    cout<<"Концентрации элементов в элементе:"<<endl;
    for (int i=0;i<n;i++)
        cout<<F[i]<<" ";
    cout<<endl;
}

void Material::setV(Element El) {
    Material::V.push_back(El);
}

const string &Material::getName() const {
    return name;
}

const vector<Element> &Material::getV() const {
    return V;
}

Material_GoldEdition::Material_GoldEdition(const string &name, int n, float density) : Material(name, n, density) {}

void Material_GoldEdition::AddElement(Element El, int nAtoms) {
    setV(El);
    //F.push_back(f);
}

void Material_GoldEdition::Printing() {
    cout<<getName()<<": "<<endl;
    cout<<"Элементный состав:"<<endl;
    vector<Element> V_copy=getV();
    for (int i=0;i<V_copy.size();i++)
        V_copy[i].Print();

}
