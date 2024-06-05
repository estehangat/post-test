#include <stdio.h>
#include <stdlib.h>
#define max 1000

typedef struct {
    int data[max];
    int count;
} stack;
stack tumpuk;

int isFull(stack *x){
    int hasil = 0;
    if((x -> count) == max){
        hasil = 1;
    }
    return hasil;
}

int isEmpty(stack *x){
    int hasil = 0;
    if((x -> count) == 0){
        hasil = 1;
    }
    return hasil;
}

void inisialisasi(stack *x){
    x -> count = 0;
}

void push(int angka, stack *x){
    if(isFull(x) == 1){
        printf("Penuh Bos");
    } else {
        x -> data[x -> count] = angka;
        (x -> count)++;
    }
}

void pop(stack *x){
    if(isEmpty(x) == 1){
        printf("Kosong Bos\n");
    } else {
        (x -> count)--;
        x -> data[x -> count] = 0;
    }
}

void fibonacci(int n, stack *x){
    int angka = x -> data[x -> count];
    printf("%d %d ", x -> data[x -> count = 0], x -> data[x -> count = 1]);
    for(int i = 0; i < n - 2; i++){
        angka += angka;
        printf("%d ", angka);
        (x -> count)++;
    }
}

int main(){
    int n;
    inisialisasi(&tumpuk);
    printf("Masukkan nilai n: ");
    scanf("%d", n);
    push(0, &tumpuk);
    push(1, &tumpuk);
    fibonacci(10, &tumpuk);
}