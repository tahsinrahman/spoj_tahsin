#include <bits/stdc++.h>
using namespace std;

#define mx 1000010
bool base[mx+10];
int primes[79000];

void sieve()
{
	int i, j, k, x;

	for(i = 3; i <= 1000; i += 2)
		if(!base[i]) for(j = i*i, k = i<<1; j < mx; j += k) base[j] = 1;

	primes[0] = 2;
	j = 1;
	for(i = 3; i < mx; i += 2) if(!base[i]) primes[j++] = i;
}

bool check(long long n)
{
	int i, c;

	while(n%2 == 0) n /= 2;

	for(i = 0; (long long) primes[i]*primes[i] <= n; i++) {
		if(primes[i]%4 == 1) continue;

		c = 0;
		while(n%primes[i] == 0) {
			n /= primes[i];
			c++;
		}
		cout << primes[i] << ' ' << c << endl;
		if(c&1) return 0;
	}
	return 1;
}


		


int main()
{
	sieve();

	long long n, p, x, y;
	int i, t, f;

	scanf("%d", &t);

	while(t--) {
		scanf("%lld", &n);

		if(check(n)) printf("Yes\n");
		else printf("No\n");

	}

	return 0;
}
