#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

int N, M, s = 0, S, E;
int ar[100001];
int sum[100001] = {0};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> ar[i];
        s += ar[i];
        sum[i] = s;
    }

    cin >> M;

    for (int i = 0; i < M; ++i) {
        cin >> S >> E;
        cout << sum[E] - sum[S-1] << '\n';
    }

    return 0;
}
