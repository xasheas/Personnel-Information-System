
/*            Ders : Algoritma ve Programlama 2
             Proje : Personel bilgi sistemi
       Dersi veren : DOC. DR. AYSEGUL ALAYBEYOGLU           */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

FILE *dosya;
void kayitekle();
void personellistele();
void kaydiduzenle();
void tckimliknoilekayitbul();
void isimilekayitbul();
void kayitsil();

struct eleman{
char isim[30];
char tckimlikno[15];
char telefon[15];
char eposta[30];
char adres[50];
}personel;

int main()
{   setlocale(LC_ALL,"Turkish");
    char secim;
    printf("\n-_-_-_-_* PERSONEL BILGI SISTEMI *_-_-_-_-");
    do{
    printf("\n\n -ISLEMLER-\n");
    printf(" 1.Kayit ekle \n 2.Personel Listele \n 3.Kaydi Duzenle \n 4.TC Kimlik No ile Kayit Bul \n 5.Isim ile Kayit bul \n 6.Kayit sil \n 0.Cikis\n --> ");
    secim=getche();
    switch(secim){
  case '0': exit(0);
  case '1': kayitekle();  break;
  case '2': personellistele();  break;
  case '3': kaydiduzenle();   break;
  case '4': tckimliknoilekayitbul();   break;
  case '5': isimilekayitbul();   break;
  case '6': kayitsil();   break;
   default: system("cls"); printf("\n!!! gecersiz islem !!!\a"); break;  }
    }while(secim != '0');
  return 0;
}

void kayitekle(){
 dosya=fopen("personel.txt","a");
 system("cls");
 printf("\npersonelin:\n");
 printf("Adini giriniz:\n");
 fflush(stdin);     gets(personel.isim);
 fwrite(&personel.isim, sizeof(char),30,dosya);
 printf("TC. kimlik numarasini giriniz:\n");
 fflush(stdin);     gets(personel.tckimlikno);
 fwrite(&personel.tckimlikno, sizeof(char),15,dosya);
 printf("Telefon numarasini giriniz:\n");
 fflush(stdin);     gets(personel.telefon);
 fwrite(&personel.telefon, sizeof(char),15,dosya);
 printf("E-posta adresini giriniz:\n");
 fflush(stdin);     gets(personel.eposta);
 fwrite(&personel.eposta, sizeof(char),30,dosya);
 printf("Adresini giriniz:\n");
 fflush(stdin);     gets(personel.adres);
 fwrite(&personel.adres, sizeof(char),50,dosya);
 fclose(dosya);
 char secim;
 printf("Tekrar kayit eklemek icin E, cikmak icin H tusuna basiniz\n");
 kytcikis:
 secim=getche();
 switch(secim){
 case 'e':
 case 'E': kayitekle();
 case 'h':
 case 'H': break;
 default: printf("Tanimlanmayan deger girdiniz, isleminizi tekrarlayin\n\a"); goto kytcikis;  }
}

void personellistele(){
 struct eleman listele;
 dosya=fopen("personel.txt","r");
 system("cls");
 fseek(dosya,0,SEEK_SET);
 int i=1;
 do{
 fread(&listele,sizeof(char),140,dosya);
 if(feof(dosya)!=0) break;
printf("\n\n%d.personelin \nadi: ",i);
  printf("%s",listele.isim);
printf("\nTC.numarasi: ");
  printf("%s",listele.tckimlikno);
printf("\nTel.numarasi: ");
   printf("%s",listele.telefon);
printf("\nE-posta adresi: ");
  printf("%s",listele.eposta);
printf("\nAdresi: ");
   printf("%s",listele.adres);
  i++;
 }while(0==0);
 fclose(dosya);
}

void kaydiduzenle(){
   struct eleman duzenle[20];
   dosya=fopen("personel.txt","r");
   char a[30];
   system("cls");
   printf("\nKaydi duzenlenecek kisinin adini giriniz;\n --> ");
   fflush(stdin);
   gets(a);
   int b=0,i,x=21,z;
   while(!feof(dosya)){
    fread(&duzenle[b],sizeof(char),140,dosya);
    b++; }
    for(i=0; i<(b-1); i++){
        if(strcmp(a,duzenle[i].isim)==0){ x=i;} }
        if(x==21){ printf("aradiginiz kisi bulunamadi\a");
        goto cikis;
        }
        printf("Listede bastan %d. personel\n",x+1);
        printf("kaydi duzenlenecek kisinin bilgileri;  *(yanlarina güncel bilgilerini giriniz)*\n");
        printf("Adi: %s --> ",duzenle[x].isim);
        fflush(stdin);   gets(duzenle[x].isim);
        printf("TC. kimlik no: %s --> ",duzenle[x].tckimlikno);
        fflush(stdin);   gets(duzenle[x].tckimlikno);
        printf("Tel no: %s --> ",duzenle[x].telefon);
        fflush(stdin);   gets(duzenle[x].telefon);
        printf("E-posta: %s --> ",duzenle[x].eposta);
        fflush(stdin);   gets(duzenle[x].eposta);
        printf("Adres: %s --> ",duzenle[x].adres);
        fflush(stdin);   gets(duzenle[x].adres);
    fclose(dosya);
    dosya=fopen("personel.txt","w");
    fseek(dosya,0,SEEK_SET);
    for(z=0; z<(b-1); z++){
        fwrite(&duzenle[z],sizeof(char),140,dosya);  }
    cikis:
fclose(dosya);
}

