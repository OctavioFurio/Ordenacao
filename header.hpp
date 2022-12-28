#include <chrono>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <utility>

using namespace std;

/*
 *
 * Seguem aqui algumas funções auxiliares.
 * Nenhuma é extritamente necessária, porém
 * trazem grande versatilidade em diversos processos.
 *
 * */

inline string generate(int *vector, int n, int choice) {
  /*
   *
   * Esta função é utilizada pelo programa para gerar os
   * vetores que serão organizados pelos algoritmos.
   *
   * */
  int a = 0;

  switch (choice) {
  case 1:
    for (int i = 0; i < n; i++) {
      *(vector + i) = a;
      a += rand() % 3;
    }
    return "Crescente";
  case 2:
    for (int i = n - 1; i >= 0; i--) {
      a += rand() % 3;
      *(vector + i) = a;
    }
    return "Decrescente";
  default:
    for (int i = 0; i < n; i++)
      *(vector + i) = rand() % 100;
  }
  return "Aleatorio";
}

inline void rewrite(int n) {
  /*
   *
   * Esta pequena função utiliza-se de escape sequences
   * para reescrever a tela.
   *
   * */
  for (int i = 0; i <= n; i++) {
    cout << "                                                                ";
    cout << "                                                                ";
    printf("\033[F");
  }
}

inline void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// Efetivamente, uma função floor()
inline int split(int x) { return x % 2 == 0 ? x / 2 : (x - 1) / 2; }

inline void wait(int x) {
  std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

/*
 *
 * Esta função "desenha" o array na tela, permitindo
 * uma melhor visualização da ordenação.
 *
 * */

inline void largePrint(int array[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "\t|";
    for (int size = 0; size < 100; size++)
      cout << ' ';
    cout << endl;
  }

  rewrite(n);

  for (int i = 0; i < n; i++) {
    cout << "\x1b[1;31m"
         << "\t█";
    for (int size = 0; size < array[i]; size++)
      cout << "\x1b[1;33m█";
    cout << endl;
  }
}

/*
 *
 * Esta função sobrescreve o array desenhado na
 * tela com uma nova versão de si, atualizando a
 * visualização, além de controlar a velocidade
 * destas atualizações.
 *
 * */
inline void visualize(int v[], int n, int &compare, int &move) {
  cout << "\x1b[1;37m"
       << "\t|";
  for (int x = 0; x < n; x++)
    printf(" %.2d", v[x]);

  cout << "\x1b[1;37m"
       << " | C:" << compare << " M:" << move << "\n\n\n";

  largePrint(v, n);

  wait(40);

  rewrite(n + 1);
}

void insetionSort(int array[], int n);
void binaryInsetionSort(int array[], int n);
void selectionSort(int array[], int n);
void bubbleSort(int array[], int n);
inline void heapaux(int array[], int L, int R, int &compare, int &move);
void heapSort(int array[], int n, int &compare, int &move);
void merge(int a[], int l, int h, int r, int c[], int &compare, int &move);
void mpass(int a[], int n, int p, int c[], int &compare, int &move);
void mergeSort(int array[], int n, int &compare, int &move);
void quickSort(int v[], int L, int R, int n, int &compare, int &move);
