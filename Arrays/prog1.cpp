#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printVector(vector <int> &arr){
    for(int i : arr){
        cout << i << " ";
    }
    cout <<endl;
}

void reverseArr(vector <int> &arr){
    int s = 0, e = arr.size()-1;
    while(s < e){
        swap(arr[s++], arr[e--]);
    }
    printVector(arr);
}

void minMax(vector <int> &arr){
    int mini = arr[0], maxi = arr[0];
    for(int i = 1; i < arr.size(); i++){
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }

    cout << "The Maximum is : " << maxi << " and Minimum is : " << mini << endl;
}

void kthSmallestElement(vector <int> &arr, int k){
    sort(arr.begin(), arr.end());
    cout << "Minimum is : " << arr[k-1] << endl;
}

void sort012(vector <int> &arr){
    int s = 0, m = 0, e = arr.size()-1;
    while(m <= e){
        switch(arr[m]){
            case 0:
                swap(arr[s++], arr[m++]);
                break;
            case 1:
                m++;
                break;
            case 2:
                swap(arr[m], arr[e--]);
                break;
        }
    }
    printVector(arr);
}

void moveNegative(vector <int> &arr){
    printVector(arr);
    int n = arr.size();
    int nonNegative = n - 1; // Non negative elements should be at the right side of array
    for(int i = n-1; i >= 0; i--){
        if(arr[i] > 0){
            swap(arr[i], arr[nonNegative--]);
        }
    }
    sort(arr.begin(), arr.end());
    printVector(arr);
}

void intersectionArr(vector <int> &a, vector <int> &b){
    int i = 0, j = 0, m = a.size(), n = b.size();
    vector <int> ans;
    while(i < m && j < n){
        if(a[i] == b[j]){
            ans.push_back(a[i]);
            i++;
            j++;
        } else if(a[i] > b[j]){
            j++;    
        } else {
            i++;
        }
    }
    printVector(ans);
}

void unionArr(vector <int> &a, vector <int> &b){
    vector <int> ans;
    int i = 0, j = 0, m = a.size(), n = b.size();
    while(i < m || j <  n){
        // Skip the duplicates
        while(i > 0 && i < m && a[i] == a[i-1]){
            i++;
        }
        while(j > 0 && j < n && b[j] == b[j-1]){
            j++;
        }

        // if any one array finishes
        if(i >= m){
            ans.push_back(b[j]);
            j++;
            continue;
        }
        if(j >= n){
            ans.push_back(a[i]);
            i++;
            continue;
        }

        // comparison
        if(a[i] < b [j]){
            ans.push_back(a[i]);
            i++;
        } else if(a[i] > b [j]){
            ans.push_back(b[j]);
            j++;
        } else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    printVector(ans);
}

void rotateBy1(vector <int> &arr){
    int temp = arr[arr.size() - 1];
    for(int i = arr.size()-1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
    printVector(arr);
}

int kadaneAlgo(vector <int> &arr){
    int curr_sum = 0, max_sum = 0;
    for(int i = 0; i < arr.size(); i++){
        curr_sum += arr[i];
        max_sum = max(max_sum, curr_sum);
        if(curr_sum < 0){
            curr_sum = 0;
        }
    }
    return max_sum;
}

int trapWater(vector <int> &arr){
    int res = 0, n = arr.size();
    vector <int> lsum(n);
    vector <int> rsum(n);

    lsum[0] = arr[0];
    for(int i = 1; i < n; i++){
        lsum[i] = max(lsum[i-1], arr[i]);
    }

    rsum[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        rsum[i] = max(arr[i], rsum[i+1]);
    }

    for(int i = 1; i < n-1; i++){
        res += min(lsum[i], rsum[i]) - arr[i];
    }
    return res;
}

int smallestSubWithSum(vector <int> &arr, int sum){
    int left = 0, total = 0, res = INT_MAX;
    for(int i = 0; i < arr.size(); i++){
        total += arr[i];
        while(total > sum){
            res = min(res, i - left + 1);
            total = total - arr[left];
            left++;
        }
    }
    return res;
}

int maxProduct(vector <int> &arr){
    int curr_product = 1, max_product = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        curr_product *= arr[i];
        max_product = max(max_product, curr_product);
        if(curr_product == 0){
            curr_product = 1;
        }
    }
    curr_product = 1;
    for(int i = arr.size()-1; i >= 0; i--){
        curr_product *= arr[i];
        max_product = max(max_product, curr_product);
        if(curr_product == 0){
            curr_product = 1;
        }
    }
    return max_product;
}

bool subArr0(vector <int> &arr){
    int n = arr.size();
    vector <int> prefixSum(n);
    prefixSum[0] = arr[0]; 
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            return 1;
        }
        if(i >= 1){
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(prefixSum[i] == 0){
            return 1;
        }
    }

    return 0;
}

int duplicateElement(vector <int> &arr){
    int slow = arr[0], fast = arr[0];
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

int minDiff(int arr[], int n, int k){
    if(n==1) return 0;
    sort(arr, arr+n);
    int diff = arr[n-1] - arr[0];
    int maxi, mini;
    for(int i = 1; i < n; i++){
        if(arr[i]-k < 0) continue;
        maxi = max(arr[n-1]-k, arr[i-1]+k);
        mini = min(arr[0]+k, arr[i]-k);
        diff = min(diff, maxi-mini);
    }
    return diff;
}

int minJumps(int arr[], int n){
    int jump = 0, pos = 0, dest = 0;
    
    for(int i = 0; i < n-1; i++){

        dest = max(dest, arr[i]+i);

        if(pos == i){
            pos = dest;
            jump++;
        }
    }
    return jump;
}

int naiveCntInversions(vector <int> &arr);

int merge(vector <int> &arr, int left, int mid, int right){
    int i = left, j = mid, k = 0;
    int inv_cnt = 0;
    vector <int> temp(right-left+1);
    while((i < mid) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];

            inv_cnt += (mid-i);
        }
    }

    while(i < mid){
        temp[k++] = arr[i++];
    }

    while(j <= right){
        temp[k++] = arr[j++];
    }

    for(i = left, k = 0; i <= right; i++, k++){
        arr[i] = temp[k];
    }

    return inv_cnt;

}

