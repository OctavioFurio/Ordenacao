#include "header.hpp"

/*
 *
 * Menu principal
 *
 * */

int main(int n, char **order) {

  /*
   *
   *  Dado que o programa deve ser executado via terminal,
   *  é interessante que haja feedback quanto ao seu uso.
   *  Para tal, segue uma pequena interface, utilizando-se
   *  de escape sequences para formatação.
   *
   * */

  if (n != 4) {
    cout << "\n\t\x1b[1;37mErro na chamada do programa!"
            "\n\n\t\x1b[37mPara executar o programa corretamente, tente:"
            "\n\n\t\t\x1b[1;31m{nome_do_executavel} "
            "{numero_de_itens_do_vetor} "
            "{numero_do_algoritmo} "
            "{ordenacao_inicial}"
            "\n\n\t\x1b[37mExemplo:"
            "\n\n\t\t\x1b[1;31m./ordering 50 2 3"
            "\n\n\t\x1b[3;37mAlgoritmos implementados:\n"
            "\n\t1) Insertion Sort."
            "\n\t2) Binary Insertion Sort."
            "\n\t3) Selection Sort."
            "\n\t4) Bubble Sort."
            "\n\t5) Heap Sort."
            "\n\t6) Merge Sort."
            "\n\t7) Quick Sort.\n\n"
            "\t8) Testar todos.\n\n"
            "\t\x1b[3;33mOrdenacoes iniciais:\n"
            "\n\t1) Crescente."
            "\n\t2) Decrescente."
            "\n\t3) Aleatorio.\n\n";
    ;
    return 0;
  }

  int c = 0, m = 0;
  int num = atoi(order[1]);  // char -> int
  int init = atoi(order[3]); // char -> int
  int unsorted_array[num];

  /*
   *
   * Um pequeno algoritmo para criar um vetor aleatorio
   * com N termos
   *
   * */
  srand(time(NULL));

  cout
      << "\n\t[ALGORITMOS DE ORDENACAO]\n\n\tOrdernacao inicial selecionada:\t "
      << generate(unsorted_array, num, init) << "\n\tAlgoritmo selecionado: "
      << "\x1b[1;33m";

  switch (order[2][0]) {
  case '1':
    cout << "Insertion sort\n";
    insetionSort(unsorted_array, num);
    break;
  case '2':
    cout << "Binary Insertion sort\n";
    binaryInsetionSort(unsorted_array, num);
    break;
  case '3':
    cout << "Selection sort\n";
    selectionSort(unsorted_array, num);
    break;
  case '4':
    cout << "Bubble sort\n";
    bubbleSort(unsorted_array, num);
    break;
  case '5':
    cout << "Heap sort\n";
    heapSort(unsorted_array, num, c, m);
    break;
  case '6':
    cout << "Merge sort\n";
    mergeSort(unsorted_array, num, c, m);
    break;
  case '7':
    cout << "Quick sort\n";
    quickSort(unsorted_array, 0, num - 1, num, c, m);
    break;
  case '8':
    cout << "Todos.";

    cout << "\n\n\tInsertion sort\n";
    insetionSort(unsorted_array, num);

    generate(unsorted_array, num, init);
    c = 0, m = 0;

    cout << "\n\n\tBinary Insertion sort\n";
    binaryInsetionSort(unsorted_array, num);

    generate(unsorted_array, num, init);
    c = 0, m = 0;

    cout << "\n\n\tSelection sort\n";
    selectionSort(unsorted_array, num);

    generate(unsorted_array, num, init);
    c = 0, m = 0;

    cout << "\n\n\tBubble sort\n";
    bubbleSort(unsorted_array, num);

    generate(unsorted_array, num, init);
    c = 0, m = 0;

    cout << "\n\n\tHeap sort\n";
    heapSort(unsorted_array, num, c, m);

    generate(unsorted_array, num, init);
    c = 0, m = 0;

    cout << "\n\n\tMerge sort\n";
    mergeSort(unsorted_array, num, c, m);

    generate(unsorted_array, num, init);
    c = 0, m = 0;

    cout << "\n\n\tQuick sort\n";
    quickSort(unsorted_array, 0, num - 1, num, c, m);

    break;

  default:
    cout << "\n\n\t\x1b[1;31mErro! Nao ha algoritmo com este numero!"
            "\n\n\t\x1b[3;37mAlgoritmos implementados:\n"
            "\n\t1) Insertion Sort."
            "\n\t2) Binary Insertion Sort."
            "\n\t3) Selection Sort."
            "\n\t4) Bubble Sort."
            "\n\t5) Heap Sort."
            "\n\t6) Merge Sort."
            "\n\t7) Quick Sort.\n\n"
            "\t8) Testar todos.\n\n"
            "\t\x1b[3;33mOrdenacoes iniciais:\n"
            "\n\t1) Crescente."
            "\n\t2) Decrescente."
            "\n\t3) Aleatorio.\n\n";
    return 0;
  }

  cout << "\n\n\t\x1b[37mOrganizado!";

  return 0;
}
