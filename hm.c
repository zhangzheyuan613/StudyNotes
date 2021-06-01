#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include<assert.h>
#include<malloc.h>
#pragma warning(disable:4996)

////�ϲ�������������
//void MergeData(int array[], int left, int mid, int right, int temp[])
//{
//	int begin1 = left, end1 = mid;
//	int begin2 = mid , end2 = right;
//	int index = left;
//	while (begin1 < end1 && begin2 < end2)
//	{
//		if (array[begin1] <= array[begin2])
//		{
//			temp[index++] = array[begin1++];
//		}
//		else
//		{
//			temp[index++] = array[begin2++];
//		}
//	}
//	while (begin1<end1)
//	{
//		temp[index++] = array[begin1++];
//	}
//	while (begin2 < end2)
//	{
//		temp[index++] = array[begin2++];
//	}
//}
////�鲢����
//void MergeSort(int array[], int left, int right, int temp[])
//{
//	if (right - left <= 1)
//	{
//		return;
//	}
//	int mid = left + ((right - left) / 2);
//	
//	MergeSort(array, left, mid, temp);
//
//	MergeSort(array,mid , right, temp);
//
//	MergeData(array, left, mid, right, temp);   
//	memcpy(array + left, temp+left, sizeof(array[0])*(right - left));
//}
//void _MergeSort(int array[], int size)
//{
//	int* temp = (int*)malloc(array[0] * size);
//	if (NULL == temp)
//	{
//		return;
//	}
//	MergeSort(array, 0, size, temp);
//	free(temp);
//}

////��һ�֣�hoare��
//int Partion1(int array[], int left, int right)
//{
//	int begin = left;
//	int end = right - 1;
//	int key = array[end];//��׼ֵ�����һ��Ԫ��
//	while (begin < end)
//	{
//		while (begin<end&&array[begin] <= key) //��֤��Ч����
//		{
//			begin++;
//		}
//		while (begin < end&&array[end] >= key)   
//		{
//			end--;	
//		}
//		if (begin < end)
//		{
//			swap(&array[begin], &array[end]);
//		}
//	}
//	if (begin!=right-1)
//	{
//		swap(&array[begin], &array[right - 1]);//����׼ֵ���������м�
//	}
//	return begin;//���ػ�׼ֵλ��
//}
////�ڶ��֣��ڿӷ�	
//int Partion2(int array[], int left, int right)
//{
//	int begin = left;
//	int end = right - 1;
//	int key = array[end];
//	while (begin < end)
//	{
//		//begin��ǰ�����ң��ұȻ�׼ֵ���Ԫ�� 
//		while (begin < end&&array[begin] <= key)
//		{
//			begin++;
//		}
//		if (begin < end)
//		{
//			array[end] = array[begin];
//			end--;
//		}
//
//		while (begin < end&&array[end] >= key)
//		{
//			end--;
//		}
//		if (begin < end)
//		{
//			array[begin] = array[end];
//			begin++;
//		}
//	}
//	array[begin] = key;
//	return begin;
//}
////������
//int Partion3(int array[], int left, int right)
//{
//	int cur = left;
//	int prev = cur-1;
//	int key = array[right - 1];
//	while (cur < right) 
//	{
//		if (array[cur] < key&&++prev != cur)
//		{
//			swap(&array[cur], &array[prev]);
//		}
//		cur++;
//	}
//	if (++prev != right - 1)
//	{
//		swap(&array[prev], &array[right-1]);
//	}
//	return prev;
//}
//
//void QuickSort(int array[], int left, int right)
//{
//	int div = 0;
//	if (right - left <= 1)
//	{
//		return;
//	}
//	//�һ�׼ֵ�������е����ݽ��л��֣�div�������ֺõȺ��׼ֵλ��
//	div = Partion3(array, left, right);
//	//�ݹ�
//	QuickSort(array, left, div);
//	QuickSort(array, div+1, right);
//}
//int main()
//{
//	int array[] = { 8,9,6,4,3,7,5,2,1 };
//	QuickSort(array,0,9);
//	for (int i = 0; i < 9; i++)
//	{
//		printf("%d", array[i]);
//	}
//	return 0;
//}


////��������
//void CountSort(int array[], int size)
//{
//	//1.�����ݷ�Χ
//	int max = array[0];
//	int min = array[0];
//	int index = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (array[i] > max)
//		{
//			max = array[i];
//		}
//		if (array[i] < min)
//		{
//			min = array[i];
//		}
//	}
//	//2.����ռ�
//	int* count = (int*)calloc(max - min + 1, sizeof(int));
//	if (NULL == count)
//	{
//		return NULL; 
//	}
//	//3.ͳ��ÿ��Ԫ�س��ִ���
//	for (int i = 0; i < size; i++)
//	{
//		count[array[i] - min]++;
//	}
//	//4.array��������
//	for (int i=0;i<max-min+1;i++)
//	{
//		while (count[i]--)
//		{
//			array[index++] = i + min;
//		}
//	}
//	free(count);
//}

