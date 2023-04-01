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
    cout << endl;
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
bool SoSanhPS1(PhanSo a, PhanSo b)
{
    return a.iTuSo*b.iMauSo < b.iTuSo*a.iMauSo; //ban dau nhap a.iTuSo/a.iMauSo < b.iTuSo/b.iMauSo loi truong hop khi xuat hien phan so 0
}
bool SoSanhPS2(PhanSo a, PhanSo b)
{
    return a.iTuSo*b.iMauSo > b.iTuSo*a.iMauSo;
}
void XuatPS(PhanSo x)
{
   int ucln = gcd(x.iTuSo, x.iMauSo);
    if (x.iMauSo)
    {
        if (x.iMauSo == ucln)
             cout << x.iTuSo << " ";
        else
             cout <<  x.iTuSo << "/" << x.iMauSo << " ";
    }
}
PhanSo TimPhanSoMax(PhanSo a[], int n)
{
    PhanSo kq = *max_element(a, a+n, SoSanhPS1);
    return kq;
}
void SapXepPhanSoTangDan(PhanSo a[], int n)
{
    sort(a,a+n,SoSanhPS1);
}
void SapXepPhanSoGiamDan(PhanSo a[], int n)
{
    sort(a,a+n,SoSanhPS2);
}
int main()
{
   int n;
   cout << "Nhap so luong phan so: ";
   cin >> n;
   cout << endl;

   PhanSo *a = new PhanSo[n];
   for(int i = 0; i < n; ++i)
   {
       cout << "Nhap phan so thu " << i + 1 << endl;
       NhapPS(a[i]);
       RutGonPS(a[i]);
   }
   cout << "Phan so lon nhat tim duoc la: ";
   XuatPS(TimPhanSoMax(a,n));
   cout << endl;

   SapXepPhanSoTangDan(a,n);
   cout << "Phan so sau khi duoc sap xep tang dan: ";
   for(int i = 0; i < n; ++i)
   {
       XuatPS(a[i]);
   }
   cout << endl;

   cout << "Phan so sau khi duoc sap xep giam dan: ";
   SapXepPhanSoGiamDan(a,n);
   for(int i = 0; i < n; ++i)
   {
       XuatPS(a[i]);
   }
   cout << endl;
   delete []a;
}
