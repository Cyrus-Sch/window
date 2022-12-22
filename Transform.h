//
// Created by Jed Knauer on 22.12.22.
//

#ifndef WINDOW_TRANSFORM_H
#define WINDOW_TRANSFORM_H


class Transform {
    double x;
    double y;
    double rotation;
    double scaleX;
    double scaleY;
public:
    Transform();
    void translate(double x, double y);
    void rotate(double angle);
    void scale(double x, double y);
    void setX(double x);
    void setY(double y);
    void setRotation(double rotation);
    void setScaleX(double scaleX);
    void setScaleY(double scaleY);
    double getX();
    double getY();
    double getRotation();
    double getScaleX();
    double getScaleY();
private:
    void
};


#endif //WINDOW_TRANSFORM_H
