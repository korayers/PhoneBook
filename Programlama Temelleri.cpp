#include <stdio.h>
#include <string.h>

// bu kýsým "struct" yapýsý olan "dict" adlý bir veri türü tanýmlar, bu veri türü name, num, mail gibi bilgileri içeren bir kiþi defteri öðesini simgeler
struct dict {
    char name[50];
    char num[11];
    char mail[35];
} sp[25];//struct yapýsý "sp" adlý 25 elemanlýk bir dizi ile birleþtirilir, sp[25] ifadesi 25 kiþinin bilgisinin tutulmasýný saðlar

int h, i = 1; // int tipinde h adýnda bir deðiþken tanýmlanýr , i=1 ifadesi i adýndaki tam sayý deðiþkenini 1 ile baþlatýr 

int main() {
    printf("------------------------Welcome to Phone Book------------------------\n");

    int c, addcon, a = 1; // 3 tane int türünde deðiþken tanýmlar, c: gecici kullanýlacak sayýsal deðer, addcon: kaç kiþinin eklenmek istediðini belirten sayýsal deðer, 
    int choice, v, pos;// 3 adet int daha tanýmlanýr, choice: kullancýcýnýn menüde seçtiði seçeneði saklamak için kullanýlýr, v: kiþi eklerken kullanýlacak geçici deðer, pos: arama yaparken kullanýlacak kiþinin pozisyonunu belirten sayýsal deðer 
    char b[50]; // bu dizi 50 karakterlik bir bellek olduðunu ifade eder, metin verilerini depolar

    strcpy(sp[1].name, "Koray");//sp dizisinin birinci elemanýný name alanýna kopyalar 
    strcpy(sp[1].num, "05399115270");// ayný elemanýn num alanýna kopyalar 
    strcpy(sp[1].mail, "koray@gmail.com");// mail alanýna kopyalar
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

    while (a == 1) {// sonsuz bir döngü baþlatýr, bu döngü kullanýcýnýn programý devam ettirmek isteyip istemediðini sormak için kullanýlýr eðer 'a'=1 ise döngü devam eder 
        printf("1--->DISPLAY CONTACTS\n2--->DELETING CONTACTS\n3--->ADDING CONTACTS\n4--->FINDING CONTACTS"); // çeþitli seçenekleri içeren bir menü gösterilir 
        printf("\nENTER YOUR CHOICE:");// ve kullanýcýdan bir seçim yapmasý seçim yapmasý istenir

        scanf("%d", &choice); //seçim alýnýr

        for (int j = 0; j < 140; j++) {
            printf("_");// ekraný çizip daha düzenli bir görünüm ortaya çýkarýr
        }

        if (choice <= 4) {//kullanýcýnýn girdiði seçime göre seçime göre bir kontrol yapýlýr, eðer seçim 4 e kadar bir sayý ise ilgili durum iþlenir aksi takdirde geçerli olmayan bir seçim olduðu yazýlýr
            switch (choice) {//seçime göre farklý durum iþlenir
                case 1:// kiþileri görüntüleme durumu
                    printf("\nREG NO\tNAME\t\tNUMBER\t\t\tEMAYL\n");//ekrana baþlýk yazdýrýr, her bir kiþinin bilgilerinin sýrasýný ve hangi sütunun hangi bilgiyi temsil ettiðini belirtir 
                    for (int n = 1; n < i; n++) {//bu döngü kiþilerin bilgilerini içeren diziyi (sp) tarar, i deðiþkeni toplam kiþi sayýsýný temsil eder 
                        printf("%3d%15s%20s%25s\n", n, sp[n].name, sp[n].num, sp[n].mail); //her bir kiþinin bilgilerini biçimlendirerek ekrana yazar(örn:%3d ifadesi birinci sütundaki (reg no) sayýyý üç karakter geniþliðinde yazdýrmasýný saðlar)
                    }
                    printf("\n");//yeni satýr karakterini erkana yazdýrýr, ekrandaki mevcut satýrýn sona erdiðini ve bir sonraki çýktýnýn yeni bir satýrdan baþlayacaðýný belirtir
                    for (int j = 0; j < 80; j++) {//bir döngü oluþturur ve 80 kere tekrarlanýr(çizgi çekmek için)
                        printf("_");
                    }
                    break;//case bloðunun sonunu belirtir

                case 2://kiþi silme durumu
                    printf("\nENTER THE REG NO OF CONTACT TO REMOVE");//kullanýcýya silmek istediði kiþinin 'reg no' deðerini girmesi bir mesaj gösterilir 
                    scanf("%d", &h);// bu deðer kullanýcýdan alýnýr ve h deðiþkenine atanýr(daha sonra girilen deðer kullanýlarak ilgili kiþi rehberden silenecektir)

                    if (h >= i) {// eðer kullanýcý tarafýndan girilen h deðeri mevcut kiþi sayýsýndan daha büyük veya eþitse bu durumda geçerli bir reg no deðeri olmadýðýný belirtmek için ekrana "INVALID REG NO" yazdýrýlýr
                        printf("INVALID REG NO");
                    } else {
                        for (c = h; c <= i; c++) {//h deðerinden baþlayarak mevcut kiþi sayýsýna (i) kadar arttýrarak döndürür, silinecek kiþinin konumundan baþlayarak bir bir kaydýrarak bir önceki kiþinin üzerine yazarak silme iþlemini gerçekleþtirir, iþlem 	sonucunda "i" deðiþkeni bir azaltýlarak kiþi sasyýsý güncellenir
                            strcpy(sp[c].name, sp[c + 1].name);
                            strcpy(sp[c].num, sp[c + 1].num);
                            strcpy(sp[c].mail, sp[c + 1].mail);
                        }
                        i--;// kiþi sayýsýný 1 azaltýr

                        for (int n = 1; n < i; n++) {//kiþi listesini ekrana yazdýrmak için bir döngü baþlatýlýyor 
                            printf("\n%d\t%s\t\t%s\t\t%s", n, sp[n].name, sp[n].num, sp[n].mail);// \n yeni bir satýra geçmek için, %d tamsayý deðeri(RegNo deðeri olan n yi yazdýrýr,\t bir sonraki sütuna geçer,%s karakter dizisi yazdýrýr (name,num,mail deðerlerini yazdýrýr))
                        }
                    }
                    printf("\n");
                    for (int j = 0; j < 80; j++) {
                        printf("_");
                    }
                    break;//case 2 bloðunu sona erdirir

                case 3:
                    printf("\nADDING CONTACT");//kiþi ekleme durumu
                    printf("\nENTER THE NO OF PERSONS TO BE ADDED:");
                    scanf("%d", &addcon);//kullanýcýnýn bir deðer girmesini ve  bu deðeri 'addcon' deðiþkenine atamasýný saðlar 

                    for (v = i; v < i + addcon; ++v) {//v'yi 1 deðeriyle baþlatýr, döngü v deðeri i+addcon deðerinden küçük olduðu sürece çalýþýr, döngü her çalýþtýðýnda v deðerini 1 arttýrýr
                        printf("\n enter name:");//adýný gir
                        scanf("%s", sp[v].name);//girdiði adý sp dizisinin v indeksine sahip öðesinin name deðiþkenine kaydeder %s format belirteci bir dize almak için kullanýlýr ayný iþlem num ve mail için de tekrarlanýr
                        printf("\n enter number:");
                        scanf("%s", sp[v].num);
                        printf("\n enter mail:");
                        scanf("%s", sp[v].mail);
                    }

                    printf("\n");
                    for (int j = 0; j < 140; j++) {
                        printf("_");
                    }
                    i = v;//i deðiþkeninin deðerini v deðiþkeninin deðeri ile eþitlemektedir, i deðiþkeninin deðerini v deðiþkeninin deðeri ile eþitlemektedir (bu sayede programýn devamýnda yeni eklenen kiþilere eriþebiliriz)

                    printf("\nAFTER CHANGING\n");//þekilnde baþlýk yazdýrýr
                    printf("REG NO\tNAME\t\tNUMBER\t\t\tEMAIL");//bu baþlýklarla tablo baþlatýlýyor 

                    for (int n = 1; n < i; n++) {//kaydedilmiþ kiþi bilgileri sýrayla ekrana yazdýrýlýr 
                        printf("\n%d\t%s\t\t%s\t\t%s", n, sp[n].name, sp[n].num, sp[n].mail);//her bir kiþinin bilisini ekrana yazdýrýr
                    }
                    printf("\n");// alt satýra geçer
                    for (int j = 0; j < 140; j++) {
                        printf("_");
                    }
                    break;

                case 4:
                    printf("\nENTER THE REG NO OF THE PERSON:");//kayýt numarasý girmeniz istenir, daha sonra bu numaraya karþýlýk gelen bilgileri ekrana yazdýrýr
                    scanf("%d", &pos);//kullanýcýdan tam sayý alýr ve bu deðeri pos deðiþkenine atar  

                    if (pos >= i) {//kulllanýcýn girdiði reg no deðerinin geçerli bir aralýkta olup olmadýðýný kontrol eder,eðer pos (girilen kayýt numarasý ) mevcut kiþi sayýsýndan (i) büyük veya eþitse bu durum geçerli deðildir yazdýrýlýr 
                    
                        printf("INVALID REG NO:");
                    } else {//kullanýcýnýn girdiði deðer geçerliyse ilgili kiþinin bilgilerinin yazdýrýr 
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
        } else {//geçersiz bir seçenek (1 ve 4 arasý bir sayý girmemiþse) girilmemesi durumunda geçersiz seçenek yazdýrýr 
            printf("\nINVALID CHOICE");
        }

        printf("\nPRESS 1 TO CONTINUE 0 TO EXIT");//devam edit etmeyeceði sorulur kullanýcý 1 seçerse program tekrar döngüye girer ve iþlemleri devam ettirir eðer 0 seçilirse program sona erer ve çalýþmayý durdurur
        scanf("%d", &a);//scanf fonksiyonu kullanýcýnýn giriþini alýr ve bu deðeri a deðiþkenine atar 
    }

    return 0;//programýn baþarýyla tamamlandýðýný gösterir
} 
