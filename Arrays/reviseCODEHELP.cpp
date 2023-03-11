#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i : arr){
        cout << i <<" ";
    }
    cout << endl;
}

void reverseArr(vector<int> arr){
    int l = 0, h = arr.size()-1;
    while(l < h){
        swap(arr[l++], arr[h--]);
    }
    printVector(arr);
}

void maxMinElement(vector<int> arr){
    int maxi = INT_MIN, mini = INT_MAX;
    for(int i = 0; i < arr.size(); i++){
        maxi = max(maxi, arr[i]);
        mini = min(arr[i], mini);
    }
    cout << "Maximum and Minimum is : " << maxi << ", " << mini << endl;
}

void sort012(vector<int> arr){
    int start = 0, i = 0, j = arr.size()-1;
    while(i <= j){
        if(arr[i] == 0){
            swap(arr[i++], arr[start++]);
        } else if(arr[i] == 1){
            i++;
        } else {
            swap(arr[i], arr[j--]);
        }
    }
    printVector(arr);
}

void moveNegBegin(vector<int> arr){
    int nonNegative = arr.size()-1;
    for(int i = arr.size()-1; i >= 0; i--){
        if(arr[i] >= 0){
            swap(arr[i], arr[nonNegative--]);
        } 
    }
    printVector(arr);
}

void intersectionArrays(vector<int> one, vector<int> two){
    vector<int> ans;
    int i = 0, j = 0;
    while(i < one.size() && j < two.size()){
        while(one[i] > two[j] && i < one.size() && j < two.size()){
            j++;
        }
        while(two[j] > one[i] && i < one.size() && j < two.size()){
            i++;
        }
        if(one[i] == two[j]){
            ans.push_back(one[i]);
            i++;
            j++;
        }
    }
    printVector(ans);
}

void unionArrays(vector<int> one, vector<int> two){
    vector<int> ans;
    int i = 0, j = 0;
    while(i < one.size() || j < two.size()){
        // Duplicacy check 
        while(i > 0 && i < one.size() && one[i] == one[i-1]){
            i++;
        }
        while(j > 0 && j < two.size() && two[j] == two[j-1]){
            j++;
        }

        // any of the array exhausts
        if(i >= one.size()){
            ans.push_back(two[j++]);
            continue;
        }
        if(j >= two.size()){
            ans.push_back(one[i++]);
            continue;
        }

        // Entery
        if(one[i] > two[j]){
            ans.push_back(two[j++]);
        } else if(two[j] > one[i]){
            ans.push_back(one[i++]);
        } else {
            ans.push_back(one[i++]);
            j++;
        }
    }
    printVector(ans);
}

int kadane(vector<int> arr){
    int curr = 0, maxi_sum = 0;
    for(int i = 0; i < arr.size(); i++){
        curr = max(arr[i], curr+arr[i]);
        maxi_sum = max(maxi_sum, curr);
    }
    return maxi_sum;
}

int minimizeHeights(vector<int> arr, int k){
    int n = arr.size();
    if(n==1) return 0;
    sort(arr.begin(), arr.end());
    int diff = arr[n-1] - arr[0];
    // cout << diff << endl;
    int maxi, mini;
    for(int i = 1; i < n; i++){
        if(arr[i]-k < 0) continue;
        maxi = max(arr[n-1]-k, arr[i-1]+k);
        mini = min(arr[0]+k, arr[i]-k);
        diff = min(diff, maxi-mini);
    }
    return diff;
}

int duplicateElement(vector<int> arr){
    int slow = arr[0];
    int fast = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);

    fast = arr[0];

    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

void mergeNoSpace(vector<int> one, vector<int> two){
    int i = 0, j = 0;
    while(i < one.size()){
        if(one[i] > two[j]){
            swap(one[i], two[j]);
        }
        sort(two.begin(), two.end());
        i++;
    }
    printVector(one);
    printVector(two);
}

void mergeIntervals(vector<vector<int>> arr){
    vector<vector<int>> res;
    if(arr.size() == 0) return;

    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    });

    vector<int> curr = arr[0];

    for(int i = 1; i < arr.size(); i++){
        if(curr[1] < arr[i][0]){
            res.push_back(curr);
            curr = arr[i];
        }
        curr[1] = max(curr[1],arr[i][1]);
    }
    res.push_back(curr);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

