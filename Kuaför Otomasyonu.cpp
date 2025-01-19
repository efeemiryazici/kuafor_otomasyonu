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
	cout << "|~~~~~Kuaför Otomasyonuna Hoþgeldiniz~~~~~|" << endl; 
    cout << "|              Seçim Yapýnýz              |" << endl; 
    cout << "|           1-Randevu Oluþturma           |" << endl; 
    cout << "|           2-Randevu Listeleme           |" << endl;
    cout << "|           3-Randevu Arama               |" << endl;
    cout << "|           4-Randevu Silme               |" << endl;
    cout << "|           5-Randevu Düzeltme            |" << endl;
    cout << "|           6-Fiyat Listesi               |" << endl;
    cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << endl;
    cout << "Seçimi giriniz: " ;
	
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
	cout << "\nAna Menüye Dönmek Ýstermisiniz? (e/h) : " ;
	secim=getche();
	
}
while(secim=='e' || secim=='E');

cout << endl;
	
	system("pause");
	return 0;
}

void RandevuOlustur()
{
	ofstream yaz("kuaför.dat",ios::binary | ios::app);
	
	char secim;
	int adet=0;
	
	do{
	cout << endl;
	cout << "Müþterinin Adýný Giriniz: " ;
	cin >> musteri.ad ;
	cout << "Müþterinin Soyadýný Giriniz: " ;
	cin >> musteri.soyad ;
	cout << "Müþterinin Telefon Numarasýný Giriniz: " ;
	cin >> musteri.telefon ;
	cout << "Randevu Oluþturulacak Tarihi Giriniz: " ;
	cin >> musteri.tarih ;
	cout << "Randevu Oluþturulacak Saati Giriniz: " ;
	cin >> musteri.saat ;
	
	yaz.write((char*)&musteri,sizeof(musteri));
	adet++;
		
	cout << "Baþka müþteri eklemek ister misiniz? (e/h) : " ;
	secim=getche();	
	}
	while(secim=='e' || secim=='E');
	
	cout << endl;
	cout << endl;
	cout << adet << " adet müþteri eklendi" << endl;
	
	yaz.close();
}

void RandevuListele()
{
	ifstream oku("kuaför.dat",ios::binary | ios::app);
	oku.seekg(0,ios::end);
	int kayit=oku.tellg()/sizeof(musteri);
	
	cout << endl;
	
	cout << "Toplam randevu sayýsý: " << kayit << endl;
	
	cout << endl;
	
	if(kayit>0)
	{
	for(int i=0;i<kayit;i++)
	{
		oku.seekg(i*sizeof(musteri));
		oku.read((char*)&musteri,sizeof(musteri));
		
		cout << endl;
		cout << i+1 << ". Müþterinin Bilgileri" << endl;
		cout << "Müþterinin Adý: " << musteri.ad << endl;
		cout << "Müþterinin Soyadý: " << musteri.soyad << endl;
		cout << "Müþterinin Telefon Numarasý: " << musteri.telefon << endl;
		cout << "Randevu Tarihi: " << musteri.tarih << endl;
		cout << "Randevu Saati: " << musteri.saat << endl;
		cout << endl;
		cout << "---------------------------" << endl;
	}
	oku.close();
	}
	else
	cout << "Randevu Bulunamadý" << endl;
	cout << endl;
	
}

void RandevuAra()
{
	ifstream oku("kuaför.dat",ios::binary | ios::app);
	oku.seekg(0,ios::end);
	int kayit=oku.tellg()/sizeof(musteri);
	
	cout << endl;
	
	char telefonn[10];
	cout << "Randevusu Aranacak Müþterinin Telefon Numarasýný Giriniz: " ;
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
		cout << "Randevusu Bulunan Müþterinin Bilgileri" << endl;
		cout << "Müþterinin Adý: " << musteri.ad << endl;
		cout << "Müþterinin Soyadý: " << musteri.soyad << endl;
		cout << "Müþterinin Telefon Numarasý: " << musteri.telefon << endl;
		cout << "Randevu Tarihi: " << musteri.tarih << endl;
		cout << "Randevu Saati: " << musteri.saat << endl;		
		}
	}
	oku.close();
	}
	else
	cout << "\nRandevu bulunamadý" << endl;
}

