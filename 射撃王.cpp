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
  int n; cin >> n;
  vector<ll> h(n), s(n);
  rep(i, n) cin >> h[i] >> s[i];
  ll l = -1, r = 1000000000ll+1000000000ll*100000ll+5;
  while(r-l > 1) {
    double mid = l+(r-l)/2; //floor計算のためdouble型
    vector<ll> limit(n);
    bool ok = true;

    rep(i, n) limit[i] = (ll)floor((mid-h[i])/s[i]); //この風船は何秒以内に話なら割らなければならないか
    sort(ALL(limit));
    rep(i, n) if(i > limit[i]) ok = false;
    if(ok) r=mid;
    else l=mid;
  }
  cout << r << endl;
}
