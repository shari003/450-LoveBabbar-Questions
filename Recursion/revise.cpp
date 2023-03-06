#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
}

bool isGoodNumber(int num, int d){
    int digit = num % 10;
    if(digit == d) return 0;

    int rightSum = digit;
    num /= 10;
    while(num){
        digit = num%10;
        if(digit <= rightSum) return 0;
        rightSum += digit;
        if(digit == d) return 0;
        num /= 10;
    }
    return 1;
}

void solveBin(string str, int n){
    if(n == 0) {
        cout << str << " ";
        return;
    }

    solveBin(str+'0', n-1);
    solveBin(str+'1', n-1);
}

void genBinStrings(int n){
    string str = "";
    solveBin(str, n);
}

void solveNo1s(string str, int n, int bit){
    if(n==0) {
        cout << str << " ";
        return;
    }

    solveNo1s(str+'0', n-1, 0);

    if(bit == 0){
        solveNo1s(str+'1', n-1, 1);
    }
}

void genNoCons1sBIN(int n){
    string str = "";
    solveNo1s(str, n, 0);
}

void solveParan(int n, string str, int oc, int cc){
    if(oc == n && cc == n){
        cout << str << endl;
        return;
    }
    if(oc < n){ // 
        solveParan(n, str+'[', oc+1, cc);
    } 
    if(cc < oc){ // Cant be closed until there's one more opening paranthesis
        solveParan(n, str+']', oc, cc+1);
    }
}

void genParanthesis(int n){
    string str = "";
    int oc = 0, cc = 0;
    solveParan(n, str, oc, cc);
}

void solvePower(string str, string op, int n){
    if(n == str.length()){
        cout << op << endl;
        return;
    }
    solvePower(str, op+str[n], n+1);
    solvePower(str, op, n+1);
}

void powerSet(string str){
    string op = "";
    solvePower(str, op, 0);
}

void solvePerfect(vector<int> arr, vector<int> sub, int index, int target, int curr_sum){
    if(index >= arr.size()){
        if(target == curr_sum){
            printVector(sub);
        }
        return;
    }

    solvePerfect(arr, sub, index+1, target, curr_sum);

    sub.push_back(arr[index]);
    solvePerfect(arr, sub, index+1, target, curr_sum+arr[index]);
} 

void perfectSum(vector<int> arr, int sum){
    vector<int> sub;
    int index = 0;
    solvePerfect(arr, sub, index, sum, 0);
}

void solveSumSub1(vector<int> arr, vector<int> sub, int sum, int index){
    if(index >= arr.size()){
        cout << sum << " ";
        return;
    }

    solveSumSub1(arr, sub, sum, index+1);

    sub.push_back(arr[index]);
    solveSumSub1(arr, sub, sum+arr[index], index+1);
}

void subsetSum1(vector<int> arr){
    int sum = 0;
    vector<int> sub;
    solveSumSub1(arr, sub, sum, 0);
}

void solvePhone(string digits, string output, vector<string> map, int index){
    if(index >= digits.length()){
        cout << output << endl;
        return;
    }

    int num = digits[index] - '0';
    string val = map[num];

    for(int i = 0; i < val.length(); i++){
        output.push_back(val[i]);
        solvePhone(digits, output, map, index+1);
        output.pop_back();
    }

}

void phoneKeypad(string digits){
    string output = "";
    vector<string> map {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int index = 0;
    solvePhone(digits, output, map, index);
}

void solvePermStr(string str, int index){
    if(index >= str.length()){
        cout << str << " ";
        return;
    }

    for(int i = index; i < str.length(); i++){
        swap(str[i], str[index]);
        solvePermStr(str, index+1);
        swap(str[i], str[index]);
    }
}

void permutationStr(string str){
    string op = "";
    int index = 0;
    solvePermStr(str, index);
}

int main(){
    // Find the Good Number.
    // int n = 9620, a = 4;
    // cout << isGoodNumber(n, a);

    // Generate Binary Strings.
    // int n = 2;
    // genBinStrings(n);

    // Generate Binary Strings such that no consecutive 1s.
    // int n = 3;
    // genNoCons1sBIN(n);

    // Generate Paranthesis.
    // int n = 3;
    // genParanthesis(n);

    // Power Set.
    // string s = "abc";
    // powerSet(s);

    // Perfect Sum.
    // vector<int> arr {2, 3, 5, 6, 8, 10};
    // int sum = 10;
    // perfectSum(arr, sum);

    // Subsets Sum
    // vector<int> arr {2,3};
    // subsetSum1(arr);

    // Phone Keypad
    // string digits = "23";
    // phoneKeypad(digits);

    // Permutations Of A String.
    string str = "abc";
    permutationStr(str);

    return 0;
}