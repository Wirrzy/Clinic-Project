#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ll long long
#define ld long double
#define max_limit 256


//Nama : Perwiraputra 
// Nim : 2501962832

//struct data
typedef struct{
    char name[max_limit];
    char bdate[max_limit];
    int age;
    char address[max_limit];
    int stats;
}User1;
typedef struct{
    char tdata[max_limit];
    char clinic;
    char docname[max_limit];
    char diagnosis[max_limit];
    char medikasi[max_limit];
    int harganya;
}User2;
User1 datapat1;
User2 datapat2;

struct node{
    User1 datapat1;
    User2 datapat2;
    node *next;
};
struct que{
    node *front,*rear;
};

//Declare the code
node *newnode(char name[],char bdate[], int age, char address[], int stats, char clinic, char dok[]);
que* createQue();
void entr();
void enque(que* q, char name[], char bdate[], int age, char address[], int stat, char clinic, char docname[]);
void printantri(que* antri);
void dismenu();
void printdoc();
void disque(que* dq, int last);
void datatf(que* src, que* dest, char tanggal[]);
void dispar(que* x);
void buydrug(que* drug);
void payment(que* pay);
void deque(que *dec);
char dokA[2][20] = {"DrBryan","DrValen"};
char dokB[2][20] = {"DrDevi","DrDonny"};
char dokC[2][30] = {"DrWanwan","DrRoxy"};
char dokD[2][20] = {"DrGona","DrVanny"};
char sakitapa[10][20] = {"Flu", "Fever", "Toothache", "Diarrhea", "Sore Throat", "Diabetes", "TBC", "Amoeba", "Indigestion", "Diphtheria"};
char obat[10][max_limit] = {"Paracetamol", "Ibuprofen", "Panadol", "Loperamide", "Degirol", "Metformin", "Isoniazid", "Mebendazole", "Mylanta", "Erythomycin"};
char method[3][30] = {"BPJS","inHealth(asuransi)","Mand"};
int harga[10] = {2400, 4500, 10000, 22000, 14000, 2500, 3800, 8000, 14000, 20000};
int potongan[4] = {1500, 1700, 1300, 1000};
int tax[4] = {0, 1500, 2000, 1000};
int randd();
int rclinic(char x);

