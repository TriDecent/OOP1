#include <bits/stdc++.h>

using namespace std;

struct sCalendar
{
    int iDay, iMonth, iYear;
    sCalendar(int iDay = 1, int iMonth = 1, int iYear = 1);
    void NhapNgay();
    void XuatNgay();
    int NgayMaxTrongThangDo();
    void TimNgayKeTiep();
};

sCalendar::sCalendar(int iDay, int iMonth, int iYear)
{
    this->iDay = iDay;
    this->iMonth = iMonth;
    this->iYear = iYear;
}

int sCalendar::NgayMaxTrongThangDo()
{
    if (iMonth == 4 || iMonth == 6 || iMonth == 9 || iMonth == 11)
        return 30;
    else if (iMonth == 2)
    {
        if ((iYear % 4 == 0 && iYear % 100 != 0) || (iYear % 400 == 0))
           return 29;
        else
            return 28;
    }
    else return 31;
}
void sCalendar::NhapNgay()
{
   cout << "Nhap ngay: ";
   cin >> iDay;
   while (iDay > 31 || iDay < 1)
   {
       cout << "Ngay nhap khong hop le, hay nhap lai: ";
       cin >> iDay;
   }

   cout << "Nhap thang: ";
   cin >> iMonth;
   while (iMonth > 12 || iMonth < 1)
   {
       cout << "Thang nhap khong hop le, hay nhap lai: ";
       cin >> iMonth;
   }

   cout << "Nhap nam: ";
   cin >> iYear;
   while (iYear < 1)
   {
       cout << "Nam nhap khong hop le, hay nhap lai: ";
       cin >> iYear;
   }
   while (iDay > NgayMaxTrongThangDo())
   {
       cout << "Thang va nam ban vua nhap khien cho ngay khong hop le, hay nhap lai ngay hoac nhan -1 de nhap lai toan bo: ";
       cin >> iDay;
       if (iDay = -1) NhapNgay();
   }
}
void sCalendar::XuatNgay()
{
    cout << iDay << "/" << iMonth << "/" << iYear;
}
void sCalendar::TimNgayKeTiep()
{
    ++iDay;
    if (iDay > NgayMaxTrongThangDo())
    {
        iDay = 1;
        ++iMonth;
        if (iMonth > 12)
        {
            iMonth = 1;
            ++iYear;
        }
    }
}
int main()
{
    sCalendar NgayNhap, NgayKeTiep;
    NgayNhap.NhapNgay();
    NgayNhap.TimNgayKeTiep();
    NgayKeTiep = NgayNhap;
    cout << "Ngay ke tiep la: ";
    NgayKeTiep.XuatNgay();
}