////ð������
//void BubbleSort(int array[], int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		int flag=0;
//		//��������Ԫ�رȽϣ�������ͽ���
//		for (int j = 0; j < size - i-1; j++)
//		{
//			if (array[j]>array[j+1])
//			{
//				flag=1;
//				swap(&array[j] ,&array[j+1]);
//			}	
//		}
//		if(!flag)
//		{
//			return;
//		}
//	}
//}

////������
//void swap(int arr1[], int arr2[])
//{
//	int temp = 0;
//	temp = *arr1;
//	*arr1 = *arr2;
//	*arr2 = temp;
//}
//void HeapAdjust(int array[], int size, int parent)//���µ���
//{
//	//�ȱ�����ӣ�parent��������û����
//	int child = parent * 2 + 1;
//	while (child<size)
//	{
//		//�ҵ����Һ����нϴ�ģ���child���
//		if (child+1 < size && array[child] < array[child + 1])
//		{
//			child += 1;
//		}
//		//���˫�׽��С�ڽϴ���ӽ�㣬�򽻻�
//		if (array[parent] < array[child])
//		{
//			swap(&array[parent], &array[child]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			return;
//		}
//	}
//
//}
//void HeapSort(int array[], int size)
//{
//	int end = size - 1;
//	//���ѣ� ����-->���    ����-->С��
//	//�ӵ�����һ����Ҷ�ӽ�㵽�����һֱ���µ���
//	for (int root = (end - 1) / 2; root >= 0; root--)
//	{
//		HeapAdjust(array, size, root);
//	}
//	//����
//	while(end)
//	{
//		swap(&array[0], &array[end]);
//		HeapAdjust(array, end , 0);
//		end--;
//	}
//}

//

////ѡ������
//void swap(int arr1[], int arr2[])
//{
//	int temp = 0;
//	temp = *arr1;
//	*arr1 = *arr2;
//	*arr2 = temp;
//}
//
//void SelectSort(int array[], int size)
//{
//	for(int i=0;i<size-1;i++)//���ʣһ�����Ͳ������ˣ������size-1
//	{
//		int maxPos = 0;
//		//Ѱ�����ֵ��λ��
//		for (int j = 1; j < size - i; j++)
//		{
//			if (array[j] > array[maxPos])
//			{
//				maxPos = j;
//			}
//		}
//		//�����ֵ�����������
//		if (maxPos != size - 1 - i)
//		{
//			swap(&array[maxPos], &array[size - 1 - i]);
//		}
//	}
//}

//void SelectSortOP(int array[], int size)
//{
//	int begin = 0,end = size - 1;
//	while (begin < end)
//	{
//		//�������СԪ��λ��
//		int maxPos = begin;
//		int minPos = begin;
//		int index = begin + 1;
//		while (index <= end)
//		{
//			if (array[index] > array[maxPos])
//			{
//				maxPos = index;
//			}
//			if (array[index] < array[minPos])
//			{
//				minPos = index;
//			}
//			index++;
//		}
//		if (maxPos != end)
//		{
//			swap(&array[maxPos], &array[end]);
//		}
//		//�����С��Ԫ��ǡ����end���������������ı���СԪ�ص�λ��
//		if (minPos == end)
//		{
//			minPos = maxPos;
//		}
//		if (minPos != begin)
//		{
//			swap(&array[minPos], &array[begin]);
//		}
//		begin++;
//		end--;
//	}
//}

////ϣ������
//void ShellSort(int array[], int size)
//{
//	int gap = size;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int i = gap; i < size; i++)
//		{
//			int end = i - gap;
//			int key = array[i];
//			while (end>=0&&array[end]>key)
//			{
//				array[end+gap] = array[end];
//				end=end-gap;
//			}
//			array[end + gap] = key;
//		}
//	}
//}

////��������  
//void InsertSort(int array[], int size)
//{
//	for (int i=1;i<size;i++)
//	{
//		int end = i - 1;
//		int key = array[i];
//		//Ѱ�Ҳ���λ��
//		while (end>=0&&array[end]>key)
//		{
//			array[end+1] = array[end];
//			end--;
//		}
//		//����Ԫ��
//		array[end + 1] = key;
//	}
//}


