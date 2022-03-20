void coppy(char a[50],string b)
{
	int i;
	for ( i=0;i<b.length();i++)
	   a[i]=b[i];
	for (int j=i;j<50;j++)  a[i] ='\0';
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
	   	//cout<<"kienvip";
	   	dsnhanvien.soluong=dsnhanvien.soluong+1;         // trong file co ki tu xuong dong nen du het ki tu nhung file van chua ket thuc
	   	  dsnhanvien.nhanvien[dsnhanvien.soluong] = new NHANVIEN;
	   	  s="";  getline(f,s);
	   	  coppy(dsnhanvien.nhanvien[dsnhanvien.soluong]->manv,s);
	   	  s="";  getline(f,s);
	   	  coppy(dsnhanvien.nhanvien[dsnhanvien.soluong]->ho,s);
	   	  s="";  getline(f,s);
	   	  coppy(dsnhanvien.nhanvien[dsnhanvien.soluong]->ten,s);
	   	  s="";  getline(f,s);
	   	  coppy(dsnhanvien.nhanvien[dsnhanvien.soluong]->phai,s);
	      
	     
	   }
	f.close();
}

void ghifile_nhanvien(DSNHANVIEN &dsnhanvien)
{
	fstream f;
	f.open(file_nhanvien,ios_base::out|ios_base::app);           // con tro chuot ow dong dau nen se xuong dong 2 de ghi
	//dsnhanvien.nhanvien[dsnhanvien.soluong] = new NHANVIEN;
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
void xuat_dsnhanvien(DSNHANVIEN dsnhanvien)
{
	int a=155,b=205;
	//cout<<"kiendz";
	//cout<<"cuoi cung "<<dsnhanvien.soluong<<endl;
	for (int i=0;i<dsnhanvien.soluong;i++)
	  {
	  	cincolor(0, 15 ,2);
	  	outtextxy(a,b,dsnhanvien.nhanvien[i]->ho);
	  	a=a+375;
	  	outtextxy(a,b,dsnhanvien.nhanvien[i]->ten);
	  	a=a+285;
	  	outtextxy(a,b,dsnhanvien.nhanvien[i]->phai);
	  	a=a+200;
		outtextxy(a,b,dsnhanvien.nhanvien[i]->manv); 	
	  	a=155;
	  	b=b+30;
	  	//cout<<dsnhanvien.nhanvien[i]->ho<<endl;
	  	//cout<<dsnhanvien.nhanvien[i]->ten<<endl;
	  	//cout<<dsnhanvien.nhanvien[i]->phai<<endl;
	  	//cout<<dsnhanvien.nhanvien[i]->manv<<endl<<endl;
	  }
}
int kt_vitri(DSNHANVIEN &dsnhanvien,char s[50])
{
	int vt =-1;
	cout<<s<<endl;
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
	dsnhanvien.soluong =  dsnhanvien.soluong - 1;
	for (int i=vt ; i<dsnhanvien.soluong;i++)
	     {
	     	dsnhanvien.nhanvien[i] =  dsnhanvien.nhanvien[i+1];
		 }
	delete dsnhanvien.nhanvien[dsnhanvien.soluong+1];
}
void auto_manv(DSNHANVIEN dsnhanvien,char sx[50])
{
	char s[50]=("");
	for (int i=0;i<dsnhanvien.soluong;i++)
	  {
	  	  if ((ktra_manv(dsnhanvien.nhanvien[i]->manv)==true )&&(strcmp(dsnhanvien.nhanvien[i]->manv,sx)>0))
	  	       strcpy(sx,dsnhanvien.nhanvien[i]->manv);
	  }
	cout<<sx<<endl;
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
	if (i!=dem)
	   {
	   	int j=i-1;
	   	while (j>=2)
	   	   {
	   	   	if (sx[j]<'9')  
	   	   	          {
	   	   	          	sx[j]= char(49 + (sx[j] -'0'));
	   	   	          		cout<<sx<<endl;
	   	   	          	return ;
							}
			else 
			    {
			    	sx[j]='0';
			    	j=j-1; 
				}
			  }
	   }
		cout<<sx<<endl;
		return ;
}
