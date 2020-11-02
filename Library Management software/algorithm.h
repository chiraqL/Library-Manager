#pragma once
#include "Headers.h"
class AlgorithmStudent {
private:
	int mid;
	int student::* i_alias;
	char(student::* s_alias)[30];
public:
	void set_alias_sort_student(int sortby);
	void swap(student&, student&);

	//book sort algorithms
	float list_student_bubblesort(student*, int, bool&, bool&, int);
	float list_student_selectionsort(student*, int, bool&, bool&, int);
	float list_student_insertionsort(student*, int, bool&, bool&, int);
	float list_student_mergesort(student*, int, bool&, bool&, int);
	void mergeSort(student* T, int l, int r, bool&, bool&);
	void merge(student* T, int l, int m, int r, bool&, bool&);
	float list_student_heapsort(student*, int, bool&, bool&, int);
	void heapify(student*, int n, int i, bool&, bool&);
	float list_student_quicksort(student* T, int n, bool&, bool&, int);
	void quickSort(student*, int low, int high, bool&, bool&);
	int partition(student*, int low, int high, bool&, bool&);
	float list_student_bogosort(student* T, int n, bool&, bool&, int);
	bool isSorted(student* T, int n, bool&, bool&);
	void shuffle(student* T, int n);

	//book search
	int binary_search_student(student* T, int l, int r, char  x[20]);

};
class AlgorithmBook {
private:
	int mid;
	int book::* i_alias;
	char(book::* s_alias)[30];
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

};

class Sortmenu {
private:
	graphics gra;
	tools to;
public:
	int sortby;
	int order;
	int sorting_algo;

	void sort_book_menu();
	void sort_student_menu();
};