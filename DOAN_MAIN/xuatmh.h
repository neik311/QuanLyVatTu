#define clear() cleardevice();

void cincolor(int a,int b,int c,int d=0,int e=0)
{
	if (a!=-1)
	    setcolor(a);            
	if (b!=-1)
  	   setbkcolor(b);            
  	if (c!=-1)
	   settextstyle(d,e,c);       
}
void clear02()
{
	setfillstyle(1,11); 
	bar(10,52,1480,820);
}
void clear03()
{
	setfillstyle(1,11); 
	bar(6,110,1490,820);
}
void clear04()
{
	setfillstyle(1,15); 
	bar(85,230,1385,795);
}
void clear05()
{
	setfillstyle(1,15); 
	bar(335,140,1467,800);
}

void vien_01()
{
	setfillstyle(1,9); 
	bar(295,145,1105,685);
	setfillstyle(1,15); 
	bar(300,150,1100,680);

}
void vien_02()
{
	setfillstyle(1,9); 
	bar(340,240,1055,375);
	setfillstyle(1,15); 
	bar(345,245,1050,370);
}

void vien_03()
{
	setfillstyle(1,9); 
	bar(27,117,1473,808);
	setfillstyle(1,15); 
	bar(30,120,1470,805);

}

void vien_04()
{
	setfillstyle(1,9); 
	bar(37,127,1463,803);
	setfillstyle(1,15); 
	bar(40,130,1460,800);
}


void vien_hcm(int a,int b, int c,int d)   
{
	line(a,b,c,b);line(a,b,a,d);line(a,d,c,d);line(c,b,c,d);
}
void barcolor(int a,int b,int c,int d,int e)
{
	setfillstyle(1,e); 
	bar(a,b,c,d);
}


byte ktra01(int j,int i)
{
	     	if ((j>=75 && j<=275) && (i>=7 && i<=40)) //vat tu
	     	  {
	     	   return 1;
	          }
	        if ((j>=580 && j<=850) && (i>=7 && i<=40))             // nhan vien
	     	   {
	     	   return 2;
	          }
	        if ((j>=1125  && j<=1350) && (i>=7 && i<=40))         // hoa don
	               return 3;
	     	 if ((j>=360 && j<=500) && (i>=30 && i<=50))  //huong dan
	     	   {
	     	   return 4;
	          }
	        if ((j>=930 && j<=1070) && (i>=30 && i<=50))   // thong tin
	          {
	          return 5;
	          }
	        return 0;
}
byte ktra(int j,int i,int ktm=0)
{

	     	if ((j>=75 && j<=275) && (i>=7 && i<=40)) //vat tu
	     	  {
	     	   return 1;
	          }
	        if ((j>=580 && j<=850) && (i>=7 && i<=40))             // nhan vien
	     	   {
	     	   return 2;
	          }
	        if ((j>=1125  && j<=1350) && (i>=7 && i<=40))         // hoa don
	               return 3;
	     	 if ((j>=360 && j<=500) && (i>=30 && i<=50))  //huong dan
	     	   {
	     	   return 4;
	          }
	           if ((j>=930 && j<=1070) && (i>=30 && i<=50))   // thong tin
	          {
	          return 5;
	          }
	         // 
	     	 if ((j>=340 && j<=725) && (i>=65 && i<=95))    //them 
	     	   return 6;

	        if ((j>=730 && j<=1120)&& (i>=65 && i<=95))      // danh sach
	            return 7;
	        
	        // them nhan vien
	         if ((j>=700 && j<=755)&& (i>=400 && i<=420))    //nam 
	            return 16;
	         if ((j>=800 && j<=840)&& (i>=400 && i<=420))    //nu  
	            return 17;
            
	            
	        if ((j>=595 && j<=1000) && (i>=200 && i<=220))   // nhap ho / ten vat tu
	          return 10;
	        if ((j>=595 && j<=1000)  && (i>=300 && i<=320))   //  ten nv // so luong
	                 return 11;   	
	        if ((j>=595 && j<=1000)  && (i>=400 && i<=420))   // don vi tinh
	                 return 12;
			if ((j>=595 && j<=1000)  && (i>=500 && i<=520))   // manv/mavt
	                 return 13;
			if ((j>=548 && j<=625)  && (i>=600 && i<=630))  // luu
	                 return 14;   	
			if ((j>=748 && j<=825)  && (i>=600 && i<=630))  // huy
	                 return 15;   
			
			  
			  // ktm ==2
			if ((j>=680 && j<=980 )  && (i>=150 && i<=170) && ktm==2)   // nhap tim kiem
			          return 21;
			if ((j>=1030 && j<=1170 )  && (i>=145 && i<=175)&& ktm==2)   // tim kiem
			          return 22;
			if ((j>=1395+(450-i) && j<= 1445 -(450-i)  )  && (i<= 450 && i >= 423))         // mui ten len
			          return 23;
			if ((j>=1395+(i-480) && j<= 1445 -(i-480)  )  && (i>= 480 && i <= 507))         // mui ten xuong
			          return 24;
	
			if ((j>=1057 && j<= 1147  )  && (i>= 188 && i <= 210))            //thoat           
			          return 25;
			if ((j>=1318 && j<= 1344  )  && (i>= 304 && i <= 805))         // xoa
			          return 26;      
			 if ((j>=1350 && j<= 1376  )  && (i>= 304 && i <= 805))       //sua
			          return 27;
			          
			  // ktm ==3
			if ((j>=380 && j<= 720  )  && (i>= 150 && i <= 170))       //ho
			          return 34;        
			if ((j>=380 && j<= 770  )  && (i>= 150 && i <= 170))       //ho
			          return 28;
			if ((j>=960 && j<= 1240  )  && (i>= 150 && i <= 170))       //ten
			          return 35;	
			if ((j>=900 && j<= 1240  )  && (i>= 150 && i <= 170))       //ten
			          return 29;
			if ((j>=400 && j<= 450  )  && (i>= 180 && i <= 200))       //gioitinh nam
			          return 30;
			if ((j>=480 && j<= 520  )  && (i>= 180 && i <= 200))       //nu
			          return 31;
			if ((j>=1325 && j<= 1350  )  && (i>= 140 && i <= 165))       //  dau x sua nv
			          return 32;
			if ((j>=1270 && j<= 1340  )  && (i>= 185 && i <= 210))       //  luu sua nv
			          return 33;
			            
			return 0;
}

