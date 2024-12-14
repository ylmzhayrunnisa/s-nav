#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

void showEmployees() {

    // Calisan bilgilerini tutan diziler
    string names[] = { "Hayrunnisa Yılmaz", "Joudi Tafran", "Masah Jsri", "Yazal Yuce", "Cansu Piroglu", "Gulsemin Ozgur" };
    string emails[] = { "jouditafran271@gmail.com", "nisa.yilmaz@example.com", "Masah.Jsri@example.com",
                       "Yazal.Yuce@example.com", "Cansu.Piroglu@example.com", "Gulsemin.Ozgur@example.com" };
    string phones[] = { "0542842928", "05724682479", "0544765887", "0566481737", "05267687248", "05723648176" };
    string departments[] = { "Yoneticisi CEO", "Genel Mudur", "Basim-Yayin Yoneticisi", "Editor", "Insan Kaynaklari Muduru", "Yazar" };
    int numEmployees = 6;

    int choice;
    do {
        cout << "\nFIRMA CALISANLARI:\n";
        for (int i = 0; i < numEmployees; ++i) {
            cout << (i + 1) << ". " << names[i] << " - " << departments[i] << "\n";
        }
        cout << "7. Geri Don\n";
        cout << "Seciminiz: ";
        cin >> choice;

        if (choice >= 1 && choice <= numEmployees) {
            int index = choice - 1;
            cout << "\nBilgiler:\n";
            cout << "Isim: " << names[index] << "\n";
            cout << "E-posta: " << emails[index] << "\n";
            cout << "Telefon: " << phones[index] << "\n\n";
        }
        else if (choice != 7) {
            cout << "\nGecersiz bir secim yaptiniz. Lutfen tekrar deneyin.\n";
        }
    } while (choice != 7);
}
void firmaTanitim() {
    cout << " \nMJHYGC Kitap, tum dunyadaki eserlerin satin alinabildigi bir firmadir.";
}
void urunIncelemeVeAlisveris() {
    string names[] = { "Suc ve Ceza", "Gurur ve Onyargi", "Yeraltindan Notlar", "Commandos", "Pro Evolution Soccer" };
    string k_Tanitim[] = { "Fyodor DOSTOYEVSKI", "Jane AUSTEN", "Fyodor Mihayloviç",
                           "Taktik tabanli savas oyunu", "Futbol tutkunlarina ozel" };
    int Fiyat[] = { 90, 67, 88, 45, 79 };

    int numUrun = 5;
    int choice;
    int toplam = 0;

    int cartIndices[100] = { 0 };
    int cartQuantities[100] = { 0 };
    int cartSize = 0;

    do {
        cout << "\nUrunlerimiz:\n";
        for (int i = 0; i < numUrun; ++i) {
            cout << (i + 1) << ". " << names[i] << " - " << k_Tanitim[i] << " - " << Fiyat[i] << " TL\n";
        }
        cout << "6. Sepeti goruntule\n";
        cout << "7. Alisverisi Tamamla\n";
        cout << "8. Geri Don\n";
        cout << "-------------------------\n";
        cout << "Seciminizi yapiniz: ";
        cin >> choice;

        if (choice >= 1 && choice <= numUrun) {
            int adet;
            cout << names[choice - 1] << " urununden kac adet eklemek istersiniz: ";
            cin >> adet;

            cartIndices[cartSize] = choice - 1;
            cartQuantities[cartSize] = adet;
            cartSize++;

            int urunToplam = Fiyat[choice - 1] * adet;
            toplam += urunToplam;

            cout << names[choice - 1] << "    " << adet << " Adet  Toplam: " << urunToplam << " TL\n";
            cout << "-------------------------\n";
        }
        else if (choice == 6) {
            cout << "Sepetinizdeki Urunler:\n";
            cout << "-------------------------\n";
            for (int i = 0; i < cartSize; ++i) {
                int index = cartIndices[i];
                cout << names[index] << "    " << cartQuantities[i] << " Adet  Toplam: "
                    << Fiyat[index] * cartQuantities[i] << " TL\n";
            }
            cout << "-------------------------\n";
            cout << "Sepet Toplami: " << toplam << " TL\n";
        }
        else if (choice == 7) {
            cout << "\nAlisverisi tamamladiniz! Toplam Tutar: " << toplam << " TL\n";
            int taksit;
            cout << "Lutfen taksit sayisini seciniz (0-36): ";
            cin >> taksit;

            if (taksit > 0 && taksit <= 36) {
                double aylikOdeme = static_cast<double>(toplam) / taksit;
                cout << "Taksit Secimi: " << taksit << " ay. Aylik Odeme: " << aylikOdeme << " TL\n";
            }
            else if (taksit == 0) {
                cout << "Odeme tek seferde yapilacak. Toplam Tutar: " << toplam << " TL\n";
            }
            else {
                cout << "Gecersiz taksit secimi. Tek seferde odeme olarak kabul edildi.\n";
            }

            // Save the invoice to a file
            ofstream fatura("fatura.txt");

            fatura << "FATURA\n";
            fatura << "-------------------------\n";
            for (int i = 0; i < cartSize; ++i) {
                int index = cartIndices[i];
                fatura << names[index] << "    " << cartQuantities[i] << " Adet  Toplam: "
                    << Fiyat[index] * cartQuantities[i] << " TL\n";
            }
            fatura << "-------------------------\n";
            fatura << "Toplam Tutar: " << toplam << " TL\n";
            if (taksit > 0) {
                fatura << "Taksit Sayisi: " << taksit << "\n";
                fatura << "Aylik Odeme: " << static_cast<double>(toplam) / taksit << " TL\n";
            }
            else {
                fatura << "Odeme Tek Seferde Yapilacak.\n";
            }
            fatura << "-------------------------\n";
            fatura << "Alisveris icin tesekkur ederiz!\n";
            fatura.close();

            cout << "Faturaniz 'fatura.txt' dosyasina kaydedildi.\n";
            break;
        }
        else if (choice != 8) {
            cout << "\nGecersiz bir secim yaptiniz. Lutfen tekrar deneyin.\n";
        }
    } while (choice != 8);
}


int main() {
    int choice;

    do {
        cout << "\nANA MENU:\n";
        cout << "1. Firma Hakkinda\n";
        cout << "2. Urun Inceleme ve Alisveris\n";
        cout << "3. Cikis\n";
        cout << "Seciminiz: ";
        cin >> choice;

        switch (choice) {
        case 1:
            firmaTanitim();
            showEmployees();
            break;
        case 2:
            urunIncelemeVeAlisveris();
            break;
        case 3:
            cout << "\nCikis yapiliyor...\n";
            break;
        default:
            cout << "\nGecersiz bir secim yaptiniz. Lutfen tekrar deneyin.\n";
        }
    } while (choice != 3);



    system("pause");
    return 0;
}