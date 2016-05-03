#ifndef DEFINES_STRUCTURES_H
#define DEFINES_STRUCTURES_H

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define ASCII_CONVERTION 48 // subtracting 48 from the char-values makes 0 = 0, 1 = 1 etc.
#define ROAD_WIDTH		 10
#define DELTA_ANGLE		 0.01

enum ASCII_CHARACTER { decimal_point = -2, minus_sign = -3};
enum ElementType { Segment_Enum, CircleArc_Enum, ClothoArc_Enum };


struct position{
	double x;
    double y;

	position(double _x = 0, double _y = 0){
		x = _x;
		y = _y;
	}
};

inline double convertStringToDouble(string _string){
	double result	= 0;
	int divisor		= 1; /// only divide the result if a comma is present;
	int value;
	for (int digit = _string.length() -1, iterations = 0; digit >= 0; digit--){
		value = _string[digit] - ASCII_CONVERTION; /// start with the least significant digit
		if (value >= 0){ /// if the value-variable corresponds to a number
			result += value * pow(10,iterations); /// The value is added to the right position if no comma is present
            iterations++;
        }
		else if (value == decimal_point){
            /// assign the divisor with the value needed to divide the result, moving the comma to the right position.
            divisor = pow(10, (_string.length() - 1 - digit));
        }
		else if (value == minus_sign){
            result *= -1;
        }
        else{
            cout << "Something went wrong with the ConvertStringToDuble" << endl;
        }
    }
    return result / divisor;
}

template <typename datatype> int sign(datatype _value){
	return (datatype(0) < _value) - (_value < datatype(0));
}

#endif // DEFINES_STRUCTURES_H
