#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Secenekleri_Yazdir() {
    printf("1. Serbest Dusme Deneyi\n");
    printf("2. Yukari Atis Deneyi\n");
    printf("3. Agirlik Deneyi\n");
    printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
    printf("5. Hidrostatik Basinc Deneyi\n");
    printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
    printf("7. Basit Sarkac Periyodu Deneyi\n");
    printf("8. Sabit Ip Gerilmesi Deneyi\n");
    printf("9. Asansor Deneyi\n");
}

void SerbestDusme(float *yercekimi, int *sure, float *sonuclar) {
    *sure = (*sure < 0) ? -*sure : *sure;

    for (int i = 0; i < 8; i++) {
        *(sonuclar + i) = 0.5f * (*(yercekimi + i)) * (*sure) * (*sure);
    }
}

void YukariAtis(float *yercekimi, float *hiz, float *sonuclar) {
    *hiz = (*hiz < 0) ? -*hiz : *hiz;

    for (int i = 0; i < 8; i++) {
        *(sonuclar + i) = ((*hiz) * (*hiz)) / (2 * (*(yercekimi + i)));
    }
}

void AgirlikDeneyi(float *yercekimi, float *kutle, float *sonuclar) {
    *kutle = (*kutle < 0) ? -*kutle : *kutle;

    for (int i = 0; i < 8; i++) {
        *(sonuclar + i) = (*kutle) * (*(yercekimi + i));
    }
}

void PotansiyelEnerji(float *yercekimi, float *kutle, float *yukseklik, float *sonuclar) {
    *kutle = (*kutle < 0) ? -*kutle : *kutle;
    *yukseklik = (*yukseklik < 0) ? -*yukseklik : *yukseklik;

    for (int i = 0; i < 8; i++) {
        *(sonuclar + i) = (*kutle) * (*(yercekimi + i)) * (*yukseklik);
    }
}

void HidrostatikBasinc(float *yercekimi, float *rho, float *derinlik, float *sonuclar) {
    *rho = (*rho < 0) ? -*rho : *rho;
    *derinlik = (*derinlik < 0) ? -*derinlik : *derinlik;

    for (int i = 0; i < 8; i++) {
        *(sonuclar + i) = (*rho) * (*(yercekimi + i)) * (*derinlik);
    }
}

void ArsimetKuvveti(float *yercekimi, float *rho, float *hacim, float *sonuclar) {
    *rho = (*rho < 0) ? -*rho : *rho;
    *hacim = (*hacim < 0) ? -*hacim : *hacim;

    for (int i = 0; i < 8; i++) {
        *(sonuclar + i) = (*rho) * (*(yercekimi + i)) * (*hacim);
    }
}

void BasitSarkac(float *yercekimi, float *uzunluk, float *sonuclar) {
    *uzunluk = (*uzunluk < 0) ? -*uzunluk : *uzunluk;

    for (int i = 0; i < 8; i++) {
        *(sonuclar + i) = 2 * M_PI * sqrt((*uzunluk) / (*(yercekimi + i)));
    }
}

void IpGerilmesi(float *yercekimi, float *kutle, float *sonuclar) {
    *kutle = (*kutle < 0) ? -*kutle : *kutle;

    for (int i = 0; i < 8; i++) {
        *(sonuclar + i) = (*kutle) * (*(yercekimi + i));
    }
}

void AsansorDeneyi(float *yercekimi, float *kutle, float *ivme, float *sonuclar) {
    *kutle = (*kutle < 0) ? -*kutle : *kutle;

    for (int i = 0; i < 8; i++) {
        float etkili_g = (*ivme >= 0)? (*(yercekimi + i) + (*ivme)): (*(yercekimi + i) - (-(*ivme)));
        *(sonuclar + i) = (*kutle) * etkili_g;
    }
}

