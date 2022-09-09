#include <immintrin.h>
#include <stdio.h>


int main(){

    //Alocando espaco na memoria para o vetor de X
    float* vet_X = (float*)aligned_alloc(32 , 8*(sizeof(float)));

    vet_X[0] = 1.0f;
    vet_X[1] = 3.0f;
    vet_X[2] = 0.5f;
    vet_X[3] = 5.9f;
    vet_X[4] = 1.4f;
    vet_X[5] = 9.0f;
    vet_X[6] = 1.8f;
    vet_X[7] = 4.4f;
    
	
   //Alocando espaco na memoria para o vetor de Y
    float* vet_Y = (float*)aligned_alloc(32 , 8*(sizeof(float)));

    vet_Y[0] = 0.7f;
    vet_Y[1] = 3.5f;
    vet_Y[2] = 1.5f;
    vet_Y[3] = 3.9f;
    vet_Y[4] = 1.9f;
    vet_Y[5] = 4.5f;
    vet_Y[6] = 8.8f;
    vet_Y[7] = 7.4f;
    
    //Declarando o vetor do escalar
    float* vetEscalar = (float*) aligned_alloc (32, 8*(sizeof(float)));
    //Escalar que vai ser lido
    float esq;

    printf("Entre com o valor de escalar : \n");
    scanf("%f",&esq);

    // Faz o vetor 
    for(int i = 0; i < 8 ; i++){
        vetEscalar[i] = esq;
    }

    //Carregando os vetores para a memoria
    __m256 X =  _mm256_load_ps(vet_X);
    __m256 Y =  _mm256_load_ps(vet_Y);
    __m256 es = _mm256_load_ps(vetEscalar);

    //Multplica o vetor X pelo o escalar 
    __m256 mult = _mm256_mul_ps(X , es);
    // Soma o resultado da multiplicacao com o vetor Y
    __m256 result = _mm256_add_ps(mult , Y);

    //Pegando a referencia dos vetores X e Y
    float* vetX = (float*)&X;
    float* vetY = (float*)&Y;
    //O vetor que ira ser guardado o resultado
    float res_operacao[8];

    _mm256_store_ps((float*)&res_operacao , result);

    
    printf("O vetor X e multiplicado pelo o escalar e depois e feita a soma com o vetor Y : \n" );
    
    //Imprimindo o vetor de X
    printf("X(0)= %lf,X(1)= %lf,X(2)= %lf,X(3)= %lf,X(4)= %lf,X(5)= %lf,X(6)= %lf,X(7)= %lf \n" ,
    vetX[0], vetX[1], vetX[2], vetX[3], vetX[4], vetX[5], vetX[6], vetX[7]); 
    //Imprimindo o vetor de Y
    printf("Y(0)= %lf,Y(1)= %lf,Y(2)= %lf,Y(3)= %lf,Y(4)= %lf,Y(5)= %lf,Y(6)= %lf,Y(7)= %lf \n" , 
    vetY[0], vetY[1], vetY[2], vetY[3], vetY[4], vetY[5], vetY[6], vetY[7]);
    // Resultado das operacoes 
    printf("R(0)= %lf,R(1)= %lf,R(2)= %lf,R(3)= %lf,R(4)= %lf,R(5)= %lf,R(6)= %lf,R(7)= %lf \n" , 
    res_operacao[0], res_operacao[1], res_operacao[2], res_operacao[3], res_operacao[4], res_operacao[5], res_operacao[6], res_operacao[7]);
    
    
    return 0;
}