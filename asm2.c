// Xây dựng 1 MeNu chương trình cho phép người dùng lựa chọn chương trình theo mong muốn

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
// Hàm cho phép người dùng nhập nhiều lần trong 1 chức năng
int dungNhieuLan()
{
    char nhap;
    printf("Bạn có muốn thoát chức năng này không (y/n): ");
    scanf(" %c", &nhap);
    if(nhap == 'y')
    {
        return -1; // -1 tương đương với việc thoát chức năng
    }
    else return 0;
}
// Cac hàm cho chương trình số 1
void kiemTraSoNguyenTo(float soKiemTra)
{
    
    int  check=0;
    // Nhập số cần kiểm tra 

    int i ; // Biến đếm để thực hiện kiểm tra
    
    if(floor(soKiemTra) == soKiemTra)
    {
        int n = (int) soKiemTra;
        if(n > 2 )
        {
            for(i = 2;i<=sqrt(n);i++)
            {
                if( n % i ==0)
                {
                    check = 1;
                    printf("Số %d không là số nguyên tố\n", n);
                    break;
                }
                
            }
                if(check == 0)
                {
                    printf("Số %d là 1 số nguyên tố\n",n);
                }  
        }
        else
        {
            printf("Số %d Không phải là số nguyên tố\n", n);
        }                   
    }
    else
        {
       
        printf("Không thể kiểm tra số thực có phải là số nguyên tố hay không\n");
        }
}   
void kiemTraSoNguyen(float soKiemTra)
{
    int check = 0;
    if(floor(soKiemTra)== soKiemTra)
    {
       check = 1;
        
    }
    else check = 0;
    
    if(check == 1)
    {
        printf("Số %.0f là 1 số nguyên\n", soKiemTra);
    }
    else printf("Số %.1f không phải là 1 số nguyên\n", soKiemTra);
}
void kiemTraSoChinhPhuong(float soKiemTra)
{   
    int check = 0;
    if(soKiemTra >0)
    {
        float canBacHai = sqrt(soKiemTra);
        
        if(pow(floor(canBacHai),2) == soKiemTra)
        {
            check = 1;
        }else check = 0;
    }
    else 
    {
        printf("Số âm không phải là 1 số chính phương\n");
        return;
    }
    if (check ==1)
    {
        printf("Số %.1f là 1 số chính phương\n", soKiemTra);
    }else  printf("Số %.1f không phải là số chính phương\n", soKiemTra);     
} 
void chucNang1()
{
    int thoat = 0;
    do
    {
        float soDuocNhap;
        
        printf("Hãy nhập số bạn cần kiểm tra\n");
        scanf("%f", &soDuocNhap);
        printf("Kết quả sau khi kiểm tra: \n");
        kiemTraSoNguyenTo(soDuocNhap);
        kiemTraSoNguyen(soDuocNhap);
        kiemTraSoChinhPhuong(soDuocNhap);
        thoat = dungNhieuLan();
        if(thoat == -1)
        {
            break;
        }
    } while (thoat == 0);
}   
     
//----------------------------************----------------------------------------//
//----------------------------************----------------------------------------//
// Các hàm cho chương trình số 2
int uocChungLonNhat(float a, float b)
{
    if(floor(a) == a && floor(b) == b)
    {
    int d,UCLN;
    int a1 = (int) a, b1 = (int) b;
    while (b1!=0)
    {
        d = a1 % b1;
        a1 = b1;
        b1 = d;
    }
    UCLN = a1;
    return UCLN;
}
}
int boiChungNhoNhat(float a, float b, int UCLN)

