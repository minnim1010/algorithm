#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int M, N, tmp;
int ar[500000];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> ar[i];
    }
    sort(ar, ar+N);

    cin >> M;

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        cin >> tmp;
        ans = upper_bound(ar, ar+N, tmp) - lower_bound(ar, ar+N, tmp);
        cout << ans << ' ';
    }

    return 0;
}
