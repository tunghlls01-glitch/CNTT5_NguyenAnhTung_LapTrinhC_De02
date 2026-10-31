#include<stdio.h>
#include<string.h>
#define MAX 50
typedef struct {
	int maThuoc;
	char tenThuoc[50];
	int soLuong;
	double donGia;
} thuoc;

void hienThiMenu(){
	printf("\n ===== QUAN LY THUOC =====\n");
	printf("1. Them thuoc\n");
	printf("2. Hien thi danh sach thuoc\n");
	printf("3. Cap nhat thuoc theo ma\n");
	printf("4. Xoa thuoc theo ma\n");
	printf("5. Tim thuoc theo ten\n");
	printf("6. Thong ke kho hang\n");
	printf("0. Thoat\n");
	printf("Chon chuc nang: \n");
}

int timTheoMaThuoc(thuoc ds[], int n, int ma){
	for(int i = 0; i< n; i++){
		if(ds[i].maThuoc == ma){
			return i;
		}
	}
	return -1;
}
int themThuoc(thuoc ds[], int n){
	thuoc t;
	if(n >= MAX){
		printf("Danh sach da day");
		return n;
	}
	printf("Moi ban nhap ma: ");
	scanf("%d", &t.maThuoc);
	if(t.maThuoc <= 0){
		printf("Ma thuoc khong duoc am hay bang 0");
		return n;
	}
	if(timTheoMaThuoc(ds, n, t.maThuoc) != -1){
		printf("Ma thuoc da ton tai");
		return n;
	}
	getchar();
	printf("Moi ban nhap ten: ");
	fgets(t.tenThuoc, sizeof(t.tenThuoc), stdin);
	t.tenThuoc[strcspn(t.tenThuoc, "\n")] = '\0';
	
	do{
		printf("Moi ban nhap so luong thuoc: ");
		scanf("%d", &t.soLuong);
		if(t.soLuong < 0){
			printf("moi ban nhap lai so luong phai lon hon hoac bang 0\n");
		}
	}while(t.soLuong <= 0);
	
	do{
		printf("Moi ban nhap don gia thuoc: ");
		scanf("%lf", &t.donGia);
		if(t.donGia < 0){
			printf("moi ban nhap lai gon gia phai lon hon 0\n");
		}
	}while(t.donGia < 0);
	ds[n] = t;
	n++;
	printf("Them thuoc thanh cong");
	return n;
}

void hienThiDanhSach(thuoc ds[], int n){
	if(n == 0){
		printf("Danh sach rong");
		return;
	}
	
	printf("\nMa | Ten thuoc | so Luong | Don gia | Thanh tien\n");
	for(int i = 0; i < n; i++){
		printf("%d | %s | %d | %.2f | %.0f\n", ds[i].maThuoc, ds[i].tenThuoc, ds[i].soLuong, ds[i].donGia, (ds[i].soLuong * ds[i].donGia));	
	}
}

void capNhatThuoc(thuoc ds[], int n){
	if(n == 0){
		printf("Danh sach rong");
		return;
	}
	thuoc t;
	int viTri;
	printf("Moi ban nhap ma can cap nhat: ");
	scanf("%d", &t.maThuoc);
	viTri = timTheoMaThuoc(ds, n, t.maThuoc);
	if(viTri == -1){
		printf("Khong tim thay thuoc");
		return;
	}
	getchar();
	printf("Moi ban nhap ten moi: ");
	fgets(t.tenThuoc, sizeof(t.tenThuoc), stdin);
	t.tenThuoc[strcspn(t.tenThuoc, "\n")] = '\0';
	
	do{
		printf("Moi ban nhap so luong thuoc moi: ");
		scanf("%d", &t.soLuong);
		if(t.soLuong < 0){
			printf("moi ban nhap lai so luong phai lon hon hoac bang 0\n");
		}
	}while(t.soLuong <= 0);
	
	do{
		printf("Moi ban nhap don gia thuoc moi: ");
		scanf("%lf", &t.donGia);
		if(t.donGia < 0){
			printf("moi ban nhap lai gon gia phai lon hon 0\n");
		}
	}while(t.donGia < 0);
	
	
	strcpy(ds[viTri].tenThuoc, t.tenThuoc);
	ds[viTri].soLuong = t.soLuong;
	ds[viTri].donGia = t.donGia;
	
	printf("Cap nhat thanh cong");
}

