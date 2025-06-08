#include <iostream>
#include <iomanip>
#include "SinhVien.h"

using namespace std;

// -- SinhVien --

SinhVien::SinhVien() : maSV(""), hoTen(""), diaChi(""), tongSoTinChi(0), diemTrungBinh(0.0f) {}

SinhVien::SinhVien(string m, string ht, string dc, int tsc, float dtb)
    : maSV(m), hoTen(ht), diaChi(dc), tongSoTinChi(tsc), diemTrungBinh(dtb) {}

void SinhVien::nhap() {
    cout << "Nhap ma sinh vien: "; getline(cin, maSV);
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap dia chi: "; getline(cin, diaChi);
    cout << "Nhap tong so tin chi: "; cin >> tongSoTinChi;
    cout << "Nhap diem trung binh: "; cin >> diemTrungBinh;
    cin.ignore();
}

void SinhVien::xuat() {
    cout << left << setw(12) << maSV
         << setw(20) << hoTen
         << setw(20) << diaChi
         << setw(10) << tongSoTinChi
         << setw(10) << diemTrungBinh;
}

float SinhVien::getDiemTrungBinh() {
    return diemTrungBinh;
}

string SinhVien::getMaSV() {
    return maSV;
}

// -- SinhVienCaoDang --

SinhVienCaoDang::SinhVienCaoDang() : SinhVien(), diemThiTotNghiep(0.0f) {}

void SinhVienCaoDang::nhap() {
    SinhVien::nhap();
    cout << "Nhap diem thi tot nghiep: "; cin >> diemThiTotNghiep;
    cin.ignore();
}

void SinhVienCaoDang::xuat() {
    SinhVien::xuat();
    cout << setw(15) << diemThiTotNghiep << endl;
}

bool SinhVienCaoDang::duDieuKienTotNghiep() {
    return (tongSoTinChi >= 120 && diemTrungBinh >= 5 && diemThiTotNghiep >= 5);
}

// -- SinhVienDaiHoc --

SinhVienDaiHoc::SinhVienDaiHoc() : SinhVien(), tenLuanVan(""), diemLuanVan(0.0f) {}

void SinhVienDaiHoc::nhap() {
    SinhVien::nhap();
    cout << "Nhap ten luan van: "; getline(cin, tenLuanVan);
    cout << "Nhap diem luan van: "; cin >> diemLuanVan;
    cin.ignore();
}

void SinhVienDaiHoc::xuat() {
    SinhVien::xuat();
    cout << setw(20) << tenLuanVan << setw(10) << diemLuanVan << endl;
}

bool SinhVienDaiHoc::duDieuKienTotNghiep() {
    return (tongSoTinChi >= 170 && diemTrungBinh >= 5 && diemLuanVan >= 5);
}
