#include <bits/stdc++.h>
using namespace std;

long long _tam_crivo;
bitset<10000010> bs;
vector<int> primos;

void crivo(long long limite) {
  _tam_crivo = limite + 1;
  bs.reset();
  bs.flip();
  bs.set(0, false);
  bs.set(1, false);
  for (long long i = 2; i <= _tam_crivo; i++) {
    if (bs.test((size_t)i)) {
      for (long long j = i * i; j <= _tam_crivo; j += 1)
        bs.set((size_t)j, false);
      primos.push_back((int)i);
    }
  }
} // Chamar na função main

bool is_prime(long long n) {
  if (n < _tam_crivo) {
    return bs.test(n);
  }

  for (int i = 0; i < primos.size(); i++) {
    if (n % primos[i] == 0) {
      return false;
    }
  } // Só funciona se n <= que o último primo do vetor primos

  return true;
}
