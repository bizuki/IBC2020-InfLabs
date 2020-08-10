#include <iostream>

using namespace std;
// We would be more accurate if we compare numbers with EPS but i'm lazy :-D
struct point {
    double x, y;

    point(double X, double Y) {
        x = X;
        y = Y;
    }

    point() {}
};

istream &operator>>(istream &in, point &p) {
    in >> p.x >> p.y;
    return in;
}

point operator-(point a, point b) {
    return point(a.x - b.x, a.y - b.y);
}

int sign(double x) {
    if (x > 0)
        return 1;
    if (x < 0)
        return -1;
    return 0;
}

double operator*(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

bool isOnTheSameSide(point start, point end, point p1, point p2) {
    int t1 = sign((start - end) * (p1 - end));
    int t2 = sign((start - end) * (p2 - end));
    return t1 == t2;
}

bool isBetween2ParallelLines(point startLine1, point endLine1, point startLine2, point endLine2, point Point) {
    if ((startLine1 - endLine1) * (Point - endLine1) == 0 || (startLine2 - endLine2) * (Point - endLine2) == 0)
        return true;
    return (isOnTheSameSide(startLine1, endLine1, Point, endLine2) &&
            isOnTheSameSide(startLine2, endLine2, Point, endLine1));

}

bool PointInParallelogram(point a, point b, point c, point d, point P) {
    return isBetween2ParallelLines(a, b, c, d, P) && isBetween2ParallelLines(a, d, c, b, P);
}

int main() {
    int n;
    cin >> n;
    point a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < n; i++) {
        point P;
        cin >> P;
        PointInParallelogram(a, b, c, d, P);
    }
}