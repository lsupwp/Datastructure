#include <stdio.h>

int main(){
    int n = 100;
    int arr[] = {1};

    printf("%p\n", &arr);
    printf("%p\n", &n);

    printf("%i\n", n);

    arr[1] = 10;
    printf("%i\n", n);


    printf("%p\n", &n);
    printf("%p\n", &arr[1]);
    printf("%p\n", &arr[0]+1);
}