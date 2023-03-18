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

    if (x.iMauSo == gcd(x.iTuSo, x.iMauSo))
        x.iTuSo = x.iTuSo/x.iMauSo;
    else
         x.iTuSo = x.iTuSo/ucln;
         x.iMauSo = x.iMauSo/ucln;

    if (x.iMauSo < 0 && x.iTuSo > 0)
    {
        x.iTuSo = -x.iTuSo;
        x.iMauSo = -x.iMauSo;
    }

}
int SoSanhPS(PhanSo a, PhanSo b)
{
    float x=(float)a.iTuSo/a.iMauSo;
    float y=(float)b.iTuSo/b.iMauSo;
    if (x==y) return 0;
    else if (x>y) return 1;
    else return -1;
}
void XuatPS(PhanSo a, PhanSo b)
{
   int kq = SoSanhPS(a, b);
   if (kq == 0)
        cout << "Phan so lon nhat la: " << a.iTuSo << "/" << a.iMauSo;
    else if (kq > 0)
        cout << "Phan so lon nhat la: " << a.iTuSo << "/" << a.iMauSo;
    else
        cout << "Phan so lon nhat la: " << b.iTuSo << "/" << b.iMauSo;
}
int main()
{
    PhanSo PS1, PS2;
    NhapPS(PS1);
    NhapPS(PS2);
    SoSanhPS(PS1, PS2);
    XuatPS(PS1, PS2);
    return 0;
}

