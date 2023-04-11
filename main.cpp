#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//������'����� (������) ������
//���������

template<typename T>
class List
{
public:
	List();
	~List();
	//��������� ������:
	void pop_front(); //��������� ������� �������� � ������
	void clear(); //��������� ��� �������� � ������
	void push_back(T data); //�������� ������ ������� � ����� ������
	int GetSize() { return Size; } //�����, �� �������� ������� �������� ������
	T& operator[](const int index); //������ �� ����������� �������� ������

	void push_front(T data); //��������� �������� �� ������� ������
	void insert(T value, int index); //��������� �������� � ��������� ���� � ������
	void removeAt(int index); //��������� �������� � ����������� ���� ������
	void pop_back(); //��������� ���������� �������� ������

private:
	
	template<typename T> //��������� ���� (������ � ���� ������ ������)
	class Node 
	{
	public:
		Node *pNext;
		T data;

		Node(T data = T(), Node *pNext = nullptr) //�����������
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List() //����������
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;

	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;

		while (current->pNext != nullptr) 
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}

//����� �������� ����������� �������� ������
template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T value, int index)
{
	if (index==0)
	{
		push_front(value);
	}
	else
	{
		Node<T> *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(value, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

int main() 
{
	setlocale(LC_ALL, "ukr");

	string path = "myFile.txt";

	List<string> lst;
	int numbersCount; //ʳ������ �������� ������
	/*cin >> numbersCount;*/
	lst.push_back("Lviv");
	lst.push_back("Kyiv");
	lst.push_back("Chernihiv");
	lst.push_back("Irpin");
	//��������� ������� �������� ������
	/*lst.GetSize();*/

	//���� ��� �������� ������
	cout << "�������� ������: " << endl;
	for (size_t i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	////���������� ������ ����������� �������
	//for (int i = 0; i < numbersCount; i++)
	//{
	//	lst.push_back(rand() % 10);
	//}

	//��������� �������� �� ������� ������� � ���������:
	int addElement;
	cout << "����i�� i����� ��������, ���� ����� ������: ";
	cin >> addElement;
	string information;
	cout << "����i�� i�������i� � ������� �������: ";
	cin >> information;
	lst.insert(information, addElement);

	//��������� �������� �� ������� ������� � ���������:
	int deleteElement;
	cout << "����i�� i����� ��������, ���� ����� ��������: ";
	cin >> deleteElement;
	lst.removeAt(deleteElement);

	/*cout << lst.GetSize() << endl;

	cout << lst[2] << endl;*/

	//��������� �� ����� ����������, ��� ���������� � �������� �������:
	int findElement;
	cout << "����i�� i����� ��������, ���� ����� ������: ";
	cin >> findElement;
	cout << lst[findElement] << endl;

	//���� ��� �������� ������
	cout << "�������� ������: " << endl;
	for (size_t i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	return 0;
}