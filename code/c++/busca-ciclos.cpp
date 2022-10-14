pair<int, int> floyd_cycle_finding(function<int(int)> f, int x0) {
  int tart = f(x0), lebr = f(f(x0));
  while (lebr != tart) {
    tart = f(tart);
    lebr = f(f(lebr));
  }

  int mu = 0;
  lebr = tart;
  tart = x0;

  while (lebr != tart) {
    tart = f(tart);
    lebr = f(lebr);
    mu++;
  }

  int lamb = 1;
  lebr = f(tart);

  while (lebr != tart) {
    lebr = f(lebr);
    lamb++;
  }

  return make_pair(mu, lamb);
}
