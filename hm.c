#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include<assert.h>
#include<malloc.h>
#pragma warning(disable:4996)

////合并两个有序数组
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
////归并排序
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

////第一种：hoare法
//int Partion1(int array[], int left, int right)
//{
//	int begin = left;
//	int end = right - 1;
//	int key = array[end];//基准值是最后一个元素
//	while (begin < end)
//	{
//		while (begin<end&&array[begin] <= key) //保证有效区间
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
//		swap(&array[begin], &array[right - 1]);//将基准值放在数组中间
//	}
//	return begin;//返回基准值位置
//}
////第二种：挖坑法	
//int Partion2(int array[], int left, int right)
//{
//	int begin = left;
//	int end = right - 1;
//	int key = array[end];
//	while (begin < end)
//	{
//		//begin从前往后找，找比基准值大的元素 
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
////第三种
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
//	//找基准值对区间中的数据进行划分，div表述划分好等候基准值位置
//	div = Partion3(array, left, right);
//	//递归
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


////计数排序
//void CountSort(int array[], int size)
//{
//	//1.找数据范围
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
//	//2.申请空间
//	int* count = (int*)calloc(max - min + 1, sizeof(int));
//	if (NULL == count)
//	{
//		return NULL; 
//	}
//	//3.统计每个元素出现次数
//	for (int i = 0; i < size; i++)
//	{
//		count[array[i] - min]++;
//	}
//	//4.array数组排序
//	for (int i=0;i<max-min+1;i++)
//	{
//		while (count[i]--)
//		{
//			array[index++] = i + min;
//		}
//	}
//	free(count);
//}

////冒泡排序
//void BubbleSort(int array[], int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		int flag=0;
//		//相邻两个元素比较，不满足就交换
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

////堆排序
//void swap(int arr1[], int arr2[])
//{
//	int temp = 0;
//	temp = *arr1;
//	*arr1 = *arr2;
//	*arr2 = temp;
//}
//void HeapAdjust(int array[], int size, int parent)//向下调整
//{
//	//先标记左孩子，parent可能有左没有右
//	int child = parent * 2 + 1;
//	while (child<size)
//	{
//		//找到左右孩子中较大的，用child标记
//		if (child+1 < size && array[child] < array[child + 1])
//		{
//			child += 1;
//		}
//		//如果双亲结点小于较大的子结点，则交换
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
//	//建堆， 升序-->大堆    降序-->小堆
//	//从倒数第一个非叶子结点到根结点一直向下调整
//	for (int root = (end - 1) / 2; root >= 0; root--)
//	{
//		HeapAdjust(array, size, root);
//	}
//	//排序
//	while(end)
//	{
//		swap(&array[0], &array[end]);
//		HeapAdjust(array, end , 0);
//		end--;
//	}
//}

//

////选择排序
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
//	for(int i=0;i<size-1;i++)//最后剩一个数就不用排了，因此是size-1
//	{
//		int maxPos = 0;
//		//寻找最大值的位置
//		for (int j = 1; j < size - i; j++)
//		{
//			if (array[j] > array[maxPos])
//			{
//				maxPos = j;
//			}
//		}
//		//将最大值放在数组最后
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
//		//找最大最小元素位置
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
//		//如果最小的元素恰巧在end处，则上面操作会改变最小元素的位置
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

////希尔排序
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

////插入排序  
//void InsertSort(int array[], int size)
//{
//	for (int i=1;i<size;i++)
//	{
//		int end = i - 1;
//		int key = array[i];
//		//寻找插入位置
//		while (end>=0&&array[end]>key)
//		{
//			array[end+1] = array[end];
//			end--;
//		}
//		//插入元素
//		array[end + 1] = key;
//	}
//}


