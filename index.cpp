#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            count++;
            if (i != n / i) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    const int MAX_B = 1000000;
    vector<int> sequence;
    vector<int> countUpTo(MAX_B + 1, 0);

    sequence.push_back(1);
    while (true) {
        int next = sequence.back() + countDivisors(sequence.back());
        if (next > MAX_B) break;
        sequence.push_back(next);
    }

    for (int num : sequence) {
        countUpTo[num] = 1;
    }
    for (int i = 1; i <= MAX_B; ++i) {
        countUpTo[i] += countUpTo[i - 1];
    }

    int T;
    scanf("%d", &T);
    vector<pair<int, int>> queries(T);
    for (int t = 0; t < T; ++t) {
        scanf("%d %d", &queries[t].first, &queries[t].second);
    }

    for (int t = 0; t < T; ++t) {
        int A = queries[t].first;
        int B = queries[t].second;
        int result = countUpTo[B] - (A > 1 ? countUpTo[A - 1] : 0);
        printf("Case %d: %d\n", t + 1, result);
    }

    return 0;
}
