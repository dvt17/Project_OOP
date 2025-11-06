#pragma once 
#include <iostream>
#include <string>
#include "SanPham.h"
using namespace std;
class CartItem: public SanPham {
    friend class Order;
    private: 
        int quantity;
    public:
        CartItem (string ma, string ten, string dm, double g, double t, int quan = 0) : SanPham(ma, ten, dm, g, t), quantity(quan){}
        friend istream& operator>> (istream& in, CartItem& c);
        friend ostream& operator<< (istream& out, CartItem& c);
        int getQuantity() const { return quantity;}
        void setQuantity(int qty) { quantity = qty;}
        double calculateSubTotal(){return getGia() * quantity;}
        void displayInfo(){
            cout << "Ten san pham: " << getTen() << endl;
            cout << "So luong san pham: " << quantity << endl;
            cout << "Thanh tien: " << calculateSubTotal << endl;
        }
        ~CartItem();
        
};
