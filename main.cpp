#include <iostream>
#include <vector>
#include "headers/ClassP.h"
using namespace std;

int main() {
    Isotope Fe(56,26,"fe");
    //Fe.Print();
    Isotope O(16,8,"o");

    Element FeO("FeO",2);
    FeO.AddIsotope(Fe,95);
    FeO.AddIsotope(O,5);
    //FeO.Check();
    //FeO.Print();


    Isotope Al(26,13,"al");
    Element AlO("AlO",2);
    FeO.AddIsotope(Al,90);
    FeO.AddIsotope(O,10);

    Material New("NewMaterial",2,20);
    New.AddElement(FeO,50);
    New.AddElement(AlO,50);
    //New.Check();
    //New.Print();

    /////////////////////////////////ГРАФИТ
    Isotope C12(12,6,"c12");
    Isotope C13(13.003,6,"c13");

    Element C("C",2);
    C.AddIsotope(C12,99);
    C.AddIsotope(C13,1);

    Material Graphite("Графит",1,2.01);
    Graphite.AddElement(C,100);
    Graphite.Check();
    Graphite.Print();

    /////////////////////////////////SiO2
    Isotope O16(15.995,8,"o16");
    Isotope O17(16.999,8,"o17");
    Isotope O18(17.999,8,"o18");

    Element Oxygene ("O",3);
    Oxygene.AddIsotope(O16,99.7);
    Oxygene.AddIsotope(O17,0.1);
    Oxygene.AddIsotope(O18,0.2);


    Isotope Si28 (27.977,14,"si28");
    Isotope Si29 (28.977,14,"si29");
    Isotope Si30 (29.974,14,"si30");

    Element Si ("Si",3);
    Si.AddIsotope(Si28,99.6);
    Si.AddIsotope(Si29,0.1);
    Si.AddIsotope(Si30,0.3);

    Material_GoldEdition SiO2("SiO2",2,100.562);
    SiO2.AddElement(Si,1);
    SiO2.AddElement(Oxygene,2);
    SiO2.Printing();

    /////////////////////////////////BGO (Bi4Ge3O12)
    Isotope Bi(208.9804,83,"bi");
    Isotope Ge (72.630,32,"ge");

    return 0;
}