int main() {
    char kullanici_adi[40];
    char *gezegenler[] = {"Merkur","Venus","Dunya","Mars","Jupiter","Saturn","Uranus","Neptun"};
    int secim;
    int sure_saniye;
    float ivme, uzunluk, hacim, rho, derinlik, kutle, yukseklik, firlatis_metre;
    float yercekimi[] = {3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15};
    float yollar[8];

    printf("Kullanici Adi: ");
    fgets(kullanici_adi, 40, stdin);
    kullanici_adi[strcspn(kullanici_adi, "\n")] = '\0';

    printf("\n--------------------------------------\n");

    while(1) {
        Secenekleri_Yazdir();
        printf("\nSeciminizi giriniz (1-9, Cikis icin -1): ");
        scanf("%d", &secim);
        if (secim == -1) {
            printf("Program sonlandiriliyor...\n");
            break;
        }

            switch(secim) {
            case 1:
                printf("Sayin %s Lutfen Sureyi Giriniz : ",kullanici_adi);
                scanf("%d",&sure_saniye);

                SerbestDusme(yercekimi, &sure_saniye, yollar);

                for (int i = 0; i < 8; i++) {
                    printf("%s icin dusulen yol: %.2f metre\n", *(gezegenler + i), *(yollar + i));
                }
                break;
            case 2:
                printf("Sayin %s Lutfen Cismi Kac m/s de Firlattiginizi Giriniz : ", kullanici_adi);
                scanf("%f", &firlatis_metre);

                YukariAtis(yercekimi, &firlatis_metre, yollar);

                for (int i = 0; i < 8; i++) {
                    printf("%s icin cikabilecegi max yukseklik: %.2f metre\n", *(gezegenler + i), *(yollar + i));
                }
                break;
            case 3:
                printf("Sayin %s Lutfen Cismin Kutlesini (kg) Giriniz : ", kullanici_adi);
                scanf("%f", &kutle);

                AgirlikDeneyi(yercekimi, &kutle, yollar);

                for (int i = 0; i < 8; i++) {
                    printf("%s icin cismin agirligi: %.2f Newton\n",*(gezegenler + i),*(yollar + i));
                }
                break;
            case 4:
                printf("Sayin %s Lutfen Cismin Kutlesini (kg) Giriniz : ", kullanici_adi);
                scanf("%f", &kutle);

                printf("Sayin %s Lutfen Yuksekligi (m) Giriniz : ", kullanici_adi);
                scanf("%f", &yukseklik);

                PotansiyelEnerji(yercekimi, &kutle, &yukseklik, yollar);

                for (int i = 0; i < 8; i++) {
                    printf("%s icin kutlecekimsel potansiyel enerji: %.2f Joule\n",*(gezegenler + i),*(yollar + i));
                }
                break;

            case 5:
                printf("Sayin %s Lutfen Sivi Yogunlugunu (kg/m^3) Giriniz : ", kullanici_adi);
                scanf("%f", &rho);

                printf("Sayin %s Lutfen Derinligi (m) Giriniz : ", kullanici_adi);
                scanf("%f", &derinlik);

                HidrostatikBasinc(yercekimi, &rho, &derinlik, yollar);

                for (int i = 0; i < 8; i++) {
                    printf("%s icin hidrostatik basinc: %.2f Pascal\n",*(gezegenler + i),*(yollar + i));
                }
                break;
            case 6:
                printf("Sayin %s Lutfen Sivi Yogunlugunu (kg/m^3) Giriniz : ", kullanici_adi);
                scanf("%f", &rho);

                printf("Sayin %s Lutfen Cismin Batan Hacmini (m^3) Giriniz : ", kullanici_adi);
                scanf("%f", &hacim);

                ArsimetKuvveti(yercekimi, &rho, &hacim, yollar);

                for (int i = 0; i < 8; i++) {
                    printf("%s icin arsimet kaldirma kuvveti: %.2f Newton\n",*(gezegenler + i),*(yollar + i));
                }
                break;
            case 7:
                printf("Sayin %s Lutfen Sarkac Uzunlugunu (m) Giriniz : ", kullanici_adi);
                scanf("%f", &uzunluk);

                BasitSarkac(yercekimi, &uzunluk, yollar);

                for (int i = 0; i < 8; i++) {
                    printf("%s icin sarkac periyodu: %.2f saniye\n",*(gezegenler + i),*(yollar + i));
                }
                break;
            case 8:
                printf("Sayin %s Lutfen Cismin Kutlesini (kg) Giriniz : ", kullanici_adi);
                scanf("%f", &kutle);

                IpGerilmesi(yercekimi, &kutle, yollar);

                for (int i = 0; i < 8; i++) {
                    printf("%s icin ipin gerilme kuvveti: %.2f Newton\n",*(gezegenler + i),*(yollar + i));
                }
                break;
            case 9:
                printf("Sayin %s Lutfen Cismin Kutlesini (kg) Giriniz : ", kullanici_adi);
                scanf("%f", &kutle);

                printf("Sayin %s Lutfen Asansor Ivmesini (m/s^2) Giriniz (Yukari +, Asagi -): ", kullanici_adi);
                scanf("%f", &ivme);

                AsansorDeneyi(yercekimi, &kutle, &ivme, yollar);

                for (int i = 0; i < 8; i++) {
                    printf("%s icin hissedilen agirlik: %.2f Newton\n",*(gezegenler + i),*(yollar + i));
                }
                break;
            default:
                printf("Gecersiz secim! Lutfen 1-9 arasi bir deger giriniz.\n");
        }
        printf("\n--------------------------------------\n");
    }
    return 0;
}
