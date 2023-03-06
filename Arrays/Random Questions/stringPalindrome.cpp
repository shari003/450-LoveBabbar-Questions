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

int noOfStrings(string text, string name){
    int len1 = text.length();
    int len2 = name.length();
    int ans = 0;
    for(int i = 0; i < len1; i++){
        // cout << "I : " << i << endl;
        bool flag = false;
        if(smallCap(text[i]) == smallCap(name[0])){
            cout << "Yes" << endl;
            for(int j = i, k = 0; j < len2 && j < len1; j++, k++){
                cout << "J : " << text[j] << endl;
                if(smallCap(text[j]) == smallCap(name[k])){
                    flag = true;
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) ans++;
    }
    return ans;
}

int main(){
    string S = "c1 O$d@eeD o1c";
    // cout << "Is Palindrome ? : " << isPalindrome(S);
    // cout << makeStr(S);
    // int arr[] {1,2,1,1,2,1};
    // cout << isArr(arr, 6);

    string text = "TimistheloveTimplaystim";
    string name = "Tim";
    cout << "No of tims : " << noOfStrings(text, name) << endl;
    return 0;
}