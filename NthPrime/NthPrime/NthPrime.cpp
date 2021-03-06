﻿#include "stdafx.h"
#include <iostream>
#include <vector>
#include<fstream>
#include <time.h>
#define MAXSIZE 200000000
int isNotPrime[MAXSIZE];
int prime[MAXSIZE];
using namespace std;
/*
const long N = 2000;
long prime[N] = { 0 }, num_prime = 0;
int isNotPrime[N] = { 1, 1 };
*/
int main()
{
	ofstream fout;
	fout.open("result.txt", ios::out);
	cout << "please enter n:" << endl;
	int n;
	cin >> n;

	int upper = 1000;
	if (n > 100)
	{
		upper = 1.3 * n*log(n);
	}

	int num_prime = 0;

	//	memset(isNotPrime, 0, sizeof(int)*upper);
	//memset(prime, 0, sizeof(int)*n);
	isNotPrime[0] = 1;
	isNotPrime[1] = 1;
	long beginTime = clock();//获得开始时间，单位为毫秒  
	for (int i = 2; i < upper; i++)
	{
		if (!isNotPrime[i])
		{
			prime[num_prime++] = i;
		}
		for (int j = 0; j < num_prime && i * prime[j] < upper; j++)
		{
			try
			{
				isNotPrime[i * prime[j]] = 1;
				if (!(i % prime[j]))
					break;
			}
			catch(exception e)
			{
				// Code to execute after the try block goes here.
			}
		}
	}
	int index = 0;
	int nprime[100];
	while (prime[n - 1])
	{
		nprime[index] = prime[n - 1] % 10;
		index++;
		prime[n - 1] = prime[n - 1] / 10;
	}
	fout << "the" << n << "th prime: ";
	index--;
	for (index; index >= 0; index--)
	{
		if (index % 3 == 2)
		{
			fout << ' ';
		}
		fout << nprime[index];
	}
	fout << endl;
	//	cout << prime[1000000];
	long endTime = clock();//获得结束时间
	fout << "beginTime:" << beginTime << endl
		<< "endTime:" << endTime << endl
		<< "endTime-beginTime:" << endTime - beginTime << "ms" << endl;
	return 0;
}