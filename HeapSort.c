#include "HeapSort.h"
#include <stdio.h>
#include <string.h>

void Swap(HPDatatype* pLeft, HPDatatype* pRight) {
	HPDatatype tmp = *pLeft;
	*pLeft = *pRight;
	*pRight = tmp;
}

void HeapAdjust(int* array, int size, int parent) {
	int child = parent * 2 + 1;
	while (child < size) {
		if (child + 1 < size&&array[child + 1] > array[child])
			child += 1;
		if (array[parent] < array[child]) {
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void HeapSort(int* array, int size) {
	//大堆--->升序
	//小堆--->降序
	int root = ((size - 2) >> 1);//找倒数第一个非叶节点
	for (; root >= 0; --root)
		HeapAdjust(array, size, root);
	//排序，采用堆删除的思想
	int end = size - 1;
	while (end) {
		Swap(&array[end], &array[0]);
		HeapAdjust(array, end, 0);
		end--;
	}
}

int main() {
	int array[] = { 2,6,7,3,9,1,4,0,5,8 };
	HeapSort(array, sizeof(array)/sizeof(array[0]));

}