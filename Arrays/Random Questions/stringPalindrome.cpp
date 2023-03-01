#include<iostream>
#include<vector>
using namespace std;

bool isValidChar(char c){
    if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
        return 1;
    }
    return 0;
}

char smallCap(char c){
    if(c >= 'A' && c <= 'Z'){
        return c - 'A' + 'a';
    }
    return c;
}

string makeStr(string str){
    string new1 = "";
    for(int i = 0; i < str.size(); i++){
        if(isValidChar(str[i])){
            new1.push_back(smallCap(str[i]));
        }
    }
    return new1;
}

bool isPalindrome(string str){
    str = makeStr(str);
    int s = 0, e = str.size()-1;
    while(s <= e){
        if(str[s] != str[e]){
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}

bool isArr(int arr[], int n){
    int s = 0, e = n-1;
    while(s < e){
        if(arr[s] != arr[e]){
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}

int main(){
    string S = "c1 O$d@eeD o1c";
    cout << "Is Palindrome ? : " << isPalindrome(S);
    // cout << makeStr(S);
    // int arr[] {1,2,1,1,2,1};
    // cout << isArr(arr, 6);
    return 0;
}