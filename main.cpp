// Example program:
// Using SDL2 to create an application window
#include <iostream>
#include <SDL.h>
#include <array>
#include "vector"
#include "Screen.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 32
#define FRAMES_PER_SECOND 60
#define MAX_SPEED 10
#define MAX_ACCELERATION 1
#define MAX_DECELERATION 1
#define ROTATION_SPEED 0.0314159265358979323846
int width = 960;
int height = 960;
float scaling = 2.0;


void drawline(Screen &screen, std::pair<int, int> a, std::pair<int, int> b) {
    std::pair<int, int> ab(b.first - a.first, b.second - a.second);
    double abs = sqrt(ab.first * ab.first + ab.second * ab.second);
    for (int i = 0; i <= abs; i++) {
        std::pair<int, int> c(0, 0);
        c.first = ab.first * (1.0 / float(abs)) * i + a.first;
        c.second = ab.second * (1.0 / float(abs)) * i + a.second;
        screen.pixel(c.first, c.second);
    }
}
//TODO change to vectorised version
void drawline(Screen &screen, std::vector< std::pair<int, int> > points) {
    for (int i = 0; i < points.size() - 1; i++) {
        drawline(screen, points[i], points[i + 1]);
    }
}

int calc_absolute_distance(std::array<int, 3> a, std::array<int, 3> b) {
    int abs_ab = 0;
    for (int i = 0; i < 3; i++) {
        abs_ab += (b[i] - a[i]) * (b[i] - a[i]);
    }
    return abs_ab;
}

void vec_scalar_multiplication(std::array<float, 3> &vec, float scalar) {
    for (auto &col: vec) {
        col = col * scalar;
    }
}

void vec_add(std::array<float, 3> &vec1, std::array<float, 3> &vec2) {
    for (int i = 0; i < 3; i++) {
        vec1[i] += vec2[i];
    }
}

void matrix3x3_vec_multiplication(std::array<std::array<float, 3>, 3> matrix, std::array<float, 3> &vec) {
    std::array<float, 3> result_vector = {0.0, 0.0, 0.0};
    for (int i = 0; i < 3; i++) {
        vec_scalar_multiplication(matrix[i], vec[i]);
        vec_add(result_vector, matrix[i]);
    }
    vec = result_vector;
}

std::pair<int, int>
two_dtransform(std::array<float, 3> &point) {
    float diameter = sqrt(width * width + height * height);
    float xang = acos(float(width) / -diameter);
    float yang = acos(float(height) / diameter);
    std::pair<int, int> d2point;
    d2point.first = float(point[0]) + cos(xang) * (float(point[2])) + width / 4.0;
    d2point.second = float(point[1]) + cos(yang) * (float(point[2])) + height / 4.0;
    return d2point;
}

void rotate_point(std::array<float, 3> &point, std::array<float, 3> &center_of_rotation, float rotation_x = 0, float rotation_y = 0, float rotation_z = 0) {

    //calc direction vector

    auto center_to_point = center_of_rotation;
    vec_scalar_multiplication(center_to_point, -1.0);


    //define rotation matrix and calculate all sin cos values

    std::array<float, 3> row1 = {cos(rotation_y) * cos(rotation_z),
                                 sin(rotation_x) * sin(rotation_y) *
                                 cos(rotation_z) +
                                 cos(rotation_x) * sin(rotation_z),
                                 sin(rotation_x) *
                                 sin(rotation_z) -
                                 cos(rotation_x) *
                                 sin(rotation_y) *
                                 cos(rotation_z)};

    std::array<float, 3> row2 = {-cos(rotation_y) * sin(rotation_z),
                                 cos(rotation_x) * cos(rotation_z) -
                                 sin(rotation_x) * sin(rotation_y) * sin(rotation_z),
                                 cos(rotation_x) * sin(rotation_y) * sin(rotation_z) +
                                 sin(rotation_x) * cos(rotation_z)};
    std::array<float, 3> row3 = {sin(rotation_y), -sin(rotation_x) * cos(rotation_y),
                                 cos(rotation_x) * cos(rotation_y)};
    std::array<std::array<float, 3>, 3> rotation_matrix = {row1, row2, row3};

    //transform points with vec point multiplication

    matrix3x3_vec_multiplication(rotation_matrix, point);
    vec_add(center_to_point, point);
    vec_add(point,center_to_point);

}

