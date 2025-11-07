#pragma once
#include <iostream>
#include <iomanip>
#include "MucGioHang.h"
#include <map>
#include "SanPham.h" 

class GioHang : public mucTrongGioHang {
private:
    // int soLuongHienTai; 
    map<SanPham*, int> dsSanPham;

    // int timViTri(const SanPham& sanPham) {
    //     for (int i=0; i<soLuongHienTai; i++) {
    //         if (danhMuc[i].getSanPham().getMaSP() == sanPham.getMaSP()) {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
public:
    GioHang(string ma, string ten, string dm, double g, double t, int quan = 0)
        : mucTrongGioHang(ma,ten,dm,g,t,quan){}
    void themSanPham(SanPham* sp, int soLuong) {
        if (dsSanPham.count(sp)) {
            dsSanPham[sp] += soLuong;
            std::cout << "==> Cap nhat so luong " << sp->getTen() << " thanh " << dsSanPham[sp] << std::endl;
        } else {
            dsSanPham[sp] = soLuong;
            std::cout << "==> Da them " << soLuong << " " << sp->getTen() << " vao gio hang." << std::endl;
        }
    }

    void xemGioHang() const {
        std::cout << "--- GIO HANG CUA BAN ---\n";
        if (dsSanPham.empty()) {
            std::cout << "Gio hang dang trong!\n";
            return;
        }

        int i = 1;
        double tongTien = 0;
        for (const auto& cap : dsSanPham) {
            SanPham* sp = cap.first;
            int soLuong = cap.second;
            double thanhTien = sp->getGia() * soLuong; 
            std::cout << i++ << ". ";
            sp;
            std::cout << "     So luong: " << soLuong << " | Thanh tien: " << fixed << setprecision(0) << thanhTien << " VND" << std::endl;
            tongTien += thanhTien;
        }
        cout << "-----------------------------------\n";
        cout << "==> TONG CONG: " << fixed << setprecision(0) << tongTien << " VND" << std::endl;
    }

    double tinhTongTien() const {
        double tongTien = 0;
        for (const auto& cap : dsSanPham) {
            // Dùng getter: cap.first->getDonGia()
            tongTien += cap.first->getGia() * cap.second;
        }
        return tongTien;
    }

    bool isEmpty() const {
        return dsSanPham.empty();
    }

    // Getter (dùng cho lớp DonHang)
    const std::map<SanPham*, int>& getDsSanPham() const {
        return dsSanPham;
    }
        

    // void addItem(const SanPham& sanPham, int quantity) {
    //     for(int i = 0; i < m.size(); i++){
    //         m.push_back(getTen());
    //     }
        
        // int viTri= timViTri(sanPham); 
        // if (viTri != -1) {
        //     int soLuongCu = danhMuc[viTri].getSoLuong();
        //     danhMuc[viTri].setSoLuong(soLuongCu + quantity);
        //     std::cout << "Cap nhat so luong cho " << sanPham.getTenSP() << std::endl;
        // } else {
        //     if (soLuongHienTai >= MAX_ITEMS) {
        //         std::cout << "Gio hang da day!" << std::endl;
        //         return;
        //     }
        //     danhMuc[soLuongHienTai] = MucGioHang(sanPham, quantity);
        //     soLuongHienTai++;
        //     std::cout << "Da them " << sanPham.getTenSP() << " vao gio hang" << std::endl;
        // 

    // void removeItem(const SanPham& sanPham) {
    //     int viTri = timViTri(sanPham);
    //     if (viTri != -1) {
    //         for (int i=viTri; i<soLuongHienTai - 1; i++) {
    //             danhMuc[i] = danhMuc[i + 1];
    //         }
    //         soLuongHienTai--; 
    //         std::cout << "Da xoa " << sanPham.getTenSP() << " khoi gio hang" << std::endl;
    //     } else {
    //         std::cout << "Khong tim thay " << sanPham.getTenSP() << " trong gio hang" << std::endl;
    //     }
    // }

    // void updateQuantity(const SanPham& sanPham, int newQuantity) {
    //     int viTri = timViTri(sanPham);

    //     if (viTri != -1) {
    //         if (newQuantity > 0) {
    //             danhMuc[viTri].setSoLuong(newQuantity);
    //             std::cout << "Cap nhat so luong " << sanPham.getTenSP() << " thanh " << newQuantity << std::endl;
    //         } else {
    //             removeItem(sanPham);
    //         }
    //     } else {
    //         std::cout << "Khong tim thay " << sanPham.getTenSP() << " trong gio" << std::endl;
    //     }
    // }

    // double tinhTongTien() {
    //     double total = 0.0;
    //     for (int i=0; i<soLuongHienTai; i++) {
    //         total += danhMuc[i].tinhThanhTien();
    //     }
    //     return total;
    // }

    // void hienThiGioHang() {
    //     std::cout << "\n GIO HANG CUA BAN \n";
    //     if (soLuongHienTai == 0) {
    //         std::cout << "Gio hang dang trong!\n" << std::endl;
    //         return;
    //     }

    //     std::cout << std::left
    //               << std::setw(10) << "Ma SP"
    //               << std::setw(20) << "Ten San Pham"
    //               << std::setw(10) << "So Luong"
    //               << std::setw(15) << "Don Gia"
    //               << std::setw(15) << "Thanh Tien" << std::endl;
    //     for (int i = 0; i < soLuongHienTai; i++) {
    //         danhMuc[i].hienThi();
    //     }

    //     std::cout << std::right << std::setw(55) << "\n TONG CONG: "
    //               << std::fixed << std::setprecision(0)
    //               << tinhTongTien() << " VND\n" << std::endl;
    // }

    // void xoaTatCa() {
    //     soLuongHienTai = 0;
    //     std::cout << "> Da xoa toan bo gio hang." << std::endl;
    // }

    // bool kiemTraRong() const {
    //     return (soLuongHienTai == 0);
    // }
};