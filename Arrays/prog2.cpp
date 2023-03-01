#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

void printVector(vector <int> &arr){
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
}

void nextPermutation(vector <int> &arr){
    if(arr.size() <= 0){
        return;
    }
    int idx1=-1, idx2 = 0;
    for(int i = arr.size()-2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            idx1 = i;
            break;
        }
    }

    if(idx1 < 0){
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

int maxProfit(vector <int> &arr){
    int maxRight = arr[arr.size()-1];
    int profit = 0;

    for(int i = arr.size()-2; i >= 0; i--){
        maxRight = max(maxRight, arr[i]);
        profit = max(profit, maxRight-arr[i]);
    }

    return profit;
}

int multipleBuys(vector <int> &arr){
    int profit = 0;
    for(int i = arr.size()-2; i >= 0; i--){
        if(arr[i+1] > arr[i]){
            profit += arr[i+1] - arr[i];
        }
    }
    return profit;
}

int getPairsCount(vector <int> &arr, int sum){
    int i = 0, j = arr.size()-1;
    int pairs = 0;
    while(i < j){
        int k = arr[i] + arr[j];
        if(k == sum){
            pairs++;
            i++;
            j--;
        } else if(k > sum){
            j--;
        } else {
            i++;
        }
    }
    return pairs;
}

void commonElements(vector <int> &a, vector <int> &b, vector <int> &c){
    vector <int> ans;
    int i = 0, j = 0, k = 0;
    int n1 = a.size(), n2 = b.size(), n3 = c.size();
    // To track Duplicates
    int prev1, prev2, prev3;
    prev1 = prev2 = prev3 = INT_MIN;

    while(i < n1 && j < n2 && k < n3){
        // Should Not Include Duplicates
        while(i < n1 && prev1 == a[i]){
            i++;
        }
        while(j < n2 && prev2 == b[j]){
            j++;
        }
        while(k < n3 && prev3 == c[k]){
            k++;
        }
        if(a[i] == b[j] && b[j] == c[k]){
            ans.push_back(a[i]);
            prev1 = a[i];
            prev2 = b[j];
            prev3 = c[k];
            i++;
            j++;
            k++;   
        } else if(a[i] < b[j]){
            prev1 = a[i];
            i++;
        } else if(b[j] < c[k]){
            prev2 = b[j];
            j++;
        } else {
            prev3 = c[k];
            k++;
        }
    }
    cout << "The Size is : " << ans.size() << endl;
    printVector(ans);
}

void naiveRearrange(vector <int> &arr){
    printVector(arr);
    vector <int> neg;
    vector <int> pos;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < 0){
            neg.push_back(arr[i]);
        } else {
            pos.push_back(arr[i]);
        }
    }
    int i = 0, j = 0, k = 0;
    while(i < pos.size() && j < neg.size()){
        arr[k++] = neg[j++];
        arr[k++] = pos[i++];
    }

    while(i < pos.size()){
        arr[k++] = pos[i++];
    }

    while(j < neg.size()){
        arr[k++] = neg[j++];
    }

    printVector(arr);
}

void efficientRearrange(vector <int> &arr){
    int i = 0, j = arr.size() - 1;
    // P P P P P N N N N N
    while(i < j){
        if(arr[i] > 0 && arr[j] < 0){
            i++;
            j--;
        } else if(arr[i] < 0 && arr[j] > 0){
            swap(arr[i], arr[j]);
            j--;
            i++;
        } else if(arr[i] < 0 && arr[j] < 0){
            j--;
        } else {
            i++;
        }
    }
    printVector(arr);
    // cout << arr[i] << endl;

    int k = 0;
    while(i < arr.size()){
        swap(arr[k], arr[i]);
        i++;
        k += 2;
    }

    printVector(arr);
}

int appearance(vector <int> &arr, int k){
    unordered_map <int, int> m;
    int cnt = 0;
    for(int i = 0; i < arr.size(); i++){
        m[arr[i]] += 1;
        if(m[arr[i] > arr.size()/k]){
            cnt++;
            m[arr[i]] = -1000;
        }
    }
    return cnt;
}

