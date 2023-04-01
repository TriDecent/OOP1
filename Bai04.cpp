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

void NhapPS(PhanSo &p)
{
    cout << "Nhap tu so: ";
    cin >> p.iTuSo;
    cout << "Nhap mau so: ";
    cin >> p.iMauSo;
    while (p.iMauSo == 0)
    {
        cout << "Phan so khong hop le, hay nhap lai: ";
        cin >> p.iMauSo;
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
bool SoSanhPS(PhanSo a, PhanSo b)
{
    return a.iTuSo/a.iMauSo < b.iTuSo/b.iMauSo;
}
void XuatPS(PhanSo x)
{
   int ucln = gcd(x.iTuSo, x.iMauSo);
    if (x.iMauSo)
    {
        if (x.iMauSo == ucln)
             cout << x.iTuSo/ucln << " ";
        else
             cout <<  x.iTuSo << "/" << x.iMauSo << " ";
    }
}
PhanSo TimPhanSoMax(PhanSo a[], int n)
{
    PhanSo kq = *max_element(a, a+n, SoSanhPS);
    return kq;
}
void SapXepPhanSoTangDan(PhanSo a[], int n)
{
    sort(a,a+n,SoSanhPS);
}
int main()
{
   int n;
   cin >> n;
   PhanSo *a = new PhanSo[n];
   for(int i = 0; i < n; ++i)
   {
       NhapPS(a[i]);
       RutGonPS(a[i]);
   }
   XuatPS(TimPhanSoMax(a,n));
   SapXepPhanSoTangDan(a,n);
   for(int i = 0; i < n; ++i)
   {
       XuatPS(a[i]);
   }

   delete []a;
}
