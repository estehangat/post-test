#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node *address;
typedef struct Mahasiswa {
    int NIM;
    char nama[50];
    float IPK;
} Mahasiswa;

typedef struct Node {
    Mahasiswa data;
    address next;
} Node;

address first = NULL;

address alokasikan(int NIM, char *nama, float IPK){
    address newNode = (address)malloc(sizeof(Node));
    strcpy(newNode -> data.nama, nama);
    newNode -> data.NIM = NIM;
    newNode -> data.IPK = IPK;
    newNode -> next = NULL;
    return newNode;
}

void insertFirst(address p){
    p -> next = first;
    first = p;
}

void insertLast(address p){
    if(first == NULL){
        first = p;
    } else {
        address temp = first;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = p;
    }
}

void deleteFirst(){
    if(first != NULL){
        address temp = first;
        first = first -> next;
        free(temp);
    }
}

void deleteLast(){
    if(first == NULL){
        printf("Kosong, gabisa dihapus\n");
        return;
    }

    if(first -> next == NULL){
        free(first);
        first = NULL;
        return;
    }

    address current = first;
    address prev = NULL;
    while(current -> next != NULL){
        prev = current;
        current = current -> next;
    }
    prev -> next = NULL;
    free(current);
}

void cetak(){
    address temp = first;
    while(temp != NULL){
        printf("NIM: %d, Nama: %s, IPK: %.2f\n", temp -> data.NIM, temp -> data.nama, temp -> data.IPK);
        temp = temp -> next;
    }
}

void insertAscending(address p){
    address temp = first;
    address prev = NULL;
    while(temp != NULL && p -> data.NIM > temp -> data.NIM){
        prev = temp;
        temp = temp -> next;
    }
    p -> next = temp;
    if(prev != NULL){
        prev -> next = p;
    } else {
        first = p;
    }
}

void swapData(address node1, address node2){
    Mahasiswa temp = node1 -> data;
    node1 -> data = node2 -> data;
    node2 -> data = temp;
}

void sortList(){
    
}

void cetakBerdasarkanNIM(){
    address temp = first;
    while(temp != NULL){
        printf("NIM: %d, Nama: %s, IPK: %.2f\n", temp -> data.NIM, temp -> data.nama, temp -> data.IPK);
        temp = temp -> next;
    }
}

int main(){
    address current;
    current = alokasikan(125, "Budi", 3.5);
    insertFirst(current);
    current = alokasikan(128, "Siti", 3.7);
    insertFirst(current);
    current = alokasikan(126, "Andi", 3.8);
    insertFirst(current);
    current = alokasikan(130, "Desi", 3.2);
    insertFirst(current);
    current = alokasikan(127, "Dedi", 3.9);
    insertFirst(current);
    current = alokasikan(129, "Saki", 3.4);
    insertFirst(current);
    deleteLast();
    printf("Setelah dihapus satu dari belakang:\n");
    cetak();
    printf("\nSetelah data diurutkan berdasarkan NIM:\n");
    cetakBerdasarkanNIM();
    return 0;
}