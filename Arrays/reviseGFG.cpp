#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
}

void reversed(vector<int> arr, int l, int r){
    while(l < r){
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void moveZeroesEnd(vector<int> arr){
    printVector(arr);
    int nonZero = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != 0){
            swap(arr[i], arr[nonZero++]);
        }
    }
    printVector(arr);
}

void moveZeroesStart(vector<int> arr){
    printVector(arr);
    int nonZero = arr.size()-1;
    for(int i = arr.size()-1; i >= 0; i--){
        if(arr[i] != 0){
            swap(arr[i], arr[nonZero--]);
        }
    }
    printVector(arr);
}

void rotateLeft(vector<int> arr){
    int temp = arr[0];
    for(int i = 1; i < arr.size(); i++){
        arr[i-1] = arr[i];
    }
    arr[arr.size()-1] = temp;
    printVector(arr);
}

void rotateLeftD(vector<int> arr, int D){
    printVector(arr);
    reversed(arr, 0, D-1);
    reversed(arr, D, arr.size()-1);
    reversed(arr, 0, arr.size()-1);
    printVector(arr);
}

void leaders(vector<int> arr){
    int curr_leader = arr[arr.size()-1];
    cout << curr_leader << " ";
    for(int i = arr.size()-2; i >= 0; i--){
        if(arr[i] > curr_leader){
            cout << arr[i] << " ";
            curr_leader = arr[i];
        }
    }
}

int maxDiff(vector<int> arr){
    int res = arr[1]-arr[0], minVal = arr[0];
    for(int i = 1; i < arr.size(); i++){
        res = max(res, arr[i]-minVal);
        minVal = min(minVal, arr[i]); // Updating the minimu element
    }
    return res;
}

void printFreq(vector<int> arr){
    int i = 1, freq = 1;
    while(i < arr.size()){
        while(i < arr.size() && arr[i] == arr[i-1]){
            i++;
            freq++;
        }
        cout << arr[i-1] << " : " << freq << endl;
        freq = 1;
        i++;
    }
    if(arr.size()==1 || arr[arr.size()-1] != arr[arr.size()-2]){
        cout << arr[arr.size()-1] << " : " << 1 << endl;
    }
}

int maxProfit(vector<int> arr){
    int profit = 0;
    for(int i = arr.size()-2; i >= 0; i--){
        if(arr[i+1] > arr[i]){
            profit += arr[i+1]-arr[i];
        }
    }
    return profit;
}

int singleMaxProfit(vector<int> arr){
    int profit = 0;
    int maxRight = arr[arr.size()-1];
    for(int i = arr.size()-2; i >= 0; i--){
        maxRight = max(maxRight, arr[i]);
        profit = max(profit, maxRight-arr[i]);
    }
    return profit;
}

int trapWater(vector<int> arr){
    int res = 0;
    vector<int> left(arr.size(), 0);
    vector<int> right(arr.size(), 0);
    
    left[0] = arr[0];
    for(int i = 1; i < arr.size(); i++){
        left[i] = max(left[i-1], arr[i]);
    }

    right[arr.size()-1] = arr[arr.size()-1];
    for(int i = arr.size()-2; i >= 0; i--){
        right[i] = max(arr[i], right[i+1]);
    }

    for(int i = 1; i < arr.size()-1; i++){
        res += min(left[i], right[i]) - arr[i];
    }
    return res;
}

int maxConsecutive1(vector<int> arr){
    int res = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 1){
            res = max(res, res+1);
        }
        if(arr[i] == 0){
            res = 0;
        }
    }
    return res;
}

int maxSumSub(vector<int> arr){
    int max_sum = arr[0], curr_sum = arr[0];
    for(int i = 1; i < arr.size(); i++){
        curr_sum = max(arr[i], curr_sum+arr[i]);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

int maxLen(vector<int> arr){
    int res = 0, curr = 1;
    for(int i = 1; i < arr.size(); i++){
        if((arr[i]%2 == 0 && arr[i-1]%2 != 0) || (arr[i]%2 != 0 && arr[i-1]%2 == 0)){
            curr++;
            res = max(res, curr);
        } else {
            curr = 1;
        }
    }
    return res;
}

int circularSum(vector<int> arr){
    int normalSum = maxSumSub(arr);
    if(normalSum < 0) return normalSum;
    int arr_sum = 0;
    for(int i = 0; i < arr.size(); i++){
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int max_circular = arr_sum + maxSumSub(arr);
    return max(normalSum, max_circular);
}

// Moore's Algorithm
int majorityElement(vector<int> arr){
    int res = 0, count = 1;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] == arr[res]) {
            count++;
        } else {
            count--;
        }
        if(count == 0){
            count = 1;
            res = i;
        }
    }

    count = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == arr[res]){
            count++;
        }
        if(count <= arr.size()/2){
            return arr[res];
        }
    }

    return -1;

}

