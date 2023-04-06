#include<bits/stdc++.h>
using namespace std;

class cHocSinh
{
   private:
       string iHoTen;
       float iDiemToan, iDiemVan;
   public:
       cHocSinh(string = "", float iDiemToan = 0, float iDiemVan = 0);
       void NhapHocSinh();
       void XuatHocSinh();
       float TinhDiemTrungBinh();
};
cHocSinh::cHocSinh(string HoTen, float DiemToan, float DiemVan)
{
    this->iHoTen = iHoTen;
    this->iDiemToan = iDiemToan;
    this->iDiemVan = iDiemVan;
}
void cHocSinh::NhapHocSinh()
{
    cout << "Nhap ten hoc sinh: ";
    getline(cin, iHoTen);
    cout << "Nhap diem toan: ";
    cin >> iDiemToan;

    while (iDiemToan > 10 || iDiemToan < 0)
    {
        cout << "Diem nhap khong hop le, hay nhap lai:";
        cin >> iDiemToan;
    }
    cout << "Nhap diem van: ";
    cin >> iDiemVan;
    cout << endl;
     while (iDiemVan > 10 || iDiemVan < 0)
     {
         cout << "Diem nhap khong hop le, hay nhap lai:";
         cin >> iDiemVan;
         cout << endl;
     }
    cin.ignore();
}
void cHocSinh::XuatHocSinh()
{
    cout << "Ten hoc sinh: " << iHoTen << endl;
    cout << "Diem toan: " << iDiemToan << endl;
    cout << "Diem van: " << iDiemVan << endl;
    cout << endl;
}
float cHocSinh::TinhDiemTrungBinh()
{
    return (iDiemToan + iDiemVan)/2;
}
float DiemCaoNhat(cHocSinh a[], int n)
{
    int cnt = 0;
    float maxDTB = a[0].TinhDiemTrungBinh();
    for (int i = 1; i < n; ++i)
        if (a[i].TinhDiemTrungBinh() > maxDTB)
        {
            maxDTB = a[i].TinhDiemTrungBinh();
        }
    return maxDTB;
}
float DiemThapNhat(cHocSinh a[], int n)
{
    int cnt = 0;
    float minDTB = a[0].TinhDiemTrungBinh();
    for (int i = 1; i < n; ++i)
        if (a[i].TinhDiemTrungBinh() < minDTB)
        {
            minDTB = a[i].TinhDiemTrungBinh();
        }
    return minDTB;
}
int SoHSDiemCaoNhat(cHocSinh a[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i].TinhDiemTrungBinh() == DiemCaoNhat(a,n))
        {
            ++cnt;
        }
    }
    return cnt;
}
cHocSinh *DanhSachHSDiemCaoNhat(cHocSinh a[], int n)
{
    int j = 0;
    cHocSinh *Max = new cHocSinh[n];
    for (int i = 0; i < n; ++i)
    {
        if (a[i].TinhDiemTrungBinh() == DiemCaoNhat(a,n))
        {
            Max[j] = a[i];
            ++j;
        }
    }
    return Max;
}
cHocSinh *DanhSachHSDiemThapNhat(cHocSinh a[], int n)
{
    int j = 0;
    cHocSinh *Min = new cHocSinh[n];
    for (int i = 0; i < n; ++i)
    {
        if (a[i].TinhDiemTrungBinh() == DiemThapNhat(a,n))
        {
            Min[j] = a[i];
            ++j;
        }
    }
    return Min;
}
int SoHSDiemThapNhat(cHocSinh a[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i].TinhDiemTrungBinh() == DiemThapNhat(a,n))
        {
            ++cnt;
        }
    }
    return cnt;
}

int main()
{
    int n, cnt;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    cout << endl;
    cin.ignore();
    cHocSinh *arr = new cHocSinh[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "Nhap hoc sinh thu " << i + 1 << ":" << endl;
        arr[i].NhapHocSinh();
    }

    cout << "Thong tin hoc sinh co diem trung binh cao nhat: " << endl;

    cHocSinh *MaxDTB = DanhSachHSDiemCaoNhat(arr, n);
    cHocSinh *MinDTB = DanhSachHSDiemThapNhat(arr, n);
    for (int i = 0; i < SoHSDiemCaoNhat(arr, n); ++i)
    {
        MaxDTB[i].XuatHocSinh();
    }
    delete []MaxDTB;

    cout << "Thong tin hoc sinh co diem trung binh thap nhat: " << endl;
    for (int i = 0; i < SoHSDiemThapNhat(arr, n); ++i)
    {
        MinDTB[i].XuatHocSinh();
    }
    delete []MinDTB;
    delete []arr;

}
