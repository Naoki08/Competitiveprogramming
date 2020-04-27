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
  vector<int> a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];

  sort(ALL(a)); sort(ALL(b)); sort(ALL(c)); //二分探索の準備

  ll ans = 0ll;
  rep(i, n) {
    auto up = lower_bound(ALL(a), b[i]); //パーツAの半開区間の右側
    auto down = upper_bound(ALL(c), b[i]); //パーツCの半開区間の左側
    ll a_num = distance(a.begin(), up); //使えるAの個数
    ll c_num = distance(down, c.end()); //使えるCの個数
    ans += a_num * c_num;
  }
  cout << ans << endl;
}