#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, cnt = 0;
int ar[10001] = {0};
int sum[10001] = {0};
unsigned long long M;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> ar[i];
        sum[i] = sum[i-1] + ar[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            if(sum[j] - sum[j-i] == M) cnt++;
        }
    }

    cout << cnt;

    return 0;
}
