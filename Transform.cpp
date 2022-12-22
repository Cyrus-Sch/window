#include "Transform.h"

Transform::Transform() {
    x = 0;
    y = 0;
    rotation = 0;
    scaleX = 1;
    scaleY = 1;
}

void Transform::translate(double x, double y) {
    this->x += x;
    this->y += y;
}
void Transform::rotate(double angle) {
    rotation += angle;
}
