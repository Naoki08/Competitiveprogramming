#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define SZ(x) ((int)(x).size())
using ll = long long;
using P = pair<int, int>;
using llP = pair<ll, ll>;
using DoP = pair<double, double>;
const int di[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dj[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int INF = 1 << 29;
const ll INF64 = 1ll << 55;
const int mod = 1000000007;
//const int mod = 998244353;

template <class T>inline bool chmin(T &a, const T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>inline bool chmax(T &a, const T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  int n, l;
  cin >> n >> l;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  ll t1, t2, t3;
  cin >> t1 >> t2 >> t3;
  
  vector<ll> dp(l+1, INF64);
  dp[0] = 0; //0地点に0秒でいる

  for(int now = 0; now < l; ++now) {
    //行き先にハードルがある場合ペナルティT3を加算する必要がある

    chmin(dp[now+1], dp[now]+t1 + ((binary_search(ALL(x), now+1))?t3:0)); //行動1

    if(now+2 <= l) chmin(dp[now+2], dp[now]+t1+t2 + ((binary_search(ALL(x), now+2))?t3:0)); //行動2ゴールから飛び出さない場合
    else chmin(dp[l], dp[now]+ t1/2 + t2/2 ); //ゴールを飛び出す場合

    if(now+4 <= l) chmin(dp[now+4], dp[now]+t1+3*t2 + ((binary_search(ALL(x), now+4))?t3:0)); //行動3ゴールから飛び出さない場合
    else chmin(dp[l], dp[now] + t1/2 + (2*(l-now)-1)*t2/2); //ゴールを飛び出す場合

  }

  cout << dp[l] << endl;
}
