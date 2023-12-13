#include <stdio.h>
#include <string.h>

// bu k�s�m "struct" yap�s� olan "dict" adl� bir veri t�r� tan�mlar, bu veri t�r� name, num, mail gibi bilgileri i�eren bir ki�i defteri ��esini simgeler
struct dict {
    char name[50];
    char num[11];
    char mail[35];
} sp[25];//struct yap�s� "sp" adl� 25 elemanl�k bir dizi ile birle�tirilir, sp[25] ifadesi 25 ki�inin bilgisinin tutulmas�n� sa�lar

int h, i = 1; // int tipinde h ad�nda bir de�i�ken tan�mlan�r , i=1 ifadesi i ad�ndaki tam say� de�i�kenini 1 ile ba�lat�r 

int main() {
    printf("------------------------Welcome to Phone Book------------------------\n");

    int c, addcon, a = 1; // 3 tane int t�r�nde de�i�ken tan�mlar, c: gecici kullan�lacak say�sal de�er, addcon: ka� ki�inin eklenmek istedi�ini belirten say�sal de�er, 
    int choice, v, pos;// 3 adet int daha tan�mlan�r, choice: kullanc�c�n�n men�de se�ti�i se�ene�i saklamak i�in kullan�l�r, v: ki�i eklerken kullan�lacak ge�ici de�er, pos: arama yaparken kullan�lacak ki�inin pozisyonunu belirten say�sal de�er 
    char b[50]; // bu dizi 50 karakterlik bir bellek oldu�unu ifade eder, metin verilerini depolar

    strcpy(sp[1].name, "Koray");//sp dizisinin birinci eleman�n� name alan�na kopyalar 
    strcpy(sp[1].num, "05399115270");// ayn� eleman�n num alan�na kopyalar 
    strcpy(sp[1].mail, "koray@gmail.com");// mail alan�na kopyalar
    i++;//sonraki elemana atar
    strcpy(sp[2].name, "Ahmet");
    strcpy(sp[2].num, "05399115271");
    strcpy(sp[2].mail, "ahmet@gmail.com");
    i++;
    strcpy(sp[3].name, "Mehmet");
    strcpy(sp[3].num, "05399115272");
    strcpy(sp[3].mail, "mehmet@gmail.com");
    i++;
    strcpy(sp[4].name, "Enes");
    strcpy(sp[4].num, "05399115273");
    strcpy(sp[4].mail, "enes@gmail.com");
    i++;
    strcpy(sp[5].name, "Bartu");
    strcpy(sp[5].num, "05399115274");
    strcpy(sp[5].mail, "bartu@gmail.com");
    i++;

    while (a == 1) {// sonsuz bir d�ng� ba�lat�r, bu d�ng� kullan�c�n�n program� devam ettirmek isteyip istemedi�ini sormak i�in kullan�l�r e�er 'a'=1 ise d�ng� devam eder 
        printf("1--->DISPLAY CONTACTS\n2--->DELETING CONTACTS\n3--->ADDING CONTACTS\n4--->FINDING CONTACTS"); // �e�itli se�enekleri i�eren bir men� g�sterilir 
        printf("\nENTER YOUR CHOICE:");// ve kullan�c�dan bir se�im yapmas� se�im yapmas� istenir

        scanf("%d", &choice); //se�im al�n�r

        for (int j = 0; j < 140; j++) {
            printf("_");// ekran� �izip daha d�zenli bir g�r�n�m ortaya ��kar�r
        }

        if (choice <= 4) {//kullan�c�n�n girdi�i se�ime g�re se�ime g�re bir kontrol yap�l�r, e�er se�im 4 e kadar bir say� ise ilgili durum i�lenir aksi takdirde ge�erli olmayan bir se�im oldu�u yaz�l�r
            switch (choice) {//se�ime g�re farkl� durum i�lenir
                case 1:// ki�ileri g�r�nt�leme durumu
                    printf("\nREG NO\tNAME\t\tNUMBER\t\t\tEMAYL\n");//ekrana ba�l�k yazd�r�r, her bir ki�inin bilgilerinin s�ras�n� ve hangi s�tunun hangi bilgiyi temsil etti�ini belirtir 
                    for (int n = 1; n < i; n++) {//bu d�ng� ki�ilerin bilgilerini i�eren diziyi (sp) tarar, i de�i�keni toplam ki�i say�s�n� temsil eder 
                        printf("%3d%15s%20s%25s\n", n, sp[n].name, sp[n].num, sp[n].mail); //her bir ki�inin bilgilerini bi�imlendirerek ekrana yazar(�rn:%3d ifadesi birinci s�tundaki (reg no) say�y� �� karakter geni�li�inde yazd�rmas�n� sa�lar)
                    }
                    printf("\n");//yeni sat�r karakterini erkana yazd�r�r, ekrandaki mevcut sat�r�n sona erdi�ini ve bir sonraki ��kt�n�n yeni bir sat�rdan ba�layaca��n� belirtir
                    for (int j = 0; j < 80; j++) {//bir d�ng� olu�turur ve 80 kere tekrarlan�r(�izgi �ekmek i�in)
                        printf("_");
                    }
                    break;//case blo�unun sonunu belirtir

                case 2://ki�i silme durumu
                    printf("\nENTER THE REG NO OF CONTACT TO REMOVE");//kullan�c�ya silmek istedi�i ki�inin 'reg no' de�erini girmesi bir mesaj g�sterilir 
                    scanf("%d", &h);// bu de�er kullan�c�dan al�n�r ve h de�i�kenine atan�r(daha sonra girilen de�er kullan�larak ilgili ki�i rehberden silenecektir)

                    if (h >= i) {// e�er kullan�c� taraf�ndan girilen h de�eri mevcut ki�i say�s�ndan daha b�y�k veya e�itse bu durumda ge�erli bir reg no de�eri olmad���n� belirtmek i�in ekrana "INVALID REG NO" yazd�r�l�r
                        printf("INVALID REG NO");
                    } else {
                        for (c = h; c <= i; c++) {//h de�erinden ba�layarak mevcut ki�i say�s�na (i) kadar artt�rarak d�nd�r�r, silinecek ki�inin konumundan ba�layarak bir bir kayd�rarak bir �nceki ki�inin �zerine yazarak silme i�lemini ger�ekle�tirir, i�lem 	sonucunda "i" de�i�keni bir azalt�larak ki�i sasy�s� g�ncellenir
                            strcpy(sp[c].name, sp[c + 1].name);
                            strcpy(sp[c].num, sp[c + 1].num);
                            strcpy(sp[c].mail, sp[c + 1].mail);
                        }
                        i--;// ki�i say�s�n� 1 azalt�r

                        for (int n = 1; n < i; n++) {//ki�i listesini ekrana yazd�rmak i�in bir d�ng� ba�lat�l�yor 
                            printf("\n%d\t%s\t\t%s\t\t%s", n, sp[n].name, sp[n].num, sp[n].mail);// \n yeni bir sat�ra ge�mek i�in, %d tamsay� de�eri(RegNo de�eri olan n yi yazd�r�r,\t bir sonraki s�tuna ge�er,%s karakter dizisi yazd�r�r (name,num,mail de�erlerini yazd�r�r))
                        }
                    }
                    printf("\n");
                    for (int j = 0; j < 80; j++) {
                        printf("_");
                    }
                    break;//case 2 blo�unu sona erdirir

                case 3:
                    printf("\nADDING CONTACT");//ki�i ekleme durumu
                    printf("\nENTER THE NO OF PERSONS TO BE ADDED:");
                    scanf("%d", &addcon);//kullan�c�n�n bir de�er girmesini ve  bu de�eri 'addcon' de�i�kenine atamas�n� sa�lar 

                    for (v = i; v < i + addcon; ++v) {//v'yi 1 de�eriyle ba�lat�r, d�ng� v de�eri i+addcon de�erinden k���k oldu�u s�rece �al���r, d�ng� her �al��t���nda v de�erini 1 artt�r�r
                        printf("\n enter name:");//ad�n� gir
                        scanf("%s", sp[v].name);//girdi�i ad� sp dizisinin v indeksine sahip ��esinin name de�i�kenine kaydeder %s format belirteci bir dize almak i�in kullan�l�r ayn� i�lem num ve mail i�in de tekrarlan�r
                        printf("\n enter number:");
                        scanf("%s", sp[v].num);
                        printf("\n enter mail:");
                        scanf("%s", sp[v].mail);
                    }

                    printf("\n");
                    for (int j = 0; j < 140; j++) {
                        printf("_");
                    }
                    i = v;//i de�i�keninin de�erini v de�i�keninin de�eri ile e�itlemektedir, i de�i�keninin de�erini v de�i�keninin de�eri ile e�itlemektedir (bu sayede program�n devam�nda yeni eklenen ki�ilere eri�ebiliriz)

                    printf("\nAFTER CHANGING\n");//�ekilnde ba�l�k yazd�r�r
                    printf("REG NO\tNAME\t\tNUMBER\t\t\tEMAIL");//bu ba�l�klarla tablo ba�lat�l�yor 

                    for (int n = 1; n < i; n++) {//kaydedilmi� ki�i bilgileri s�rayla ekrana yazd�r�l�r 
                        printf("\n%d\t%s\t\t%s\t\t%s", n, sp[n].name, sp[n].num, sp[n].mail);//her bir ki�inin bilisini ekrana yazd�r�r
                    }
                    printf("\n");// alt sat�ra ge�er
                    for (int j = 0; j < 140; j++) {
                        printf("_");
                    }
                    break;

                case 4:
                    printf("\nENTER THE REG NO OF THE PERSON:");//kay�t numaras� girmeniz istenir, daha sonra bu numaraya kar��l�k gelen bilgileri ekrana yazd�r�r
                    scanf("%d", &pos);//kullan�c�dan tam say� al�r ve bu de�eri pos de�i�kenine atar  

                    if (pos >= i) {//kulllan�c�n girdi�i reg no de�erinin ge�erli bir aral�kta olup olmad���n� kontrol eder,e�er pos (girilen kay�t numaras� ) mevcut ki�i say�s�ndan (i) b�y�k veya e�itse bu durum ge�erli de�ildir yazd�r�l�r 
                    
                        printf("INVALID REG NO:");
                    } else {//kullan�c�n�n girdi�i de�er ge�erliyse ilgili ki�inin bilgilerinin yazd�r�r 
                        printf("NAME:%s\n", sp[pos].name);
                        printf("PHONE NUMBER:%s\n", sp[pos].num);
                        printf("MAIL ID:%s\n", sp[pos].mail);
                    }
                    printf("\n");
                    for (int j = 0; j < 140; j++) {
                        printf("_");
                    }
                    break;
            }
        } else {//ge�ersiz bir se�enek (1 ve 4 aras� bir say� girmemi�se) girilmemesi durumunda ge�ersiz se�enek yazd�r�r 
            printf("\nINVALID CHOICE");
        }

        printf("\nPRESS 1 TO CONTINUE 0 TO EXIT");//devam edit etmeyece�i sorulur kullan�c� 1 se�erse program tekrar d�ng�ye girer ve i�lemleri devam ettirir e�er 0 se�ilirse program sona erer ve �al��may� durdurur
        scanf("%d", &a);//scanf fonksiyonu kullan�c�n�n giri�ini al�r ve bu de�eri a de�i�kenine atar 
    }

    return 0;//program�n ba�ar�yla tamamland���n� g�sterir
} 
