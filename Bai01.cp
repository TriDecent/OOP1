#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
  int r;
  while (b)
  {
      r = a%b;
      a=b;
      b=r;
  }
  return a;
}
struct PhanSo
{
    int iTuSo;
    int iMauSo;
};

void NhapPS(PhanSo &x)
{
    cout << "Hay nhap phan so" << endl;
    cout << "Nhap tu so: ";
    cin >> x.iTuSo;
    cout << "Nhap mau so: ";
    cin >> x.iMauSo;
    while (x.iMauSo == 0)
    {
        cout << "Phan so khong hop le, hay nhap lai: ";
        cin >> x.iMauSo;
    }
}

void RutGonPS(PhanSo &x)
{
    int ucln = gcd(x.iTuSo, x.iMauSo);
     x.iTuSo = x.iTuSo/ucln;
     x.iMauSo = x.iMauSo/ucln;

    if (x.iMauSo < 0 && x.iTuSo > 0)
    {
        x.iTuSo = -x.iTuSo;
        x.iMauSo = -x.iMauSo;
    }
}
void XuatPS(PhanSo x)
{
    if (x.iMauSo == 1)
         cout << x.iTuSo;
    else
         cout << x.iTuSo << "/" << x.iMauSo;
}
int main()
{
    PhanSo x;
    NhapPS(x);
    RutGonPS(x);
    cout << "Phan so duoc rut gon thanh: ";
    XuatPS(x);
    return 0;
}
