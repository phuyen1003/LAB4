#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

        struct NHANVIEN {
            int MaNV;
            string HoTen;
            string DiaChi;
            bool CBQL;
        };
        // Hàm nhập thông tin của một nhân viên
        void nhapNhanVien(NHANVIEN &nv) {
            cout << "Nhap MaNV: ";
            cin >> nv.MaNV;
            cin.ignore(); // Đọc bỏ dấu Enter sau khi nhập MaNV

            cout << "Nhap HoTen: ";
            getline(cin, nv.HoTen);

            cout << "Nhap DiaChi: ";
            getline(cin, nv.DiaChi);

            cout << "Nhap CBQL (1: Co, 0: Khong): ";
            cin >> nv.CBQL;
        }

        // Hàm nhập thông tin của n nhân viên và xóa những nhân viên không là cán bộ quản lý
        void nhapDanhSachNhanVienVaXoaKhongCBQL(NHANVIEN danhSachNV[], int &n) {
            for (int i = 0; i < n; ++i) {
                cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
                nhapNhanVien(danhSachNV[i]);
            }

            int i = 0;
            while (i < n) {
                if (!danhSachNV[i].CBQL) {
                    for (int j = i; j < n - 1; ++j) {
                        danhSachNV[j] = danhSachNV[j + 1];
                    }
                    --n;
                } else {
                    ++i;
                }
            }
                }
        // Hàm chèn nhân viên mới vào danh sách tại vị trí k
        void chenNhanVien(NHANVIEN danhSachNV[], int &n, NHANVIEN nvMoi, int k) {
            if (k < 0 || k > n) {
                cout << "Vi tri chen khong hop le." << endl;
                return;
            }

            for (int i = n; i > k; --i) {
                danhSachNV[i] = danhSachNV[i - 1];
            }

            danhSachNV[k] = nvMoi;
            ++n;
        }
                bool laSoNguyenTo(int num) {
            if (num <= 1) {
                return false;
            }
            for (int i = 2; i <= sqrt(num); ++i) {
                if (num % i == 0) {
                    return false;
                }
            }
            return true;
        }

        // Hàm nhập mảng ngẫu nhiên từ 1 đến 100
        void nhapMangNgauNhien(int mang[], int n) {
            srand(time(0));
            for (int i = 0; i < n; ++i) {
                mang[i] = rand() % 100 + 1;
            }
        }

        // Hàm sắp xếp và loại bỏ phần tử trùng nhau
        int sapXepVaLoaiBoTrungNhau(int mang[], int n) {
            sort(mang, mang + n);
            int k = 0;
            for (int i = 1; i < n; ++i) {
                if (mang[i] != mang[k]) {
                    ++k;
                    mang[k] = mang[i];
                }
            }
            return k + 1; // Kích thước mới của mảng sau khi loại bỏ trùng nhau
        }

        // Hàm nhập mảng
        void nhapMang(int A[], int N) {
            for (int i = 0; i < N; ++i) {
                cout << "Nhap phan tu thu " << i + 1 << ": ";
                cin >> A[i];
            }
        }

        // Hàm xuất mảng
        void xuatMang(int A[], int N) {
            for (int i = 0; i < N; ++i) {
                cout << A[i] << " ";
            }
            cout << endl;
        }

        // Hàm hủy n phần tử từ vị trí p trong mảng
        void huyNPhanTu(int A[], int &N, int p, int n) {
            if (n <= 0 || p < 0 || p >= N) {
                cout << "Khong the huy " << n << " phan tu tu vi tri " << p << endl;
                return;
            }

            for (int i = p; i < N - n; ++i) {
                A[i] = A[i + n];
            }
            N -= n;
        }

        // Hàm chèn mảng B vào mảng A tại vị trí p
        void chenMang(int A[], int &N, int B[], int M, int p) {
            if (p < 0 || p > N) {
                cout << "Vi tri chen khong hop le." << endl;
                return;
            }

            for (int i = N + M - 1; i >= p + M; --i) {
                A[i] = A[i - M];
            }

            for (int i = 0; i < M; ++i) {
                A[p + i] = B[i];
            }

            N += M;
        }
// Hàm nhập mảng thực
void nhapMang(float a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
}

// Hàm sắp xếp mảng thực theo thứ tự tăng dần
void sapXepTang(float a[], int n) {
    sort(a, a + n);
}

// Hàm tìm phần tử xuất hiện nhiều nhất trong mảng
float phanTuXuatHienNhieuNhat(float a[], int n) {
    float result = a[0];
    int maxCount = 1;

    int currentCount = 1;
    float currentValue = a[0];

    for (int i = 1; i < n; ++i) {
        if (a[i] == currentValue) {
            ++currentCount;
        } else {
            currentCount = 1;
            currentValue = a[i];
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            result = a[i];
        }
    }

    return result;
}

