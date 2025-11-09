#pragma once
#include <iostream>
#include <iomanip>
#include "MucGioHang.h"
#include <map>
#include "SanPham.h" 
#include <vector>
using namespace std;

//extern vector<SanPham> ds;
int n = 0;
class GioHang {

private:
    map<string, mucTrongGioHang> dsMuc; // Danh sách các mục trong giỏ hàng

public:
    GioHang() {}

    // Thêm 1 mục vào giỏ hàng

    void themMuc(mucTrongGioHang m) {
            for(auto& x : dsMuc){
                if(m.getTen() == x.first){
                    n += m.getSoLuong();
                    m.setSoLuong(n);
                    dsMuc[m.getTen()] = m;
                }
                else {
                    n = 0;
                    n += m.getSoLuong();
                    m.setSoLuong(n);
                    dsMuc[m.getTen()] = m;
                }
            }
    }

 
    void nhap() {
        int n;
        cout << "Nhap so luong san pham muon mua: ";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cout << "\nSan pham thu " << i + 1 << " ---" << endl;
            mucTrongGioHang m;
            themMuc( m.nhapmuc());
        }
    }

    // Hiển thị toàn bộ giỏ hàng
    void xuat() const {
        cout << "\n===== THONG TIN GIO HANG =====\n";
        for (auto& x : dsMuc) {
            cout << "Ten san pham: " << x.first<< endl;
            cout << "So luong san pham: " << x.second.getSoLuong()<< endl;
            cout << "Thanh tien: " << x.second.tinhTong(x.second.getTen()) << endl;
        
            cout << "--------------------------\n";
        }
        cout << "Tong tien cua gio hang: " << tinhTongTien() << endl;
    }

    // Tính tổng tiền toàn bộ giỏ hàng
    int tinhTongTien() const {
        int tong = 0;
        for (auto& x : dsMuc) {
            tong += x.second.getSoLuong() * x.second.getGia(); // Hoặc m.tinhTong()
        }
        return tong;
    }

    // Xóa một sản phẩm theo tên
    void xoaMuc(const string& ten) {
        for (auto it = dsMuc.begin(); it != dsMuc.end(); ++it) {
            if ((*it).second.getTen() == ten) {
                dsMuc.erase(it);
                cout << "Da xoa san pham: " << ten << endl;
                return;
            }
        }
        cout << "Khong tim thay san pham: " << ten << endl;
    }


/*private:
    // int soLuongHienTai; 
    map<string, int> dsSanPham;
    int count = 0;
    mucTrongGioHang m;

   
public:
    GioHang(mucTrongGioHang _m)
    
    {
        m = _m;
        if(dsSanPham.empty()) {
            dsSanPham.insert({m.getTen(),m.getSoLuong()});
        
        }
        else{
           for(auto i = dsSanPham.begin();i != dsSanPham.end();i++){
                if(i->first == m.getTen() ){
                    i->second += m.getSoLuong();
                }
                else {
                    dsSanPham.insert({m.getTen(),m.getSoLuong()});
                }
            }
        
        
         }
    }
    int tinhTien() const {
        int tinhtien = 0;
        for(auto i = dsSanPham.begin();i != dsSanPham.end();i++){
            for(auto x : ds){
                if(i->first == x.getTen()){
                    tinhtien = x.getGia() * i->second;
                }
            }
            
        }
        return tinhtien;

    }

    void xemGioHang() const {
        cout << "--- GIO HANG CUA BAN ---\n";
        if (dsSanPham.empty()) {
            cout << "Gio hang dang trong!\n";
            return;
        }
        for(auto i = dsSanPham.begin(); i!=dsSanPham.end();i++){
            cout << i->first <<" "<< i->second<<endl;

        }
        cout << "-----------------------------------\n";
        cout << "==> TONG CONG: "  << tinhTien() << " VND" << std::endl;
    }


    bool isEmpty() const {
        return dsSanPham.empty();
    }

    // Getter (dùng cho lớp DonHang)
    // const map<SanPham*, int>& getDsSanPham() const {
    //     return dsSanPham;
    // }
*/ 
};