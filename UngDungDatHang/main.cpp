#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "DanhGiaSP.h"
#include "SanPham.h"
#include "User.h"
#include "TroChoi.h"
#include "MucGioHang.h"
#include "DocFile.h"
using namespace std;
void DocFile(){
    ifstream file("SanPham.txt");
    vector<SanPham> ds;
    SanPham sp;
    while (file >> sp) {
        ds.push_back(sp);

    }
 
    file.close();
}
void dangKi(){
    string tk, mk;
    
    cout << "Nhap tai khoan: ";
    cin >> tk;
    cout << "Nhap mat khau: ";
    cin >> mk;
    User u(tk, mk);
    u.ghiFile();
    cout << "Dang ky thanh cong!\n";
}

void dangNhap(){
    string tk, mk;
   
    cout << "Nhap tai khoan: ";
    cin >> tk;
    cout << "Nhap mat khau: ";
    cin >> mk;
    User u(tk, mk);
    if (u.dangNhap(tk, mk)) {
        cout << "Dang nhap thanh cong!\n";
    }
    else {
        cout << "Sai tai khoan hoac mat khau!\n";
    }
}

int TinhTien(int n){


}


int main() {
    DocFile();
    string s = "========= MENU =========\n"
        "[1]. Dang ky tai khoan\n"
        "[2]. Dang nhap\n"
        "[3]. Thoat\n"
        "========================\n";
    cout << s << endl;
    int c; bool ok;
    ok = true;
   
    while (ok) {
        cout << "Nhap lua chon: ";
        cin >> c;
        if (c == 1) {
            dangKi();
        }
        else if (c == 2) {
            dangNhap();
            string s = "========= MENU =========\n"
            "[1]. Danh muc san pham\n"
            "[2]. Game\n"
            "[3]. Mua hang\n"
            "========================\n";
            cout << s <<endl;
           
            bool ok2 = true;
            while(ok2){
                char chon; cin >>chon ;
                if(chon == '1'){
                    string dm;
                    cout <<"Chon danh muc san pham(ThucPham, ThucUong, CaNhan, GiaDung): ";
                    cin >> dm;
                    for(auto it : ds ){
                        if(dm == it.getDanhMuc()){
                            cout <<it.getMa()<<" "<<it.getTen()<<" "<<it.getGia()<<endl;
                        } 

                    }

                }
                else if(chon == '2' ){
                    string ten;
                    cin >> ten;
                    TroChoi c(ten);
                    c.BatDau();
                    c.DoiThuong();
                }
                else if(chon == '3'){
                    string tensp;
                    cout <<"Nhap ten san pham muon mua: ";
                    cin >>tensp;
                    
                    int soluong;
                    cout <<"Nhap so luong san pham: ";
                    cin>> soluong;
                    mucTrongGioHang m("",tensp,soluong);
                    m.nhap();
                    m.tinhTong(tensp);
                    m.displayInfo();
                    
                    // m.displayInfo();
                    


                }

            }
        }
        else {
            cout << "Thoat thanh cong";
            ok = false;
        }

    }

    return 0;
}