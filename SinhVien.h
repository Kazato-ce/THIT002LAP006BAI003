#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <string>
using namespace std;

class SinhVien {
protected:
    string maSV;
    string hoTen;
    string diaChi;
    int tongSoTinChi;
    float diemTrungBinh;

public:
    SinhVien();
    SinhVien(string m, string ht, string dc, int tsc, float dtb);

    virtual void nhap();
    virtual void xuat();
    virtual bool duDieuKienTotNghiep() = 0;

    float getDiemTrungBinh();
    string getMaSV();

    virtual ~SinhVien() {}  // Destructor ảo để hủy đúng lớp con
};

class SinhVienCaoDang : public SinhVien {
private:
    float diemThiTotNghiep;

public:
    SinhVienCaoDang();

    void nhap() override;
    void xuat() override;
    bool duDieuKienTotNghiep() override;
};

class SinhVienDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    float diemLuanVan;

public:
    SinhVienDaiHoc();

    void nhap() override;
    void xuat() override;
    bool duDieuKienTotNghiep() override;
};

#endif