////���������ӱ�ʾ��
//typedef int BDataType;
//typedef struct BTNode	
//{
//	BDataType data;
//	struct BTNode* left;
//	struct BTNode* right;
//}BTNode;
////��㴴��
//BTNode* BuyBinTreeNode(BDataType data)
//{
//	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
//	if (NULL == node)
//	{
//		assert(0);
//		return NULL;
//	}
//	node->data = data;
//	node->left = node->right = NULL;
//	return node;
//}
////�������
//typedef BTNode* DataType;
//typedef struct QNode //���н��
//{
//	DataType data;
//	struct QNode* next;
//}Qnode;
//typedef struct Queue //����
//{
//	struct Queue* front;
//	struct Queue* back;
//}Queue;
//void LevelOrder(BTNode* root)
//{
//	Queue q;
//	if (NULL == root)
//	{
//		return;
//	}
//	QueueInit(&q);
//	QueuePush(&q, root);
//	while(!QueueEmpty(&q))
//	{
//		BTNode* cur = QueueFront(&q);
//		printf("%d",cur->data);
//		if (cur->left)
//			QueuePush(&q, cur->left);
//		if (cur->right)
//			QueuePush(&q, cur->right);
//		QueuePop(&q);
//	}
//	QueueDestroy(&q);
//}
////����
//void BinTreeDestroy(BTNode** root)
//{
//	assert(root);
//	if (NULL == *root)
//	{
//		return;
//	}
//	//�������������������
//	BinTreeDestroy(&(*root)->left); 
//	BinTreeDestroy(&(*root)->right);
//	free(*root);
//	*root = NULL;
//}
////�������������
//int BinaryTreeSize(BTNode* root)
//{
//	if (NULL == root)
//	{
//		return 0;
//	}
//	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;//��+��+��
//}
////�������Ҷ�ӽ�����
//int BinaryTreeLeafSize(BTNode* root)
//{
//	if (NULL == root)
//	{
//		return 0;
//	}
//	if (NULL == root->left && NULL == root->right)
//	{
//		return 1;
//	}
//	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
//}
////���������k�������
//int BinaryTreeLevelkSize(BTNode* root, int k) 
//{
//	if (NULL == root||k<=0)
//	{
//		return 0;
//	}
//	if (k = 1 )//��һ��ֻ�и����
//	{
//		return 1;	
//	}
//	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
//}
////��������߶�
//int BinaryTreeHeight(BTNode* root)
//{
//	if (NULL == root )
//	{
//		return 0;
//	}
//	//�Ƚ����������������ĸ߶ȣ����ظߵ���һ��
//	int leftheight = BinaryTreeHeight(root->left);
//	int rightheight = BinaryTreeHeight(root->right);
//	return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
//}
////����������ֵΪx�Ľ��
//BTNode* BinaryTreeFind(BTNode* root,BDataType x)
//{
//	BTNode* ret = NULL;
//	if (NULL == root)
//	{
//		return NULL;
//	}
//	if (x == root->data)
//	{
//		return root;
//	}
//	if (ret = BinaryTreeFind(root->left, x))//��������ֵ����ret����ret��Ϊif���ж�������ret��Ϊ�գ���ִ��
//		return ret;
//	return BinaryTreeFind(root->right, x);
//}	
////����������
////array�п�����λ�õ�ֵΪ-1��indexҪͨ���βθı�ʵ�Σ�Ҫ����ַ
//BTNode* CreatBinTree(BDataType  array[],int size,int* index)
//{
//	BTNode* root = NULL;
//	if (*index < size && -1 != array[*index])//���Ⱥ�˳��
//	{
//		//�������ڵ�
//		root = BuyBinTreeNode(array[*index]);
//		//����������
//		++(*index);
//		root->left = CreatBinTree(array, size, index);
//		//����������
//		++(*index);
//		root->right = CreatBinTree(array, size, index);
//	}
//	return root;
//}

	



////���еĴ���
//typedef int DataType;
//typedef struct QNode  //�����нڵ�Ľṹ
//{
//	DataType data;
//	struct QNode* next;
//}QNode;
//typedef struct Queue//���еĽṹ
//{
//	struct QNode* front;
//	struct QNode* back;
//}Queue;
////�������н��
//QNode* BuyQueueNode(DataType data)
//{
//	QNode* node = (QNode*)malloc(sizeof(QNode));
//	if (NULL == node)
//	{
//		assert(0);
//		return NULL;
//	}
//	node->data = data;
//	node->next = NULL;
//	return node;
//}
////��ʼ��
//void QueueInit(Queue* q)
//{
//	assert(q);
//	q->back = q->front =BuyQueueNode(0);
//}
////�����
//void QueuePush(Queue* q, DataType data)
//{
//	assert(q); 
//	q->back->next = BuyQueueNode(data);
//}
////������
//void QueuePop(Queue* q)
//{
//
//}
////��ȡ��ͷԪ��
//DataType QueueFront(Queue* q)
//{
//
//}
////��ȡ��βԪ��
//DataType QueueBack(Queue* q)
//{
//
//}
////��ȡ��������ЧԪ�ظ���
//int QueueSize(Queue* q)
//{
//
//}
////�������Ƿ�Ϊ��
//int QueueEmpty(Queue* q)
//{
//
//}
////���ٶ���
//void QueueDestroy(Queue* q)
//{
//
//}
////����
//void TestQueue()
//{
//	Queue q;
//	QueueInit(&q);
//
//	QueueDestroy(&q);
//}







////ջ�Ĵ���
//typedef int DataType;
//typedef struct stack
//{
//	DataType* array;
//	size_t size;
//	size_t capicity;
//}stack;