void draw3dcube(Screen &screen, float edge_length, std::array<float, 3> center_position, float rotation_x = 0,
                float rotation_y = 0, float rotation_z = 0) {
    std::array<std::array<float, 3>, 8> edge_coordinates_3d = {};
    float center_to_edge = edge_length / 2;
    std::array<float, 3> bottom_left_front = {(center_position[0] - center_to_edge),
                                              (center_position[1] - center_to_edge),
                                              (center_position[2] + center_to_edge)};
    std::array<float, 3> bottom_right_front = {(center_position[0] + center_to_edge),
                                               (center_position[1] - center_to_edge),
                                               (center_position[2] + center_to_edge)};
    std::array<float, 3> bottom_left_back = {(center_position[0] - center_to_edge),
                                             (center_position[1] - center_to_edge),
                                             (center_position[2] - center_to_edge)};
    std::array<float, 3> bottom_right_back = {(center_position[0] + center_to_edge),
                                              (center_position[1] - center_to_edge),
                                              (center_position[2] - center_to_edge)};

    std::array<float, 3> top_left_front = {(center_position[0] - center_to_edge), (center_position[1] + center_to_edge),
                                           (center_position[2] + center_to_edge)};
    std::array<float, 3> top_right_front = {(center_position[0] + center_to_edge),
                                            (center_position[1] + center_to_edge),
                                            (center_position[2] + center_to_edge)};
    std::array<float, 3> top_left_back = {(center_position[0] - center_to_edge), (center_position[1] + center_to_edge),
                                          (center_position[2] - center_to_edge)};
    std::array<float, 3> top_right_back = {(center_position[0] + center_to_edge), (center_position[1] + center_to_edge),
                                           (center_position[2] - center_to_edge)};

    edge_coordinates_3d[0] = bottom_left_front;
    edge_coordinates_3d[1] = bottom_right_front;
    edge_coordinates_3d[2] = bottom_left_back;
    edge_coordinates_3d[3] = bottom_right_back;

    edge_coordinates_3d[4] = top_left_front;
    edge_coordinates_3d[5] = top_right_front;
    edge_coordinates_3d[6] = top_left_back;
    edge_coordinates_3d[7] = top_right_back;

    std::array<std::pair<int, int>, 8> edge_coordinates_2d = {};
    int index = 0;
    for (auto &point: edge_coordinates_3d) {
        rotate_point(point,center_position, rotation_x, rotation_y, rotation_z);
        edge_coordinates_2d[index] = two_dtransform(point);
        index++;
    }

    drawline(screen, edge_coordinates_2d[0], edge_coordinates_2d[1]);
    drawline(screen, edge_coordinates_2d[2], edge_coordinates_2d[3]);
    drawline(screen, edge_coordinates_2d[4], edge_coordinates_2d[5]);
    drawline(screen, edge_coordinates_2d[6], edge_coordinates_2d[7]);

    drawline(screen, edge_coordinates_2d[0], edge_coordinates_2d[2]);
    drawline(screen, edge_coordinates_2d[1], edge_coordinates_2d[3]);
    drawline(screen, edge_coordinates_2d[4], edge_coordinates_2d[6]);
    drawline(screen, edge_coordinates_2d[5], edge_coordinates_2d[7]);

    drawline(screen, edge_coordinates_2d[0], edge_coordinates_2d[4]);
    drawline(screen, edge_coordinates_2d[1], edge_coordinates_2d[5]);
    drawline(screen, edge_coordinates_2d[2], edge_coordinates_2d[6]);
    drawline(screen, edge_coordinates_2d[3], edge_coordinates_2d[7]);

    //drawline(screen, edge_coordinates_2d[0], edge_coordinates_2d[7]);
    //drawline(screen, edge_coordinates_2d[1], edge_coordinates_2d[6]);
    //drawline(screen, edge_coordinates_2d[2], edge_coordinates_2d[5]);
    //drawline(screen, edge_coordinates_2d[3], edge_coordinates_2d[4]);

}

void draw3dcircle(Screen &screen, float radius, std::array<float, 3> &center_position, float definition, float rot_x,
                  float rot_y, float rot_z) {
    std::array<float, 3> start_point = {center_position[0] + radius, center_position[1], center_position[2]};
    std::array<std::pair<int, int>, 1000000> points = {};
    int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                rotate_point(start_point,center_position, i * definition, j * definition, k * definition);
                rotate_point(start_point,center_position, rot_x, rot_y, rot_z);
                auto point2d = two_dtransform(start_point);
                points[index] = point2d;
                index++;
            }

        }
    }
    for (int i = 0; i < 62500; i += 2) {
        drawline(screen, points[i], points[i + 1]);
    }
}


//TODO write unit tests for all functions
int main() {
    Screen screen;
    while (true) {
        float rotation = 0.01745329;
        std::array<float, 3> center = {50, 10, -50};
        std::array<float, 3> center2 = {std::rand() % 200, std::rand() % 100, std::rand() % 200};
        std::array<float, 3> center3 = {std::rand() % 100, std::rand() % 100, std::rand() % 100};


        float size = 50;
        for (int i = 0; i < 360; i++) {
            std::cout << "cycle: " << i << std::endl;
            //draw3dcircle(screen,100.0,center,0.0628318530718,0, 0, rotation);

            draw3dcube(screen, size, center, rotation, rotation, 0);
            rotation += 0.01745329;
            screen.show();
            SDL_Delay(50);
            screen.clear();
            screen.input();

        }
    }
}