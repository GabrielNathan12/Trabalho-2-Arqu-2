// Multiplicação de duas matrizes


#include <iostream>
#include <immintrin.h>


double** matrix_mult(double** a, double** b) {
    __m256d* a_m256d = new __m256d[4];
	__m256d* b_m256d = new __m256d[4];
    __m256d* x_m256d = new __m256d[4];

    for (int i = 0; i < 4; i++) {
		a_m256d[i] = _mm256_set_pd(a[i][3], a[i][2], a[i][1], a[i][0]);
        b_m256d[i] = _mm256_set_pd(b[3][i], b[2][i], b[1][i], b[0][i]);
	}

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            x_m256d[i] = _mm256_add_pd(x_m256d[i], _mm256_mul_pd(a_m256d[j], b_m256d[j]));
        }
    }

    double** x = new double*[4];

    for (int i = 0; i < 4; i++) {
        x[i] = new double[4];
        _mm256_storeu_pd (x[i], x_m256d[i]);
    }

    return x;
}


int main() {

    int a_m, a_n, b_m, b_n;

    std::cout << "Entre as dimensões da matriz A: ";
    std::cin >> a_m >> a_n;
    std::cout << "Entre as dimensões da matriz B: ";
    std::cin >> b_m >> b_n;

    if (a_n != b_m) {
    	std::cout << "Dimensões incompatíveis para multiplicação!";
        return 1;
    }

    if (a_m > 4 or a_n > 4 or b_m > 4 or b_n > 4) {
        std::cout << "Dimensão máxima deve ser 4!";
    	return 2;
    }

    int x_m = a_n, x_n = b_m;

    std::cout << "Entre com os valores da matriz A:\n";

	double** a = new double*[4];
	for (int i = 0; i < 4; i++) {
		a[i] = new double;
	}

	for (int i = 0; i < a_m; i++) {
		for (int j = 0; j < a_n; j++) {
			std::cin >> a[i][j];
		}
	}

    std::cout << "Entre com os valores da matriz B:\n";

    double** b = new double*[4];
	for (int i = 0; i < 4; i++) {
		b[i] = new double;
	}

	for (int i = 0; i < b_m; i++) {
		for (int j = 0; j < b_n; j++) {
			std::cin >> b[i][j];
		}
	}

    std::cout << "A x B =\n";

    double** x = matrix_mult(a, b);

    for (int i = 0; i < b_m; i++) {
        std::cout << '\t';
		for (int j = 0; j < b_n; j++) {
			std::cout << x[i][j] << ' ';
		}
        std::cout << '\n';
	}

    return 0;
}