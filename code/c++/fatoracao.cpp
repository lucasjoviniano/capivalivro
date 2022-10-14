vector<int> primeFactors(int n) {
  vector<int> factors;

  int pf_idx = 0, pf = primos[pf_idx]; // Primos gerados pelo crivo

  while (n != 1 && (pf * pf <= n)) {
    while (n % pf == 0) {
      n /= pf;
      factors.push_back(pf);
    }
    pf = primos[++pf_idx];
  }

  if (n != 1)
    factors.push_back(n);
  return factors;
}
