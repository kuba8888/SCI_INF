#include<iostream>
#include<cstring>
using namespace std;

class Cipher
{
	public:
		char text[1000];
		int lenght, key;

	void read()
	{
		cout << "Write a message that you want to encrypt or decrypt: ";
		cin.getline(text, 1000);
		lenght = strlen(text);
	}
	void encryptCaesar()
	{
		char ch;
		cout << "Enter the key: ";
		cin >> key;
		if (key <= 0 || key > 26)
		{
			cout << "Invalid number!\n";
			return;
		}

		for (int i = 0; i<lenght;i++)
		{
			ch = text[i];
			if (ch >='a' && ch <='z')
			{
				ch = ((ch -'a' + key)% 26)+'a';
			}
			text[i] = ch;
		}
		printf("Encrypted using caesar cipher: %s \n", text);
	}
	void decryptCaesar()
	{
		char ch;
		cout << "Enter the key: ";
		cin >> key;
		if (key <= 0 || key > 26)
		{
			cout << "Invalid number!\n";
			return;
		}

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
		printf("Decrypted using caesar cipher: %s \n", text);
	}
	void transposition()
	{
		for(int i =0; i<lenght-1; i+=2)
		{
			char ch2;
			ch2 = text[i];
			text[i] = text[i+1];
			text[i+1] = ch2;
			
		}
			printf("Encrypted using transposition cipher: %s \n", text);
	}

};

int main()
{
	int cipherChoice;
	
	Cipher obj;
	obj.read();
	cout << "What do you want to do? \n 1. Encrypt in caesar cipher \n 2. Decrypt caesar cipher \n 3. Encrypt/decrypt in transposition cipher \n 4. Encrypt in both \n";
	cin >> cipherChoice;
	
	switch(cipherChoice)
	{
		case 1:
			obj.encryptCaesar();
			break;
		case 2:
			obj.decryptCaesar();
			break;
		case 3: 
			obj.transposition();
			break;
		case 4:
			obj.encryptCaesar();
			obj.transposition();
			break;
		default: 
			cout << "Invalid number!\n";
			return 0;
	}
}
