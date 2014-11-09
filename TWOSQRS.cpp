#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, p, x, y;
	int i, t, f;

	scanf("%d", &t);

	while(t--) {
		scanf("%lld", &n);

		x = (int) (sqrt(n>>1) + 1e-9);

		f = 1;
		for(i = 0; i <= x; i++) {
			p = (long long) i*i;
			y = (int) (sqrt(n-p) + 1e-9);
			if(p + (long long) y*y == n) {
				printf("Yes\n");
				f = 0;
				break;
			}
		}
		if(f) printf("No\n");
	}

	return 0;
}
