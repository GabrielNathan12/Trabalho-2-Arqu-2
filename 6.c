#include <immintrin.h>
#include <stdio.h>


int main(){

    //Alocando espaco na memoria para o vetor A
    double* vet_A = (double*)aligned_alloc(32 , 4*(sizeof(double)));
    
    printf("Entre com os dados do vetor A : \n");
    
    for(int i = 0; i < 4 ;i++){
        scanf("%le",&vet_A[i]);
    }
    
   //Alocando espaco na memoria para o vetor B
    double* vet_B = (double*)aligned_alloc(32 , 4*(sizeof(double)));

    printf("Entre com os dados do vetor B : \n");
    
    for(int i = 0; i < 4 ;i++){
        scanf("%le",&vet_B[i]);
    }

    //Alocando espaco na memoria para o vetor C
    double* vet_C = (double*) aligned_alloc (32, 4*(sizeof(double)));
    
    printf("Entre com os dados do vetor C : \n");
    
    for(int i = 0; i < 4 ;i++){
        scanf("%le",&vet_C[i]);
    }

    
    //Carregando os vetores para a memoria

    __m256d A =  _mm256_load_pd(vet_A);
    __m256d B =  _mm256_load_pd(vet_B);
    __m256d C = _mm256_load_pd(vet_C);

    //Realiza a operacao de multiplicao de A e B e guarda no vetor D
    __m256d vet_D = _mm256_mul_pd(A , B);
    // Realiza a operacao de soma dele mesmo e o vetor C
    vet_D = _mm256_add_pd(vet_D , C);


    double* vetA = (double*)&A;
    double* vetB = (double*)&B;
    double* vetC = (double*)&C;
   
    double* vetD = (double*)&vet_D;
    
    //Imprimindo o vetor de A
    printf("A(0)= %lf,A(1)= %lf,A(2)= %lf,A(3)= %lf,A(4)= %lf \n" ,
    vetA[0], vetA[1], vetA[2], vetA[3], vetA[4]); 
    
     //Imprimindo o vetor de B
    printf("B(0)= %lf,B(1)= %lf,B(2)= %lf,B(3)= %lf,B(4)= %lf \n" ,
    vetB[0], vetB[1], vetB[2], vetB[3], vetB[4]); 
    
     //Imprimindo o vetor de C
    printf("C(0)= %lf,C(1)= %lf,C(2)= %lf,C(3)= %lf,C(4)= %lf \n" ,
    vetC[0], vetC[1], vetC[2], vetC[3], vetC[4]); 
    
     //Imprimindo o vetor de D
    printf("D(0)= %lf,D(1)= %lf,D(2)= %lf,D(3)= %lf,D(4)= %lf \n" ,
    vetD[0], vetD[1], vetD[2], vetD[3], vetD[4]); 
  
    
    return 0;
}