int mergeSort(vector <int> &arr, int left, int right){
    int inv_cnt = 0;
    if(right > left){

        int mid = left+(right-left)/2;

        inv_cnt = mergeSort(arr, left, mid);
        inv_cnt += mergeSort(arr, mid+1, right);

        inv_cnt += merge(arr, left, mid+1, right);
    }
    return inv_cnt;
}

int efficientCntInversions(vector <int> &arr){
    return mergeSort(arr, 0, arr.size()-1);
}

void sortArr(vector <int> &arr){
    for(int i = 0; i < arr.size()-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
}

void mergeTwoSortedArraysWithoutExtraSpace(vector <int> &a, vector <int> &b){
    int i = 0, j = 0, n = a.size();
    while(i < n){
        if(a[i] > b[j]){
            swap(a[i], b[j]);
        }
        sortArr(b);
        i++;
    }
}

int main(){
    // Q1. Reverse the array.
    // vector <int> arr {1,2,3,4,5};
    // reverseArr(arr);

    // Q2. Find Min and Max element in an array.
    // vector <int> arr {2,24,1,13,99,56,12};
    // minMax(arr);

    // Q3. Find kth smallest element in the array.
    // vector <int> arr {7, 10, 4, 3, 20, 15};
    // int k = 3;
    // kthSmallestElement(arr, k);

    // Q4. Sort 0 1 2
    // vector <int> arr {0,2,1,0,0,2,2,1,1};
    // sort012(arr);

    // Q5. Move all Negative Numbers to beginning
    // vector<int> arr { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    // moveNegative(arr);

    // Q6. Union Of Two Arrays.
    // vector <int> a {1, 2, 3, 4, 5};
    // vector <int> b {1, 2, 3};
    // unionArr(a, b);

    // Q7. Write a program to cyclically rotate an array by one.
    // vector <int> arr {1, 2, 3, 4, 5};
    // rotateBy1(arr);

    // Q8. Find Largest sum contiguous Subarray 
    // vector <int> arr {1,2,3,-2,5};
    // cout << "The Maximum sum is : " << kadaneAlgo(arr);

    // Q9. Trapping Rain Water Problem.
    // vector <int> arr = {3,0,0,2,0,4};
    // cout << "Trapped Water : " << trapWater(arr) << endl;

    // Q10. Smallest subarray with sum greater than x.
    // vector <int> A = {1, 4, 45, 6, 0, 19};
    // vector <int> A = {1, 10, 5, 2, 7};
    // int sum = 9;
    // cout << "The Minimum Possible Length is : " << smallestSubWithSum(A, sum) << endl;

    // Q11. Maximum Product Subarray.
    // vector <int> arr {6, -3, -10, 0, 2};
    // vector <int> arr {0,0,0,-5,0};
    // vector <int> arr {2, 3, 4, 5, -1, 0};
    // cout << "The Maximum Product is : " << maxProduct(arr) << endl;


    // -------------------------------------------------------
    // Q12. Find if there is any subarray with sum equal to 0.
    // vector <int> arr = {4, 2, -3, 1, 6};
    // vector <int> arr = {4, 2, 0, 1, 6};
    // vector <int> arr = {1,2,3,4,5};
    // cout << "Is there sub array : " << subArr0(arr);
    // -------------------------------------------------------  

    // Q13. Find duplicate in an array of N+1 Integers
    // using slow and fast pointers.
    // vector <int> arr = {1, 3, 4, 2, 2};
    // cout << "The Duplicate Element is : " << duplicateElement(arr) << endl;

    // Q14. Union of two sorted arrays.
    // vector <int> a {1, 2, 3, 4, 5};
    // vector <int> b {1, 2, 3};
    // unionArr(a, b);

    // Q15. Minimise the maximum difference between heights [V.IMP]
    // int arr[] = {1, 5, 8, 10};
    // int n = 4, k = 2;
    // cout << "Minimized Height is : " << minDiff(arr, n, k) << endl;

    // ------------------------------------------------------------------------
    // Q16. Minimum no. of Jumps to reach end of an array.
    // int arr[] = {1,0,3,2,1};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // cout << "Minimum Number of Jumps required : " << minJumps(arr, n) << endl;
    // ------------------------------------------------------------------------

    // Q17. Count Inversions.
    // vector <int> arr {2,5,1,3,4};
    // cout << "Naive Count of Inversions : " << naiveCntInversions(arr) << endl;
    // cout << "(Efficient with Merge Sort) Count of Inversions : " << efficientCntInversions(arr) << endl;

    // Q18. Merge Two Sorted Arrays.
    // vector <int> a {1, 4, 5, 7};
    // vector <int> b {2, 3, 6};
    // mergeTwoSortedArraysWithoutExtraSpace(a, b);
    // printVector(a);
    // printVector(b);

    return 0;
}

int naiveCntInversions(vector <int> &arr){
    int cnt = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size(); j++){
            if(arr[i] > arr[j] && i < j){
                cnt++;
            }
        }
    }
    return cnt;
}