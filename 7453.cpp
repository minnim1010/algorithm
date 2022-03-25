#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int a[4000], b[4000], c[4000], d[4000];
int s1[16000000], s2[16000000];
unsigned long long ans = 0, sum_size;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    sum_size = N*N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            s1[j+i*N] = a[i] + b[j];
            s2[j+i*N] = c[i] + d[j];
        }
    }

    sort(s2, s2+sum_size);

    for (int i = 0; i < sum_size; ++i) {
        int l = lower_bound(s2, s2+sum_size, -s1[i]) - s2;
        if(s2[l] != -s1[i]) continue;
        int h = upper_bound(s2, s2+sum_size, -s1[i]) - s2;

        ans += h-l;
    }

    cout << ans;

    return 0;
}