void RandevuSil()
{
    ifstream oku("kuaför.dat",ios::binary | ios::app);
	oku.seekg(0,ios::end);
	int kayit=oku.tellg()/sizeof(musteri);
	
	cout << endl;
	
	char secim;
	char telefonn[10];
	bool durum=false;
	cout << "Randevusu Silinecek Müþterinin Telefon Numarasýný Giriniz: " ;
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
		cout << "Randevusu Silinecek Müþterinin Bilgileri" << endl;
		cout << "Müþterinin Adý: " << musteri.ad << endl;
		cout << "Müþterinin Soyadý: " << musteri.soyad << endl;
		cout << "Müþterinin Telefon Numarasý: " << musteri.telefon << endl;
		cout << "Randevu Tarihi: " << musteri.tarih << endl;
		cout << "Randevu Saati: " << musteri.saat << endl;
		
		cout << "Randevusu silinecek müþteri bu mu? (e/h): " ;	
		
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
		remove("müsteri.dat");
		rename("yedek.dat","musteri.dat");
		
		cout << "Randevu silindi" << endl;
	}
	else
	{
		remove("müsteri.dat");
		cout << "Randevu bulunamadý" << endl;
	}
}
   else 
   cout << "Randevu bulunamadý" << endl;
}

void RandevuDuzenle()
{
    ifstream oku("kuaför.dat",ios::binary | ios::app);
	oku.seekg(0,ios::end);
	int kayit=oku.tellg()/sizeof(musteri);
	
	cout << endl;
	
	char secim;
	char telefonn[10];
	bool durum=false;
	cout << "Randevusu Düzenlenecek Müþterinin Telefon Numarasýný Giriniz: " ;
	cin >> telefonn;
	
	if(kayit>0)
	{
	for(int i=0;i<kayit;i++)
	{
		oku.seekg(i*sizeof(musteri));
		oku.read((char*)&musteri,sizeof(musteri));
		
		if(strcmp(musteri.telefon,telefonn)==0)
		{
		cout << "\nRandevusu Düzenlenecek Müþterinin Bilgileri" << endl;
		cout << "Müþterinin Adý: " << musteri.ad << endl;
		cout << "Müþterinin Soyadý: " << musteri.soyad << endl;
		cout << "Müþterinin Telefon Numarasý: " << musteri.telefon << endl;
		cout << "Randevu Tarihi: " << musteri.tarih << endl;
		cout << "Randevu Saati: " << musteri.saat << endl;
		
		cout << "Randevusu düzenlenecek müþteri bu mu? (e/h): " ;	
		
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
	           cout << "Müþterinin Adýný Giriniz: " ;
	           cin >> musteri.ad ;
	           cout << "Müþterinin Soyadýný Giriniz: " ;
	           cin >> musteri.soyad ;
	           cout << "Müþterinin Telefon Numarasýný Giriniz: " ;
	           cin >> musteri.telefon ;
	           cout << "Randevu Oluþturulacak Tarihi Giriniz: " ;
	           cin >> musteri.tarih ;
	           cout << "Randevu Oluþturulacak Saati Giriniz: " ;
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
		remove("müsteri.dat");
		rename("yedek.dat","musteri.dat");
		
		cout << "Randevu Düzenlendi." << endl;
	}
	else
	{
		remove("müsteri.dat");
		cout << "Randevu bulunamadý" << endl;
	}

 }
    else
    cout << "Randevu bulunamadý" << endl;
}

void FiyatListe()
{
	ofstream yaz("kuaför.dat",ios::binary | ios::app);
	
	cout << endl;
	cout << "\n-----ÞEKÝLLENDÝRME-----" << endl;
	cout << "Fön      ------> 500 TL" << endl;
	cout << "Maþa     ------> 1000 TL" << endl;
	cout << "Topuz    ------> 1000 TL" << endl;
	cout << endl;
	cout << "---------KESÝM---------" << endl;
	cout << "Kýz Çocuk Kesim ------> 750 TL" << endl;
	cout << "Kadýn Kesim     ------> 1000 TL" << endl;
	cout << endl;
	cout << "------RENK VERME-------" << endl;
	cout << "Kozmetik Boya   ------> 1500-1800-2500 TL" << endl;
	cout << "Renk Deðiþtirme ------> 6500-8000-10000 TL" << endl;
	cout << "Ombre           ------> 7500-9500-12000 TL" << endl;
	cout << "Röfle           ------> 7500-9500-12000 TL" << endl;
	cout << endl;
	cout << "---KALICI ÞEKÝLLENDRÝME---" << endl;
	cout << "Perma           ------> 5500-6500-9000 TL" << endl;
	cout << "Brezilya Fönü   ------> 4000-5000-6000 TL" << endl;
	cout << endl;
	cout << "--------BAKIM---------" << endl;
	cout << "Manikür         ------> 650 TL" << endl;
	cout << "Pedikür         ------> 800 TL" << endl;
	cout << endl;
	cout << "-------PAKETLER-------" << endl;
	cout << "Gelin Saçý ve Makyajý  ------> 14000 TL" << endl;
	cout << "Niþan Saçý ve Makyajý  ------> 8000 TL" << endl;
	
	yaz.close();

}













