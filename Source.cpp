#include<iostream>
# define MAX 5
using namespace std;

class Deque
{
	int arr[MAX] = { 0 }, data, choice = 0, top = -1, front = -1, rear = -1;
public:
	void makeNull();
	bool isFull();
	bool isEmpty();
	void pushRear();
	void pushFront();
	int popFront();
	int popRear();
	void stackDisplay();
	void queueDisplay();
	void stack();
	void queue();
	void mainMenu();
	void dequeMenu();
};

int main() {
	Deque d;
	d.mainMenu();
	return 0;
}

void Deque::mainMenu()
{
	int check = 0;
	while (check != 4)
	{
		system("cls");
		cout << "\n\t\t\t\t\t\t---> Welcome to Mainmenu <---\n\t\t\t\t\t\t";
		cout << "\n\t\t\t\t1.Stack\n\t\t\t\t";
		cout << "\n\t\t\t\t2.Queue\n\t\t\t\t";
		cout << "\n\t\t\t\t3.Deque\n\t\t\t\t";
		cout << "\n\t\t\t\t4.Exit\n\t\t\t\t";
		cout << "\n\t\t\t\t Enter Your Choice :: ";
		cin >> check;
		switch (check)
		{
		case 1:
			stack();
			break;
		case 2:
			queue();
			break;
		case 3:
			dequeMenu();
			break;
		}
	}
}

void Deque::dequeMenu()
{
	makeNull();
	int check = 0;
	while (check != 4)
	{
		system("cls");
		cout << "\n\t\t\t\t\t\t---> Welcome to Deque Menu <---\n\t\t\t\t\t\t";
		cout << "\n\t\t\t\t1.Enqueue\n\t\t\t\t";
		cout << "\n\t\t\t\t2.Dequeue\n\t\t\t\t";
		cout << "\n\t\t\t\t3.Display\n\t\t\t\t";
		cout << "\n\t\t\t\t4.Exit\n\t\t\t\t";
		cout << "\n\t\t\t\t Enter Your Choice :: ";
		cin >> check;
		switch (check)
		{
		case 1:
			if (isFull())
			{
				cout << "\n\t\t\t\tQueue Overflow\n\t\t\t\t";
				system("pause");
			}
			else
			{
				choice = 0;
				while (choice != 3)
				{
					system("cls");
					cout << "\n\t\t\t\t\t\tEnQueue\n\t\t\t\t\t\t";
					cout << "\n\t\t\t\t1.From Rear End\n\t\t\t\t";
					cout << "\n\t\t\t\t2.From Front End\n\t\t\t\t";
					cout << "\n\t\t\t\t3.Back to Deque Menu\n\t\t\t\t";
					cout << "\n\t\t\t\t Enter Your Choice :: ";
					cin >> choice;
					switch (choice)
					{
					case 1:
						if (isFull())
						{
							cout << "\n\t\t\t\tQueue Overflow\n\t\t\t\t";
							system("pause");
							break;
						}
						else
						{
							pushRear();
							choice = 0;
							while (choice != 2)
							{
								system("cls");
								cout << "\n\t\t\t\t EnQueue Successfully";
								if (isFull())
								{
									cout << "\n\t\t\t\tNumber of Max items reached\n\n";
									system("pause");
									choice = 2;
									break;
								}
								cout << "\n\n\t\t\t\t Press 1 . EnQueue Again ";
								cout << "\n\n\t\t\t\t Press 2 . Return Back ";
								cout << "\n\n\t\t\t\t  Enter Your Choice :: ";
								cin >> choice;
								if (choice == 1)
								{
									pushRear();
								}
							}
						}
						break;
					case 2:
						if (isFull())
						{
							cout << "\n\t\t\t\tQueue Overflow\n\t\t\t\t";
							system("pause");
							break;
						}
						else
						{
							pushFront();
							choice = 0;
							while (choice != 2)
							{
								system("cls");
								cout << "\n\t\t\t\t EnQueue Successfully";
								if (isFull())
								{
									cout << "\n\t\t\t\tNumber of Max items reached\n\n";
									system("pause");
									choice = 2;
									break;
								}
								cout << "\n\n\t\t\t\t Press 1 . EnQueue Again ";
								cout << "\n\n\t\t\t\t Press 2 . Return Back ";
								cout << "\n\n\t\t\t\t  Enter Your Choice :: ";
								cin >> choice;
								if (choice == 1)
								{
									pushFront();
								}
							}
						}
						break;
					}
				}
			}
			break;
		case 2:
			if (isEmpty())
			{
				cout << "\n\t\t\t\tQueue underflow\n\t\t\t\t";
				system("pause");
			}
			else
			{
				system("cls");
				cout << "\n\t\t\t\t\t\tDeQueue\n\t\t\t\t\t\t";
				cout << "\n\t\t\t\t1.From Front End\n\t\t\t\t";
				cout << "\n\t\t\t\t2.From Rear End\n\t\t\t\t";
				cout << "\n\t\t\t\t3.Back to Deque Menu\n\t\t\t\t";
				cout << "\n\t\t\t\t Enter Your Choice :: ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					if (isEmpty())
					{
						cout << "\n\t\t\t\tQueue underflow\n\t\t\t\t";
						system("pause");
						break;
					}
					else
					{
						popFront();
						choice = 0;
						while (choice != 2)
						{
							system("cls");
							cout << "\n\n\t\t\t\tDeQueue Successfully";
							if (top == -1)
							{
								choice = 2;
								break;
							}
							cout << "\n\n\t\t\t\t Press 1 . DeQueue Again ";
							cout << "\n\n\t\t\t\t Press 2 . Return Back ";
							cout << "\n\n\t\t\t\t  Enter Your Choice :: ";
							cin >> choice;
							if (choice == 1)
							{
								popFront();
							}
						}
					}
					break;
				case 2:
					if (isEmpty())
					{
						cout << "\n\t\t\t\tQueue underflow\n\t\t\t\t";
						system("pause");
						break;
					}
					else
					{
						popRear();
						choice = 0;
						while (choice != 2)
						{
							system("cls");
							cout << "\n\n\t\t\t\tDeQueue Successfully";
							if (top == -1)
							{
								choice = 2;
								break;
							}
							cout << "\n\n\t\t\t\t Press 1 . DeQueue Again ";
							cout << "\n\n\t\t\t\t Press 2 . Return Back ";
							cout << "\n\n\t\t\t\t  Enter Your Choice :: ";
							cin >> choice;
							if (choice == 1)
							{
								popRear();
							}
						}
					}
					break;
				}
			}
			break;
		case 3:
			queueDisplay();
			break;
		}
	}
}

