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

int main()
{
    cHocSinh a;
    a.NhapHocSinh();
    cout << "Diem trung binh cua hoc sinh la: " << setprecision(2) << fixed << a.TinhDiemTrungBinh();
}
