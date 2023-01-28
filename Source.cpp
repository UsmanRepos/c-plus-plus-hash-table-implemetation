#include<iostream>
#define TABLE_S 10
using namespace std;

class Hash_TableEntry
{

public:
	int element_key;
	int element_value;

	Hash_TableEntry(int k, int v):element_key(k),element_value(v){}
};

class Hash_MapTable
{
	Hash_TableEntry** table;
public:
	Hash_MapTable()
	{
		table = new Hash_TableEntry*[TABLE_S];

		for (int i = 0; i < TABLE_S; i++)
			table[i] = NULL;
	}

	int Hash_Function(int k)
	{
		return (k % TABLE_S);
	}

	~Hash_MapTable()
	{
		for (int i = 0; i < TABLE_S; i++)
		{
			if (table[i] != NULL)
				delete table[i];
			delete[] table;
		}
	}

	void Insert_value(int k, int v);
	int  Search_value(int k);
	void Remove_value(int k);
	void Display_values()const;

};
void Hash_MapTable::Insert_value(int k, int v)
{
	int  hash_index = Hash_Function(k);
	bool flag = false;
	int  count = 0;

	while (table[hash_index] != NULL )
	{
		if (table[hash_index]->element_key == k)
			break;

		if (count >= TABLE_S -1)
		{
			flag = true;
			break;
		}

		hash_index = Hash_Function(hash_index + 1);
		count++;
	}
	if (!flag)
	{
		if (table[hash_index] != NULL)
			delete table[hash_index];

		table[hash_index] = new Hash_TableEntry(k, v);
	}
	else
		cout << "Table Storage is Full ...!!!!!!\n\n";
}

int Hash_MapTable::Search_value(int k)
{

	int  hash_index = Hash_Function(k);

	while (table[hash_index] != NULL )
	{
		if (table[hash_index]->element_key == k)
			break;
		hash_index = Hash_Function(hash_index + 1);
	}

	if (table[hash_index] == NULL)
		return -1;
	else
		return table[hash_index]->element_value;
}

void Hash_MapTable::Remove_value(int k)
{
	int hash_index = Hash_Function(k);

	while (table[hash_index] != NULL)
	{
		if (table[hash_index]->element_key == k)
			break;
		hash_index = Hash_Function(hash_index + 1);
	}

	if (table[hash_index] == NULL)
	{
		cout << "No Element found at key " << k << endl;
		return;
	}
	else
	{
		delete table[hash_index];
	}

	cout << "Element Deleted" << endl;
}
void Hash_MapTable::Display_values()const
{
	int i = 0;
	cout << "Table Elements: ";
	while (i < TABLE_S)
	{
		if (table[i] != NULL)
			cout << table[i]->element_value << " ";
		i++;
	}
	cout << endl;
}
int main()
{
	Hash_MapTable obj;
	int value, key, s_d;
	int ch;
	
	while (true)
	{
		system("cls");
		cout << "-----------(MAIN MENU)-----------\n";
		cout << "1) INSERTION \n";
		cout << "2) SEARCHING \n";
		cout << "3) DELETION \n";
		cout << "4) DISPLAY\n";
		cout << "5) Exit \n\n";
		cout << "Enter choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "Enter Value: ";
			cin >> value;
			cout << "Enter Key: ";
			cin >> key;

			obj.Insert_value(key, value);
			break;
		case 2:
			cout << "Enter Key: ";
			cin >> key;
			s_d = obj.Search_value(key);
			if (s_d != -1)
				cout << "Search Data is " << s_d << endl;
			else
				cout << "Search Not Found....!!!\n";
			system("PAUSE");
			break;
		case 3:
			cout << "Enter Key: ";
			cin >> key;
			obj.Remove_value(key);
			system("PAUSE");
			break;
		case 4:
			obj.Display_values();
			system("PAUSE");
			break;
		case 5:
			exit(-1);
		}
	}
	system("pause");
}



