#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define pi (acos(-1.0))
#define F first
#define S second
#define lson (o<<1),l,mid
#define rson (o<<1|1),mid+1,r
#define MP make_pair
const double eps = 1e-9 ;
const int inf = 0x3f3f3f3f ;
const ll INF = (ll)1e18 ;

ll dp[20][1<<11][11] ;
int digit[20] ;
ll l , r ;
int k ;

int judge (int o) {
	int cnt = 0 ;
	while (o) {
		if (o & 1) cnt ++ ;
		o >>= 1 ;
	}
	return cnt == k ;
}

int work (int o , int x) {
	if (o == 0) return 1<<x ;
	for (int i = 9 ; i >= 0 ; i --) {
		if (o&(1<<i)) {
			if (x >= i) return o | (1<<x) ;
			break ;
		}
	}
	for (int i = 0 ; i <= 9 ; i ++) {
		if ( (o&(1<<i)) && i>=x) {
			return (o^(1<<i))|(1<<x) ;
		}
	}
}

ll calc (int pos , int o , bool wild , bool zero) {
	if (pos == -1) 
		return judge(o) ;
	if (!wild && dp[pos][o][k] != -1) 
		return dp[pos][o][k] ;
	int f = wild?digit[pos]:9 ;
	ll ret = 0 ;

	for (int i = 0 ; i <= f ; i ++) {
		if (zero && i == 0)
			ret += calc (pos-1 , 0 , wild & (i == f) , 1) ;
		else 
			ret += calc (pos-1 , work(o,i) , wild & (i==f) , 0) ;
	}
	if (!wild && !zero)
		dp[pos][o][k] = ret ;
	return ret ;
}

ll go (ll x) {
	int pos = 0 ;
	while (x) {
		digit[pos ++] = x%10 ;
		x /= 10 ;
	}
	return calc (pos-1 , 0 , 1 , 1) ;
}

int main () {
	int T ;
	scanf ("%d" , &T) ;
	memset (dp , -1 , sizeof(dp)) ;
	for (int cas = 1 ; cas <= T ; cas ++) {
		scanf (LLD LLD "%d" , &l , &r , &k) ;
		printf ("Case #%d: " , cas) ;
		printf (LLD "\n" , go(r) - go(l-1)) ;
	}
	return 0 ;
}
