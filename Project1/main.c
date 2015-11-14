#include <stdio.h>


typedef struct node //链表节点
{
	char name[20];
	char brend[20];
	int num;//数量；
	int price;
	struct node *next;
}Node;

typedef struct list
{
	struct node *head;
	struct node *tail;
}List;

void CreatList(List *l)//创建链表，包括头结点和尾节点
{
	l->head = (Node*)malloc(sizeof(Node));
	l->tail = (Node*)malloc(sizeof(Node));
	if (NULL == l->head|| NULL == l->tail)
	{
		printf("动态分配内存失败\n");
		exit(-1);
	}
	else
	{
		l->tail = l->head->next;
		l->tail->next = NULL;                    
	}
	return;
}

//从文件里恢复链表
void AddNode(List *l, char name[], char brend[], int num, int price)//向链表中添加节点,并且排序。
{
	Node *p = (Node*)malloc(sizeof(Node));
	Node *q;
	Node *r;
	p->name = name;
	p->brend = brend;
	p->num = num;
	p->price = price;
	if (l->head->next == l->tail)//判读链表是否为空。
	{
		l->head->next = p;
		p->next = l->tail;
	}
	else//如果链表不为空
	{
		q = l->head->next;
		if (p->price <= q->price)
		{
			l->head->next = p;
			p->next = q;
		}
		while (p->price > q->price) 
		{
			r = q;
			q = q->next;
			if (q->next == l->tail)//到头了怎么办
			{
				if (q->price <= p->price)
				{
					r = q;
					q = l->tail;
					break;
				}
				else if (q->price > p->price)
				{
					break;
				}
			}
		}
		p = r->next;
		p->next = q;
	}
}

int main()
{
	List l;
	CreatList(&l);
}