#include <bits/stdc++.h>

using namespace std;

class PHANSO {
private:
    int Tu;
    int Mau;
public:
    // Constructor mặc định
    PHANSO() : Tu(0), Mau(1) {}

    // Constructor với 2 tham số
    PHANSO(int tu, int mau) : Tu(tu), Mau(mau) {}

    // Toán tử cộng hai phân số
    PHANSO operator + (const PHANSO other) const;

    // Toán tử cộng số nguyên với phân số (dạng friend)
    friend PHANSO operator + (int value, const PHANSO& ps);

    // Toán tử giảm đơn vị (tiền tố)
    PHANSO& operator -- ();

    // Toán tử giảm đơn vị (hậu tố)
    PHANSO operator -- (int);

    // Toán tử nhập xuất
    friend ostream & operator << (ostream& os, PHANSO& ps);
    friend istream & operator >> (istream& is, PHANSO& ps);

};

PHANSO PHANSO :: operator + (const PHANSO other) const {
    return PHANSO(Mau * other.Tu + Tu * other.Mau, Mau * other.Mau);
}

PHANSO operator + (int value, const PHANSO& ps) {
    return PHANSO(ps.Tu + value * ps.Mau, ps.Mau);
}

PHANSO& PHANSO :: operator -- () {
    Tu -= 1; // Giảm tử số đi 1
    return *this;
}

PHANSO PHANSO::operator -- (int) {
    PHANSO temp = *this; // Lưu giá trị hiện tại
    Tu -= 1;             // Giảm tử số đi 1
    return temp;         // Trả về giá trị trước khi giảm
}

ostream & operator << (ostream & os, PHANSO & Cur) {
    os << Cur.Tu << "/" << Cur.Mau;
    return os;
}

istream & operator >> (istream & is, PHANSO & Cur) {
    is >> Cur.Tu; is >> Cur.Mau;
    return is;
}

int main() {
    PHANSO ps1, ps2(-2, 3), ps3;
    cin >> ps1;
    ps3 = 5 + ps1 + ps2--;
    cout << "ps1 = " << ps1 << endl << "ps2 = " << ps2 << endl << "ps3 = " << ps3 << endl;
    return 0;
}

