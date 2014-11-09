#include <bits/stdc++.h>
using namespace std;

int n;// a[100];
long long a[100];
map <long long, map <int, map <int, bool> > >dp;
vector <int> v;

long long fact[40];

void fac()
{
	fact[1] = 1;
	fact[2] = 2;
	fact[3] = 6;
	fact[4] = 24;
	fact[5] = 120;
	fact[6] = 720;
	fact[7] = 5040;
	fact[8] = 40320;
	fact[9] = 362880;
	fact[10] = 3628800;
	fact[11] = 39916800;
	fact[12] = 479001600;
	fact[13] = 227020758;
	fact[14] = 178290591;
	fact[15] = 674358851;
	fact[16] = 789741546;
	fact[17] = 425606191;
	fact[18] = 660911389;
	fact[19] = 557316307;
	fact[20] = 146326063;
	fact[21] = 72847302;
	fact[22] = 602640637;
	fact[23] = 860734560;
	fact[24] = 657629300;
	fact[25] = 440732388;
	fact[26] = 459042011;
	fact[27] = 394134213;
	fact[28] = 35757887;
	fact[29] = 36978716;
	fact[30] = 109361473;
	fact[31] = 390205642;
	fact[32] = 486580460;
}

void f(long long make, int i, int j)
{
	if(make == 0) {
		v.push_back(j);
		return;
	}
	if(i == n) return;// 0;

	if(dp[make][i][j] == 0) {
		if(make-a[i] >= 0) f(make-a[i], i+1, j+1);
		f(make, i+1, j);

		dp[make][i][j] = 1;
	}
}

int main()
{
	int t, i, cs = 0;// s, d;
	long long k, s, d;
	scanf("%d", &t);

	fac();


	while(t--) {
		dp.clear();
		v.clear();

		scanf("%d%I64d", &n, &k);

		for(i = 0; i < n; i++) scanf("%I64d", &a[i]);
		
		f(k, 0, 0);

		s = 0;
		int size = v.size();
		for(i = 0; i < size; i++) {
			d = fact[v[i]]*fact[n-v[i]];
			d %= 1000000007;
			s += d;
			s %= 1000000007;
		}
		printf("Case %d: %I64d\n", ++cs, s);
	}

	return 0;
}
