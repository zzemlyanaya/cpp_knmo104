//
// Created by zzemlyanaya on 22.09.2021.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> to_vec(string n) {
    vector<int> nn;
    for (int i = n.length()-1; i >=0 ; i--) {
        nn.push_back(int(n[i]) - int('0'));
    }
    return nn;
}

vector<int> mul(vector<int> a, int b){
    int len = a.size() + 1;
    vector<int> c(len);
    for(auto i: c)
        i = 0;

    for (int i = 0; i < a.size(); i++) {
        c[i] += a[i]*b;
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }
    while(c.size() > 1 && c.back() == 0){
        len--;
        c.pop_back();
    }
    return c;
}

vector<int> divs(vector<int> a, int b){
    vector<int> c;
    int cur=0, i=0, q;
    for (int i = a.size()-1; i >= 0 || q > 0; i--) {
        cur += i >= 0 ? a[i] : 0;
        q = cur/b;
        if (q == 0)
            cur *= 10;
        else{
            c.push_back(cur/b);
            if (i > 0)
                cur = (cur%b)*10;
            else
                cur %= b;
        }
    }

    if (c.size() == 0)
        c.push_back(0);
    else
        reverse(c.begin(), c.end());
    return c;
}

vector<int> sum(vector<int> a, vector<int> b){
    int len = std::max(a.size(), b.size()) + 1;
    while (b.size() < len)
        b.push_back(0);
    for (int i = 0; i < len; i++) {
        b[i] += (i < a.size() ? a[i] : 0);
        b[i+1] += b[i] / 10;
        b[i] %= 10;
    }
    while (b.size() > 0 && b.back() == 0) {
        len--;
        b.pop_back();
    }
    return b;
}


void print(vector<int> n){
    bool flag = false;
    while(!n.empty()) {
        if (flag || n.back() != 0 || n.size() == 1) {
            cout << n.back();
            flag = true;
        }
        n.pop_back();
    }
}

vector<int> cnk(int n, int k) {
    if ((k == n) || (k == 0)) {
        return to_vec("1");
    }
    if (k == 1){
        return to_vec(to_string(n));
    }
    else
        return divs(mul(cnk(n-1, k-1), n), k);
}

int main2()
{
    int n0, k0;
    cin >> n0 >> k0;
    // vector<int> n = to_vec(to_string(n0));
    // vector<int> k = to_vec(to_string(k0));
    // print(divs(n, k0));
    // const int mn = n0 + 1;
    // vector<int> n = to_vec(to_string(n0));
    // vector<int> k = to_vec(to_string(k0));
    // vector<int> ** cnk;
    // for (int i = 0; i < mn; i++) {
    //     cnk[i] = new vector<int>[mn];
    // }
    // for (int i = 0; i < mn; ++i) {
    //   cnk[i][0] = to_vec("1");
    //   cnk[i][i] = to_vec("1");
    //   for (int j = 1; j < i; ++j) {
    //       cnk[i][j] = sum(cnk[i-1][j], cnk[i-1][j-1]);
    //   }
    // }

    // print(cnk[n0][k0]);

    auto res = cnk(n0, k0);
    print(res);
    return 0;
}