byte ktrahd(int j,int i,int ktm=0)
{
	if ((j>=75 && j<=275) && (i>=7 && i<=40)) //vat tu
	     	  {
	     	   return 1;
	          }
	if ((j>=580 && j<=850) && (i>=7 && i<=40))             // nhan vien
	     	   {
	     	   return 2;
	          }
	if ((j>=1125  && j<=1350) && (i>=7 && i<=40))         // hoa don
	               return 3;
	if ((j>=360 && j<=500) && (i>=30 && i<=50))  //huong dan
	     	   {
	     	   return 4;
	          }
	if ((j>=930 && j<=1070) && (i>=30 && i<=50))   // thong tin
	          {
	          return 5;
	          }
	if ((j>=400 && j<600 ) && (i>=70 &&i<=100))     // tao hd
	        return 6;
	if ((j>=600 && j<800 ) && (i>=70 &&i<=100))      // in hd
	        return 7;
	if ((j>800 && j<1000 ) && (i>=70 &&i<=100))      // thong ke
	        return 8;
	        
	if ((j>=135 && j<=365)  && (i>=130  && i<=150) )    // ma nv
	        return 9;
    if ((j>=470 && j<=815)  && (i>=130  && i<=150) )     // so hd
	        return 10;
	if ((j>=905 && j<=930)  && (i>=130  && i<=150) )    // n
	        return 11;
    if ((j>=930 && j<=955)  && (i>=130  && i<=150) )    //x
	        return 12;
	if ((j>=1055 && j<=1110)  && (i>=130  && i<=150) )    //ngay
	        return 13;
	if ((j>=1125 && j<=1175)  && (i>=130  && i<=150) )    //thang
	        return 14;
	if ((j>=1188 && j<=1283)  && (i>=130  && i<=150) )    //nam
	        return 15;
	if ((j>=1320 && j<=1440)  && (i>=130  && i<=152) )    // them hd
	        return 16;
	if ((j>=135 && j<=365)  && (i>=170  && i<=190) )    // mavt
	        return 17;
	if ((j>=520 && j<=715)  && (i>=170  && i<=190) )    // so luong
	        return 18;
	if ((j>=915 && j<=1115)  && (i>=170  && i<=190) )    // don gia
	        return 19;
	if ((j>=1235 && j<=1308)  && (i>=170  && i<=190) )    // vat
	        return 20;
	
	
	if ((j>=1330 && j<=1400)  && (i>=160  && i<=200) && ktm==4)        // huy    
	        return 42;  
	if ((j>=1400 && j<=1470)  && (i>=160  && i<=200)  && ktm==4)        // luu    
	        return 43;  
			       
	if ((j>=1320 && j<=1440)  && (i>=170  && i<=192) )    // them vt;
	        return 21;
	if ((j>=450 && j<=750)  && (i>=773  && i<=805) )    //  huy hoa don;
	        return 22;   
	if ((j>=750 && j<=1047)  && (i>=773  && i<=805) )    //  luu hoa don
	        return 23;        
	if ((j>=535 && j<=910)  && (i>=270  && i<=290) )    //  check hoa don
	        return 24; 
	if ((j>=660 && j<=730)  && (i>=310  && i<=340) )    //  tl hd
	        return 25; 
	if ((j>=1445 && j<=1470)  && (i>=120  && i<=145) )    // dong tt hoa don
	        return 26; 
	if ((j>=30 && j<=180)  && (i>=701  && i<=755) )    // check ds hoa don
	        return 27; 
	if ((j>=180 && j<=330)  && (i>=701  && i<=755) )    // check vt
	        return 28; 
	if ((j>=30 && j<=330)  && (i>=755  && i<=805) )    // lam moi
	        return 29; 
	        
	if ((j>=85 && j<=130)  && (i>=330  && i<=350) )  // nhap thoi gian  
	        return 30; 
	if ((j>=155 && j<=210)  && (i>=330  && i<=350) )    //
	        return 31; 
	if ((j>=230 && j<=310)  && (i>=330  && i<=350) )    // 
	        return 32; 
	if ((j>=85 && j<=130)  && (i>=430  && i<=450) )    
	        return 33; 
	if ((j>=155 && j<=210)  && (i>=430  && i<=450) )    
	        return 34; 
	if ((j>=23 && j<=310)  && (i>=430  && i<=450) )    
	        return 35; 
	if ((j>=1410 && j<=1440)  && (i>=230  && i<=740) )   //xoa 
	        return 40;
	        
	if ((j>=1440 && j<=1470)  && (i>=230  && i<=740) )    // sua
	        return 41;
   if ((j>=1395 && j<=1465)  && (i>=755  && i<=785) )    // next
	        return 42;
	return -1;
 } 



