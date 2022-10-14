int euler_phi(int n) {
  vector<int> factors = primeFactors(n);
  auto new_end = unique(factors.begin(), factors.end());

  int result = n;

  for (auto it = factors.begin(); it != new_end; it++) {
    result = result - result / *it;
  }

  return result;
}