int xoaThuoc(thuoc ds[], int n){
	if(n == 0){
		printf("Danh sach rong");
		return n;
	}
	thuoc t;
	int viTri;
	printf("Moi ban nhap ma can xoa: ");
	scanf("%d", &t.maThuoc);
	viTri = timTheoMaThuoc(ds, n, t.maThuoc);
	if(viTri == -1){
		printf("Khong tim thay thuoc");
		return n;
	}
	for(int i = viTri; i < n - 1; i++){
		ds[i] = ds[i+1];
	}
	n--;
	printf("Xoa thanh cong");
	return n;
}

void timThuocTheoTen(thuoc ds[], int n){
	if(n == 0){
		printf("Danh sach rong");
		return n;
	}
	thuoc t;
	int flag = -1;
	getchar();
	printf("Moi ban nhap ten can tim: ");
	fgets(t.tenThuoc, sizeof(t.tenThuoc), stdin);
	t.tenThuoc[strcspn(t.tenThuoc, "\n")] = '\0';
	
	for(int i = 0; i < n; i++){
		if(strcmp(ds[i].tenThuoc, t.tenThuoc) == 0){
			flag = i;
		}
	}
	
	if(flag == -1){
		printf("Khong tim thay thuoc\n");
		return;
	}
	printf("\nMa | Ten thuoc | so Luong | Don gia | Thanh tien\n");
	for(int i = 0; i < n; i++){
		if(strcmp(ds[i].tenThuoc, t.tenThuoc) == 0){
			printf("%d | %s | %d | %.2f | %.0f\n", ds[i].maThuoc, ds[i].tenThuoc, ds[i].soLuong, ds[i].donGia, (ds[i].soLuong * ds[i].donGia));	
		}
	}
	return;
}

void thongKe(thuoc ds[], int n){
	if(n == 0){
		printf("Danh sach rong");
		return n;
	}
	float tongThanhKho = 0;
	for(int i = 0; i < n; i++){
		tongThanhKho = (ds[i].soLuong * ds[i].donGia);
	}
	
	printf("Tong gia tri Kho: %.0f\n", tongThanhKho);
	printf("so thuoc sap het hang: \n");
	for(int i = 0; i < n; i++){
		if(ds[i].soLuong < 5){
			printf("%d | %s | %d | %.2f | %.0f\n", ds[i].maThuoc, ds[i].tenThuoc, ds[i].soLuong, ds[i].donGia, (ds[i].soLuong * ds[i].donGia));	
		}
	}
	thuoc temp;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if((ds[i].soLuong * ds[i].donGia) < (ds[j].soLuong * ds[j].donGia))
			temp = ds[i];
			ds[i] = ds[j];
			ds[j] = temp;
		}
	}
	printf("thuoc co gia tien lon nhat la: ");
	printf("%d | %s | %d | %.2f | %.0f\n", ds[0].maThuoc, ds[0].tenThuoc, ds[0].soLuong, ds[0].donGia, (ds[0].soLuong * ds[0].donGia));
}
int main(void){
	thuoc ds[MAX];
	int n = 0;
	int choice;
	do{
		hienThiMenu();
		scanf("%d", &choice);
		switch(choice){
			case 1: {
				n = themThuoc(ds, n);
				break;
			}
			case 2: {
				hienThiDanhSach(ds, n);
				break;
			}
			case 3: {
				capNhatThuoc(ds, n);
				break;
			}
			case 4: {
				n = xoaThuoc(ds, n);
				break;
			}
			case 5: {
				timThuocTheoTen(ds, n);
				break;
			}
			case 6: {
				thongKe(ds, n);
				break;
			}
			case 0: {
				printf("Tam biet!");
				break;
			}
			default: {
				printf("Lua chon khong hop le");
				break;
			}
		}
	}while(choice != 0);
	return 0;
}