#include <stdio.h>
#include <immintrin.h>


int main() {
	int x1;
	printf("Insira o valor de linha da primeira matriz: ");
	scanf("%li" , &x1);
	int y1;
	printf("Insira o valor de coluna da primeira matriz: ");
	scanf("%li" , &y1);

	int x2;
	printf("Insira o valor de linha da primeira matriz: ");
	scanf("%li" , &x2);
	int y2;
	printf("Insira o valor de coluna da primeira matriz: ");
	scanf("%li" , &y2);

	if(x1 > 4 || y1 > 4 || x2 > 4 || y2 > 4){
		printf("Tamanho da matriz maior que o esperado");
	}
	else if(y1 != x2){
		printf("Impossivel realizar a multiplicacao");
	}
	else{

		double mat_A[x1][y1];
		double mat_B[x2][y2];

		for(int i = 0; i < x1; i++){
			for(int j = 0 ; j < y1 ;j++){
				printf("Matriz A[ %d ] [ %d ] = ", i, j);
				scanf("%le", &mat_A[i][j]);
			}
			printf("\n");
		}

		for(int i = 0; i < x2; i++){
			for(int j = 0 ; j < y2 ;j++){
				printf("Matriz B[ %d ] [ %d ] = ", i, j);
				scanf("%le", &mat_B[i][j]);
			}
			printf("\n");
		}
		double* vet_A = (double*)aligned_alloc(32 , 8*(sizeof(double)));

		for(int i = 0; i < x1 ; i++){
			for(int j = 0; j < y2; j++){
				vet_A[i] = mat_A[i][j];
			}
		}

		double* vet_B = (double*)aligned_alloc(32 , 8*(sizeof(double)));

		for(int i = 0; i < x1 ; i++){
			for(int j = 0; j < y2; j++){
				vet_B[i] = mat_B[i][j];
			}
		}
		__m256d A =  _mm256_load_pd(vet_A);
    	__m256d B =  _mm256_load_pd(vet_B);
		
		double matrizRes[x1][y2];
		
		for(int i = 0; i < x1; i++){
			for(int j = 0; j < y2; j++){
				matrizRes[i][j] = 0;
			}
		}

		double* vet_C = (double*)aligned_alloc(32 , 8*(sizeof(double)));

		for(int i = 0; i < x1; i++){
			for(int j = 0; j < y2; j++){
				vet_C[i] = matrizRes[i][j];
			}
		}

		__m256d C = _mm256_load_pd(vet_C);
		__m256d mult = _mm256_add_pd(A , B);
		mult = _mm256_mul_pd(mult , mult);
		
		C = mult;

		double* matA = (double*)&A;
   	 	double* matB = (double*)&B;
    	double* matC = (double*)&C;

		
		printf("Valores da matriz A \n");

		for(int i = 0; i < x1 + y1; i++){
			printf("%le" ,&matA[i]);
			printf(" ");
		}
		
		printf("\nValores da matriz B \n");
		
		for(int i = 0; i < x1 + y1; i++){
			printf("%le" ,&matB[i]);
			printf(" ");
		}

		printf("\nValores da matriz C \n");
		for(int i = 0; i < x1 + y1; i++){
			printf("%le" ,&matC[i]);
			printf(" ");
		}
	}
	
    return 0;
}