////��ͷ�ڵ�˫��ѭ���б�Ĵ���
//typedef int DataType;
//typedef struct DListNode
//{
//	struct DListNode *next;
//	struct DListNode *prev;
//	DataType data;
//}Node;
////����ڵ�
//Node* BuyDListNode(DataType data)
//{
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	if (NULL == newNode)
//	{
//		assert(0);
//		return NULL;
//	}
//	newNode->data = data;
//	newNode->next = NULL;
//	newNode->prev = NULL;
//	return newNode;
//}
////һ��ָ����ܽṹ��ĵ�ַ������ָ����ܽṹ���ַ�ĵ�ַ�������ı�ָ��
////��ʼ��
//void  DListInit(Node**head)
//{
//	assert(head);
//	*head = BuyDListNode(0);
//	(*head)->next = *head;
//	(*head)->prev = *head;
//}
////����λ�ò���------���뵽posǰ
//void DListInsert(Node* pos,DataType data)
//{
//	Node* newNode = NULL;
//	if (NULL == pos)
//		return;
//	newNode = BuyDListNode(data);//��������Ҫ�����½ڵ�
//	newNode->prev = pos->prev;
//	newNode->next = pos;
//	newNode->prev->next = newNode;
//	pos->prev = newNode; 
//}
////����λ��ɾ��
//void DListEresa(Node* pos)
//{
//	if (NULL == pos)
//		return;
//	pos->prev->next = pos->next;
//	pos->next->prev = pos->prev; 
//	free(pos);//�ͷŽڵ�
//}
////β��
//void DListPushBack(Node* head,DataType data)
//{
//	DListInsert(head,data);
//}
////ͷ��
//void DListPushFront(Node* head, DataType data)
//{
//	DListInsert(head->next, data);
//}
////βɾ
//void DListPopBack(Node* head)
//{
//	assert(head);
//	DListErase(head->prev);
//}
////ͷɾ
//void DListPopFront(Node* head)
//{
//	assert(head);
//	DListErase(head->next);
//}
////��������
//void DListDestroy(Node**head)
//{
//	assert(head);
//	Node* cur = (*head)->next;
//	while (cur!=*head)
//	{
//		(*head)->next = cur->next;
//		free(cur);
//		cur = (*head)->next;
//	}
//	free(*head);
//	*head = NULL;
//}
//// ˫���������
//Node* DListFind(Node* head, DataType data)
//{
//	assert(head);
//	Node* cur = head->next;
//	while (cur != head)
//	{
//		if (cur->data == data)
//		{
//			return cur;
//		}
//		cur = cur->next;
//	}
//	return NULL;
//}
//// ˫�������ӡ
//void DListPrint(Node* head)
//{
//	assert(head);
//	Node* cur = head->next;
//	while (cur != head;)
//	{
//		printf("%d", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//}



////��һ����n,�������پ������ٴα仯���Ա�Ϊһ��쳲���������,ÿ�α仯ֻ�ܼ�һ���һ
//int main()
//{
//	int N = 1;
//	int a = 0, b = 1, sum = 1;
//	int B = 0;//����
//	int t = 0;
//	scanf("%d", &N);
//	B = N - 1; 
//	while (1)
//	{
//		sum = a + b;
//		a = b;
//		b = sum;
//		t = N - sum;
//		if (t >= 0)
//		{
//			t= N-sum;
//		}
//		if (t < 0)
//		{
//			t = -(N - sum);
//		}
//		if (B < t)
//		{
//			break;
//		}
//		B = t;
//	}
//	printf("%d", B);
//	return 0;
//}

//int my_atoi(char *str)//ģ��ʵ��atoi����
//{
//	assert(str != NULL);
//	int r = 0;//���ص�����
//	int i = 1;//�ж�����
//
//	while (isspace(*str)==0)
//	{
//		str++;
//	}
//	if (*str == '-')
//	{
//		i = -1;
//	}
//	if (*str == '-'|| *str == '+')//==
//	{
//		str++;
//	}
//	while (*str>='0'&&*str<='9')
//	{
//		r = r * 10 + *str - '0';//�ַ������ֿ����ø��ַ�-'0'
//		str++;
//	}
//	r = r * i;
//	return r;
//}

//#define N 100  //˳���
//typedef int datatype;
////��̬����˳���
//typedef struct Seqlist
//{
//	datatype arrayp[N];//��������
//	size_t size;//��Ч���ݸ���
//}Seqlist;
////��̬����˳���
//typedef struct Seqlist
//{
//	datatype *array;//ָ�������ָ����
//	size_t size;//��Ч���ݸ���
//	size_t capicity;//�����ռ��С
//}Seqlist;
 
//void *my_realloc(void *memblock,size_t size)
//{
//	//�����ռ�
//	void *new_base = malloc(size);
//	assert(new_base != NULL);
//	//���ݸ���
//	memcpy(new_base, memblock, size);
//	//�ͷſռ�
//	free(memblock);
//	//���ص�ַ
//	return new_base;
//}

//void *my_memmove(void *strDest, const void *strSrc, size_t count)//ģ��ʵ��memmove����
//{
//	assert(strDest!=NULL&&strSrc!=NULL);
//	char *str1 =(char *) strDest;
//	const char *str2 = (char *)strSrc;
//	if (str2>=str1||str1>=str2+count)
//	{
//		while (count-- != 0)  
//		{
//			*str1++ = *str2++;
//		}
//	}
//	else
//	{
//		str1 = str1 + count-1;
//		str2 = str2 + count-1;
//		while (count-- != 0)
//		{
//			*str1-- = *str2--;
//		}
//	}
//	return strDest;
//}


