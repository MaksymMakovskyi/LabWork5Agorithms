#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Однозв'язний (лінійний) список
//реалізація

template<typename T>
class List
{
public:
	List();
	~List();
	//Прототипи методів:
	void pop_front(); //Видалення першого елементу зі списку
	void clear(); //Видалення всіх елементів зі списку
	void push_back(T data); //Прототип методу вставки в кінець списку
	int GetSize() { return Size; } //Метод, що виводить кількість елементів списку
	T& operator[](const int index); //Доступ до конкретного елементу списку

	void push_front(T data); //Додавання елементу на початок списку
	void insert(T value, int index); //Додавання елементу в конкретне місце в списку
	void removeAt(int index); //Видалення елементу в конкретному місці списку
	void pop_back(); //Видалення останнього елементу списку

private:
	
	template<typename T> //Шаблонний клас (працює з усіма типами данних)
	class Node 
	{
	public:
		Node *pNext;
		T data;

		Node(T data = T(), Node *pNext = nullptr) //Конструктор
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
List<T>::~List() //Деструктор
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

//Пошук значення конкретного елементу списку
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
	int numbersCount; //Кількість елементів списку
	/*cin >> numbersCount;*/
	lst.push_back("Lviv");
	lst.push_back("Kyiv");
	lst.push_back("Chernihiv");
	lst.push_back("Irpin");
	//Виведення кількості елементів списку
	/*lst.GetSize();*/

	//Вивід всіх елементів списку
	cout << "Елементи списку: " << endl;
	for (size_t i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	////Заповнення списку випадковими числами
	//for (int i = 0; i < numbersCount; i++)
	//{
	//	lst.push_back(rand() % 10);
	//}

	//Додавання елементу із заданим номером у структури:
	int addElement;
	cout << "Введiть iндекс елемента, який треба додати: ";
	cin >> addElement;
	string information;
	cout << "Введiть iнформацiю в доданий елемент: ";
	cin >> information;
	lst.insert(information, addElement);

	//Видалення елементу із заданим номером зі структури:
	int deleteElement;
	cout << "Введiть iндекс елемента, який треба видалити: ";
	cin >> deleteElement;
	lst.removeAt(deleteElement);

	/*cout << lst.GetSize() << endl;

	cout << lst[2] << endl;*/

	//Виведення на екран інформації, яка зберігається в заданому елементі:
	int findElement;
	cout << "Введiть iндекс елемента, який треба знайти: ";
	cin >> findElement;
	cout << lst[findElement] << endl;

	//Вивід всіх елементів списку
	cout << "Елементи списку: " << endl;
	for (size_t i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	return 0;
}