void Deque::stack()
{
	makeNull();
	int sChoice = 0;
	while (sChoice != 5)
	{
		system("cls");
		cout << "\n\t\t\t\t\t\t---> Welcome to Stack Menu <---\n\t\t\t\t\t\t";
		cout << "\n\t\t\t\t1.Push\n\t\t\t\t";
		cout << "\n\t\t\t\t2.Pop\n\t\t\t\t";
		cout << "\n\t\t\t\t3.Peek\n\t\t\t\t";
		cout << "\n\t\t\t\t4.Display\n\t\t\t\t";
		cout << "\n\t\t\t\t5.Exit\n\t\t\t\t";
		cout << "\n\t\t\t\t Enter Your Choice :: ";
		cin >> sChoice;
		switch (sChoice)
		{
		case 1:
			if (isFull())
			{
				cout << "\n\t\t\t\tStack Overflow\n\t\t\t\t";
				system("pause");
				break;
			}
			else
			{
				pushRear();
				choice = 0;
				while (choice != 2)
				{
					system("cls");
					cout << "\n\t\t\t\t Data Pushed Successfully";
					if (isFull())
					{
						cout << "\n\t\t\t\tNumber of Max items reached\n\n";
						system("pause");
						choice = 2;
						break;
					}
					cout << "\n\n\t\t\t\t Press 1 . Push Again ";
					cout << "\n\n\t\t\t\t Press 2 . Return Back ";
					cout << "\n\n\t\t\t\t  Enter Your Choice :: ";
					cin >> choice;
					if (choice == 1)
					{
						pushRear();
					}
				}
			}
			break;
		case 2:
			if (isEmpty())
			{
				cout << "\n\t\t\t\tStack underflow\n\t\t\t\t";
				system("pause");
				break;
			}
			else
			{
				popRear();
				choice = 0;
				while (choice != 2)
				{
					system("cls");
					cout << "\n\n\t\t\t\tPop Successfully";
					if (top == -1)
					{
						choice = 2;
						break;
					}
					cout << "\n\n\t\t\t\t Press 1 . Pop Again ";
					cout << "\n\n\t\t\t\t Press 2 . Return Back ";
					cout << "\n\n\t\t\t\t  Enter Your Choice :: ";
					cin >> choice;
					if (choice == 1)
					{
						popRear();
					}
				}
				break;
		case 3:
			if (isEmpty())
			{
				cout << "\n\t\t\t\tStack underflow\n\t\t\t\t";
				system("pause");
				break;
			}
			else
			{
				cout << "\n\n\t\t\t\tTop Most Data Item is " << arr[rear] << "\n\n";
				system("pause");
			}
			break;
		case 4:
			stackDisplay();
			break;
			}
		}
	}
}

