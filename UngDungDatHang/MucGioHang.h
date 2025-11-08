#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include "SanPham.h"
using namespace std;
class mucTrongGioHang : public SanPham{
    //friend class DonHang;
    private:
        int soLuong;
        vector <SanPham> s;
    public:
        mucTrongGioHang (string ma = "",string ten = "",int quan = 0)
             : SanPham(ma,ten), soLuong(quan){}
        // friend istream& operator>> (istream& in, mucTrongGioHang& c){
        //     in >> c.tenSanPham>> c.soLuong;
        //     return in;
        // }
        void nhap(){
            DocFile();
        }
        int getSoLuong() const { return soLuong;}
        void setSoLuong(int qty) { soLuong = qty;}
        int tinhTong(string ten)const {
            
            for(auto x : s){
                
                if(x.getTen() == ten ){

                    return x.getGia() * soLuong;
                }
            }
            return 1;
            
        }

        void displayInfo(){
            cout << "Ten san pham: " << tenSanPham<< endl;
            cout << "So luong san pham: " << soLuong << endl;
            cout << "Thanh tien: " << tinhTong(tenSanPham) << endl;
        }
        // friend ostream& operator<< (ostream& out, mucTrongGioHang& c){
        //     out << "Ten san pham: " << c.tenSanPham << endl;
        //     out << "So luong san pham: " << c.soLuong << endl;
        //     // out << "Thanh tien: " << c.tinhTong() << endl;
        //     return out;
        // }
        ~mucTrongGioHang(){}
        
};