//'\0'Ҳ�ᱻ����
//void *my_memcpy(void *strDest,const void *strSrc,size_t count)//ģ��ʵ��memcpy����
//{
//	char *str1 =(char*)strDest;
//	char *str2 = (char*)strSrc;
//	assert(strDest != NULL);
//	while (count--!=0)
//	{
//		*str1++ = *str2++;
//	}
//	return strDest;
//}


/*memset�������ֽڶ��ڴ����г�ʼ����
���Բ���������int�����ʼ��Ϊ0��-1֮�������ֵ�����Ǹ�ֵ���ֽں͵��ֽ���ͬ��*/
//void *my_memset(void *dest, int n, size_t count)//ģ��ʵ��memset����
//{
//	assert(dest!=NULL);
//	char *pdest = (char*)dest;//ǿת��Ϊ��һ��ֻ����һ���ֽ�
//	while (count--!=0)
//	{
//		*pdest++ = n;
//	}
//	return dest;
//}


//size_t my_strlen(const  char *str)//ģ��ʵ��strlen
//{
//	assert(str!=NULL);
//	const char *strEnd = str;
//	while (*strEnd!='\0')
//	{
//		strEnd++;
//	}
//	return strEnd - str;
//}

//char *my_strcpy(char *strDest,const char *strSrc)//ģ��ʵ��strcpy����
//{
//	assert(strDest!=NULL&&strSrc!=NULL);
//	char *str1 = strDest;
//	const char *str2 = strSrc;
//	while (*str2!='\0')
//	{
//		*str1++ = *str2++;
//	}
//	*str1 = '\0';
//	return strDest;
//}

//int my_strcmp(char *str1, char *str2)//ģ��ʵ��strcmp����
//{
//	if (str1 == NULL || str2 == NULL)
//	{
//		return NULL;
//	}
//	while (*str1!=0||*str2!=0)
//	{
//		if (*str1 < *str2)
//		{
//			return *str1-*str2;
//		}
//		else if (*str1 > *str2)
//		{
//			return *str1-*str2;
//		}
//		else
//		{
//			*str1++;
//			*str2++;
//		}
//	}
//	return 0;
//}

//char *my_strcat(char *strDest,const char *strSrc)//ģ��ʵ��strcat����
//{
//	char *str1 = strDest;//����str1ָ��Ŀ���ַ����ĵ�ַ
//	assert(strDest != NULL && strSrc != NULL);
//	while (*str1 != '\0')
//	{
//		str1++;
//	}//str1ָ����ַ���'\0'��λ��
//	while (*strSrc!='\0')
//	{
//		*str1++ = *strSrc++;
//	}
//	return strDest;
//}

//char* my_strstr(const char *str1,const char *str2)//ģ��ʵ��strstr����
//{
//	const char *s = str1;//����
//	const char *t = str2;//ģʽ��
//	int i, j;
//	i = j = 0;
//	while (s[i]!='\0'&&t[j]!='\0')//�����ַ�����һ����ּ�����ѭ��
//	{
//		if (s[i] == t[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = 0;//ģʽ���±��Ϊ0
//			i = i - j + 1;//�����±��Ϊ��һ���ַ�
//		}
//	}
//	if (t[j] == '\0')
//	{
//		return s+i-j;
//	}
//	return NULL;
//}
//int main()
//{
//	char *str1 = "abcdefgh";
//	char *str2 = "def";
//	char *cp=my_strstr(str1, str2);
//	if (cp == NULL)
//	{
//		printf("������");
//	}
//	else
//		printf("%s", cp);
//	return 0;
//}

//int main()//������
//{
//	int people[] = { 0,0,0,0 };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		people[i] = 1;//����iΪ1
//		if ((people[0]!=1)+(people[2]==1)+(people[3]==1)+(people[3]!=1)==3)
//		{
//			break;
//		}
//		people[i] = 0;
//	}
//	printf("%c",'A'+i);
//}

//#define SIZE 7   //��ӡ���������
//int main()
//{
//	int arr[SIZE][SIZE] = { 0 };
//	for (int i = 0; i < SIZE; i++)
//	{
//		for (int j = 0; j <=i; j++)
//		{
//			if (j == 0 || j == i)
//			{
//				arr[j][0] = 1;
//			}
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	for (int i = 0; i < SIZE; i++)
//	{
//		for (int j = 0; j <=i; j++)	
//		{ 
//			printf("%-3d", arr[i][j]);
//		}
//		printf("\n");
//	}
//}

//void arr_exchange(int arr1[], int arr2[],int n)//�����������������
//{
//	for (int i=0;i<n;i++)
//	{
//		int temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//	}
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 6,7,8,9,10 };
//	int n = sizeof(arr1) / sizeof(arr1[0]);
//	printf("arr1:");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	printf("arr2:");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	printf("arr1:");
//	arr_exchange(arr1,arr2,n);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	printf("arr2:");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//}

//void reverse(int arr[], int left, int right)//����Ԫ�ص�����
//{
//	while (left < right)
//	{
//		int temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//		left++;
//		right--;
//	}
//}

//void print(int arr[], int n)//��ӡ����
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}

//void init(int arr[],int n)//��ʼ������Ϊȫ0
//{
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = 0;
//	}
//}

