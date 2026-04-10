#include <stdio.h>

typedef struct {
    char title[100];
    char author[100];
    float price;
} Book;

void display_book(Book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Price: %.2f\n", b.price);
}

int main(void) {
    Book b;
    printf("Enter title : ");
    scanf("%99s", b.title);
    printf("Enter author : ");
    scanf("%99s", b.author);
    printf("Enter price: ");
    scanf("%f", &b.price);

    printf("\n-- Book Details --\n");
    display_book(b);
    return 0;
}


//gcc 4.c -o 4.exe && .\4.exe
//./4.exe