#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, sumTime;
    cin >> d >> sumTime;

    vector<int> minTime(d), maxTime(d);

    int MinSum = 0, MaxSum = 0;

    for(int i = 0; i < d; i++) {
        cin >> minTime[i] >> maxTime[i];
        MinSum += minTime[i];
        MaxSum += maxTime[i];
    }

    if(sumTime < MinSum || sumTime > MaxSum) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    int remaining = sumTime - MinSum;

    for(int i = 0; i < d; i++) {

        int extra = min(remaining, maxTime[i] - minTime[i]);

        minTime[i] += extra;
        remaining -= extra;
    }
    for(int x : minTime)
        cout << x << " ";

    return 0;
}                                                                                  