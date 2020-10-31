#pragma once
#include "Headers.h"
class algorithm {
private:
	int mid;

	int book::* i_alias;
	char(book::* s_alias)[50];
public:
	void set_alias_sort_book(int sortby);
	void swap(book&, book&);
	//book sort algorithms
	float list_book_bubblesort(book*, int, bool&, bool&, int);
	float list_book_selectionsort(book*, int, bool&, bool&, int);
	float list_book_insertionsort(book*, int, bool&, bool&, int);
	float list_book_mergesort(book*, int, bool&, bool&, int);
	void mergeSort(book* T, int l, int r, bool&, bool& );
	void merge(book* T, int l, int m, int r, bool&, bool&  );
	float list_book_heapsort(book*, int, bool&, bool&, int);
	void heapify(book*, int n, int i, bool&,bool&);
	float list_book_quicksort(book* T, int n, bool&, bool&, int);
	void quickSort(book*, int low, int high, bool&,bool&);
	int partition(book*, int low, int high, bool&,bool&);
	float list_book_bogosort(book* T, int n, bool&, bool&, int);
	bool isSorted(book* T, int n, bool&, bool&);
	void shuffle(book* T, int n);

	//book search
	int binary_search_book(book* T, int l, int r, char  x[20]);

	//student
};
