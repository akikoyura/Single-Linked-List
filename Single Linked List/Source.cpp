#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct Node *ref;
struct Node
{
	int value;
	ref Next;
};
ref GetNode (int key)
{
	ref p; 
	p = (ref)malloc(sizeof(struct Node));
	if (p == NULL)
	{
		printf("Loi khong du bo nho");
		exit(0);
	}
	//tạo con trỏ tới struct node gán giá trị cho value = key;
	p->value = key;
	//Khởi tạo vùng nhớ cho Node mới bằng null
	p->Next = NULL;
	//trả về node p;
	return p;
}
//dùng kỹ thuật tham chiếu trên C++
void addFirst(ref &head, ref& tail, int k)
{
	//lấy giá trị của nút
	ref p = GetNode(k);
	if (head == NULL)
	{
		head = tail = p;
	}
	else
	{
		//tạo mối liên kết với node có head hiện tại = p->Next = head;
		//rồi gán head = p;
		p->Next = head;
		head = p;
	}
}
void printList(ref head)
{
	ref p;
	if (head == NULL)
	{
		printf("\ndanh sach rong");
	}
	else
	{
		for (p = head; p; p = p->Next)
		{
			printf("%d\n", p->value);
		}
	}
}
void destroyList(ref& head)
{
	ref p;
	while (head)
	{
		p=head;
		head = head->Next;
		free(p); 
	}
	printf("\nFree memory successfully");
}
void addLast(ref &head, ref& tail, int k)
{
	//thêm giá trị vào node p 
	ref p = GetNode(k);
	//Nếu node p chưa có giá trị thì gán head = tail =p;
	if (head == NULL)
	{
		head = tail = p;
	}
	//ngược lại thì ref tail trỏ tới next = p
	else
	{
		(*tail).Next = p;
		//sau đó gán tail = p;
		tail = p;
	}
}
void addLastLinear(ref& head, int k)
{
	ref p;
	if (head == NULL)
	{
		head = GetNode(k);
	}
	else
	{
		//gán node đầu tiên là head;
		p = head;
		//trong khi duyệt qua danh sách và node kế tiếp
		while (p->Next)
		{
			//p sẽ được gán bằng node tiếp theo
			p = p->Next;
			//lúc đó node tiếp theo sẽ có get giá trị 
			p->Next = GetNode(k);
		}
	}
}
int main(int argc, char **argv)
{
	int k;
	ref head = NULL, tail = NULL;
	while(1)
	{
		printf("nhap so nguyen (nhap so khong de thoat):");
		scanf_s("%d", &k);
		if (k == 0)
		{
			break;
		}
		addLast(head, tail, k);
	}
	printList(head);
	destroyList(head);
	system("pause");
	return 0;
}