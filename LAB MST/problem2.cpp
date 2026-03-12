/*
    Given an array nums and integer k. You can do following operation any number of times:-
    Choose any two distinct indices i and j and Simultaneously update values nums[i] = nums[i] & nums[j], nums[j] = nums[i] | nums[j];
    Choose k elements from the final array and calculate sum of their squares.
    Return maximum sum of squares we can achieve Return modulo 1e9+7
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    int n, k;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    cin>>k;

    const long long MOD = 1e9 + 7;
    long long maxVal = 0;
    for(int i = 0; i < n; i++) {
        maxVal |= arr[i];
    }
    
    vector<long long> result;
    for(int i = 0; i < k && i < n; i++) {
        result.push_back(maxVal);
    }
    
    long long sum = 0;
    for(long long val : result) {
        long long sq = (val * val) % MOD;
        sum = (sum + sq) % MOD;
    }
    
    cout << sum << endl;

    return 0;
}
