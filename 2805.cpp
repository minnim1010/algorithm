#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

unsigned long long N, M;
unsigned long long tree[1000000];
unsigned long long ans = 0;

void binary_cut(unsigned long long s, unsigned long long e){
    unsigned long long mytree = 0;
    unsigned long long mid;
    long long gap;

    if(s > e){
        return;
    }

    mid = (s+e)/2;

    for (int i = 0; i < N; ++i) {
        long long cut = tree[i] - mid;
        if(cut <= 0) break;
        mytree += cut;
    }
    gap = mytree-M;

    if(gap < 0)
        binary_cut(s, mid-1);
    else if(gap > 0){
        ans = mid;
        binary_cut(mid+1, e);
    }
    else{
        ans = mid;
        return;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> tree[i];
    }

    sort(tree, tree+N, greater<>());

    binary_cut(0, tree[0]);

    if(M == 0) {
        cout << 0;
        return 0;
    }

    cout << ans;

    return 0;
}
