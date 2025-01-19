#include <iostream>
#include <locale.h>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Musteri
{
	char ad[50];
	char soyad[50];
	char telefon[50];
	char tarih[50];
	char saat[50];
};

Musteri musteri;

void RandevuOlustur();
void RandevuListele();
void RandevuAra();
void RandevuSil();
void RandevuDuzenle();
void FiyatListe();

int main()
{
	setlocale(LC_ALL,"Turkish");
	
	char secim;
	
	do{

	system("cls");
	cout << endl;
	cout << "|~~~~~Kuaf�r Otomasyonuna Ho�geldiniz~~~~~|" << endl; 
    cout << "|              Se�im Yap�n�z              |" << endl; 
    cout << "|           1-Randevu Olu�turma           |" << endl; 
    cout << "|           2-Randevu Listeleme           |" << endl;
    cout << "|           3-Randevu Arama               |" << endl;
    cout << "|           4-Randevu Silme               |" << endl;
    cout << "|           5-Randevu D�zeltme            |" << endl;
    cout << "|           6-Fiyat Listesi               |" << endl;
    cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << endl;
    cout << "Se�imi giriniz: " ;
	
	secim=getche();
	
	switch(secim)
	{
		case '1':
			{
			    RandevuOlustur();
				break;
			}
		case '2':
		    {
			    RandevuListele();
			    break;
		    }
		case '3':
			{
			    RandevuAra();
				break;
			}
		case '4':
		    {
			    RandevuSil();
			    break;
		    }
		case '5':
			{
			    RandevuDuzenle();
				break;
			}
		case '6':
		    {
			    FiyatListe();
			    break;
		    }    
		
	}
	cout << "\nAna Men�ye D�nmek �stermisiniz? (e/h) : " ;
	secim=getche();
	
}
while(secim=='e' || secim=='E');

cout << endl;
	
	system("pause");
	return 0;
}

void RandevuOlustur()
{
	ofstream yaz("kuaf�r.dat",ios::binary | ios::app);
	
	char secim;
	int adet=0;
	
	do{
	cout << endl;
	cout << "M��terinin Ad�n� Giriniz: " ;
	cin >> musteri.ad ;
	cout << "M��terinin Soyad�n� Giriniz: " ;
	cin >> musteri.soyad ;
	cout << "M��terinin Telefon Numaras�n� Giriniz: " ;
	cin >> musteri.telefon ;
	cout << "Randevu Olu�turulacak Tarihi Giriniz: " ;
	cin >> musteri.tarih ;
	cout << "Randevu Olu�turulacak Saati Giriniz: " ;
	cin >> musteri.saat ;
	
	yaz.write((char*)&musteri,sizeof(musteri));
	adet++;
		
	cout << "Ba�ka m��teri eklemek ister misiniz? (e/h) : " ;
	secim=getche();	
	}
	while(secim=='e' || secim=='E');
	
	cout << endl;
	cout << endl;
	cout << adet << " adet m��teri eklendi" << endl;
	
	yaz.close();
}

void RandevuListele()
{
	ifstream oku("kuaf�r.dat",ios::binary | ios::app);
	oku.seekg(0,ios::end);
	int kayit=oku.tellg()/sizeof(musteri);
	
	cout << endl;
	
	cout << "Toplam randevu say�s�: " << kayit << endl;
	
	cout << endl;
	
	if(kayit>0)
	{
	for(int i=0;i<kayit;i++)
	{
		oku.seekg(i*sizeof(musteri));
		oku.read((char*)&musteri,sizeof(musteri));
		
		cout << endl;
		cout << i+1 << ". M��terinin Bilgileri" << endl;
		cout << "M��terinin Ad�: " << musteri.ad << endl;
		cout << "M��terinin Soyad�: " << musteri.soyad << endl;
		cout << "M��terinin Telefon Numaras�: " << musteri.telefon << endl;
		cout << "Randevu Tarihi: " << musteri.tarih << endl;
		cout << "Randevu Saati: " << musteri.saat << endl;
		cout << endl;
		cout << "---------------------------" << endl;
	}
	oku.close();
	}
	else
	cout << "Randevu Bulunamad�" << endl;
	cout << endl;
	
}

