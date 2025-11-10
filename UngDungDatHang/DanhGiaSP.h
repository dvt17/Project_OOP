#pragma once
#include <iostream>
#include <string>
using namespace std;

class DanhGia
{
private:
    float diem;
    string binhLuan;

public:
    DanhGia(float d = 0, string bl = "")
        : diem(d), binhLuan(bl) {}
    friend ostream &operator<<(ostream &out, const DanhGia &d)
    {
        out << d.diem << d.binhLuan;
        return out;
    }
    friend istream &operator>>(istream &in, DanhGia &d)
    {
        in >> d.diem >> d.binhLuan;
        return in;
    }
    float getDiem() const { return diem; }
    string getBinhLuan() const { return binhLuan; }

    void setDiem(float d)
    {
        if (d >= 1 && d <= 5)
            diem = d;
        else
            diem = 1;
    }
    void setBinhLuan(string b)
    {
        binhLuan = b;
    }

    void display() const
    {
        cout << "Diem: " << diem << "/5 sao" << endl;
        cout << "Binh luan: " << binhLuan << endl;
    }
};