//Main function
void entr(){
    printf("Enter To Continue...");
    getchar();
}
node *newnode(char name[],char bdate[], int age, char address[], int stats, char clinic, char dok[]){
    node *new1 = (node*)malloc(sizeof(node));
    strcpy(new1->datapat1.name,name);
    strcpy(new1->datapat1.bdate,bdate);
    new1->datapat1.age = age;
    strcpy(new1->datapat1.address,address);
    new1->datapat1.stats = stats;
    new1->datapat2.clinic = clinic;    
    strcpy(new1->datapat2.docname, dok);;
    new1->next = NULL;
    return new1;
}
que* createQue(){
    que* q = (que*)malloc(sizeof(que));
    q->front = q -> rear = NULL;
    return q;
}
void enque(que* q, char name[], char bdate[], int age, char address[], int stat, char clinic, char docname[]){
    node* temp = newnode(name, bdate, age, address, stat, clinic, docname);
    if(q->rear == NULL){
        q -> front  = q -> rear = temp;
        return;
    }
    q->rear->next=temp;
    q->rear=temp;
}
void printantri(que* antri){
    int antrian = 0;
    node* temp = antri->front;
    while(temp != NULL){
        temp = temp->next;
        antrian++;
    }
    printf("Queue Number : %d\n",antrian);
}
int randd(){
    int x;
    x = rand()%9+0;
    return x;
}
void dismenu(){
    puts(">>> Clinic System <<<");
    puts("1. List of doctors");
    puts("2. Registration");
    puts("3. Current Clinic Queue");
    puts("4. Outpatient");
    puts("5. Pharmacy Queue");
    puts("6. Drug taken");
    puts("7. Payment");
    puts("0. <<Exit>>");
}
void printdoc(){
    system("clear");
    puts("|||||||||||||||||||||||||||||||||||||||||||||||||");
    puts("|\t  Doctors    \t|\t   Doctors    \t|");
    printf("|%-23s|%-23s|\n", dokA[0],dokB[0]);
    printf("|%-23s|%-23s|\n", dokA[1],dokB[1]);
    puts("|||||||||||||||||||||||||||||||||||||||||||||||||");
    puts("|\t  Doctors    \t|\t   Doctors    \t|");
    printf("|%-23s|%-23s|\n", dokC[0],dokD[0]);
    printf("|%-23s|%-23s|\n", dokC[1],dokD[1]);
    puts("|||||||||||||||||||||||||||||||||||||||||||||||||");
    getchar();
    entr();
}
int rclinic(char x){
    if(x == 'A')
        return 0;
    else if(x == 'B')
        return 1;
    else if (x == 'C')
        return 2;
    else if(x == 'D')
        return 3;
    else return -1;
}
void disque(que* dq, int last){
    char dokname[8][max_limit] = {"DrBryan", "DrValen",
        "DrDevi", "DrDonny",
        "DrWanwan", "DrRoxy",
        "DrGona", "DrVanny"};
    printf("Doctor %s:\n", dokname[last]);
    node* temp = dq->front;
    if(temp == NULL){
        printf("No patient in queue!\n");
    }else{
        while(temp != NULL){
            printf("%s - ", temp->datapat1.name);
            temp = temp -> next;
        }
        printf("NULL\n");
    }
    printf("\n");
}
void datatf(que* src, que* dest, char tanggal[]){
    node* temp = src->front;
    char name[max_limit];
    char bdate[max_limit];
    int age;
    char address[max_limit];
    int stats;
    char tdata[max_limit];
    char clinic;
    char docname[max_limit];
    char diagnoses[max_limit];  
    char medication[max_limit];
    int cost;
    strcpy(name,temp->datapat1.name);
    strcpy(bdate,temp->datapat1.bdate);
    age = temp->datapat1.age;
    strcpy(address, temp->datapat1.address);
    stats = temp->datapat1.stats;
    clinic = temp->datapat2.clinic;
    strcpy(docname, temp->datapat2.docname);

    node* new1 = newnode(name, bdate, age, address, stats, clinic, docname);
    strcpy(new1->datapat2.tdata, tanggal);
    int money = randd();
    strcpy(new1->datapat2.diagnosis, sakitapa[money]);
    strcpy(new1->datapat2.medikasi, obat[money]);
    new1->datapat2.harganya = harga[money];
    if(dest->rear == NULL){
        dest->front = dest->rear = new1;
        return;
    }
    dest->rear->next = new1;
    dest->rear = new1;
}
void dispar(que* x){
    node* temp = x->front;
    if(temp == NULL){
        printf("Queue is empty..\n");
    }else{
        puts("Pharmacy Queue");
        puts("===============");
    while(temp != NULL){
        printf("%s - ",temp->datapat1.name);
        temp = temp ->next;
        }
        printf("NULL\n");
    }
    printf("\n");
}
void buydrug(que* drug){
    node* temp = drug->front;
    if(temp == NULL){
        printf("Pharmacy queue is empty..\n");
    }else{
        printf("Medicine Price : %d\n",temp->datapat2.harganya+tax[temp->datapat2.clinic-65]);
    }
}
void payment(que* pay){
    node* temp = pay->front;
    FILE* fp=fopen("Database.txt","a");
    if(temp == NULL){
        printf("No Patient..\n");
    }else{
        temp->datapat2.harganya += potongan[temp->datapat2.clinic-65];
        printf("Patient Receipt\n---------------\n");
        printf("Name: %s\n", temp->datapat1.name);
        printf("DOB: %s\n", temp->datapat1.bdate);
        printf("Age: %d\n", temp->datapat1.age);
        printf("Address: %s\n", temp->datapat1.address);
        printf("Status: %s\n", method[(temp->datapat1.stats)-1]);
        printf("Treatment Date: %s\n", temp->datapat2.tdata);
        printf("Clinic: Clinic %c\n", temp->datapat2.clinic);
        printf("Doctor Name: %s\n", temp->datapat2.docname);
        printf("Diagnoses: %s\n", temp->datapat2.diagnosis);
        printf("Medication: %s\n", temp->datapat2.medikasi);
        if(temp->datapat1.stats == 1 || temp->datapat1.stats == 2){
            printf("\nCost: The cost are covered by BPJS\n");
        }else{
            printf("\nCost: %d\n", temp->datapat2.harganya);
        }
        fprintf(fp, "%s|%s|%d|%s|%d|%s|%c|%s|%s|%s|%d\n", temp->datapat1.name, temp->datapat1.bdate, temp->datapat1.age, temp->datapat1.address, temp->datapat1.stats, temp->datapat2.tdata, temp->datapat2.clinic, temp->datapat2.docname, temp->datapat2.diagnosis, temp->datapat2.medikasi, temp->datapat2.harganya);
        fclose(fp);
    }
}
void deque(que *dec){
    if(dec->front == NULL){
        return;
    }
    node* temp = dec->front;
    dec->front = dec->front->next;
    if(dec->front == NULL){
        dec->rear = NULL;
    }
    free(temp);
}
int main(){
    que* DrBryan = createQue();
    que* DrValen = createQue();
    que* DrDevi = createQue();
    que* DrDonny = createQue();
    que* DrWanwan = createQue();
    que* DrRoxy = createQue();
    que* DrGona = createQue();
    que* DrVanny = createQue();
    que* doqe = createQue();
    que* targetc = createQue();
    time_t t1;
    srand((unsigned) time (&t1));
    int menu = 0;
    while(!menu){
    char name[max_limit];
    char bdate[max_limit];
    int age;
    char address[max_limit];
    int stats;
    char tdata[max_limit];
    char clinic;
    char docname[max_limit];
    char diagnoses[max_limit];  
    char medication[max_limit];
    int cost;
        dismenu();
    int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printdoc();
            break;
            case 2:
                // getchar();
                printf("Enter your name: ");
                scanf(" %[^\n]", name);getchar();
                printf("Enter Date of Birth: ");
                scanf(" %[^\n]", bdate);getchar();
                printf("Enter your Age: ");
                scanf("%d", &age);
                printf("Enter your Address: ");
                scanf(" %[^\n]", address);getchar();
                do{
                printf("1. BPJS\n");
                printf("2. inHealth\n");
                printf("3. Mandiri\n");
                scanf("%d", &stats);
                }while(stats > 3 || stats < 0);
                printf("Enter Clinic Choice A/B/C/D: ");
                scanf(" %c", &clinic);
                switch(rclinic(clinic)){
                    int x;
                    case 0:
                    printf("Available Doctor's in Clinic A\n");
                    printf("1. %s\n", dokA[0]);
                    printf("2. %s\n", dokA[1]);
                    printf("Enter the selected doctor: ");
                    scanf("%d", &x);
                        if(x == 1){
                            enque(DrBryan, name, bdate, age, address, stats, clinic , dokA[0]);
                            printf("Doctor %s\n", dokA[0]);
                            printantri(DrBryan);entr();getchar();             
                        }else if(x == 2){
                            enque(DrValen, name, bdate, age, address, stats, clinic , dokA[0]);
                            printf("Doctor %s\n", dokA[1]);
                            printantri(DrValen);entr();getchar();
                        }
                    break;
                    case 1:
                        printf("Available Doctor's in Clinic B\n");
                        printf("1. %s\n", dokB[0]);
                        printf("2. %s\n", dokB[1]);
                        printf("Enter the selected doctor: ");
                        scanf("%d", &x);
                        if(x == 1){
                            enque(DrDevi, name, bdate, age, address, stats, clinic , dokB[0]);
                            printf("Doctor %s\n", dokB[0]);
                            printantri(DrDevi);entr();getchar();             
                        }else if(x == 2){
                            enque(DrDonny, name, bdate, age, address, stats, clinic , dokB[1]);
                            printf("Doctor %s\n", dokB[1]);
                            printantri(DrDonny);entr();getchar();
                        }
                    break;
                    case 2:
                        printf("Available Doctor's in Clinic C\n");
                        printf("1. %s\n", dokC[0]);
                        printf("2. %s\n", dokC[1]);
                        printf("Enter the selected doctor: ");
                        scanf("%d", &x);
                        if(x == 1){
                            enque(DrWanwan, name, bdate, age, address, stats, clinic , dokC[0]);
                            printf("Doctor %s\n", dokC[0]);
                            printantri(DrWanwan); entr();getchar();            
                        }else if(x == 2){
                            enque(DrRoxy, name, bdate, age, address, stats, clinic , dokC[1]);
                            printf("Doctor %s\n", dokC[1]);
                            printantri(DrRoxy);entr();getchar();
                        }
                    break;
                    case 3:
                        printf("Available Doctor's in Clinic D\n");
                        printf("1. %s\n", dokD[0]);
                        printf("2. %s\n", dokD[1]);
                        printf("Enter the selected doctor: ");
                        scanf("%d", &x);
                        if(x == 1){
                            enque(DrGona, name, bdate, age, address, stats, clinic , dokD[0]);
                            printf("Doctor %s\n", dokD[0]);getchar();
                            printantri(DrGona);    entr();         
                        }else if(x == 2){
                            enque(DrVanny, name, bdate, age, address, stats, clinic , dokD[1]);
                            printf("Doctor %s\n", dokD[1]);getchar();
                            printantri(DrVanny);entr();
                        }
                    break;
                    case -1:
                        printf("Clinic unavailable\n");
                        entr();getchar();
                    break;
                }
            break;
            case 3:
                disque(DrBryan,0);
                disque(DrValen,1);
                disque(DrDevi,2);
                disque(DrDonny,3);
                disque(DrWanwan,4);
                disque(DrRoxy,5);
                disque(DrGona,6);
                disque(DrVanny,7);
                entr();getchar();
            break;
            case 4:
                char clinik,tanggal[50];
                printf("Enter Clinic Choice A/B/C/D: ");
                scanf(" %c", &clinik);
                int e;
                switch(rclinic(clinik)){
                    case 0:
                        printf("Treatment date: ");
                        scanf(" %[^\n]", tanggal);getchar();
                        printf("Available Doctor's in Clinic A\n");
                        printf("1. %s\n", dokA[0]);
                        printf("2. %s\n", dokA[1]);
                        printf("Doctor that treated you: ");
                        scanf("%d", &e);getchar();
                        if(e == 1){
                            datatf(DrBryan, doqe, tanggal);
                            deque(DrBryan);
                        }else if(e==2){
                            datatf(DrValen, doqe, tanggal);
                            deque(DrValen);
                        }
                    break;
                    case 1:
                        printf("Treatment date: ");
                        scanf(" %[^\n]", tanggal);getchar();
                        printf("Available Doctor's in Clinic B\n");
                        printf("1. %s\n", dokB[0]);
                        printf("2. %s\n", dokB[1]);
                        printf("Doctor that treated you: ");
                        scanf("%d", &e);getchar();
                        if(e == 1){
                            datatf(DrDevi, doqe, tanggal);
                            deque(DrDevi);
                        }else if(e==2){
                            datatf(DrDonny, doqe, tanggal);
                            deque(DrDonny);
                        }
                    break;
                    case 2:
                        printf("Treatment data: ");
                        scanf(" %[^\n]", tanggal);getchar();
                        printf("Available Doctor's in Clinic C\n");
                        printf("1. %s\n", dokC[0]);
                        printf("2. %s\n", dokC[1]);
                        printf("Doctor that treated you: ");
                        scanf("%d", &e);getchar();
                        if(e == 1){
                            datatf(DrWanwan, doqe, tanggal);
                            deque(DrWanwan);
                        }else if(e==2){
                            datatf(DrRoxy, doqe, tanggal);
                            deque(DrRoxy);
                        }
                    break;
                    case 3:
                        printf("Treatment date: ");
                        scanf(" %[^\n]", tanggal);getchar();
                        printf("Available Doctor's in Clinic D\n");
                        printf("1. %s\n", dokD[0]);
                        printf("2. %s\n", dokD[1]);
                        printf("Doctor that treated you: ");
                        scanf("%d", &e);getchar();
                        if(e == 1){
                            datatf(DrGona, doqe, tanggal);
                            deque(DrGona);
                        }else if(e==2){
                            datatf(DrVanny, doqe, tanggal);
                            deque(DrVanny);
                        }
                    break;
                    case -1:
                        printf("Clinic unavailable\n");
                        entr();getchar();
                    break;
                    }
                    // struct node* temp = doqe->front;
                    entr();getchar;
                    break;
            case 5:
                dispar(doqe);
                entr();getchar();
            break;
            case 6:
                buydrug(doqe);
                if(doqe -> front != NULL){
                    char tgl[max_limit];
                    strcpy(tgl, doqe->front->datapat2.tdata);
                    //Move to(docQueue, dummy, tgl);
                    struct node* temp = doqe->front; 
                    char name[max_limit];
                    char bdate[max_limit];
                    int age;
                    char address[max_limit];
                    int stat;
                    char tdata[max_limit];
                    char clinic;
                    char docname[max_limit];
                    char diagnoses[max_limit];  
                    char medication[max_limit];
                    int cost;
                    strcpy(name, temp->datapat1.name);
                    strcpy(bdate, temp->datapat1.bdate);
                    age = temp->datapat1.age;
                    strcpy(address, temp->datapat1.address);
                    stat = temp->datapat1.stats;
                    clinic = temp->datapat2.clinic;
                    strcpy(docname, temp->datapat2.docname);

                    node* new1 = newnode(name, bdate, age, address, stat, clinic, docname);
                    strcpy(new1->datapat2.tdata, temp->datapat2.tdata);
                    strcpy(new1->datapat2.diagnosis, temp->datapat2.diagnosis);
                    strcpy(new1->datapat2.medikasi, temp->datapat2.medikasi);
                    new1->datapat2.harganya = temp->datapat2.harganya;
                    if(targetc->rear == NULL){
                        targetc->front = targetc->rear = new1;
                    }
                    targetc->rear->next=new1;
                    targetc->rear=new1;
                    deque(doqe);
                }
                entr();getchar();
            break;
            case 7:
                payment(targetc);
                deque(targetc);
                entr();getchar();
            break;
            case 0:
                exit(1);
            break;
            default:
                puts("Error Wrong Input!");
                entr();getchar();
            break;
        }
    }
        
    return 0;
}