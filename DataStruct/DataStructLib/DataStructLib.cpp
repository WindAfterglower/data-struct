#include <iostream>
#include "Vector.h"

int main(){

    Vector* v = new Vector(3);
    for (int i = 0;i < 10;i++) v->Insert(i, i + 2);
    v->PrintVector();
    v->Delete(2);
    v->PrintVector();

    delete v;
    
    Vector newV(3);
    for (int i = 0;i < 5;i++) newV.Insert(i, i* 2);
    newV.PrintVector();
    newV.Delete(5);
    newV.PrintVector();
}



