#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

unsigned long long K, N;
unsigned long long ar[10000];
unsigned long long ans = 0;

void binary_search(unsigned long long start, unsigned long long end){

    if(start > end)
        return;

    unsigned long long mid = (start+end)/2;

    unsigned long long lan = 0;
    for (int i = 0; i < K; ++i) {
        lan += ar[i]/mid;
    }

    if(lan < N){
        binary_search(start, mid-1);
    }
    else{
        if(ans < mid) ans = mid;
        binary_search(mid+1, end);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;
    for (int i = 0; i < K; ++i) {
        cin >> ar[i];
    }

    sort(ar, ar+K);

    binary_search(1, ar[K-1]);

    cout << ans;

    return 0;
}
