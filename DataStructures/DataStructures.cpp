// DataStructures.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyArray.h"

int main()
{
	int a = 0;
	int b = 1;
	MyArray<int> tmp = MyArray<int>(1);
	tmp.Add(a);
	tmp.Add(b);
	printf("%d", tmp[1]);
	tmp.RemoveAt(0);
	printf("%d", tmp[0]);
    return 0;
}

