#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printPatt(int n){
    int i = 0;
    while(i < n){
        int j = 0;
        while(j < n-i){
            cout << "*";
            j++;
        }
        int spaces = 2*i-1;
        while(spaces != 0 && spaces > 0){
            cout << " ";
            spaces--;
        }
        while(j > 0){
            cout << "*";
            j--;
        }
        cout << endl;
        i++;
    }

}

int main(){
    int n = 5;
    printPatt(n);
    return 0;
}