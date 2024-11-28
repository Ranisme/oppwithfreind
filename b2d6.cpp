#include <bits/stdc++.h>

using namespace std;

class PhanSo {
private:
    int Tu;
    int Mau;
public:
    // Constructor mặc định
    PhanSo() : Tu(0), Mau(1) {}

    // Constructor với 2 tham số
    PhanSo(int tu, int mau) : Tu(tu), Mau(mau) {}

    // Constructor với 1 tham số (mẫu mặc định = 1)
    PhanSo(int tu) : Tu(tu), Mau(1) {}

    // Toán tử cộng
    PhanSo operator + (const PhanSo other) const;

    // Hàm xuất
    void Xuat() ;
};

PhanSo PhanSo :: operator + (const PhanSo other) const {
    return PhanSo(Mau * other.Tu + Tu * other.Mau, Mau * other.Mau);
}

void PhanSo :: Xuat() {
    cout << Tu << "/" << Mau;
}

int main() {
    PhanSo a;           // tử: 0; mẫu: 1
    PhanSo b(1, 2);     // tử: 1; mẫu: 2
    PhanSo c(3);        // tử: 3; mẫu: 1
    a = b + c;
    a.Xuat();           // Kết quả sẽ là 7/2
    return 0;
}
