#include "header.hpp"

/*
 *
 * Seguem aqui os algoritmos de ordenação
 * propriamente ditos.
 *
 * */

void insetionSort(int array[], int n) {
  int compare = 0, move = 0;

  for (int i = 0, j; i < n; i++, compare++) {

    visualize(array, n, compare, move);

    for (int j = i - 1; j >= 0; j--) {
      if (array[j + 1] < array[j]) {
        swap(array[j + 1], array[j]);
        compare++;
        move += 3;
      }
    }

    visualize(array, n, compare, move);
  }
}

void binaryInsetionSort(int array[], int n) {
  int compare = 0, move = 0;

  for (int i = 0, j; i <= n - 1; i++) {
    int S = 0, L = i;
    while (S < L) {
      int M = (S + L) / 2;
      if (array[i] >= array[M]) {
        S = M + 1;
        compare++;
      } else {
        L = M;
        compare++;
      }
    }

    for (int y = i; y > L /*Era S*/; y--) {
      swap(array[y - 1], array[y]);
      move += 3;
    }
    visualize(array, n, compare, move);
  }
}

void selectionSort(int array[], int n) {
  int compare = 0, move = 0;

  for (int i = 0, j, small; i < n; i++) {
    small = i;

    for (j = i + 1; j < n; j++, compare++)
      if (array[j] < array[small])
        small = j;

    visualize(array, n, compare, move);

    swap(array[i], array[small]);
    move += 3;
  }
}

void bubbleSort(int array[], int n) {
  int compare = 0, move = 0;

  for (int i = 0, j; i < n; i++) {

    for (int j = n - 1; j > i; j--) {
      compare++;
      if (array[j] < array[j - 1]) {
        swap(array[j], array[j - 1]);
        move += 3;
      }
    }

    visualize(array, n, compare, move);
  }
}

void heapaux(int array[], int L, int R, int &compare, int &move) {
  R--;
  int i = L, j = 2 * L;
  int x = array[L];
  move++;
  if (j < R && array[j] < array[j + 1])
    j++, compare++;

  compare++;

  while (j <= R && x < array[j]) {
    compare++;
    array[i] = array[j], move++;
    i = j;
    j = 2 * j;
    if (j < R && array[j] < array[j + 1])
      j++, compare++;
  }
  array[i] = x, move++;
}

void heapSort(int array[], int n, int &compare, int &move) {
  for (int L = split(n); L >= 0; L--) {
    heapaux(array, L, n, compare, move);
    visualize(array, n, compare, move);
  }

  for (int R = n - 1; R > 1; R--) {
    swap(array[0], array[R]), move += 3;
    heapaux(array, 0, R - 1, compare, move);
    visualize(array, n, compare, move);
  }

  if (array[0] > array[1])
    swap(array[0], array[1]), move += 3;

  visualize(array, n, compare, move);
}

void merge(int a[], int l, int h, int r, int c[], int &compare, int &move) {
  int i = l;
  int j = h + 1;
  int k = l - 1;

  while (i <= h && j <= r) {
    k++;
    if (a[i] < a[j]) {
      c[k] = a[i];
      compare++, move++, i++;
    } else {
      c[k] = a[j];
      compare++, move++, j++;
    }
  }

  while (i <= h) {
    move++, k++;
    c[k] = a[i];
    i++;
  }

  while (j <= r) {
    move++, k++;
    c[k] = a[j];
    j++;
  }
}

void mpass(int a[], int n, int p, int c[], int &compare, int &move) {
  int i = 0;
  while (i <= (n - (2 * p) + 1)) {
    merge(a, i, i + p - 1, i + (2 * p) - 1, c, compare, move);
    i += 2 * p;
  }
  if (i + p - 1 < n)
    merge(a, i, i + p - 1, n, c, compare, move);

  else
    for (int j = i; j <= n; j++) {
      move++;
      c[j] = a[j];
    }
}

void mergeSort(int array[], int n, int &compare, int &move) {

  int c[n];
  int p = 1;

  while (p < n) {
    visualize(array, n, compare, move);
    mpass(array, n - 1, p, c, compare, move);
    visualize(array, n, compare, move);
    p *= 2;
    visualize(array, n, compare, move);
    mpass(c, n - 1, p, array, compare, move);
    visualize(array, n, compare, move);
    p *= 2;
  }
  visualize(array, n, compare, move);
}

void quickSort(int v[], int L, int R, int n, int &compare, int &move) {

  int i = L;
  int j = R;

  int x = v[(int)((L + R) / 2)];
  move++;

  visualize(v, n, compare, move);

  do {
    compare++;
    while (v[i] < x) {
      compare++;
      i++;
    }
    while (v[j] > x) {
      compare++;
      j--;
    }

    if (i <= j) {
      swap(v[i], v[j]);
      move += 3;

      i++;
      j--;
    }
  } while (i <= j);

  visualize(v, n, compare, move);

  if (L < j)
    quickSort(v, L, j, n, compare, move);

  if (R > i)
    quickSort(v, i, R, n, compare, move);
}
