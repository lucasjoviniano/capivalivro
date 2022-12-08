#include "point.cpp"

double polygonArea(Polygon &T) {
  double s = 0.0;
  int n = T.size();
  for (int i = 0; i < n; i++) {
    s += T[i] ^ T[(i + 1) % n];
  }

  return s / 2.0;
}

double perimeter(Polygon &T) {
  double result = 0.0;
  int n = T.size();

  for (int i = 0; i < n; i++)
    result += Point::dist(T[i], T[(i + 1) % n]);

  return result;
}
