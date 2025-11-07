#include <iostream>
#include <vector>
#include <string>
#include "SanPham.h"
#include "KhachHang.h"
#include "GioHang.h"
using namespace std;
class UngDung {
private:
     vector<SanPham> dsSanPham; // Yêu cầu: Sử dụng STL
    GioHang gioHangHienTai;
    KhachHang khachHangHienTai;

    // --- Các phương thức private (logic nội bộ) ---

    // Yêu cầu 1: Load dữ liệu từ file
    void loadSanPhamTuFile(const  string& tenFile) {
         ifstream file(tenFile);
        if (!file.is_open()) {
             cerr << "Loi: Khong mo duoc file " << tenFile <<  endl;
            return;
        }

         string line;
        while ( getline(file, line)) {
             stringstream ss(line);
             string ma, ten, giaStr;
            
             getline(ss, ma, ',');
             getline(ss, ten, ',');
             getline(ss, giaStr, ',');

            // Dùng constructor public của SanPham để tạo
            dsSanPham.push_back(SanPham(ma, ten,  stod(giaStr)));
        }
        file.close();
         cout << "Da load thanh cong " << dsSanPham.size() << " san pham.\n";
    }

    // Yêu cầu 2: Hiển thị danh sách sản phẩm
    void hienThiDanhSachSanPham() const {
         cout << "\n--- DANH SACH SAN PHAM ---\n";
        for (size_t i = 0; i < dsSanPham.size(); ++i) {
             cout << "  " << (i + 1) << ". ";
            dsSanPham[i].hienThi(); // Dùng hàm public hienThi()
        }
         cout << "----------------------------\n";
    }

    // Yêu cầu 3: Lựa chọn sản phẩm
    void chonSanPham() {
        int luaChon = -1;
        int soLuong = 0;

        while (true) {
            hienThiDanhSachSanPham();
             cout << "Nhap STT san pham de them vao gio (nhap 0 de thoat): ";
             cin >> luaChon;

            if (luaChon == 0) {
                break;
            }

            if (luaChon < 1 || luaChon > dsSanPham.size()) {
                 cout << "Lua chon khong hop le. Vui long chon lai.\n";
                continue;
            }

             cout << "Nhap so luong: ";
             cin >> soLuong;

            if (soLuong <= 0) {
                 cout << "So luong phai lon hon 0.\n";
                continue;
            }
            
            // Lấy con trỏ tới sản phẩm trong vector
            SanPham* spChon = &dsSanPham[luaChon - 1];
            // Dùng hàm public của GioHang
            gioHangHienTai.themSanPham(spChon, soLuong);
        }
    }

    // Yêu cầu 5: Đặt hàng (nhập thông tin)
    void datHang() {
        // Dùng hàm public của GioHang
        if (gioHangHienTai.isEmpty()) { 
             cout << "Gio hang cua ban dang trong. Vui long them san pham truoc.\n";
            return;
        }
        
        // Dùng hàm public của KhachHang
        khachHangHienTai.nhapThongTin(); 

        // Yêu cầu 6: Hiển thị và xác nhận đơn hàng
        // Truyền các đối tượng private vào constructor của DonHang
        DonHang donHangMoi(khachHangHienTai, gioHangHienTai);
        
        donHangMoi.hienThiXacNhan(); // Dùng hàm public
        
        // Reset giỏ hàng sau khi đặt thành công
        gioHangHienTai = GioHang(); // Tạo một giỏ hàng mới (rỗng)
         cout << "Dat hang thanh cong! Gio hang cua ban da duoc reset.\n";
    }

public:
    // Constructor của UngDung, gọi hàm load file
    UngDung() {
        loadSanPhamTuFile("sanpham.txt");
    }

    // Hàm chạy chính của ứng dụng (public)
    void run() {
        int luaChon = -1;
        while (luaChon != 0) {
             cout << "\n--- UNG DUNG DAT HANG ---\n";
             cout << "1. Xem danh sach san pham\n";
             cout << "2. Them san pham vao gio hang\n";
             cout << "3. Xem gio hang\n";
             cout << "4. Tien hanh dat hang\n";
             cout << "0. Thoat\n";
             cout << "Nhap lua chon cua ban: ";
             cin >> luaChon;

            switch (luaChon) {
            case 1:
                hienThiDanhSachSanPham();
                break;
            case 2:
                chonSanPham();
                break;
            case 3:
                // Yêu cầu 4: Xem giỏ hàng
                gioHangHienTai.xemGioHang(); // Dùng hàm public
                break;
            case 4:
                // Yêu cầu 5 & 6
                datHang();
                break;
            case 0:
                 cout << "Cam on ban da su dung ung dung!\n";
                break;
            default:
                 cout << "Lua chon khong hop le!\n";
            }
        }
    }
};