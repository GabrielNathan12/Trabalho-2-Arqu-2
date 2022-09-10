#include <stdio.h>
#include <immintrin.h>

int main(){
    printf("Selecione o tipo dos dados:\n");
    printf("1 - doubles (4x 64Bits)\n");
    printf("2 - floats (8x 32Bits)\n");
    printf("3 - inteiros (8x 32Bits)\n");

    int entrada;
    scanf("%d", &entrada);


    return 0;
}