{
    
    // Tìm ước chung lớn nhất giữa 2 số a và b
    
    int boiChungNhoNhat;
    UCLN = uocChungLonNhat(a, b);
    boiChungNhoNhat = (abs(a * b))/ UCLN;
    
    
    return boiChungNhoNhat;
}
void chucNang2()
{   
    int thoat = 0;
    do
    {
            float so1, so2;
            int boiNhoNhat, uocLonNhat;
            int triSo1, triSo2;
        //  Nhập 2 số cần tìm ước chung lớn nhất
            printf("Nhập số thứ 1: \n");
            scanf ("%f",&so1);
            printf("Nhập số thứ 2: \n");
            scanf ("%f",&so2);
            if(floor(so1)!=so1 || floor(so2)!=so2)
            {
                printf("Không thể tìm được ước chung lớn nhất của 2 số thục\n");
                printf("Không thể tìm được bội số chung nhỏ nhất của 2 số thực\n");
            }
            else if(so1 == 0 || so2 == 0)
            {
                printf("Không thể có ước chung lớn nhất khi 1 trong 2 số = 0\n");
                printf("Không thể có bội số chung nhỏ nhất khi 1 trong 2 số = 0\n");
            }
            else if(so1 <0 || so2 < 0)
            {
                printf("Ước chung lớn nhất chỉ áp dụng với 2 số nguyên dương\n");
                printf("Bội số chung nhỏ nhất chỉ áp dụng với 2 số nguyên dương\n");
            }else if(so1 > 0 && so2 >0) {
                
                uocLonNhat = uocChungLonNhat(so1, so2);
                boiNhoNhat = boiChungNhoNhat(so1, so2, uocLonNhat);
                printf("Ước chung lớn nhất của 2 số %.1f và %.1f là %d\n",so1, so2, uocLonNhat);
                printf("Bội chung nhỏ nhất của 2 %.1f và %.1f là %d\n",so1, so2, boiNhoNhat);
            }
            thoat = dungNhieuLan();
            if (thoat == -1)
            {
                break;
            }
    }while (thoat == 0);   
}
//----------------------------************----------------------------------------//
//----------------------------************----------------------------------------//
// Hàm xử lý chức năng số 4
float tinhTienDien()
{
    float soTienPhaiTra, soDienTieuThu;
    printf("Nhập số điện tiêu thụ trong tháng: ");
    scanf("%f",&soDienTieuThu);
    
    if(soDienTieuThu<=50)
    {
        soTienPhaiTra = 1678 * soDienTieuThu;
        printf("Số tiền cần phải đóng = %.0f VNĐ\n", soTienPhaiTra);
    }
    else if( soDienTieuThu<=100)
    {
        soTienPhaiTra = 1678 * 50 + (soDienTieuThu - 50) * 1734;
        printf("Số tiền cần phải đóng = %.0f VNĐ\n", soTienPhaiTra);
    }
    else if( soDienTieuThu <= 200)
    {
        soTienPhaiTra = (1678*50) +(50*1734) + (soDienTieuThu - 100)*2014;
        printf("Số tiền cần phải đóng = %.0f VNĐ\n", soTienPhaiTra);
    }
    else if( soDienTieuThu<=300)
    {
        soTienPhaiTra = (1678*50) + (1734*50) + (2014*100) + (soDienTieuThu - 200)*2536;
        printf("Số tiền cần phải đóng = %.0f VNĐ\n", soTienPhaiTra);
    }
    else if( soDienTieuThu<=400)
    {
        soTienPhaiTra = (1678*50) + (1734*50) + (2014*100) + (2536*100) + (soDienTieuThu - 300) * 2834;
        printf("Số tiền cần phải đóng = %.0f VNĐ\n", soTienPhaiTra);
    }
    else
    {
        soTienPhaiTra = (1678*50) + (1734*50) + (2014*100) + (2536*100) + (2834*100) + (soDienTieuThu-400)*2927;
        printf("Số tiền cần phải đóng = %.0f VNĐ\n", soTienPhaiTra);
    }  
    return soTienPhaiTra;
         
}
void chucNang4()
{
      int thoat4 = 0;
            do 
            {
                tinhTienDien();
                thoat4 = dungNhieuLan();
                if( thoat4 == -1)
                {
                    break;
                }
            }while ( thoat4 == 0); 
}
//----------------------------************----------------------------------------//
//----------------------------************----------------------------------------//
// Chương trình 3 : Tính tiền cho quán Karaoke.
float tinhTienKaraoke()
{   
    float gioBatDau ,gioKetThuc;
//	Nhap vao gio bat dau
    do
    {
        printf("Nhap gio bat dau: ");
	    scanf("%f", &gioBatDau);
    } while (gioBatDau < 12 || gioBatDau > 23);
    
//	Nhap gio ket thuc
    do
    {
       printf("Nhap gio ket thuc: ");
	    scanf("%f", &gioKetThuc);
    } while (gioKetThuc > 23 || gioKetThuc < 12 || gioKetThuc < gioBatDau);
    
    double tienGio, tienGiamGia, tienThanhToan;
    double thanhToan;
	    if (gioBatDau >=14 && gioBatDau <=17)
	    {
		    if(gioKetThuc - gioBatDau <= 3)
		{
			tienGio = (gioKetThuc - gioBatDau)* 150000;
			tienGiamGia  = 0.1* tienGio;
			tienThanhToan = tienGio - tienGiamGia;
		}
		else
		{
			tienGio =  (gioKetThuc - gioBatDau ) * 150000 ;
			tienGiamGia = (gioKetThuc - gioBatDau - 3 ) * 150000 * 0.3 ;
            thanhToan = tienGio - tienGiamGia ;
			tienThanhToan = tienGio - tienGiamGia - 0.1 * thanhToan;
	}
        }
	else
	{
		if(gioKetThuc - gioBatDau <= 3)
		{
			tienGio = (gioKetThuc - gioBatDau)* 150000;
			tienThanhToan = tienGio ;
			}
			else
			{
				tienGio =  (gioKetThuc - gioBatDau ) * 150000 ;
			    tienGiamGia = (gioKetThuc - gioBatDau - 3 ) * 150000 * 0.3 ;
                tienThanhToan = tienGio - tienGiamGia;		
}
    }
    return tienThanhToan;
}
void chucNang3()
{
    int thoat3 = 0;
            do
            {
               int tienThanhToan = tinhTienKaraoke();
                printf("Số tiền thanh toán là %lf VNĐ\n", tienThanhToan);
                 thoat3 = dungNhieuLan();
                if( thoat3 == -1)
                {
                    break;
                }
            } while (thoat3 == 0);
            
}
//----------------------------************----------------------------------------//
//----------------------------************----------------------------------------//
// Hàm xử lý chức năng số 6
void tinhLaiVayNganHang()
{
    int phuongThuc, quayLai = 1;
    do
    {
        printf("Phương thức 1: Dư nợ giảm dần\n");
        printf("Phương thức 2: Trả góp đều\n");
        printf("Bạn hãy lựa chọn phương thức: ");
        scanf("%d", &phuongThuc);    
    
    switch (phuongThuc)
    {
        case 1:
        {
            printf("Phương thức trả góp đều hàng tháng:\n");
            const float laiSuat = 0.05;
            int soThang ;
            double soTienVay;
            do
            {
                printf("Nhập số tiền bạn muốn vay: ");
                scanf("%lf", &soTienVay);
            }while (soTienVay < 0 );
        
            do
            {
                printf("Nhập số tháng bạn muốn thanh toán: ");
                scanf("%d", &soThang);
            } while (soThang <= 0);
        
            double goc,lai, soTienPhaiTraHangThang;
      
            goc = soTienVay / soThang;
            printf("\n===== THONG TIN KHOAN VAY =====\n");
            printf("Tien vay duoc duyet: %.0lf VND\n", soTienVay);
            printf("So thang vay: %d\n", soThang);
           
            printf("------------------------------------------------------------------------------------------\n");
            printf("%-6s | %-15s | %-12s | %-12s | %-15s | %-15s\n","Thang", "Du no dau ky", "Tien goc", "Tien lai", "Tong phai tra", "Du no cuoi ky");
            printf("------------------------------------------------------------------------------------------\n");
            for( int i = 0; i < soThang; i++)
            {
                double duNoDauKy = soTienVay;
                lai = soTienVay * laiSuat;
                soTienPhaiTraHangThang = goc + lai;
                soTienVay = soTienVay - goc;
                printf("%-6d | %-15.0f | %-12.0f | %-12.0f | %-15.0f | %-15.0f\n",i+1, duNoDauKy, goc, lai, soTienPhaiTraHangThang, soTienVay);
            }
            printf("------------------------------------------------------------------------------------------\n");
        break;
        }
        case 2:
        {
        
            printf("Phương thức dư nợ giảm dần: \n");
            const float laiSuat1 = 0.05;
            int soThang1 ;
            double soTienVay1;
            do
            {
                printf("Nhập số tiền bạn muốn vay: ");
                scanf("%lf", &soTienVay1);
            }while (soTienVay1 < 0 );
            do
            {
                printf("Nhập số tháng bạn muốn vay: ");
                scanf("%d", &soThang1);
            } while (soThang1 < 1 );
        
            double  soTienPhaiTraHangThang1, bieuThuc;
            printf("\n===== THONG TIN KHOAN VAY =====\n");
            printf("Tien vay duoc duyet: %.0lf VND\n", soTienVay1);
            printf("So thang vay: %d\n", soThang1);

            printf("------------------------------------------------------------------------------------------\n");
            printf("%-6s | %-15s | %-12s | %-12s | %-15s | %-15s\n","Thang", "Du no dau ky", "Tien goc", "Tien lai", "Tong phai tra", "Du no cuoi ky");
            printf("------------------------------------------------------------------------------------------\n");
            bieuThuc = (laiSuat1 * pow(1+laiSuat1, soThang1)) / (pow(1 + laiSuat1, soThang1) - 1);
            soTienPhaiTraHangThang1 = soTienVay1 * bieuThuc; 
            for(int i = 0; i < soThang1; i++)
            {
                double duNoDauKy = soTienVay1;
                double tienLai = duNoDauKy * laiSuat1;
                double tienGoc = soTienPhaiTraHangThang1 - tienLai;

                soTienVay1 -= tienGoc;

                printf("%-6d | %-15.0f | %-12.0f | %-12.0f | %-15.0f | %-15.0f\n",i+1, duNoDauKy, tienGoc, tienLai,soTienPhaiTraHangThang1, soTienVay1);
            }
            printf("------------------------------------------------------------------------------------------\n");
        }      
        
        default:
            break;
    }
    printf("Bạn hãy chọn lại phương thức\n");
    printf("\nNhap 1 de chọn phương thức khác , 0 de thoat: \n");
   
    scanf("%d", &quayLai);
    } while (phuongThuc < 1 || phuongThuc > 3 || quayLai == 1);
}
//----------------------------************----------------------------------------//
//----------------------------************----------------------------------------//
// Hàm xử lý chức năng số 5
void doiTien()
{
        int soTien;
        printf("Nhập số tiền cần tính toán: ");
        scanf("%d", &soTien);
        int loaiTien[9]={500,200,100,50,20,10,5,2,1};
	    int i, soto, phanthua;
	    for(i=0;i<9;i++)
	    {
		soto = soTien / loaiTien[i];
		printf("%4d to %2d dong\n",soto,loaiTien[i]);
		soTien = soTien % loaiTien[i];
		}
}
void chucNang5()
{
       int thoat5 = 0;
            do 
            {
                doiTien();
                thoat5 = dungNhieuLan();
                if(thoat5 == -1)
                {
                    break;
                }
            }while (thoat5 == 0);
}
//----------------------------************----------------------------------------//
//----------------------------************----------------------------------------//
// Hàm xử lý chức năng số 7
void vayMuaXe()
{
    const int MAX_PERCENT = 80;
    const double MAX_LOAN = 500000000;
    const float ANNUAL_RATE = 0.072;
    int YEARS  ;
    double giaXe;
    double phanTramVay;
    double tienVayMongMuon, tienVayThucTe;
    double tienTraTruoc;
    double laiSuatThang;
    int soThang;
    double gocThang;
    double duNo;
    double laiThang;
    double tongTraThang;
    double tongLai = 0;

    // ===== Nhập dữ liệu =====
    printf("Nhap gia xe (VND): ");
    scanf("%lf", &giaXe);

    do {
        printf("Nhap phan tram vay (<= 80%%): ");
        scanf("%lf", &phanTramVay);

        if (phanTramVay <= 0 || phanTramVay > MAX_PERCENT) {
            printf("Phan tram vay khong hop le! Nhap lai.\n");
        }

    } while (phanTramVay <= 0 || phanTramVay > MAX_PERCENT);

    // ===== Tính tiền vay =====
    tienVayMongMuon = giaXe * phanTramVay / 100.0;

    if (tienVayMongMuon > MAX_LOAN) {
        tienVayThucTe = MAX_LOAN;
    } else {
        tienVayThucTe = tienVayMongMuon;
    }

    tienTraTruoc = giaXe - tienVayThucTe;

    printf("Nhập số năm muốn vay: ");
    scanf("%d", &YEARS);

    soThang = YEARS *12;
    // ===== Thông tin vay =====
    laiSuatThang = ANNUAL_RATE / 12.0;
    gocThang = tienVayThucTe / soThang;
    duNo = tienVayThucTe;

    printf("\n===== THONG TIN KHOAN VAY =====\n");
    printf("Tien vay duoc duyet: %.0lf VND\n", tienVayThucTe);
    printf("Tien tra truoc: %.0lf VND\n", tienTraTruoc);
    printf("So thang vay: %d\n", soThang);
    printf("Lai suat thang: %.4lf %%\n\n", laiSuatThang * 100);

    printf("Thang |    Goc      |    Lai      |   Tong Tra   |   Du No Con Lai\n");
    printf("----------------------------------------------------------------------\n");

    // ===== Vòng lặp tính từng tháng =====
    for (int i = 1; i <= soThang; i++) {
        laiThang = duNo * laiSuatThang;
        tongTraThang = gocThang + laiThang;

        tongLai += laiThang;

        duNo -= gocThang;
        if (duNo < 0) duNo = 0;

        printf("%5d | %10.0lf | %10.0lf | %12.0lf | %15.0lf\n",
               i, gocThang, laiThang, tongTraThang, duNo);
    }

    printf("\n===== TONG KET =====\n");
    printf("Tong tien lai phai tra: %.0lf VND\n", tongLai);
    printf("Tien vay duoc duyet: %.0lf VND\n", tienVayThucTe);
    printf("Tong tien phai tra (ca goc + lai): %.0lf VND\n",
           tongLai + tienVayThucTe);
}
void chucNang7()
{
    int thoat7 = 0;
        do
        {
            vayMuaXe();
            thoat7 = dungNhieuLan();
            if(thoat7 == -1)
            {
                break;
            }
        } while (thoat7 == 0);
}
// Hàm xử lý chức năng số 8: SẮP XẾP THÔNG TIN SINH VIÊN
void sapXepThongTinSinhVien(int n)
{
    struct thongTinSinhVien
    {
        char hoTenSinhVien[100];
        float diemTrungBinh;
        char hocLuc[10];
    }sinhVien[n];
    
    for(int i = 0; i < n; i++)
    {
        // Nhập họ tên sinh viên
        printf("Nhập họ tên sinh viên: ");
        gets(sinhVien[i].hoTenSinhVien);

        // Nhập điểm trung bình của sinh viên
        do
        {
        printf("Nhập điểm trung bình của sinh viên: ");
        scanf("%f", &sinhVien[i].diemTrungBinh);
        getchar();
        } while (sinhVien[i].diemTrungBinh < 0 || sinhVien[i].diemTrungBinh > 10);
        
        
    }
    //  Xác định học lực của sinh viên
    for(int i = 0; i < n; i++)
    {
        if(sinhVien[i].diemTrungBinh >= 9)
        {
           strcpy(sinhVien[i].hocLuc, "Xuất sắc");
        }
        else if(sinhVien[i].diemTrungBinh < 9 && sinhVien[i].diemTrungBinh >=8 )
        {
            strcpy(sinhVien[i].hocLuc, "Giỏi");
        }
        else if(sinhVien[i].diemTrungBinh < 8 && sinhVien[i].diemTrungBinh >= 6.5 )
        {
           strcpy(sinhVien[i].hocLuc, "Khá");
        }
        else if (sinhVien[i].diemTrungBinh < 6.5 &&  sinhVien[i].diemTrungBinh >= 5)
        {
            strcpy(sinhVien[i].hocLuc, "Trung Bình");
        }
        else if( sinhVien[i].diemTrungBinh < 5)
        {
            strcpy(sinhVien[i].hocLuc, "Yếu");
        }
    }
    // Sắp xếp theo thứ tụ điểm giảm dần
    for(int i = 0; i < n; i++)
    {
        for( int j = i + 1; j < n; j++)
        {
            if(sinhVien[i].diemTrungBinh < sinhVien[j].diemTrungBinh)
            {
                struct thongTinSinhVien SvTam;
                SvTam = sinhVien[i];
                sinhVien[i] = sinhVien[j];
                sinhVien[j] = SvTam;

            }
        }
    }
    // HIển thị thông tin trên
    printf("********THÔNG TIN SINH VIÊN*********\n");
    printf("%-5s | %-15s | %-25s | %-25s \n",  "Số thứ tự", "Tên Sinh Viên","Điểm trung bình", "Học lực");
    for(int i = 0; i < n; i++)
    {
         printf("%-5d | %-15s | %-15.2f  | %-20s\n", i+1, sinhVien[i].hoTenSinhVien, sinhVien[i].diemTrungBinh, sinhVien[i].hocLuc);
         printf("\n");
    }

}
void chucNang8()
{
    int thoat8 =0;
    do
    {
        // Khai báo số lượng sinh viên
        int soSinhVien;
        printf("Nhập số lượng sinh viên: ");
        scanf("%d", &soSinhVien);
        getchar();
        sapXepThongTinSinhVien(soSinhVien);
        thoat8 = dungNhieuLan();
        if(thoat8 == -1)
        {
            break;
        }
    } while (thoat8 == 0);
    
    
    
}
// Hàm xử lý chức năng thứ 10
int uocChungLonNhat1(int a, int b)
{
    
    int d,UCLN;
    
    while (b!=0)
    {
        d = a % b;
        a = b;
        b = d;
    }
    UCLN = a;
    return UCLN;
}
void tong2PhanSo(int a, int b, int c, int d)
{
	int tuso, mauso;
	tuso = a * d + c*b;
	mauso = b * d;
	int Uoc = uocChungLonNhat1(tuso, mauso);
	int tuso1, mauso1;
	tuso1 = tuso / Uoc;
	mauso1 = mauso / Uoc;
	printf("Tong 2 phan so %d/%d + %d/%d = %d/%d\n",a, b, c, d, tuso1, mauso1);
}
void tich2PhanSo(int a, int b, int c, int d)
{
	int tuso, mauso;
	tuso = a *c;
	mauso = b * d;
	int Uoc = uocChungLonNhat1(tuso, mauso);
	int tuso1, mauso1;
	tuso1 = tuso / Uoc;
	mauso1 = mauso / Uoc;
	printf("Tich 2 phan so %d/%d x %d/%d = %d/%d\n",a, b, c, d, tuso1, mauso1);	
	}
