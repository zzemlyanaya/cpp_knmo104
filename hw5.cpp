//
// Created by zzemlyanaya on 27.10.2021.
//
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void solveFirst(int n) {
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    int cur;
    if (n < 3) {
        cout << "Invalid input" << endl;
        return;
    }
    while (n--) {
        cin >> cur;
        if (cur > first){
            third = second;
            second = first;
            first = cur;
        }
        else if (cur > second){
            third = second;
            second = cur;
        }
        else if (cur > third)
            third = cur;
    }
    cout << first << " " << second << " " << third << endl;
}

void solveSecond(int n) {
    int array[100];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int diff = 0, len = 0, longest_len = 2, longest_i = 0, j = 0;
    for (int i = 0; i < n - longest_len; i += len-1) {
        diff = array[i+1]-array[i];
        for(j = i+2; j < n && array[j-1]+diff == array[j]; ++j);
        len = j - i;
        if (longest_len < len) {
            longest_len = len;
            longest_i = i;
        }
    }
    diff = array[longest_i+1] - array[longest_i];
    for(int i = 0; i < longest_len; ++i){
        cout << array[longest_i + i] << " ";
    }
    cout << endl << "Основание прогрессии: " << diff << endl;
}

void print_num(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
    }
    cout << endl;
}

void solveThird(string s, int p) {
    int num[100];
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        num[i] = s[i]-'0';
    }
    for (int i = n-1; i >= 0; i--) {
        num[i] *= p;
    }
    for (int i = n-1; i > 0; i--) {
        if (num[i] >= 10) {
            num[i-1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    print_num(num, n);
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    int k;
    string s;

    int n = 1;
    cout << "Номер задачи для теста:" << endl;
    cin >> n;
    while (n != -1) {
        switch(n) {
            case 1: {
                cin >> k;
                solveFirst(k);
                break;
            }
            case 2: {
                cin >> k;
                solveSecond(k);
                break;
            }
            case 3: {
                cin >> s >> k;
                solveThird(s, k);
                break;
            }
//            case 4: {
//                cin >> s >> k;
//                solveFourth(s, k);
//                break;
//            }
            default:
                break;
        }
        cout << "Номер задачи для теста:" << endl;
        cin >> n;
    }

    return 0;
}
