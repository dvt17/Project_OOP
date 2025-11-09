#pragma once
#include "DonHang.h"
#include <iostream>

class QuanLyDonHang {
private:
    int soLuongHienTai;
public:
    QuanLyDonHang() {
        soLuongHienTai = 0;
    }
    void themDonHang(const DonHang& donHang) {
        if (soLuongHienTai < 100) {
            danhSachDonHang[soLuongHienTai] = donHang;
            soLuongHienTai++; 
            cout << "Da luu don hang " << donHang.getMaDonHang() << " vao he thong" << std::endl;
        } else {
            cout << "He thong da day, khong the luu them don hang!" << std::endl;
        }
    }

    void hienThiTatCaDonHang() const {
        cout << "\n DANH SACH DON HANG DA DAT \n";
        if (soLuongHienTai == 0) {
            cout << "Chua co don hang nao trong he thong\n" << std::endl;
            return;
        }
        for (int i = 0; i < soLuongHienTai; i++) {
            danhSachDonHang[i].hienThiDonHang();
        }
    }
};