bool isSubset(int a1[], int n, int a2[], int m){
    unordered_map <int, int> map;
    for(int i = 0; i < n; i++){
        map[a1[i]] = 1;
    }
    for(int j = 0; j < m; j++){
        if(map[a2[j]] != 1){
            return false;
        }
    }
    return true;
}

bool isTriplet(int *arr, int n, int x){
    sort(arr, arr+n);
    int s, e = n-1;
    for(int i = 0; i < n; i++){
        int y = x - arr[i];
        s = i+1;
        while(s < e){
            if(arr[s] + arr[e] == y){
                return 1;
            } else if(arr[s] + arr[e] > y){
                e--;
            } else {
                s++;
            }
        }
    }
    return 0;
}

int findMinDiff(int arr[], int n, int m){
    sort(arr, arr+n);
    int minDiff = arr[m-1] - arr[0];
    int i = 1, j = m;
    while(j < n){
        minDiff = min(minDiff, arr[j]-arr[i]);
        i++;
        j++;
    }
    return minDiff;
}

int minSwaps(vector <int> &arr, int K){
    int cnt = 0, bad = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] <= K){
            cnt++;
        }
    }

    for(int i = 0; i < cnt; i++){
        if(arr[i] > K){
            ++bad;
        }
    }

    int ans = bad;
    for(int i = 0, j = cnt; j < arr.size(); i++, j++){
        if(arr[i] > K){
            --bad;
        }
        if(arr[j] > K){
            ++bad;
        }
        ans = min(ans, bad);
    }
    return ans;
}

bool isPalindrome(int n){
        int rev = 0, temp = n;
        while(n != 0){
            int last = temp%10;
            rev = rev*10 + last;
            n = n/10;
        }
        return n==rev ? 1 : 0;
}

int mergeOperations(vector <int> &arr){
    int ops = 0;
    int i = 0, j = arr.size() - 1;
    while(i <= j){
        if(arr[i] == arr[j]){
            i++;
            j--;
        } else if(arr[i] < arr[j]){
            i++;
            arr[i] += arr[i-1];
            ops++;
        } else {
            j--;
            arr[j] += arr[j+1];
            ops++;
        }
    }
    return ops;
}