void RandevuAra()
{
	ifstream oku("kuaf�r.dat",ios::binary | ios::app);
	oku.seekg(0,ios::end);
	int kayit=oku.tellg()/sizeof(musteri);
	
	cout << endl;
	
	char telefonn[10];
	cout << "Randevusu Aranacak M��terinin Telefon Numaras�n� Giriniz: " ;
	cin >> telefonn;
	
	if(kayit>0)
	{
	for(int i=0;i<kayit;i++)
	{
		oku.seekg(i*sizeof(musteri));
		oku.read((char*)&musteri,sizeof(musteri));
		
		cout << endl;
		
		if(strcmp(musteri.telefon,telefonn)==0)
		{
		cout << "Randevusu Bulunan M��terinin Bilgileri" << endl;
		cout << "M��terinin Ad�: " << musteri.ad << endl;
		cout << "M��terinin Soyad�: " << musteri.soyad << endl;
		cout << "M��terinin Telefon Numaras�: " << musteri.telefon << endl;
		cout << "Randevu Tarihi: " << musteri.tarih << endl;
		cout << "Randevu Saati: " << musteri.saat << endl;		
		}
	}
	oku.close();
	}
	else
	cout << "\nRandevu bulunamad�" << endl;
}

void RandevuSil()
{
    ifstream oku("kuaf�r.dat",ios::binary | ios::app);
	oku.seekg(0,ios::end);
	int kayit=oku.tellg()/sizeof(musteri);
	
	cout << endl;
	
	char secim;
	char telefonn[10];
	bool durum=false;
	cout << "Randevusu Silinecek M��terinin Telefon Numaras�n� Giriniz: " ;
	cin >> telefonn;
	
	if(kayit>0)
	{
	for(int i=0;i<kayit;i++)
	{
		oku.seekg(i*sizeof(musteri));
		oku.read((char*)&musteri,sizeof(musteri));
		
		cout << endl;
		
		if(strcmp(musteri.telefon,telefonn)==0)
		{
		cout << "Randevusu Silinecek M��terinin Bilgileri" << endl;
		cout << "M��terinin Ad�: " << musteri.ad << endl;
		cout << "M��terinin Soyad�: " << musteri.soyad << endl;
		cout << "M��terinin Telefon Numaras�: " << musteri.telefon << endl;
		cout << "Randevu Tarihi: " << musteri.tarih << endl;
		cout << "Randevu Saati: " << musteri.saat << endl;
		
		cout << "Randevusu silinecek m��teri bu mu? (e/h): " ;	
		
		secim=getche(); 
		
		if(secim=='h' || secim=='H')
		{
			
		ofstream y_yaz("yedek.dat",ios::binary | ios::app);
		
	    y_yaz.write((char*)&musteri,sizeof(musteri));
	    y_yaz.close();		
	   }
	   else if(secim=='e' || secim=='E')
	   {
	   	durum=true;
	   }
}
		else
		{
		ofstream y_yaz("yedek.dat",ios::binary | ios::app);
	    
	    y_yaz.write((char*)&musteri,sizeof(musteri));
	    y_yaz.close();
		}
	}
oku.close();
    if(durum) 
	{
		remove("m�steri.dat");
		rename("yedek.dat","musteri.dat");
		
		cout << "Randevu silindi" << endl;
	}
	else
	{
		remove("m�steri.dat");
		cout << "Randevu bulunamad�" << endl;
	}
}
   else 
   cout << "Randevu bulunamad�" << endl;
}

