#include <stdio.h>

void PrintArray(int *array, int size)
{
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

//ֱ�Ӳ�������
//i����ץ����Ƶ��±�[1,size)
//j��array[i]�Ƚϵ��Ƶ��±�[i-1, 0]
//ʱ�临�Ӷ�
//�	O(n^2)    �Ѿ�����
//ƽ��	O(n^2)
//���	O(n)      �Ѿ�����
//�ռ临�Ӷ� O(1)
//�ȶ�
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

//���ö��ֲ���д����

//ϣ������
//ʱ�临�Ӷ�
//�	O(n^2)     ��Ҫ���⹹��
//ƽ��	O(n^2)
//���	O(n)       �Ѿ�����
//�ռ临�Ӷ�	O(1)
//���ȶ�
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

//ϣ����������
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

//����gap = 1д����
void InsertSort2(int *array, int size)
{
	InsertSortWithGap(array, size, 1);
}

//ð������
//ʱ�临�Ӷ�
//�	O(n^2)    �Ѿ�����
//ƽ��	O(n^2)
//���	O(n)
//�ռ临�Ӷ�O(1)
//�ȶ�
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

//ѡ������������
//ʱ�临�Ӷ�O(n^2)
//�ռ临�Ӷ�O(1)
//���ȶ�
//���ݲ����У�����ԭ����������ʲô˳�򣬲�Ӱ��ִ��ʱ�䣩
void SelsctSort(int *array, int size)
{
	for (int i = 1; i < size; i++){
		int max = 0;    //����һ��ʼ�±�0������
		for (int j = 1; j <= size - i; j++){
			if (array[j] >= array[max]){
				max = j;
			}
		}
		//����������max�±���
		int tmp = array[size - i];
		array[size - i] = array[max];
		array[max] = tmp;
	}
}

//������ֱ��ѡ������һ�μ������ģ�Ҳ����С��
void SelectSortOP(int *array, int size)
{
	int minSpace = 0;        //��������ҵ�����С�����±�
	int maxSpace = size - 1; //��������ҵ�����������±�

	//��Ϊ�Ǳ����䣬minSpace == maxSpaceʱ
	//[minSpace, maxSpace]������ֻʣһ������
	//���Կ���ֹͣ��
	while (minSpace < maxSpace){
		int min = minSpace; //������С����minSpaceλ��
		int max = minSpace; //����������minSpaceλ��
		//��[minSpace+1�� maxSpace]����������������С�����

		for (int j = minSpace + 1; j <= maxSpace; j++){
			if (array[j] < array[min]){
				min = j;
			}

			if (array[j] > array[max]){
				max = j;
			}
		}

		//min��max�ֱ�ʱ��С�����������±�
		//�Ƚ���С��
		{
			int tmp = array[min];
			array[min] = array[minSpace];
			array[minSpace] = tmp;
		}
		//�ٽ������
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

//root��ʾҪ��ʼ�����Ľ���±�
//�����
void AdjustDown(int *array, int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	while (left < size){
		//�����������д��һ��
		//ֻ��һ����������һ�����Һ���
		//���Һ��Ӳ����Һ��ӵ�ֵ�������ӵ�ֵ
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

//����
void CreateHeap(int *array, int size)
{
	//�����һ����Ҷ�ӽ�㿪ʼ���µ���
	for (int i = (size - 2) / 2; i >= 0; i--){
		AdjustDown(array, size, i);
	}
}

//������
//ʱ�临�Ӷ�O(n*logn)
//�ռ临�Ӷ�O(1)
//���ȶ�
//���ݲ�����
void HeapSort(int *array, int size)
{
	//�����
	CreateHeap(array, size);

	//ѡ��
	for (int i = 1; i < size; i++){
		int tmp = array[0];
		array[0] = array[size - i];
		array[size - i] = tmp;

		AdjustDown(array, size - i, 0);
	}
}

//����
void TestRight()
{
	int array[] = { 1, 5, 8, 7, 6, 2, 3, 4, 5, 8, 4, 11, 2, 5, 4, 5, 66, 2 };
	int size = sizeof(array) / sizeof(int);

	HeapSort(array, size);

	PrintArray(array, size);
}

#if 0
//�����ٶ�

#define SIZE (5 * 10000)
void TestSpeed()
{
	int array[SIZE];
	int size = SIZE;

	srand(20190119);
	for (int i = 0; i < size; i++){
		array[i] = rand() % size;
	}

	�߾��ȼ�ʱ ��ʱ��;
	��ʱ��.��ʼ();
	��ʱ��.����();

	printf("��ʱ��%f����\n", ��ʱ��.�������());
}
#endif