////二叉树孩子表示法
//typedef int BDataType;
//typedef struct BTNode	
//{
//	BDataType data;
//	struct BTNode* left;
//	struct BTNode* right;
//}BTNode;
////结点创建
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
////层序遍历
//typedef BTNode* DataType;
//typedef struct QNode //队列结点
//{
//	DataType data;
//	struct QNode* next;
//}Qnode;
//typedef struct Queue //队列
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
////销毁
//void BinTreeDestroy(BTNode** root)
//{
//	assert(root);
//	if (NULL == *root)
//	{
//		return;
//	}
//	//按后序遍历规则来销毁
//	BinTreeDestroy(&(*root)->left); 
//	BinTreeDestroy(&(*root)->right);
//	free(*root);
//	*root = NULL;
//}
////求二叉树结点个数
//int BinaryTreeSize(BTNode* root)
//{
//	if (NULL == root)
//	{
//		return 0;
//	}
//	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;//左+右+根
//}
////求二叉树叶子结点个数
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
////求二叉树第k层结点个数
//int BinaryTreeLevelkSize(BTNode* root, int k) 
//{
//	if (NULL == root||k<=0)
//	{
//		return 0;
//	}
//	if (k = 1 )//第一层只有根结点
//	{
//		return 1;	
//	}
//	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
//}
////求二叉树高度
//int BinaryTreeHeight(BTNode* root)
//{
//	if (NULL == root )
//	{
//		return 0;
//	}
//	//比较左子树和右子树的高度，返回高的那一个
//	int leftheight = BinaryTreeHeight(root->left);
//	int rightheight = BinaryTreeHeight(root->right);
//	return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
//}
////二叉树查找值为x的结点
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
//	if (ret = BinaryTreeFind(root->left, x))//函数返回值赋给ret，把ret作为if的判断条件，ret若为空，不执行
//		return ret;
//	return BinaryTreeFind(root->right, x);
//}	
////二叉树创建
////array中空树的位置的值为-1，index要通过形参改变实参，要传地址
//BTNode* CreatBinTree(BDataType  array[],int size,int* index)
//{
//	BTNode* root = NULL;
//	if (*index < size && -1 != array[*index])//有先后顺序
//	{
//		//创建根节点
//		root = BuyBinTreeNode(array[*index]);
//		//创建左子树
//		++(*index);
//		root->left = CreatBinTree(array, size, index);
//		//创建右子树
//		++(*index);
//		root->right = CreatBinTree(array, size, index);
//	}
//	return root;
//}

	



////队列的创建
//typedef int DataType;
//typedef struct QNode  //队列中节点的结构
//{
//	DataType data;
//	struct QNode* next;
//}QNode;
//typedef struct Queue//队列的结构
//{
//	struct QNode* front;
//	struct QNode* back;
//}Queue;
////创建队列结点
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
////初始化
//void QueueInit(Queue* q)
//{
//	assert(q);
//	q->back = q->front =BuyQueueNode(0);
//}
////入队列
//void QueuePush(Queue* q, DataType data)
//{
//	assert(q); 
//	q->back->next = BuyQueueNode(data);
//}
////出队列
//void QueuePop(Queue* q)
//{
//
//}
////获取队头元素
//DataType QueueFront(Queue* q)
//{
//
//}
////获取队尾元素
//DataType QueueBack(Queue* q)
//{
//
//}
////获取队列中有效元素个数
//int QueueSize(Queue* q)
//{
//
//}
////检测队列是否为空
//int QueueEmpty(Queue* q)
//{
//
//}
////销毁队列
//void QueueDestroy(Queue* q)
//{
//
//}
////测试
//void TestQueue()
//{
//	Queue q;
//	QueueInit(&q);
//
//	QueueDestroy(&q);
//}







////栈的创建
//typedef int DataType;
//typedef struct stack
//{
//	DataType* array;
//	size_t size;
//	size_t capicity;
//}stack;



