#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;

int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct Point {
  double x, y;

  Point(double x = 0, double y = 0) : x(x), y(y) {}

  Point operator+(Point other) {
    return Point(x + other.x, y + other.y);
  }

  Point operator-(Point other) {
    return Point(x - other.x, y - other.y);
  }

  Point operator*(double t) {
    return Point(x * t, y * t);
  }

  Point operator/(double t) {
    return Point(x / t, y / t);
  }

  // Produto Escalar
  double operator*(Point other) {
    return x * other.x + y * other.y;
  }

  // Produto vetorial
  double operator^(Point other) {
    return x * other.y - y * other.x;
  }

  int cmp(Point other) const {
    if (int t = ::cmp(x, other.x)) return t;
    return ::cmp(y, other.y);
  }

  bool operator==(Point other) const {
    return cmp(other) == 0;
  }

  bool operator!=(Point other) {
    return cmp(other) != 0;
  }

  bool operator<(Point other) const {
    return cmp(other) < 0;
  }

  friend ostream& operator<<(ostream& o, Point p) {
    return o << "(" << p.x << ", " << p.y << ")";
  }

  static Point pivot;
};

Point Point::pivot;
typedef vector<Point> Polygon;
