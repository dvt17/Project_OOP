#pragma once
#include <iostream>
using namespace std;

class DanhGia {
private:
    string  MaDanhGia;
    int MaSanPham;
    float Diem;
    string BinhLuan;
    int DanhGiaTichCuc;
    int DanhGiaTieuCuc;
public:
    DanhGia(string MaDG = " ", int MaSP = 1, string binhluan = " ")
        : MaDanhGia(MaDG), MaSanPham(MaSP), BinhLuan(binhluan){

    }
    float getDiem() const {
        return Diem;
    }
    string getBinhLuan() const {
        return BinhLuan;
    }
    void setDiem(float d) {
        if(d > 0) Diem = d;
        else Diem = 1;   
    }
    void setBinhLuan(string b){
        BinhLuan = b;
    }

    // void TichCuc(){
    //     if(Diem >= 2.5 )
    //         DanhGiaTichCuc++;
    // }
    // void TieuCuc(){
    //     if(Diem < 2.5)
    //         DanhGiaTieuCuc++;
    // }

    void displayy() {
        cout << "Đánh giá #" << MaDanhGia << " -Mã sản phẩm " << MaSanPham<< endl;
        cout << "Người dùng: " << userID << " | Điểm: " << Diem << "/5 sao\n";
        cout << "Bình luận: " << BinhLuan << endl;
        // cout << "Ngày: " << reviewDate << " | Thích: " << likes
        //      << " | Không thích: " << dislikes << endl;

    }
};