void threeWayPartition(vector <int> &arr, int a, int b){
    int start = 0, end = arr.size()-1, i = 0;
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

void sort012(vector <int> &arr){
    printVector(arr);
    int start = 0, i = 0, j = arr.size();
    while(i <= j){
        if(arr[i] == 0){
            swap(arr[i++], arr[start++]);
        } else if(arr[i] == 2){
            swap(arr[i], arr[j--]);
        } else {
            i++;
        }
    }
    printVector(arr);
}

int maxProfitTwice(vector <int> &arr){
    int n = arr.size();
    int maxRight = arr[n-1];
    vector <int> back(n, 0);
    // For 1st max Profit
    for(int i = n-2; i >= 0; i--){
        maxRight = max(arr[i], maxRight);
        back[i] = max(maxRight-arr[i], back[i+1]);
    }

    // 2nd max Profit
    int minPrice = arr[0];

    for(int i = 1; i < n; i++){
        minPrice = min(minPrice, arr[i]);
        back[i] = max(back[i-1], arr[i]-minPrice+back[i]);
    }

    // Find Max Profit
    int ans = back[n-1];

    // printVector(back);
    return ans;
}

string shiftString(string &str, int n){
    string new1 = "";
    for(int i = 0; i < str.size(); i++){
        char c = str[i];
        new1.push_back(char(char(c-'A'+n)%26 + 'A'));
    }
    return new1;
}

void print2D(vector <vector<int>> arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;
}

void findTriplets(vector<int>arr, int n, int K) {
	vector <vector<int>> ans;
    int e = n-1;
	sort(arr.begin(), arr.end());
	for(int i = 0; i < n; i++){
		int tmp = arr[i];
		int y = K - tmp;
		int s = i+1;
		while(s < e){
			if(arr[s] + arr[e] == y){
				ans.push_back({tmp, arr[s], arr[e]});
				s++;
				e--;
			} else if(arr[s] + arr[e] > y){
				e--;
			} else {
				s++;
			}
		}
	}
	if(ans.size() == 0){
		ans.push_back({-1});
	}
	print2D(ans);
}

string replaceSpaces(string &str){
	string new1 = "";
	for(int i = 0; i < str.size(); i++){
		if(str[i] == ' '){
			new1.push_back('@');
			new1.push_back('4');
			new1.push_back('0');
		} else {
		    new1.push_back(str[i]);
        }
	}
	return new1;
}

int main(){
    // Q. TRIPLET
    // vector <int> arr = {1, 2, 3, 4};
    // vector <int> arr = {1, 2, 3, 1, 2, 3};
    // findTriplets(arr, arr.size(), 6);

    // Q19. Next Permutation.
    // vector <int> arr {4,3,2,1};
    // nextPermutation(arr);

    // Q20. Best Time to Buy and Sell Stock
    // On single buy not multiple buys
    //                0,1,2,3,4,5
    // vector <int> arr {7, 6, 4, 3, 1};
    // vector <int> arr {7,1,5,3,6,4};
    // cout << "Max Profit : " << maxProfit(arr);
    // cout << "Max Profit : " << multipleBuys(arr);

    // Q21. Find all pairs on integer array whose sum is equal to given number.
    // vector <int> arr {1,2,3,4,5,6,7};
    // int k = 8;
    // cout << "No. of pairs : " << getPairsCount(arr, k) << endl;

    // Q22. Find common elements In 3 sorted arrays
    // vector <int> A = {1,1,3,3};
    // vector <int> B = {1,1,2,2};
    // vector <int> C = {2,2,3,3};
    // commonElements(A, B, C);

    // Q23. Rearrange the array in alternating positive and negative items.
    // vector <int> arr {1,2,3,-4,-1,4};
    // naiveRearrange(arr);
    // efficientRearrange(arr);

    // Q24. Find all elements appearing more than n/k times
    // using unordered map
    // vector <int> arr {3, 1, 2, 2, 1, 2, 3, 3};
    // int k = 4;
    // cout << "elements appearing more than " << arr.size()/k << " is : " << appearance(arr, k) << endl;

    // Q25. Find whether an array is a subset of another array.
    // int a1[] = {11, 1, 13, 21, 3, 7};
    // int a2[] = {11, 3, 7, 1, 99};
    // cout << "Is a subset ? : " << isSubset(a1, 6, a2, 5) << endl;

    // Q26. Find the triplet that sum to a given value.
    // int arr[] = {1, 4, 45, 6, 10, 8};
    // int n = 6, X = 13;
    // cout << "Is there any triplet ? : " << isTriplet(arr, n, X);

    // Q27. Chocolate Distribution Problem.
    // int N = 7, M = 3;
    // int A[] = {7, 3, 2, 4, 9, 12, 56};
    // cout << "The Minimum Diff is : " << findMinDiff(A, N, M) << endl;

    // Q28. Minimum swaps required bring elements less equal K together
    // vector <int> arr = {2, 7, 9, 5, 8, 7, 4};
    // int K = 6;
    // cout << "The Minimum Swaps are : " << minSwaps(arr, K) << endl;

    // Q29. Minimum no. of merge operations required to make an array palindrome.
    // vector <int> arr {1,4,5,1};
    // cout << "Min merge operations : " << mergeOperations(arr) << endl;

    // Q30. Three Way Partitioning (Dutch Algorithm).
    // vector <int> arr {1,14,5,20,4,2,54,20,87,98,3,1,32};
    // int a = 10, b = 20;
    // threeWayPartition(arr, a, b);

    // Q31. Sort 0, 1 and 2.
    // vector <int> arr {1,1,2,2,0,0,1,0,2};
    // sort012(arr);

    // -------------- HARD ------------------
    // Q32. Maximum profit by buying and selling a share atmost twice.
    // vector <int> arr {10,22,5,75,65,80};
    // vector <int> arr {2, 30, 15, 10, 8, 25, 80};
    // cout << "Max Profit atmost twice is : " << maxProfitTwice(arr) << endl;

    // -------------- SURYA's ---------------
    // Q. Add n to str
    // string s = "XYZSTVOPQRT";
    // int n = 98;
    // cout << shiftString(s, n) << endl;
    // char c = 'Z';
    // cout << char(char(c-'A'+2)%26 + 'A');

    string str = "coding ninjas is a coding platform";
    cout << replaceSpaces(str);

    return 0;
}