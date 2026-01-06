#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    char kullanici_adi[40];
    char *gezegenler[] = {"Merkur","Venus","Dunya","Mars","Jupiter","Saturn","Uranus","Neptun"};
    int secim;
    int sure_saniye;
    int yol_metre;
    float yercekimi[] = {3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15};
    float yollar[8];

    printf("Kullanici Adi: ");
    fgets(kullanici_adi, 40, stdin);
    kullanici_adi[strcspn(kullanici_adi, "\n")] = '\0';

    system("cls");
    Secenekleri_Yazdir();

    printf("\nSeciminizi giriniz (1-9): ");
    scanf("%d", &secim);

    switch(secim) {
        case 1:
            printf("Sayin %s Lutfen Sureyi Giriniz : ",kullanici_adi);
            scanf("%d",&sure_saniye);
            SerbestDusme(yercekimi, &sure_saniye, yollar);
            for (int i = 0; i < 8; i++) {
                printf("%s icin dusulen yol: %.2f metre\n", *(gezegenler + i), *(yollar + i)); }
            break;
        case 2:
            printf("Yukari Atis Deneyi secildi.\n");
            break;
        case 3:
            printf("Agirlik Deneyi secildi.\n");
            break;
        case 4:
            printf("Kutlecekimsel Potansiyel Enerji Deneyi secildi.\n");
            break;
        case 5:
            printf("Hidrostatik Basinc Deneyi secildi.\n");
            break;
        case 6:
            printf("Arsimet Kaldirma Kuvveti Deneyi secildi.\n");
            break;
        case 7:
            printf("Basit Sarkac Periyodu Deneyi secildi.\n");
            break;
        case 8:
            printf("Sabit Ip Gerilmesi Deneyi secildi.\n");
            break;
        case 9:
            printf("Asansor Deneyi secildi.\n");
            break;
        default:
            printf("Gecersiz secim! Lutfen 1-9 arasi bir deger giriniz.\n");
    }

    return 0;
}
