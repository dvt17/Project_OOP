#pragma once
#include <iostream>
#include <string>
using namespace std;

class DanhGia {
private:
    string maDanhGia;
    string maKhachHang;
    string maSanPham;   
    float diem; 
    string binhLuan;   
public:
    DanhGia(string maDG = "", string maKH = "", string maSP = "", float d = 0, string bl = "")
        : maDanhGia(maDG), maKhachHang(maKH), maSanPham(maSP), diem(d), binhLuan(bl) {}

    string getMaDanhGia() const { return maDanhGia; }
    string getMaKhachHang() const { return maKhachHang; }
    string getMaSanPham() const { return maSanPham; }
    float getDiem() const { return diem; }
    string getBinhLuan() const { return binhLuan; }

    void setDiem(float d) {
        if(d >= 1 && d <= 5) diem = d;
        else diem = 1;   
    }
    void setBinhLuan(string b){
        binhLuan = b;
    }

    void display() const {
        cout << "\n Danh Gia " << maDanhGia << endl;
        cout << "Nguoi dung (Ma KH): " << maKhachHang << endl;
        cout << "San pham (Ma SP): " << maSanPham << endl;
        cout << "Diem: " << diem << "/5 sao" << endl;
        cout << "Binh luan: " << binhLuan << endl;
    }
};