/*================== BÀI TẬP KẾ THỪA ==================
-Thư viện X tiến hành cho đăng kí làm thẻ độc giả.Thông tin độc giả gồm :
+Họ tên
+ Ngày lập thẻ
+ Số tháng có hiệu lực của thẻ
- Có 2 loại độc giả : trẻ em và người lớn
+ Độc giả trẻ em cần lưu thêm thông tin họ tên người đại diện.
Tiền làm thẻ tính theo công thức : số tháng có hiệu lực * 5.000 VND
+ Độc giả người lớn cần lưu thêm thông tin số CMND.
Tiền làm thẻ tính theo công thức : số tháng có hiệu lực * 10.000 VND

== = Yêu cầu == =
1. Hãy cài đặt các lớp đại diện cho các loại thẻ độc giả trên để :
+Quản lí thông tin thẻ
+ Tính tiền làm thẻ của một thẻ độc giả
Hãy cài đặt lớp CThuVien để quản lí danh sách các thẻ độc giả trong thư viện, với các chức

năng sau :
+Nhập, xuất danh sách các thẻ độc giả
+ Tính tổng tiền làm thẻ
/*===========================================================================*/
#include "libForm.h"


int main()
{
	libForm* x = new libForm;
	x->Input();
	x->Output();
	cout << "\n\t COST OF CREATE LIBRARY CARD FOR ALL READER: " \
		<< x->sumOfMoney() << " VND"<<endl;

	delete x;
	system("pause");
	return 0;
}