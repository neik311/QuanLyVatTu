
struct CT_HOADON
{
	char mavt[sl_kytu_mavt] =("");
	long long soluong;
	long long dongia;
	int vat;
};
struct DS_CT_HD
{
	CT_HOADON ct_hoadon[max_cthd];
	int soluong;
};
struct THOIGIAN
{
	int ngay;
	int thang;
	int nam;
};
struct HOADON
{
	char sohd[max_kt]=("");
	THOIGIAN thoigian;
	char loai[max_gioitinh]=("");
	DS_CT_HD dscthd;
};
struct notehd
{
	HOADON hoadon;
	notehd *next;
};

struct NHANVIEN
{
	char manv[max_kt] =("");
	char ho[max_kt]=("");
	char ten[max_kt]=("");
	char phai[max_gioitinh]=("");
	notehd *dshd = NULL;
};

struct DSNHANVIEN
{
	NHANVIEN *nhanvien[max_slnhanvien];
	int soluong;
};


struct VatTu
{
	char MaVT[sl_kytu_mavt]=("");
	char TenVT[max_kt]=("");
	char DVT[max_kt]=("");// don vi tinh
	long long SLT=-1;// so luong ton
};
struct ListVatTu
{
	VatTu vt;
	ListVatTu *pleft, *pright;
};
typedef struct ListVatTu* LISTVT;


struct MANG_VT
{
	VatTu *vt[MAXVT];
	int sl;
};

notehd *khoitaonote()
{
	notehd *p=new notehd;
	p->next=NULL;
	return p;	
}