////带头节点双向循环列表的创建
//typedef int DataType;
//typedef struct DListNode
//{
//	struct DListNode *next;
//	struct DListNode *prev;
//	DataType data;
//}Node;
////申请节点
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
////一级指针接受结构体的地址，二级指针接受结构体地址的地址，进而改变指向
////初始化
//void  DListInit(Node**head)
//{
//	assert(head);
//	*head = BuyDListNode(0);
//	(*head)->next = *head;
//	(*head)->prev = *head;
//}
////任意位置插入------插入到pos前
//void DListInsert(Node* pos,DataType data)
//{
//	Node* newNode = NULL;
//	if (NULL == pos)
//		return;
//	newNode = BuyDListNode(data);//插入首先要申请新节点
//	newNode->prev = pos->prev;
//	newNode->next = pos;
//	newNode->prev->next = newNode;
//	pos->prev = newNode; 
//}
////任意位置删除
//void DListEresa(Node* pos)
//{
//	if (NULL == pos)
//		return;
//	pos->prev->next = pos->next;
//	pos->next->prev = pos->prev; 
//	free(pos);//释放节点
//}
////尾插
//void DListPushBack(Node* head,DataType data)
//{
//	DListInsert(head,data);
//}
////头插
//void DListPushFront(Node* head, DataType data)
//{
//	DListInsert(head->next, data);
//}
////尾删
//void DListPopBack(Node* head)
//{
//	assert(head);
//	DListErase(head->prev);
//}
////头删
//void DListPopFront(Node* head)
//{
//	assert(head);
//	DListErase(head->next);
//}
////销毁链表
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
//// 双向链表查找
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
//// 双向链表打印
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



////给一个数n,求他最少经过多少次变化可以变为一个斐波那契数列,每次变化只能加一或减一
//int main()
//{
//	int N = 1;
//	int a = 0, b = 1, sum = 1;
//	int B = 0;//步数
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

//int my_atoi(char *str)//模拟实现atoi函数
//{
//	assert(str != NULL);
//	int r = 0;//返回的整数
//	int i = 1;//判断正负
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
//		r = r * 10 + *str - '0';//字符变数字可以用该字符-'0'
//		str++;
//	}
//	r = r * i;
//	return r;
//}

//#define N 100  //顺序表
//typedef int datatype;
////静态开辟顺序表
//typedef struct Seqlist
//{
//	datatype arrayp[N];//定长数组
//	size_t size;//有效数据个数
//}Seqlist;
////动态开辟顺序表
//typedef struct Seqlist
//{
//	datatype *array;//指向数组的指针吗
//	size_t size;//有效数据个数
//	size_t capicity;//容量空间大小
//}Seqlist;
 
//void *my_realloc(void *memblock,size_t size)
//{
//	//创建空间
//	void *new_base = malloc(size);
//	assert(new_base != NULL);
//	//数据复制
//	memcpy(new_base, memblock, size);
//	//释放空间
//	free(memblock);
//	//返回地址
//	return new_base;
//}

//void *my_memmove(void *strDest, const void *strSrc, size_t count)//模拟实现memmove函数
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


//'\0'也会被拷贝
//void *my_memcpy(void *strDest,const void *strSrc,size_t count)//模拟实现memcpy函数
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


/*memset函数按字节对内存块进行初始化，
所以不能用它将int数组初始化为0和-1之外的其他值（除非该值高字节和低字节相同）*/
//void *my_memset(void *dest, int n, size_t count)//模拟实现memset函数
//{
//	assert(dest!=NULL);
//	char *pdest = (char*)dest;//强转是为了一次只操作一个字节
//	while (count--!=0)
//	{
//		*pdest++ = n;
//	}
//	return dest;
//}


//size_t my_strlen(const  char *str)//模拟实现strlen
//{
//	assert(str!=NULL);
//	const char *strEnd = str;
//	while (*strEnd!='\0')
//	{
//		strEnd++;
//	}
//	return strEnd - str;
//}

//char *my_strcpy(char *strDest,const char *strSrc)//模拟实现strcpy函数
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

//int my_strcmp(char *str1, char *str2)//模拟实现strcmp函数
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

//char *my_strcat(char *strDest,const char *strSrc)//模拟实现strcat函数
//{
//	char *str1 = strDest;//定义str1指向目标字符串的地址
//	assert(strDest != NULL && strSrc != NULL);
//	while (*str1 != '\0')
//	{
//		str1++;
//	}//str1指向该字符串'\0'的位置
//	while (*strSrc!='\0')
//	{
//		*str1++ = *strSrc++;
//	}
//	return strDest;
//}

//char* my_strstr(const char *str1,const char *str2)//模拟实现strstr函数
//{
//	const char *s = str1;//主串
//	const char *t = str2;//模式串
//	int i, j;
//	i = j = 0;
//	while (s[i]!='\0'&&t[j]!='\0')//两个字符串有一个结局即跳出循环
//	{
//		if (s[i] == t[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = 0;//模式串下标变为0
//			i = i - j + 1;//主串下标变为下一个字符
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
//		printf("不存在");
//	}
//	else
//		printf("%s", cp);
//	return 0;
//}