void hieu2PhanSo(int a, int b, int c, int d)
{
	int tuso, mauso;
	tuso = a * d - c*b;
	mauso = b * d;
	int Uoc = uocChungLonNhat1(tuso, mauso);
	int tuso1, mauso1;
	tuso1 = tuso / Uoc;
	mauso1 = mauso / Uoc;
	if(mauso1 < 0)
	{
		tuso1 = -tuso1;
		mauso1 = - mauso1;
		}
	printf("Hieu 2 phan so %d/%d - %d/%d = %d/%d\n",a, b, c, d, tuso1, mauso1);
	}
void chia2PhanSo(int a, int b, int c, int d)
{
	int tuso, mauso;
	tuso = a * d;
	mauso = b * c;
	int Uoc = uocChungLonNhat1(tuso, mauso);
	int tuso1, mauso1;
	tuso1 = tuso / Uoc;
	mauso1 = mauso / Uoc;
	printf("Thuong 2 phan so %d/%d / %d/%d = %d/%d\n",a, b, c, d, tuso1, mauso1);
	}
void chucNang10()
{
int thoat10 = 0;
	do
	{
	int a, b, c, d;
	// Phan so thu nhat
	printf("Moi nguoi dung nhap tu so cua phan so thu nhat: ");
	scanf("%d", &a);
	do
	{
		
	printf("Moi nguoi dung nhap mau so cua phan so thu nhat: ");
	scanf("%d", &b);
	} while (b == 0);
	// Phan so thu hai
	printf("Moi nguoi dung nhap tu so cua phan so thu hai: ");
	scanf("%d", &c);
	
	do
	{
	printf("Moi nguoi dung nhap mau so cua phan so thu hai: ");
	scanf("%d", &d);
	} while(d == 0);
	
	tong2PhanSo(a, b, c, d);
	hieu2PhanSo(a, b, c, d);
	tich2PhanSo(a, b, c, d);
	chia2PhanSo(a, b, c, d);
	thoat10 = dungNhieuLan();
	if(thoat10 == -1)
	{
		break;
	}
	}while (thoat10 == 0);	
	}
