double ternary_search(double l, double r) {
  double eps = 1e-9; // limite para comparação de floats
  // podemos, ao invés de comparar por diferença, usar uma quantidade fixa
  // 200 a 300 deve ser o suficiente
  while (r - l > eps) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double f1 = f(m1);
    double f2 = f(m2);
    if (f1 < f2)
      l = m1;
    else
      r = m2;
  }
  return f(l); // máximo de f(x) em [l, r]
}