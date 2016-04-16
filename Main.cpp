#include "ThuVien.h"
#include "Student_CSV.h"
#include "Template.h"

void main()
{
	//Khai báo các biến sử dụng
	string HTML; //Chuỗi chứa cấu trúc file HTML
	ThongTin *SV = NULL; //Con trỏ cấu trúc thông tin sinh vien
	int Tong_SV; //Biến chứa tổng số sinh viên
	string *SinhVien = NULL; //Con trỏ chứa thông tin của sinh viên
	string *SinhVien_CT = NULL; //Con trỏ chứa thuộc tính của sinh viên
	int SV_index; //Chỉ mục các thuộc tính các sinh viên
	int *ThuocTinh = NULL; //Con trỏ chứa số thuộc tính của các sinh viên

	//Lấy thông tin sinh viên
	int Test = GetInformation(SV, Tong_SV, SinhVien, SinhVien_CT, ThuocTinh, SV_index);
	if (Test == 0)
	{
		cout << "Error. The number of students is out of memory!" << endl << endl;
		system("pause");
		return;
	}

	//Lấy template từ file html
	GetTemplate(HTML);

	//Đưa thông tin trong struct vào file html
	for (int i = 0; i < Tong_SV; i++)
	{
		TaiThongTin(SV, HTML, i, ThuocTinh);
	}

	//Thông báo hoàn tất
	cout << "All the transmission are completed. Please check your files for any mistake!" << endl << endl;

	//Giải phóng vùng nhớ
	delete[] SV;
	delete[] SinhVien;
	delete[] SinhVien_CT;
	delete[] ThuocTinh;

	system("pause");
}