// Hàm xử lý chức năng số 9
void soNgauNhien(int a[], int size, int min, int max)
{
	srand(time(NULL));
	for(int i = 0; i < size; i++)
	{
		a[i] = rand() % (max - min + 1) + min;
		}
	}
void inSoNgauNhien(int arr[], int size)
{
	printf("Các so trong day trung thuong la: \n");
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
		}
		printf("\n");
	}
 void chucNang9()
{
    int thoat9 = 0;
    do
    {
        int soNhap[2];
	// Nhập 2 số yêu thích
	for(int i = 0; i < 2; i++)
	{
        do
        {
            printf("Nhap sô thu %d: ", i+1);
		    scanf("%d", &soNhap[i]);
        } while (soNhap[i] < 0 || soNhap[i] > 15);
        
		
	}
	
	int random[2];
	soNgauNhien(random, 2, 1, 15);
	
	inSoNgauNhien(random, 2);
	int soLanGiongNhau = 0;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if(soNhap[i] == random[j])
			{
				soLanGiongNhau = soLanGiongNhau + 1;
			}
		}
	}
	if (soLanGiongNhau == 0)
	{
		printf("Chuc ban may man lan sau!!\n");
	}
	else if (soLanGiongNhau == 1)
	{
		printf("Ban da trung giai nhi!!\n");
		}
		else if (soLanGiongNhau >= 2)
		{
			printf("Ban da trung giai nhat!!\n");
			}
    thoat9 = dungNhieuLan();
    if(thoat9 == -1)
    {
        break;
    }        
    } while (thoat9 == 0);      
}   

