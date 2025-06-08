#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "SinhVien.h"

using namespace std;

int main() {
    vector<SinhVien*> dsSV;
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nNhap sinh vien thu " << i + 1 << endl;
        cout << "Chon loai sinh vien (1: Cao dang, 2: Dai hoc): ";
        int loai; cin >> loai;
        cin.ignore();

        SinhVien* sv = nullptr;
        if (loai == 1) {
            sv = new SinhVienCaoDang();
        } else if (loai == 2) {
            sv = new SinhVienDaiHoc();
        } else {
            cout << "Loai sinh vien khong hop le.\n";
            i--;
            continue;
        }
        sv->nhap();
        dsSV.push_back(sv);
    }

    cout << "\n--- Danh sach sinh vien ---\n";
    cout << left << setw(12) << "Ma SV"
         << setw(20) << "Ho Ten"
         << setw(20) << "Dia Chi"
         << setw(10) << "Tin Chi"
         << setw(10) << "DTB"
         << setw(15) << "Diem Tot Nghiep/Luan Van"
         << setw(20) << "Ten Luan Van"
         << setw(10) << "Diem LV" << endl;

    for (auto sv : dsSV) {
        sv->xuat();
    }

    cout << "\n--- Sinh vien du dieu kien tot nghiep ---\n";
    for (auto sv : dsSV) {
        if (sv->duDieuKienTotNghiep()) {
            sv->xuat();
        }
    }

    cout << "\n--- Sinh vien khong du dieu kien tot nghiep ---\n";
    for (auto sv : dsSV) {
        if (!sv->duDieuKienTotNghiep()) {
            sv->xuat();
        }
    }

    float maxDiemDH = -1;
    SinhVienDaiHoc* svDHmax = nullptr;
    for (auto sv : dsSV) {
        SinhVienDaiHoc* svdh = dynamic_cast<SinhVienDaiHoc*>(sv);
        if (svdh && svdh->getDiemTrungBinh() > maxDiemDH) {
            maxDiemDH = svdh->getDiemTrungBinh();
            svDHmax = svdh;
        }
    }
    if (svDHmax) {
        cout << "\nSinh vien dai hoc co diem trung binh cao nhat:\n";
        svDHmax->xuat();
    } else {
        cout << "\nKhong co sinh vien dai hoc trong danh sach.\n";
    }

    float maxDiemCD = -1;
    SinhVienCaoDang* svCDmax = nullptr;
    for (auto sv : dsSV) {
        SinhVienCaoDang* svcd = dynamic_cast<SinhVienCaoDang*>(sv);
        if (svcd && svcd->getDiemTrungBinh() > maxDiemCD) {
            maxDiemCD = svcd->getDiemTrungBinh();
            svCDmax = svcd;
        }
    }
    if (svCDmax) {
        cout << "\nSinh vien cao dang co diem trung binh cao nhat:\n";
        svCDmax->xuat();
    } else {
        cout << "\nKhong co sinh vien cao dang trong danh sach.\n";
    }

    int demKH_CaoDang = 0, demKH_DaiHoc = 0;
    for (auto sv : dsSV) {
        if (!sv->duDieuKienTotNghiep()) {
            if (dynamic_cast<SinhVienCaoDang*>(sv)) demKH_CaoDang++;
            else if (dynamic_cast<SinhVienDaiHoc*>(sv)) demKH_DaiHoc++;
        }
    }
    cout << "\nSo luong sinh vien cao dang khong du dieu kien tot nghiep: " << demKH_CaoDang << endl;
    cout << "So luong sinh vien dai hoc khong du dieu kien tot nghiep: " << demKH_DaiHoc << endl;

    for (auto sv : dsSV) {
        delete sv;
    }

    return 0;
}
