#include<stdio.h>
#include<vector>
using namespace std;
#define SIZE 1000009
#define MOD 12312312
#define PRIME1 127
#define PRIME2 131
typedef long long ll;
char txt[SIZE], ptn[SIZE];
int P, T;
vector<int> ans;
int mod(ll n) {
	if (n >= 0)n%MOD;
	return ((-n / MOD + 1)*MOD + n) % MOD;
}
int main() {
	fgets(txt, SIZE, stdin);
	fgets(ptn, SIZE, stdin);
	for (; txt[T]; T++);
	txt[--T] = 0;
	for (; ptn[P]; P++);
	ptn[--P] = 0;

	int power = 1, hash_t = 0, hash_p = 0;
	int hash2_t = 0, hash2_p = 0, power2 = 1;
	for (int i = 0; i <= T - P; i++) {
		if (i == 0) {
			for (int j = 0; j < P; j++) {
				hash_t = mod(hash_t + 1LL * power * txt[P - j - 1]);
				hash2_t = mod(hash2_t + 1LL * power2 * txt[P - j - 1]);

				hash_p = mod(hash_p + 1LL * power * ptn[P - j - 1]);
				hash2_p = mod(hash2_p + 1LL * power2 * ptn[P - j - 1]);

				if (j < P - 1) power = mod(power * PRIME1);
				if (j < P - 1) power2 = mod(power2 * PRIME2);

			}
			//printf("Hash value of Pattern(Fixed):%d\n", hash_p);
		}
		else {
			hash_t = mod(PRIME1 * (hash_t - 1LL * power*txt[i - 1]) + txt[i + P - 1]);
			hash2_t = mod(PRIME2 * (hash2_t - 1LL * power2*txt[i - 1]) + txt[i + P - 1]);
		}
		//printf("Hash value of Text(Variable):%d\n", hash_t);
		if (hash_t == hash_p && hash2_t == hash2_p) {
			ans.push_back(i + 1);
		}
	}

	printf("%d\n", ans.size());

	for (int i : ans)
		printf("%d ", i);

	return 0;
}