// Hàm chính trong bài
int main()
{
   
    // Khai báo biến lưu trữ giá trị của sự lựa chọn
    int luaChon;
    int tiepTuc = 1;
    // Xây dựng Menu 
 
    // Kiểm tra người dùng chọn chức năng
    do
    {
        printf("*********Menu Chương Trình**********\n`"); 
        printf("Chương trình 1 : Kiểm tra số \n"); //xong
        printf("Chương trình 2 : Tìm ước số chung và bội số chung của 2 số\n"); // xong
        printf("Chương trình 3 : Tính tiền cho quán Karaoke\n"); // xong
        printf("Chương trình 4 : Tính tiền điện\n"); // xong
        printf("Chương trình 5 : Đổi tiền\n"); //  xong
        printf("Chương trình 6 : Tính lãi vay ngân hàng, vay trả góp\n"); // xong
        printf("Chương trình 7 : Vay tiền mua xe\n"); // xong
        printf("Chương trình 8 : Sắp xếp thông tin sinh viên\n");
        printf("Chương trình 9 : Game FPOLY_LOTT\n");
        printf("Chương trình 10: Tính toán phân số\n");
        printf("Bạn hãy chọn chức năng ");
        scanf("%d", &luaChon);

        switch(luaChon)
    {
        case 1 : 
            printf("Bạn đã chọn chương trình số 1 : Kiểm tra số nguyên\n");
            chucNang1();
            break;

        case 2 : 
            printf("Bạn đã chọn chương trình số 2 : Tìm ước số chung và bội số chung của 2 số\n");
            chucNang2();
            break;

        case 3 : 
        {   
            printf("Bạn đã chọn chương trình số 3 : Tính tiền cho quán Karaoke\n ");
            chucNang3();
            
            break;
        }
        case 4 : 
        {
            printf("Bạn đã chọn chương trình số 4 : Tính tiền điện\n");
            chucNang4(); 
            break;
        }
        case 5 : 
         {  
            printf("Bạn đã chọn chương trình số 5 : Đổi tiền\n");
            chucNang5();
            break;
         }   
        case 6 :  
            {
                
                printf("Bạn hãy chọn phương pháp trả khoản vay: \n");
                tinhLaiVayNganHang();      
            } 
            break;

        case 7 : 
        {
        printf("Bạn đã chọn chương trình số 7 : Vay tiền mua xe\n");
        chucNang7();
        break;
        }
        case 8 : 
        printf("Bạn đã chọn chương trình số 8 : Sắp xếp thông tin sinh viên\n");
        chucNang8();
        break;

        case 9 : 
        printf("Bạn đã chọn chương trình số 9 : Game FPOLY_LOTT\n");
        chucNang9();
        break;

        case 10 : 
        printf("Bạn đã chọn chương trình số 10: Tính toán phân số\n");
        chucNang10();
        break;


        default:
        printf("Bạn hãy chọn lại chương trình");
        
    }
    printf("\nNhập 1 để quay lại MeNu chương trình, 0 de thoat: ");
    scanf("%d", &tiepTuc);
    if (tiepTuc == 0)
    {
        printf("Bạn đã thoát khỏi MENU");
    }
    } while ((luaChon <1 || luaChon > 10 ) || tiepTuc == 1);
    return 0;
}