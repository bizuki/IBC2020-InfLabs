#include <iostream>
#include <cmath>

using namespace std;

struct point {
    double x, y;

    point(double X, double Y) {
        x = X;
        y = Y;
    }

    double dist(point b) {
        return sqrt((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
    }

    point() = default;
};

istream &operator>>(istream &in, point &p) {
    in >> p.x >> p.y;
    return in;
}

struct triangle {
    point points[3] = {point(), point(), point()};
    double sides[3] = {-1, -1, -1};

    triangle(point A, point B, point C) {
        points[0] = A;
        points[1] = B;
        points[2] = C;
    }

    bool exist() {
        for (int i = 0; i < 3; i++) {
            sides[i] = points[i].dist(points[(i + 1) % 3]);
        }
        double sum = sides[0] + sides[1] + sides[2];
        for (int i = 0; i < 3; i++) {
            if (sum <= 2 * sides[i])
                return false;
        }
        return true;
    }

    double area() {
        double hp = (sides[0] + sides[1] + sides[2]) / 2;// calc half of perimeter
        return sqrt(hp * (hp - sides[0]) * (hp - sides[1]) * (hp - sides[2]));
    }

    triangle() = default;
};

istream &operator>>(istream &in, triangle &t) {
    for (int i = 0; i < 3; i++)
        in >> t.points[i];
    return in;
}

int main() {
    triangle tr;
    cout << "Please Input 3 coordinates:\n";
    cin >> tr;
    while (!tr.exist()) {
        cout << "It's not a triangle. Please Input 3 coordinates again:\n";
        tr = triangle();
        cin >> tr;
    }
    cout << "Processing\n";
    cout << "Area of that triangle: " << tr.area();
}