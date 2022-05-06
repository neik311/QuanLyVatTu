
#include <stdio.h>
#include <conio.h>
//#include <graphics.h>
#include <winbgim.h> 
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string.h>
#include <ctime> 
#include "xuatmh.h"
#include "hangso.h"
#include "data.h"
#include "function.h"
using namespace std;        // size 2 15x15  // size 3 23x23  //size 4  30x30
void xuat_huongdan();
void xuat_thongtin();
void xuat_xoanv();
void xuat_tnv();
void xuat_nhapvt();
void xuat_suanv();
byte xl_nhanvien(DSNHANVIEN &dsnhanvien,int &ktm1); 
byte xl_hoadon(DSNHANVIEN &dsnhanvien,LISTVT &tree,int &ktm3, notehd *&hd,int &vt);
void xuat_01();
byte xl_vattu(LISTVT &tree,MANG_VT &mangvt,int &ktm2);
void gd2(LISTVT &tree);


//---------------------------------------------------------------------Nguyen Hoang Hao-------------------------------------------------------------------------

void RemoveVatTu(LISTVT &tree, VatTu vt);
void InsertVatTu(LISTVT &tree, VatTu vt,MANG_VT &mangvt);
void sua_slt(LISTVT &tree, char mavt2[sl_kytu_mavt],int slt,int xi);
void CheckMaVT(LISTVT tree, char mavt[50] , VatTu &x);
void loc_danhsachvt(MANG_VT &mangvt ,int *loc[MAXVT] ,int &n,char stk[max_kt]);
void check_mavt(LISTVT &tree, char s[50],bool &kt);
int vitri_xoavt(int y,int sl,int sotrang);
void delete_mangvt (MANG_VT &mangvt,int vt);
void them_mangvt(MANG_VT &mangvt, VatTu *vt);
int vitri_vt(MANG_VT &mangvt,char s[max_kt] );
void docfile_vattu(LISTVT &tree , MANG_VT &mangvt);
void ghifile_vattu(VatTu vt);
void duyet_file(LISTVT &tree, fstream &f);
void reset_filevt(LISTVT &tree);
void coppy(char a[50],string b);
string int_string(int n);
void auto_mavt(char sx[50],LISTVT tree);
bool sosanh_tg(THOIGIAN c, THOIGIAN d);
void auto_manv(DSNHANVIEN dsnhanvien,char sx[50]);
bool NamNhuan(int nam);
bool CheckNgay(int ngay,int thang,int nam);
bool sosanh(char a[max_kt], char b[max_kt]);
void viet_hoa(char sx[max_kt]);
void chuyen_cach(char sx[max_kt]);
long long  char_long(char s[50]);
int char_int(char s[50]);
char *tro_long(long long n);
char *tro_int(int n);
int min(int a,int b);
void loc_danhsach(DSNHANVIEN &dsnhanvien ,int *loc[max_slnhanvien] ,int &n,char stk[max_kt]);

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


void InsertVatTu(LISTVT &tree, VatTu vt,MANG_VT &mangvt)
{	
	if(tree == NULL)
	{
		ListVatTu *p = new ListVatTu;
		p->vt = vt;
		p->pleft = p->pright = NULL;
		
		tree = p;
		VatTu *vt = &tree->vt;
		them_mangvt(mangvt,vt);
	}
	else
	{
		if(strcmp(tree->vt.MaVT, vt.MaVT) > 0)
		{
			InsertVatTu(tree->pleft, vt,mangvt);
		}
		else
		{
			InsertVatTu(tree->pright, vt,mangvt);
		}
	}
}

string int_string(int n)
{
	string s = "";
	while (n>0)
	{
		s =  char (48 +n%10) + s ;
		n = n/10;
	}
	return s;
}
void xuat_tthd()
{
	cincolor(2,7,3);
	barcolor(399,67,997,100,2);
	cincolor(2,7,3);
	outtextxy(404,70," TAO HD ");     
	outtextxy(602,70," IN HD  ");      
	outtextxy(800,70,"THONG KE");	  
}
void xuat_dahuy()
{
	byte i=0;
	while(i<1)
	   {
	   	cincolor(2,4,3);
	   	outtextxy(550,600,"HUY");
	   	cincolor(4,15,2);
	    outtextxy(480,630,"HUY THANH CONG");
	   	delay(400);
	   	i=i+1;
	   }
	delay(0.0001);
	cincolor(2,7,3);
	outtextxy(550,600,"HUY");
	barcolor(450,630,950,650,15);
}
void xuat_themthanhcong(char *s)
{
	byte i=0;
	while(i<1)
	   {
	   	cincolor(2,4,3);
	   	outtextxy(750,600,"LUU");
	   	cincolor(4,15,2);
	    outtextxy(680,640,s);
	   	delay(400);
	   	i=i+1;
	   }
	delay(0.0001);
	cincolor(2,7,3);
	outtextxy(750,600,"LUU");
	barcolor(450,630,950,660,15);
}
void xl_tthd(int x)
{
	if (x==4)  {
		       	cincolor(2,4,2);
	             outtextxy(360,30,"HUONG DAN");
	            cincolor(-1,11,3);  return ;
			   }
		else {
		       	cincolor(2,7,2);
	             outtextxy(360,30,"HUONG DAN");
	            cincolor(-1,11,3); 
			   }
	if (x==5)   {
		       	cincolor(2,4,2);
	             outtextxy(930,30,"THONG TIN");
	            cincolor(-1,11,3);  return ;
			   }
	    else {
		       	cincolor(2,7,2);
	             outtextxy(930,30,"THONG TIN");
	            cincolor(-1,11,3);  ;
			   }
}
void xl_x(int x,int y)
{
	if ((x>=1325 && x<= 1350  )  && (y>= 140 && y<= 165))
	        {
	           cincolor(15,4,3);
	           outtextxy(1325,140,"X");
			}
	else 
		  {
			cincolor(15,7,3);
	           outtextxy(1325,140,"X");
		  }
	if ((x>=1270 && x<= 1340  )  && (y>= 185 && y <= 210))       
	       {
	     		cincolor(2,4,3);
	            outtextxy(1270,185,"Luu");
		   }
		else
	       {
		         		cincolor(2,7,3);
	                    outtextxy(1270,185,"Luu");
			}			          
	cincolor(0,7,2);				  
}

void xuat_01()                    
{
	clear02();
	setcolor(2);
	barcolor(1,1,1500,50,9);
 	setbkcolor(11);
 	vien_hcm(4,1,1495,50);
 	line(5,51,1495,51);
	int x1=80,y1=10;
	cincolor(2,7,3);
	setfillstyle(1,7);
	bar(x1-5,y1-3,x1+195,y1+30);
	setbkcolor(7);
	outtextxy(x1,y1," VAT TU ");    
	barcolor(x1+500-5,y1-3,x1+500+270,y1+30,7);
	outtextxy(x1+500,y1," NHAN VIEN ");   
	barcolor(x1+1050-5,y1-3,x1+1050+220,y1+30,7); 
	outtextxy(x1+1050,y1," HOA DON ");     
	settextstyle(0,0,2);
	outtextxy(x1+280,y1+20,"HUONG DAN");  
	outtextxy(x1+850,y1+20,"THONG TIN");        
	cincolor(2,11,3);
}

void coppy(char a[50],string b)
{
	int i;
//	strcpy(a,"");
	for ( i=0;i<b.length();i++)
	   a[i]=b[i];
	   
	for (int j=i;j<50;j++)  a[i] ='\0';
}


void xuat_huongdan()
 {
 	clear03();
 	fstream f1;
 	int x=230,y=230;
	setfillstyle(1,0);	bar(200,150,1300,700); vien_hcm(200,150,1300,700);
	cincolor(15,7,3); outtextxy(1275,150,"X"); 
	cincolor(15,0,3);  outtextxy(550,180,"HUONG DAN"); 
 	f1.open(file_huongdan,ios_base::in);
 	while (f1.eof()==false)
 	  {
 	  	string s1;
 	  	char *s= new char [1000];
 	  	getline(f1,s1);
 	  	for (int i=0;i<s1.length();i++)
 	  	   s[i]=s1[i];
 	  	for (int i=s1.length();i<=100;i++)
 	  	   s[i]='\0';
 	  	cincolor(15,0,2);
 	  	outtextxy(x,y,s);
 	  	y=y+28;
	   }
	f1.close();
	while(1)
	{
		delay(1);
		delay(1);
 	  	int x1=mousex();
		int y1=mousey();
 	  	if ((x1>=1275 && x1<=1300) && (y1>=150  && y1<=175)) {
		       	cincolor(15,4,3);
	            outtextxy(1275,150,"X"); 
			   }
		else   {
		       	cincolor(15,7,3);
	            outtextxy(1275,150,"X"); 
			   }  
	    if (ismouseclick(WM_LBUTTONDOWN)) 	    {
	  	      getmouseclick(WM_LBUTTONDOWN, x, y);
	  	      if ((x>=1275 && x<=1300 )&& (y >=150 && y<=175))    {
				  clear03();
	  		      return;
	  		  }
	    }
	}
 }

void xuat_thongtin()
{
	clear03();
 	fstream f2;
 	int x=250,y=230;
 	setfillstyle(1,0);	bar(200,150,1300,700); vien_hcm(200,150,1300,700);
	cincolor(15,7,3); outtextxy(1275,150,"X"); 
	cincolor(15,0,3);  outtextxy(550,180,"THONG TIN"); 
 	f2.open(file_thongtin,ios_base::in);
 	while (f2.eof()==false) {
 	  	string s1;
 	  	char *s= new char [1400];
 	  	getline(f2,s1);
 	  	for (int i=0;i<s1.length();i++)
 	  	   s[i]=s1[i];
 	  	for (int i=s1.length();i<=100;i++)
 	  	   s[i]='\0';
 	  	cincolor(15,0,2);
 	  	outtextxy(x,y,s);
 	  	y=y+28;
	   }
	f2.close();
	while(1)
	{
		delay(1);
		delay(1);
 	  	int x1=mousex();
		int y1=mousey();
 	  	if ((x1>=1275 && x1<=1300) && (y1>=150  && y1<=175)) {
		       	cincolor(15,4,3);
	            outtextxy(1275,150,"X"); 
			   }
		else   {
		       	cincolor(15,7,3);
	            outtextxy(1275,150,"X"); 
			   }  
	    if (ismouseclick(WM_LBUTTONDOWN)) 	    {
	  	      getmouseclick(WM_LBUTTONDOWN, x, y);
	  	      if ((x>=1275 && x<=1300 )&& (y >=150 && y<=175))    {
				  clear03();
	  		      return;
	  		  }
	    }
	}
 }

void xl_ktm3(int ktm3 ,int &vt01,int &vt02)
{
	int x2=mousex();
		int y2=mousey();
	 if (ktm3==1)
		   {
		   	  int gt02 =ktrahd(x2,y2);
		   	  if (gt02!=vt01)
		   	  {
		   	  	vt01=gt02;
		   	  if (gt02==22 )
		   	        {  
		   	      	    barcolor(450,773,750,805,9);
	                    barcolor(453,773,747,805,4);
	                    cincolor(0,4,2);
	                    outtextxy(500,780,"Huy hoa don");
					 }
			   else if (gt02 !=22 )
			       {
			      	    barcolor(450,773,750,805,9);
	                    barcolor(453,773,747,805,7);
	                    cincolor(0,7,2);
	                    outtextxy(500,780,"Huy hoa don");
				   }
			   if (gt02==23  )
			        {
			       	    barcolor(747,773,1047,805,9);
	                    barcolor(750,773,1044,805,4);
	                    cincolor(0,4,2);
	                    outtextxy(800,780,"luu hoa don");
				    }
			    else if(gt02!=23)
				    {
				        barcolor(747,773,1047,805,9);
	                    barcolor(750,773,1044,805,7);
	                    cincolor(0,7,2);
	                    outtextxy(800,780,"luu hoa don");	
					}
		        }
		       cincolor(7,7,2);
	       }
		   else if (ktm3==3)
		      {
		      	int gt02 =ktrahd(x2,y2);
		      	if (gt02!=vt02)
		      	   {
		      	   	vt02=gt02;
		      	   	if (gt02==27)
		      	   	       {
		      	   	     	   barcolor(30,701,330,805,7);barcolor(30,701,330,703,9);barcolor(30,753,330,755,9);barcolor(179,701,181,753,9);
		      	   	     	   barcolor(30,703,179,753,4);
	                           cincolor(0,4,2);
	                           outtextxy(45,717,"Hoa don");
	                           cincolor(0,7,2);
	                           outtextxy(200,717,"Vat tu");
	                            outtextxy(125,770,"Lam moi");
							  }
					else if (gt02==28)
					        {
					        	      
		      	   	     	   barcolor(30,701,330,805,7);barcolor(30,701,330,703,9);barcolor(30,753,330,755,9);barcolor(179,701,181,753,9);
		      	   	     	   barcolor(181,703,330,753,4);
		      	   	     	   cincolor(0,4,2);
		      	   	     	   outtextxy(200,717,"Vat tu");
	                           cincolor(0,7,2);
	                           outtextxy(45,717,"Hoa don");
	                            outtextxy(125,770,"Lam moi");
							}
					else if (gt02==29)
					        {
					        	      
		      	   	     	   barcolor(30,701,330,805,7);barcolor(30,701,330,703,9);barcolor(30,753,330,755,9);barcolor(179,701,181,753,9);
	                           cincolor(0,7,2);
	                           outtextxy(45,717,"Hoa don");
	                           outtextxy(200,717,"Vat tu");
	                           barcolor(30,755,330,805,4);
	                           cincolor(0,4,2);
	                            outtextxy(125,770,"Lam moi");
							}
					 else 
					        {
					        	barcolor(30,701,330,805,7);barcolor(30,701,330,703,9);barcolor(30,753,330,755,9);barcolor(179,701,181,753,9);
	                           cincolor(0,7,2);
	                           outtextxy(45,717,"Hoa don");
	                           outtextxy(200,717,"Vat tu");
	                            outtextxy(125,770,"Lam moi");
							}
					 }
			  }
}

// --------------------------------------------------------------------HOA DON---------------------------------------------------------------------

