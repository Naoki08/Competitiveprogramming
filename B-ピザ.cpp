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
  ll D;
  int n, m;
  cin >> D >> n >> m;

  vector<ll> d(n, 0);
  rep(i, n-1) cin >> d[i+1];
  d.push_back(D);
  sort(ALL(d)); //二分探索をするための準備

  ll ans = 0ll;

  rep(i, m) {
    ll k; cin >> k;
    if(binary_search(ALL(d), k)) continue; //店と同じ位置に配達先があるならば距離は0

    auto it = lower_bound(ALL(d), k); //配達先より右側の住所のイテレーター
    ll r = *it;
    --it;
    ll l = *it;
    ans += min(r-k, k-l); //配達距離の短いほうを加算
  } 
  cout << ans << endl;
}