#pragma once
#include <chrono> 
#include"allheader.h"
#include"algorithm.h"

void algorithm::swap(book& t1, book& t2)
{
	book tmp = t1;
	t1 = t2;
	t2 = tmp;
}

float algorithm::list_book_asc_bubblesort(book* T, int n,bool& order)
{
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (order?(T[j].price < T[j + 1].price): (T[j].price > T[j + 1].price))
				swap(T[j], T[j + 1]);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

float algorithm::list_book_asc_selectionsort(book* T, int n, bool& order)
{
	auto start = chrono::high_resolution_clock::now();
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (order? (T[j].price > T[min_idx].price) : (T[j].price < T[min_idx].price))
				min_idx = j;
		swap(T[min_idx], T[i]);
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

float algorithm::list_book_asc_insertionsort(book* T, int n, bool& order)
{
	auto start = chrono::high_resolution_clock::now();
	//potential error declaring key as int; do float
	int i, j;
	float key;
	for (i = 1; i < n; i++)
	{
		key = T[i].price;
		j = i - 1;
		while (j >= 0 && (order?(T[j].price < key): (T[j].price > key)))
		{
			swap(T[j + 1], T[j]);
			j = j - 1;
		}
		T[j + 1].price = key;
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

float algorithm::list_book_asc_mergesort(book* T, int n, bool& order)
{
	auto start = chrono::high_resolution_clock::now();
	mergeSort(T, 0, n - 1,order);
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

void algorithm::mergeSort(book* T, int l, int r, bool& order)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(T, l, m, order);
		mergeSort(T, m + 1, r, order);
		merge(T, l, m, r, order);
	}
}

void algorithm::merge(book* T, int l, int m, int r,bool& order)
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
		if (order?(L[i].price >= R[j].price):(L[i].price <= R[j].price))
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

float algorithm::list_book_asc_heapsort(book* T, int n, bool& order)
{
	auto start = chrono::high_resolution_clock::now();
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(T, n, i,order);
	for (int i = n - 1; i > 0; i--)
	{
		swap(T[0], T[i]);
		heapify(T, i, 0,order);
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

void algorithm::heapify(book* T, int n, int i,bool& order)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && (order? (T[l].price < T[largest].price) :(T[l].price > T[largest].price)))
		largest = l;
	if (r < n && (order? (T[r].price < T[largest].price) :(T[r].price > T[largest].price)))
		largest = r;
	if (largest != i)
	{
		swap(T[i], T[largest]);
		heapify(T, n, largest,order);
	}
}

float algorithm::list_book_asc_quicksort(book* T, int n,bool& order)
{
	auto start = chrono::high_resolution_clock::now();
	quickSort(T, 0, n - 1,order);
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

void algorithm::quickSort(book* T, int low, int high,bool& order)
{
	if (low < high)
	{
		int pi = partition(T, low, high,order);  
		quickSort(T, low, pi - 1,order);
		quickSort(T, pi + 1, high,order);
	}
}

int algorithm::partition(book* T, int low, int high,bool& order)
{
	int pivot = T[high].price; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (order? (T[j].price > pivot) :(T[j].price < pivot))
		{
			i++; 
			swap(T[i], T[j]);
		}
	}
	swap(T[i + 1], T[high]);
	return (i + 1);
}

float algorithm::list_book_asc_bogosort(book* T, int n, bool& order)
{
	auto start = chrono::high_resolution_clock::now();
	while (!isSorted(T, n, order))
		shuffle(T, n);
	auto end = chrono::high_resolution_clock::now();	
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

bool algorithm::isSorted(book* T, int n, bool& order)
{
	while (--n >= 1)
		if (order? (T[n].price > T[n - 1].price):(T[n].price < T[n - 1].price))
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
	return -1;
}