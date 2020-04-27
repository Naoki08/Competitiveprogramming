#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define ALL(a) (a).begin(), (a).end()

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using DoP = pair<double, double>;
using edge = struct { int to; ll cost; }; // edge x = {to, cost}

const int INF = 400000000;
const ll INF64 = 1ll << 40;
const int mod = 1000000007;

int main(){
  int n; cin >> n;
  vector<int> s(n);
  rep(i, n) cin >> s[i];
  int q; cin >> q;
  int ans = 0;
  rep(i, q) {
    int t; cin >> t;
    if(binary_search(ALL(s), t)) ++ans; //存在するかを二分探索で判定
  }
  cout << ans << endl;
}