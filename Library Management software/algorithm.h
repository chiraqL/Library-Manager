#pragma once
#include"allheader.h"
class algorithm {
private:
	int mid;
public:
	void swap(book&, book&);
	//book sort algorithms
	float list_book_asc_bubblesort(book*, int, bool&);
	float list_book_asc_selectionsort(book*, int, bool&);
	float list_book_asc_insertionsort(book*, int, bool&);
	float list_book_asc_mergesort(book*, int, bool&);
	void mergeSort(book* T, int l, int r, bool&);
	void merge(book* T, int l, int m, int r, bool&);
	float list_book_asc_heapsort(book*, int, bool&);
	void heapify(book*, int n, int i, bool&);
	float list_book_asc_quicksort(book* T, int n, bool&);
	void quickSort(book*, int low, int high, bool&);
	int partition(book*, int low, int high, bool&);
	float list_book_asc_bogosort(book* T, int n, bool&);
	bool isSorted(book* T, int n, bool&);
	void shuffle(book* T, int n);

	//book search
	int binary_search_book(book* T, int l, int r, char  x[20]);

	//student
};
