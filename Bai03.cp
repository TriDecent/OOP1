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
    PhanSo(int iTuSo = 0, int iMauSo = 1)
    {
        this->iTuSo = iTuSo;
        this->iMauSo = iMauSo;
    }
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

PhanSo RutGonPS(PhanSo x)
{
    int ucln = gcd(x.iTuSo, x.iMauSo);
    x.iTuSo = x.iTuSo/ucln;
    x.iMauSo = x.iMauSo/ucln;

    if (x.iMauSo < 0 && x.iTuSo > 0)
    {
        x.iTuSo = -x.iTuSo;
        x.iMauSo = -x.iMauSo;
    }
    return x;
}
void XuatPS(PhanSo x)
{
    int ucln = gcd(x.iTuSo, x.iMauSo);
    if (x.iMauSo == 1)
        cout << x.iTuSo << endl;
    else
        cout << x.iTuSo << "/" << x.iMauSo << endl;

}
PhanSo Addition(PhanSo x, PhanSo y)
{
    PhanSo Result;
    Result.iTuSo = x.iTuSo*y.iMauSo + y.iTuSo*x.iMauSo;
    Result.iMauSo = x.iMauSo*y.iMauSo;
    return Result;
}
PhanSo Substraction(PhanSo x, PhanSo y)
{
    PhanSo Result;
    Result.iTuSo = x.iTuSo*y.iMauSo - y.iTuSo*x.iMauSo;
    Result.iMauSo = x.iMauSo*y.iMauSo;
    return Result;
}
PhanSo Multiplication(PhanSo x, PhanSo y)
{
    PhanSo Result;
    Result.iTuSo = x.iTuSo*y.iTuSo;
    Result.iMauSo = x.iMauSo*y.iMauSo;
    return Result;
}
PhanSo Division(PhanSo x, PhanSo y)
{
    PhanSo Result;
    Result.iTuSo = x.iTuSo*y.iMauSo;
    Result.iMauSo = x.iMauSo*y.iTuSo;
    return Result;
}
int main()
{
    PhanSo x,y;
    cout << "Nhap phan so thu nhat" << endl;
    NhapPS(x);
    cout << endl;
    cout << "Nhap phan so thu hai" << endl;
    NhapPS(y);
    cout << "Phep cong hai phan so: ";
    XuatPS(RutGonPS(Addition(x,y)));
    cout << "Phep tru hai phan so: ";
    XuatPS(RutGonPS(Substraction(x,y)));
    cout << "Phep nhan hai phan so: ";
    XuatPS(RutGonPS(Multiplication(x,y)));
    cout << "Phep chia hai phan so (neu phan so thu hai bang khong phep chia se khong duoc thuc hien): ";
    XuatPS(RutGonPS(Division(x,y)));
    return 0;
}
