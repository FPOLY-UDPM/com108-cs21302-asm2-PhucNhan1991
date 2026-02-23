// Xây dựng 1 MeNu chương trình cho phép người dùng lựa chọn chương trình theo mong muốn

#include <stdio.h>
#include <math.h>

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
                printf("Không thể tìm được ước chung lớn nhất của 2 số thục");
            }
            else if(so1 == 0 || so2 == 0)
            {
                uocLonNhat = uocChungLonNhat((int) so1, (int) so2);
                printf("Ước chung lớn nhất của 2 số %.1f và %.1f là %d\n",so1, so2, uocLonNhat) ;}
            else if(so1 <0 || so2 < 0)
            {
                triSo1 = abs(so1);
                triSo2 = abs(so2);
                uocLonNhat = uocChungLonNhat(triSo1, triSo2);
                boiNhoNhat = boiChungNhoNhat( triSo1, triSo2, uocLonNhat);
                printf("Ước chung lớn nhất của 2 số %.1f và %.1f là %d\n",so1, so2, uocLonNhat);
                printf("Bội chung nhỏ nhất của 2 %.1f và %.1f là %d\n",so1, so2, boiNhoNhat); 
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
    
    int tienGio, tienGiamGia, tienThanhToan;
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
			tienGio =  (gioKetThuc - gioBatDau ) * 150000;
			tienGiamGia = (gioKetThuc - gioBatDau ) * 150000 * 0.3 + 0.1* tienGio;
			tienThanhToan = (gioKetThuc - gioBatDau)* 150000 - tienGiamGia;
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
				tienGio =  (gioKetThuc - gioBatDau ) * 150000;
				tienGiamGia = (gioKetThuc - gioBatDau ) * 150000 * 0.3;
				tienThanhToan = (gioKetThuc - gioBatDau)* 150000 - tienGiamGia;			
}
    }
    return tienThanhToan;
}
// __________________________************__________________________________
// __________________________************__________________________________

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
        printf("PHương thức trả góp đều hàng tháng:\n");
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

        for( int i = 0; i < soThang; i++)
        {
            lai = soTienVay * laiSuat;
            soTienPhaiTraHangThang = goc + lai;
            soTienVay = soTienVay - goc;
            printf("Số tiền bạn phải thanh toán vào tháng thứ %d : %.0f\n", i+1, soTienPhaiTraHangThang);
        }
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
        for(int i = 0; i < soThang1; i++)
        {
        bieuThuc = (laiSuat1 * pow(1+laiSuat1, soThang1)) / (pow(1 + laiSuat1, soThang1) - 1);
        soTienPhaiTraHangThang1 = soTienVay1 * bieuThuc; 
        printf("Số tiền bạn phải thanh toán hàng tháng là : %.0f\n", soTienPhaiTraHangThang1);
        }
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
        printf("Chương trình 7 : Vay tiền mua xe\n");
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
            int thoat3 = 0;
            do
            {
               int tienThanhToan = tinhTienKaraoke();
                printf("Số tiền thanh toán là %d VNĐ\n", tienThanhToan);
                 thoat3 = dungNhieuLan();
                if( thoat3 == -1)
                {
                    break;
                }
            } while (thoat3 == 0);
            
            
            break;
        }
        case 4 : 
            printf("Bạn đã chọn chương trình số 4 : Tính tiền điện\n");
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
            break;

        case 5 : 
           
            printf("Bạn đã chọn chương trình số 5 : Đổi tiền\n");
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
            break;

        case 6 :  
            {
                
                printf("Bạn hãy chọn phương pháp trả khoản vay: \n");
                tinhLaiVayNganHang();      
            } 
            break;

        case 7 : 
        printf("Bạn đã chọn chương trình số 7 : Vay tiền mua xe");
        break;

        case 8 : 
        printf("Bạn đã chọn chương trình số 8 : Sắp xếp thông tin sinh viên");
        break;

        case 9 : 
        printf("Bạn đã chọn chương trình số 9 : Game FPOLY_LOTT");
        break;

        case 10 : 
        printf("Bạn đã chọn chương trình số 10: Tính toán phân số");
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