//void exchange_JO(int arr[],int a,int b )//��������ż��˳��
//{
//	int temp = 0;
//	while (b>a)
//	{
//		while (a<b&&arr[a] % 2 == 1)
//		{
//			a++;
//		}
//		while (a<b&&arr[b] % 2 == 0)
//		{
//			b--;
//		}
//		if (a < b)
//		{
//			temp = arr[a];
//			arr[a] = arr[b];
//			arr[b] = temp;
//		}
//
//	}
//}

//void Bubble_Sort(int arr[], int left, int right)//ð������
//{
//	for (int i = left; i < right - 1; i++)
//	{
//		int j = left;
//		for(j=left;j<right-1-i;j++)
//		{
//			if (arr[j] > arr[j+1])
//			{
//				int t = arr[j+1];
//				arr[j+1] = arr[j];
//				arr[j] = t;
//			}
//		}
//	}
//}

//void exchange_JO(int *arr,int n)//��������ż��˳������λ�������ǰ�벿�֣�ż��λ������ĺ�벿�֡�
//{
//	int j = 0;//�������±�
//	for(int i=0;i<n;i++)
//	{
//		for (; j < n; )
//		{
//			if (*(arr+i)% 2 == 1)
//			{
//				int temp = *(arr + i);
//				*(arr + i) = *(arr + j);
//				*(arr + j) = temp;
//				j++;
//				break;
//			}
//			break;
//		}
//	}
//}

//char * my_strcpy(char * dst, const char * src)//ģ��ʵ��strcpy
//{
//	char * cp = dst;
//	while (*cp++ = *src++);
//	return(dst);
//}

//size_t my_strlen(const char * str)//ģ��ʵ��strlen
//{
//	const char *eos = str;
//	while (*eos++);
//	return(eos - str - 1);
//}

//int main()
//{
//	int a = 10,b=20;
//	printf("%d %d\n", a, b);
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("%d %d",a,b);
//}

//int Count(int a)  //�����������1�ĸ���
//{
//	int count = 1;
//	while (a & (a - 1))
//	{
//		a = a & (a - 1);
//		count++;
//	}
//	return count;
//}

//int main()
//{
//	int a = 21;
//	for (int i = 0; i < 32; i += 2)
//	{
//		printf("%d", a>>i & 1);
//	}
//	printf("\n");
//	for (int i = 1; i < 33; i += 2)
//	{
//		printf("%d", (a>>i) & 1);
//	}
//}

