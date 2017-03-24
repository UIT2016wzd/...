#include"iostream"
#include"string"
using namespace std;

struct Node//��������ṹ��
{
	int Data;
	Node * next;
};

class list//����������
{
	Node*head;
	public:
		list()
		{
			head = NULL;
		}
		void insertlist(int aData, int bData);//����ڵ�Ĳ���
		void Deletelist(int aData);//����ڵ��ɾ��
		void Outputlist();//����ڵ�����
			Node*Gethead()
			{
				return head; 
			}
};

void list::Outputlist()//�����������
{
	Node*current = head;
	while (current != NULL)
	{
		cout << current->Data << " ";
		current = current->next;
	}
	cout << endl;
}

void list::insertlist(int aData, int bData)//������뺯���������ڵ��е����ݣ�
{
	Node *p, *q, *s;//pָ��ڵ�a��qָ��ڵ�a_k,sָ��ڵ�b
	q = NULL;
	s = (Node*)new(Node);//��̬����һ���½ڵ�
	s->Data = bData;//��bΪ���½ڵ�
	p = head;
	if (head == NULL)//���ǿձ�ʹb��Ϊ��һ���ڵ�
	{
		head = s;
		s->next = NULL;
	}
	else
	{
		if (p->Data == aData)//��a�ǵ�һ���ڵ�
		{
			s->next = p;
			head = s;
		}
		else
		{
			while (p->Data != aData&&p->next != NULL)//���ҽڵ�a
			{
				q = p;
				p = p->next;
			}
			if (p->Data == aData)//���нڵ�a
			{
				q->next = s;
				s->next = p;
			}
			else//��û�нڵ�a
			{
				p->next = s;
				s->next = NULL;
			}
		}
	}
}

void list::Deletelist(int aData)//��aData��Ҫɾ���Ľڵ�a�е����ݳ�Ա
{
	Node*p, *q;//p����ָ��a��q����ָ��ڵ�a��ǰһ���ڵ�
	p = head;
	q = NULL;
	if (p == NULL)//���ǿձ�
	{
		return;
	}
	if (p->Data == aData)//��a�ǵ�һ���ڵ�
	{
		head = p->next;
		delete p;
	}
	else
	{
		while (p->Data != aData&&p->next != NULL)//���ҽڵ�a
		{
			q = p;
			p = p->next;
		}
		if (p->Data == aData)
		{
			q->next = p->next;
			delete p;
		}
	}
}