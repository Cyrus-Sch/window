//
// Created by Jed Knauer on 22.12.22.
//

#ifndef WINDOW_LA_ARRAY_H
#define WINDOW_LA_ARRAY_H


class LA_Array {
    double *array;
    int size;
public:
    LA_Array();
    LA_Array(int size);
    LA_Array(double *array, int size);
    LA_Array(const LA_Array &array);
    void operator+(const LA_Array &array);
    LA_Array operator-(const LA_Array &array);
    LA_Array operator*(const LA_Array &array);
    LA_Array operator/(const LA_Array &array);
    LA_Array operator+(double value);
    LA_Array operator-(double value);
    LA_Array operator*(double value);
    LA_Array operator/(double value);
    LA_Array operator=(const LA_Array &array);
    void operator+=(const LA_Array &array);
    void operator-=(const LA_Array &array);
    bool operator==(const LA_Array &input);
    double operator[](int index);
    double get(int index);
    void set(int index, double value);
    int getSize();
    ~LA_Array();
};



#endif //WINDOW_LA_ARRAY_H
