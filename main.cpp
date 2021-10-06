#include <windows.h>
#include <iostream>

using namespace std;

void doMagic(int n) {
    int m_multiplicity = 1; int m_del = 1;
    int i;
    int border = n;
    bool has_dels_out = false;

    cout << n << " = ";

    for (i = 2; i <= border; i++) {
        int current_multiplicity = 0;

        while (n%i == 0) {
            if (has_dels_out)
                cout << " * " << i;
            else
                cout << i;

            has_dels_out = true;
            current_multiplicity++;
            n /= i;
        }

        if (current_multiplicity > m_multiplicity){
            m_multiplicity = current_multiplicity;
            m_del = i;
        }
    }

    if (border == 1) cout << 1;
    cout << endl << "У искомого делителя " << m_del << " степень " << m_multiplicity << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n = 0;
    while (n != -1) {
        cin >> n;
        doMagic(n);
    }

    return 0;
}