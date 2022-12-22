#include "LA_Array.h"
#include <algorithm>
#include <numeric>

LA_Array::LA_Array() {
    array = new double[1];
    array[0] = 0;
    size = 1;
}

LA_Array::LA_Array(int size) {
    array = new double[size];
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
    this->size = size;
}

LA_Array::LA_Array(double *array, int size) {
    this->array = new double[size];
    for (int i = 0; i < size; i++) {
        this->array[i] = array[i];
    }
    this->size = size;
}

LA_Array::LA_Array(const LA_Array &array) {
    this->array = new double[array.size];
    for (int i = 0; i < array.size; i++) {
        this->array[i] = array.array[i];
    }
    this->size = array.size;
}

void LA_Array::operator+(const LA_Array &array) {
    if (this->size == array.size) {
        for (int i = 0; i < this->size; i++) {
            this->array[i] += array.array[i];
        }
    }
}

LA_Array LA_Array::operator-(const LA_Array &array) {
    if (this->size == array.size) {
        LA_Array result(this->size);
        for (int i = 0; i < this->size; i++) {
            result.array[i] = this->array[i] - array.array[i];
        }
        return result;
    }
    return LA_Array();
}

LA_Array LA_Array::operator*(const LA_Array &array) {
    if (this->size == array.size) {
        LA_Array result(this->size);
        for (int i = 0; i < this->size; i++) {
            result.array[i] = this->array[i] * array.array[i];
        }
        return result;
    }
    return LA_Array();
}

LA_Array LA_Array::operator/(const LA_Array &array) {
    if (this->size == array.size) {
        LA_Array result(this->size);
        for (int i = 0; i < this->size; i++) {
            result.array[i] = this->array[i] / array.array[i];
        }
        return result;
    }
    return LA_Array();
}

LA_Array LA_Array::operator+(double value) {
    LA_Array result(this->size);
    for (int i = 0; i < this->size; i++) {
        result.array[i] = this->array[i] + value;
    }
    return result;
}

void LA_Array::operator+=(const LA_Array &array) {
    if (this->size == array.size) {
        for (int i = 0; i < this->size; i++) {
            this->array[i] += array.array[i];
        }
    }
}
void LA_Array::operator-=(const LA_Array &array) {
    if (this->size == array.size) {
        for (int i = 0; i < this->size; i++) {
            this->array[i] -= array.array[i];
        }
    }
}

LA_Array LA_Array::operator-(double value) {
    LA_Array result(this->size);
    for (int i = 0; i < this->size; i++) {
        result.array[i] = this->array[i] - value;
    }
    return result;
}

LA_Array LA_Array::operator*(double value) {
    LA_Array result(this->size);
    for (int i = 0; i < this->size; i++) {
        result.array[i] = this->array[i] * value;
    }
    return result;
}

LA_Array LA_Array::operator/(double value) {
    LA_Array result(this->size);
    for (int i = 0; i < this->size; i++) {
        result.array[i] = this->array[i] / value;
    }
    return result;
}

LA_Array LA_Array::operator=(const LA_Array &array) {
    this->array = new double[array.size];
    for (int i = 0; i < array.size; i++) {
        this->array[i] = array.array[i];
    }
    this->size = array.size;
    return *this;
}


double LA_Array::operator[](int index) {
    return array[index];
}

double LA_Array::get(int index) {
    return array[index];
}

void LA_Array::set(int index, double value) {
    array[index] = value;
}

int LA_Array::getSize() {
    return size;
}
bool LA_Array::operator==(const LA_Array &input) {
    if (this->size == input.size) {
        for (int i = 0; i < this->size; i++) {
            if (this->array[i] != input.array[i]) {
                return false;
            }
        }
        return true;
    }
    return true;

}


LA_Array::~LA_Array() {
    delete[] array;
}

//TODO: Write Unit Tests

