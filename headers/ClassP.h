#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef WORK4_CLASSP_H
#define WORK4_CLASSP_H

class Isotope{
private:
    double A,Z;
    string name;
public:
    double getA() const;

    void setA(double A);

    double getZ() const;

    void setZ(double Z);

    const string &getName() const;

    void setName(const string &name);

    Isotope(double A, double Z, const string &name);

    void Print();
};

class Element{
private:
    string name;
    int n;
    vector <Isotope> V;
    vector <double> F;
public:
    const vector<double> &getF() const;

    void setF(const vector<double> &F);

    const string &getName() const;

    void setName(const string &name);

    int getN() const;

    void setN(int n);

    const vector<Isotope> &getV() const;

    void setV(const vector<Isotope> &V);

    Element(const string &name, int n);

    void AddIsotope(Isotope Is, double f);

    void Print();

    void Check();
};

class Material {
private:
    string name;
    int n;
    float density;
    vector<Element> V;
    vector<float> F;
public:
    const vector<Element> &getV() const;

    const string &getName() const;

    void setV(Element El);

    Material(const string &name, int n, float density);
    void AddElement(Element El,double f);
    void Check();
    void Print();
};

class Material_GoldEdition: public Material{
private:
public:
    Material_GoldEdition(const string &name, int n, float density);
    void AddElement(Element El,int nAtoms);
    void Printing();
};

#endif //WORK4_CLASSP_H
