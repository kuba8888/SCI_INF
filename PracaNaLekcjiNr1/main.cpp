#include<iostream>
#include<cstring>
using namespace std;

class cipher
{
	public:
		char text[1000];
		int lenght;
		int key = 27;
	void read()
	{
		cout << "Write a message that you want to encrypt: ";
		cin.getline(text, 1000);
		lenght = strlen(text);
	}
	void encryptCaesar()
	{
		char ch;
		for (int i = 0; i<lenght;i++)
		{
			ch = text[i];
			if (ch >='a' && ch <='z')
			{
				ch = ((ch -'a' + key)% 26)+'a';
			}
			text[i] = ch;
		}
		printf("Encrypted message: %s \n", text);
	}
	void decryptCaesar()
	{
		char ch;
		for (int i = 0; i<lenght;i++)
		{
			ch = text[i];
			if (ch >='a' && ch <='z')
			{
				ch = ch - key;
			}
			if (ch < 'a')
			{
				ch = ch + 'z' - 'a' + 1;
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
	obj.encryptCaesar();
	obj.read();
	obj.decryptCaesar();
	return 0;
}