void tckimliknoilekayitbul(){
    system("cls");
    dosya=fopen("personel.txt","r");
    struct eleman bul[20];
    char a[15];
    printf("\nkaydini bulmak istediginiz personelin TC. kimlik numarasini giriniz;\n --> ");
    fflush(stdin);      gets(a);
   int b=0,i,x=21;
   while(!feof(dosya)){
    fread(&bul[b],sizeof(char),140,dosya);
    b++;
   }
   for(i=0; i<(b-1); i++){
    if(strcmp(a,bul[i].tckimlikno)==0){
        x=i;   }
   }
   if(x==21){printf("aradiginiz kisi bulunamadi\a");
   goto cikis;}
    fseek(dosya,(x*140)*sizeof(char),SEEK_SET);
    struct eleman goruntule;
    fread(&goruntule,sizeof(char),140,dosya);
  printf("adi: ");
  printf("%s",goruntule.isim);
printf("\nTC.numarasi: ");
  printf("%s",goruntule.tckimlikno);
printf("\nTel.numarasi: ");
   printf("%s",goruntule.telefon);
printf("\nE-posta adresi: ");
  printf("%s",goruntule.eposta);
printf("\nAdresi: ");
   printf("%s",goruntule.adres);
   cikis:
   fclose(dosya);
}

void isimilekayitbul(){
    system("cls");
    dosya=fopen("personel.txt","r");
    struct eleman bul2[20];
    char a[30];
    printf("\nkaydini bulmak istediginiz personelin adini giriniz;\n --> ");
    fflush(stdin);      gets(a);
   int b=0,i,x=21;
   while(!feof(dosya)){
    fread(&bul2[b],sizeof(char),140,dosya);
    b++;
   }
   for(i=0; i<(b-1); i++){
    if(strcmp(a,bul2[i].isim)==0){
        x=i;   }
   }
   if(x==21) { printf("aradiginiz kisi bulunamadi\a");
   goto cikis;
   }
    fseek(dosya,(x*140)*sizeof(char),SEEK_SET);
    struct eleman goruntule2;
    fread(&goruntule2,sizeof(char),140,dosya);

   printf("adi: ");
  printf("%s",goruntule2.isim);
printf("\nTC.numarasi: ");
  printf("%s",goruntule2.tckimlikno);
printf("\nTel.numarasi: ");
   printf("%s",goruntule2.telefon);
printf("\nE-posta adresi: ");
  printf("%s",goruntule2.eposta);
printf("\nAdresi: ");
   printf("%s",goruntule2.adres);
   cikis:
   fclose(dosya);
}

void kayitsil(){
    system("cls");
    dosya=fopen("personel.txt","r");
    struct eleman sil[20];
    char a[15];
    printf("\nkaydini silmek istediginiz personelin TC. kimlik numarasini giriniz;\n --> ");
    fflush(stdin);      gets(a);
   int b=0,i,x=21,z;
   while(!feof(dosya)){
    fread(&sil[b],sizeof(char),140,dosya);
    b++;
   }
   for(i=0; i<(b-1); i++){
    if(strcmp(a,sil[i].tckimlikno)==0){
        x=i;   }  }
        if(x==21){ printf("aradiginiz kisi bulunamadi\a");
        goto cikis;
        }
    fclose(dosya);
    struct eleman sil2[20];
    printf("listede bastan %d.eleman.\n",x+1);
    for(i=0; i<(x); i++){
        memcpy(sil2[i].isim,sil[i].isim,sizeof(sil[i].isim));
        memcpy(sil2[i].tckimlikno,sil[i].tckimlikno,sizeof(sil[i].tckimlikno));
        memcpy(sil2[i].telefon,sil[i].telefon,sizeof(sil[i].telefon));
        memcpy(sil2[i].eposta,sil[i].eposta,sizeof(sil[i].eposta));
        memcpy(sil2[i].adres,sil[i].adres,sizeof(sil[i].adres));
        }
    for(i=(x+1); i<=(b-1); i++){
        memcpy(sil2[i-1].isim,sil[i].isim,sizeof(sil[i].isim));
        memcpy(sil2[i-1].tckimlikno,sil[i].tckimlikno,sizeof(sil[i].tckimlikno));
        memcpy(sil2[i-1].telefon,sil[i].telefon,sizeof(sil[i].telefon));
        memcpy(sil2[i-1].eposta,sil[i].eposta,sizeof(sil[i].eposta));
        memcpy(sil2[i-1].adres,sil[i].adres,sizeof(sil[i].adres));
        }
    dosya=fopen("personel.txt","w");
    fseek(dosya,0,SEEK_SET);
    for(z=0; z<(b-2); z++){
        fwrite(&sil2[z],sizeof(char),140,dosya);
    }
    printf("personel basarili bir sekilde silindi");
   cikis:
   fclose(dosya);
}
