// predicado a ser usado...
bool p(int x) {
  return x >=
         4; // exemplo para o predicado [false, false, false, false, true, true]
}

// considera o intervalo fechado [lo,hi]
// false false true true --> retorna 2
int buscaBinariaMenorTrue(int lo, int hi) {
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2; // cuidado aqui!

    // de mid para a frente é true --> podemos descartar [mid+1, hi]
    if (p(mid))
      hi = mid;
    else
      lo = mid + 1; // até mid é false --> podemos descartar [lo,mid]
  }
  if (!p(lo)) {
    return -1; // erro...é falso para tudo!
  }
  return lo;
}

// considera o intervalo fechado [lo,hi]
// false false true true --> retorna 1
int buscaBinariaMaiorFalse(int lo, int hi) {
  while (lo < hi) {
    // lo + (hi-lo)/2 falharia para o caso de false true (loop infinito) !!!!!
    // ATENÇÃO! sempre teste para o caso de intervalos com dois elementos!
    int mid = lo + (hi - lo + 1) / 2; // cuidado aqui!

    // de mid para a frente é true --> podemos descartar [mid+1, hi]
    if (p(mid))
      hi = mid - 1;
    else
      lo = mid; // até mid é false --> podemos descartar [lo,mid]
  }
  if (p(lo)) {
    return -1; // erro...é true para tudo!
  }
  return lo;
}

// Em um intervalo continuo, temos varios false, false, true, true
// retorna um double proximo da região que divide os false dos true.
double buscaBinariaContinua(double lo, double hi) {
  // mudar! podemos executar X iteracoes, parar quando distancia
  // entre hi e lo for pequena, etc...
  for (int i = 0; i < 100; i++) {
    double mid = lo + (hi - lo) / 2;
    if (p(mid))
      hi = mid;
    else
      lo = mid;
  }

  return lo;
}
