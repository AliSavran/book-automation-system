#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int max_kitap_sayisi = 100;

class kitap {
private:
    string ad;
    string yazar;
    string tur;
    int sayfa_sayisi;
    int basim_yili;

public:
    // Parametreli kurucu işlev
    kitap(string ad, string yazar, string tur, int sayfa_sayisi, int basim_yili) {
        this->ad = ad;
        this->yazar = yazar;
        this->tur = tur;
        this->sayfa_sayisi = sayfa_sayisi;
        this->basim_yili = basim_yili;
    }

    // Varsayılan kurucu işlev
    kitap() {
        ad = "";
        yazar = "";
        tur = "";
        sayfa_sayisi = 0;
        basim_yili = 0;
    }

    string kitap_bilgileri() {
        return "Ad: " + ad + ", Yazar: " + yazar + ", Tur: " + tur + ", Sayfa sayisi: " + to_string(sayfa_sayisi) + ", Basim yili: " + to_string(basim_yili);
    }

    string get_tur() {
        return tur;
    }
};

class Kutuphane {
private:
    kitap kitaplar[max_kitap_sayisi];
    int kitapSayisi;

public:
    Kutuphane() : kitapSayisi(0), kitaplar{} {} // kitaplar dizisini boş değerlerle başlatır

    void kitap_ekle(string ad, string yazar, string tur, int sayfa_sayisi, int basim_yili) {
        if (kitapSayisi < max_kitap_sayisi) {
            kitap yeni_kitap(ad, yazar, tur, sayfa_sayisi, basim_yili);
            kitaplar[kitapSayisi++] = yeni_kitap;
            cout << ad << " isimli kitap kutuphaneye eklendi. " << endl;
        }
        else {
            cout << "Kutuphane dolu oldugu icin yeni kitap eklenemedi..." << endl;
        }
    }

    void kitap_liste(string tur) {
        bool var = false;
        for (int i = 0; i < kitapSayisi; i++) {
            if (kitaplar[i].get_tur() == tur) {
                if (!var) {
                    cout << "Kutuphanede bulunan " << tur << " turundeki kitaplar : " << endl;
                    var = true;
                }
                cout << i + 1 << ". " << kitaplar[i].kitap_bilgileri() << endl;
            }
        }
        if (!var) {
            cout << "Kutuphanede " << tur << " turunde kitap bulunmamaktadir...." << endl;
        }
    }

    void kitap_satinal(int index) {
        if (index >= 0 && index < kitapSayisi) {
            cout << kitaplar[index].kitap_bilgileri() << " satin alindi.";
            for (int i = index; i < kitapSayisi - 1; i++) {
                kitaplar[i] = kitaplar[i + 1];
            }
            kitapSayisi--;
        }
        else {
            cout << "Gecersiz kitap no..." << endl;
        }
    }
};

int main() {
    Kutuphane kutuphane;
    int secim;

    while (true) {

        cout << " ------ Kutuphane Yonetim Sistemi ------" << endl;
        cout << "1. Kitap ekleme" << endl;
        cout << "2. Roman turundeki kitaplar" << endl;
        cout << "3. Biyografi turundeki kitaplar" << endl;
        cout << "4. Tarih turundeki kitaplar" << endl;
        cout << "5. Korku turundeki kitaplar" << endl;
        cout << "6. Cikis" << endl;

        cout << "Hangi islemi yapmak istersiniz : ";
        cin >> secim;

        switch (secim) {

        case 1: {

            string ad, yazar, tur;
            int sayfa_sayisi, basim_yili;

            cout << "Kitap adi : ";
            cin.ignore();
            getline(cin, ad);

            cout << "Kitap yazari : ";
            getline(cin, yazar);

            cout << "Kitap turu : ";
            getline(cin, tur);

            cout << "Kitap sayfa sayisi : ";
            cin >> sayfa_sayisi;

            cout << "Kitap basim tarihi : ";
            cin >> basim_yili;

            kutuphane.kitap_ekle(ad, yazar, tur, sayfa_sayisi, basim_yili);
            break;
        }
        case 2: {

            kutuphane.kitap_liste("Roman");
            break;
        }
        case 3: {

            kutuphane.kitap_liste("Biyografi");
            break;
        }
        case 4: {

            kutuphane.kitap_liste("Tarih");
            break;
        }
        case 5: {

            kutuphane.kitap_liste("Korku");
            break;
        }
        case 6: {

            cout << "Cikis yapiliyor..." << endl;
            return 0;
        }
        default:
            cout << "Gecersiz secim...tekrar deneyiniz." << endl;
        }
    }

    return 0;
}
