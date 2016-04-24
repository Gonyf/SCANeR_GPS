#ifndef DEFINES_STRUCTURES_H
#define DEFINES_STRUCTURES_H

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define ASCII_CONVERTION 48

enum ElementType { Segment_Enum, CircleArc_Enum, ClothoArc_Enum };


struct position{
    double x;
    double y;
};

inline double convertStringToDouble(string _string){
    double result = 0;
    int divisor = 1; /// only divide the result if a comma is present;
    for (int digit = _string.length() -1, iterations; digit >= 0; digit--){
        int value = int(_string[digit] - ASCII_CONVERTION); /// start with the least significant digit
        if (value >= 0){ /// if value does not correspond to a comma
            result += value * pow(10,iterations); /// The value is added to the right position if no comma is present
            iterations++;
        }
        else if (value == -2){
            /// assign the divisor with the value needed to divide the result, moving the comma to the right position.
            divisor = pow(10, (_string.length() - 1 - digit));
        }
        else if (value == -3){
            result *= -1;
        }
        else{
            cout << "Something went wrong with the ConvertStringToDuble" << endl;
        }
    }
    return result / divisor;
}





#endif // DEFINES_STRUCTURES_H
