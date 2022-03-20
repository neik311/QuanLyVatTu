#include <string.h>
#include <fstream>


void xl_phim()
{
	while(1)
	  {
	  	if (kbhit())
	  	  	char c=getch();
	  	else   return;
	  }
}

int min(int a,int b)
{
	if (a>b)  return b;
	else return a;
}

char *tro_char(char s[50])
{
	char *x =new char [50];
	int i=0;
	while (s[i]!='\0')
	    {
	    	x[i]=s[i];
	    	i=i+1;
		}
	for (int j=i;j<=50;j++)  x[i] ='\0';
	return x;
}
char *tro_int(int n)
{
	if (n==0) return "0";
	char *x =  new char [50];
	char *s =  new char [50];
	int i=0,j=0;
	while(n!=0)
	   {
	   	x[i] = char(n%10 + 48);
	   	n=n/10;
	   	i=i+1;
	   }
	for (int j=0;j<i;j++)   s[j] = x[i-j-1];
	for (int j=i;j<=50;j++)  s[i] ='\0';
	return s;
}

char *tro_long(long long n)
{
	if (n==0) return "0";
	char *x =  new char [50];
	char *s =  new char [50];
	int i=0,j=0;
	while(n!=0)
	   {
	   	x[i] = char(n%10 + 48);
	   	n=n/10;
	   	i=i+1;
	   }
	for (int j=0;j<i;j++)   s[j] = x[i-j-1];
	for (int j=i;j<50;j++)  s[i] ='\0';
	return s;
}


int kt_vitri(DSNHANVIEN &dsnhanvien,char s[50])
{
	int vt =-1;
	//cout<<s<<endl;
	for (int i=0;i<dsnhanvien.soluong;i++)
	{
		if (strcmp(dsnhanvien.nhanvien[i]->manv,s)==0)
		    {
		    	vt = i;
		    	break;
			}
	}
	return vt;
}
bool ktra_manv(char s[50])
{
	if ((s[0]!='n' )||(s[1] !='v'))
	   return false;
	int i=2;
	while (s[i]!='\0')
	  {
	  	if (s[i]>='0' && s[i]<='9')
	  	         i=i+1;
	  	else return false;
	  }
	return true;
}


void delete_nv(DSNHANVIEN &dsnhanvien,int vt)
{
	dsnhanvien.soluong =  dsnhanvien.soluong - 1;//5 6 7
	for (int i=vt ; i<dsnhanvien.soluong;i++)
	     {
	     	dsnhanvien.nhanvien[i] =  dsnhanvien.nhanvien[i+1];
		 }
	delete dsnhanvien.nhanvien[dsnhanvien.soluong];
}

void xl_dsnhanvien(DSNHANVIEN &dsnhanvien)
{
	int vt,i;
	if (dsnhanvien.soluong==1)
	     return;
	else
	 {
	 	NHANVIEN *x =dsnhanvien.nhanvien[dsnhanvien.soluong-1];
	 	for ( i=0;i<dsnhanvien.soluong-1;i++)
	 	{
	 	    if (strcmp(dsnhanvien.nhanvien[i]->ten,x->ten)>0 || ((strcmp(dsnhanvien.nhanvien[i]->ten,x->ten)==0) &&(strcmp(dsnhanvien.nhanvien[i]->ho,x->ho))>0)
			  || ((strcmp(dsnhanvien.nhanvien[i]->ten,x->ten)==0) &&(strcmp(dsnhanvien.nhanvien[i]->ho,x->ho))==0 && strcmp(dsnhanvien.nhanvien[i]->manv,x->manv)>0) )
			      {
			      	vt=i;
			      	break;
				  }
	    }
	    if (i==dsnhanvien.soluong-1)  return;
	    for (int i=dsnhanvien.soluong-1;i>vt;i--)
	       {
	       	dsnhanvien.nhanvien[i]=dsnhanvien.nhanvien[i-1];
		   }
		dsnhanvien.nhanvien[vt]=x;
	 }
}




