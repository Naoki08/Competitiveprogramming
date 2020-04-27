#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define ALL(a) (a).begin(), (a).end()

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using DoP = pair<double, double>;
using edge = struct { int to; ll cost; }; // edge x = {to, cost}

const int di[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dj[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int INF = 400000000;
const ll INF64 = 1ll << 40;
const int mod = 1000000007;

int main(){
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> p(n);
  rep(i, n) cin >> p[i];
  p.push_back(0); //投げないということは0点の的とみなせる

  vector<ll> tow_throw;
  rep(i, n+1) rep(j, n+1) if(p[i]+p[j]<=m) tow_throw.push_back(p[i]+p[j]); //2回投げた状態の点数を保持
  sort(ALL(tow_throw)); //二分探索の準備

  ll ans = 0ll;

  rep(i, tow_throw.size()) {
    ll limit = m-tow_throw[i]; //残り2回の投げにおいて点数を得られる最大の点数
    auto it = lower_bound(ALL(tow_throw), limit);
    if(*it != limit) --it; //ピッタリじゃなかったら減らす

    ll last_throw = *it;
    ans = max(ans, tow_throw[i] + last_throw);
  }
  cout << ans << endl;
}