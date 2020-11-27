#pragma once
#include "Headers.h"

class AlgorithmStudent {
private:
	int mid;
	int student::* i_alias;							//pointers to member data
	char(student::* s_alias)[50];
public:
	void set_alias_sort_student(int sortby);		//setting pointers to member data
	void set_alias_search_student(int searchby);
	void swap(student&, student&);

	//Student Sort
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

	//Student Search
	int linear_search_student(student* T, int n, char x[50], bool order, bool type, int searchby);
	int binary_search_student(student* T, int n, char x[50], bool order, bool type, int searchby);
	int binary_search_algo(student* T, int l, int r, char  x[50]);

};
class AlgorithmBook {
private:
	int mid;
	int book::* i_alias;
	char(book::* s_alias)[50];
public:
	void set_alias_sort_book(int sortby);
	void set_alias_search_book(int searchby);
	void swap(book&, book&);

	//Book Sort
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

	//Book Search
	int linear_search_book(book* T, int n, char x[50], bool order, bool type, int searchby);
	int binary_search_book(book* T, int n, char x[50], bool order, bool type, int searchby);
	int binary_search_algo(book* T, int l, int r, char x[50]);
};

class Sortmenu {
private:
	graphics gra;
	tools to;
public:
	int sortby = 0;
	int order = 0;
	int sorting_algo = 0;

	void sort_book_menu();
	void sort_student_menu();
};

class Searchmenu {
private:
	graphics gra;
	tools to;
public:
	int searchby = 0;
	int searching_algo = 0;

	void search_book_menu();
	void search_student_menu();
};