// Hàm kiểm tra và chèn x vào mảng sao cho mảng vẫn tăng
void kiemTraVaChen(float a[], int &n, float x) {
    int viTriChen = n;

    for (int i = 0; i < n; ++i) {
        if (a[i] >= x) {
            viTriChen = i;
            break;
        }
    }

    for (int i = n; i > viTriChen; --i) {
        a[i] = a[i - 1];
    }

    a[viTriChen] = x;
    ++n;
}


int main() {
    int choice;
    do {
        cout << "MENU:\n";
        cout << "CƠ BẢN:\n";
        cout << "1. Nhap mang va tinh trung binh cong\n";
        cout << "2. Xoa va sap xep mang\n";
        cout << "3. Chen phan tu va sap xep tang dan\n";
        cout << "4. Nhap, sap xep , loai no trong mang \n";
        cout << "5. Mang nguyen duong A[N]\n";
        cout << "6. Nhap vao hai mang A[N] VA B[N]\n";
        cout << "7.Nhap, sap xep , in phan tu và nhap mot so thuc x\n";
        cout << "8. Danh sach nhan vien la can bo quan ly.\n";
        cout << "9. Xoa nhan vien la khong can bo quan ly\n";
        cout << "10. Chen nhan vien moi\n";
        cout << "ỨNG DỤNG:\n";
        cout << "11. IELTS\n";
        cout << "12. ĐH DTM\n";
        cout << "13. So gtvt TPHCM\n";
        cout << "14. DVD\n";
        cout << "15. Thoat chuong trinh.\n";
        cout << "Nhap lua chon (1-15): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                int mang[100];

                cout << "Nhap so luong phan tu n: ";
                cin >> n;

                cout << "Nhap cac phan tu cua mang: ";
                for (int i = 0; i < n; ++i) {
                    cin >> mang[i];
                }

                int tongDuong = 0;
                int demDuong = 0;
                int tongAm = 0;
                int demAm = 0;
                int mangChan[100];
                int demChan = 0;

                for (int i = 0; i < n; ++i) {
                    if (mang[i] > 0) {
                        tongDuong += mang[i];
                        ++demDuong;
                    } else if (mang[i] < 0) {
                        tongAm += mang[i];
                        ++demAm;
                    }

                    if (mang[i] % 2 == 0) {
                        mangChan[demChan] = mang[i];
                        ++demChan;
                    }
                }

                cout << "Trung binh cong cua cac so duong: " << static_cast<double>(tongDuong) / demDuong << endl;
                cout << "Trung binh cong cua cac so am: " << static_cast<double>(tongAm) / demAm << endl;

                cout << "Cac so nguyen to trong mang: ";
                for (int i = 0; i < n; ++i) {
                    if (laSoNguyenTo(mang[i])) {
                        cout << mang[i] << " ";
                    }
                }
                cout << endl;

                for (int i = 0; i < demChan - 1; ++i) {
                    for (int j = i + 1; j < demChan; ++j) {
                        if (mangChan[i] > mangChan[j]) {
                            int temp = mangChan[i];
                            mangChan[i] = mangChan[j];
                            mangChan[j] = temp;
                        }
                    }
                }

                cout << "Cac so chan trong mang sau khi sap xep tang dan: ";
                for (int i = 0; i < demChan; ++i) {
                    cout << mangChan[i] << " ";
                }
                cout << endl;

                break;
            }
            case 2: {
                const int MAX_SIZE = 100;
                int A[MAX_SIZE];
                int n, x;

                cout << "Nhap so phan tu cua mang A: ";
                cin >> n;

                cout << "Nhap cac phan tu cua mang A: ";
                for (int i = 0; i < n; ++i) {
                    cin >> A[i];
                }

                cout << "Nhap so nguyen x: ";
                cin >> x;

                bool found = false;
                int count = 0;

                for (int i = 0; i < n; ++i) {
                    if (A[i] == x) {
                        found = true;
                        ++count;
                        // Gán giá trị của phần tử sau vào phần tử hiện tại để "xóa" phần tử hiện tại
                        for (int j = i; j < n - 1; ++j) {
                            A[j] = A[j + 1];
                        }
                        --n; // Giảm kích thước mảng đi 1 sau khi xóa
                        --i; // Giảm chỉ số để kiểm tra phần tử mới chuyển tới
                    }
                }

                if (found) {
                    cout << x << " co trong mang A." << endl;
                    cout << "So lan xuat hien cua " << x << " la: " << count << endl;
                    cout << "Mang A sau khi xoa cac phan tu " << x << ": ";
                    for (int i = 0; i < n; ++i) {
                        cout << A[i] << " ";
                    }
                } else {
                    cout << x << " khong co trong mang A." << endl;
                }

                break;
            }
            case 3: {
                const int MAX_SIZE = 100;
                int A[MAX_SIZE];
                int n, x;

                cout << "Nhap so phan tu cua mang A: ";
                cin >> n;

                cout << "Nhap cac phan tu cua mang A: ";
                for (int i = 0; i < n; ++i) {
                    cin >> A[i];
                }

                cout << "Nhap so nguyen x: ";
                cin >> x;

                // Sắp xếp mảng A theo thứ tự giảm dần
                sort(A, A + n);

                // Tìm vị trí để chèn x vào mảng A sao cho mảng vẫn giữ nguyên thứ tự
                int insertPos = 0;
                for (int i = 0; i < n; ++i) {
                    if (A[i] <= x) {
                        insertPos = i + 1;
                    } else {
                        break;
                    }
                }

                // Dịch các phần tử từ vị trí chèn để tạo chỗ cho x
                for (int i = n; i > insertPos; --i) {
                    A[i] = A[i - 1];
                }

                A[insertPos] = x;
                ++n; // Tăng kích thước mảng sau khi chèn

                cout << "Mang A sau khi chen " << x << ": ";
                for (int i = 0; i < n; ++i) {
                    cout << A[i] << " ";
                }
                cout << endl;

                break;
            }
            case 4: {
                                        int soPhanTu;
                                cout << "Nhap vao so phan tu cua mang: ";
                                cin >> soPhanTu;

                                int mangSoNguyen[100]; // Giả sử tối đa 100 phần tử

                                nhapMangNgauNhien(mangSoNguyen, soPhanTu);

                                cout << "Mang truoc khi sap xep: ";
                                for (int i = 0; i < soPhanTu; ++i) {
                                    cout << mangSoNguyen[i] << " ";
                                }
                                cout << endl;

                                int kichThuocMoi = sapXepVaLoaiBoTrungNhau(mangSoNguyen, soPhanTu);

                                cout << "Mang sau khi sap xep va loai bo trung nhau: ";
                                for (int i = 0; i < kichThuocMoi; ++i) {
                                    cout << mangSoNguyen[i] << " ";
                                }
                                cout << endl;

                break;
            }
            case 5: {
                                int N, p, n;
                    cout << "Nhap so phan tu cua mang A: ";
                    cin >> N;

                    int A[100]; // Giả sử tối đa 100 phần tử

                    nhapMang(A, N);

                    cout << "Nhap vi tri p: ";
                    cin >> p;
                    cout << "Nhap so phan tu n can huy: ";
                    cin >> n;

                    huyNPhanTu(A, N, p, n);

                    cout << "Mang sau khi huy " << n << " phan tu tu vi tri " << p << ": ";
                    xuatMang(A, N);

                break;
            }
            case 6: {
                                int N, M, p;
                    cout << "Nhap so phan tu cua mang A va B: ";
                    cin >> N;

                    int A[200], B[100]; // Giả sử tối đa 200 phần tử cho mảng A và 100 phần tử cho mảng B

                    cout << "Nhap mang A:" << endl;
                    nhapMang(A, N);

                    cout << "Nhap mang B:" << endl;
                    nhapMang(B, N);

                    cout << "Nhap vi tri p: ";
                    cin >> p;

                    chenMang(A, N, B, N, p);

                    cout << "Mang A sau khi chen mang B tai vi tri " << p << ": ";
                    xuatMang(A, N);

                break;
            }
            case 7: {
                                        int n;

                            cout << "Nhap so luong phan tu cua mang: ";
                            cin >> n;

                            float a[100]; // Giả sử tối đa 100 phần tử

                            nhapMang(a, n);
                            sapXepTang(a, n);

                            cout << "Mang sau khi sap xep: ";
                            for (int i = 0; i < n; ++i) {
                                cout << a[i] << " ";
                            }
                            cout << endl;

                            float maxAppearElement = phanTuXuatHienNhieuNhat(a, n);
                            cout << "Phan tu xuat hien nhieu nhat trong mang: " << maxAppearElement << endl;

                            float x;
                            cout << "Nhap so thuc x: ";
                            cin >> x;

                            bool found = false;
                            for (int i = 0; i < n; ++i) {
                                if (a[i] == x) {
                                    cout << "Vi tri xuat hien cua " << x << " trong mang: " << i + 1 << endl;
                                    found = true;
                                    break;
                                }
                            }

                            if (!found) {
                                kiemTraVaChen(a, n, x);
                                cout << "Mang sau khi chen " << x << " sao cho van tang: ";
                                for (int i = 0; i < n; ++i) {
                                    cout << a[i] << " ";
                                }
                                cout << endl;
                            }

                break;
            }
            case 8: {
          int n;

                    cout << "Nhap so luong nhan vien: ";
                    cin >> n;

                    NHANVIEN danhSachNV[100]; // Giả sử tối đa 100 nhân viên

                    for (int i = 0; i < n; ++i) {
                        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
                        nhapNhanVien(danhSachNV[i]);
                    }

                    cout << "Danh sach nhan vien la can bo quan ly:" << endl;
                    for (int i = 0; i < n; ++i) {
                        if (danhSachNV[i].CBQL) {
                            cout << danhSachNV[i].HoTen << endl;
                        }
                    }
                break;
            }
            case 9: {
                 int n;

                    cout << "Nhap so luong nhan vien: ";
                    cin >> n;

                    NHANVIEN danhSachNV[100]; // Giả sử tối đa 100 nhân viên

                    nhapDanhSachNhanVienVaXoaKhongCBQL(danhSachNV, n);

                    cout << "Danh sach nhan vien sau khi xoa nhung khong la can bo quan ly:" << endl;
                    for (int i = 0; i < n; ++i) {
                        cout << "MaNV: " << danhSachNV[i].MaNV << ", HoTen: " << danhSachNV[i].HoTen
                            << ", DiaChi: " << danhSachNV[i].DiaChi << ", CBQL: " << danhSachNV[i].CBQL << endl;
                    }

                break;
            }
            case 10: {
                                    int n;

                    cout << "Nhap so luong nhan vien: ";
                    cin >> n;

                    NHANVIEN danhSachNV[100]; // Giả sử tối đa 100 nhân viên

                    for (int i = 0; i < n; ++i) {
                        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
                        nhapNhanVien(danhSachNV[i]);
                    }

                    NHANVIEN nvMoi;
                    cout << "Nhap thong tin nhan vien moi:" << endl;
                    nhapNhanVien(nvMoi);

                    int k;
                    cout << "Nhap vi tri k de chen: ";
                    cin >> k;

                    chenNhanVien(danhSachNV, n, nvMoi, k);

                    cout << "Danh sach nhan vien sau khi chen:" << endl;
                    for (int i = 0; i < n; ++i) {
                        cout << "MaNV: " << danhSachNV[i].MaNV << ", HoTen: " << danhSachNV[i].HoTen
                            << ", DiaChi: " << danhSachNV[i].DiaChi << ", CBQL: " << danhSachNV[i].CBQL << endl;
                    }
                break;
            }
            case 11: {
                cout << "Ket thuc chuong trinh.\n";
                break;
            }
            case 12: {
                                string maNgach, hoTen;
                        int luongCoBan, bacLuong;
                        const int phuCap_HT = 2000000;
                        const int phuCap_HP = 900000;
                        const int phuCap_GV = 500000;

                        cout << "Nhap ma ngach: ";
                        cin >> maNgach;

                        cout << "Nhap ho ten: ";
                        cin.ignore();
                        getline(cin, hoTen);

                        cout << "Nhap luong co ban: ";
                        cin >> luongCoBan;

                        bacLuong = stoi(maNgach.substr(2, 2));

                        int phuCap;
                        if (maNgach.substr(0, 2) == "HT") {
                            phuCap = phuCap_HT;
                        } else if (maNgach.substr(0, 2) == "HP") {
                            phuCap = phuCap_HP;
                        } else if (maNgach.substr(0, 2) == "GV") {
                            phuCap = phuCap_GV;
                        }

                        int thuNhap = luongCoBan * bacLuong + phuCap;

                        cout  << maNgach << "\t"
                            << hoTen << "\t"
                            << bacLuong << "\t"
                            << phuCap << "\t"
                            << thuNhap << endl;
                break;
            }
            case 13: {
                cout << "Ket thuc chuong trinh.\n";
                break;
            }
            case 14: {
                cout << "Ket thuc chuong trinh.\n";
                break;
            }
            case 15: {
                                    int soLuongDia;
                        const int giaTienDia = 5000;

                        cout << "Nhap so luong dia DVD can mua: ";
                        cin >> soLuongDia;

                        int tongTien = soLuongDia * giaTienDia;

                        if (soLuongDia > 10) {
                            int giamGia = tongTien * 10 / 100;
                            tongTien -= giamGia; // Giảm 10% nếu mua hơn 10 dia
                        }

                        cout << "So tien phai tra: " << tongTien << " VNĐ" << endl;

                break;
            }
            default: {
                cout << "Lua chon khong hop le.\n";
                break;
            }
        }

    } while (choice != 15);

    return 0;
}