//int main()//猜凶手
//{
//	int people[] = { 0,0,0,0 };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		people[i] = 1;//凶手i为1
//		if ((people[0]!=1)+(people[2]==1)+(people[3]==1)+(people[3]!=1)==3)
//		{
//			break;
//		}
//		people[i] = 0;
//	}
//	printf("%c",'A'+i);
//}

//#define SIZE 7   //打印杨辉三角形
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

//void arr_exchange(int arr1[], int arr2[],int n)//交换两个数组的内容
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

//void reverse(int arr[], int left, int right)//数组元素的逆置
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

//void print(int arr[], int n)//打印数组
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}

//void init(int arr[],int n)//初始化数组为全0
//{
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = 0;
//	}
//}

//void exchange_JO(int arr[],int a,int b )//调整奇数偶数顺序
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

//void Bubble_Sort(int arr[], int left, int right)//冒泡排序
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

//void exchange_JO(int *arr,int n)//调整奇数偶数顺序，奇数位于数组的前半部分，偶数位于数组的后半部分。
//{
//	int j = 0;//奇数的下标
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

//char * my_strcpy(char * dst, const char * src)//模拟实现strcpy
//{
//	char * cp = dst;
//	while (*cp++ = *src++);
//	return(dst);
//}

//size_t my_strlen(const char * str)//模拟实现strlen
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

//int Count(int a)  //求二进制序列1的个数
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

//int main()//求二进制序列中1的个数
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

//int FB(int n)//迭代循环求斐波那契数列第n项
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

//int FB(int n)//求第n个斐波那契数
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	return FB(n - 2) + FB(n - 1);
//}

//int powr(int n, int k)//递归实现n的k次方
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

//int DigitSum(n)//调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19
//{
//	if (n < 10)
//		return n % 10;
//	return n % 10 + DigitSum(n / 10);
//}

//void reverse_string(char * string)//递归实现将字符串反向排列
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

//int	strlen(char *str)//递归实现strlen
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

//int main()//n！
//{
//	int n = 5;
//	int val = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		val = val * i;
//	}
//	printf("%d",val);
//}

//int fact(int n)//递归求解n！
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

//int print(int a)//递归打印一个数每一位
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

//void Mul(int n)// 函数打印乘法口诀表
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

//void exchange(int *a,int *b)//函数交换两个数
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

//int is_lead(int n)//函数打印闰年
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

//int is_prime(int n)  //函数打印素数
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

//int main()//喝过的酒
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

//int main() //打印菱形
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

//int main()  //水仙花数
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

//void BS(char *str,char *end)//倒序字符串
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

//void print(int *arr ,int sz)//使用指针打印数组
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

//void Menu()//猜数字游戏
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
//			printf("你猜的小了!\n");
//		}
//		else if (n > data) {
//			printf("你猜大了!\n");
//		}
//		else {
//			printf("恭喜你，猜对了，数据是 %d, 花了 %d 次机会 \n", n, count);
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
//		printf("恭喜你完成，要不要再搞一把!\n");
//	}
//	printf("byebye!\n");
//}

//int main()  //使用二分查找法在整形有序数组中查找某个数
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

//int main()  乘法口诀表
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

//int main()  //求10个整数中最大值
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

//int main()  //计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值
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

//int main()   //1到100中9出现的次数
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

//int main()   //1到100中9出现的次数
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

//int main() //求100到200中的素数
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

//int main()   //求闰年
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

//int main()  //辗转相除法求最大公约数
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


//int main()  //最大公约数
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

//int main() 打印三的倍数
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

//int main()   从大到小排列
//{
//	int a, b, c;//定义三个数的变量 
//	int t;//定义作为交换的变量 
//	scanf("%d%d%d", &a, &b, &c); //取值 
//	if (a < b)
//	{
//		t = a; a = b; b = t;
//	}//如果a,b，进行交换，反之不动 
//	if (a < c)
//	{
//		t = a; a = c; c = t;
//	}//同上 
//	if (b < c)
//	{
//		t = b; b = c; c = t;
//	}
//	printf("%-5d%-5d%-5d\n", a, b, c);//输出 
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