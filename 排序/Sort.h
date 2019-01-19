#include <stdio.h>

void PrintArray(int *array, int size)
{
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

//直接插入排序
//i代表被抓起的牌的下标[1,size)
//j和array[i]比较的牌的下标[i-1, 0]
//时间复杂度
//最坏	O(n^2)    已经逆序
//平均	O(n^2)
//最好	O(n)      已经有序
//空间复杂度 O(1)
//稳定
void InsertSort(int array[], int size)
{
	for (int i = 0; i < size; i++){
		int k = array[i];
		int j;
		for (j = i - 1; j >= 0; j--){
			if (array[j] <= k){
				break;
			}

			array[j + 1] = array[j];
		}

		array[j + 1] = k;
	}
}

//利用二分查找写插排

//希尔排序
//时间复杂度
//最坏	O(n^2)     需要刻意构造
//平均	O(n^2)
//最好	O(n)       已经有序
//空间复杂度	O(1)
//不稳定
void InsertSortWithGap(int *array, int size, int gap)
{
	for (int i = gap; i < size; i++){
		int k = array[i];
		int j;
		for (j = i - gap; j >= 0; j -= gap){
			if (array[j] <= k){
				break;
			}

			array[j + gap] = array[j];
		}
		array[j + gap] = k;
	}
}

void ShellSort(int *array, int size)
{
	int gap = size;
	while (1){
		gap = (gap / 3) + 1;
		InsertSortWithGap(array, size, gap);
		if (gap == 1){
			break;
		}
	}
}

//希尔排序逆序
void InsertSortWithGapR(int *array, int size, int gap)
{
	for (int i = gap; i < size; i++){
		int k = array[i];
		int j;
		for (j = i - gap; j >= 0; j -= gap){
			if (array[j] >= k){
				break;
			}
			array[j + gap] = array[j];
		}
		array[j + gap] = k;
	}
}

void ShellSortR(int *array, int size)
{
	int gap = size;
	while (1){
		gap = (gap / 3) + 1;
		InsertSortWithGapR(array, size, gap);
		if (gap == 1){
			break;
		}
	}
}

//利用gap = 1写插排
void InsertSort2(int *array, int size)
{
	InsertSortWithGap(array, size, 1);
}

//冒泡排序
//时间复杂度
//最坏	O(n^2)    已经逆序
//平均	O(n^2)
//最好	O(n)
//空间复杂度O(1)
//稳定
void BubbleSort(int *array, int size)
{
	for (int i = 1; i < size; i++){
		int count = 0;
		for (int j = 0; j < size - i; j++){
			if (array[j] > array[j + 1]){
				int tmp = array[j];
				array[j + 1] = array[j];
				array[j] = tmp;
				count++;
			}
		}
		if (count == 0){
			break;
		}
	}
}

//选择排序，找最大的
//时间复杂度O(n^2)
//空间复杂度O(1)
//不稳定
//数据不敏感（无论原来的数据是什么顺序，不影响执行时间）
void SelsctSort(int *array, int size)
{
	for (int i = 1; i < size; i++){
		int max = 0;    //假设一开始下标0是最大的
		for (int j = 1; j <= size - i; j++){
			if (array[j] >= array[max]){
				max = j;
			}
		}
		//最大的数存在max下标下
		int tmp = array[size - i];
		array[size - i] = array[max];
		array[max] = tmp;
	}
}

//升级版直接选择排序，一次即找最大的，也找最小的
void SelectSortOP(int *array, int size)
{
	int minSpace = 0;        //用来存放找到的最小数的下标
	int maxSpace = size - 1; //用来存放找到的最大数的下标

	//因为是闭区间，minSpace == maxSpace时
	//[minSpace, maxSpace]区间内只剩一个数了
	//所以可以停止了
	while (minSpace < maxSpace){
		int min = minSpace; //假设最小的是minSpace位置
		int max = minSpace; //假设最大的是minSpace位置
		//在[minSpace+1， maxSpace]区间里找真正的最小和最大

		for (int j = minSpace + 1; j <= maxSpace; j++){
			if (array[j] < array[min]){
				min = j;
			}

			if (array[j] > array[max]){
				max = j;
			}
		}

		//min和max分别时最小和最大的数的下标
		//先交换小的
		{
			int tmp = array[min];
			array[min] = array[minSpace];
			array[minSpace] = tmp;
		}
		//再交换大的
		if (max == minSpace){
			max = min;
		}
		{
			int tmp = array[max];
			array[max] = array[maxSpace];
			array[maxSpace] = tmp;
		}

		minSpace++;
		maxSpace--;
	}
}

//root表示要开始调整的结点下标
//建大堆
void AdjustDown(int *array, int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	while (left < size){
		//找两个孩子中大的一个
		//只有一种情况，大的一个是右孩子
		//有右孩子并且右孩子的值大于左孩子的值
		int max = left;
		if (right < size && array[right]>array[left]){
			max = right;
		}

		if (array[root] >= array[max]){
			break;
		}

		int tmp = array[root];
		array[root] = array[max];
		array[max] = tmp;

		root = max;
		left = 2 * root + 1;
		right = 2 * root + 2;
	}
}

//建堆
void CreateHeap(int *array, int size)
{
	//从最后一个非叶子结点开始向下调整
	for (int i = (size - 2) / 2; i >= 0; i--){
		AdjustDown(array, size, i);
	}
}

//堆排序
//时间复杂度O(n*logn)
//空间复杂度O(1)
//不稳定
//数据不敏感
void HeapSort(int *array, int size)
{
	//建大堆
	CreateHeap(array, size);

	//选择
	for (int i = 1; i < size; i++){
		int tmp = array[0];
		array[0] = array[size - i];
		array[size - i] = tmp;

		AdjustDown(array, size - i, 0);
	}
}

//测试
void TestRight()
{
	int array[] = { 1, 5, 8, 7, 6, 2, 3, 4, 5, 8, 4, 11, 2, 5, 4, 5, 66, 2 };
	int size = sizeof(array) / sizeof(int);

	HeapSort(array, size);

	PrintArray(array, size);
}

#if 0
//测试速度

#define SIZE (5 * 10000)
void TestSpeed()
{
	int array[SIZE];
	int size = SIZE;

	srand(20190119);
	for (int i = 0; i < size; i++){
		array[i] = rand() % size;
	}

	高精度计时 计时器;
	计时器.开始();
	计时器.结束();

	printf("耗时：%f毫秒\n", 计时器.间隔毫秒());
}
#endif