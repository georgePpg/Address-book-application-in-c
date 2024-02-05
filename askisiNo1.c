#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 50
struct abEntry
{
    int am;
    char lname[100];
    char fname[100];
    char address[100];
    long int zip;
    char email[100];
};
struct abEntry ab[MAX_ENTRIES];

int getUserCommand();
void sortAb(int abFreeEntry);
int compare(const void *a, const void *b);
int recallFileAb(int abFreeEntry);
int saveFileAb(int abFreeEntry);
int displayAbEntry(int abFreeEntry);
int getAbEntry(int abFreeEntry);
void searchAb();
void editAb();

int main()
{
    int abFreeEntry = 0;
    int i;
    int cmd;
    int am;
                while((cmd=getUserCommand())!=8){
                        switch(cmd){
                                case 1:
                                        abFreeEntry = getAbEntry(abFreeEntry);
                                        break;
                                case 2:
                                        displayAbEntry(abFreeEntry);
                                        break;
                                case 3:
                                        editAb();
                                        break;
                                case 4:
                                        saveFileAb(abFreeEntry);
                                        break;
                                case 5:
                                        recallFileAb(abFreeEntry);
                                        break;
                                case 6:
                                        sortAb(abFreeEntry);
                                        break;
                                case 7:
                                        searchAb();
                                        break;
                        }
                }

return 0;
}

void editAb()
{
    int n, num;
    printf("1. allakse am\n");
    printf("2. allakse epitheto\n");
    printf("3. allakse onoma\n");
    printf("4. allakse address\n");
    printf("5. allakse zip\n");
    printf("6. allakse email\n\n");
    printf("dwse arithmo: 1-6 gia thn epithymhth tropopoihsh:\t");
    scanf("%d", &n);
    switch(n){
        case 1:
                printf("dwse arithmo eggrafhs tou address book pou tha ginei h epithymhth tropopoihsh: \n");
                scanf("%d", &num);
                printf("dwse kainourgio am: \n");
                scanf("%d", &ab[num].am);
                break;
        case 2:       
                printf("dwse arithmo eggrafhs tou address book pou tha ginei h epithymhth tropopoihsh: \n");
                scanf("%d", &num);
                printf("dwse kainourgio epitheto: \n");
                scanf("%s", ab[num].lname);
                break;
        case 3:
                printf("dwse arithmo eggrafhs tou address book pou tha ginei h epithymhth tropopoihsh: \n");
                scanf("%d", &num);
                printf("dwse kainourgio onoma: \n");
                scanf("%s", ab[num].fname);
                break;
        case 4:
                printf("dwse arithmo eggrafhs tou address book pou tha ginei h epithymhth tropopoihsh: \n");
                scanf("%d", &num);
                printf("dwse kainourgio address: \n");
                scanf("%s", ab[num].address);
                break;
        case 5:
                printf("dwse arithmo eggrafhs tou address book pou tha ginei h epithymhth tropopoihsh: \n");
                scanf("%d", &num);
                printf("dwse kainourgio zip: \n");
                scanf("%d", ab[num].zip);
                break;
        case 6:
                printf("dwse arithmo eggrafhs tou address book pou tha ginei h epithymhth tropopoihsh: \n");
                scanf("%d", &num);
                printf("dwse kainourgio email: \n");
                scanf("%s", ab[num].email);
                break;                                                
    }
}

int getAbEntry(int abFreeEntry)
{
    int i;
        printf("\n\ndwse arithmo mhtrwou:\n");
        scanf("%d", &ab[abFreeEntry].am);
        printf("dwse epitheto:\n");
        scanf("%s", ab[abFreeEntry].lname);
        printf("dwse onoma:\n");
        scanf("%s", ab[abFreeEntry].fname);
        printf("dwse dieythynsh\n");
        scanf("%s", ab[abFreeEntry].address);
        printf("dwse zip code:\n");
        scanf("%d", &ab[abFreeEntry].zip);
        printf("dwse email:\n");
        scanf("%s", ab[abFreeEntry].email);     
        abFreeEntry++;
    return abFreeEntry;    
}

int displayAbEntry(int abFreeEntry)
{
    int i;
    for(i=0;i<abFreeEntry + 1;i++)
    {
        printf("No.%d\n", i);
        printf("am: %d\n", ab[i].am);
        printf("last name: %s\n", ab[i].lname);
        printf("first name: %s\n", ab[i].fname);
        printf("address: %s\n", ab[i].address);
        printf("zip: %d\n", ab[i].zip);
        printf("email: %s\n", ab[i].email);
        printf("--------------------------\n\n");
    }
    
}

int saveFileAb(int abFreeEntry)
{
    int i;
    FILE *fp;
    fp=fopen("addressbook.txt", "w");
    if(fp == NULL){
        printf("error\n");
    }
    for(i=0;i<abFreeEntry + 1;i++){
        fprintf(fp, "%d\t am: %d\t lastName: %s\t firstName: %s\t address: %s\t zip: %d\t email: %s\t\n", i, ab[i].am, ab[i].lname, ab[i].fname, ab[i].address, ab[i].zip, ab[i].email);
    }
    fclose(fp);
}

int recallFileAb(int abFreeEntry)
{
    int i;
    FILE *fp;
    fp=fopen("addressbook.txt", "r");
    if(fp == NULL){
        printf("error\n");
    }
    for(i=0;i<50;i++){
        fscanf(fp, "%d%d%s%s%s%d%s", &i, &ab[i].am, ab[i].lname, ab[i].fname, ab[i].address, &ab[i].zip, ab[i].email);
        printf("%d\t am: %d\t lastName: %s\t firstName: %s\t address: %s\t zip: %d\t email: %s\t\n", i, ab[i].am, ab[i].lname, ab[i].fname, ab[i].address, ab[i].zip, ab[i].email);
    }
    fclose(fp);

}

int compare(const void *a, const void *b)
{
    const struct abEntry *aa = (const struct abEntry *)a;
    const struct abEntry *bb = (const struct abEntry *)b;
    return strcmp(aa->lname, bb->lname);
} 

void sortAb(int abFreeEntry)
{
    int n, num, i, numbers;
    qsort(ab, abFreeEntry, sizeof(struct abEntry), compare);
    displayAbEntry(abFreeEntry);
}

void searchAb()
{
    char lname[100];
    printf("dwse epitheto: ");
    scanf("%s", lname);
    struct abEntry key;
    strcpy(key.lname, lname);
    struct abEntry *result = (struct abEntry *) bsearch(&key, ab, MAX_ENTRIES, sizeof(struct abEntry), compare);
    if (result != NULL) {
        printf("vrethhke eisodos me epitheto: %s:\n", lname);
        printf("am: %d\n", result->am);
        printf("first name: %s\n", result->fname);
        printf("address: %s\n", result->address);
        printf("zip: %d\n", result->zip);
        printf("email: %s\n", result->email);
    } else {
        printf("den vrethhke eisodos me epitheto: %s\n", lname);
    }
}


int getUserCommand(){
	int uc;
    printf("1: eisagwgh neas eggrafhs \n");
    printf("2: emfanish eggrafwn \n");
    printf("3: tropopoihsh eggrafhs \n");
    printf("4: apothhkeysh twn eggrafwn se arxeio \n");
    printf("5: anaklhsh eggrafwn apo arxeio\n");
    printf("6: taksinomhsh twn eggrafwn \n");
    printf("7: anazhthsh eggrafhs \n");
    printf("8: Termatismos programmatos \n");
	printf("\n");
	printf("dose epilogh:");
    scanf("%d",&uc);
	printf("\n");
	return uc;
}

