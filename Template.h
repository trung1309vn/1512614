#include "ThuVien.h"

//Hàm Get Template
//Input: chuỗi HTML
//Output: dữ liệu html template chứa vào chuỗi HTML
void GetTemplate(string &HTML)
{
	//Mở file html
	ifstream f;
	f.open("Personal.txt");
	if (!f)
	{
		perror("Mo file that bai.\n");
	}
	string T; //Chuỗi tạm
	while (!f.eof())
	{
		getline(f, T);
		HTML += T;
		HTML += "\n";
	}

	//Đóng file
	f.close();
}