int char_int(char s[50])
{
	int x = 0, i=0 ;
	while (s[i] != '\0')
	   {
	   	  x =  x*10 + (int(s[i]) - 48);
	   	   i=i+1;
	   }
	return x;
}
long long  char_long(char s[50])
{
	long long x = 0;
	int i=0 ;
	while (s[i] != '\0')
	   {
	   	  x =  x*10 + (long(s[i]) - 48);
	   	   i=i+1;
	   }
	return x;
}


void chuyen_cach(char sx[max_kt])
{
	int i=0,n =0,j=0,x = 0;
	while (sx[i]==' ') // 
	        i=i+1;    //      

	while (sx[n]!='\0')//
	    n = n +1;
	j=n-1;
	while (sx[j] == ' ')
	          j = j -1 ;
	while (i<=j)
	  {
	  	sx[x] = sx[i];
	  	i=i+1;
	  	x=x+1;
	  }
    for (int z=x;z<=n;z++)  sx[z] ='\0';
    for (int i=0;i<x-1;i++)
     {
     	if (sx[i] ==' ' &&sx[i+1]==' ')
     	     {
     	     	for (int j=i+1;j<x-1;j++)
     	     	      sx[j] = sx[j+1];
     	     	sx[x-1]='\0';
				x=x-1;
     	     	i=i-1;
			  }
	 }
}

void viet_hoa(char sx[max_kt])          // ng
{
	if (sx[0]>='a' && sx[0]<='z')
	          sx[0] = char (int(sx[0]) - 32);
	int i = 1;
	while (sx[i] != '\0' )
	  {
	  	if (sx[i-1] ==' ' && (sx[i]>='a' && sx[i+1] <='z'))
	  	    sx[i] = char(int(sx[i]) - 32);
	  	else if ((sx[i] >= 'A' && sx[i]<='Z') && sx[i-1]!=' ')
	  	      sx[i] = char(int (sx[i])+32);
	  	i=i+1;
	  }
}

bool sosanh(char a[max_kt], char b[max_kt])
{
	int i=0;
	while (a[i] !='\0' && b[i] !='\0')
	  {
	  	if (a[i]==b[i] || a[i] - b[i] ==32 || b[i]-a[i] == 32)
	  	         i=i+1;
	  	else break;
	  }
	if (a[i] =='\0' && b[i] =='\0')  return true;
	else return false;
}
bool NamNhuan(int nam)
{
	return(nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) ? 1 : 0;
}
bool CheckNgay(int ngay,int thang,int nam)
{
	
	int check = 0, maxday = 0;
	if (thang > 12|| thang <1) return false;
	switch (thang)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			maxday = 31;
			break;
		case 4: case 6: case 9: case 11:
			maxday = 30;
			break;
		case 2:
			if (NamNhuan(nam) == 1) maxday = 29;
			else maxday = 28;
			break;
	}
	if (ngay > maxday || ngay <1)	return false;
    if (nam  < 1)                 return false;
	return true;
}


void check_mavt(LISTVT &tree, char s[50],bool &kt)                     /// tree
{
	if (tree == NULL) return ;
	if (tree != NULL)
	{
		if (strcmp(tree->vt.MaVT, s) == 0)
		{
		      kt= true;
		}
		else if (strcmp(tree->vt.MaVT, s) > 0)
		{
			 check_mavt(tree->pleft, s,kt);
		}
		else 
		{
			check_mavt(tree->pright, s,kt);
		}
	}
}
void auto_mavt(char sx[50],LISTVT tree,int sl)
{
	sx[0] ='v';                    
	sx[1] = 't';                     
	int i2 =1;
	bool kt = false;
	if (sl>=100 ) sl =sl%100;
	if (sl<10)
	    {
	    	sx[4] = '0';
	    	sx[5] = char (48 +sl);
		}
	else if (sl>=10)
	    {
	    	sx[4] = char (48 +sl/10);
	    	sx[5] = char (48 +sl%10);
		}
	int x= rand() % (9 - 0 +1) +0;
	int y= rand() % (9 - 0 +1) +0;
	sx[2] = char(48+x);
	sx[3] = char (48+y);
	for (int j=6;j<=50;j++)  sx[j]='\0';
	while (kt)
	  {
	     check_mavt(tree ,sx,kt);
	     if (kt==true)
	         {
	          x= rand() % (9 - 0 +1) +0;
	          int y= rand() % (9 - 0 +1) +0;
	          sx[2] = char(48+x);
	          sx[3] = char (48+y);
			}       	
		}
	for (int i=6;i<50;i++) sx[i] = '\0';
}