void RandevuDuzenle()
{
    ifstream oku("kuaf�r.dat",ios::binary | ios::app);
	oku.seekg(0,ios::end);
	int kayit=oku.tellg()/sizeof(musteri);
	
	cout << endl;
	
	char secim;
	char telefonn[10];
	bool durum=false;
	cout << "Randevusu D�zenlenecek M��terinin Telefon Numaras�n� Giriniz: " ;
	cin >> telefonn;
	
	if(kayit>0)
	{
	for(int i=0;i<kayit;i++)
	{
		oku.seekg(i*sizeof(musteri));
		oku.read((char*)&musteri,sizeof(musteri));
		
		if(strcmp(musteri.telefon,telefonn)==0)
		{
		cout << "\nRandevusu D�zenlenecek M��terinin Bilgileri" << endl;
		cout << "M��terinin Ad�: " << musteri.ad << endl;
		cout << "M��terinin Soyad�: " << musteri.soyad << endl;
		cout << "M��terinin Telefon Numaras�: " << musteri.telefon << endl;
		cout << "Randevu Tarihi: " << musteri.tarih << endl;
		cout << "Randevu Saati: " << musteri.saat << endl;
		
		cout << "Randevusu d�zenlenecek m��teri bu mu? (e/h): " ;	
		
		secim=getche(); 
		
		if(secim=='h' || secim=='H')
		{
			
		ofstream y_yaz("yedek.dat",ios::binary | ios::app);
		
	    y_yaz.write((char*)&musteri,sizeof(musteri));
	    y_yaz.close();		
	   }
	   else if(secim=='e' || secim=='E')
	   {
	   	durum=true;
	   	
	ofstream y_yaz("yedek.dat",ios::binary | ios::app);
	   	
	           cout << endl;
	           cout << "M��terinin Ad�n� Giriniz: " ;
	           cin >> musteri.ad ;
	           cout << "M��terinin Soyad�n� Giriniz: " ;
	           cin >> musteri.soyad ;
	           cout << "M��terinin Telefon Numaras�n� Giriniz: " ;
	           cin >> musteri.telefon ;
	           cout << "Randevu Olu�turulacak Tarihi Giriniz: " ;
	           cin >> musteri.tarih ;
	           cout << "Randevu Olu�turulacak Saati Giriniz: " ;
	           cin >> musteri.saat ;
	           
	y_yaz.write((char*)&musteri,sizeof(musteri));
	y_yaz.close();           
	   	
	   }
}
		else
		{
		ofstream y_yaz("yedek.dat",ios::binary | ios::app);
	    
	    y_yaz.write((char*)&musteri,sizeof(musteri));
	    y_yaz.close();
		}
	}
oku.close();
    if(durum) 
	{
		remove("m�steri.dat");
		rename("yedek.dat","musteri.dat");
		
		cout << "Randevu D�zenlendi." << endl;
	}
	else
	{
		remove("m�steri.dat");
		cout << "Randevu bulunamad�" << endl;
	}

 }
    else
    cout << "Randevu bulunamad�" << endl;
}

void FiyatListe()
{
	ofstream yaz("kuaf�r.dat",ios::binary | ios::app);
	
	cout << endl;
	cout << "\n-----�EK�LLEND�RME-----" << endl;
	cout << "F�n      ------> 500 TL" << endl;
	cout << "Ma�a     ------> 1000 TL" << endl;
	cout << "Topuz    ------> 1000 TL" << endl;
	cout << endl;
	cout << "---------KES�M---------" << endl;
	cout << "K�z �ocuk Kesim ------> 750 TL" << endl;
	cout << "Kad�n Kesim     ------> 1000 TL" << endl;
	cout << endl;
	cout << "------RENK VERME-------" << endl;
	cout << "Kozmetik Boya   ------> 1500-1800-2500 TL" << endl;
	cout << "Renk De�i�tirme ------> 6500-8000-10000 TL" << endl;
	cout << "Ombre           ------> 7500-9500-12000 TL" << endl;
	cout << "R�fle           ------> 7500-9500-12000 TL" << endl;
	cout << endl;
	cout << "---KALICI �EK�LLENDR�ME---" << endl;
	cout << "Perma           ------> 5500-6500-9000 TL" << endl;
	cout << "Brezilya F�n�   ------> 4000-5000-6000 TL" << endl;
	cout << endl;
	cout << "--------BAKIM---------" << endl;
	cout << "Manik�r         ------> 650 TL" << endl;
	cout << "Pedik�r         ------> 800 TL" << endl;
	cout << endl;
	cout << "-------PAKETLER-------" << endl;
	cout << "Gelin Sa�� ve Makyaj�  ------> 14000 TL" << endl;
	cout << "Ni�an Sa�� ve Makyaj�  ------> 8000 TL" << endl;
	
	yaz.close();

}













