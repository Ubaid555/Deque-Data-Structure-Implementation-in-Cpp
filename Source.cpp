#include<iostream>
# define MAX 5
using namespace std;

class Deque
{
	int data, count = 0, choice = 0;
	Deque* front = NULL;
	Deque* rear = NULL;
	Deque* lptr = NULL;
	Deque* rptr = NULL;
public:
	void makeNull();
	bool isFull();
	bool isEmpty();
	void pushRear();
	void pushFront();
	void popFront();
	void popRear();
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
		cout << "\n\t\t\t\t4.Return to MainMenu\n\t\t\t\t";
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
							cout << "\n\t\t\t\tStack Overflow\n\t\t\t\t";
							system("pause");
							break;
						}
						else
						{
							pushRear();
							rear->rptr = front;
							front->lptr = rear;
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
									rear->rptr = front;
									front->lptr = rear;
								}

							}
						}
						break;
					case 2:
						if (isFull())
						{
							cout << "\n\t\t\t\tStack Overflow\n\t\t\t\t";
							system("pause");
							break;
						}
						else
						{
							pushFront();
							rear->rptr = front;
							front->lptr = rear;
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
									pushFront();
									rear->rptr = front;
									front->lptr = rear;
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
				choice = 0;
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
						if (isEmpty())
						{
							cout << "\n\n\t\t\t\tDeQueue Successfully\n\n";
							system("pause");
							break;
						}
						else
						{
							rear->rptr = front;
							front->lptr = rear;
						}
						choice = 0;
						while (choice != 2)
						{
							system("cls");
							cout << "\n\n\t\t\t\tDeQueue Successfully\n\n";
							if (isEmpty())
							{
								system("pause");
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
								if (rear != NULL)
								{
									rear->rptr = front;
									front->lptr = rear;
								}
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
						if (isEmpty())
						{
							cout << "\n\n\t\t\t\tDeQueue Successfully\n\n";
							system("pause");
							break;
						}
						else
						{
							rear->rptr = front;
							front->lptr = rear;
						}
						choice = 0;
						while (choice != 2)
						{
							system("cls");
							cout << "\n\n\t\t\t\tDeQueue Successfully\n\n";
							if (isEmpty())
							{
								system("pause");
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
								if (rear != NULL)
								{
									rear->rptr = front;
									front->lptr = rear;
								}
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
		cout << "\n\t\t\t\t5.Return to MainMenu\n\t\t\t\t";
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
					cout << "\n\n\t\t\t\tPop Successfully\n\n";
					if (isEmpty())
					{
						system("pause");
						choice = 2;
						break;
					}
					cout << "\t\t\t\tItems remaining is ---> " << count;
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
				cout << "\n\n\t\t\t\tTop Most Data Item is " << rear->data << "\n\n";
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
		cout << "\n\t\t\t\t4.Return to MainMenu\n\t\t\t\t";
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
				rear->rptr = front;
				front->lptr = rear;
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
						rear->rptr = front;
						front->lptr = rear;
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
				if (rear == NULL)
				{
					cout << "\n\n\t\t\t\tDeQueue Successfully\n\n";
					system("pause");
					break;
				}
				else
				{
					rear->rptr = front;
					front->lptr = rear;
				}
				choice = 0;
				while (choice != 2)
				{
					system("cls");
					cout << "\n\n\t\t\t\tDeQueue Successfully\n\n";
					if (isEmpty())
					{
						system("pause");
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
						if (rear != NULL)
						{
							rear->rptr = front;
							front->lptr = rear;
						}
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

bool Deque::isEmpty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Deque::isFull()
{
	if (count == MAX)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Deque::makeNull()
{
	data, count = 0, choice = 0;
	front = NULL, rear = NULL, lptr = NULL, rptr = NULL;
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
		Deque* newQueue = new Deque;
		cout << "\n\t\t\tEnter Data :: ";
		cin >> newQueue->data;
		if (isEmpty())
		{
			front = newQueue;
			rear = newQueue;
		}
		else
		{
			rear->rptr = newQueue;
			newQueue->lptr = rear;
			rear = newQueue;
		}
		count++;
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
		Deque* newQueue = new Deque;
		cout << "\n\t\t\tEnter Data :: ";
		cin >> newQueue->data;
		if (isEmpty())
		{
			front = newQueue;
			rear = newQueue;
		}
		else
		{
			front->lptr = newQueue;
			newQueue->rptr = front;
			front = newQueue;
		}
		count++;
	}
}

void Deque::popFront()
{
	if (isEmpty())
	{
		cout << "\n\t\t\t\tQueue underflow\n\t\t\t\t";
		system("pause");
	}
	else
	{
		if (rear == front)
		{
			front = rear = NULL;
		}
		else
		{
			front = front->rptr;
			front->lptr = NULL;
		}
		count--;
	}
}

void Deque::popRear()
{
	if (isEmpty())
	{
		cout << "\n\t\t\t\tQueue underflow\n\t\t\t\t";
		system("pause");
	}
	else
	{
		if (rear == front)
		{
			front = rear = NULL;
		}
		else
		{
			rear = rear->lptr;
			rear->rptr = NULL;
		}
		count--;
	}
}

void Deque::stackDisplay()
{
	if (isEmpty())
	{
		cout << "\n\n\t\t\tStack underflow\n\n";
		system("pause");
	}
	else
	{
		Deque* temp = rear;
		system("cls");
		cout << "\n\n\t\t\tTop ---> ";
		while (temp != NULL)
		{
			cout << temp->data << "\n\n\t\t\t\t ";
			temp = temp->lptr;
		}
		system("pause");
	}
}

void Deque::queueDisplay()
{
	if (isEmpty())
	{
		cout << "\n\n\t\t\tQueue underflow\n\n";
	}
	else
	{
		Deque* temp = front;
		int c = 0;
		cout << "\n\n\t\t\t Front  ";
		while (c != count)
		{
			cout << " ---> " << temp->data;
			temp = temp->rptr;
			c++;
		}
		cout << "   <--- Rear\n\n";
	}
	system("pause");
}