void nextPermutation(vector<int> &arr){
    int idx1 = -1, idx2;
    for(int i = arr.size()-2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            idx1 = i;
            break;
        }
    }
    if(idx1 == -1){
        reverse(arr.begin(), arr.end());
    } else {
        for(int i = arr.size()-1; i >= 0; i--){
            if(arr[i] > arr[idx1]){
                idx2 = i;
                break;
            }
        }
        swap(arr[idx1], arr[idx2]);
        reverse(arr.begin()+idx1+1, arr.end());
    }
    printVector(arr);
}

int buySellStock(vector<int> arr){
    int maxRight = arr[arr.size()-1];
    int maxProfit = 0;
    for(int i = arr.size()-2; i >= 0; i--){
        maxRight = max(maxRight, arr[i]);
        maxProfit = max(maxProfit, maxRight-arr[i]);
    }
    return maxProfit;
}

int maxProduct(vector<int> arr){
    int max_pr = -1, curr = 1;
    for(int i = 0; i < arr.size(); i++){
        curr *= arr[i];
        if(curr > max_pr){
            max_pr = curr;
        }
    }
    curr = 1;
    for(int i = arr.size()-1; i >= 0; i--){
        curr *= arr[i];
        if(curr > max_pr){
            max_pr = curr;
        }
    }
    return max_pr;
}

int trapWater(vector<int> arr){
    int res = 0;
    vector<int> left(arr.size());
    left[0] = arr[0];
    for(int i = 1; i < left.size(); i++){
        left[i] = max(left[i-1], arr[i]);
    }

    vector<int> right(arr.size());
    right[arr.size()-1] = arr[arr.size()-1];
    for(int i = arr.size()-2; i>= 0; i--){
        right[i] = max(right[i+1], arr[i]);
    }

    for(int i = 1; i < arr.size()-1; i++){
        res += min(left[i], right[i]) - arr[i];
    }

    return res;
}

int chocolateDistribution(vector<int> arr, int m){
    if(arr.size() == 0) return 0;
    
    sort(arr.begin(), arr.end());

    int res = arr[m-1] - arr[0];

    int i = 1, j = m;

    while(j < arr.size()){
        res = min(res, arr[j]-arr[i]);
        i++;
        j++;
    }
    return res;
}

int smallestSubWithSum(vector<int> arr, int target){
    int left = 0, total = 0, res = INT_MAX;
    for(int i = 0; i < arr.size(); i++){
        total += arr[i];
        while(total > target){
            res = min(res, i-left+1);
            total = total - arr[left];
            left++;
        }
    }
    return res;
}

void threeWayPartition(vector<int> &arr, int a, int b){
    int start = 0, i = 0, end = arr.size()-1;
    printVector(arr);

    while(i <= end){
        if(arr[i] < a){
            swap(arr[i++], arr[start++]);
        } else if(arr[i] > b){
            swap(arr[i], arr[end--]);
        } else {
            i++;
        }
    }
    printVector(arr);
}

int pairSum(vector<int> arr, int sum){
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size()-1;
    int pairs = 0;
    while(i < j){
        int curr = arr[i] + arr[j];
        if(curr == sum){
            pairs++;
            i++;
            j--;
        } else if(curr > sum){
            j--;
        } else {
            i++;
        }
    }
    return pairs;

}

void commonElements(vector<int> a, vector<int> b, vector<int> c){
    int i = 0, j = 0, k = 0;
    int n1 = a.size(), n2 = b.size(), n3 = c.size();
    int prev1 = INT_MIN, prev2 = INT_MIN, prev3 = INT_MIN;
    vector<int> ans;

    while(i < n1 && j < n2 && k < n3){
        // duplicacy check
        while(i < n1 && prev1 == a[i]){
            i++;
        }
        while(j < n2 && prev2 == b[j]){
            j++;
        }
        while(k < n3 && prev3 == c[k]){
            k++;
        }

        // store
        if(a[i] == b[j] && b[j] == c[k]){
            ans.push_back(a[i]);
            prev1 = a[i++];
            prev2 = b[j++];
            prev3 = c[k++];
        } else if(a[i] < b[j]){
            prev1 = a[i++];
        } else if(b[j] < c[k]){
            prev2 = b[j++];
        } else {
            prev3 = c[k++];
        }
    }
    printVector(ans);
}

