#include "rational.h"

#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;
#include <math.h>

int main(int argc, char *argv[])
{
    long int n,d;
    char c;
for(int i = 1; i < argc; ++i){
    std::fstream fs;
    fs.open(argv[i], std::fstream::in);

    fs >> n >>  c >> d;
    Rational rn1(n,d);
    fs >> n >>  c >> d;
    Rational rn2(n,d);

    cout << endl;
    cout << rn1 << " + " << rn2 << " = " << rn1+rn2 << "\n";
    cout << rn1 << " - " << rn2 << " = " << rn1-rn2 << "\n";
    cout << rn1 << " * " << rn2 << " = " << rn1*rn2 << "\n";
    cout << rn1 << " / " << rn2 << " = " << rn1/rn2 << "\n\n";
}

    return 0;
}
