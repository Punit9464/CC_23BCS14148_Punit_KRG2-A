/*
    Given an array nums and maxOperations that you can perform on array.
    perform following operation any number of times.
    Take any ith and divide nums[i] into any two positive numbers
    Your penalty is maximum number of array. We want to minimize the penalty.
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool isAns(vector<int> &nums, int maxOperations, int penalty) {
    int ops = 0;
    for(int i = 0;  i < nums.size(); i++) {
        if(nums[i] > penalty) {
            ops += (nums[i]-1)/penalty;
        }
    }
    return ops <= maxOperations;
}

int main() {
    int n, maxOperations;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin>>nums[i];
    cin>>maxOperations;

    int low = 1, high = *max_element(nums.begin(), nums.end());

    while(low < high) {
        int mid = (low + high)/2;
        if(isAns(nums, maxOperations, mid)) {
            high = mid;
        } else {
            low = mid+1;
        }
    }

    cout<<high<<endl;

    return 0;
}
