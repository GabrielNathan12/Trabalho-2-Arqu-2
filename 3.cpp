// Cifra de César

#include <immintrin.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>

std::string criptografar(std::string texto) {
	int numero_palavras = ceil(texto.length() / 8.0);
	int texto_index = 0;
	std::string novo_texto = "";
	for (int i = 0; i < numero_palavras; i++) {
		char p[8];
		for (int j = texto_index; j < 8; j++) {
			if (j >= texto.length()) {
				p[j] = ' ';
			}
			else{
				p[j] = texto[texto_index];
			}
			texto_index++;
		}
		__m256i palavra = _mm256_set_epi32(p[7], p[6], p[5], p[4], p[3], p[2], p[1], p[0]);
		__m256 _m256_palavra = _mm256_cvtepi32_ps(palavra);
		_m256_palavra = _mm256_permute_ps(_m256_palavra, 0b00111001);
		float p_f[8];
		_mm256_storeu_ps(p_f, _m256_palavra);
		for (int i = 0; i < 8; i++) {
			novo_texto += char(int(p_f[i]));
		}
	}
	return novo_texto;
}

std::string descriptografar(std::string texto) {
	int numero_palavras = ceil(texto.length() / 8.0);
	int texto_index = 0;
	std::string novo_texto = "";
	for (int i = 0; i < numero_palavras; i++) {
		char p[8];
		for (int j = texto_index; j < 8; j++) {
			if (j >= texto.length()) {
				p[j] = ' ';
			}
			else{
				p[j] = texto[texto_index];
			}
			texto_index++;
		}
	__m256i palavra = _mm256_set_epi32(p[7], p[6], p[5], p[4], p[3], p[2], p[1], p[0]);
	__m256 _m256_palavra = _mm256_cvtepi32_ps(palavra);
	_m256_palavra = _mm256_permute_ps( _m256_palavra, 0b10010011);
		float p_f[8];
		_mm256_storeu_ps(p_f, _m256_palavra);
		for (int i = 0; i < 8; i++) {
			novo_texto += char(int(p_f[i]));
		}
	}
	return novo_texto;
}

int main() {

	std::cout << "c: criptografar\n";
	std::cout << "d: descriptografar\n";
	std::cout << "> ";

	char c;
	std::cin >> c;


	std::cout << "Nome do arquivo (na pasta raíz):\n";
	std::cout << "> ";

	std::string nome_arquivo;
	std::cin >> nome_arquivo;

	std::string texto = "";
	char* criptografada;

	if (c == 'c') {
		std::ifstream arquivo_leitura(nome_arquivo);
		if (arquivo_leitura.is_open()){
			getline(arquivo_leitura, texto);
			texto = criptografar(texto);
			arquivo_leitura.close();
		}
		std::ofstream arquivo_escrita(nome_arquivo);
		if (arquivo_escrita.is_open()) {
			arquivo_escrita << texto;
			arquivo_escrita.close();
		}
	}
	if (c == 'd') {
		std::ifstream arquivo_leitura(nome_arquivo);
		if (arquivo_leitura.is_open()){
			getline(arquivo_leitura, texto);
			texto = descriptografar(texto);
			arquivo_leitura.close();
		}
		std::ofstream arquivo_escrita(nome_arquivo);
		if (arquivo_escrita.is_open()) {
			arquivo_escrita << texto;
			arquivo_escrita.close();
		}
	}

	return 0;
}