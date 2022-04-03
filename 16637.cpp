#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
//16637 괄호 추가하기
using namespace std;

int N;
string str;
bool parenthesis[19] = {0};
char substitution[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
long long ans = LLONG_MIN;

long long calOneOperator(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
    }
}

long long unsubstitute(char ch, vector<long long> c) {
    if ('a' <= ch && ch <= 'i') {
        int idx = ch-'a';
        return c[idx];
    } else return ch - '0';
}

long long calString(string str) {
    long long result;
    int idx = N;
    string tmp_str;
    vector<long long> c;
    int cnt_parenthesis = 0;

    //string, parenthesis 기반으로 괄호 연산
    for (int i = 0; i < idx; ++i) {
        if (parenthesis[i]) {
            c.push_back(calOneOperator(str[i] - '0', str[i + 2] - '0', str[i + 1]));
            tmp_str.push_back(substitution[cnt_parenthesis]);
            cnt_parenthesis++;
            i += 2;
        } else {
            tmp_str.push_back(str[i]);
        }
    }

    result = unsubstitute(tmp_str[0], c);
    for (int i = 1; i < tmp_str.size(); i += 2) {
        long long b = unsubstitute(tmp_str[i + 1], c);
        result = calOneOperator(result, b, tmp_str[i]);
    }

    return result;
}

void solution(int idx) {
    if (idx >= N - 1) {
        long long result = calString(str);
        if (result > ans)
            ans = result;
        return;
    }

    if (!('0' <= str[idx] && str[idx] <= '9')) {
        ++idx;
    }

    if (idx + 2 < N) {
        for (int i = 0; i <= 2; ++i) {
            parenthesis[idx + i] = true;
        }

        solution(idx + 3);

        for (int i = 0; i <= 2; ++i) {
            parenthesis[idx + i] = false;
        }
    }

    solution(idx + 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> str;

    solution(0);
    cout << ans;

    return 0;
}
