/*

=== Fused Multiply Add ===

FOR j := 0 to 7
i := j*32
	IF ((j & 1) == 0)
		dst[i+31:i] := (a[i+31:i] * b[i+31:i]) - c[i+31:i]
	ELSE
		dst[i+31:i] := (a[i+31:i] * b[i+31:i]) + c[i+31:i]
	FI
ENDFOR
dst[MAX:256] := 0

*/


#include <immintrin.h>
#include <iostream>


int* fma_int(int a[], int b[], int c[]) {
	__m256i a_i = _mm256_set_epi32(a[7], a[6], a[5], a[4], a[3], a[2], a[1], a[0]);
	__m256i b_i = _mm256_set_epi32(b[7], b[6], b[5], b[4], b[3], b[2], b[1], b[0]);
	__m256i c_i = _mm256_set_epi32(c[7], c[6], c[5], c[4], c[3], c[2], c[1], c[0]);
	__m256 a_f = _mm256_cvtepi32_ps(a_i);
	__m256 b_f = _mm256_cvtepi32_ps(b_i);
	__m256 c_f = _mm256_cvtepi32_ps(c_i);
	__m256i dst = _mm256_cvtps_epi32(_mm256_addsub_ps(_mm256_mul_ps(a_f, b_f), c_f));
	float* fma_f = new float[8];
	_mm256_storeu_ps(fma_f, _mm256_cvtepi32_ps(dst));
	int* fma_i = new int[8];
	for (int i = 0; i < 8; i++) {
		fma_i[i] = fma_f[i];
	}
	delete[] fma_f;
	return fma_i;
}

float* fma_float(float a[], float b[], float c[])  {
	__m256 a_f = _mm256_load_ps(a);
	__m256 b_f = _mm256_load_ps(b);
	__m256 c_f = _mm256_load_ps(c);
	__m256 dst = _mm256_addsub_ps(_mm256_mul_ps(a_f, b_f), c_f);
	float* fma_f = new float[8];
	_mm256_storeu_ps(fma_f, dst);
	return fma_f;
}

double* fma_double(double a[], double b[], double c[])  {
	__m256d a_d = _mm256_load_pd(a);
	__m256d b_d = _mm256_load_pd(b);
	__m256d c_d = _mm256_load_pd(c);
	__m256d dst = _mm256_addsub_pd(_mm256_mul_pd(a_d, b_d), c_d);
	double* fma_d = new double[8];
	_mm256_storeu_pd(fma_d, dst);
	return fma_d;
}


int main() {

	std::cout << "i: integer\n";
	std::cout << "f: float\n";
	std::cout << "d: double\n";
	std::cout << "> ";

	char c;
	std::cin >> c;

	if (c == 'i') {
		int a[8], b[8], c[8];
		std::cout << "Digite os valores de A: ";
		std::cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7];
		std::cout << "Digite os valores de B: ";
		std::cin >> b[0] >> b[1] >> b[2] >> b[3] >> b[4] >> b[5] >> b[6] >> b[7];
		std::cout << "Digite os valores de C: ";
		std::cin >> c[0] >> c[1] >> c[2] >> c[3] >> c[4] >> c[5] >> c[6] >> c[7];
		int* fma = fma_int(a, b, c);
		std::cout << "FMA(A, B, C) = ";
		for (int i = 0; i < 8; i++) {
			std::cout << fma[i] << ' ';
		}
		std::cout << std::endl;
	}
	else if (c == 'f') {
		float a[8], b[8], c[8];
		std::cout << "Digite os valores de A: ";
		std::cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7];
		std::cout << "Digite os valores de B: ";
		std::cin >> b[0] >> b[1] >> b[2] >> b[3] >> b[4] >> b[5] >> b[6] >> b[7];
		std::cout << "Digite os valores de C: ";
		std::cin >> c[0] >> c[1] >> c[2] >> c[3] >> c[4] >> c[5] >> c[6] >> c[7];
		float* fma = fma_float(a, b, c);
		std::cout << "FMA(A, B, C) = ";
		for (int i = 0; i < 8; i++) {
			std::cout << fma[i] << ' ';
		}
		std::cout << std::endl;
	}
	else if (c == 'd') {
		double a[4], b[4], c[4];
		std::cout << "Digite os valores de A: ";
		std::cin >> a[0] >> a[1] >> a[2] >> a[3];
		std::cout << "Digite os valores de B: ";
		std::cin >> b[0] >> b[1] >> b[2] >> b[3];
		std::cout << "Digite os valores de C: ";
		std::cin >> c[0] >> c[1] >> c[2] >> c[3];
		double* fma = fma_double(a, b, c);
		std::cout << "FMA(A, B, C) = ";
		for (int i = 0; i < 4; i++) {
			std::cout << fma[i] << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}