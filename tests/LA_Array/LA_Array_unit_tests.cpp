//
// Created by Jed Knauer on 22.12.22.
//

#include "../../LA_Array.h"
#include <gtest/gtest.h>

TEST(LA_Array, LA_Array) {
    LA_Array array;
    ASSERT_EQ(array.getSize(), 1);
    ASSERT_EQ(array.get(0), 0);
}

TEST(LA_Array, LA_Array_size) {
    LA_Array array(5);
    ASSERT_EQ(array.getSize(), 5);
    ASSERT_EQ(array.get(0), 0);
    ASSERT_EQ(array.get(1), 0);
    ASSERT_EQ(array.get(2), 0);
    ASSERT_EQ(array.get(3), 0);
    ASSERT_EQ(array.get(4), 0);
}

TEST(LA_Array, LA_Array_array) {
    double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    ASSERT_EQ(la_array.getSize(), 5);
    ASSERT_EQ(la_array.get(0), 1);
    ASSERT_EQ(la_array.get(1), 2);
    ASSERT_EQ(la_array.get(2), 3);
    ASSERT_EQ(la_array.get(3), 4);
    ASSERT_EQ(la_array.get(4), 5);
}

TEST(LA_Array, LA_Array_copy) {
    double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    LA_Array la_array_copy(la_array);
    ASSERT_EQ(la_array_copy.getSize(), 5);
    ASSERT_EQ(la_array_copy.get(0), 1);
    ASSERT_EQ(la_array_copy.get(1), 2);
    ASSERT_EQ(la_array_copy.get(2), 3);
    ASSERT_EQ(la_array_copy.get(3), 4);
    ASSERT_EQ(la_array_copy.get(4), 5);
}

TEST(LA_Array, LA_Array_add) {
    double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    LA_Array la_array_copy(array, 5);
    la_array_copy + la_array;
    ASSERT_EQ(la_array_copy.getSize(), 5);
    ASSERT_EQ(la_array_copy.get(0), 2);
    ASSERT_EQ(la_array_copy.get(1), 4);
    ASSERT_EQ(la_array_copy.get(2), 6);
    ASSERT_EQ(la_array_copy.get(3), 8);
    ASSERT_EQ(la_array_copy.get(4), 10);
}
TEST(LA_Array, LA_Array_subtract) {
    double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    LA_Array la_array_copy(array, 5);
    LA_Array la_array_result = la_array_copy - la_array;
    ASSERT_EQ(la_array_result.getSize(), 5);
    ASSERT_EQ(la_array_result.get(0), 0);
    ASSERT_EQ(la_array_result.get(1), 0);
    ASSERT_EQ(la_array_result.get(2), 0);
    ASSERT_EQ(la_array_result.get(3), 0);
    ASSERT_EQ(la_array_result.get(4), 0);
}

TEST(LA_Array, LA_Array_multiply) {
    double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    LA_Array la_array_copy(array, 5);
    LA_Array la_array_result = la_array_copy * la_array;
    ASSERT_EQ(la_array_result.getSize(), 5);
    ASSERT_EQ(la_array_result.get(0), 1);
    ASSERT_EQ(la_array_result.get(1), 4);
    ASSERT_EQ(la_array_result.get(2), 9);
    ASSERT_EQ(la_array_result.get(3), 16);
    ASSERT_EQ(la_array_result.get(4), 25);
}

TEST(LA_Array, LA_Array_divide) {
    double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    LA_Array la_array_copy(array, 5);
    LA_Array la_array_result = la_array_copy / la_array;
    ASSERT_EQ(la_array_result.getSize(), 5);
    ASSERT_EQ(la_array_result.get(0), 1);
    ASSERT_EQ(la_array_result.get(1), 1);
    ASSERT_EQ(la_array_result.get(2), 1);
    ASSERT_EQ(la_array_result.get(3), 1);
    ASSERT_EQ(la_array_result.get(4), 1);
}

TEST(LA_Array, LA_Array_add_scalar) {
    double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    LA_Array la_array_copy(array, 5);
    la_array_copy = la_array + 1;
    ASSERT_EQ(la_array_copy.getSize(), 5);
    ASSERT_EQ(la_array_copy.get(0), 2);
    ASSERT_EQ(la_array_copy.get(1), 3);
    ASSERT_EQ(la_array_copy.get(2), 4);
    ASSERT_EQ(la_array_copy.get(3), 5);
    ASSERT_EQ(la_array_copy.get(4), 6);
}