byte xl_nhaphd(int a,int b,int c,int d,int e,int dem,int dem2, char sx[50],int ktm3=1) {
	int vt01=0,vt02=0;
	setcolor(2);
	setfillstyle(1,7);
	a=a+4;b=b-2;c=c+1;d=d-2;
    bar(a,b,c,d); vien_hcm(a,b,c,d);
 	byte n=0,cox=-1; bool co=false;
	int x2=a+3,y2=b+1;
	bool danhdau=true; 
	cincolor(0,7,2); 
	outtextxy(x2,y2,tro_char(sx));
	while (sx[n] != '\0')
	    {
	    	n=n+1;
	         x2 = x2 +17;
		}
	cincolor(8,7,2); 
	outtextxy(x2,y2,"|");
	char c1;int v;
	while(1)  {
	  xuly :
	 	delay(1);
		 while (1)
    	    {
    	    	if (ktm3==1 ||ktm3==3)
    	    	       {
    	    	       	xl_ktm3(ktm3,vt01,vt02);
					   }
    	    	 if (ismouseclick(WM_LBUTTONDOWN)) {
				        co=true;
				         int x,y;
	  	                 getmouseclick(WM_LBUTTONDOWN, x, y);
				        cox=ktrahd(x,y,ktm3);
				        clearmouseclick(WM_LBUTTONDOWN);
				        outtextxy(x2,y2," ");
	      	            setcolor(7);vien_hcm(a,b,c,d);     	            
						break;
				 }
				 
				 if (kbhit) break;
			}
		if (co==true)
		    {
		return 	cox ;
	         }
    	if (kbhit())  {
          c1=getch();v=c1;
	  	char s[1]=("") ;s[0]='\0';s[1]='\0'; 
	  	s[0]=c1;
	  	if (v==0 || v==-32)
	  	 {
	  		danhdau=false;
	  		goto xuly;
	  	 } 
	  	else if (danhdau==true)
	  	{
	  	if ( (e==0) && (((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z') ) ||(s[0]>='0'&& s[0]<='9')) && n<dem) {
	  	    	cincolor(0,7,2); 
	           	outtextxy(x2,y2,s);
	           	if (n<dem2)
	              {
	           	    x2 = x2 +17;
	           	    cincolor(8,7,2);
				    outtextxy(x2,y2,"|"); 
	              }
	           	sx[n]=s[0];
				n=n+1;
	          }
	    else 	if ( (e==1 ) &&(s[0]>='0'&& s[0]<='9') && n<dem) {
	  	    	cincolor(0,7,2); 
	           	outtextxy(x2,y2,s);
	           	if (n<dem2)
	              {
	           	    x2=x2+17;
	           	    cincolor(8,7,2); 
	           	    outtextxy(x2,y2,"|");
	              }
	           	sx[n]=s[0];
				n=n+1;
	          }
	    if (v==8 && n>0 ) {
	        	cincolor(7,7,2);
	        	outtextxy(x2,y2," ");
	        	if (n>dem2)  n=dem2+1;
	        	else
				   x2=x2-17;
	        	cincolor(8,7,2); 
	           	outtextxy(x2,y2,"|");
	           	sx[n] ='\0';
	           	n=n-1; ;
	           	sx[n] = '\0';
			}
	    if (v==13 ) {    	
	      	clearmouseclick(WM_LBUTTONDOWN);
	      	outtextxy(x2,y2," ");
	      	setcolor(7);vien_hcm(a,b,c,d);
	      	cincolor(11,11,1);
	      	return -1;
	 		}	
	 	}
	     else if (danhdau==false)  danhdau=true;
      }     
    }
}

bool kt_dulieu(notehd *hd,int sl,int x=-1)
{
	if (x==-1)
	 {
	if ( hd->hoadon.sohd[0]!='\0' && hd->hoadon.loai[0]!='\0'&& CheckNgay(hd->hoadon.thoigian.ngay,hd->hoadon.thoigian.thang,hd->hoadon.thoigian.nam) ==true
	   && hd->hoadon.dscthd.ct_hoadon[sl].mavt[0]!='\0' && hd->hoadon.dscthd.ct_hoadon[sl].dongia!=-1 && hd->hoadon.dscthd.ct_hoadon[sl].soluong!=-1)
	        return true;
	else return false;
     }
    else
	{ 
	    if (hd->hoadon.dscthd.ct_hoadon[x].mavt[0]!='\0' && hd->hoadon.dscthd.ct_hoadon[x].dongia!=-1 && hd->hoadon.dscthd.ct_hoadon[x].soluong!=-1)
	           return true;
	    else return false;
    }
}
void xuat_ngay(int c ,int h ,THOIGIAN x)
{
	cincolor(0,15,1,1);
	outtextxy(c,h,tro_int(x.ngay));
    int cl = 16;
    if (x.ngay>=10)  cl =cl+16;
    outtextxy(c+cl+3,h,"/"); cl=cl+16;
	outtextxy(c+cl,h,tro_int(x.thang));
	cl=cl+15;
    if (x.thang>=10)  cl =cl+16;
    outtextxy(c+cl+3,h,"/"); cl=cl+16;
    outtextxy(c+cl,h,tro_int(x.nam));
}

void CheckMaVT(LISTVT tree, char mavt[50] , VatTu &x)
{
  	if (tree == NULL) 
	  {
	  	x.SLT =-1;
	  	return ;
	  }
	else if (strcmp(tree->vt.MaVT, mavt) == 0)
	{
		x = tree->vt;
		return ;
	}
	else if (strcmp(tree->vt.MaVT, mavt) > 0)
	{
		 CheckMaVT(tree->pleft, mavt,x);
	}
	else
	{
		 CheckMaVT(tree->pright, mavt,x);
	}
}
void xuat_bangvattu()
{
	barcolor(30,200,1470,202,9);
	barcolor(30,740,1470,742,9);
	barcolor(30,770,1470,773,9);
	cincolor(0,15,2);
	outtextxy(50,207,"Ma vat tu");
	outtextxy(250,207,"Ten vat tu");
	outtextxy(500,207,"So luong");
	outtextxy(660,207,"Don vi tinh");
	outtextxy(860,207,"Don gia");
	outtextxy(1040,207,"VAT");
	outtextxy(1140,207,"Thanh tien(d)");
	outtextxy(850,745,"Tong tien :");
	cincolor(9,-1,-1);
	line(30,230,1470,230);	
	line(210,200,210,740);
    line(485,200,485,740);
	line(650,200,650,740);
	line(845,200,845,740);
	line(1035,200,1035,770);
	line(1095,200,1095,740);	
	line (1410,200,1410,740);
	barcolor(450,773,750,805,9);
	barcolor(453,773,747,805,7);
	barcolor(747,773,1047,805,9);
	barcolor(750,773,1044,805,7);
	cincolor(0,7,2);
	outtextxy(500,780,"Huy hoa don");
	outtextxy(800,780,"luu hoa don");
}
void xuat_ttien(int xn , long long tien,int cot)
{
	char a[5];
	int dem=0 ;
	long long x =tien ;
	while( x != 0)
	  {
	  	a[dem] = char(x%10+48);
	  	dem=dem+1;
	  	x = x/10;
	    if (dem ==3 || x ==0)
	        {
	        	char b[5];
	        	for (int i=0;i<dem;i++)
	        	   b[i] = a[dem-i-1];
	        	for (int i=dem;i<5;i++) b[i] = '\0';
	        	for (int i=0;i<5;i++) a[i] = '\0';
	        	cot = cot -(16*dem +5);
	        	outtextxy(cot,xn,b);
	        	dem=0;
			}
	  }
}
void xuat_vthd (notehd *hd , int sl, VatTu &x,long long &tongt,int cot =1405,int color=0)        // hang vat tu hoa don
{
	int xn = 240 +sl*25 , yn =30;
	cincolor(color,15,2);
	outtextxy(40,xn,hd->hoadon.dscthd.ct_hoadon[sl].mavt);
	outtextxy(490,xn,tro_long(hd->hoadon.dscthd.ct_hoadon[sl].soluong));
	outtextxy(850,xn,tro_long(hd->hoadon.dscthd.ct_hoadon[sl].dongia));
	outtextxy(1042,xn,tro_long(hd->hoadon.dscthd.ct_hoadon[sl].vat));
	long long tien = hd->hoadon.dscthd.ct_hoadon[sl].soluong * hd->hoadon.dscthd.ct_hoadon[sl].dongia;
	tien =tien + (tien* (hd->hoadon.dscthd.ct_hoadon[sl].vat))/100 ;
	xuat_ttien(xn,tien,cot);
    outtextxy(220,xn,x.TenVT);
    outtextxy(660,xn,x.DVT);	
	tongt = tongt +tien;
	xuat_ttien(745,tongt,cot);
	barcolor(1413,xn-2,1438,xn+19,4);
	cincolor(15,4,2); outtextxy(1417,xn-2,"x");
	barcolor(1441,xn-2,1468,xn+19,1);
	cincolor(15,1,2); outtextxy(1446,xn-2,"i");
}

void xuat_themvattu()
{
	int x=40,y=170;
	cincolor(0,15,2);
	outtextxy(x,y,"Ma VT:");
	outtextxy(x+340,y,"So luong:");
	outtextxy(x+700,y,"Don gia(d):");
	outtextxy(x+1090,y,"VAT(%)");
	outtextxy(x+1180,y,":");
	cincolor(0,7,2);
	outtextxy(x+100,y,"              ");
	outtextxy(x+485,y,"            ");
	outtextxy(x+880,y,"            ");
	outtextxy(x+1200,y,"    ");
	barcolor(1317,167,1443,193,2);
	barcolor(1320,170,1440,190,15);
	cincolor(2,15,2);
	outtextxy(1325,170,"Them vt");
}
int suavt_hd(notehd *hd,int y,int sl)
{
	int vty = (y-238)/25;
	if (vty>=sl) return -1;
	xuat_themvattu();
	setcolor(4);
	vien_hcm(29,160,1470,200);
	barcolor(1315,165,1445,195,15);
	barcolor(1330,161,1470,200,9);
	barcolor(1332,163,1468,198,7);
	barcolor(1399,163,1401,198,9);
	cincolor(0,7,2);
	outtextxy(1340,170,"Huy");
	outtextxy(1410,170,"Luu");	
	cincolor(0,7,2);
   	outtextxy(142,170,hd->hoadon.dscthd.ct_hoadon[vty].mavt);
    if(hd->hoadon.dscthd.ct_hoadon[vty].soluong!=-1) outtextxy(527,170,tro_int(hd->hoadon.dscthd.ct_hoadon[vty].soluong));
    if(hd->hoadon.dscthd.ct_hoadon[vty].dongia!=-1) outtextxy(922,170,tro_int(hd->hoadon.dscthd.ct_hoadon[vty].dongia));
    if(hd->hoadon.dscthd.ct_hoadon[vty].vat!=-1) outtextxy(1242,170,tro_int(hd->hoadon.dscthd.ct_hoadon[vty].vat));
    return vty;	
}
void xuat_taohd()
{
	int x=40,y=130;
	cincolor(0,15,2);
	outtextxy(x,y,"Ma NV: ");
	outtextxy(x+340,y,"So HD: ");
	outtextxy(x+785,y,"Loai: ");
	outtextxy(x+925,y,"Ngay: ");
	cincolor(0,7,2);
	outtextxy(x+1020,y,"              ");
	cincolor(0,15,2);
	outtextxy(x+1070,y,"/");
	outtextxy(x+1139,y,"/");
	cincolor(0,7,2);
	outtextxy(x+100,y,"              ");
	outtextxy(x+435,y,"                     ");
	barcolor(x+865,130,x+890,150,7);
	barcolor(x+890,130,x+915,150,7);
	outtextxy(x+870,y,"N");outtextxy(x+895,y,"X");
	cincolor(0,0,-1);
	line(x+890,131,x+890,149);
	cincolor(9,-1,-1);
	line(30,160,1470,160);
}
void xuat_themhd()
{
	byte i=0;
	while(i<1)
	   {
	   	barcolor(1320,130,1440,150,4);
	   	cincolor(2,4,2);
	   	outtextxy(1325,130,"Them hd");
	   	delay(300);
	   	i=i+1;
	   }
	delay(1);
	barcolor(1320,130,1440,150,15);
	cincolor(2,15,2);
	outtextxy(1325,130,"Them hd");
}
void xuat_themvt(int x ,char *s)
{
	byte i=0;
	while(i<1)
	   {
	   	barcolor(1320,170,1440,190,4);
	   	cincolor(2,4,2);
	   	outtextxy(x,170,s);
	   	delay(200);
	   	i=i+1;
	   }
	delay(1);
	barcolor(1320,170,1440,190,15);
	cincolor(2,15,2);
	outtextxy(x,170,s);
}
void xuat_inhd()
{
	vien_02();
	barcolor(660,310,730,340,7);
	cincolor(0,15,2);
	outtextxy(420,270,"So HD: ");
	cincolor(2,7,2);
	outtextxy(540,270,"                       ");
	cincolor(2,7,2);
	outtextxy(670,315,"TIM");
	
}
void xuat_tthoadon()
{
	vien_03();
    cincolor(15,7,3);
    outtextxy(1445,120,"X");
	barcolor(40,200,1460,202,9);
	cincolor(0,15,2);
	outtextxy(80,130,"So hoa don : ");
	outtextxy(1000,130,"Loai :");
	outtextxy(600,130,"Ngay lap : ");
	outtextxy(80,166,"Ho ten nhan vien : "); 
	cincolor(0,15,2);
	outtextxy(50,207,"Ma vat tu");
	outtextxy(250,207,"Ten vat tu");
	outtextxy(500,207,"So luong");
	outtextxy(660,207,"Don vi tinh");
	outtextxy(860,207,"Don gia(d)");
	outtextxy(1040,207,"VAT");
	outtextxy(1210,207,"Thanh tien(d)");
	cincolor(9,-1,-1);	  
}

bool kt_sohd(DSNHANVIEN &dsnhanvien ,char sx5[max_kt])
{	
    if (strcmp(sx5,"")==0) return false;
    for (int i=0;i<dsnhanvien.soluong;i++)
     {
     	if (dsnhanvien.nhanvien[i]->dshd != NULL )
     	   {
     	   	for (notehd *k =dsnhanvien.nhanvien[i]->dshd;k!= NULL ; k=k->next)
     	   	   {
     	   	   	if (strcmp(k->hoadon.sohd,sx5) ==0)
     	   	   	          return true;
     	   	   }
     	   }
     }
    return false;
}
void check_tthd(DSNHANVIEN &dsnhanvien , LISTVT &tree,char sx5[max_kt])
{
    for (int i=0;i<dsnhanvien.soluong;i++)
     {
     	if (dsnhanvien.nhanvien[i]->dshd != NULL )
     	   {
     	   	for (notehd *k =dsnhanvien.nhanvien[i]->dshd;k!= NULL ; k=k->next)
     	   	   {
     	   	   	if (strcmp(k->hoadon.sohd,sx5) ==0)
     	   	   	   {
     	   	          cincolor(0,15,1,1);
     	   	          outtextxy(280,128,k->hoadon.sohd);
     	   	          if (strcmp(k->hoadon.loai,"N") ==0 )  outtextxy(1110,128,"Nhap");
     	   	          else outtextxy(1110,128,"Xuat");
     	   	          xuat_ngay(770,128,k->hoadon.thoigian);
     	   	          outtextxy(380,164,dsnhanvien.nhanvien[i]->ho);
     	   	          int j=0;
     	   	          while (dsnhanvien.nhanvien[i]->ho[j] !='\0')
     	   	             {
     	   	             	j=j+1;
						 }
					 outtextxy(380 + j*15+13,164,dsnhanvien.nhanvien[i]->ten);
					 cincolor(0,15,2);
					 outtextxy(380 +j*15+15+230,166,"Ma nhan vien : ");
					 cincolor(0,15,1,1);
					 outtextxy(380+j*15+15+180+285,164,dsnhanvien.nhanvien[i]->manv);
					 long long tongt=0;
					 int xn,yn,cl1=25;	 
					 cl1 =cl1 +(20 - k->hoadon.dscthd.soluong);
					 for (int sl=0;sl<k->hoadon.dscthd.soluong;sl++)
					   {
					   	  VatTu x;
					   	  CheckMaVT(tree,k->hoadon.dscthd.ct_hoadon[sl].mavt,x);
					   	  xn = 250 +sl*cl1 ; yn =30;
	                      cincolor(0,15,2);
	                      outtextxy(47,xn,k->hoadon.dscthd.ct_hoadon[sl].mavt);
	                      outtextxy(490,xn,tro_long(k->hoadon.dscthd.ct_hoadon[sl].soluong));
	                      outtextxy(850,xn,tro_long(k->hoadon.dscthd.ct_hoadon[sl].dongia));
	                      outtextxy(1042,xn,tro_long(k->hoadon.dscthd.ct_hoadon[sl].vat));
	                      long long tien = k->hoadon.dscthd.ct_hoadon[sl].soluong * k->hoadon.dscthd.ct_hoadon[sl].dongia;
	                      tien =tien + (tien* (k->hoadon.dscthd.ct_hoadon[sl].vat))/100 ;
	                      xuat_ttien(xn,tien,1450);
	                      if (strcmp(x.TenVT,"")!=0)
	                       {
                                outtextxy(220,xn,x.TenVT);
                                outtextxy(660,xn,x.DVT);
                           }
                           	else  
			                 {
				                cincolor(4,15,2);    
			                    outtextxy(220,xn,"Vat tu da bi xoa");
			                    cincolor(2,15,2);
			                 }
	                      tongt = tongt +tien;
					   }
					if (k->hoadon.dscthd.soluong==20) xn =xn-5;
					cincolor(9,-1,-1);
					line(40,240,1460,240);
                	line(210,200,210,xn+38);
                    line(485,200,485,xn+38);
                	line(650,200,650,xn+38);
                	line(845,200,845,xn+38);
              	    line(1035,200,1035,xn+26*3);
                   	line(1095,200,1095,xn+38);
                   	line(40,xn+38,1460,xn+38);
                   	line(40,xn+26*3,1460,xn+26*3);
                   	line(40,xn+26*3+1,1460,xn+26*3+1);
                   	barcolor(40,200,42,xn+26*3+1,9);
	                barcolor(1458,200,1460,xn+26*3+1,9);
                   	cincolor(0,15,2);
					outtextxy(850,xn+26*2,"Tong Tien :");
					xuat_ttien(xn+26*2,tongt,1450);
			        return;
     	          }
     	      }
			}
	 }
}
void xuat_bangtracuu()
{
	vien_03();
	cincolor(0,15,1,1);
	outtextxy(50,200,"BANG THONG KE");
	barcolor(330,120,332,805,9);
	cincolor(0,15,2);
	outtextxy(40,300,"Tu ngay :");
	outtextxy(40,400,"Den ngay:");
	outtextxy(140,330,"/");
	outtextxy(210,330,"/");
	outtextxy(140,430,"/");
	outtextxy(210,430,"/");
	cincolor(7,7,2);
	outtextxy(87,330,"   ");
	outtextxy(160,330,"   ");
	outtextxy(230,330,"     ");
	outtextxy(87,430,"   ");
	outtextxy(160,430,"   ");
	outtextxy(230,430,"     ");
	
	barcolor(30,701,330,805,7);
	barcolor(30,701,330,703,9);
	barcolor(30,753,330,755,9);
	barcolor(179,701,181,753,9);
	cincolor(0,7,2);
	outtextxy(45,717,"Hoa don");
	outtextxy(200,717,"Vat tu");
	outtextxy(125,770,"Lam moi");
}
void xuat_10vt(THOIGIAN d, THOIGIAN c)
{
	cincolor(0,15,1,1);
	outtextxy(570,145,"TOP 10 VAT TU CO DOANH THU CAO NHAT");
	outtextxy(580,175,"Tu ngay : "); outtextxy(900,175,"Den ngay : ");
	xuat_ngay(710,175,d);xuat_ngay(1050,175,c);
	cincolor(0,15,2);
	outtextxy(360,250,"Ma vat tu");
	outtextxy(600,250,"Ten vat tu");
	outtextxy(950,250,"Da ban");
	outtextxy(1200,250,"Tong gia tri(d)");	
	barcolor(340,235,1460,237,9);
	barcolor(340,235,342,737,9);
	barcolor(1460,235,1462,737,9);
	barcolor(340,285,1460,287,9);
	for (int i=1;i<=10;i++)
	  {
	  	barcolor(340,285+45*i,1460,287+45*i,9);
	  }
	barcolor(540,235,542,737,9);
	barcolor(870,235,872,737,9);
	barcolor(1150,235,1152,737,9);
}
void check_10vt(DSNHANVIEN &dsnhanvien,LISTVT tree,THOIGIAN d, THOIGIAN c)
{
	int vti=0;
	CT_HOADON top[max_cthd];
	for (int i=0;i<dsnhanvien.soluong;i++)
     {
     	if (dsnhanvien.nhanvien[i]->dshd != NULL)
     	   {
     	   	  for (notehd *k =dsnhanvien.nhanvien[i]->dshd;k!= NULL ; k=k->next)
     	   	    {
     	   	     if (sosanh_tg(d,k->hoadon.thoigian) && sosanh_tg(k->hoadon.thoigian,c) && strcmp(k->hoadon.loai,"X") == 0)
     	   	              {
     	   	           	    for (int j=0;j<k->hoadon.dscthd.soluong;j++)
     	   	           	           {
     	   	           	           	int z=0;
     	   	           	           	for (z=0;z<vti;z++)
     	   	           	           	    if (strcmp(k->hoadon.dscthd.ct_hoadon[j].mavt,top[z].mavt)==0)
     	   	           	           	      {
     	   	           	           	            top[z].soluong = top[z].soluong + k->hoadon.dscthd.ct_hoadon[j].soluong;
												top[z].dongia = top[z].dongia + k->hoadon.dscthd.ct_hoadon[j].dongia*k->hoadon.dscthd.ct_hoadon[j].soluong*(k->hoadon.dscthd.ct_hoadon[j].vat+100)/100;
											    break;
													}
									if (z>=vti)
									      {
									      	strcpy(top[vti].mavt,k->hoadon.dscthd.ct_hoadon[j].mavt);
									      	top[vti].soluong = k->hoadon.dscthd.ct_hoadon[j].soluong;
									      	top[vti].dongia =k->hoadon.dscthd.ct_hoadon[j].dongia*k->hoadon.dscthd.ct_hoadon[j].soluong*(k->hoadon.dscthd.ct_hoadon[j].vat+100)/100;
										    vti =vti +1;
										  }
     	   	           	           	             
								 }
     	   	           	   
						   }
     	   	     }
			}
		}
	if (vti==0) 
	     {
	        barcolor(335,140,1465,740,15); 
			cincolor(4,15,2);
			outtextxy(45,630,"Khong co vat tu!");    	
			return ;
		 }
	xuat_10vt(d,c);
	cincolor(0,15,2);
	bool kttop[vti];
	for (int i=0;i<vti;i++)
	      kttop[i] =false;
	int dsl =0 , vtmax =0;
	long long maxt = top[0].dongia;
	for (int i=0 ;i<10;i++)
	    {
	    	for (int j=0;j<vti;j++)
	    	      {
	    	      	if (top[j].dongia>maxt && kttop[j]==false)
	    	      	     {
	    	      	        maxt = top[j].dongia;
	    	      	        vtmax =j;
	    	      	     }
				  }
			
			VatTu x;
			CheckMaVT(tree,top[vtmax].mavt,x);
			kttop[vtmax] =true;
			maxt =top[0].dongia;
			outtextxy(350,300+45*i,top[vtmax].mavt);
			if (strcmp(x.MaVT,"")!=0)   outtextxy(545,300+45*i,x.TenVT);
			else  
			      {
				   cincolor(4,15,2);    
			       outtextxy(545,300+45*i,"Vat tu da bi xoa");
			       cincolor(0,15,2);
			     }
			outtextxy(880,300+45*i,tro_long(top[vtmax].soluong));
			xuat_ttien(300+45*i,top[vtmax].dongia,1455);
			vtmax=0;
			if (i==vti-1) 
			  {
			  	  barcolor(335,300+45*(i+1)-13,1465,740,15);
			  	  return;
			  }
		}
	
}
void xuat_tophd(THOIGIAN d, THOIGIAN c)
{
	cincolor(0,15,1,1);
	outtextxy(500,145,"BANG LIET KE HOA DON TRONG KHOANG THOI GIAN");
	outtextxy(560,175,"Tu ngay : "); outtextxy(920,175,"Den ngay : ");
	xuat_ngay(690,175,d);xuat_ngay(1070,175,c);
	cincolor(0,15,2);
	outtextxy(400,250,"So hoa don");
	outtextxy(655,250,"Ngay");
	outtextxy(800,250,"Loai");
	outtextxy(900,250,"Nhan vien lap");
	outtextxy(1250,250,"Gia tri(d)");
	barcolor(335,235,1465,237,9);
	barcolor(335,235,337,737,9);
	barcolor(1465,235,1467,737,9);
	barcolor(335,285,1465,287,9);
	for (int i=1;i<=10;i++)
	  {
	  	barcolor(335,285+45*i,1465,287+45*i,9);
	  }

	barcolor(640,235,642,737,9);  
	barcolor(795,235,797,737,9);
	barcolor(865,235,867,737,9);
	barcolor(1200,235,1202,737,9);		
}
int dem_slhd(DSNHANVIEN &dsnhanvien , THOIGIAN d, THOIGIAN c)
{
	int dem =0;
	for (int i=0;i<dsnhanvien.soluong;i++)
     {
     	if (dsnhanvien.nhanvien[i]->dshd != NULL)
     	   {
     	   	  for (notehd *k =dsnhanvien.nhanvien[i]->dshd;k!= NULL ; k=k->next)
     	   	    {
     	   	     if (sosanh_tg(d,k->hoadon.thoigian) && sosanh_tg(k->hoadon.thoigian,c))
     	   	           {
     	   	           	dem = dem +1;
						   }
			}
      }
  }
  return dem;
}
void check_tophd(DSNHANVIEN &dsnhanvien , THOIGIAN d, THOIGIAN c,int sotrang,int dem)
{
	int vti=0 , demsl=-1;
	cincolor(0,15,2);
	delay(0.0001);
	for (int i=0;i<dsnhanvien.soluong;i++)
     {
     	if (dsnhanvien.nhanvien[i]->dshd != NULL)
     	   {
     	   	  for (notehd *k =dsnhanvien.nhanvien[i]->dshd;k!= NULL ; k=k->next)
     	   	    {
     	   	     if (sosanh_tg(d,k->hoadon.thoigian) && sosanh_tg(k->hoadon.thoigian,c))
     	   	           {
     	   	           	demsl = demsl +1;
     	   	           	if (demsl >= (sotrang-1)*10)
     	   	           	  {
     	   	           	  	int slhd =0;
     	   	           	  	while (k->hoadon.sohd[slhd] != '\0')
     	   	           	  	         slhd =slhd +1;
     	   	           	    if (slhd<18)  outtextxy(345,300 +45*vti,k->hoadon.sohd);
     	   	           	    else   
     	   	           	        {
     	   	           	        	slhd = 0;
     	   	           	        	while (k->hoadon.sohd[slhd] != '\0')
     	   	           	        	    {
     	   	           	        	    	char *sa = new char[1];
	    	                                sa[0] = k->hoadon.sohd[slhd]; sa[1]='\0';
     	   	           	        	    	outtextxy(340+slhd*15,300+45*vti,sa);
     	   	           	        	    	slhd =slhd +1;
     	   	           	        	    	delete sa;
										}
									barcolor(640,235,642,737,9); 
								}
     	   	           	    char sl[5] ;
     	   	           	    if (strcmp(k->hoadon.loai,"N")==0)
     	   	           	        strcpy(sl,"Nhap");
     	   	           	    else if (strcmp(k->hoadon.loai,"X")==0)  strcpy(sl,"Xuat");
     	   	           	    for(int i=0;i<4;i++)
	                              {
	    	                        char *sa = new char[1];
	    	                        sa[0] = sl[i]; sa[1]='\0';
	    	                        outtextxy(800+i*15,300+45*vti,sa);
	    	                        delete sa;
		                          }
		                    outtextxy(643,300+45*vti,tro_int(k->hoadon.thoigian.ngay));
     	   	                int cl = 17;
     	   	                if (k->hoadon.thoigian.ngay>=10)  cl =cl+15;
     	   	                outtextxy(643+cl,300+45*vti,"/"); cl=cl+13;
					        outtextxy(643+cl,300+45*vti,tro_int(k->hoadon.thoigian.thang));
					        cl=cl+15;
					        if (k->hoadon.thoigian.thang>=10)  cl =cl+15;
     	   	                outtextxy(643+cl,300+45*vti,"/"); cl=cl+13;
					        outtextxy(643+cl,300+45*vti,tro_int(k->hoadon.thoigian.nam));    
		                    barcolor(795,235,797,737,9);
     	   	           	    char sz[max_kt];
     	   	           	    int j=0;
     	   	           	    for (j=0;dsnhanvien.nhanvien[i]->ho[j]!='\0' ;j++)
     	   	           	            sz[j] = dsnhanvien.nhanvien[i]->ho[j];
     	   	           	    sz[j]=' ';
     	   	           	    j=j+1;
     	   	           	    for (int j1=0;dsnhanvien.nhanvien[i]->ten[j1]!='\0' ;j1++)
     	   	           	          {
     	   	           	            sz[j] = dsnhanvien.nhanvien[i]->ten[j1];
     	   	           	            j=j+1;
     	   	           	          }   
     	   	           	    for (int j1=j;j1<50;j1++)
     	   	           	             sz[j1]='\0';
     	   	           	    if (j<20 ) outtextxy(873,300+45*vti,sz);
     	   	           	    else 
     	   	           	         {
     	   	           	         	char sz2[max_kt];
     	   	           	         	int d2=0;  bool ktj =false;
     	   	           	            for (int j2=0;dsnhanvien.nhanvien[i]->ho[j2]!='\0' ;j2++)
     	   	           	                 {
     	   	           	                 	 if (ktj ==false)
													  {  
													    sz2[d2] = dsnhanvien.nhanvien[i]->ho[j2]; d2 =d2+1;
													 }
     	   	           	                 	 else 
     	   	           	                 	     {
     	   	           	                 	         if (dsnhanvien.nhanvien[i]->ho[j2-1]==' ')
     	   	           	                 	             {
															  sz2[d2] = dsnhanvien.nhanvien[i]->ho[j2]; d2 = d2 +1;
															   sz2[d2] = ' '; d2 =d2+1;
													     }
												 }
     	   	           	                 	 if (dsnhanvien.nhanvien[i]->ho[j2] ==' ') ktj =true;
										}
     	   	           	            for (int j2=0;dsnhanvien.nhanvien[i]->ten[j2]!='\0' ;j2++)
     	   	           	              {
     	   	           	                sz2[d2] = dsnhanvien.nhanvien[i]->ten[j2];
     	   	           	                d2=d2+1;
     	   	           	             }     
     	   	           	            for (int j2=d2;j2<50;j2++)
     	   	           	                sz2[j2]='\0';
     	   	           	            outtextxy(873,300+45*vti,sz2);
								}
     	   	           	    long long tien =0;
     	   	           	    for (int j=0;j<k->hoadon.dscthd.soluong;j++)
     	   	           	           {
     	   	           	           	tien =tien +k->hoadon.dscthd.ct_hoadon[j].dongia*k->hoadon.dscthd.ct_hoadon[j].soluong*(k->hoadon.dscthd.ct_hoadon[j].vat+100)/100;
										  }
							cout<<"tien "<<tien;
     	   	           	    if (tien < 10e15) xuat_ttien(300+45*vti,tien,1460); 
						    else outtextxy(1190,300+45*vti,tro_long(tien)); 
     	   	           	    vti=vti+1;
     	   	           	    if (vti==10 ) return ;
     	   	           	   if (demsl ==dem-1)
     	   	           	       {
     	   	           	     	barcolor(335,300+45*vti -13,1467,740,15);
     	   	           	     	return;
							   }
     	   	             }
					}
     	   	     }
			}
		}
}

void xulyhd(notehd *hd,int sl,LISTVT &tree)
{
   cincolor(0,7,2);
   	outtextxy(142,170,hd->hoadon.dscthd.ct_hoadon[sl].mavt);
    if(hd->hoadon.dscthd.ct_hoadon[sl].soluong>0) outtextxy(527,170,tro_long(hd->hoadon.dscthd.ct_hoadon[sl].soluong));
    if(hd->hoadon.dscthd.ct_hoadon[sl].dongia>0) outtextxy(922,170,tro_long(hd->hoadon.dscthd.ct_hoadon[sl].dongia));
    if(hd->hoadon.dscthd.ct_hoadon[sl].vat>0) outtextxy(1242,170,tro_int(hd->hoadon.dscthd.ct_hoadon[sl].vat));
    if (sl!=0)
       {
       	    int tt=0;
       	    long long tongt=0;
       	 	for (tt=0;tt<sl;tt++)
       	 	{
       	 		VatTu x ;
			    CheckMaVT(tree,hd->hoadon.dscthd.ct_hoadon[tt].mavt,x);
			    xuat_vthd(hd,tt,x,tongt);
		    }
	   }
}

void docfile_hoadon(DSNHANVIEN &dsnhanvien)
{
	fstream f;
	f.open(file_hoadon,ios_base::in);
	string s;
	getline(f,s);
	getline(f,s);
	while (f.eof()==false)
	   {
	   	   s="";  getline(f,s);
	   	  if (s=="") break;
	   	  char sx[50]=("");
	   	  coppy(sx,s);
	   	  int vt = kt_vitri(dsnhanvien,sx);
	   	  notehd *p =khoitaonote();
	   	  s="";  getline(f,s);
	   	  coppy(p->hoadon.sohd,s);
	   	  s="";  getline(f,s);
	   	  coppy(p->hoadon.loai,s);
	   	  int a , b ,c;
	   	  f>>a>>b>>c;
	   	  p->hoadon.thoigian.ngay = a;
	   	  p->hoadon.thoigian.thang = b;
	   	  p->hoadon.thoigian.nam = c;
	   	  s="";getline(f,s);
	      int sl=0;
          while (1)
            {
            	s="";
            	getline(f,s);
            	if (s=="") 
            	    {
            	    	p->hoadon.dscthd.soluong=sl;
            	    	break;
					}
            	coppy(p->hoadon.dscthd.ct_hoadon[sl].mavt,s);
            	f>>p->hoadon.dscthd.ct_hoadon[sl].soluong;
            	f>>p->hoadon.dscthd.ct_hoadon[sl].dongia;
            	f>>p->hoadon.dscthd.ct_hoadon[sl].vat;
            	s="";getline(f,s);
				sl=sl+1;
			}
		  if (vt!=-1) themdau( dsnhanvien,vt,p); 		 
	   }
	f.close();
}

void ghifile_hoadon(DSNHANVIEN &dsnhanvien,int vt)
{
	fstream f;
	f.open(file_hoadon,ios_base::out|ios_base::app);           
	f<<dsnhanvien.nhanvien[vt]->manv<<"\n";
	f<<dsnhanvien.nhanvien[vt]->dshd->hoadon.sohd<<"\n";
	f<<dsnhanvien.nhanvien[vt]->dshd->hoadon.loai<<"\n";
	f<<dsnhanvien.nhanvien[vt]->dshd->hoadon.thoigian.ngay<<" "<<dsnhanvien.nhanvien[vt]->dshd->hoadon.thoigian.thang<<" "<<dsnhanvien.nhanvien[vt]->dshd->hoadon.thoigian.nam<<"\n";
    int i=0;
	while(i<dsnhanvien.nhanvien[vt]->dshd->hoadon.dscthd.soluong)
	    {
	    	f<<dsnhanvien.nhanvien[vt]->dshd->hoadon.dscthd.ct_hoadon[i].mavt<<"\n";
	    	f<<dsnhanvien.nhanvien[vt]->dshd->hoadon.dscthd.ct_hoadon[i].soluong<<" ";
	    	f<<dsnhanvien.nhanvien[vt]->dshd->hoadon.dscthd.ct_hoadon[i].dongia<<" ";
	    	f<<dsnhanvien.nhanvien[vt]->dshd->hoadon.dscthd.ct_hoadon[i].vat<<"\n";
	    	i=i+1;
		}
	f<<"\n";
	f.close();
}

// --------------------------------------------------------------------------NHAN VIEN ---------------------------------------------------------------------------

byte xl_ten(int a,int b,int c,int d,int e,int dem,int dem2, char sx[50],int ktm=0) {
	setcolor(2);
	setfillstyle(1,7);
	a=a+4;b=b-2;c=c+1;d=d-1;
    bar(a,b,c,d); vien_hcm(a,b,c,d);
 	int n=0,cox=-1; bool co=false;
	 int x2=a+3,y2=b+1;
	 bool danhdau=true; 
	 cincolor(0,7,2); 
	 outtextxy(x2,y2,tro_char(sx));
	 while (sx[n] != '\0')
	    {
	    	n=n+1;
	    	 x2 = x2 +17;
		}
	cincolor(8,7,2); 
	 outtextxy(x2,y2,"|");
	 char c1;int v;
	 while(1)  {
	  xuly :
	 	delay(1);
		 while (1)
    	    {
    	    	if (ktm==3)
    	    	{
    	    	  int x4=mousex();
		          int y4=mousey();
		            xl_x(x4,y4);
		        }
    	    	 if (ismouseclick(WM_LBUTTONDOWN)) {
				        co=true;
				         int x,y;
	  	                 getmouseclick(WM_LBUTTONDOWN, x, y);
				        cox=ktra(x,y,ktm);
				        clearmouseclick(WM_LBUTTONDOWN);
				        outtextxy(x2,y2," ");
	      	            setcolor(7);vien_hcm(a,b,c,d);
	      	            
						break;
				 }
				 
				 if (kbhit) break;
			}
		if (co==true) 
		   {
		       return 	cox ;
	       }
    	 if (kbhit())  {
          c1=getch();v=c1;
	  	char s[1]=("");s[0]='\0';s[1]='\0';
	  	s[0]=c1;
	  	if (v==0 || v==-32)
	  	{
	  		danhdau=false;
	  		goto xuly;
	  	}
	    if (v==8 && n>0 ) {
	        	cincolor(7,7,2);
	        	outtextxy(x2,y2," ");
	        	if (n>dem2)  n=dem2+1;
	        	else
				   x2=x2-17;
	        	cincolor(8,7,2); 
	           	outtextxy(x2,y2,"|");
	           	sx[n] ='\0';
	           	n=n-1; ;
	           	sx[n] ='\0';
			}
	    if (v==13 ) {
	    	
	      	clearmouseclick(WM_LBUTTONDOWN);
	      	outtextxy(x2,y2," ");
	      	setcolor(7);vien_hcm(a,b,c,d);
	      	cincolor(11,11,1);
	      	return -1;
	 		  }		 	
	  	else if (danhdau==true)
	  	{
	  	if ( (e==0|| e==4) && ((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z') || s[0]==' ') && n<dem) {
	  	    	cincolor(0,7,2); 
	           	outtextxy(x2,y2,s);
	           	if (n<dem2)
	              {
	              	 x2 = x2 +17;
	           	cincolor(8,7,2); 
	           	outtextxy(x2,y2,"|");
	              }
	           	sx[n]=s[0];
					  n=n+1;
	       }
	    
	    else 	if ( (e==1 || e ==3 ) && ((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z') ) && n<dem) {
	  	    	cincolor(0,7,2); 
	           	outtextxy(x2,y2,s);
	           	if (n<dem2)
	              {
	           	      
	               x2 = x2 +17;
	           	cincolor(8,7,2); 
	           	outtextxy(x2,y2,"|");
	              }
	           	sx[n]=s[0];
					  n=n+1;
	       }
	    else if ((e==1|| e==2||e==4) && n<dem)
	       {
	       	if (s[0]>='0'&& s[0]<='9')
	       	   {
	       	   	  cincolor(0,7,2); 
	           	outtextxy(x2,y2,s);
	           	if (n<dem2)
	           	{
	           	       x2=x2+17;
	           	cincolor(8,7,2); 
	           	outtextxy(x2,y2,"|");
	           }
	           	sx[n]=s[0];
				n=n+1; 
			  }
		   }
	 	}
	     else if (danhdau==false)  danhdau=true;
      }
    }
}
void xuat_tnv()                              // them nv
{
    vien_01();
	int x=350,y=200;
  	cincolor(0,15,2); 
  	outtextxy(x,y,"Ho - ten dem : ");
  	outtextxy(x,y+100,"Ten          : ");
  	outtextxy(x,y+200,"Gioi tinh    : ");
  	outtextxy(x,y+300,"Ma nhan vien : ");
  	cincolor(7,7,2);
  	outtextxy(x+250,y,"                         ");outtextxy(x+250,y+100,"                         ");outtextxy(x+250,y+300,"                         ");
  	cincolor(0,7,2);
	outtextxy(x+350,y+200,nam);
	cincolor(0,7,2);
	outtextxy(x+450,y+200,nu);
  	cincolor(2,7,3);
	outtextxy(x+200,y+400,"HUY");
	cincolor(2,7,3);  
	outtextxy(x+400,y+400,"LUU");	 
}

void xuat_suadsnv()
{
	barcolor(148,138,1352,222,2);
	barcolor(150,140,1350,220,15);
	cincolor(0,15,2);
	outtextxy(160,150,"Ho - ten dem:");
	outtextxy(820,150,"Ten:");
	outtextxy(160,180,"Gioi tinh   :");
	outtextxy(678,180,"Ma nhan vien:");	
	barcolor(380,150,770,170,7);
	barcolor(900,150,1230,170,7);
	cincolor(0,7,2);
	outtextxy(400,180,nam);
	outtextxy(480,180,nu);
	cincolor(2,7,3);
	outtextxy(1270,185,"Luu");
	cincolor(15,7,3);
	outtextxy(1325,140,"X");
	
}
void xuat_sotrang(int f,int sotrang)
{
	cincolor(0,15,2);
	int a=1395 ,x=sotrang ;int y = f/16;
	if (f%16 >0) y=y+1;
	outtextxy(a,457,tro_int(x));
	outtextxy(1410,457,"/");
	outtextxy(1425,457,tro_int(y));
}

void xuat_sopt(int f)
{
	int x =825;
	cincolor(2,7,2);
	outtextxy(x,235,"("); 
	x=x+16;
	if (f==0)
	   outtextxy(x,235,"0");
	else
	        outtextxy(x,235,tro_int(f));   
	x=x+20;
	if (f >=10) x = x+16;
	if (f>=100)  x = x +16;
	outtextxy(x,235,")  ");
}
void xuat_indsnv(int f,int sotrang)               //       in danh sach nhan vien                      
{	                                         
	int i=1 +(sotrang-1)*16 ;
	barcolor(455,230,940,258,7);
	cincolor(2,7,2);
	outtextxy(510,235,"DANH SACH NHAN VIEN");
	 
	int a=90,b=260,c=1380,d=290;
	barcolor(a-2,b-2,c+2,d+10+2,3); 
    barcolor(a,b,c,d+10,15);
    b=b+40;d=d+40;        

    int min1 = min(f , (sotrang)*16);
	while (i<= min1)
	{
	    barcolor(a-2,b-2,c+2,d+2,3); 
	    barcolor(a,b,c,d,15);
	    cincolor(0,15,2);
	    outtextxy(a+5,b+5,tro_int(i));   
	    b=b+30;d=d+30;
	    i=i+1;
	}
	barcolor(a-2,d-30,c+2,d-28,15);
	barcolor(a-2,d-32,c+2,d-30,3);
	cincolor(0,15,2);
	outtextxy(95,265,"STT");
	outtextxy(220,265,"Ho - ten dem");
	outtextxy(550,265,"Ten nhan vien");
	outtextxy(810,265,"Gioi tinh");
	outtextxy(1050 ,265,"Ma nhan vien");
	cincolor(0,15,2);
	barcolor(145,260,147,d-30,3);
	barcolor(520,260,522,d-30,3);
	barcolor(800,260,802,d-30,3); 
	barcolor(980,260,982,d-30,3);
	barcolor(1310,260,1312,d-30,3);
	xuat_sotrang(f,sotrang);
}

void loc_danhsach(DSNHANVIEN &dsnhanvien ,int *loc[max_slnhanvien] ,int &n,char stk[max_kt])
{
	n=0;
	bool *kt = new bool[max_slnhanvien];
	for (int i= 0 ;i < max_slnhanvien; i++ )   kt[i] = false;
	for (int i = 0;i <dsnhanvien.soluong;i++)
	  {
	  	if (sosanh(dsnhanvien.nhanvien[i]->manv,stk) && kt[i]==false)
	  	    {
	            loc[n] = new int ;
				*loc[n] = i;
				kt[i] = true;
	            n=n+1;
	            break;
			  }
	  }
	for (int i = 0;i <dsnhanvien.soluong;i++)
	  {
	  	if (sosanh(dsnhanvien.nhanvien[i]->ten,stk)  && kt[i] ==false)
	  	    {
	            loc[n] = new int ;
				*loc[n] = i;
				kt[i] = true;
	            n=n+1;
			  }
	  }
	  
	 for (int i = 0;i <dsnhanvien.soluong;i++)
	  {
	  	if (((dsnhanvien.nhanvien[i]->ten[0]==stk[0]) || (dsnhanvien.nhanvien[i]->ten[0]==stk[0]-32)||(dsnhanvien.nhanvien[i]->ten[0]==stk[0]+32)) && stk[1]=='\0'  && kt[i] == false) 
	  	    {
	            loc[n] = new int ;
				*loc[n] = i;
				kt[i] = true;
	            n=n+1;
			  }
	  }  
	  delete kt;
}

void xuat_loc(DSNHANVIEN &dsnhanvien,int *loc[max_slnhanvien],int n,int vtnv=-1)
{
	int nen=15;
	int a=90,b=260,c=1380,d=290;
    b=b+40;d=d+40;          	
	int a1=155,b1=305;
	if (n>=16)  n=16;
	for (int j=0;j<n;j++)
	   {
	   	if (j == vtnv)   nen =3;
	   	else    nen =15;
	   	int i = *loc[j];
	   	barcolor(a1,b1,a1+365,b1+20,nen);
	   	barcolor(a-2,b-2,c+2,d+2,3); 
	    barcolor(a,b,c,d,nen);
	    b=b+30;d=d+30; 	
	   	cincolor(0, nen ,2);
	  	outtextxy(a1-60,b1,tro_int(j+1));
	  	outtextxy(a1,b1,dsnhanvien.nhanvien[i]->ho);
	  	a1=a1+375;
	  	barcolor(a1,b1,a1+270,b1+20,nen);
	  	outtextxy(a1,b1,dsnhanvien.nhanvien[i]->ten);
	  	a1=a1+285;
	  	barcolor(a1,b1,a1+165,b1+20,nen);
	  	outtextxy(a1,b1,dsnhanvien.nhanvien[i]->phai);
	  	a1=a1+180;
	  	barcolor(a1,b1,1310,b1+20,nen);
		outtextxy(a1,b1,dsnhanvien.nhanvien[i]->manv); 
		barcolor(1318,b1-1,1344,b1+20,4);
		cincolor(15,4,2); outtextxy(1323,b1,"x");
		barcolor(1350,b1-1,1376,b1+20,1);
		cincolor(15,1,2); outtextxy(1355,b1,"i");
	  	a1=155;
	  	b1=b1+30;
       }
   	barcolor(a-2,d-30,c+2,d-28,15);
	barcolor(a-2,d-32,c+2,d-30,3);
    barcolor(145,260,147,d-30,3);
	barcolor(520,260,522,d-30,3);
	barcolor(800,260,802,d-30,3); 
	barcolor(980,260,982,d-30,3);
	barcolor(1310,260,1312,d-30,3);
}

void delete_ptloc(int *loc[max_slnhanvien] ,int vt,int &n)
{
	int x =*loc[vt];
	for (int i=vt;i<n-1;i++)
	    *loc[i] = *loc[i+1];
	delete loc[n-1];
	n=n-1;
	for (int i=0;i<n;i++)
	  {
	  	if (*loc[i] >x)
	  	     *loc[i] =*loc[i] -1;
	  }
}
void xoa_duoi(int n,int trangthai)
{
	int a=90,b=300,c=1380,d=330,x;
	x = b +30*n;
	if(trangthai==2)
	       x = x+2;
	else if (trangthai==1) x=x;
	barcolor(a-3,x,c+3,800,15); 
}

void xuat_timnv()
{
	cincolor(0,15,2);
	outtextxy(290,150,"Nhap ma/ten nhan vien :");
	outtextxy(285,175,"(ky tu dau cua ten)");
	cincolor(7,7,2);
	barcolor(674,150,990,170,7);
	barcolor(1028,145,1172,174,4);
	barcolor(1030,147,1170,172,7);
	cincolor(2,7,2);
	outtextxy(1035,150,"Tim kiem");
}
void docfile_nhanvien(DSNHANVIEN &dsnhanvien)
{
	fstream f;
	f.open(file_nhanvien,ios_base::in);
	string s;
	dsnhanvien.soluong=-1;
	getline(f,s);
	while (f.eof()==false)
	   {
	   	dsnhanvien.soluong=dsnhanvien.soluong+1;         
	   	  dsnhanvien.nhanvien[dsnhanvien.soluong] = new NHANVIEN;
	   	  s="";  getline(f,s);
	   	   if (s=="") break;
	   	  coppy(dsnhanvien.nhanvien[dsnhanvien.soluong]->manv,s);
	   	  s="";  getline(f,s);
	   	  coppy(dsnhanvien.nhanvien[dsnhanvien.soluong]->ho,s);
	   	  s="";  getline(f,s);
	   	  coppy(dsnhanvien.nhanvien[dsnhanvien.soluong]->ten,s);
	   	  s="";  getline(f,s);
	   	  coppy(dsnhanvien.nhanvien[dsnhanvien.soluong]->phai,s);
	      xl_dsnhanvien(dsnhanvien);   
	   }
	f.close();
}

void ghifile_nhanvien(DSNHANVIEN &dsnhanvien)
{
	fstream f;
	f.open(file_nhanvien,ios_base::out|ios_base::app);           
	f<<dsnhanvien.nhanvien[dsnhanvien.soluong]->manv<<"\n";
	f<<dsnhanvien.nhanvien[dsnhanvien.soluong]->ho<<"\n";
	f<<dsnhanvien.nhanvien[dsnhanvien.soluong]->ten<<"\n";
	f<<dsnhanvien.nhanvien[dsnhanvien.soluong]->phai<<"\n";
	f.close();
}
void reset_file(DSNHANVIEN &dsnhanvien)
{
	fstream f;
	f.open(file_nhanvien,ios_base::out|ios_base::trunc);
	f.close();
	f.open(file_nhanvien,ios_base::out|ios_base::app); 
	f<<"\n";
	for (int i=0;i<dsnhanvien.soluong;i++)
	{
	f<<dsnhanvien.nhanvien[i]->manv<<"\n";
	f<<dsnhanvien.nhanvien[i]->ho<<"\n";
	f<<dsnhanvien.nhanvien[i]->ten<<"\n";
	f<<dsnhanvien.nhanvien[i]->phai<<"\n";
   }
	f.close();
}

void xuat_nhapnv()                                 // xuat cac thong tin ve nhanvien
{
	cincolor(2,7,3);
	barcolor(335,67,1119,100,2);
	cincolor(2,7,3);
	outtextxy(340,70," THEM NHAN VIEN ");
	outtextxy(730,70,"   DANH SACH    ");	
}
void xuatnv_i(int a,int b, DSNHANVIEN dsnhanvien,int i,int nen=15)
{
	barcolor(a,b,a+365,b+20,nen);
	cincolor(0, nen ,2);
	  	
	  	outtextxy(a,b,dsnhanvien.nhanvien[i]->ho);
	  	a=a+375;
	  	barcolor(a,b,a+270,b+20,nen);
	  	outtextxy(a,b,dsnhanvien.nhanvien[i]->ten);
	  	a=a+285;
	  	barcolor(a,b,a+165,b+20,nen);
	  	outtextxy(a,b,dsnhanvien.nhanvien[i]->phai);
	  	a=a+180;
	  	barcolor(a,b,1310,b+20,nen);
		outtextxy(a,b,dsnhanvien.nhanvien[i]->manv);
		
		barcolor(1312,b,1380,b+20,nen);
		
		barcolor(1318,b-1,1344,b+20,4);
		cincolor(15,4,2); outtextxy(1323,b,"x");
		
		barcolor(1350,b-1,1376,b+20,1);
		cincolor(15,1,2); outtextxy(1355,b,"i"); 
}
void xuat_dsnhanvien(DSNHANVIEN dsnhanvien,int sotrang,int vtnv=-1)               // xuat thong tin cac nhan vien
{
	int nen;
	int a=155,b=305 , x =(sotrang-1)*16 , n =min(dsnhanvien.soluong,sotrang*16);
	for (int i=x;i<n;i++)
	  {
	  	if (i==vtnv)
	  	     nen=3;
	  	else 
	  	   nen=15;
	  	xuatnv_i(a,b,dsnhanvien,i,nen);
	  	a=155;
	  	b=b+30;
	  }
}
int vitri_xoanv(int y,int sl,int sotrang)
{
	int x =(sotrang-1)*16 , n =min(sl-(sotrang-1)*16,sotrang*16);
	int z=(y-304) %30;
	if (z>=0 && z<=21 )
	  {
	  	int v = (y-304) / 30;
	  	if (v<n)
	  	     return v+(sotrang-1)*16;
	  	else 
	  	   return -1;
	  }
	return -1;
}
void tomau_i(int vt,int nen,int sl,NHANVIEN *nvx)
{
	    int a =155 , b=305+ (vt%16)*30;
      	barcolor(90,300+(vt%16)*30,1380,328+(vt%16)*30,nen);
      	cincolor(0, nen ,2);
      	 outtextxy(95,b,tro_int((vt)+1));   
	  	outtextxy(a,b,nvx->ho);
	  	a=a+375;
	  	barcolor(a,b,a+270,b+20,nen);
	  	outtextxy(a,b,nvx->ten);
	  	a=a+285;
	  	barcolor(a,b,a+165,b+20,nen);
	  	outtextxy(a,b,nvx->phai);
	  	a=a+180;
	  	barcolor(a,b,1310,b+20,nen);
		outtextxy(a,b,nvx->manv);	
		barcolor(1312,b,1380,b+20,nen);
		barcolor(1318,b-1,1344,b+20,4);
		cincolor(15,4,2); outtextxy(1323,b,"x");
		barcolor(1350,b-1,1376,b+20,1);
		cincolor(15,1,2); outtextxy(1355,b,"i"); 
		if (vt%16==15 || vt ==sl-1) b = b-5;
		barcolor(145,b-5,147,b+30,3);
	    barcolor(520,b-5,522,b+30,3);
	    barcolor(800,b-5,802,b+30,3); 
	    barcolor(980,b-5,982,b+30,3);
	    barcolor(1310,b-5,1312,b+30,3);
}
void xl_tomau(DSNHANVIEN &dsnhanvien,int y,int sl,int sotrang,int &vt_ht,int &vt_truoc)
{
	int n =min(sl-(sotrang-1)*16,sotrang*16),x;
	int v = (y-300) / 30;
	if (v<n)
	       {
	  	     x= v+(sotrang-1)*16;
	  	     if (x!=vt_ht)
	  	            {
	  	            	vt_ht =x;
					  }
			else return ;
	  	 }
  	else 
	  	   return;	   
   if (vt_truoc!=-1)
      {
      	NHANVIEN *nvx = new NHANVIEN;
      	nvx = dsnhanvien.nhanvien[vt_truoc];
      	tomau_i(vt_truoc,15,sl,nvx);
	  }
   if (vt_ht!=-1)
      {
      	NHANVIEN *nvx = new NHANVIEN;
      	nvx = dsnhanvien.nhanvien[vt_ht];
      	tomau_i(vt_ht,3,sl,nvx);
		vt_truoc =vt_ht;
	  }
	 
}
void xl_tomauloc(DSNHANVIEN &dsnhanvien,int *loc[max_slnhanvien],int sl,int y,int sotrangtk,int &vt_ht,int &vt_truoc)
{
	int n =min(sl-(sotrangtk-1)*16,sotrangtk*16),x;
	int v = (y-300) / 30;
	if (v<n)
	       {
	  	     x= v+(sotrangtk-1)*16;
	  	     if (x!=vt_ht)
	  	            {
	  	            	vt_ht =x;
					  }
			else return ;
	  	 }
  	else 
	  	   return;	   
	  if (vt_truoc!=-1)
      {
      	NHANVIEN *nvx = new NHANVIEN;
      	nvx = dsnhanvien.nhanvien[*loc[vt_truoc]];
      	tomau_i(vt_truoc,15,sl,nvx);
	  }
   if (vt_ht!=-1)
      {
      	NHANVIEN *nvx = new NHANVIEN;
      	nvx = dsnhanvien.nhanvien[*loc[vt_ht]];
      	tomau_i(vt_ht,3,sl,nvx);
		vt_truoc =vt_ht;
	  }
	 
}

//
// ------------------------------------------------------------------------------VAT TU---------------------------------------------------------------------
//
void xuat_timvt()           
{
	cincolor(0,15,2);
	outtextxy(310,150,"Nhap ma/ten vat tu :");
	outtextxy(310,175,"(ky tu dau cua ten)");
	cincolor(7,7,2);
	//outtextxy(680,150,"                   ");
	barcolor(674,150,990,170,7);	
	barcolor(1028,145,1172,174,4);
	barcolor(1030,147,1170,172,7);
	cincolor(2,7,2);
	outtextxy(1035,150,"Tim kiem");
}
void xuat_nhapvt()            
{
	cincolor(2,7,3);
	barcolor(335,67,1119,100,2);
	cincolor(2,7,3);
	outtextxy(340,70,"  THEM VAT TU   ");
	outtextxy(730,70,"   DANH SACH    ");	
}

void tomauvt_i(int vt,int nen,int sl,VatTu *vtx)       
{
	int a =155 , b=305+ (vt%16)*30;
    barcolor(90,300+(vt%16)*30,1380,328+(vt%16)*30,nen);
    cincolor(0, nen ,2);  	
    outtextxy(95,b,tro_int((vt)+1)); 
    barcolor(a,b,a+245,b+20,nen);
	cincolor(0, nen ,2);  	
	outtextxy(a,b,vtx->MaVT);
	a=a+260;
  	barcolor(a,b,a+315,b+20,nen);
  	outtextxy(a,b,vtx->TenVT);
  	a=a+325;
  	barcolor(a,b,a+290,b+20,nen);
  	outtextxy(a,b,vtx->DVT);
  	a=a+300;
  	barcolor(a,b,1310,b+20,nen);
	outtextxy(a,b,tro_long(vtx->SLT));			
	barcolor(1318,b-1,1344,b+20,4);
	cincolor(15,4,2); outtextxy(1323,b,"x");	
	barcolor(1350,b-1,1376,b+20,1);
	cincolor(15,1,2); outtextxy(1355,b,"i"); 
	if (vt%16==15 || vt ==sl-1) b = b-5;
	barcolor(145,b-5,147,b+30,3);
	barcolor(400,b-5,402,b+30,3);
	barcolor(730,b-5,732,b+30,3); 
	barcolor(1030,b-5,1032,b+30,3);
	barcolor(1310,b-5,1312,b+30,3);
}
void xl_tomauvt(MANG_VT &mangvt,int y,int sotrang,int &vt_ht,int &vt_truoc)           
{
	int sl = mangvt.sl;
	int n =min(sl-(sotrang-1)*16,sotrang*16),x;
	int v = (y-300) / 30;
	if (v<n)
	       {
	  	     x= v+(sotrang-1)*16;
	  	     if (x!=vt_ht)
	  	            {
	  	            	vt_ht =x;
					  }
			else return ;
	  	 }
  	else 
	  	   return;	   
	if (vt_truoc!=-1)
      {
      	VatTu *vtx = new VatTu;
      	vtx = mangvt.vt[vt_truoc];
      	tomauvt_i(vt_truoc,15,sl,vtx);
	  }
   if (vt_ht!=-1)
      {
      	VatTu *vtx = new VatTu;
      	vtx = mangvt.vt[vt_ht];
      	tomauvt_i(vt_ht,3,sl,vtx);
		vt_truoc =vt_ht;
	  }
	 
}
void xl_tomauvtloc(MANG_VT &mangvt,int *loc[MAXVT],int sl,int y,int sotrangtk,int &vt_ht,int &vt_truoc)         
{
	int n =min(sl-(sotrangtk-1)*16,sotrangtk*16),x;
	int v = (y-300) / 30;
	if (v<n)
	       {
	  	     x= v+(sotrangtk-1)*16;
	  	     if (x!=vt_ht)
	  	            {
	  	            	vt_ht =x;
					  }
			else return ;
	  	 }
  	else 
	  	   return;	   
	  if (vt_truoc!=-1)
      {
      	VatTu *vtx = new VatTu;
      	vtx = mangvt.vt[*loc[vt_truoc]];
      	tomauvt_i(vt_truoc,15,sl,vtx);
	  }
   if (vt_ht!=-1)
      {
      	VatTu *vtx = new VatTu;
      	vtx = mangvt.vt[*loc[vt_ht]];
      	tomauvt_i(vt_ht,3,sl,vtx);
		vt_truoc =vt_ht;
	  }
	 
}

void xuat_indsvt(int f,int sotrang)                
{
	int i=1 +(sotrang-1)*16 ;
	barcolor(495,230,970,258,7);
	cincolor(2,7,2);
	outtextxy(515,235,"   DANH SACH VAT TU ");
	 
	int a=90,b=260,c=1380,d=290;
	barcolor(a-2,b-2,c+2,d+10+2,3); 
    barcolor(a,b,c,d+10,15);
   b=b+40;d=d+40;        

   int min1 = min(f , (sotrang)*16);
	while (i<= min1)
	{
	    barcolor(a-2,b-2,c+2,d+2,3); 
	    barcolor(a,b,c,d,15);
	    cincolor(0,15,2);
	    outtextxy(a+5,b+5,tro_int(i));   
	    b=b+30;d=d+30;
	    i=i+1;
	}
		barcolor(a-2,d-30,c+2,d-28,15);
	barcolor(a-2,d-32,c+2,d-30,3);
	cincolor(0,15,2);
	outtextxy(94,265,"STT");
	outtextxy(200,265,"Ma vat tu");
	outtextxy(490,265,"ten vat tu");
	outtextxy(800,265,"Don vi tinh");
	outtextxy(1090 ,265,"So luong ton");
	cincolor(0,15,2);
	barcolor(145,260,147,d-30,3);
	barcolor(400,260,402,d-30,3);
	barcolor(730,260,732,d-30,3); 
	barcolor(1030,260,1032,d-30,3);
	barcolor(1310,260,1312,d-30,3);
	xuat_sotrang(f,sotrang);
}
void xuatvt_i(int a,int b,MANG_VT &mangvt,int i,int nen=15)          
{
	barcolor(a,b,a+245,b+20,nen);
	cincolor(0, nen ,2);	
	outtextxy(a,b,mangvt.vt[i]->MaVT);
	a=a+260;
	barcolor(a,b,a+315,b+20,nen);
	outtextxy(a,b,mangvt.vt[i]->TenVT);
	a=a+325;
  	barcolor(a,b,a+290,b+20,nen);
  	outtextxy(a,b,mangvt.vt[i]->DVT);
  	a=a+300;
  	barcolor(a,b,1310,b+20,nen);
	outtextxy(a,b,tro_long(mangvt.vt[i]->SLT));
	barcolor(1312,b,1380,b+20,nen);
	barcolor(1318,b-1,1344,b+20,4);
	cincolor(15,4,2); outtextxy(1323,b,"x");		
	barcolor(1350,b-1,1376,b+20,1);
	cincolor(15,1,2); outtextxy(1355,b,"i"); 
}
void xuat_dsvt(MANG_VT &mangvt, int sotrang,int vtnv =-1)              
{
	int nen;
	int a=155,b=305 , x =(sotrang-1)*16 , n =min(mangvt.sl,sotrang*16);
	for (int i=x;i<n;i++)
	  {
	  	if (i==vtnv)
	  	     nen=3;
	  	else 
	  	   nen=15;
	  	xuatvt_i(a,b,mangvt,i,nen);
	  	a=155;
	  	b=b+30;
	  }
}
void xuat_tvt()               // them cac thong tin vat tu                
  {
  	vien_01();
  	int x=350,y=200;
  	cincolor(0,15,2);
  	outtextxy(x,y,"Ten vat tu  : ");
  	outtextxy(x,y+100,"So luong    : ");
  	outtextxy(x,y+200,"Don vi tinh : ");
  	outtextxy(x,y+300,"Ma vat tu   : ");
  	cincolor(0,7,2);
  	outtextxy(x+250,y,"                         ");
  	outtextxy(x+250,y+100,"                         ");
  	outtextxy(x+250,y+200,"                         ");
  	outtextxy(x+250,y+300,"                         ");
  	cincolor(2,7,3);
	outtextxy(x+200,y+400,"HUY");
	cincolor(2,7,3);  
	outtextxy(x+400,y+400,"LUU");	
}
void loc_danhsachvt(MANG_VT &mangvt ,int *loc[MAXVT] ,int &n,char stk[max_kt])
{
	if (stk[0]=='\0') return;
	n=0;
	bool *kt = new bool[max_slnhanvien];
	for (int i= 0 ;i < max_slnhanvien; i++ )   kt[i] = false;
	for (int i = 0;i <mangvt.sl;i++)
	  {
	  	if (sosanh(mangvt.vt[i]->MaVT,stk) && kt[i]==false)
	  	    {
	            loc[n] = new int ;
				*loc[n] = i;
				kt[i] = true;
	            n=n+1;
	            delete kt;
	            return;
			  }
	  }
	for (int i = 0;i <mangvt.sl;i++)
	  {
	  	if (sosanh(mangvt.vt[i]->TenVT,stk)  && kt[i] ==false)
	  	    {
	            loc[n] = new int ;
				*loc[n] = i;
				kt[i] = true;
	            n=n+1;
			  }
	  }
	 if (stk[1]!='\0')
	     {
	     	delete kt;
	     	return ;
		 }
	 for (int i = 0;i <mangvt.sl;i++)
	  {
	  	if (((mangvt.vt[i]->TenVT[0]==stk[0]) || (mangvt.vt[i]->TenVT[0]==stk[0]-32)||(mangvt.vt[i]->TenVT[0]==stk[0]+32)) && stk[1]=='\0'  && kt[i] == false) 
	  	    {
	            loc[n] = new int ;
				*loc[n] = i;
				kt[i] = true;
	            n=n+1;
			  }
	  }
	delete kt;
}

void xuat_locvt(MANG_VT &mangvt,int *loc[MAXVT],int n,int nen=15)                  // do hoa 
{
	
	int a=90,b=260,c=1380,d=290;
    b=b+40;d=d+40;          
	int a1=155,b1=305;
	if (n>=16)  n=16;
	for (int j=0;j<n;j++)
	   {
	   	int i = *loc[j];
	   	barcolor(a-2,b-2,c+2,d+2,3); 
	    barcolor(a,b,c,d,nen);
	    b=b+30;d=d+30;
	   	
	   	cincolor(0, nen ,2);
	   	barcolor(a1,b1,a1+245,b1+20,nen);
	  	outtextxy(a1-60,b1,tro_int(j+1));
	  	outtextxy(a1,b1,mangvt.vt[i]->MaVT);
	  	a1=a1+260;
	  	barcolor(a1,b1,a1+315,b1+20,nen);
	  	outtextxy(a1,b1,mangvt.vt[i]->TenVT);
	  	a1=a1+325;
	  	barcolor(a1,b1,a1+290,b1+20,nen);
	  	outtextxy(a1,b1,mangvt.vt[i]->DVT);
	  	a1=a1+300;
	  	barcolor(a1,b1,1310,b1+20,nen);
		outtextxy(a1,b1,tro_int(mangvt.vt[i]->SLT)); 
		barcolor(1318,b1-1,1344,b1+20,4);
		cincolor(15,4,2); outtextxy(1323,b1,"x");
		barcolor(1350,b1-1,1376,b1+20,1);
		cincolor(15,1,2); outtextxy(1355,b1,"i");
	  	a1=155;
	  	b1=b1+30;	   	
   }
   	barcolor(a-2,d-30,c+2,d-28,15);
	barcolor(a-2,d-32,c+2,d-30,3);	
    barcolor(145,260,147,d-30,3);
	barcolor(400,260,402,d-30,3);
	barcolor(730,260,732,d-30,3); 
	barcolor(1030,260,1032,d-30,3);
	barcolor(1310,260,1312,d-30,3);
}

int vitri_xoavt(int y,int sl,int sotrang)
{
	int x =(sotrang-1)*16 , n =min(sl-(sotrang-1)*16,sotrang*16);
	int z=(y-304) %30;
	if (z>=0 && z<=21 )
	  {
	  	int v = (y-304) / 30;
	  	if (v<n)
	  	     return (v+(sotrang-1)*16);
	  	else 
	  	   return -1;
	  }
	return -1;
}
void xuat_suavt()                                                                    // do hoa  
{
		barcolor(148,138,1352,222,2);
	barcolor(150,140,1350,220,15);
	cincolor(0,15,2);
	outtextxy(160,150,"Ten vat tu  :");
	outtextxy(750,150,"Don vi tinh:");
	outtextxy(160,180,"So luong ton:");
	outtextxy(750,180,"Ma vat tu  :");
	
	barcolor(380,150,720,170,7);
	barcolor(960,150,1240,170,7);
	cincolor(0,7,2);
	cincolor(2,7,3);
	outtextxy(1270,185,"Luu");
	cincolor(15,7,3);
	outtextxy(1325,140,"X");
}


void delete_mangvt (MANG_VT &mangvt,int vt)
{
	for (int i=vt;i<mangvt.sl-1;i++)
	  mangvt.vt[i] = mangvt.vt[i+1];
	mangvt.sl = mangvt.sl-1;
}
void them_mangvt(MANG_VT &mangvt, VatTu *vt)
{
        VatTu vtx =*vt;
	 	int vti=-2;
	 	for (int i=0;i<mangvt.sl;i++)
	 	  {
	 	  	if (strcmp(mangvt.vt[i]->TenVT,vtx.TenVT)>0)
	 	  	  {
	 	  	     vti = i;
	 	  	     break;
	 	  	 }
		   }
		if (vti == -2)  
		{
	    	mangvt.vt[mangvt.sl] = vt;
	    	mangvt.sl = mangvt.sl+1;
	    	
	    	return;
		}
	    for (int i=mangvt.sl;i>vti;i--)
	       {
	       	mangvt.vt[i] = mangvt.vt[i-1];
		   }
		mangvt.vt[vti] = vt;
		mangvt.sl =mangvt.sl+1;
	 
}
int vitri_vt(MANG_VT &mangvt,char s[max_kt] )
{
	    for (int i=0;i<mangvt.sl;i++)
	       {
	               if ( strcmp(mangvt.vt[i]->MaVT,s) ==0)
	                         return i;
		   }
		return -1;
	 
}
void docfile_vattu(LISTVT &tree , MANG_VT &mangvt)
{
	mangvt.sl=0;
	      fstream f;
	f.open(file_vattu,ios_base::in);
	string s;
	int x = 0, x1 = 0;
	int i=1;
	getline(f,s);
	while(f.eof()==false)
	{
		i=i+1;
		VatTu vt;
		s="";
		getline(f,s);
		if (s=="") break;
		coppy(vt.TenVT,s);	
		long long slt;
		f>>slt;
		getline(f,s);
		vt.SLT =slt;
		s="";
		getline(f,s);
		coppy(vt.DVT,s);
		s="";
		getline(f,s);
		coppy(vt.MaVT,s);
		InsertVatTu(tree,vt,mangvt);
	}
	f.close(); 
}

void ghifile_vattu(VatTu vt)
{
	fstream f;
	f.open(file_vattu,ios_base::out|ios_base::app);           // con tro chuot ow dong dau nen se xuong dong 2 de ghi
	f<<vt.TenVT<<"\n";
	f<<vt.SLT<<"\n";
	f<<vt.DVT<<"\n";
	f<<vt.MaVT<<"\n";
	f.close();
}
void duyet_file(LISTVT &tree, fstream &f)
{
	if(tree != NULL)
	{
		f<<tree->vt.TenVT<<"\n";
	    f<<tree->vt.SLT<<"\n";
	    f<<tree->vt.DVT<<"\n";
    	f<<tree->vt.MaVT<<"\n";
		duyet_file(tree->pleft,f);
		duyet_file(tree->pright,f);
	}
}
void reset_filevt(LISTVT &tree)
{
	fstream f;
	f.open(file_vattu,ios_base::out|ios_base::trunc);
	f.close();
	f.open(file_vattu,ios_base::out|ios_base::app); 
	f<<"\n";
	duyet_file(tree,f);
	f.close();
}


//------------------------------------------------------------------------Bat Dau ----------------------------------------------------------------------------------- 
void gd2(LISTVT &tree)                        // bat dau
{	
  
	DSNHANVIEN dsnhanvien;
	docfile_nhanvien(dsnhanvien);
	docfile_hoadon(dsnhanvien);
    MANG_VT mangvt;
    docfile_vattu(tree,mangvt);
    bool kt1 = false;
    int ktm3=0 ,ktm1=0,ktm2=0 ,vt=-1 ;
    notehd *hd = khoitaonote();
    hd->hoadon.dscthd.soluong=0;
    hd->hoadon.dscthd.ct_hoadon[0].dongia=-1;
	hd->hoadon.dscthd.ct_hoadon[0].soluong=-1;
	hd->hoadon.dscthd.ct_hoadon[0].vat=0;
	barcolor(0,0,1509,840,9); 
	barcolor(5,5,1496,823,11); 
	xuat_01();
	int x1=80,y1=10;
	while(1)
	{
		delay(0.0001);
		int x=mousex();
		int y=mousey();
		byte gia_tri = ktra01(x,y);
		xl_tthd(gia_tri);
	   if (ismouseclick(WM_LBUTTONDOWN))
	    {	    	
	        int x,y;
	  	    getmouseclick(WM_LBUTTONDOWN, x, y);
	    batdau:
	  		if ((gia_tri== 1 )) {
	  		  	xuat_01(); 
	            barcolor(x1-5,y1-3,x1+195,y1+30,4);
	            cincolor(2,4,3);
	            outtextxy(x1,y1," VAT TU ");
	            setbkcolor(11);
	  		    gia_tri=xl_vattu(tree,mangvt,ktm2);
	  		    goto batdau;
	  	     }
	  	     if (gia_tri==2 ) {
			  	xuat_01(); 
            	barcolor(x1+500-5,y1-3,x1+500+270,y1+30,4);
	            cincolor(2,4,3);
	            outtextxy(x1+500,y1," NHAN VIEN "); 
	            setbkcolor(11);
	            int fsl = mangvt.sl;
			  	gia_tri=xl_nhanvien(dsnhanvien,ktm1);
			  	mangvt.sl = fsl;
			  	goto batdau;
			  }
			  if (gia_tri==3)
			   {
			    xuat_01(); 
            	barcolor(x1+1050-5,y1-3,x1+1050+220,y1+30,4);
	            cincolor(2,4,3);
	            outtextxy(x1+1050,y1," HOA DON "); 
	            setbkcolor(11);      
			  	gia_tri=xl_hoadon(dsnhanvien,tree,ktm3,hd,vt);
			  	goto batdau;
		       }
	  	     if (gia_tri==4) {
	  		    xuat_huongdan();	
	  		    setbkcolor(11); 	
				}
			 if (gia_tri==5) { 
	  		    xuat_thongtin();	
	  		    setbkcolor(11); 	
				}
	    }
	    if (gia_tri==-2)
		  {
		  	delete tree;
			delete dsnhanvien.nhanvien;
			delete mangvt.vt;
			closegraph();
			return  ; 
		   } 
	    if (kbhit())
			  {
			  	char c2=getch();
			  	int v2 =c2;
			  	if (v2==27)
			  	    {
			  	    	delete tree;
			  	    	delete dsnhanvien.nhanvien;
			  	    	closegraph();
						return  ; 
					  }
			  }
	} 
	
}

byte xl_nhanvien(DSNHANVIEN &dsnhanvien,int &ktm1)
{

	int slnhanvien =dsnhanvien.soluong-1;
    int x1=80,y1=10 , trangthai =1 ,sotrang =1 , sotrangtk =1, vi_tri3=0 ,vt_ht =-1,vt_truoc=-1 , gia_tri=0;;
    bool ktdem=false , kt2=false ;
    int *loc[max_slnhanvien];int n =0, dx01=0;
	int vi_tri2 ;
	xuat_nhapnv();
	char sx1[max_kt] = (""),s1[max_kt] = (""),s2[max_kt] = (""),s3[max_kt] = (""),stk[max_kt] = ("");
	while(1)
	   {
	   	delay(0.0001);
	   	int x2=mousex();
		int y2=mousey();
		xl_tthd(ktra(x2,y2));
		if (ktm1==3)
		    xl_x(x2,y2);
		if (ktm1==2 ||ktm1 ==3)
		{
		  int a= ktra(x2,y2);
		  if (a==23)
		   tomauxuong();
		  else if (a==24)
		    tomaulen();
		  if (a!=23)
		     tra_mauxuong();
		  if (a!=24)
		     tra_maulen();
		 }
		if (ktm1==2)
		{
		 if (trangthai==1)
		 {
		  if (x2>= 90 && x2<=1380&& y2>=300 )
		    	xl_tomau(dsnhanvien,y2,dsnhanvien.soluong,sotrang,vt_ht,vt_truoc);
		 else 
		 {
		 	if (vt_ht!=-1)
		     tomau_i(vt_ht,15,dsnhanvien.soluong,dsnhanvien.nhanvien[vt_ht]);
		    if (vt_truoc!=-1)
		     tomau_i(vt_truoc,15,dsnhanvien.soluong,dsnhanvien.nhanvien[vt_truoc]);
		    vt_ht=-1;
		    vt_truoc=-1;
		}
		}
		else if (trangthai==2)
		   {
		   	if (x2>= 90 && x2<=1380&& y2>=300 )
		    	xl_tomauloc(dsnhanvien,loc,n,y2,sotrangtk,vt_ht,vt_truoc);
		    else 
		    {
		 	if (vt_ht!=-1)
		     tomau_i(vt_ht,15,n,dsnhanvien.nhanvien[*loc[vt_ht]]);
		    if (vt_truoc!=-1)
		     tomau_i(vt_truoc,15,n,dsnhanvien.nhanvien[*loc[vt_truoc]]);
		    vt_ht=-1;
		    vt_truoc=-1;
		    }
		   }
		}
		if (ktm1!=0 &&kt2==false)
		     {
			    if (ktm1==1)  gia_tri=6;
				else if (ktm1==2 || ktm1 ==3) gia_tri=7; 
		        goto batdaunv;
		    }
		if (kbhit())
			  {
			  	char c2=getch();
			  	int v2 =c2;
			  	if (v2==27)
			  	    {
						return -2 ; 
					  }
			  }
	    if (ismouseclick(WM_LBUTTONDOWN))
	    {
	    	setfillstyle(1,15); 
	    	int x,y;
	  	      getmouseclick(WM_LBUTTONDOWN, x, y);
	  	      gia_tri=ktra(x,y,ktm1);
	  	       
	  	batdaunv:
	  		  delay(0.0001);
	  		  kt2=true;
	  		  char sx[max_kt] = ("");
	  		  switch( gia_tri)
	  		  {
	  		  	case 1: return 1; 
	  		  	case 3 : return 3;
	  		  	case 4:
	  		  		 xuat_nhapvt(); 
	  		         xuat_huongdan(); gia_tri=dx01; goto batdaunv;	break;
	  		    case 5:
	  		    	 xuat_nhapvt(); 
	  		         xuat_thongtin();gia_tri=dx01; goto batdaunv;  break;
	  		    case 6:
	  		        clear03();
	  	       		xuat_nhapnv(); 
			    	cincolor(-1,4,3);
	                outtextxy(340,70," THEM NHAN VIEN ");
	  	       	    xuat_tnv();
	  	       	    dsnhanvien.nhanvien[dsnhanvien.soluong] = new NHANVIEN;
				/*	cincolor(0,7,2);
	  	            outtextxy(602,200,dsnhanvien.nhanvien[dsnhanvien.soluong]->ho);
	  	            outtextxy(602,300,dsnhanvien.nhanvien[dsnhanvien.soluong]->ten);
	  	            outtextxy(602,500,dsnhanvien.nhanvien[dsnhanvien.soluong]->manv);
	  	            if (strcmp(dsnhanvien.nhanvien[dsnhanvien.soluong]->phai,"Nam")==0)
	  	                        {
	  	                        	 cincolor(0,4,2); outtextxy(700,400,nam);
			    	            cincolor(0,7,2); outtextxy(800,400,nu);
								  }
					else if (strcmp(dsnhanvien.nhanvien[dsnhanvien.soluong]->phai,"Nu")==0)
					             {
					             	cincolor(0,7,2); outtextxy(700,400,nam);
			    	            cincolor(0,4,2); outtextxy(800,400,nu);
								 } */
	  	       		dx01=6;
				    ktm1 =1; break;
	  		    
	  		    case 7:
				    clear03();
			    	xuat_nhapnv(); 
			    	cincolor(-1,4,3);
	                outtextxy(730,70,"   DANH SACH    ");
	                vien_04();
	                xuat_timnv();
	                xuat_indsnv(dsnhanvien.soluong,sotrang);
	                if (dsnhanvien.soluong>0)
	                {
	  	    		  xuat_dsnhanvien(dsnhanvien,sotrang);
	  	    		  xuat_sopt(dsnhanvien.soluong);
	  	    	    }
	  	    		cincolor(0,7,2);
	  	    		if (stk[0]!= '\0')  outtextxy(677,150,stk);
	  	    		trangthai=1;
	  	    		dx01=7;
				    ktm1 =2 ; break;	  		    	
				}
	  	      
	  	     switch (ktm1)
	  	     {
	  	       case 1:
	  	       	{              
	  	       	    if (gia_tri==10) {
			  	            xl_phim();
			  	            gia_tri=xl_ten(595,200,1000,220,0,max_honv,max_honv,sx);
			  	            barcolor(602,200,1000,220,7);
			  	            chuyen_cach(sx);
			  	            viet_hoa(sx);
			  	            cincolor(0,7,2);
			  	            outtextxy(602,199,sx);
			  	            strcpy(dsnhanvien.nhanvien[dsnhanvien.soluong]->ho,sx) ; 
			 	            if (gia_tri!=-1) goto batdaunv;
			              }
		              else if (gia_tri==11 || gia_tri==19)
		                  {
		       	            xl_phim();
		       	            gia_tri=xl_ten(595,300,1000,320,3,max_tennv,max_tennv,sx);
		       	            viet_hoa(sx);
		       	            barcolor(602,300,1000,320,7);
		       	            cincolor(0,7,2);
			  	            outtextxy(602,299,sx);
		       	            strcpy(dsnhanvien.nhanvien[dsnhanvien.soluong]->ten,sx) ;         
			  	            if (gia_tri!=-1) goto batdaunv;
			              }
			           else if (gia_tri==13 )
			            {
			  	          xl_phim();
			  	          auto_manv(dsnhanvien,sx);
			              gia_tri=xl_ten(595,500,1000,520,1,max_manv,max_manv,sx);
			              strcpy(dsnhanvien.nhanvien[dsnhanvien.soluong]->manv,sx) ; 
			  	          if (gia_tri!=-1) goto batdaunv;
			               }
			            else if (gia_tri==14)
			                {
			                	delete dsnhanvien.nhanvien[dsnhanvien.soluong];
			                	dsnhanvien.nhanvien[dsnhanvien.soluong] = new NHANVIEN;
			                	clear03();
                                xuat_tnv();
			                    xuat_dahuy();
			                }
			            else if (gia_tri==15)
			                 {
			                 	if (dsnhanvien.nhanvien[dsnhanvien.soluong]->ho[0]=='\0'||dsnhanvien.nhanvien[dsnhanvien.soluong]->ten[0]=='\0'||dsnhanvien.nhanvien[dsnhanvien.soluong]->phai[0]=='\0'||dsnhanvien.nhanvien[dsnhanvien.soluong]->manv[0]=='\0')
			                 	      xuat_themthanhcong("Thieu thong tin");
			                 	else if (kt_vitri(dsnhanvien,dsnhanvien.nhanvien[dsnhanvien.soluong]->manv) !=-1)
			                 	       xuat_themthanhcong("Ma nv da ton tai");
			                 	else 
			                 	{
			                 	clear03();
			                    xuat_tnv();
			                    xuat_themthanhcong("Them thanh cong");
			                    ghifile_nhanvien(dsnhanvien);
			                    dsnhanvien.soluong = dsnhanvien.soluong+1;
			                    dsnhanvien.nhanvien[dsnhanvien.soluong] = new NHANVIEN;
			                    xl_dsnhanvien(dsnhanvien);
				                 }
                			}
			          else if (gia_tri==16 )
			                 {
			                 	strcpy(dsnhanvien.nhanvien[dsnhanvien.soluong]->phai,nam) ;
			    	            cincolor(0,4,2); outtextxy(700,400,nam);
			    	            cincolor(0,7,2); outtextxy(800,400,nu);
				             }
			           else if (gia_tri==17)
			                 {
			                 	strcpy(dsnhanvien.nhanvien[dsnhanvien.soluong]->phai,nu) ;
			                 	cincolor(0,4,2); outtextxy(800,400,nu);
			    	            cincolor(0,7,2); outtextxy(700,400,nam);
				             }
						break;
					}
				 
	  	       
	  	    	case 2:
	  	    		
	  	    		if (gia_tri == 21)
	  	    		   {
	  	    		   	xl_phim();
	  	    		   	gia_tri=xl_ten(670,150,990,170,1,max_kytu,max_kytu,sx,ktm1);
	  	    		   	strcpy(stk,sx);
	  	    		   	if (gia_tri!= -1) goto batdaunv;
						 }
					else if (gia_tri == 22)                                // tim kiem
					    {
					    	delete loc;
	  	    	            *loc= new int[max_slnhanvien]; n=0;
					    	loc_danhsach(dsnhanvien , loc,n,stk);
					    	xuat_loc(dsnhanvien,loc,n);
					    	xuat_sopt(n);
					    
					    	trangthai =2;
					    	xuat_sotrang(sotrangtk,sotrangtk);
					    	if (n<16)
					    	{
					    	xoa_duoi(n,trangthai);
					        }
					    	cincolor(2,7,2);
					    	barcolor(1055,186,1149,212,4);
					    	barcolor(1057,188,1147,210,7);
	  	    	            outtextxy(1062,190,"Thoat");
	  	    	            vt_ht=-1;vt_truoc=-1;
						}
					else if (gia_tri==23 )                        //xuong
					   {
					   	if (trangthai==1)
					   	 {
					     if (sotrang>1)
					     {
					          sotrang = sotrang -1;
					     clear04();
					     xuat_indsnv(dsnhanvien.soluong,sotrang); 
	  	    		     xuat_dsnhanvien(dsnhanvien,sotrang);
	  	    		     xuat_sopt(dsnhanvien.soluong);
	  	    		     vt_ht=-1;vt_truoc=-1;
	  	    		       }
	  	    		   }  
					   }
					else if (gia_tri==24)                                    //len
					     {
					      if (trangthai==1)
					      {
					     if ((sotrang)*16 <dsnhanvien.soluong)
					       {
					          sotrang = sotrang + 1;
					     clear04();
					     xuat_indsnv(dsnhanvien.soluong,sotrang); 
					     xuat_dsnhanvien(dsnhanvien,sotrang);
	  	    		     xuat_sopt(dsnhanvien.soluong);
	  	    		     vt_ht=-1;vt_truoc=-1;
	  	    		       }
	  	    		   }
					   }
					 else if (gia_tri==25 && trangthai ==2)         // thoat
					    {
					     clear04();
					     barcolor(1055,186,1149,212,15);
					     xuat_indsnv(dsnhanvien.soluong,sotrang); 
	  	    		     xuat_dsnhanvien(dsnhanvien,sotrang);
	  	    		     xuat_sopt(dsnhanvien.soluong);
	  	    		     trangthai=1;
						}
					 else if (gia_tri==26)                                     // xoa
					    {
					    	if (trangthai==1)
					    	{ 
					    	int vtnv =vitri_xoanv(y,dsnhanvien.soluong,sotrang);
					    	if (vtnv!=-1)
					    	{
					    	delete_nv(dsnhanvien,vtnv);
					    	xuat_sopt(dsnhanvien.soluong);
					    	xuat_sotrang(dsnhanvien.soluong,sotrang);
					    	xuat_dsnhanvien(dsnhanvien,sotrang,vtnv);
					    	if ( dsnhanvien.soluong < sotrang*16 )
					    	     xoa_duoi(dsnhanvien.soluong%16,trangthai);
					    	vt_ht=-1;vt_truoc=-1 ;
					        }
					       }
					       if (trangthai==2)
					       {
					      	int vtnv =vitri_xoanv(y,n,sotrangtk);
					    	if (vtnv!=-1)
					    	{
					    	int a = *loc[vtnv];    
					    	delete_nv(dsnhanvien,a);
	  	    	            delete_ptloc(loc,vtnv,n);
					    	xuat_loc(dsnhanvien,loc,n,vtnv);
					    	xuat_sopt(n);
					    	xuat_sotrang(sotrangtk,sotrangtk);
					    	if ( n < sotrangtk*16 )
					    	     xoa_duoi(n%16,trangthai);
					    	vt_ht=-1;vt_truoc=-1 ;
					   
					       }  
						  }
						   reset_file(dsnhanvien);
					    }
					  else if (gia_tri==27)                            // sua
					       {
					        if (trangthai==1)
					    	{ 
					    	int vtnv =vitri_xoanv(y,dsnhanvien.soluong,sotrang);
					    	if (vtnv!=-1)
					    	  {
					    		    vi_tri2=vtnv;
					    	        xuat_suadsnv();
					    	        cincolor(0,15,2);
					    	        outtextxy(903,180,dsnhanvien.nhanvien[vi_tri2]->manv);
					    	        ktm1=3;;
							   }
						    }
						  else   if (trangthai==2)
					    	{ 
					    	int vtnv =vitri_xoanv(y,n,sotrangtk);
					    	if (vtnv!=-1)
					    	{
					    		     vi_tri2=*loc[vtnv];
					    		     vi_tri3=vtnv;
					    	         xuat_suadsnv();
					    	          cincolor(0,15,2);
					    	         outtextxy(903,180,dsnhanvien.nhanvien[vi_tri2]->manv);
					    	         ktm1=3;					       	
							   }
						}
					}
	  	    		break;
	  	    	case 3:   
	  	    	
			     	       cincolor(15,15,2);
			     	        outtextxy(1200,227,"Thieu thong tin!");
	  	       	         if (gia_tri==28 || gia_tri==34) {
			  	            xl_phim();
			  	            gia_tri=xl_ten(375,150,773,170,0,max_honv,max_honv,sx,ktm1);
			  	           // cout<<"gia_tri "<<gia_tri<<endl;
			  	            strcpy(s1,sx);
			 	            if (gia_tri!=-1) goto batdaunv;
			              }
		                 else if (gia_tri==29 || gia_tri==35)
		                   {
		       	            xl_phim();
		       	            gia_tri=xl_ten(895,150,1230,170,3,max_tennv,max_tennv,sx,ktm1);
		       	            strcpy(s2,sx) ;
			  	            if (gia_tri!=-1) goto batdaunv;
			                }
			              else if (gia_tri==30 )
			                {
			                	 strcpy(s3,nam) ;
			    	             cincolor(0,4,2); outtextxy(400,180,nam);
			    	             cincolor(0,7,2); outtextxy(480,180,nu);
				             }
			              else if (gia_tri==31)
			                    {
			                    	strcpy(s3,nu) ;
			    	               cincolor(0,7,2); outtextxy(400,180,nam);
			    	               cincolor(0,4,2); outtextxy(480,180,nu);
				                }
			               else if (gia_tri==32)
			                    {
			                    	barcolor(148,138,1352,222,15);
			     	                xuat_timnv();
			     	                ktm1=2;
			                        if (trangthai==2)
			                          {
			                               cincolor(2,7,2);
					    	               barcolor(1055,186,1149,212,4);
					                    	barcolor(1057,188,1147,210,7);
	  	    	                           outtextxy(1062,190,"Thoat");
									  }
			                      }
			               else if (gia_tri==33)
			                     {
			                     	if (s1[0]!='\0' && s2[0]!='\0' && s3[0]!='\0')
			                     	{	
									 cout<<s1<<endl<<s2<<endl<<s3;		                  
			                     	chuyen_cach(s1);
			  	                    viet_hoa(s1);
			  	                    viet_hoa(s2);
			                     	strcpy(dsnhanvien.nhanvien[vi_tri2]->ho,s1);
			                     	strcpy(dsnhanvien.nhanvien[vi_tri2]->ten,s2);
			                     	strcpy(dsnhanvien.nhanvien[vi_tri2]->phai,s3);			                     	
			                     	barcolor(148,138,1352,222,15);
			     	                xuat_timnv();
			     	                int x;
			     	                x = vi_tri2 % 16;
			     	                if (trangthai==1)
			     	                {
			     	                	if (dsnhanvien.soluong==1 && vi_tri2==0)
			     	                	      {
			     	                             	      	xuat_dsnhanvien(dsnhanvien,sotrang,vi_tri2);
											   }
										else
										{
			     	                    NHANVIEN *nv = new NHANVIEN ;
			                     	    nv =dsnhanvien.nhanvien[vi_tri2];
			                     	    delete_nv(dsnhanvien,vi_tri2);
			                     	    dsnhanvien.nhanvien[dsnhanvien.soluong] = new  NHANVIEN;
			                     	    *dsnhanvien.nhanvien[dsnhanvien.soluong] = *nv;
			                     	    dsnhanvien.soluong=dsnhanvien.soluong+1;
			                     	    xl_dsnhanvien(dsnhanvien);
			     	                    xuat_dsnhanvien(dsnhanvien,sotrang,vi_tri2);
			     	                   }
			     	                }
			     	                else if (trangthai==2)
			     	                    {
			     	                    	if (n==1 && vi_tri2==0)
			     	                	      {
			     	                             	      	tomau_i(0,15,n,dsnhanvien.nhanvien[vi_tri2]);
			     	                             	      	cincolor(2,7,2);
					    	                                barcolor(1055,186,1149,212,4);
					    	                                barcolor(1057,188,1147,210,7);
	  	    	                                            outtextxy(1062,190,"Thoat");
	  	    	                                           // cout<<"trang thai :"<<trangthai;
											   }
											else
											{
			     	                            char s12[max_kt];
			     	                            strcpy(s12,dsnhanvien.nhanvien[vi_tri2]->manv);
			     	                            x =vi_tri3%16;
			     	                            tomau_i(x,15,n,dsnhanvien.nhanvien[vi_tri2]);
			     	                            cincolor(2,7,2);
					    	                    barcolor(1055,186,1149,212,4);
					    	                    barcolor(1057,188,1147,210,7);
	  	    	                                outtextxy(1062,190,"Thoat");
	  	    	                                NHANVIEN *nv = new NHANVIEN ;
			                     	            nv =dsnhanvien.nhanvien[vi_tri2];
			                     	            delete_nv(dsnhanvien,vi_tri2);
			                     	            dsnhanvien.nhanvien[dsnhanvien.soluong] = new  NHANVIEN;
			                     	            *dsnhanvien.nhanvien[dsnhanvien.soluong] = *nv;
			                     	            dsnhanvien.soluong=dsnhanvien.soluong+1;
			                     	            xl_dsnhanvien(dsnhanvien);
			                     	            *loc[vi_tri3] = kt_vitri(dsnhanvien,s12);
											}
										}
			     	                strcpy(s1,"") ;strcpy(s2,"") ;strcpy(s3,"") ;
			     	                ktm1=2;
			     	                reset_file(dsnhanvien);
			     	               }
			     	               else
			     	                 {
			     	                 	cincolor(4,15,2);
			     	                 	outtextxy(1200,227,"Thieu thong tin!");
									  }
									
			                     }  	               
			            break;
			}
			
	  	 }
	}
}
byte xl_vattu(LISTVT &tree,MANG_VT &mangvt, int &ktm2)                            
{
    int x1=80,y1=10 , trangthai =1 ,sotrang =1 , sotrangtk =1, vi_tri3=0 ,f; bool ktdem =false , kt2=false;
    int vt_ht=-1, vt_truoc = -1  ,gia_tri=0;
    int *loc[MAXVT];int n =0 , dx01 =0;
	int vi_tri2 ;
	VatTu vt; vt.SLT=-1;
	xuat_nhapvt();
	char sx1[max_kt] = (""),s1[max_kt] = (""),s2[max_kt] = (""),s3[max_kt] = (""),stk[max_kt] = ("");
	while(1)
	   {
	   	delay(0.0001);
	   	int x2=mousex();
		int y2=mousey();
		xl_tthd(ktra(x2,y2));
		if (ktm2==3)
		    xl_x(x2,y2);
		if (ktm2==2 ||ktm2 ==3)
		{
		    int a= ktra(x2,y2);
		    if (a==23)
		          tomauxuong();
		    else if (a==24)
		          tomaulen();
		    if (a!=23)
		            tra_mauxuong();
		    if (a!=24)
		           tra_maulen();
		}
		if (ktm2==2 )
		{
		 if (trangthai==1)
		 {
		   if (x2>= 90 && x2<=1380&& y2>=300 )
		    	xl_tomauvt(mangvt,y2,sotrang,vt_ht,vt_truoc);
		   else 
		     {
		 	     if (vt_ht!=-1)
		               tomauvt_i(vt_ht,15,mangvt.sl,mangvt.vt[vt_ht]);
		         if (vt_truoc!=-1)
		                  tomauvt_i(vt_truoc,15,mangvt.sl,mangvt.vt[vt_truoc]);
		         vt_ht=-1;
		         vt_truoc=-1;
		     }
		 }
		else if (trangthai==2)
		   {
		   	if (x2>= 90 && x2<=1380&& y2>=300 )
		   	
		    	xl_tomauvtloc(mangvt,loc,n,y2,sotrangtk,vt_ht,vt_truoc);
		    else 
		     {
		 	    if (vt_ht!=-1)
		            tomauvt_i(vt_ht,15,n,mangvt.vt[*loc[vt_ht]]);
		        if (vt_truoc!=-1)
		            tomauvt_i(vt_truoc,15,n,mangvt.vt[*loc[vt_truoc]]);
		        vt_ht=-1;
		        vt_truoc=-1;
		      }
		   }
		}
		if (ktm2!=0 &&kt2==false)
		     {
			    if (ktm2==1)  gia_tri=6;
				else if (ktm2==2 ) gia_tri=7; 
		        goto batdauvt;
		    }
		    
		if (kbhit())
			  {
			  	char c2=getch();
			  	int v2 =c2;
			  	if (v2==27)
			  	    {
						return -2 ; 
					  }
			  }
	    if (ismouseclick(WM_LBUTTONDOWN))
	    {
	    	  setfillstyle(1,15); 
	    	  int x,y;
	  	      getmouseclick(WM_LBUTTONDOWN, x, y);
	  	      gia_tri=ktra(x,y,ktm2);
	  	       
	  	batdauvt:
	  		  delay(0.0001);
	  		  kt2=true;
	  		  char sx[max_kt] = ("");
	  		  switch( gia_tri)
	  		  {
	  		  	case 2:		 return 2; 
	  		  	case 3 : return 3;
	  		  	case 4:
	  		  		 xuat_nhapvt(); 
	  		         xuat_huongdan(); gia_tri=dx01;goto batdauvt;	break;
	  		    case 5:
	  		    	 xuat_nhapvt(); 
	  		         xuat_thongtin();gia_tri=dx01;goto batdauvt;  break;
	  		    case 6:
	  		          clear03();
	  	       		  xuat_nhapvt(); 
			    	  cincolor(-1,4,3);
	                  outtextxy(340,70,"  THEM VAT TU   ");
	  	       		  xuat_tvt(); 
	  	       		  cincolor(0,7,2);
	  	              outtextxy(602,200,vt.TenVT);
	  	              if (vt.SLT!=-1 && vt.SLT!=0) outtextxy(602,300,tro_int(vt.SLT));
	  	              outtextxy(602,400,vt.DVT);
	  	              outtextxy(602,500,vt.MaVT);
	  	       		  dx01 =6;
				      ktm2 =1; break;
	  		    case 7:
				    clear03();
			    	xuat_nhapvt(); 
			    	cincolor(-1,4,3);
	                outtextxy(730,70,"   DANH SACH    ");
	                vien_04();
	                xuat_timvt();
	                xuat_indsvt(mangvt.sl,sotrang);
	                if (mangvt.sl>0)
	                {
	                xuat_dsvt(mangvt,sotrang);
	                xuat_sopt(mangvt.sl);
	                }
	                cincolor(0,7,2);
	  	    		if (stk[0]!= '\0')  outtextxy(677,150,stk);
	  	    		trangthai=1;
	  	    		dx01=7;
				    ktm2 =2 ; break;	  		    	
				}
	  	      
	  	     switch (ktm2)
	  	     {
	  	       case 1:
	  	       	{
	  	               cincolor(15,15,2);
	                   outtextxy(630,640,"Ma vat tu da ton tai!");
	  	       	       if (gia_tri==10) {                   // ten
			  	            xl_phim();
			  	            gia_tri=xl_ten(595,200,1000,220,0,max_kytu,max_kytu,sx);
			  	             barcolor(602,200,1000,220,7);
			  	            chuyen_cach(sx);
			  	            viet_hoa(sx);
			  	            cincolor(0,7,2);
			  	            outtextxy(602,199,sx);
			  	            strcpy(vt.TenVT,sx);
			 	            if (gia_tri!=-1) goto batdauvt;
			              } 
		              else if (gia_tri==11 )                   // 
		                  {
		       	              xl_phim();
		       	              gia_tri=xl_ten(595,300,1000,320,2,max_slt,max_slt,sx);
		       	              vt.SLT = char_long(sx);
			  	              if (gia_tri!=-1) goto batdauvt;
			              }
			         else if (gia_tri==12 || gia_tri==16 || gia_tri==17 )         // don vi tinh
		                  {
		       	             xl_phim();
		       	             gia_tri=xl_ten(595,400,1000,420,0,max_dvt,max_dvt,sx);
		       	             viet_hoa(sx);
		       	             barcolor(602,400,1000,420,7);
		       	             cincolor(0,7,2);
			  	             outtextxy(602,399,sx);
		       	             strcpy(vt.DVT,sx);
			  	             if (gia_tri!=-1) goto batdauvt;
			              }
			           else if (gia_tri==13 )                                 // ma vt
			              {	
			  	             xl_phim();
			  	             auto_mavt(sx,tree,mangvt.sl);
			                 gia_tri=xl_ten(595,500,1000,520,1,sl_kytu_mavt,sl_kytu_mavt,sx);
			                 strcpy(vt.MaVT,sx);
			  	             if (gia_tri!=-1) goto batdauvt;
			               }
			            else if (gia_tri==14)
			                {
			                	  clear03();
                                  xuat_tvt(); 
			                      xuat_dahuy();
			                      strcpy(vt.DVT,"");strcpy(vt.MaVT,"");strcpy(vt.TenVT,"");
			                      vt.SLT=-1;
			                }
			            else if (gia_tri==15 )
			                 {
			                 	bool kt =false;
			                 	check_mavt(tree,vt.MaVT,kt);
			                 	if (vt.DVT[0]!='\0' && vt.MaVT[0]!='\0' && vt.TenVT[0]!='\0' && vt.SLT >0  && kt==false)
			                     {
			                     	xuat_tvt(); 
							 	    xuat_themthanhcong("Them thanh cong");
							 	    InsertVatTu(tree,vt,mangvt);
							 	    ghifile_vattu(vt);
							 	    strcpy(vt.DVT,"");strcpy(vt.MaVT,"");strcpy(vt.TenVT,"");vt.SLT=-1;
			                    }
			                    else if(kt==true)
			                         {
			                         	  cincolor(4,15,2);
	                                      outtextxy(630,640,"Ma vat tu da ton tai!");
									 }
								else 
								     {
								     	xuat_themthanhcong("Thieu thong tin!");
									 }
                			}
						break;
					}
				      
	  	    	case 2:
	  	    		
	  	    	    ktdem=false;
	  	    		if (gia_tri == 21)                       // nhap tk
	  	    		   {
	  	    		   	xl_phim();
	  	    		   	gia_tri=xl_ten(670,150,990,170,4,max_kytu,max_kytu,sx,ktm2);
	  	    		   	chuyen_cach(sx);
			  	        viet_hoa(sx);
	  	    		   	strcpy(stk,sx);
	  	    		   	if (gia_tri!= -1) goto batdauvt;
						 }
					else if (gia_tri == 22)                      /// tim kiem
					    {
					        delete loc;
	  	    	            *loc= new int[MAXVT]; n=0;
					    	loc_danhsachvt(mangvt , loc,n,stk);
					    	xuat_locvt(mangvt,loc,n);
					    	xuat_sopt(n);
					    	trangthai =2;
					    	xuat_sotrang(sotrangtk,sotrangtk);
					    	if (n<16)
					    	{
					    	      xoa_duoi(n,trangthai);
					        }
					    	cincolor(2,7,2);
					    	barcolor(1055,186,1149,212,4);
					    	barcolor(1057,188,1147,210,7);
	  	    	            outtextxy(1062,190,"Thoat");
	  	    	            vt_ht=-1;vt_truoc=-1;	    
					    	
						}
					else if (gia_tri==23 )                        //xuong
					   {
					   	if (trangthai==1)
					   	 {
					     if (sotrang>1)
					     {
					          sotrang = sotrang -1;
					          clear04();
					          xuat_indsvt(mangvt.sl,sotrang) ;
	  	    		          xuat_dsvt(mangvt,sotrang);
	  	    		          xuat_sopt(mangvt.sl);
	  	    		       }
	  	    		     }  
					   }
					else if (gia_tri==24)                                    //len
					     {
					      if (trangthai==1)
					      {
					      if ((sotrang)*16 <mangvt.sl)
					       {
					           sotrang = sotrang + 1;
					           clear04();
					           xuat_indsvt(mangvt.sl,sotrang) ;
	  	    		           xuat_dsvt(mangvt,sotrang);
	  	    		           xuat_sopt(mangvt.sl);
	  	    		       }
	  	    		      }
					     } 
					 else if (gia_tri==25 && trangthai ==2)         // thoat
					    {
					     clear04();
					     barcolor(1055,186,1149,212,15);
					     xuat_indsvt(mangvt.sl,sotrang);
	                     xuat_dsvt(mangvt,sotrang);
	                     xuat_sopt(mangvt.sl);
	  	    		     trangthai=1;
						}
					 else if (gia_tri==26)                                     // xoa
					    {
					     if (trangthai==1)
					    	{ 
					    	int vtnv =vitri_xoavt(y,mangvt.sl,sotrang);
					    	if (vtnv!=-1)
					    	{
					    		VatTu x3 = *mangvt.vt[vtnv];
					    	    RemoveVatTu(tree,x3);
					    	    for (int v = vtnv;v<mangvt.sl-1;v++)
					    	          mangvt.vt[v] = mangvt.vt[v+1];
			                    mangvt.sl = mangvt.sl - 1;
	                            xuat_dsvt(mangvt,sotrang,vtnv);
	                            xuat_sotrang(mangvt.sl,sotrang);
	                            xuat_sopt(mangvt.sl);
				    	        if ( mangvt.sl < sotrang*16 )
					    	            xoa_duoi(mangvt.sl%16,trangthai);
					            vt_ht=-1;vt_truoc=-1 ;
					        }
					       }
					       if (trangthai==2)
					       {
					      	int vtnv =vitri_xoanv(y,n,sotrangtk);
					    	if (vtnv!=-1)
					    	{
					    		int a = *loc[vtnv];
					    	    VatTu x3 = *mangvt.vt[a];
					    	    RemoveVatTu(tree,x3);
                                for (int v = a;v<mangvt.sl-1;v++)
					    	         mangvt.vt[v] = mangvt.vt[v+1];
	  	    	                delete_ptloc(loc,vtnv,n);
					    	    xuat_locvt(mangvt,loc,n,3);
					    	    xuat_sopt(n);
					    	    xuat_sotrang(sotrangtk,sotrangtk);
					    	    if ( n < sotrangtk*16 )
					    	         xoa_duoi(n%16,trangthai);
					    	    vt_ht=-1;vt_truoc=-1 ;
					        }
					       }
					        reset_filevt(tree);
					    }
					  else if (gia_tri==27)                              // sua
					    {
					      if (trangthai==1)
					    	{ 
					    	int vtnv =vitri_xoavt(y,mangvt.sl,sotrang);
					    	if (vtnv!=-1)
					    	 {
					    		    vi_tri2=vtnv;
					    	        xuat_suavt();
					    	        cincolor(0,15,2);
					    	        outtextxy(385,180,tro_int(mangvt.vt[vi_tri2]->SLT));
					    	        outtextxy(965,180,mangvt.vt[vi_tri2]->MaVT);
					    	        ktm2=3;				       	
							   }
					         }
					      else  if (trangthai==2)
					    	{ 
					    	int vtnv =vitri_xoavt(y,n,sotrangtk);
					    	if (vtnv!=-1)
					    	  {
					    		     vi_tri2=*loc[vtnv];
					    		     vi_tri3=vtnv;
					    	         xuat_suavt();
					    	         cincolor(0,15,2);
					    	         outtextxy(385,180,tro_int(mangvt.vt[vi_tri2]->SLT));
					    	         outtextxy(965,180,mangvt.vt[vi_tri2]->MaVT);
					    	         ktm2=3;
							   }
					        }
			     	     }  
	  	    		break;
	  	    	case 3:       
				  {                                                   // sua
	  	    	         cincolor(15,15,2);
			     	     outtextxy(1200,227,"Thieu thong tin");
	  	       	         if (gia_tri==34) {
			  	            xl_phim();
			  	            gia_tri=xl_ten(375,150,723,170,0,max_kytu,max_kytu,sx,ktm2);   
			  	            strcpy(s1,sx);
			 	            if (gia_tri!=-1) goto batdauvt;
			              }
		                 else if ( gia_tri==35)
		                  {
		       	            xl_phim();
		       	            gia_tri=xl_ten(955,150,1240,170,0,max_dvt,max_dvt,sx,ktm2);
		       	            strcpy(s2,sx) ;
			  	            if (gia_tri!=-1) goto batdauvt;
			              }
			            else if (gia_tri==32)
			                    {
			                    	barcolor(148,138,1352,222,15);
			     	                  xuat_timvt();
			     	                  ktm2=2;
			                          if (trangthai==2)
			                          {
			                                cincolor(2,7,2);
					    	                barcolor(1055,186,1149,212,4);
					                    	barcolor(1057,188,1147,210,7);
	  	    	                            outtextxy(1062,190,"Thoat");
									  }
			                      }
			               else if (gia_tri==33)
			                     {
			                     	if (s1[0]!='\0' && s2[0]!='\0')
			                     	{
			                     	chuyen_cach(s1);
			  	                    viet_hoa(s1);
			  	                    chuyen_cach(s2);
			  	                    viet_hoa(s2);
			                     	strcpy(mangvt.vt[vi_tri2]->TenVT,s1);
			                     	strcpy(mangvt.vt[vi_tri2]->DVT,s2);                           
			                     	barcolor(148,138,1352,222,15);
			     	                xuat_timvt();
			     	                int x;
			     	                x = vi_tri2 % 16;
			     	                ktm2=2;
			     	                if (trangthai==1)
			     	                {
			     	                	         VatTu *vt = mangvt.vt[vi_tri2];
			     	                	         delete_mangvt(mangvt,vi_tri2);
			     	                	         them_mangvt(mangvt,vt);
			     	                	         xuat_dsvt(mangvt,sotrang,vi_tri2);
			     	                }
			     	                else if (trangthai==2)
			     	                             {
			     	                             	 char s12[50]; strcpy(s12,mangvt.vt[vi_tri2]->MaVT);
			     	                             	 x =vi_tri3%16;
			     	                             	 tomauvt_i(x,15,n,mangvt.vt[vi_tri2]);
			     	                             	 cincolor(2,7,2);
					    	                         barcolor(1055,186,1149,212,4);
					    	                         barcolor(1057,188,1147,210,7);
	  	    	                                     outtextxy(1062,190,"Thoat");
	  	    	                                     VatTu *vt = mangvt.vt[vi_tri2];
			     	                	             delete_mangvt(mangvt,vi_tri2);
			     	                	             them_mangvt(mangvt,vt);
			     	                	             int x12 = vitri_vt(mangvt,s12);
			     	                	             if (x12!=-1)  *loc[vi_tri3] =x12;
												  }
									
			     	                  strcpy(s1,"") ;strcpy(s2,"") ;strcpy(s3,"") ;
			     	                  ktm2=2;
			     	                  reset_filevt(tree);
			     	               }
			     	               else
			     	                 {
			     	                 	cincolor(4,15,2);
			     	                 	outtextxy(1200,227,"Thieu thong tin");
									  }
									
			                     }
							
			            break;
			        }
			}
			
	  	 }
	}
}
byte xl_hoadon(DSNHANVIEN &dsnhanvien ,LISTVT &tree,int &ktm3, notehd *&hd,int &vt )
{
	int x1=80,y1=10;
	long long tongt =0 , tongx=0;
	CT_HOADON fs;
	THOIGIAN d,c;
	c.nam=0;c.ngay=0 ;c.thang=0;
	d.nam=0;d.ngay=0 ;d.thang=0;
	int  sl = hd->hoadon.dscthd.soluong , gia_tri , vt02=0,vt01=0 , dx01=0 , vty1, sotrang , dem;
	char sx1[max_kt] =(""),sx2[max_kt]=(""),sx3[max_kt]=(""),sx4[max_kt]=(""),sx5[max_kt]=("") ;
	bool kthd=false , kttk =false , kt2=false , danhdauhd=false , dx02=false , dx03=false ,dxloai=false;
	xuat_tthd();
	if (sl!=0)
	   {
	   	for (int i=0;i<sl;i++)
	   	    tongt =tongt + hd->hoadon.dscthd.ct_hoadon[i].dongia*hd->hoadon.dscthd.ct_hoadon[i].soluong*(100+hd->hoadon.dscthd.ct_hoadon[i].vat)/100;
	   }
	while(1)
	   {
	   	delay(0.0001);
	   	int x2=mousex();
		int y2=mousey();
		xl_tthd(ktra01(x2,y2));
        if (ktm3 ==2 )
          {
          	if (danhdauhd==true)
          	{
          	if (ktrahd(x2,y2) ==26)
          	   {
          	   	cincolor(15,4,3);
          	   	outtextxy(1445,120,"X");
				 }
			else 
			     {
          	   	cincolor(15,7,3);
          	   	outtextxy(1445,120,"X");
				 }
		    }
		  }
		else 
		   xl_ktm3(ktm3,vt01,vt02);   
		if (ktm3!=0 &&kt2==false)
		     {
			    if (ktm3==1 || ktm3==4)  gia_tri=6;
				else if (ktm3==2) gia_tri=7;
				else if (ktm3==3 )  gia_tri=8; 
		        goto batdauhd3;
		    }
		    
		if (kbhit())
			  {
			  	char c2=getch();
			  	int v2 =c2;
			  	if (v2==27)
			  	    {
						return -2 ; 
					  }
			  }
	    if (ismouseclick(WM_LBUTTONDOWN))
	    {
	    	int x,y;
	  	      getmouseclick(WM_LBUTTONDOWN, x, y);
	  	      gia_tri=ktrahd(x,y,ktm3);
	  	    batdauhd3:
	  	    	kt2=true;
	  	    	bool kttt=false;
	  	    	char sx[max_kt] = ("");
	  	     switch (gia_tri)
	  	       {
	  	       	  case 1 :
	  	       	  	   hd->hoadon.dscthd.soluong =sl;
	  	       	  	  return 1;break;
	  	       	  case 2:
	  	       	  	    hd->hoadon.dscthd.soluong =sl;
	  	       	   	   return 2;break;
	  	       	  case 4:
	  	       	  	   xuat_tthd(); 
	  		         xuat_huongdan(); gia_tri=dx01; goto batdauhd3;	break;
	  	       	  case 5:
	  	       	  	  xuat_tthd(); 
	  		         xuat_thongtin();gia_tri=dx01; goto batdauhd3;break;
	  	       	  case 6:
	  	       	  	    clear03();
	  	       	  	    xuat_tthd();
	  	       	  	    cincolor(2,4,3);outtextxy(404,70," TAO HD ");
				    	vien_03();
					    xuat_taohd(); 
					    xuat_themvattu();
					    xuat_bangvattu();
					    if (vt!=-1)
					      {
					   		cincolor(0,7,2);
					   	     outtextxy(142,130,dsnhanvien.nhanvien[vt]->manv);
					      }
					    cincolor(0,7,2);
					   	if (hd->hoadon.sohd[0] != '\0')      outtextxy(477,130,hd->hoadon.sohd);
					   	if (strcmp(hd->hoadon.loai,"N")==0)
					   	     {
					   	    int x =40;y=130;
					   	    barcolor(x+865,130,x+890,150,4);
					   	    cincolor(0,4,2);
	                        outtextxy(x+870,y,"N");
	                        barcolor(x+890,130,x+915,150,7);
	                        cincolor(0,7,2);
							outtextxy(x+895,y,"X");
	                        cincolor(0,0,-1);
	                        line(x+890,131,x+890,149);	
			        			 }
						if (strcmp(hd->hoadon.loai,"X")==0)
						         {
						         	int x =40;y=130;
					   	            barcolor(x+865,130,x+890,150,7);
					   	            cincolor(0,7,2);
	                                outtextxy(x+870,y,"N");
	                                barcolor(x+890,130,x+915,150,4);
	                                cincolor(0,4,2);
							        outtextxy(x+895,y,"X");
	                                cincolor(0,0,-1);
	                                line(x+890,131,x+890,149);
								 }             
					    cincolor(0,7,2);
						if (hd->hoadon.thoigian.ngay>0) outtextxy(1062,130,tro_int(hd->hoadon.thoigian.ngay)); 
						if (hd->hoadon.thoigian.thang>0) outtextxy(1130,130,tro_int(hd->hoadon.thoigian.thang));
						if (hd->hoadon.thoigian.nam>0) outtextxy(1197,130,tro_int(hd->hoadon.thoigian.nam));
					    xulyhd(hd,sl,tree);					   
					    danhdauhd =false;
					    dx01 =6;
					    ktm3=1; break;
	              case 7:
	              	   clear03();
	              	   xuat_tthd();
	  	       	  	   cincolor(2,4,3);
	                   outtextxy(602,70," IN HD  ");
					   xuat_inhd(); 
					   strcpy(sx5,"");
					   danhdauhd=false;
					   dx01=7;
					   ktm3=2; break;
	              case 8:
	              	   clear03();
	              	   xuat_tthd();
	  	       	  	   cincolor(2,4,3);
	                   outtextxy(800,70,"THONG KE");
	                   xuat_bangtracuu();
	                   if (d.ngay>0) outtextxy(87,330,tro_int(d.ngay));
	                   if (d.thang>0) outtextxy(159,330,tro_int(d.thang));
	                   if (d.nam>0) outtextxy(227,330,tro_int(d.nam));
	                   if (c.ngay>0) outtextxy(87,430,tro_int(c.ngay));
	                   if (c.thang>0) outtextxy(159,430,tro_int(c.thang));
	                   if (c.nam>0) outtextxy(227,430,tro_int(c.nam));
	                   danhdauhd=false;
	                   dx01=8;
					   ktm3=3 ;break;
				 }
			switch(ktm3)
			{
				case 1:
					  barcolor(1300,120,1465,160,15);
					  if (gia_tri==41)              // sua
					     {
					     	vty1 = suavt_hd(hd,y,sl);
					     	if (vty1!=-1)
					     	     {
					     	     	ktm3=4;
					     	     	fs = hd->hoadon.dscthd.ct_hoadon[vty1];
					     	     	tongx = fs.soluong;
					     	     	goto batdauhd3 ;
								  }
						 }
						else if (gia_tri==40)
						    {
						    	vty1 = (y-238)/25;
					     	    if (vty1 < sl)
					     	     {
					     	     	barcolor(32,238+(sl-1)*25,1469,240+(sl-1)*25+20,15);
	                                barcolor(1110,743,1407,765,15);
	                                setcolor(9); 
	                                line(30,230,1470,230);	
	                                line(210,200,210,740);
                                    line(485,200,485,740);
	                                line(650,200,650,740);
	                                line(845,200,845,740);
	                                line(1035,200,1035,770);
	                                line(1095,200,1095,740);	
	                                line (1410,200,1410,740);
	                                int xi =1;
					                if (strcmp(hd->hoadon.loai,"X")==0)
					                        xi = -1;
					                sua_slt(tree,hd->hoadon.dscthd.ct_hoadon[vty1].mavt,hd->hoadon.dscthd.ct_hoadon[vty1].soluong,xi*-1);
					     	     	for (int v=vty1;v<sl;v++)
					     	     	         hd->hoadon.dscthd.ct_hoadon[v] = hd->hoadon.dscthd.ct_hoadon[v+1];
					     	     	long long tongt2=0;
					     	     	for (int v=0;v<sl-1;v++)
					     	     	     {
					     	     	     	   VatTu x;
					   	                       CheckMaVT(tree,hd->hoadon.dscthd.ct_hoadon[v].mavt,x);
					   	                       xuat_vthd(hd,v,x,tongt2);
										   }
									tongt = tongt2;
									strcpy(hd->hoadon.dscthd.ct_hoadon[sl].mavt,"");
	                                hd->hoadon.dscthd.ct_hoadon[sl].dongia=-1;
	                                hd->hoadon.dscthd.ct_hoadon[sl].soluong=-1;
	                                hd->hoadon.dscthd.ct_hoadon[sl].vat =-1;
									sl=sl-1;
									reset_filevt(tree);
								  }
							}
					  else if (gia_tri==22)
					  {
					  	int xi =1;
					    if (strcmp(hd->hoadon.loai,"X")==0)
					              xi = -1;
					    for (int v=0;v<sl;v++)
					           {
					           	sua_slt(tree,hd->hoadon.dscthd.ct_hoadon[v].mavt,hd->hoadon.dscthd.ct_hoadon[v].soluong,-1*xi);
							   }
					  	delete hd;
					  	hd = khoitaonote();
					  	hd->hoadon.dscthd.soluong=0;
                        hd->hoadon.dscthd.ct_hoadon[0].dongia=-1;
	                    hd->hoadon.dscthd.ct_hoadon[0].soluong=-1;
	                    hd->hoadon.dscthd.ct_hoadon[0].vat=0;
					  	clear03();
					  	vien_03();
					  	xuat_taohd(); 
					    xuat_themvattu();
					    xuat_bangvattu();
					    sl=0; dxloai =false;
					    vt01=0;vt=-1;
					    tongt=0;   
					  } 
					else if (gia_tri==23)
					  {
					  	if (sl!= 0 && vt!=-1 && kt_sohd(dsnhanvien,hd->hoadon.sohd)==false && CheckNgay(hd->hoadon.thoigian.ngay,hd->hoadon.thoigian.thang,hd->hoadon.thoigian.nam) ==true&&hd->hoadon.thoigian.nam>=1900)
					  	 {
					  	    clear03();
					  		vien_03();
					  	    xuat_taohd(); 
					        xuat_themvattu();
					        xuat_bangvattu();
					        hd->hoadon.dscthd.soluong =sl;
					        themdau(dsnhanvien,vt,hd);
					        ghifile_hoadon(dsnhanvien,vt);
					        int xi =1;
					        if (strcmp(hd->hoadon.loai,"X")==0)
					              xi = -1;
					       /* for (int v=0;v<sl;v++)
					           {
					           	sua_slt(tree,hd->hoadon.dscthd.ct_hoadon[v].mavt,hd->hoadon.dscthd.ct_hoadon[v].soluong,xi);
							   }*/
							reset_filevt(tree);
					        hd = khoitaonote();
						    hd->hoadon.dscthd.soluong=0;
                            hd->hoadon.dscthd.ct_hoadon[0].dongia=-1;
	                        hd->hoadon.dscthd.ct_hoadon[0].soluong=-1;
	                        hd->hoadon.dscthd.ct_hoadon[0].vat=0;
					        sl=0; dxloai =false;
					        vt01=0;
					        vt=-1;
					        tongt=0;
					    }
					    else 
					     {
					     	 if (vt==-1)
							        {
							        	cincolor(4,15,2);
					       	            outtextxy(1350,120,"Loi");
					       	            outtextxy(1320,140,"nhan vien");
									}
					     	else if(kt_sohd(dsnhanvien,hd->hoadon.sohd) ==true|| hd->hoadon.sohd[0] =='\0')
							        {
							        	cincolor(4,15,2);
					       	            outtextxy(1350,120,"Loi");
					       	            outtextxy(1305,140,"so hoa don");
									}
							else if (CheckNgay(hd->hoadon.thoigian.ngay,hd->hoadon.thoigian.thang,hd->hoadon.thoigian.nam) ==false || hd->hoadon.thoigian.nam<1900)
							        {
							        	cincolor(4,15,2);
					       	            outtextxy(1360,120,"Loi");
					       	            outtextxy(1315,140,"Thoi gian");
									}
							else if (sl==0)
							      {
							      	cincolor(4,15,2);
					       	        outtextxy(1320,120,"Chua co");
					       	        outtextxy(1320,140,"vat tu!");
								  }
							cincolor(7,7,2);
						 }
     	   	        }
					 if (gia_tri==9)                                             // ma nv
					    {
					    	xl_phim();
			  	            gia_tri=xl_nhaphd(135,130,367,150,0,13,13,sx);
			  	            vt = kt_vitri(dsnhanvien,sx);
			 	            if (gia_tri!=-1) goto batdauhd3;				    	
						}
					 else if (gia_tri==10)
					    {
					    	xl_phim();
					    	gia_tri= xl_nhaphd(470,130,815,150,0,max_cthd,max_cthd,sx);
					    	 strcpy(hd->hoadon.sohd,sx);
					    	if (gia_tri!=-1) goto batdauhd3;
						}
					 else if (gia_tri==11)
					   {
					   	 if (sl==0)
					   	  {
					   	    int x =40;y=130;
					   	    barcolor(x+865,130,x+890,150,4);
					   	    cincolor(0,4,2);
	                        outtextxy(x+870,y,"N");
	                        barcolor(x+890,130,x+915,150,7);
	                        cincolor(0,7,2);
							outtextxy(x+895,y,"X");
	                        cincolor(0,0,-1);
	                        line(x+890,131,x+890,149);
	                        strcpy(hd->hoadon.loai,"N");
	                      }
	                      else
	                          {
	                          	cincolor(4,15,2);
					       	    outtextxy(1320,120,"Khong the");
					       	    outtextxy(1320,140,"thay doi!");
							  }
					   }
					   else if (gia_tri==12)
					   {
					   	 if (dxloai ==false)
					   	  {
					   	    int x =40;y=130;
					   	    barcolor(x+865,130,x+890,150,7);
					   	    cincolor(0,7,2);
	                        outtextxy(x+870,y,"N");
	                        barcolor(x+890,130,x+915,150,4);
	                        cincolor(0,4,2);
							outtextxy(x+895,y,"X");
	                        cincolor(0,0,-1);
	                        line(x+890,131,x+890,149);
	                        strcpy(hd->hoadon.loai,"X");
	                      }
	                     else
	                      {
	                      	cincolor(4,15,2);
					       	outtextxy(1320,120,"Khong the");
					       	outtextxy(1320,140,"thay doi!");
						  }
					   }
					else if (gia_tri==13)
					  {
					  	xl_phim();
					  	time_t baygio = time(0); 
                        tm *ltm = localtime(&baygio);
                        coppy(sx,int_string(ltm->tm_mday));
					  	gia_tri= xl_nhaphd(1055,130,1112,150,1,2,2,sx);
					  	hd->hoadon.thoigian.ngay = char_int(sx);
					  	if (gia_tri!=-1) goto batdauhd3;
					  }
					else if (gia_tri==14)
					  {
					  	xl_phim();
					  	time_t baygio = time(0); 
                        tm *ltm = localtime(&baygio);
                        coppy(sx,int_string(1 + ltm->tm_mon));
					  	gia_tri= xl_nhaphd(1123,130,1178,150,1,2,2,sx);
					  	hd->hoadon.thoigian.thang = char_int(sx);
					  	if (gia_tri!=-1) goto batdauhd3;
					  }
					else if (gia_tri==15)
					  {
					  	xl_phim();
					  	time_t baygio = time(0); 
                        tm *ltm = localtime(&baygio);
                        coppy(sx,int_string(1900 + ltm->tm_year));
					  	gia_tri= xl_nhaphd(1190,130,1283,150,1,4,4,sx);
					  	hd->hoadon.thoigian.nam = char_int(sx);
					  	if (gia_tri!=-1) goto batdauhd3;
					  } 
			  	    else if (gia_tri==17)
			  	      {
			  	      	xl_phim();
			  	        gia_tri=xl_nhaphd(135,170,365,190,0,sl_kytu_mavt,sl_kytu_mavt,sx);
			  	        strcpy(hd->hoadon.dscthd.ct_hoadon[sl].mavt,sx);
			 	        if (gia_tri!=-1) goto batdauhd3;	
					  }
					else if (gia_tri==18  )
			  	      {
			  	      	xl_phim();
			  	        gia_tri=xl_nhaphd(520,170,720,190,1,8,8,sx);
			  	        if (strcmp(sx,"")!=0)
			  	               hd->hoadon.dscthd.ct_hoadon[sl].soluong = char_long(sx);
			  	        else          hd->hoadon.dscthd.ct_hoadon[sl].soluong =-1;           
			 	        if (gia_tri!=-1) goto batdauhd3;	
					 }
					else if (gia_tri==19 )
			  	      {
			  	      	xl_phim();
			  	        gia_tri=xl_nhaphd(915,170,1115,190,1,9,9,sx);//        
			  	        if (strcmp(sx,"")!=0)
			  	                hd->hoadon.dscthd.ct_hoadon[sl].dongia = char_long(sx);
			  	        else          hd->hoadon.dscthd.ct_hoadon[sl].dongia =-1;    
			 	        if (gia_tri!=-1) goto batdauhd3;	
					  }
					else if (gia_tri==20)
			  	      {
			  	      	xl_phim();
			  	        gia_tri=xl_nhaphd(1235,170,1308,190,1,3,3,sx);
			  	        hd->hoadon.dscthd.ct_hoadon[sl].vat = char_long(sx);
			 	        if (gia_tri!=-1) goto batdauhd3;	
					  }
					else if (gia_tri==21  )
					   {
					   	VatTu x;
					   	x.SLT =-1;
					   	CheckMaVT(tree,hd->hoadon.dscthd.ct_hoadon[sl].mavt,x);
					   	if ( sl<20 && kt_dulieu(hd,sl) && kt_sohd(dsnhanvien,hd->hoadon.sohd)==false &&hd->hoadon.dscthd.ct_hoadon[sl].vat<=100&& hd->hoadon.thoigian.nam>=1900 &&vt!=-1 && ((x.SLT >=hd->hoadon.dscthd.ct_hoadon[sl].soluong && strcmp(hd->hoadon.loai,"X")==0)||strcmp(hd->hoadon.loai,"N")==0) && strcmp(x.MaVT,"")!=0)
					   	{  	
					   	  int xi =1;
					      if (strcmp(hd->hoadon.loai,"X")==0)
					              xi = -1;
					   	  sua_slt(tree,x.MaVT,hd->hoadon.dscthd.ct_hoadon[sl].soluong,xi);
					   	  xuat_vthd(hd,sl,x,tongt);
					   	  xuat_themvt(1325,"Them vt");
					   	  sl = sl +1;    dxloai =true;
					   	  hd->hoadon.dscthd.ct_hoadon[sl] = hd->hoadon.dscthd.ct_hoadon[sl-1];
					   }
					   else 
					       {
					       	if (vt==-1)
							        {
							        	cincolor(4,15,2);
					       	            outtextxy(1350,120,"Loi");
					       	            outtextxy(1320,140,"nhan vien");
									}
					       	else if(kt_sohd(dsnhanvien,hd->hoadon.sohd) ==true|| hd->hoadon.sohd[0] =='\0')
							        {
							        	cincolor(4,15,2);
					       	            outtextxy(1350,120,"Loi");
					       	            outtextxy(1305,140,"so hoa don");
									}
							else if (strcmp(hd->hoadon.loai,"")==0)
							     {
					       	            cincolor(4,15,2);
					       	            outtextxy(1360,120,"Loi");
					       	            outtextxy(1315,140,"Nhap loai");
					             }
							else if (sl>=20)
							          {
							          	cincolor(4,15,2);
					       	            outtextxy(1320,120,"Da du 20");
					       	            outtextxy(1320,140,"vat tu!");
					       	            xuat_themvt(1325,"Them vt");
									  }
							else if (CheckNgay(hd->hoadon.thoigian.ngay,hd->hoadon.thoigian.thang,hd->hoadon.thoigian.nam) ==false || hd->hoadon.thoigian.nam<1900)
							        {
							        	cincolor(4,15,2);
					       	            outtextxy(1360,120,"Loi");
					       	            outtextxy(1315,140,"Thoi gian");
									}
							else if (strcmp(x.MaVT,"")==0)
							        {
							        	cincolor(4,15,2);
					       	            outtextxy(1320,120,"Loi");
					       	            outtextxy(1320,140,"vat tu");
									}
							else if (x.SLT <hd->hoadon.dscthd.ct_hoadon[sl].soluong && strcmp(hd->hoadon.loai,"X")==0 && strcmp(x.MaVT,"")!=0)
					       	        {
					       	        	cincolor(4,15,2);
					       	            outtextxy(1300,120,"SL toi da:");
					       	            outtextxy(1310,140,tro_long(x.SLT));
									}
							else if (hd->hoadon.dscthd.ct_hoadon[sl].soluong<1)
							     {
					       	            cincolor(4,15,2);
					       	            outtextxy(1360,120,"Loi");
					       	            outtextxy(1315,140,"So luong>0");
					             }
							else if (hd->hoadon.dscthd.ct_hoadon[sl].dongia<1)
							     {
					       	            cincolor(4,15,2);
					       	            outtextxy(1360,120,"Loi");
					       	            outtextxy(1315,140,"Don gia>0");
					             }
							else if (hd->hoadon.dscthd.ct_hoadon[sl].vat>100)
							       {
							        	cincolor(4,15,2);
					       	            outtextxy(1360,120,"Loi");
					       	            outtextxy(1315,140,"VAT<=100");
									}
					        xuat_themvt(1325,"Them vt");
						   }
				      }		
					break;
			 case 4:
			     	  if (gia_tri==17)
			  	      {
			  	      	xl_phim();
			  	        gia_tri=xl_nhaphd(135,170,365,190,0,sl_kytu_mavt,sl_kytu_mavt,sx,ktm3);
			  	        strcpy(fs.mavt,sx);
			 	        if (gia_tri!=-1) goto batdauhd3;	
						}
					else if (gia_tri==18  )
			  	      {
			  	      	xl_phim();
			  	        gia_tri=xl_nhaphd(520,170,720,190,1,11,11,sx,ktm3);
			  	        fs.soluong = char_long(sx);
			 	        if (gia_tri!=-1) goto batdauhd3;	
						}
					else if (gia_tri==19 )
			  	      {
			  	      	xl_phim();
			  	        gia_tri=xl_nhaphd(915,170,1115,190,1,11,11,sx,ktm3);
			  	        fs.dongia = char_long(sx);
			 	        if (gia_tri!=-1) goto batdauhd3;	
					  }
					else if (gia_tri==20)
			  	      {
			  	      	xl_phim();
			  	        gia_tri=xl_nhaphd(1235,170,1308,190,1,3,3,sx,ktm3);
			  	        fs.vat = char_long(sx);
			 	        if (gia_tri!=-1) goto batdauhd3;	
					  }
					else if (gia_tri==42)
					     	     {
					     	     	barcolor(1315,161,1470,200,15);
					     	     	xuat_themvattu();
	                                setcolor(9);
	                                vien_hcm(29,160,1470,200);
	                                strcpy(hd->hoadon.dscthd.ct_hoadon[sl].mavt,"");
	                                hd->hoadon.dscthd.ct_hoadon[sl].dongia=-1;
	                                hd->hoadon.dscthd.ct_hoadon[sl].soluong=-1;
	                                hd->hoadon.dscthd.ct_hoadon[sl].vat =-1;
	                                ktm3=1;tongx =0;
								  }
					else if (gia_tri==43)
							    {
							      VatTu x1;
							      CheckMaVT(tree,fs.mavt,x1);
							      if (fs.dongia>0 && fs.soluong>0 && ((fs.soluong<=x1.SLT &&strcmp(hd->hoadon.loai,"X")==0) || strcmp(hd->hoadon.loai,"N")==0) && fs.vat!=-1 && (strcmp(fs.mavt,"")!=0))
							        {
							        barcolor(1315,161,1470,200,15);
					     	     	xuat_themvattu();
	                                setcolor(9);
	                                vien_hcm(29,160,1470,200);
	                                barcolor(32,240+vty1*25,1407,240+vty1*25+20,15);
	                                barcolor(1110,743,1407,765,15);
	                                line(210,200,210,740);
                                    line(475,200,475,740);
	                                line(680,200,680,740);
	                                line(875,200,875,740);
	                                line(1095,200,1095,770);
	                                line(1155,200,1155,740);
									int xi =1;
					                if (strcmp(hd->hoadon.loai,"X")==0)
					                       xi = -1;
					                sua_slt(tree,fs.mavt,tongx,-1*xi);
					                sua_slt(tree,fs.mavt,fs.soluong,xi);
	                                long long tongt2=0;
	                                for (int v=0;v<sl;v++)
	                                      tongt2 =tongt2 + hd->hoadon.dscthd.ct_hoadon[v].dongia*hd->hoadon.dscthd.ct_hoadon[v].soluong*(hd->hoadon.dscthd.ct_hoadon[v].vat+100)/100;
	                                VatTu x;
	                                tongt2 =tongt2 - hd->hoadon.dscthd.ct_hoadon[vty1].dongia*hd->hoadon.dscthd.ct_hoadon[vty1].soluong*(hd->hoadon.dscthd.ct_hoadon[vty1].vat+100)/100;
	                                hd->hoadon.dscthd.ct_hoadon[vty1] = fs;
					   	            CheckMaVT(tree,hd->hoadon.dscthd.ct_hoadon[vty1].mavt,x);
					   	            xuat_vthd(hd,vty1,x,tongt2);
					   	            tongt = tongt2;
					   	            strcpy(hd->hoadon.dscthd.ct_hoadon[sl].mavt,"");
	                                hd->hoadon.dscthd.ct_hoadon[sl].dongia=-1;
	                                hd->hoadon.dscthd.ct_hoadon[sl].soluong=-1;
	                                hd->hoadon.dscthd.ct_hoadon[sl].vat =-1;
					   	            ktm3=1;
					   	            reset_filevt(tree);
									}
						       }  
						       break;
			  case 2:
			     {
			     	cincolor(15,15,2);
					outtextxy(530,345,"So hoa don khong ton tai!");
			     	if (gia_tri==24)
			     	    {
			     	    	xl_phim();
			  	           	gia_tri= xl_nhaphd(535,270,910,290,0,max_cthd,max_cthd,sx,ktm3);
			  	           	strcpy(sx5,sx);
			 	            if (gia_tri!=-1) goto batdauhd3;
						 }
					else if (gia_tri==25)
					   {
					   	if (kt_sohd(dsnhanvien,sx5)==true)
						    { 
					   	        danhdauhd =true;
					   	        xuat_tthoadon();
					   	        check_tthd(dsnhanvien,tree,sx5);
					   	   }
					   	else
					   	     {
					   	     	cincolor(4,15,2);
					   	     	outtextxy(530,345,"So hoa don khong ton tai!");
							}
					   }
					else if (gia_tri==26 && danhdauhd ==true)
					   {
					   	clear03();
					   	xuat_inhd(); 
					   	danhdauhd =false;
					   	strcpy(sx5,"");
					   }
					break;
				 }
			case 3:
				  {
				  	cincolor(15,15,2);
					outtextxy(40,630,"Ngay khong hop le!");
				  	if (gia_tri==30)
				  	  {
				  	  	xl_phim();
				  	  	gia_tri=xl_nhaphd(80,330,138,350,1,2,2,sx,ktm3);
				  	  	d.ngay=char_int(sx);
				  	  	if (gia_tri!=-1) goto batdauhd3;
					  }
					else if (gia_tri==31)
				  	  {
				  	  	xl_phim();
				  	  	gia_tri=xl_nhaphd(152,330,210,350,1,2,2,sx,ktm3);
				  	  	d.thang=char_int(sx);
				  	  	if (gia_tri!=-1) goto batdauhd3;
					  }
					else if (gia_tri==32)
				  	  {
				  	  	xl_phim();
				  	  	gia_tri=xl_nhaphd(220,330,313,350,1,4,4,sx,ktm3);
				  	  	d.nam =char_int(sx);
				  	  	if (gia_tri!=-1) goto batdauhd3;
					  }
					 else if (gia_tri==33)
				  	  {
				  	  	xl_phim();
				  	  	gia_tri=xl_nhaphd(80,430,138,450,1,2,2,sx,ktm3);
				  	  	c.ngay =char_int(sx);
				  	  	if (gia_tri!=-1) goto batdauhd3;
					  }
					else if (gia_tri==34)
				  	  {
				  	  	xl_phim();
				  	  	gia_tri=xl_nhaphd(152,430,210,450,1,2,2,sx,ktm3);
				  	  	c.thang=char_int(sx);
				  	  	if (gia_tri!=-1) goto batdauhd3;
					  }
					else if (gia_tri==35)
				  	  {
				  	  	xl_phim();
				  	  	gia_tri=xl_nhaphd(220,430,313,450,1,4,4,sx,ktm3);
				  	  	c.nam =char_int(sx);
				  	  	if (gia_tri!=-1) goto batdauhd3;
					   }
					else if ((gia_tri==27 || gia_tri==28 ) && (CheckNgay(d.ngay,d.thang,d.nam)==false || CheckNgay(c.ngay,c.thang,c.nam )==false|| sosanh_tg(d,c)==false))
					            {
					            	cincolor(4,15,2);
					            	outtextxy(40,630,"Ngay khong hop le!");
								 } 
				  	else if (gia_tri==28 && CheckNgay(d.ngay,d.thang,d.nam) &&CheckNgay(c.ngay,c.thang,c.nam))
				  	       {
				  	       	clear05();
				  	       //	xuat_10vt(d,c);
				  	       	check_10vt(dsnhanvien,tree,d,c);
							 }
					else if (gia_tri==27&& CheckNgay(d.ngay,d.thang,d.nam) &&CheckNgay(c.ngay,c.thang,c.nam))
				  	       {
				  	       	 dem = dem_slhd(dsnhanvien,d,c);
				  	       	
				  	       	sotrang=1;
				  	       	clear05();
				  	       	if (dem==0)
				  	       	     {
				  	       	     		cincolor(4,15,2);
					                    outtextxy(45,630,"Khong co hoa don!");
								 }
							else
							{
				  	       	xuat_tophd(d,c);
				  	       	check_tophd(dsnhanvien,d,c,sotrang,dem);
				  	       	if (dem>=10)
				  	       	 {
				  	       	      cincolor(0,7,3);
	                              outtextxy(1395,755,"-->");
	                          }
	                        cincolor(0,15,2);
	                        outtextxy(1410,785,tro_int(sotrang));
	                        outtextxy(1425,785,"/");outtextxy(1440,785,tro_int(dem/10+1));
				  	        } 
						   }
					else if (gia_tri==29)
				  	       {
				  	       	clear05();
				  	       	barcolor(70,325,320,355,15);
				  	       	barcolor(70,425,320,455,15);
				  	       	cincolor(0,15,2);
	              	        outtextxy(140,330,"/");outtextxy(210,330,"/"); outtextxy(140,430,"/");outtextxy(210,430,"/");
	                        cincolor(7,7,2);
	                        outtextxy(87,330,"   "); outtextxy(160,330,"   "); outtextxy(230,330,"     "); outtextxy(87,430,"   ");outtextxy(160,430,"   ");outtextxy(230,430,"     ");
	                        c.nam=0;c.ngay=0 ;c.thang=0;
	                        d.nam=0;c.ngay=0 ;c.thang=0;                   
						   }
						else if (gia_tri==42 && dem>=10)
						     {
						     	if (sotrang+1<=(dem/10+1))
						     	   	  sotrang =sotrang +1;
						     	else sotrang =1;
	                            clear05();
	                            xuat_tophd(d,c);
				  	       	    check_tophd(dsnhanvien,d,c,sotrang,dem);
				  	       	    cincolor(0,7,3);
	                            outtextxy(1395,755,"-->");
	                            cincolor(0,15,2);
	                            outtextxy(1410,785,tro_int(sotrang));
	                            outtextxy(1425,785,"/");outtextxy(1440,785,tro_int(dem/10+1));
							 }
					break; 
				  }
			} 	
		 }
	    }
}

int main()
{
	//int gd=0,gm=0,i=0,x=1,y=1;
	initwindow(1509,840);
	setwindowtitle("Quan ly vat tu");
    LISTVT tree  = NULL;
    gd2(tree);
    
}
