#pragma once
#include <chrono>			//for time of execution
#include "Headers.h"

void AlgorithmBook::set_alias_sort_book(int sortby)
{
	//1.Price\n2.Book name\n3.Author name\n4.Quantity\n5.Publisher
	switch (sortby)
	{
	case 1:
		i_alias = &book::price;
		break;
	case 2:
		s_alias = &book::book_name;
		break;
	case 3:
		s_alias = &book::authorname;
		break;
	case 4:
		i_alias = &book::quantity;
		break;
	case 5:
		s_alias = &book::publication_name;
		break;
	default:
		break;
	}
}

void AlgorithmBook::set_alias_search_book(int searchby)
{
	//title number
	switch (searchby)
	{
	case 1:
		s_alias = &book::book_name;
		break;
	case 2:
		s_alias = &book::book_no;
		break;
		/*case 3:
			s_alias = &book::authorname;
			break;*/
	default:
		break;
	}
}

void AlgorithmBook::swap(book& t1, book& t2)
{
	book tmp = t1;
	t1 = t2;
	t2 = tmp;
}

float AlgorithmBook::list_book_bubblesort(book* T, int n, bool& order, bool& type, int sortby)
{

	set_alias_sort_book(sortby);
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (type ? (order ? (T[j].*i_alias < T[j + 1].*i_alias) : (T[j].*i_alias > T[j + 1].*i_alias)) : (order ? (_strcmpi(T[j].*s_alias, T[j + 1].*s_alias) < 0) : (_strcmpi(T[j].*s_alias, T[j + 1].*s_alias) > 0)))
				swap(T[j], T[j + 1]);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

float AlgorithmBook::list_book_selectionsort(book* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_book(sortby);
	auto start = chrono::high_resolution_clock::now();
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			//if (order? (T[j].price > T[min_idx].price) : (T[j].price < T[min_idx].price))
			if (type ? (order ? (T[j].*i_alias > T[min_idx].*i_alias) : (T[j].*i_alias < T[min_idx].*i_alias)) : (order ? (_strcmpi(T[j].*s_alias, T[min_idx].*s_alias) > 0) : (_strcmpi(T[j].*s_alias, T[min_idx].*s_alias) < 0)))
				min_idx = j;
		swap(T[min_idx], T[i]);
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

float AlgorithmBook::list_book_insertionsort(book* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_book(sortby);
	auto start = chrono::high_resolution_clock::now();
	int i, j;
	int i_key;
	char s_key[50];
	for (i = 1; i < n; i++)
	{
		//type ? (i_key = T[i].*i_alias) : (strcpy(s_key, T[i].*s_alias));
		if (type)
			i_key = T[i].*i_alias;
		else
			strncpy_s(s_key, T[i].*s_alias, _TRUNCATE);
		j = i - 1;
		//while (j >= 0 && (order?(T[j].*i_alias < i_key): (T[j].*i_alias > i_key)))
		while (j >= 0 && (type ? (order ? (T[j].*i_alias < i_key) : (T[j].*i_alias > i_key)) : (order ? (_strcmpi(T[j].*s_alias, s_key) < 0) : (_strcmpi(T[j].*s_alias, s_key) > 0))))
		{
			swap(T[j + 1], T[j]);
			j = j - 1;
		}
		if (type)
			T[j + 1].*i_alias = i_key;
		else
			strncpy_s(T[j + 1].*s_alias, s_key, _TRUNCATE);
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

float AlgorithmBook::list_book_mergesort(book* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_book(sortby);
	auto start = chrono::high_resolution_clock::now();
	mergeSort(T, 0, n - 1, order, type);
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

void AlgorithmBook::mergeSort(book* T, int l, int r, bool& order, bool& type)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(T, l, m, order, type);
		mergeSort(T, m + 1, r, order, type);
		merge(T, l, m, r, order, type);
	}
}

void AlgorithmBook::merge(book* T, int l, int m, int r, bool& order, bool& type)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	book* L = new book[n1];
	book* R = new book[n2];
	for (int i = 0; i < n1; i++)
	{
		T[l + i].copy_book(L[i]);
	}
	for (int j = 0; j < n2; j++)
	{
		T[m + 1 + j].copy_book(R[j]);
	}
	int i = 0;
	int j = 0;
	int k = l;
	while (i < n1 && j < n2)
	{
		//if (order?(L[i].price >= R[j].price):(L[i].price <= R[j].price))
		if (type ? (order ? (L[i].*i_alias >= R[j].*i_alias) : (L[i].*i_alias <= R[j].*i_alias)) : (order ? (_strcmpi(L[i].*s_alias, R[j].*s_alias) >= 0) : (_strcmpi(L[i].*s_alias, R[j].*s_alias) <= 0)))
		{
			swap(T[k], L[i]);
			i++;
		}
		else
		{
			swap(T[k], R[j]);
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		swap(T[k], L[i]);
		i++;
		k++;
	}
	while (j < n2)
	{
		swap(T[k], R[j]);
		j++;
		k++;
	}
	delete[]L;
	delete[]R;
}

float AlgorithmBook::list_book_heapsort(book* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_book(sortby);
	auto start = chrono::high_resolution_clock::now();
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(T, n, i, order, type);
	for (int i = n - 1; i > 0; i--)
	{
		swap(T[0], T[i]);
		heapify(T, i, 0, order, type);
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

void AlgorithmBook::heapify(book* T, int n, int i, bool& order, bool& type)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	//if (l < n && (order? (T[l].price < T[largest].price) :(T[l].price > T[largest].price)))
	if (l < n && (type ? (order ? (T[l].*i_alias < T[largest].*i_alias) : (T[l].*i_alias > T[largest].*i_alias)) : (order ? (_strcmpi(T[l].*s_alias, T[largest].*s_alias) < 0) : (_strcmpi(T[l].*s_alias, T[largest].*s_alias) > 0))))
		largest = l;
	//if (r < n && (order? (T[r].price < T[largest].price) :(T[r].price > T[largest].price)))
	if (r < n && (type ? (order ? (T[r].*i_alias < T[largest].*i_alias) : (T[r].*i_alias > T[largest].*i_alias)) : (order ? (_strcmpi(T[r].*s_alias, T[largest].*s_alias) < 0) : (_strcmpi(T[r].*s_alias, T[largest].*s_alias) > 0))))
		largest = r;
	if (largest != i)
	{
		swap(T[i], T[largest]);
		heapify(T, n, largest, order, type);
	}
}

float AlgorithmBook::list_book_quicksort(book* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_book(sortby);
	auto start = chrono::high_resolution_clock::now();
	quickSort(T, 0, n - 1, order, type);
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

void AlgorithmBook::quickSort(book* T, int low, int high, bool& order, bool& type)
{
	if (low < high)
	{
		int pi = partition(T, low, high, order, type);
		quickSort(T, low, pi - 1, order, type);
		quickSort(T, pi + 1, high, order, type);
	}
}

int AlgorithmBook::partition(book* T, int low, int high, bool& order, bool& type)
{
	int i_pivot;
	char s_pivot[50];
	if (type)
		i_pivot = T[high].*i_alias;
	else
		strncpy_s(s_pivot, T[high].*s_alias, _TRUNCATE);
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		//if (order ? (T[j].*i_alias > i_pivot) : (T[j].*i_alias < i_pivot))
		if (type ? (order ? (T[j].*i_alias > i_pivot) : (T[j].*i_alias < i_pivot)) : (order ? (_strcmpi(T[j].*s_alias, s_pivot) > 0) : (_strcmpi(T[j].*s_alias, s_pivot) < 0)))
		{
			i++;
			swap(T[i], T[j]);
		}
	}
	swap(T[i + 1], T[high]);
	return (i + 1);
}

float AlgorithmBook::list_book_bogosort(book* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_book(sortby);
	auto start = chrono::high_resolution_clock::now();
	while (!isSorted(T, n, order, type))
		shuffle(T, n);
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

bool AlgorithmBook::isSorted(book* T, int n, bool& order, bool& type)
{
	while (--n >= 1)
		//if (order ? (T[n].price > T[n - 1].price) : (T[n].price < T[n - 1].price))
		if (type ? (order ? (T[n].*i_alias > T[n - 1].*i_alias) : (T[n].*i_alias < T[n - 1].*i_alias)) : (order ? (_strcmpi(T[n].*s_alias, T[n - 1].*s_alias) > 0) : (_strcmpi(T[n].*s_alias, T[n - 1].*s_alias) < 0)))
			return false;
	return true;
}

void AlgorithmBook::shuffle(book* T, int n)
{
	for (int i = 0; i < n; i++)
		swap(T[i], T[rand() % n]);
}

int AlgorithmBook::linear_search_book(book* T, int n, char x[50], bool order, bool type, int searchby)
{
	//graphics gra;
	set_alias_search_book(searchby);
	int pos = 6;
	int f = 0;
	for (int i = 0;i < n;++i)
	{
		if (strncmp(T[i].*s_alias, x, strlen(x)) == 0) {
			T[i].display_book_bk(pos);
			//gra.miscbox();
			pos = pos + 11;
			f = 1;
		}
	}
	if (f == 0)
		return 1;//record not found
	return 0;//success
}

//Sorts data; calls binary search algorithm; searches for multiple occurrences; displays the result;
int AlgorithmBook::binary_search_book(book* T, int n, char x[50], bool order, bool type, int searchby)
{
	//searchby points to either :: BookName(1) OR Book#(2);
	set_alias_search_book(searchby);

	//Sorting book array T using Quick Sort;
	quickSort(T, 0, n - 1, order, type);				// Changes T to sorted array;

	//Binary Search to find single occurrence;
	int index = binary_search_algo(T, 0, n - 1, x);		//index > 0 if results found;
	if (index == -1)
		return 1;										//Not found;

	//checks left and right for multiple occurrences;
	int left = index - 1;
	int right = index + 1;
	while (left >= 0 && (strncmp(T[left].*s_alias, x, strlen(x)) == 0))
		--left;
	while (right < n && (strncmp(T[right].*s_alias, x, strlen(x)) == 0))
		++right;

	for (int i = left + 1;i < right;++i)				//display all occurrences;
	{
		T[i].blist();
	}
	return 0;											//success;
}

//Searches array for data; returns index if found; else returns -1;
int AlgorithmBook::binary_search_algo(book* T, int l, int r, char x[50])
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (strncmp(T[mid].*s_alias, x, strlen(x)) == 0)
			return mid;
		if (strncmp(T[mid].*s_alias, x, strlen(x)) > 0)
			return binary_search_algo(T, l, mid - 1, x);
		return binary_search_algo(T, mid + 1, r, x);
	}
	return -1;
}

//STUDENT
void AlgorithmStudent::set_alias_sort_student(int sortby)
{
	//name roll books #
	switch (sortby)
	{
	case 1:
		s_alias = &student::std_name;
		break;
	case 2:
		s_alias = &student::roll;
		break;
	case 3:
		i_alias = &student::token;
		break;
	default:
		break;
	}
}

void AlgorithmStudent::set_alias_search_student(int searchby)
{
	//name roll #
	switch (searchby)
	{
	case 1:
		s_alias = &student::std_name;
		break;
	case 2:
		s_alias = &student::roll;
		break;
		/*case 3:
			i_alias = &student::token;
			break;*/
	default:
		break;
	}
}

void AlgorithmStudent::swap(student& t1, student& t2)
{
	student tmp = t1;
	t1 = t2;
	t2 = tmp;
}

float AlgorithmStudent::list_student_bubblesort(student* T, int n, bool& order, bool& type, int sortby)
{

	set_alias_sort_student(sortby);
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (type ? (order ? (T[j].*i_alias < T[j + 1].*i_alias) : (T[j].*i_alias > T[j + 1].*i_alias)) : (order ? (_strcmpi(T[j].*s_alias, T[j + 1].*s_alias) < 0) : (_strcmpi(T[j].*s_alias, T[j + 1].*s_alias) > 0)))
				swap(T[j], T[j + 1]);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

float AlgorithmStudent::list_student_selectionsort(student* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_student(sortby);
	auto start = chrono::high_resolution_clock::now();
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			//if (order? (T[j].price > T[min_idx].price) : (T[j].price < T[min_idx].price))
			if (type ? (order ? (T[j].*i_alias > T[min_idx].*i_alias) : (T[j].*i_alias < T[min_idx].*i_alias)) : (order ? (_strcmpi(T[j].*s_alias, T[min_idx].*s_alias) > 0) : (_strcmpi(T[j].*s_alias, T[min_idx].*s_alias) < 0)))
				min_idx = j;
		swap(T[min_idx], T[i]);
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

float AlgorithmStudent::list_student_insertionsort(student* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_student(sortby);
	auto start = chrono::high_resolution_clock::now();
	int i, j;
	int i_key;
	char s_key[50];
	for (i = 1; i < n; i++)
	{
		//type ? (i_key = T[i].*i_alias) : (strcpy(s_key, T[i].*s_alias));
		if (type)
			i_key = T[i].*i_alias;
		else
			strncpy_s(s_key, T[i].*s_alias, _TRUNCATE);
		j = i - 1;
		//while (j >= 0 && (order?(T[j].*i_alias < i_key): (T[j].*i_alias > i_key)))
		while (j >= 0 && (type ? (order ? (T[j].*i_alias < i_key) : (T[j].*i_alias > i_key)) : (order ? (_strcmpi(T[j].*s_alias, s_key) < 0) : (_strcmpi(T[j].*s_alias, s_key) > 0))))
		{
			swap(T[j + 1], T[j]);
			j = j - 1;
		}
		if (type)
			T[j + 1].*i_alias = i_key;
		else
			strncpy_s(T[j + 1].*s_alias, s_key, _TRUNCATE);
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

float AlgorithmStudent::list_student_mergesort(student* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_student(sortby);
	auto start = chrono::high_resolution_clock::now();
	mergeSort(T, 0, n - 1, order, type);
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

void AlgorithmStudent::mergeSort(student* T, int l, int r, bool& order, bool& type)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(T, l, m, order, type);
		mergeSort(T, m + 1, r, order, type);
		merge(T, l, m, r, order, type);
	}
}

void AlgorithmStudent::merge(student* T, int l, int m, int r, bool& order, bool& type)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	student* L = new student[n1];
	student* R = new student[n2];
	for (int i = 0; i < n1; i++)
	{
		T[l + i].copy_student(L[i]);
	}
	for (int j = 0; j < n2; j++)
	{
		T[m + 1 + j].copy_student(R[j]);
	}
	int i = 0;
	int j = 0;
	int k = l;
	while (i < n1 && j < n2)
	{
		//if (order?(L[i].price >= R[j].price):(L[i].price <= R[j].price))
		if (type ? (order ? (L[i].*i_alias >= R[j].*i_alias) : (L[i].*i_alias <= R[j].*i_alias)) : (order ? (_strcmpi(L[i].*s_alias, R[j].*s_alias) >= 0) : (_strcmpi(L[i].*s_alias, R[j].*s_alias) <= 0)))
		{
			swap(T[k], L[i]);
			i++;
		}
		else
		{
			swap(T[k], R[j]);
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		swap(T[k], L[i]);
		i++;
		k++;
	}
	while (j < n2)
	{
		swap(T[k], R[j]);
		j++;
		k++;
	}
	delete[]L;
	delete[]R;
}

float AlgorithmStudent::list_student_heapsort(student* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_student(sortby);
	auto start = chrono::high_resolution_clock::now();
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(T, n, i, order, type);
	for (int i = n - 1; i > 0; i--)
	{
		swap(T[0], T[i]);
		heapify(T, i, 0, order, type);
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

void AlgorithmStudent::heapify(student* T, int n, int i, bool& order, bool& type)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	//if (l < n && (order? (T[l].price < T[largest].price) :(T[l].price > T[largest].price)))
	if (l < n && (type ? (order ? (T[l].*i_alias < T[largest].*i_alias) : (T[l].*i_alias > T[largest].*i_alias)) : (order ? (_strcmpi(T[l].*s_alias, T[largest].*s_alias) < 0) : (_strcmpi(T[l].*s_alias, T[largest].*s_alias) > 0))))
		largest = l;
	//if (r < n && (order? (T[r].price < T[largest].price) :(T[r].price > T[largest].price)))
	if (r < n && (type ? (order ? (T[r].*i_alias < T[largest].*i_alias) : (T[r].*i_alias > T[largest].*i_alias)) : (order ? (_strcmpi(T[r].*s_alias, T[largest].*s_alias) < 0) : (_strcmpi(T[r].*s_alias, T[largest].*s_alias) > 0))))
		largest = r;
	if (largest != i)
	{
		swap(T[i], T[largest]);
		heapify(T, n, largest, order, type);
	}
}

float AlgorithmStudent::list_student_quicksort(student* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_student(sortby);
	auto start = chrono::high_resolution_clock::now();
	quickSort(T, 0, n - 1, order, type);
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

void AlgorithmStudent::quickSort(student* T, int low, int high, bool& order, bool& type)
{
	if (low < high)
	{
		int pi = partition(T, low, high, order, type);
		quickSort(T, low, pi - 1, order, type);
		quickSort(T, pi + 1, high, order, type);
	}
}

int AlgorithmStudent::partition(student* T, int low, int high, bool& order, bool& type)
{
	int i_pivot;
	char s_pivot[50];
	if (type)
		i_pivot = T[high].*i_alias;
	else
		strncpy_s(s_pivot, T[high].*s_alias, _TRUNCATE);
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		//if (order ? (T[j].*i_alias > i_pivot) : (T[j].*i_alias < i_pivot))
		if (type ? (order ? (T[j].*i_alias > i_pivot) : (T[j].*i_alias < i_pivot)) : (order ? (_strcmpi(T[j].*s_alias, s_pivot) > 0) : (_strcmpi(T[j].*s_alias, s_pivot) < 0)))
		{
			i++;
			swap(T[i], T[j]);
		}
	}
	swap(T[i + 1], T[high]);
	return (i + 1);
}

float AlgorithmStudent::list_student_bogosort(student* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_student(sortby);
	auto start = chrono::high_resolution_clock::now();
	while (!isSorted(T, n, order, type))
		shuffle(T, n);
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

bool AlgorithmStudent::isSorted(student* T, int n, bool& order, bool& type)
{
	while (--n >= 1)
		//if (order ? (T[n].price > T[n - 1].price) : (T[n].price < T[n - 1].price))
		if (type ? (order ? (T[n].*i_alias > T[n - 1].*i_alias) : (T[n].*i_alias < T[n - 1].*i_alias)) : (order ? (_strcmpi(T[n].*s_alias, T[n - 1].*s_alias) > 0) : (_strcmpi(T[n].*s_alias, T[n - 1].*s_alias) < 0)))
			return false;
	return true;
}

void AlgorithmStudent::shuffle(student* T, int n)
{
	for (int i = 0; i < n; i++)
		swap(T[i], T[rand() % n]);
}


int AlgorithmStudent::linear_search_student(student* T, int n, char x[50], bool order, bool type, int searchby)
{
	//graphics gra;
	set_alias_search_student(searchby);
	int pos = 6;
	int f = 0;
	for (int i = 0;i < n;++i)
	{
		if (strncmp(T[i].*s_alias, x, strlen(x)) == 0) {
			T[i].display_student_sts(pos);
			//gra.miscbox();
			pos = pos + 6;
			f = 1;
		}
	}
	if (f == 0)
		return 1;//record not found
	return 0;//success
}

//Sorts data; calls binary search algorithm; searches for multiple occurrences; displays the result;
int AlgorithmStudent::binary_search_student(student* T, int n, char x[50], bool order, bool type, int searchby)
{
	//searchby points to either :: StudentName(1) OR Roll#(2);
	set_alias_search_student(searchby);

	//Sorting student array T using Quick Sort;
	quickSort(T, 0, n - 1, order, type);				// Changes T to sorted array;
	
	//Binary Search to find single occurrence;
	int index = binary_search_algo(T, 0, n - 1, x);		//index > 0 if results found;
	if (index == -1) 
		return 1;										//Not found;
	
	//checks left and right for multiple occurrences;
	int left = index - 1;
	int right = index + 1;
	while (left >= 0 && (strncmp(T[left].*s_alias, x, strlen(x)) == 0))
		--left;
	while (right < n && (strncmp(T[right].*s_alias, x, strlen(x)) == 0))
		++right;

	int pos = 6;										//For display formatting;
	for (int i = left+1;i < right;++i)					//display all occurrences;
	{
			T[i].display_student_sts(pos);
			pos = pos + 6;
	}
	return 0;											//success;
}

//Searches array for data; returns index if found; else returns -1;
int AlgorithmStudent::binary_search_algo(student* T, int l, int r, char x[50])
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (strncmp(T[mid].*s_alias, x, strlen(x)) == 0)
			return mid;
		if (strncmp(T[mid].*s_alias, x, strlen(x)) > 0)
			return binary_search_algo(T, l, mid - 1, x);
		return binary_search_algo(T, mid + 1, r, x);
	}
	return -1;
}

void Sortmenu::sort_book_menu()
{
	system("CLS");
	gra.stdbox();
	to.setxy(47, 5);
	cout << "Sort By:";
	to.setxy(47, 6);
	cout << "1.Price";
	to.setxy(47, 7);
	cout << "2.Book Name";
	to.setxy(47, 8);
	cout << "3.Author Name";
	to.setxy(47, 9);
	cout << "4.Quantity";
	to.setxy(47, 10);
	cout << "5.Publisher";
	to.setxy(47, 19);
	cout << "Choose option" << endl;
	to.setxy(47, 20);
	cin >> sortby;

	system("CLS");
	gra.passwordbox();
	to.setxy(47, 8);
	cout << "0.Ascending Order";
	to.setxy(47, 9);
	cout << "1.Decending Order";
	to.setxy(47, 10);
	cin >> order;

	system("CLS");
	gra.stdbox();
	to.setxy(47, 5);
	cout << "Select The type of sort";
	to.setxy(47, 6);
	cout << "1.Bubble Sort";
	to.setxy(47, 7);
	cout << "2.Selection Sort";
	to.setxy(47, 8);
	cout << "3.Insertion Sort";
	to.setxy(47, 9);
	cout << "4.Merge Sort";
	to.setxy(47, 10);
	cout << "5.Heap Sort";
	to.setxy(47, 11);
	cout << "6.Quick sort";
	to.setxy(47, 12);
	cout << "7.Bogo Sort";
	to.setxy(47, 19);
	cout << "Choose option" << endl;
	to.setxy(47, 20);
	cin >> sorting_algo;
}

void Sortmenu::sort_student_menu()
{
	system("CLS");
	gra.stdbox();
	to.setxy(47, 5);
	cout << "Sort By:";
	to.setxy(47, 6);
	cout << "1.Name";
	to.setxy(47, 7);
	cout << "2.Roll no.";
	to.setxy(47, 8);
	cout << "3.Books Issued number";
	to.setxy(47, 20);
	cin >> sortby;

	system("CLS");
	gra.passwordbox();
	to.setxy(47, 8);
	cout << "0.Ascending Order";
	to.setxy(47, 9);
	cout << "1.Decending Order";
	to.setxy(47, 10);
	cin >> order;

	system("CLS");
	gra.stdbox();
	to.setxy(47, 5);
	cout << "Select The type of sort";
	to.setxy(47, 6);
	cout << "1.Bubble Sort";
	to.setxy(47, 7);
	cout << "2.Selection Sort";
	to.setxy(47, 8);
	cout << "3.Insertion Sort";
	to.setxy(47, 9);
	cout << "4.Merge Sort";
	to.setxy(47, 10);
	cout << "5.Heap Sort";
	to.setxy(47, 11);
	cout << "6.Quick sort";
	to.setxy(47, 12);
	cout << "7.Bogo Sort";
	to.setxy(47, 19);
	cout << "Choose option" << endl;
	to.setxy(47, 20);
	cin >> sorting_algo;
}

void Searchmenu::search_book_menu()
{
	system("CLS");
	gra.stdbox();
	to.setxy(47, 5);
	cout << "Select algorithm:";
	to.setxy(47, 6);
	cout << "1.Linear Search";
	to.setxy(47, 7);
	cout << "2.Binary Search";
	to.setxy(47, 19);
	cout << "Choose option" << endl;
	to.setxy(47, 20);
	cin >> searching_algo;
	
	system("cls");
	to.setxy(47, 6);
	std::cout << "Search by::" << std::endl;
	to.setxy(47, 7);
	std::cout << "1.Title" << std::endl;
	to.setxy(47, 8);
	std::cout << "2.Book no." << std::endl;
	gra.stdbox();
	to.setxy(47, 20);
	cin >> searchby;
	
	system("cls");
	gra.stdbox();
	to.setxy(47, 6);
	cout << "BOOK INFORMATION" << endl;
}

void Searchmenu::search_student_menu()
{
	system("CLS");
	gra.stdbox();
	to.setxy(47, 5);
	cout << "Select algorithm:";
	to.setxy(47, 6);
	cout << "1.Linear Search";
	to.setxy(47, 7);
	cout << "2.Binary Search";
	to.setxy(47, 19);
	cout << "Choose option" << endl;
	to.setxy(47, 20);
	cin >> searching_algo;

	system("cls");
	gra.stdbox();
	to.setxy(47, 8);
	std::cout << "Search by::" << std::endl;
	to.setxy(47, 9);
	std::cout << "1.Name" << std::endl;
	to.setxy(47, 10);
	std::cout << "2.Roll" << std::endl;
	to.setxy(47, 20);
	cin >> searchby;

	system("cls");
	gra.stdbox();
	to.setxy(47, 6);
	cout << "STUDENT INFORMATION" << endl;
}