TEST(LA_Array, LA_Array_subtract_scalar) {
    double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    LA_Array la_array_copy(array, 5);
    LA_Array la_array_result = la_array_copy - 1;
    ASSERT_EQ(la_array_result.getSize(), 5);
    ASSERT_EQ(la_array_result.get(0), 0);
    ASSERT_EQ(la_array_result.get(1), 1);
    ASSERT_EQ(la_array_result.get(2), 2);
    ASSERT_EQ(la_array_result.get(3), 3);
    ASSERT_EQ(la_array_result.get(4), 4);
}

TEST(LA_Array, LA_Array_multiply_scalar) {
    double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    LA_Array la_array_copy(array, 5);
    LA_Array la_array_result = la_array_copy * 2;
    ASSERT_EQ(la_array_result.getSize(), 5);
    ASSERT_EQ(la_array_result.get(0), 2);
    ASSERT_EQ(la_array_result.get(1), 4);
    ASSERT_EQ(la_array_result.get(2), 6);
    ASSERT_EQ(la_array_result.get(3), 8);
    ASSERT_EQ(la_array_result.get(4), 10);
}

TEST(LA_Array, LA_Array_divide_scalar) {
    double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    LA_Array la_array_copy(array, 5);
    LA_Array la_array_result = la_array_copy / 2;
    ASSERT_EQ(la_array_result.getSize(), 5);
    ASSERT_EQ(la_array_result.get(0), 0.5);
    ASSERT_EQ(la_array_result.get(1), 1);
    ASSERT_EQ(la_array_result.get(2), 1.5);
    ASSERT_EQ(la_array_result.get(3), 2);
    ASSERT_EQ(la_array_result.get(4), 2.5);
}

TEST(LA_Array, LA_Array_add_assign) {
    double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    LA_Array la_array_copy(array, 5);
    la_array_copy += la_array;
    ASSERT_EQ(la_array_copy.getSize(), 5);
    ASSERT_EQ(la_array_copy.get(0), 2);
    ASSERT_EQ(la_array_copy.get(1), 4);
    ASSERT_EQ(la_array_copy.get(2), 6);
    ASSERT_EQ(la_array_copy.get(3), 8);
    ASSERT_EQ(la_array_copy.get(4), 10);
}

TEST(LA_Array, LA_Array_subtract_assign) {
    double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    LA_Array la_array_copy(array, 5);
    la_array_copy -= la_array;
    ASSERT_EQ(la_array_copy.getSize(), 5);
    ASSERT_EQ(la_array_copy.get(0), 0);
    ASSERT_EQ(la_array_copy.get(1), 0);
    ASSERT_EQ(la_array_copy.get(2), 0);
    ASSERT_EQ(la_array_copy.get(3), 0);
    ASSERT_EQ(la_array_copy.get(4), 0);
}

TEST(LA_ARRAY, get){
double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    ASSERT_EQ(la_array.get(0), 1);
    ASSERT_EQ(la_array.get(1), 2);
    ASSERT_EQ(la_array.get(2), 3);
    ASSERT_EQ(la_array.get(3), 4);
    ASSERT_EQ(la_array.get(4), 5);
}

TEST(LA_ARRAY, set){
double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    la_array.set(0, 2);
    la_array.set(1, 3);
    la_array.set(2, 4);
    la_array.set(3, 5);
    la_array.set(4, 6);
    ASSERT_EQ(la_array.get(0), 2);
    ASSERT_EQ(la_array.get(1), 3);
    ASSERT_EQ(la_array.get(2), 4);
    ASSERT_EQ(la_array.get(3), 5);
    ASSERT_EQ(la_array.get(4), 6);
}

TEST(LA_ARRAY, getSize){
double array[5] = {1, 2, 3, 4, 5};
    LA_Array la_array(array, 5);
    ASSERT_EQ(la_array.getSize(), 5);

}

TEST(LA_ARRAY, equal_Operator_arr){
    double array[5] = {1, 2, 3, 4, 5};
    double array_copy[5] = {1, 2, 4, 1, 2};
    LA_Array la_array(array, 5);
    LA_Array la_array_copy(array_copy, 5);
    la_array_copy = la_array;
    ASSERT_EQ(la_array_copy.get(0), 1);
    ASSERT_EQ(la_array_copy.get(1), 2);
    ASSERT_EQ(la_array_copy.get(2), 3);
    ASSERT_EQ(la_array_copy.get(3), 4);
    ASSERT_EQ(la_array_copy.get(4), 5);
}

TEST(LA_ARRAY, equal_operator){
    double array[5] = {1,2,3,4,5};
    double array_copy[5] = {1,2,3,4,5};
    EXPECT_TRUE(LA_Array(array, 5) == LA_Array(array_copy, 5));
}

