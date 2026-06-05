#include <stdio.h>
#include <locale.h> /* Türkçe karakterler için kütüphane */
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> /* SLEEP */

/* global degiþkenler */
char globalUye[50];
int globalYonetici;

/* fonksiyon prototipleri */
void gecersizSecim();
void islemTamamlandi();
void girdiTemizle();
void girisEkrani();
void kayitEkrani();
void menu();
void girisMenu();


int kimlikDogrulama(char *kullaniciAdi, char *sifre, int yoneticiMi);
void kucukHarfYap(char *str);
void rastgeleCizim();
void sil();

/* oyun fonksiyonlari */
void oyunAra();
void oyunEkle();
void oyunHepsi();
void oyunSil();
void oyunSatinAl();
void oyunIade();
void tumSatinAlinanOyunlar();

/* structlar */
struct Uye {
    char uyeAd[50];
    char sifre[50];
    int yoneticiMi; /* Yönetici için 1, kullanici ise 0 kontrol */
};

struct Oyun {
    char ad[256];
    char gelistirici[256];
    char tur[256];
    int fiyat;
};

int main() {
    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t $$\\   $$\\  $$$$$$\\   $$$$$$\\\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t $$ |  $$ |$$  __$$\\ $$  __$$\\ \n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t $$ |  $$ |$$ /  $$ |$$ /  \\__|\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t $$$$$$$$ |$$ |  $$ |\\$$$$$$\\\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t $$  __$$ |$$ |  $$ | \\____$$\\\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t $$ |  $$ |$$ |  $$ |$$\\   $$ |\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t $$ |  $$ | $$$$$$  |\\$$$$$$  |\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t \\__|  \\__| \\______/  \\______/\n");
    printf("\t\t\t\t\t\t\t\t\t\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t  $$$$$$\\  $$$$$$$$\\ $$\\       $$$$$$$\\  $$$$$$\\ $$\\   $$\\ $$$$$$\\ $$$$$$$$\\\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t $$  __$$\\ $$  _____|$$ |      $$  __$$\\ \\_$$  _|$$$\\  $$ |\\_$$  _|\\____$$  |\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t $$ /  \\__|$$ |      $$ |      $$ |  $$ |  $$ |  $$$$\\ $$ |  $$ |      $$  /\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t $$ |$$$$\\ $$$$$\\    $$ |      $$ |  $$ |  $$ |  $$ $$\\$$ |  $$ |     $$  /\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t $$ |\\_$$ |$$  __|   $$ |      $$ |  $$ |  $$ |  $$ \\$$$$ |  $$ |    $$  /\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t $$ |  $$ |$$ |      $$ |      $$ |  $$ |  $$ |  $$ |\\$$$ |  $$ |   $$  /\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t \\$$$$$$  |$$$$$$$$\\ $$$$$$$$\\ $$$$$$$  |$$$$$$\\ $$ | \\$$ |$$$$$$\\ $$$$$$$$\\\n");
    usleep(200000);
    printf("\t\t\t\t\t\t\t\t\t  \\______/ \\________|\\________|\\_______/ \\______|\\__|  \\__|\\______|\\________|\n");
    sleep(3);
    sil();

    globalYonetici = 3; /* giris yapmadan önce önemsiz bir degere atanir */
    sil(); /* Konsolu temizle */

    setlocale(LC_ALL, "Turkish"); /* Türkçe karakter destegi */
    girisMenu(); /* Giris menüsünü göster */
    return 0;
}

void gecersizSecim() {
    printf("\t\t\t\t\t\t\t\t\t\tGEÇERSÝZ SEÇÝM, iki saniye içinde ana menüye dönülüyor\n");
    printf("\t\t\t\t\t\t\t\t\t\t=================================================\n");
    sleep(2);
    sil();   /* CLEAR SCREEN */
    girisMenu();
}

void islemTamamlandi() {
    printf("\n\t\t\t\t\t\t\t\t\t\tÝþlem Tamamlandý\n");
    printf("\t\t\t\t\t\t\t\t\t\tAna menüye dönmek için herhangi bir tuþa basýnýz.\n");
    printf("\t\t\t\t\t\t\t\t\t\t=================================================\n");
    getchar();/* herhangi bir girdi al */
    girdiTemizle();
    sil(); /* ekran temizle */
    menu();
}

