#include <immintrin.h>
#include <stdio.h>


int main(){

   //Declarando o valor epi 16 onde 4096 e o valor maximo do tipo inteiro 
    __m256i vet_A = _mm256_set1_epi16(4096);
    // O 10 serve para estourar a memoria reservada
    __m256i vet_B = _mm256_set1_epi16(10);

    //Realizando a soma com 16 bits sem saturacao
    __m256i _16BitsSom = _mm256_add_epi16(vet_A,vet_B);
    //Realizando a soma com 16 bits com saturacao
	__m256i _16BitsSomSat = _mm256_adds_epi16(vet_A,vet_B);

     //Realizando a subitracao com 16 bits sem saturacao
    __m256i _16BitsSub = _mm256_sub_epi16(vet_A,vet_B);
    //Realizando a subitracao com 16 bits com saturacao
	__m256i _16BitsSubSat = _mm256_subs_epi16(vet_A,vet_B);

    //Declarando os ponteiros que carrega os respectivos valores de memória
	short* somaNormal16Bits = (short*)& _16BitsSom;
	short* somaSaturada16Bits = (short*)& _16BitsSomSat;
    short* subiNormal16Bits = (short*)& _16BitsSub;
	short* subiSaturada16Bits = (short*)& _16BitsSubSat;

    //Declarando o valor epi 8 onde 128 e o valor maximo do tipo inteiro 
	__m256i vet_C = _mm256_set1_epi8(128);
     // O 5 serve para estourar a memoria reservada
	__m256i vet_D = _mm256_set1_epi8(5);

     //Realizando a soma com 8 bits sem saturacao
	__m256i _8Bits = _mm256_add_epi16(vet_C,vet_D);
     //Realizando a soma com 8 bits sem saturacao
	__m256i _8BitsSat = _mm256_adds_epi16(vet_C,vet_D);
    
   //Realizando a subitracao com 8 bits sem saturacao
    __m256i _8BitsSub = _mm256_sub_epi16(vet_C,vet_D);
    //Realizando a subitracao com 8 bits sem saturacao
	__m256i _8BitsSubSat = _mm256_subs_epi16(vet_C,vet_D);

   //Declarando os ponteiros que carrega os respectivos valores de memória
	short* somaNormal8Bits = (short*)& _8Bits;
	short* somaSaturada8Bits = (short*)& _8BitsSat;
    short* subiNormal8Bits = (short*)& _8BitsSub;
	short* subiSaturada8Bits = (short*)& _8BitsSubSat;

   
    //Impressao dos resultados no console de epi16
    printf("\n Soma sem saturacao de epi16: \n");
    for (int i = 0; i < 8; i++){
		
		printf("%hi ", &somaNormal16Bits[i]);
	}
	
    printf("\n Soma com saturacao de epi16: \n");
    for (int i = 0; i < 8; i++){
		printf("%hi ", &somaSaturada16Bits[i]);
	}
	

	printf("\n Subitracao sem saturacao de epi16: \n");
    for (int i = 0; i < 8; i++){
		printf("%hi ", &subiNormal16Bits[i]);
		
	}

	printf("\n Subitracao com saturacao de epi16 : \n");
    for (int i = 0; i < 8; i++){
		printf("%hi ", &subiSaturada16Bits[i]);
	}

	 //Impressao dos resultados no console de epi8
	 printf("\n Soma sem saturacao epi8: \n");
    for (int i = 0; i < 16; i++){
		
		printf("%hi ", &somaNormal8Bits[i]);
	}
	
    printf("\n Soma com saturacao epi8: \n");
    for (int i = 0; i < 16; i++){
		printf("%hi ", &somaSaturada8Bits[i]);
	}
	

	printf("\n Subitracao sem saturacao epi8: \n");
    for (int i = 0; i < 16; i++){
		printf("%hi ", &subiNormal8Bits[i]);
		
	}

	printf("\n Subitracao com saturacao epi8: \n");
    for (int i = 0; i < 16; i++){
		printf("%hi ", &subiSaturada8Bits[i]);
	}




    return 0;
}