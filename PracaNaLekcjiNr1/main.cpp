#include<iostream>
#include<cstring>
using namespace std;

class cipher
{
	public:
		char text[1000],ch;
		int lenght;
	void read()
	{
		cout << "Write a message that you want to encrypt: ";
		cin.getline(text, 1000);
		lenght = strlen(text);
	}
	void encrypt()
	{
		for (int i = 0; i<lenght;i++)
		{
			ch = text[i];
			if (ch >='a' && ch <='z')
			{
				ch = ch + 13;
			}
			if (ch > 'z')
			{
				ch = ch - 'z' + 'a' - 1;
			}
			text[i] = ch;
		}
		printf("Encrypted message: %s \n", text);
	}

};



int main()
{
	cipher obj;
	obj.read();
	obj.encrypt();
	return 0;
}
