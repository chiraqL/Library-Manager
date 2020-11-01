#pragma once
#include <chrono> 
#include "Headers.h"
#include"algorithm.h"

void algorithm::set_alias_sort_book(int sortby)
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

void algorithm::swap(book& t1, book& t2)
{
	book tmp = t1;
	t1 = t2;
	t2 = tmp;
}

float algorithm::list_book_bubblesort(book* T, int n, bool& order, bool& type, int sortby)
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

float algorithm::list_book_selectionsort(book* T, int n, bool& order, bool& type, int sortby)
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

float algorithm::list_book_insertionsort(book* T, int n, bool& order, bool& type, int sortby)
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

float algorithm::list_book_mergesort(book* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_book(sortby);
	auto start = chrono::high_resolution_clock::now();
	mergeSort(T, 0, n - 1, order, type);
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

void algorithm::mergeSort(book* T, int l, int r, bool& order, bool& type)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(T, l, m, order, type);
		mergeSort(T, m + 1, r, order, type);
		merge(T, l, m, r, order, type);
	}
}

void algorithm::merge(book* T, int l, int m, int r, bool& order, bool& type)
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

float algorithm::list_book_heapsort(book* T, int n, bool& order, bool& type, int sortby)
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

void algorithm::heapify(book* T, int n, int i, bool& order, bool& type)
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

float algorithm::list_book_quicksort(book* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_book(sortby);
	auto start = chrono::high_resolution_clock::now();
	quickSort(T, 0, n - 1, order, type);
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

void algorithm::quickSort(book* T, int low, int high, bool& order, bool& type)
{
	if (low < high)
	{
		int pi = partition(T, low, high, order, type);
		quickSort(T, low, pi - 1, order, type);
		quickSort(T, pi + 1, high, order, type);
	}
}

int algorithm::partition(book* T, int low, int high, bool& order, bool& type)
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
		if(type?(order ? (T[j].*i_alias > i_pivot) : (T[j].*i_alias < i_pivot)):(order ? (_strcmpi(T[j].*s_alias,s_pivot)>0) : (_strcmpi(T[j].*s_alias, s_pivot) < 0)))
		{
			i++;
			swap(T[i], T[j]);
		}
	}
	swap(T[i + 1], T[high]);
	return (i + 1);
}

float algorithm::list_book_bogosort(book* T, int n, bool& order, bool& type, int sortby)
{
	set_alias_sort_book(sortby);
	auto start = chrono::high_resolution_clock::now();
	while (!isSorted(T, n, order,type))
		shuffle(T, n);
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

bool algorithm::isSorted(book* T, int n, bool& order,bool& type)
{
	while (--n >= 1)
		//if (order ? (T[n].price > T[n - 1].price) : (T[n].price < T[n - 1].price))
		if(type?(order ? (T[n].*i_alias > T[n - 1].*i_alias) : (T[n].*i_alias < T[n - 1].*i_alias)):(order ? (_strcmpi(T[n].*s_alias,T[n - 1].*s_alias)>0) : (_strcmpi(T[n].*s_alias, T[n - 1].*s_alias) < 0)))
			return false;
	return true;
}

void algorithm::shuffle(book* T, int n)
{
	for (int i = 0; i < n; i++)
		swap(T[i], T[rand() % n]);
}




int algorithm::binary_search_book(book* T, int l, int r, char  x[20])
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (strcmp(T[mid].returnbook_name(), x) == 0)
			return mid;


		if (strcmp(T[mid].returnbook_name(), x) < 0)
			return binary_search_book(T, l, mid - 1, x);


		return binary_search_book(T, mid + 1, r, x);
	}
	return 0;
}