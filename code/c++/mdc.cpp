long long mdc(long long a, long long b) {
  return (b == 0 ? a : mdc(b, a % b));;
}

long long mmc(long long a, long long b) {
  return (a * (b / mdc(a, b)));
}