void miniGroupFlips(vector<int> arr){
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] != arr[i-1]){
            if(arr[i] != arr[0]){
                cout << "From " << i << " to ";
            } else {
                cout << i-1 << endl;
            }
        }
    }
    if(arr[arr.size()-1] != arr[0]){
        cout << arr.size()-1 << endl;
    }
}

int maxSumK(vector<int> arr, int k){
    int curr = 0;
    for(int i = 0; i < k; i++){
        curr += arr[i];
    }
    int ans = curr;
    for(int i = k; i < arr.size(); i++){
        curr = curr + arr[i] - arr[i-k];
        ans = max(curr, ans);
    }
    return ans;
}

bool subarraySum(vector<int> arr, int k){
    int s = 0, e = 0;
    int curr = 0;
    while(e < arr.size()){
        curr += arr[e++];
        while(curr > k){
            curr -= arr[s++];
        }
        if(curr == k){
            return 1;
        }
    }
    return 0;
}

bool equilibriumPoint(vector<int> arr){
    int rs = 0;
    for(int i = 0; i < arr.size(); i++){
        rs += arr[i];
    }
    int ls = 0;
    for(int i = 0; i < arr.size(); i++){
        rs -= arr[i];
        if(rs == ls){
            return 1;
        }
        ls += arr[i];
    }
    return 0;
}

int maxAppearElement(vector<int> one, vector<int> two){
    vector<int> freq(101, 0);
    for(int i = 0; i < one.size(); i++){
        freq[one[i]]++;
        freq[two[i]+1]--;
    }
    int res = 0;
    for(int i = 1; i < freq.size(); i++){
        freq[i] += freq[i-1];
        if(freq[i] > freq[res]){
            res = i;
        }
    }
    return res;
}

int main(){
    // GFG Main
    // Q. Move Zeroes to End.
    // vector<int> arr = {10,8,0,0,12,0};
    // moveZeroesEnd(arr);
    // Q. Move Zeroes to Start
    // vector<int> arr = {10,8,0,0,12,0};
    // moveZeroesStart(arr);

    // Q. Left Rotate by D.
    // vector<int> arr {1,2,3,4,5};
    // rotateLeft(arr);
    // rotateLeftD(arr, 2);

    // Q. Leaders in an Array.
    // vector<int> arr {7,10,4,3,6,5,2};
    // leaders(arr);

    // Q. Maximum Difference Problem [arr[j] - arr[i], j > i]
    // vector<int> arr {2,3,10,6,4,8,1};
    // cout << "The maximum differnce is : " << maxDiff(arr);

    // Q. Frequency of elements.
    // vector<int> arr {10,10,10,30,30,40};
    // printFreq(arr);

    // Q. Stock and Buy.
    // vector<int> arr {1,5,3,8,12};
    // cout << "The cumulative max profit will be : " << maxProfit(arr);
    // cout << "The single max profit will be : " << singleMaxProfit(arr);

    // Q. Trap Water
    // vector<int> arr {3,0,1,2,5};
    // cout << "Maximum water trapped is : " << trapWater(arr) << endl;

    // Q. Maximum Consecutive Ones.
    // vector<int> arr {0,1,1,0,1,1,1,0,0,0,1,1,1,1,1,1,1};
    // cout << "Max consecutive 1s is : " << maxConsecutive1(arr) << endl;

    // Q. Maximum sum of a subarray.
    // vector<int> arr {-3, 8,-2,4,-5,6};
    // cout << "The maximum sum is : " << maxSumSub(arr) << endl;

    // Q. Maximum length even-odd subarray
    // vector<int> arr {5,10,20,6,3,8};
    // cout << "The max length even-odd subarray is : " << maxLen(arr);

    // Q. Circular Sum Sub Array.
    // vector<int> arr {8,-4,3,-5,4};
    // cout << "The Maximum Circular Sum is : " << circularSum(arr) << endl;

    // Q. Majority Element.
    // vector<int> arr {8,8,6,6,6,4,6};
    // cout << "The Majority Element is : " << majorityElement(arr) << endl;

    // Q. Minimum Group FLips to make same.
    // If 1st and last element are same then always starting flipping from 2nd group.
    // If 1st and last element differ then flip any of the group of 0s or 1s.
    // Do not touch first group i.e. arr[i] != arr[0]
    // vector<int> arr {0,0,1,1,0,0,1,1,0};
    // miniGroupFlips(arr);

    // Q. Find the maximum sum of K elements
    // vector<int> arr {1,8,30,-5,20,7};
    // cout << "The max sum of K elements is : " << maxSumK(arr, 4);

    // Q. If there exists any subarray with given sum.
    // vector<int> arr {1,4,20,3,10,5};
    // cout << "Exists any subarray : " << subarraySum(arr, 33) << endl;

    // Q. Equilibrium Point.
    // vector<int> arr {3,4,8,-9,9,7};
    // cout << "Is there any equilibrium point : " << equilibriumPoint(arr) << endl;

    // Q. Maximum Appearing element in ranges.
    vector<int> one {1,2,4};
    vector<int> two {4,5,7};
    cout << "The Maximum Appearing element in the range is : " << maxAppearElement(one,two);
    return 0;
}