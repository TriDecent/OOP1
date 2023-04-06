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
        cout << "Mau so khong hop le, hay nhap lai: ";
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
bool isIncreasing(PhanSo a, PhanSo b)
{
     return (a.iTuSo*b.iMauSo) < (b.iTuSo*a.iMauSo);
}
void XuatPS(PhanSo a)
{
    if (a.iMauSo == 1)
         cout << a.iTuSo << " ";
    else
         cout <<  a.iTuSo << "/" << a.iMauSo << " ";
}
int main()
{
    PhanSo PS1, PS2;
    cout << "Nhap phan so thu nhat" << endl;
    NhapPS(PS1);
    cout << endl;
    cout << "Nhap phan so thu hai" << endl;
    NhapPS(PS2);
    isIncreasing(PS1, PS2);
    cout << "Phan so lon nhat la: ";
    if (isIncreasing(PS1, PS2)) XuatPS(PS2);
    else XuatPS(PS1);
    return 0;
}