void auto_manv(DSNHANVIEN dsnhanvien,char sx[50])
{
	char s[50]=("");
	for (int i=0;i<dsnhanvien.soluong;i++)
	  {
	  	  if ((ktra_manv(dsnhanvien.nhanvien[i]->manv)==true )&&(strcmp(dsnhanvien.nhanvien[i]->manv,sx)>0))
	  	       strcpy(sx,dsnhanvien.nhanvien[i]->manv);
	  }
	if (sx[0]=='\0')
	       {
	       	strcpy(sx,"nv001");
	       	return ;
		   }
	int i=2, dem=2;
	while (sx[i]!='\0')
	  {
	  	if (sx[i]=='9') dem=dem+1;
	  	i=i+1;
	  }
	if (i!=dem)         // nv999
	   {                           
	   	int j=i-1;     // 
	   	while (j>=2)
	   	   {
	   	   	if (sx[j]<'9')  
	   	   	          {
	   	   	          	sx[j]= char(49 + (sx[j] -'0'));
	   	   	          	return ;
							}
			else 
			    {
			    	sx[j]='0';
			    	j=j-1; 
				}
			  }
	   }
	 else
	    {
	    	strcpy(sx,"");
	    	for(int i=2;i<=50;i++)  sx[i] ='\0';
	    	sx[0]= 'n'; sx[1] ='v';
	    	for (i=1;i<999;i++)
	          {
	  	          if (i<10)
	  	              {
	  	              	sx[2]='0'; sx[3]='0';
	  	              	sx[4] = char(48+i);    
						}
				 else if (i<100)
				      {
				      	sx[2]='0'; 
				      	sx[3]= char (48+i/10);
	  	              	sx[4] = char(48+i%10);
					  }
				else 
				      {
				      	sx[2]= char(48 + i/100);
				      	sx[3]= char (48+(i%100)/10);
	  	              	sx[4] = char(48+(i%100)%10);
					  }
                if (kt_vitri(dsnhanvien,sx) ==-1)
                    {
                    	return;
					}
	          }
		}
		return ;
}

bool sosanh_tg(THOIGIAN c, THOIGIAN d)
{
	if (c.nam > d.nam) return false;
	if (c.nam < d.nam) return true;
	if(c.thang >d.thang) return false;
	if (c.thang <d.thang) return true;
	if(c.ngay >d.ngay) return false;
	if (c.ngay <=d.ngay) return true;
}

void RemoveVatTu(LISTVT &tree, VatTu vt)
{
	if (tree == NULL)
	{
		return;
	}
	if (strcmp(tree->vt.MaVT,vt.MaVT) > 0)
	{
		return RemoveVatTu(tree->pleft, vt);
	}
	else if (strcmp(tree->vt.MaVT,vt.MaVT) < 0)
		{
			return RemoveVatTu(tree->pright, vt);
		}
	else
	{
		if (tree->pleft == NULL)
		{
			tree = tree->pright;
		}
		else if (tree->pright == NULL)
		{
			tree = tree->pleft;
		}
		else 
		{
			//tim phan tu the mang
			ListVatTu* x = tree->pleft;
			while (x->pright != NULL)
			{
				x = x->pright;
			}
			tree->vt = x->vt;
			RemoveVatTu(tree->pleft, x->vt);
			delete x;//giai phong vung nho
		}
	}
}


void sua_slt(LISTVT &tree, char mavt2[sl_kytu_mavt],int slt,int xi)
{	
	if (tree == NULL) return ;
	if (tree != NULL)
	{
		if (strcmp(tree->vt.MaVT, mavt2) == 0)
		{
		      tree->vt.SLT = tree->vt.SLT + xi*slt;
		}
		else if (strcmp(tree->vt.MaVT, mavt2) > 0)
		{
			 sua_slt(tree->pleft, mavt2,slt,xi);
		}
		else 
		{
			sua_slt(tree->pright, mavt2,slt,xi);
		}
	}
}


