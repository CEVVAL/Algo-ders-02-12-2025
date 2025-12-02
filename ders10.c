#include <stdio.h>



char people[10][20] = {
    "Ali",
    "Veli",
    "Ayse",
    "Fatma",
    "Ahmet"
};
char numbers[10][20] = { 
    "1234567890",
    "2345678901",
    "3456789012",
    "4567890123",
    "5678901234"
};
int main(){
    printf("Telefon rehberine hoşgeldiniz!\n-----------------------------------------------------------\n\n");
    while(1){
        printf("Yapmak istediğiniz işlemi giriniz:\n[0]İsim ile ara\n[1]Numara ile ara\n[2]Kişi ekle\n[3]Kişi sil\n[4]Kİşileri Listele\n[5]Çıkış\n");
        int choice;
        scanf("%d",&choice);
        if(choice==0){
            char name[20];
            printf("Aramak istediğiniz ismi giriniz: ");
            scanf("%s",name);
            printf("%s\n",name);
            int found=0;
            for(int i=0;i<10;i++){
                for (int j=0; j<20; j++){
                    printf("%c %c\n",people[i][j],name[j]);
                    if(people[i][j]!=name[j]){
                        break;
                    }
                    if(name[j]=='\0' && people[i][j]=='\0'){
                        printf("Kişi:%s Numara:%s\n\n",people[i],numbers[i]);
                        found=1;
                        break;
                    }
                }
                if(found){
                    break;}
            }
            if(!found){
                printf("Kişi bulunamadı.\n");
            }
        }
        else if(choice==1){
            char number[20];
            printf("Aramak istediğiniz numarayı giriniz: ");
            scanf("%s",number);
            int found=0;
            for(int i=0;i<10;i++){
                for (int j=0; j<20; j++){
                    if(numbers[i][j]!=number[j]){
                        break;
                    }
                    if(number[j]=='\0' && numbers[i][j]=='\0'){
                        printf("Kişi:%s Numara:%s\n\n",people[i],numbers[i]);
                        found=1;
                        break;
                    }
                }
                if(found){
                    break;}
            }
            if(!found){
                printf("Kişi bulunamadı.\n");
            }
        }
        else if(choice==2){
            // Kişi ekleme kodu buraya gelecek
            char newName[20];
            char newNumber[20];
            printf("Eklemek istediğiniz ismi giriniz: ");
            scanf("%s",newName);
            printf("Eklemek istediğiniz numarayı giriniz: ");
            scanf("%s",newNumber);
            // Burada basitlik açısından ilk boş yeri bulup ekleme yapıyoruz
            for(int i=0;i<10;i++){
                if(people[i][0]=='\0'){ // Boş yer kontrolü
                    for(int j=0; j<20; j++){
                        people[i][j] = newName[j];
                        numbers[i][j] = newNumber[j];
                    }
                printf("Kişi eklendi: %s - %s\n",newName,newNumber);
                break;
                }
            }

        }
        else if(choice==3){
            // Kişi silme kodu buraya gelecek
            char delName[20];
            printf("Aramak istediğiniz ismi giriniz: ");
            scanf("%s",delName);
            printf("%s\n",delName);
            int found=0;
            int sıra;
            for(int i=0;i<10;i++){
                for (int j=0; j<20; j++){
                    printf("%c %c\n",people[i][j],delName[j]);
                    if(people[i][j]!=delName[j]){
                        break;
                    }
                    if(delName[j]=='\0' && people[i][j]=='\0'){
                        printf("Silinecek Kişi:%s Numara:%s\n\n",people[i],numbers[i]);
                        found=1;
                        sıra=i;
                        break;
                    }
                }
                if(found){
                for(sıra;sıra<10;sıra++){
                    for(int k=0;k<20;k++){
                        people[sıra][k]=people[sıra+1][k];
                        numbers[sıra][k]=numbers[sıra+1][k];
                    }
                }
                printf("Kişi silindi.\n");
                break;
                }
            }
            if(!found){
                printf("Kişi bulunamadı.\n");
            }

        }

        else if(choice==4){
            printf("Rehberdeki kişiler:\n");
            for(int i=0;i<10;i++){
                if(people[i][0]!='\0'){ // Boş olmayanları listele
                    printf("Kişi:%s Numara:%s\n",people[i],numbers[i]);
                }
            }
        }
        else if(choice==5){
            printf("Çıkış yapılıyor...\n");
            break;
        }
        else{
            printf("Geçersiz seçim, lütfen tekrar deneyin.\n");
        }    
   }
    return 0;
}