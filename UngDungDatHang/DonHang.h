#pragma once
#include <string>
#include <ctime>
#include <vector>
#include <iostream>
#include "GioHang.h"
#include "SanPham.h"
#include "DiaChi.h"
#include "TroChoi.h"
using namespace std;
class DonHang : public GioHang
{
private:
    tm ngayDatHang;
    time_t od;
    tm duTinhNgayGiaoHang;
    DiaChi diaChi;
    double phiShip;
    double tongDonHang;
    string trangThai;

public:
    DonHang(DiaChi d)
    {
        od = time(0);
        localtime_s(&ngayDatHang, &od);
        diaChi = d;
    }
    friend ostream &operator<<(ostream &out, const DonHang &d)
    {

        out << "Ngay bat dau: " << d.ngayDatHang.tm_mday << '/' << d.ngayDatHang.tm_mon + 1 << '/' << d.ngayDatHang.tm_year + 1900 << endl;
        out << "Ngay du kien: " << d.duTinhNgayGiaoHang.tm_mday << '/' << d.duTinhNgayGiaoHang.tm_mon + 1 << '/' << d.duTinhNgayGiaoHang.tm_year + 1900 << endl;
        return out;
    }
    void ngayUocTinh()
    {
        if (diaChi.getTP() == "HOCHIMINH")
        {
            time_t tg = od + 48 * 3600;
            localtime_s(&duTinhNgayGiaoHang, &tg);
        }
        else
        {
            time_t tg = od + 96 * 3600;
            localtime_s(&duTinhNgayGiaoHang, &tg);
        }
    }
    double tinhPhiShip()
    {

        if (diaChi.getTP() == "HOCHIMINH")
        {
            phiShip = 0;
        }
        else
        {
            phiShip = 0.1;
        }
        return phiShip;
    }

    tm getNgayDH() const
    {
        return ngayDatHang;
    }
    tm getNgayDT() const
    {
        return duTinhNgayGiaoHang;
    }
};
