#include <iostream>
using namespace std;

class bankaHesabý {
private:
	string sahipAdi;
	double bakiye;

public:
	bankaHesabý(string ad, double baslangicBakiyesi) {
		sahipAdi = ad;
		bakiye = baslangicBakiyesi;
	}

	void paraYatirma(double miktar) {
		bakiye += miktar;
		cout << "Hesabiniza " << miktar << " TL Para Yatirildi! Yeni Bakiyeniz: " << bakiye << endl;
	}

	void paraCekme(double miktar) {
		if (miktar <= bakiye) {
			bakiye -= miktar;
			cout << "Hesabinizdan " << miktar << " TL Para Cekildi! Yeni Bakiyeniz: " << bakiye << endl;
		}

		else {
			cout << "Yetersiz Bakiye!!";
		}
	}

	void guncelBakiye() {
		cout << "Hesabinizin Bakiyesi: " << bakiye << " TL dir. " << endl;
	}

};



int main() {
	cout << "------------------------Banka Hesabi Yonetim Uygulamasina Hosgeldiniz------------------------" << endl << endl;
	string ad;
	cout << "Hesabinizin adini giriniz(Bitisik bir sekilde): ";
	cin >> ad;
	cout << "Hesap adi: " << ad << endl;

	double baslangicBakiyesi;
	cout << "Baslangic Bakiyesini Giriniz: ";
	cin >> baslangicBakiyesi;

	bankaHesabý hesap(ad, baslangicBakiyesi);

	char secim;

	do {
		cout << "\n1.Para Yatirma\n2.Para Cekme\n3.Bakiye Sorgulama\n4.Cikis\nSeciminizi yapin: ";
		cin >> secim;

		switch (secim) {
		case '1':
			double yatirilacakMiktar;
			cout << "Yatirilacak miktari giriniz: ";
			cin >> yatirilacakMiktar;
			hesap.paraYatirma(yatirilacakMiktar);
			break;

		case '2':
			double cekilecekMiktar;
			cout << "Cekilecek miktari giriniz: ";
			cin >> cekilecekMiktar;
			hesap.paraCekme(cekilecekMiktar);
			break;

		case '3':
			hesap.guncelBakiye();
			break;

		case '4':
			cout << "\aProgramdan Cikiliyor..." << endl << endl;
			break;

		default:
			cout << "Gecersiz secim! lutfen tekrar deneyiniz..." << endl;
		}

	} while (secim != '4');
	

	return 0;
}