#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

void bitwise_sieve(int N) {
    int n = N >> 5, k = 0;
    int* ar = new int[n + 1];

    for (int i = 0; i <= n; ++i) ar[i] = 0xffff; // 65535

    for (int i = 2; i <= N; i++) {
        if (ar[i >> 5] & (0x8000 >> (i & 31))) { // 32768
            cout << i << " ";

            for (int j= (i << 1); j <= N; j += i) ar[j >> 5] &= ~0x8000 >> (j & 31);
        }
    }

    cout << endl;
}

vector<int> sieve(int n) {
    int i = 2;
    vector<int> num, ans;
    for (int i = 0; i <= n; i++)
        num.push_back(i);
    num.at(1) = 0;
    int root = ceil(sqrt(n));
    for (int i = 0; i <= root; i++) {
        if (num[i] != 0) {
            for (int j = 2 * i; j <= n; j += i)
                num[j] = 0;
        }
    }
    for (auto i : num)
        if (i != 0)
            ans.push_back(i);

    return ans;
}

bool is_good(string sep){
    int n = sep.length();
    for(int i = 0; i < n/2; ++i)
    {
        if(sep[i] != sep[n-i-1])
            return false;
    }

    return true;
}

int main()
{
    int k, n;
    cin >> k >> n;
    auto res_k = sieve(k);
    auto res_n = sieve(n);
    vector<int> res;
    if (res_k.at(res_k.size() - 1) == k)
        res = { k };
    int size = res.size();
    std::set_difference(res_n.begin(), res_n.end(), res_k.begin(), res_k.end(), std::inserter(res, res.begin() + size));
    int flag = 0;
    for (auto i : res) {
        if (is_good(to_string(i))) {
            cout << i << " ";
            flag = 1;
        }
    }
    if (flag == 0)
        cout << 0;
    return 0;
}