void Deque::queue()
{
	makeNull();
	int qChoice = 0;
	while (qChoice != 4)
	{
		system("cls");
		cout << "\n\t\t\t\t\t\t---> Welcome to Queue Menu <---\n\t\t\t\t\t\t";
		cout << "\n\t\t\t\t1.EnQueue\n\t\t\t\t";
		cout << "\n\t\t\t\t2.DeQueue\n\t\t\t\t";
		cout << "\n\t\t\t\t3.Display\n\t\t\t\t";
		cout << "\n\t\t\t\t4.Exit\n\t\t\t\t";
		cout << "\n\t\t\t\t Enter Your Choice :: ";
		cin >> qChoice;
		switch (qChoice)
		{
		case 1:
			if (isFull())
			{
				cout << "\n\t\t\t\tQueue Overflow\n\t\t\t\t";
				system("pause");
				break;
			}
			else
			{
				pushRear();
				choice = 0;
				while (choice != 2)
				{
					system("cls");
					cout << "\n\t\t\t\t Enqueue Successfully";
					if (isFull())
					{
						cout << "\n\t\t\t\tNumber of Max items reached\n\n";
						system("pause");
						choice = 2;
						break;
					}
					cout << "\n\n\t\t\t\t Press 1 . Enqueue Again ";
					cout << "\n\n\t\t\t\t Press 2 . Return Back ";
					cout << "\n\n\t\t\t\t  Enter Your Choice :: ";
					cin >> choice;
					if (choice == 1)
					{
						pushRear();
					}
				}
			}
			break;
		case 2:
			if (isEmpty())
			{
				cout << "\n\t\t\t\tQueue underflow\n\t\t\t\t";
				system("pause");
				break;
			}
			else
			{
				popFront();
				choice = 0;
				while (choice != 2)
				{
					system("cls");
					cout << "\n\n\t\t\t\tDeQueue Successfully";
					if (top == -1)
					{
						choice = 2;
						break;
					}
					cout << "\n\n\t\t\t\t Press 1 . DeQueue Again ";
					cout << "\n\n\t\t\t\t Press 2 . Return Back ";
					cout << "\n\n\t\t\t\t  Enter Your Choice :: ";
					cin >> choice;
					if (choice == 1)
					{
						popFront();
					}
				}
			}
			break;
		case 3:
			queueDisplay();
			break;
		}
	}
}

void Deque::makeNull()
{
	arr[0] = {}, choice = 0, top = -1, front = -1, rear = -1;
}

bool Deque::isFull()
{
	if (top == MAX - 1)
		return true;
	else
		return false;
}

bool Deque::isEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
		return false;
}

void Deque::pushRear()
{
	if (isFull())
	{
		cout << "\n\t\t\t\tQueue Overflow\n\t\t\t\t";
		system("pause");
	}
	else
	{
		cout << "\n\t\t\tEnter Data :: ";
		cin >> data;
		if (isEmpty())
		{
			front = 0;
			rear = 0;
		}
		else if (front > 0  && rear == MAX-1)
		{
			rear = 0;
		}
		else
		{
			rear = rear++;
		}
		arr[rear] = data;
		top++;
	}
}

void Deque::pushFront()
{
	if (isFull())
	{
		cout << "\n\t\t\t\tQueue Overflow\n\t\t\t\t";
		system("pause");
	}
	else
	{
		cout << "\n\t\t\tEnter Data :: ";
		cin >> data;
		if (isEmpty())
		{
			front = 0;
			rear = 0;
			arr[front] = data;
		}
		else if (front == 0 && rear < MAX - 1)
		{
			for (int i = rear; i >= front; i--)
			{
				arr[i + 1] = arr[i];
			}
			arr[front] = data;
			rear++;
		}
		else
		{
			front--;
			arr[front] = data;
		}
		top++;
	}
}

int Deque::popFront()
{
	int b;
	if (front == rear)
	{
		b = front;
		front = rear = -1;
	}
	else
	{
		b = front;
		front = front++;
	}
	top--;
	return b;
}

int Deque::popRear()
{
	int c;
	if (front == rear)
	{
		c = front;
		front = rear = -1;
	}
	else
	{
		c = rear;
		rear = rear--;
	}
	top--;
	return c;
}

void Deque::stackDisplay()
{
	if (isEmpty())
	{
		cout << "\n\n\t\t\tStack underflow\n\n";
	}
	else
	{
		system("cls");
		cout << "\n\n\t\t\tTop ---> ";
		for (int i = rear; i >= front; i--)
		{
			cout << arr[i] << "\n\n\t\t\t\t ";
		}
	}
	system("pause");
}

void Deque::queueDisplay()
{
	if (isEmpty())
	{
		cout << "\n\n\t\t\tQueue underflow\n\n";
	}
	else
	{
		if (rear>=front)
		{
			cout << "\n\n\t\t\t Front --->   ";
			for (int i = front; i <= rear; i++)
			{
				cout << arr[i] << "  ";
			}
			cout << " <--- Rear\n\n";
		}
		else
		{
			cout << "\n\n\t\t\t Front --->   ";
			for (int i = front; i <= MAX-1; i++)
			{
				cout << arr[i] << "  ";
			}
			for (int i = 0; i <= rear; i++)
			{
				cout << arr[i] << "  ";
			}
			cout << " <--- Rear\n\n";
		}
	}
	system("pause");
}
