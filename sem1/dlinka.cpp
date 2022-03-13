//
// Created by zzemlyanaya on 22.09.2021.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

vector<int> mul(vector<int> a, vector<int> b) {
    int len = a.size() + b.size() + 1;
    vector<int> c(len);
    for (auto i : c) {
        i = 0;
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    for (int i = 0; i < len; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while (c.size() > 1 && c.back() == 0) {
        len--;
        c.pop_back();
    }
    return c;
}

vector<int> sum(vector<int> a, vector<int> b) {
    int len = std::max(a.size(), b.size()) + 1;
    while (b.size() < len)
        b.push_back(0);
    for (int i = 0; i < len; i++) {
        b[i] += (i < a.size() ? a[i] : 0);
        b[i + 1] += b[i] / 10;
        b[i] %= 10;
    }
    while (b.size() > 1 && b.back() == 0) {
        len--;
        b.pop_back();
    }
    return b;
}

vector<int> diff(vector<int> a, vector<int> b) {
    int len = a.size();
    for (int i = 0; i < len; i++) {
        a[i] -= (i < b.size() ? b[i] : 0);
    }
    for (int i = 0; i < len - 1; i++) {
        if (a[i] < 0) {
            a[i] += 10;
            a[i + 1] -= 1;
        }
    }
    while (b.size() > 1 && b.back() == 0) {
        len--;
        b.pop_back();
    }

    return a;
}

vector<vector<int>> divs(vector<int> a, int b){
    int cur=0, i=0, q;
    vector<int> res;
    for (int i = a.size()-1; i >= 0 || q > 0; i--) {
        cur += i >= 0 ? a[i] : 0;
        q = cur/b;
        if (q == 0)
            cur *= 10;
        else {
            res.push_back(cur/b);
            if (i > 0)
                cur = (cur%b)*10;
            else
                cur %= b;
        }
    }

    if(res.size() == 0)
        res.push_back(0);
    else
        reverse(res.begin(), res.end());
    vector<vector<int>> vec{res, vector<int>{cur/10}};
    return vec;
}

void print(vector <int> v){
    bool flag = false;
    while (!v.empty()) {
        if (flag || v.back() != 0 || v.size() == 1) {
            cout << v.back();
            flag = true;
        }
        v.pop_back();
    }
    cout << endl;
}

vector<int> to_vec(string n) {
    vector<int> nn;
    for (int i = n.length() - 1; i >= 0; i--) {
        nn.push_back(int(n[i]) - int('0'));
    }

    return nn;
}


int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string aa, bb;
    int bbb;
    vector<int> a, b;
    cin >> aa >> bbb;

    a = to_vec(aa);
    b = to_vec(bb);

    vector<vector<int>> res = divs(a, bbb);

    print(res[0]);
    print(res[1]);

    return 0;
}