void rearrangeAltPos(vector<int> &arr){
    printVector(arr);
    int n = arr.size();
    int i = -1, j = n;

    while(i < j){
        while(i <= n-1 && arr[i] >= 0){
            i++;
        }
        while(j >= 0 && arr[j] < 0){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    printVector(arr);
    
    // i denotes the index for first negative appearing element.
    if(i == 0 || i == n) return;

    int k = 0;

    while(k < n && i < n){
        swap(arr[i], arr[k]);
        k += 2;
        i++;
    }

    printVector(arr);

}

int main(){
    // Q1. Reverse the array.
    // vector<int> arr {1,2,3,4,5};
    // reverseArr(arr);

    // Q2. Maximum and Minimum element in the array.
    // vector<int> arr {3, 5, 4, 1, 9};
    // maxMinElement(arr);

    // Q4. Sort an array consisting of 0,1,2.
    // vector<int> arr = {0, 2, 1, 2, 0};
    // sort012(arr);

    // Q5. Move negative elements to beginning
    // vector<int> arr {1, 2,  -4, -5, 2, -7, 3, 2, -6, -8, -9, 3, 2,  1};
    // moveNegBegin(arr);

    // Q6A. Intersection of Two Sorted Arrays.
    // vector<int> one {85, 25, 1, 32, 54, 6};
    // vector<int> two {85,2};
    // intersectionArrays(one, two);

    // Q6B. Union of Two Sorted Arrays.
    // vector<int> one {1,2,2,3,4,5};
    // vector<int> two {3,5,9};
    // unionArrays(one, two);

    // Q7.Find Largest Sum Contiguous SubArray.
    // vector<int> arr = {-1,-2,-3,-4};
    // cout << "The Largest sum subarray is : " << kadane(arr) << endl;

    // Q8. Minimize the Heights II
    // vector<int> arr {1, 5, 8, 10};
    // cout << "The Minimum Possible differnce bw height of shortest and tallest tower is : " << minimizeHeights(arr, 2);

    // Q9. Find Duplicate in an Array.
    // vector<int> arr {1,3,4,2,2};
    // cout << "The Duplicate Element is : " << duplicateElement(arr) << endl;

    // Q10. Merge 2 sorted arrays without using Extra space
    // vector<int> one {1,2,2,3,4,5};
    // vector<int> two {3,5,9};
    // mergeNoSpace(one, two);

    // Q11. Merge Intervals.
    // vector<vector<int>> arr {{1,3},{2,6},{8,10},{15,18}};
    // mergeIntervals(arr);

    // Q12. Next Permutation.
    // vector<int> arr {1,2,3};
    // nextPermutation(arr);

    // Q13. Best time to buy and Sell stock.
    // vector<int> arr {7,6,4,3,1};
    // cout << "Best time to buy and Sell stock : " << buySellStock(arr) << endl;    

    // Q14. Find maximum product subarray.
    // vector<int> arr {6, -3, -10, 0, 2};
    // cout << "Maximum product subarray is : " << maxProduct(arr) << endl;

    // Q15. Trapping Rain Water.
    // vector<int> arr = {7,4,0,9};
    // cout << "Trapped water : " << trapWater(arr) << endl;

    // Q16. Chocolate Distribution Problem.
    // vector<int> arr {7, 3, 2, 4, 9, 12, 56};
    // int m = 3;
    // cout << "The minimum difference between maximum chocolates and minimum chocolates is : " << chocolateDistribution(arr, m) << endl;

    // Q17. Smallest Subarray with sum greater than a given value.
    // vector<int> arr {1, 10, 5, 2, 7};
    // int x = 9;
    // cout << "Minimum length subarray is : " << smallestSubWithSum(arr, x) << endl;

    // Q18. Three way partitioning of an array around a given value.
    // vector <int> arr {1,14,5,20,4,2,54,20,87,98,3,1,32};
    // int a = 10, b = 20;
    // threeWayPartition(arr, a, b);

    // Q19. Count pairs with given sum.
    // vector<int> arr {1, 5, 7, 1};
    // int sum = 6;
    // cout << "The number of pairs : " << pairSum(arr, sum) << endl;

    // Q20. find common elements In 3 sorted arrays.
    // vector<int> a {1, 5, 10, 20, 40, 80};
    // vector<int> b {6, 7, 20, 80, 100};
    // vector<int> c {3, 4, 15, 20, 30, 70, 80, 120};
    // commonElements(a, b, c);

    // Q21. Rearrange array in alternating positive & negative items with O(1) extra space
    vector<int> arr {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    rearrangeAltPos(arr);



    return 0;
}