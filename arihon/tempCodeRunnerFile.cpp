rep(i, 0, l) {
    cin >> p >> q;
    rail.unite(p, q);
  }
  rep(i, 1, n + 1) {
    if (chk[i] == 0) {
      int sum = 0;
      chk[i] = -1;
      rep(j, 1, n + 1) {
        if (road.check(i, j) and rail.check(i, j))
          chk[j] = -1, sum++;
      }
      rep(i, 1, n + 1) if (chk[i] < 0) chk[i] = sum;
      cout << chk[i] << endl;
    }
  