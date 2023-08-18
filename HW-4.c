#include <stdio.h>

#define MAX_ARABALAR 15

typedef struct {
    char marka[20];
    char model[20];
    int yas[100];
    int motor_gucu[20];
    char renk[20];
    float kira_bedeli;
} Araba;

void arabaBilgileriniGir(Araba *araba);
void arabalariDosyayaYaz(Araba arabalar[], int sayi, float maksimumKiraBedeli);

int main() {
    Araba arabalar[MAX_ARABALAR];
    float maksimumKiraBedeli;
    int i, secilenSayi = 0;

    // Araba bilgilerini kullanýcýdan alarak arabalar dizisine kaydet
    for (i = 0; i < MAX_ARABALAR; i++) {
        printf("Araba #%d bilgilerini girin:\n", i + 1);
        arabaBilgileriniGir(&arabalar[i]);
    }

    // Maksimum kira bedelini kullanýcýdan al
    printf("Maksimum kira bedelini girin: ");
    scanf("%f", &maksimumKiraBedeli);

    // Seçilen arabalarý Secilen_Arabalar.txt dosyasýna yaz
    arabalariDosyayaYaz(arabalar, MAX_ARABALAR, maksimumKiraBedeli);

    return 0;
}

void arabaBilgileriniGir(Araba *araba) {
    printf("Marka: ");
    scanf("%s", &(araba->marka));

    printf("Model: ");
    scanf("%s", &(araba->model));

    printf("Yas: ");
    scanf("%d", &(araba->yas));

    printf("Motor Gucu: ");
    scanf("%d", &(araba->motor_gucu));

    printf("Renk: ");
    scanf("%s", araba->renk);

    printf("Gunluk Kira Bedeli: ");
    scanf("%f", &(araba->kira_bedeli));
}

void arabalariDosyayaYaz(Araba arabalar[], int sayi, float maksimumKiraBedeli) {
    FILE *dosya;
    int i;
    int bulunanAraba = 0;

    dosya = fopen("Mevcut_Arabalar.txt", "w");
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }

    for (i = 0; i < sayi; i++) {
        fprintf(dosya, "Marka: %s\n", arabalar[i].marka);
        fprintf(dosya, "Model: %s\n", arabalar[i].model);
        fprintf(dosya, "Yas: %d\n", arabalar[i].yas);
        fprintf(dosya, "Motor Gucu: %d\n", arabalar[i].motor_gucu);
        fprintf(dosya, "Renk: %s\n", arabalar[i].renk);
        fprintf(dosya, "Gunluk Kira Bedeli: %.2f\n\n", arabalar[i].kira_bedeli);

        if (arabalar[i].kira_bedeli <= maksimumKiraBedeli) {
            FILE *secilenDosya = fopen("Secilen_Arabalar.txt", "a");
            if (secilenDosya != NULL) {
                fprintf(secilenDosya, "Marka: %s\n", arabalar[i].marka);
                fprintf(secilenDosya, "Model: %s\n", arabalar[i].model);
                fprintf(secilenDosya, "Yas: %d\n", arabalar[i].yas);
                fprintf(secilenDosya, "Motor Gucu: %d\n", arabalar[i].motor_gucu);
                fprintf(secilenDosya, "Renk: %s\n", arabalar[i].renk);
                fprintf(secilenDosya, "Gunluk Kira Bedeli: %.2f\n\n", arabalar[i].kira_bedeli);
                fclose(secilenDosya);
                bulunanAraba++;
            }
        }
    }

    fclose(dosya);

    if (bulunanAraba == 0) {
        printf("Ýstenilen ozelliklerde araba bulunamamýstýr!\n");
    } else {
        printf("%d adet araba Secilen_Arabalar.txt dosyasina yazildi.\n", bulunanAraba);
    }
}