void girdiTemizle() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void kucukHarfYap(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void girisMenu() {
    globalYonetici = 5; /* bug engelleyici */
    sil(); /* Konsolu temizle */

    rastgeleCizim();

    int secim;
    printf("\n\n\t\t\t\t\t\t\t\t\t\tGÝRÝÞ MENÜSÜ\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t1- Giriþ Yap\n");
    printf("\t\t\t\t\t\t\t\t\t\t2- Kayýt Ol\n");
    printf("\t\t\t\t\t\t\t\t\t\t3- Uygulamayý Kapat\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t=================================================\n\n");

    printf("\t\t\t\t\t\t\t\t\t\tLütfen Seçiminizi Yapýnýz: ");
    scanf("%d", &secim);

    girdiTemizle();

    switch (secim) {
        case 1:
            girisEkrani();
            break;
        case 2:
            kayitEkrani();
            break;
        case 3:
            exit(0);
        default:
            gecersizSecim();
            break;
    }
}

void girisEkrani() {
    char uyeAd[50];
    char sifre[50];
    printf("\n\n\t\t\t\t\t\t\t\t\t\tKullanýcý adýný giriniz: ");
    scanf("%s", uyeAd);
    printf("\n\t\t\t\t\t\t\t\t\t\tÞifrenizi giriniz: ");
    scanf("%s", sifre);

    if (kimlikDogrulama(uyeAd, sifre, 0) || kimlikDogrulama(uyeAd, sifre, 1)) {
        printf("\n\n\t\t\t\t\t\t\t\t\t\tGiriþ Baþarýlý!\n");
        
        /* globalUser degiskenini uyeAd olarak ata */
        strcpy(globalUye, uyeAd);

        printf("\n\t\t\t\t\t\t\t\t\t\tDEBUG -- %s, %d", globalUye, globalYonetici);
        menu();
    } else {
    	printf("\n\t\t\t\t\t\t\t\t\t\t=========================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Giriþ baþarýsýz, geçersiz bilgiler. ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t=========================================\n");
        girisMenu();
    }
}

void kayitEkrani() {
    struct Uye yeniUye;
    int kayit1;
    int teyit;

    printf("\n\n\t\t\t\t\t\t\t\t\t\tKullanýcý adýný giriniz: ");
    scanf("%s", yeniUye.uyeAd);

    printf("\n\t\t\t\t\t\t\t\t\t\tÞifrenizi giriniz: ");
    scanf("%s", yeniUye.sifre);

    printf("\n\n\t\t\t\t\t\t\t\t\t\t1- Kullanýcý Olarak Kaydet\n");
    printf("\t\t\t\t\t\t\t\t\t\t2- Yönetici Olarak Kaydet\n");
    scanf("%d", &kayit1);

    switch (kayit1) {
        case 1:
            yeniUye.yoneticiMi = 0;
            printf("\n\n\t\t\t\t\t\t\t\t\t\tKullanýcý Olarak Kaydedildi, ");
            goto kayit;
        case 2:
            girdiTemizle();
            printf("\n\n\t\t\t\t\t\t\t\t\t\tYönetici teyit þifresini giriniz: ");
            scanf("%d", &teyit);
            if (teyit == 777) {
                yeniUye.yoneticiMi = 1;
                printf("\n\n\t\t\t\t\t\t\t\t\t\tYönetici olarak kaydedildi, ");
                goto kayit;
            } else {
                printf("\n\n\t\t\t\t\t\t\t\t\t\tTeyit þifresi yanlýþ, giriþ ekranýna dönülüyor.\n");
                girisMenu();
            }
            break;
        default:
            printf("\n\n\t\t\t\t\t\t\t\t\t\tGeçersiz seçim, giriþ ekranýna dönülüyor.\n");
            girisMenu();
    }

kayit: ;

    /* kullanici veri dosyasini ekleme modunda aç */
    FILE *file = fopen("data/uyeDosya/uyeler.txt", "a");
    if (file == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\tDosya açýlamadý!\n");
        exit(1);
    }

    /* yeni kullaniciyi kaydet */
    fprintf(file, "%s %s %d\n", yeniUye.uyeAd, yeniUye.sifre, yeniUye.yoneticiMi);

    /* dosyayi kapat */
    fclose(file);

    printf("\n\t\t\t\t\t\t\t\t\t\tKayýt tamamlandý, giriþ ekranýna dönülüyor.\n");

    girisMenu();
}

int kimlikDogrulama(char *uyeAd, char *sifre, int yoneticiMi) 
{
    struct Uye uye;
    FILE *file = fopen("data/uyeDosya/uyeler.txt", "r");

    /* Dosyayi aç */
    if (file == NULL) {
    	printf("\n\t\t\t\t\t\t\t\t\t\t======================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Dosya açýlamadý! ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t======================\n");
        exit(1);
    }

    /* Her diziyi ara */
    while (fscanf(file, "%s %s %d", uye.uyeAd, uye.sifre, &uye.yoneticiMi) == 3) {
        /* struct bilgileri dogru mu kontrol et */
        if (strcmp(uyeAd, uye.uyeAd) == 0 && strcmp(sifre, uye.sifre) == 0 && uye.yoneticiMi == yoneticiMi) {
            globalYonetici = uye.yoneticiMi;

            fclose(file);
            return 1; /* yetkilendirme tamamlandi */
        }
    }
    fclose(file);
    return 0; /* yetkilendirme basarisiz */
}

void menu() {
    sil(); /* Konsolu temizle */
    
    rastgeleCizim();

    printf("\n\n\t\t\t\t\t\t\t\t\t\tHoþgeldiniz: %s\n", globalUye);
    int secenek;

    if (globalYonetici == 1) {
        goto yonetici;
    } else if (globalYonetici == 0) {
        goto kullanici;
    } else {
        girisMenu();
    }

yonetici:
    /* ana menü tuslari */
    printf("\n\n\t\t\t\t\t\t\t\t\t\tAna Menü\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t1- Oyun Ekle\n");
    printf("\t\t\t\t\t\t\t\t\t\t2- Oyun Ara\n");
    printf("\t\t\t\t\t\t\t\t\t\t3- Tüm Oyunlarý Göster\n");
    printf("\t\t\t\t\t\t\t\t\t\t4- Oyun Sil\n");
    printf("\t\t\t\t\t\t\t\t\t\t5- Çýkýþ Yap\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t=================================================\n\n");
    printf("\t\t\t\t\t\t\t\t\t\tLütfen seçiminizi yapýn: ");

    scanf("%d", &secenek);
    girdiTemizle();

    switch (secenek) {
        case 1:
            oyunEkle();
            break;
        case 2:
            oyunAra();
            break;
        case 3:
            oyunHepsi();
            break;
        case 4:
            oyunSil();
            break;
        case 5:
            girisMenu();
            break;
        default:
            gecersizSecim();
    }
    exit(0);

kullanici:
    /* ana menü tuslari */
    printf("\n\n\t\t\t\t\t\t\t\t\t\tAna Menü\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t1- Tüm Oyunlarý Göster\n");
    printf("\t\t\t\t\t\t\t\t\t\t2- Oyun Ara\n");
    printf("\t\t\t\t\t\t\t\t\t\t3- Oyun Satýn Al/Iade Et\n");
    printf("\t\t\t\t\t\t\t\t\t\t4- Satýn Aldýðým Oyunlarý Görüntüle\n");
    printf("\t\t\t\t\t\t\t\t\t\t5- Çýkýþ Yap\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t=================================================\n\n");
    printf("\t\t\t\t\t\t\t\t\t\tLütfen seçiminizi yapýn: ");

    scanf("%d", &secenek);
    girdiTemizle();

    switch (secenek) {
        case 1:
            oyunHepsi();
            break;
        case 2:
            oyunAra();
            break;
        case 3:
            printf("\n\n\t\t\t\t\t\t\t\t\t\t1- Oyun Satýn Al\n");
            printf("\t\t\t\t\t\t\t\t\t\t2- Ýade Et\n");
            printf("\t\t\t\t\t\t\t\t\t\t3- Menüye Geri Dön\n\n");
            printf("\t\t\t\t\t\t\t\t\t\tSeçiminizi yapýnýz: ");
            scanf("%d", &secenek);
            if (secenek == 1) { oyunSatinAl(); }
            if (secenek == 2) { oyunIade(); }
            else { menu(); }
            break;
        case 4:
            tumSatinAlinanOyunlar();
            break;
        case 5:
            girisMenu();
            break;
        default:
            gecersizSecim();
    }
    exit(0);
}

void oyunEkle() {
    struct Oyun yeniOyun;

    printf("\n\n\t\t\t\t\t\t\t\t\t\tOyun adý: ");
    scanf("%s", yeniOyun.ad);
    printf("\t\t\t\t\t\t\t\t\t\tGeliþtirici: ");
    scanf("%s", yeniOyun.gelistirici);
    printf("\t\t\t\t\t\t\t\t\t\tTür: ");
    scanf("%s", yeniOyun.tur);
    printf("\t\t\t\t\t\t\t\t\t\tFiyat: ");
    scanf("%d", &yeniOyun.fiyat);

    FILE *file = fopen("data/oyunDosya/oyunlar.txt", "a");
    if (file == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\t======================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Dosya açýlamadý! ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t======================\n");
        exit(1);
    }

    fprintf(file, "%s %s %s %d\n", yeniOyun.ad, yeniOyun.gelistirici, yeniOyun.tur, yeniOyun.fiyat);

    fclose(file);

    islemTamamlandi();
}

void oyunSil() {
    char silinecekOyun[256];

    printf("\t\t\t\t\t\t\t\t\t\tSilmek istediðiniz oyunun adýný girin: ");
    scanf("%s", silinecekOyun);
    kucukHarfYap(silinecekOyun); /* küçük harfe dönüþtür */

    FILE *tempFile = fopen("data/oyunDosya/temp.txt", "w"); /* geçici dosya */
    if (tempFile == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\t======================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Dosya açýlamadý! ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t======================\n");
        exit(1);
    }

    FILE *file = fopen("data/oyunDosya/oyunlar.txt", "r");
    if (file == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\t======================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Dosya açýlamadý! ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t======================\n");
        exit(1);
    }

    struct Oyun oyun;
    int bulundu = 0;
    while (fscanf(file, "%s %s %s %d", oyun.ad, oyun.gelistirici, oyun.tur, &oyun.fiyat) == 4) {
        char kucukHarfAd[256];
        strcpy(kucukHarfAd, oyun.ad);
        kucukHarfYap(kucukHarfAd); /* küçük harfe dönüþtür */

        if (strstr(kucukHarfAd, silinecekOyun) == NULL) {
            fprintf(tempFile, "%s %s %s %d\n", oyun.ad, oyun.gelistirici, oyun.tur, oyun.fiyat);
        } else {
            bulundu = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("data/oyunDosya/oyunlar.txt");
    rename("data/oyunDosya/temp.txt", "data/oyunDosya/oyunlar.txt");

    if (bulundu) {
    	printf("\n\t\t\t\t\t\t\t\t\t\t=============================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Oyun baþarýyla silindi. ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t=============================\n");
    } else {
    	printf("\n\t\t\t\t\t\t\t\t\t\t=========================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Silmek istediðiniz oyun bulunamadý. ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t=========================================\n");
    }

    islemTamamlandi();
}

void oyunAra() {
    char aranan[256];

    printf("\t\t\t\t\t\t\t\t\t\tAramak istediðiniz oyunu girin: ");
    scanf("%s", aranan);
    kucukHarfYap(aranan); /* küçük harfe dönüþtür */

    FILE *file = fopen("data/oyunDosya/oyunlar.txt", "r");
    if (file == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\t======================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Dosya açýlamadý! ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t======================\n");
        exit(1);
    }

    struct Oyun oyun;

    int bulundu = 0;
    while (fscanf(file, "%s %s %s %d", oyun.ad, oyun.gelistirici, oyun.tur, &oyun.fiyat) == 4) {
        char kucukHarfAd[256];
        strcpy(kucukHarfAd, oyun.ad);
        kucukHarfYap(kucukHarfAd); /* küçük harfe dönüþtür */

        if (strstr(kucukHarfAd, aranan) != NULL) {
            printf("\n\t\t\t\t\t\t\t\t\t\tOyun Adý: %s\n", oyun.ad);
            printf("\t\t\t\t\t\t\t\t\t\tGeliþtirici: %s\n", oyun.gelistirici);
            printf("\t\t\t\t\t\t\t\t\t\tTür: %s\n", oyun.tur);
            printf("\t\t\t\t\t\t\t\t\t\tFiyat: %d TL\n\n", oyun.fiyat);
            bulundu = 1;
        }
    }

    fclose(file);

    if (!bulundu) {
    	printf("\n\t\t\t\t\t\t\t\t\t\t=================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Aradýðýnýz oyun bulunamadý. ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t=================================\n");
    }

    islemTamamlandi();
}

void oyunHepsi() {
    FILE *file = fopen("data/oyunDosya/oyunlar.txt", "r");
    if (file == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\t======================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Dosya açýlamadý! ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t======================\n");
        exit(1);
    }

    struct Oyun oyun;
    while (fscanf(file, "%s %s %s %d", oyun.ad, oyun.gelistirici, oyun.tur, &oyun.fiyat) == 4) {
        printf("\n\t\t\t\t\t\t\t\t\t\tOyun Adý: %s\n", oyun.ad);
        printf("\t\t\t\t\t\t\t\t\t\tGeliþtirici: %s\n", oyun.gelistirici);
        printf("\t\t\t\t\t\t\t\t\t\tTür: %s\n", oyun.tur);
        printf("\t\t\t\t\t\t\t\t\t\tFiyat: %d TL\n\n", oyun.fiyat);
        printf("\t\t\t\t\t\t\t\t\t\t=================================================\n");
    }

    fclose(file);

    islemTamamlandi();
}

void oyunSatinAl() {
    char satinAlinanOyun[256];

    printf("\t\t\t\t\t\t\t\t\t\tSatýn almak istediðiniz oyunun adýný girin: ");
    scanf("%s", satinAlinanOyun);
    kucukHarfYap(satinAlinanOyun); /* küçük harfe dönüþtür */

    FILE *file = fopen("data/oyunDosya/oyunlar.txt", "r");
    if (file == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\t======================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Dosya açýlamadý! ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t======================\n");
        exit(1);
    }

    struct Oyun oyun;
    int bulundu = 0;
    while (fscanf(file, "%s %s %s %d", oyun.ad, oyun.gelistirici, oyun.tur, &oyun.fiyat) == 4) {
        char kucukHarfAd[256];
        strcpy(kucukHarfAd, oyun.ad);
        kucukHarfYap(kucukHarfAd); /* küçük harfe dönüþtür */

        if (strstr(kucukHarfAd, satinAlinanOyun) != NULL) {
            bulundu = 1;

            /* Satýn alýnan oyunun zaten satýn alýnýp alýnmadýðýný kontrol et */
            FILE *satinalinanFile = fopen("data/SADosya/satinAlinanlar.txt", "r");
            if (satinalinanFile == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\t======================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Dosya açýlamadý! ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t======================\n");
                exit(1);
            }

            char uyeAd[50], oyunAdi[256];
            int zatenAlinmis = 0;
            while (fscanf(satinalinanFile, "%s %s", uyeAd, oyunAdi) == 2) {
                if (strcmp(globalUye, uyeAd) == 0 && strcmp(oyun.ad, oyunAdi) == 0) {
                    zatenAlinmis = 1;
                    break;
                }
            }
            fclose(satinalinanFile);

            if (zatenAlinmis) {
            	printf("\n\t\t\t\t\t\t\t\t\t\t===================================\n");
                printf("\t\t\t\t\t\t\t\t\t\t|| Bu oyunu zaten satýn aldýnýz. ||\n");
                printf("\t\t\t\t\t\t\t\t\t\t===================================\n");
            } else {
                /* Satýn alinan oyunu satin alinanlar listesine ekleyelim */
                satinalinanFile = fopen("data/SADosya/satinAlinanlar.txt", "a");
                if (satinalinanFile == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\t======================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Dosya açýlamadý! ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t======================\n");
                    exit(1);
                }

                fprintf(satinalinanFile, "%s %s %s\n", globalUye, oyun.ad, oyun.gelistirici);
                fclose(satinalinanFile);
                printf("\n\t\t\t\t\t\t\t\t\t\t==================================\n");
                printf("\t\t\t\t\t\t\t\t\t\t|| Oyun baþarýyla satýn alýndý. ||\n");
                printf("\t\t\t\t\t\t\t\t\t\t==================================\n");
            }
        }
    }

    fclose(file);

    if (!bulundu) {
    	printf("\n\t\t\t\t\t\t\t\t\t\t==============================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Satýn almak istediðiniz oyun bulunamadý. ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t==============================================\n");
    }

    islemTamamlandi();
}

void oyunIade() {
    char iadeOyun[256];

    printf("\n\n\t\t\t\t\t\t\t\t\t\tÝade etmek istediðiniz oyunun adýný girin: ");
    scanf("%s", iadeOyun);
    kucukHarfYap(iadeOyun); /* küçük harfe dönüþtür */

    FILE *file = fopen("data/SADosya/satinAlinanlar.txt", "r");
    if (file == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\t======================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Dosya açýlamadý! ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t======================\n");
        exit(1);
    }

    FILE *tempFile = fopen("data/SADosya/temp.txt", "w");
    if (tempFile == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\t======================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Dosya açýlamadý! ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t======================\n");
        fclose(file);
        exit(1);
    }

    char uyeAd[50], oyunAdi[256];
    int bulundu = 0;
    while (fscanf(file, "%s %s", uyeAd, oyunAdi) == 2) {
        if (strcmp(globalUye, uyeAd) == 0 && strstr(oyunAdi, iadeOyun) != NULL) {
            bulundu = 1;
        } else {
            fprintf(tempFile, "%s %s\n", uyeAd, oyunAdi);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("data/SADosya/satinAlinanlar.txt");
    rename("data/SADosya/temp.txt", "data/SADosya/satinAlinanlar.txt");

    if (bulundu) {
    	printf("\n\t\t\t\t\t\t\t\t\t\t=================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Oyun baþarýyla iade edildi. ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t=================================\n");
    } else {
    	printf("\n\t\t\t\t\t\t\t\t\t\t=================================================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Ýade etmek istediðiniz oyun bulunamadý veya size ait deðil. ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t=================================================================\n");
    }

    islemTamamlandi();
}

void tumSatinAlinanOyunlar() {
    FILE *file = fopen("data/SADosya/satinAlinanlar.txt", "r");
    if (file == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\t======================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Dosya açýlamadý! ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t======================\n");
        exit(1);
    }

    struct Oyun oyun;
    int bulundu = 0;
    while (fscanf(file, "%s %s", oyun.gelistirici, oyun.ad) == 2) {
        if (strcmp(globalUye, oyun.gelistirici) == 0) {
            printf("\n\n\t\t\t\t\t\t\t\t\t\tOyun Adý: %s\n", oyun.ad);
            printf("\t\t\t\t\t\t\t\t\t\tSatýn Alan Hesap: %s\n\n", oyun.gelistirici);
            printf("\t\t\t\t\t\t\t\t\t\t=================================================\n\n");
            bulundu = 1;
        }
    }

    fclose(file);

    if (!bulundu) {
    	printf("\n\t\t\t\t\t\t\t\t\t\t========================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Henüz hiçbir oyun satýn almadýnýz. ||\n");
        printf("\t\t\t\t\t\t\t\t\t\t========================================\n");
    }

    islemTamamlandi();
}


void sil() { system("CLS"); }

void rastgeleCizim() {
    srand(time(NULL));
    int num = rand() % 6 + 1; /* 1 ile 6 arasinda rastgele sayi */
    char filename[30];

    /* Rastgele sayiyi dosya adiyla birlestir */
    sprintf(filename, "data/resimler/%d.txt", num);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\n\t\t\t\t\t\t\t\t\t\t===================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t|| Çizim dosyasý açýlamadý: %s ||\n", filename);
        printf("\t\t\t\t\t\t\t\t\t\t===================================\n");
        return;
    }

    char line[1024]; /* buffer */
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("\t\t\t\t\t\t\t\t\t%s", line); /* okunan sirayi yazdir */
    }
    printf("\n");
    fclose(fp);

    printf("\n\t\t\t\t\t\t\t\t\t\t=================================================");
}