//int main()//�������������1�ĸ���
//{
//	int a = 1999, b = 2299;
//	int val = a ^ b;
//	int count = 1;
//	while (val&(val-1))
//	{
//		val = val & (val - 1);
//		count++;
//	}
//	printf("%d",count);
//}
//
//void BubbleSort(int arr[],int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		int j=0;
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (arr[j]> arr[j+1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 78,100,3,4,5,6,75,8,59,80 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr, n);
////}

//int FB(int n)//����ѭ����쳲��������е�n��
//{
//	int a = 1,b=1,sum=2;
//	for (int i = 0; i < n; i++)
//	{
//		if (i < 2)
//		{
//			sum= 1;
//		}
//		else
//		{
//			sum = a + b;
//			a = b;
//			b=sum;
//		}
//	}
//	return sum;
//}

//int FB(int n)//���n��쳲�������
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	return FB(n - 2) + FB(n - 1);
//}

//int powr(int n, int k)//�ݹ�ʵ��n��k�η�
//{
//	if (0 == k)
//	{
//		return 1;
//	}
//	else
//	{
//		if (1 == k)
//		{
//			return n;
//		}
//		return n * powr(n, k - 1);
//	}
//}

//int DigitSum(n)//����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19
//{
//	if (n < 10)
//		return n % 10;
//	return n % 10 + DigitSum(n / 10);
//}

//void reverse_string(char * string)//�ݹ�ʵ�ֽ��ַ�����������
//{
//	int n = strlen(string);
//	char *L = string;
//	char *R = string + n - 1;
//	char temp = *L;
//	*L = *R;
//	*R = '\0';
//	if (strlen(string+1)>1)
//	{
//		reverse_string(string + 1);
//	}
//	*R = temp;
//}

//int	strlen(char *str)//�ݹ�ʵ��strlen
//{
//	if ('\0' == *str)
//	{
//		return 0;
//	}
//	return 1 + strlen(str + 1);
//}
//int main()
//{
//	char str[] = "abcdefg";
//	int n = strlen(str);
//	printf("%d",n);
//}

//int main()//n��
//{
//	int n = 5;
//	int val = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		val = val * i;
//	}
//	printf("%d",val);
//}

//int fact(int n)//�ݹ����n��
//{
//	if (1==n)
//		return 1;
//	return n * fact(n - 1);
//}
//int main() 
//{
//	int n = 5;
//	int ret = fact(n);
//	printf("%d",ret);
//}

//int print(int a)//�ݹ��ӡһ����ÿһλ
//{
//	if (a > 10)
//	{
//		print(a / 10);
//	}	
//	printf("%d", a % 10);
//}
//int main()
//{
//	int a = 1234;
//	print(a);
//}

//void Mul(int n)// ������ӡ�˷��ھ���
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			printf("%d*%d=%-5d", i, j, i*j);
//			if (i == j)
//			{
//				printf("\n");
//				break;
//			}
//		}
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	Mul(n);
//}

//void exchange(int *a,int *b)//��������������
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int main()
//{
//	int a = 10, b = 20;
//	exchange(&a,&b);
//	printf("%d %d", a, b);
//}

//int is_lead(int n)//������ӡ����
//{
//	if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
//	{
//		return 1;
//	}
//	return 0;
//}
//int main()
//{	
//	int n = 0;
//	scanf("%d", &n);
//	int val = is_lead(n);
//	printf("%d", val);
//}

//int is_prime(int n)  //������ӡ����
//{
//	for ( int j = 2; j < (int)sqrt(n); j++)
//	{
//		if (0 == n % j)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	for (int n=100;n<201;n++)
//	{
//		int val = is_prime(n);
//		if (1==val)
//		{
//			printf("%d ",n);
//		}
//	}
//}

//int main()//�ȹ��ľ�
//{
//	int money = 20;
//	int count1 = money;
//	int count2 = money;
//	while (count2 > 1)
//	{
//		count1 += count2 / 2;
//		count2 = count2 / 2 + count2 % 2;
//	}
//	printf("%d", count1);
//}

//int main() //��ӡ����
//{
//	int L = 6;
//	int R = 6;
//	for (int i = 0; i < 7; i++)
//	{
//		for (int j=0;j<13;j++)
//		{
//			if (j >= L && j <= R)
//			{
//				printf("*");
//			}
//			else
//			{
//				printf(" ");
//			}
//		}
//		L--;
//		R++;
//		printf("\n");
//	}//L=-1  R=13
//	L++;
//	R--;
//	for (int i = 0 ; i < 6; i++)
//	{
//		L++;
//		R--;
//		for (int j = 0; j < 13; j++)
//		{
//			if (j >= L && j <= R)
//			{
//				printf("*");
//			}
//			else
//			{
//				printf(" ");
//			}
//		}
//		printf("\n");
//	}
//}

//int main()  //ˮ�ɻ���
//{
//	int i = 0;
//	for (i = 0; i < 100001; i++)
//	{
//		int n = 0;
//		int a = i;
//		int sum = 0;
//		if (0 == i)
//		{
//			n = 1;
//		}
//		while (a)
//		{
//			a = a / 10;
//			n++;
//		}
//		a = i;
//		while (a)
//		{
//			sum += pow(a % 10, n);
//			a = a / 10;
//		}
//		if (i == sum)
//		{
//			printf("%d  ", i);
//		}
//	}
//}

//int main()
//{
//	int a = 0, n = 0;
//	int sum = 0, value = 0;
//	scanf("%d %d", &a, &n);
//	for (int i = 0; i < n; i++)
//	{
//		value = value * 10 + a;
//		sum = sum + value;
//	}
//	printf("%d", sum);
//	return 0;
//}

//void BS(char *str,char *end)//�����ַ���
//{
//	while (str<end)
//	{
//		int temp = 0;
//		temp = *str;
//		*str = *end;
//		*end = temp;
//		str += 1;
//		end -= 1;
//	}
//}
//int main()
//{
//	char str[] = "abcdefg";
//	int n = strlen(str);
//	BS(str, &str[n - 1]);
//	printf("%s",str);
//}

//void print(int *arr ,int sz)//ʹ��ָ���ӡ����
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	print(&arr, n);
//	return 0;
//}

//int MyMax(int x, int y)
//{
//	if (x > y) {
//		return x;
//	}
//
//	return y;
	//else if (x < y){
	//	return y;
	//}
	//else{
	//	return x;
	//}
//}

//return 0: no
//retunr 1: yes
//int is_prime_number(int n)
//{
//	int i = 2;
//	//2..n-1
//	//100
//	//4 * 25
//	//25 * 4
//	//10 * 10
//	for (; i <= (int)sqrt(n); ++i) { //2,3,4,5,6,7,8,9, n = x * y
//		if (n % i == 0) {
//			return 0;
//		}
//	}
//	return 1;
//}

//void Menu()//��������Ϸ
//{
//	printf("########################\n");
//	printf("## 1. Guess   0. Exit ##\n");
//	printf("########################\n");
//	printf("Please Select# ");
//}
//void Game()
//{
//	int n = 0;
//	int count = 0;
//	int data = rand() % 100 + 1;
//	do {
//		count++;
//		printf("Please Guess# ");
//		scanf("%d", &n);
//		if (n < data) {
//			printf("��µ�С��!\n");
//		}
//		else if (n > data) {
//			printf("��´���!\n");
//		}
//		else {
//			printf("��ϲ�㣬�¶��ˣ������� %d, ���� %d �λ��� \n", n, count);
//			break;
//		}
//	} while (1);
//
//}
//int main()
//{
//	int quit = 0;
//	srand((unsigned long)time(NULL));
//	while (!quit) {
//		Menu();
//		int select = 0;
//		scanf("%d", &select);
//		switch (select) {
//		case 1:
//			Game();
//			break;
//		case 0:
//			quit = 1;
//			break;
//		default:
//			printf("select error!\n");
//			break;
//		}
//		printf("��ϲ����ɣ�Ҫ��Ҫ�ٸ�һ��!\n");
//	}
//	printf("byebye!\n");
//}

//int main()  //ʹ�ö��ֲ��ҷ����������������в���ĳ����
//{
//	int arr[] = { 1,5,8,42,55,67,78,82,93,130 };
//	int c = sizeof(arr) / sizeof(arr[0]);
//	int a = 130;
//	int start = 0, end = c - 1;
//	while (1) 
//	{
//		int mid = (start + end) / 2;
//		if (a > arr[mid])
//		{
//			start = mid+1;	
//		}
//		else if(a < arr[mid])
//		{
//			end = mid-1;
//		}
//		else
//		{
//			printf("%d", mid);
//			break;
//		}
//	}
//	return 0;
//}

//int main()  �˷��ھ���
//{
//	int  i = 1,a=1;
//	for (i = 1; i < 10; i++)//H
//	
//		for (a = 1; a < 10; a++)//L
//		{
//			printf("%d*%d=%-5d",i,a,i*a);
//			if (a == i)
//			{
//				printf("\n");
//				break;
//			}
//		}
//}

//int main()  //��10�����������ֵ
//{
//	int i = 1;
//	int arr[10] = { 8,73,3,21,88,92,52,8,33,18};
//	int max = arr[0];
//	while (i < 10)
//	{
//		max = max > arr[i] ? max : arr[i];
//		i++;
//	}
//	printf("%d",max);
//}

//int main()  //����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ
//{
//	int i = 1,t=1;
//	double num = 0.0;
//	while (i <= 100)
//	{
//		num = num + t*(1.0 / i);
//		t = -t;
//		i++;
//	} 
//	printf("%lf",num);
//}

//int main()   //1��100��9���ֵĴ���
//{
//	int i = 1;
//	int count = 0;
//	for (i = 1; i < 101; i++)
//	{
//		if (9 == i % 10)
//		{
//			count++;
//		}
//		if (9 == i / 10)
//		{
//			count++;
//		}
//	}
//	printf("%d",count);
//}

//int main()   //1��100��9���ֵĴ���
//{
//	int i = 1,a,n=0;
//	for (i = 1; i < 101; i++) {
//		a = i;
//		while (a != 0) {
//			if (a % 10 == 9) {
//				n++;
//			}
//			a /= 10;
//		}
//	}
//	printf("%d\n", n);
//	return 0;
//}

//int main() //��100��200�е�����
//{
//	int i = 100;
//	int a;
//	for (i = 100; i <= 200; i++)
//	{
//		for (a = 2; a <= (int)sqrt(i); a++)
//		{
//			if (0 == i % a)
//			{
//				break;
//			}
//			if (a == (int)sqrt(i) - 1) 
//			{
//				printf("%d ", i);
//			}
//		}
//	}
//}

//int main()   //������
//{
//	int i=1000;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
//		{
//			printf("%d ",i);
//		}
//	}
//	return 0;
//}
//

//int main()  //շת����������Լ��
//{
//	int x = 75, y = 100;
//	int z = 0;
//	while (z = x % y)
//	{
//		x = y;
//		y = z;
//	}
//	printf("%d", y);
//	return 0;
//}


//int main()  //���Լ��
//{
//	int a = 0, b = 0,i=0;
//	scanf("%d %d", &a, &b);
//	for(i= a < b ? a : b;i>=1;i--)
//	{
//		if (a%i == 0 && b%i == 0)
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//	return  0;
//}

//int main() ��ӡ���ı���
//{
//	int i=1;
//	while (i <= 100)
//	{
//		if (0 == i % 3)
//		{
//			printf("%d ", i);
//		}
//		i++;
//	}
//	return 0;
//}

//int main()   �Ӵ�С����
//{
//	int a, b, c;//�����������ı��� 
//	int t;//������Ϊ�����ı��� 
//	scanf("%d%d%d", &a, &b, &c); //ȡֵ 
//	if (a < b)
//	{
//		t = a; a = b; b = t;
//	}//���a,b�����н�������֮���� 
//	if (a < c)
//	{
//		t = a; a = c; c = t;
//	}//ͬ�� 
//	if (b < c)
//	{
//		t = b; b = c; c = t;
//	}
//	printf("%-5d%-5d%-5d\n", a, b, c);//��� 
//}

//int main()
//{
//	int a=0, b=0, c=0;
//	scanf("%d %d %d",&a,&b,&c);
//	if (a > b)
//	{
//		if (b > c)
//		{
//			printf("%d %d %d", a, b, c);
//		}
//		else
//		{
//			if (a > c)
//			{
//				printf("%d %d %d",a,c,b);
//			}
//			printf("%d %d %d",c,a,b);
//		}
//	}
//	else//a<b
//	{
//		if ( c < a )
//		{
//			printf("%d %d %d", b, a, c);
//		}
//		else
//		{
//			if (b > c)
//			{
//				printf("%d %d %d", b, c, a);
//			}
//			printf("%d %d %d", c, b, a);
//		}
//	}
//	return 0;
//}