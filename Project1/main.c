#include <stdio.h>


typedef struct node //����ڵ�
{
	char name[20];
	char brend[20];
	int num;//������
	int price;
	struct node *next;
}Node;

typedef struct list
{
	struct node *head;
	struct node *tail;
}List;

void CreatList(List *l)//������������ͷ����β�ڵ�
{
	l->head = (Node*)malloc(sizeof(Node));
	l->tail = (Node*)malloc(sizeof(Node));
	if (NULL == l->head|| NULL == l->tail)
	{
		printf("��̬�����ڴ�ʧ��\n");
		exit(-1);
	}
	else
	{
		l->tail = l->head->next;
		l->tail->next = NULL;                    
	}
	return;
}

//���ļ���ָ�����
void AddNode(List *l, char name[], char brend[], int num, int price)//����������ӽڵ�,��������
{
	Node *p = (Node*)malloc(sizeof(Node));
	Node *q;
	Node *r;
	p->name = name;
	p->brend = brend;
	p->num = num;
	p->price = price;
	if (l->head->next == l->tail)//�ж������Ƿ�Ϊ�ա�
	{
		l->head->next = p;
		p->next = l->tail;
	}
	else//�������Ϊ��
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
			if (q->next == l->tail)//��ͷ����ô��
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