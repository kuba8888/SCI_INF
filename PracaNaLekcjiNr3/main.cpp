#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<math.h>
using namespace std;

class Cipher
{
	public:
		char text[1000];
		int lenght, key;
		int primeNumbers[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
		int n, d, e;
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

		for (int i = 0; i < lenght; i++)
		{
			ch = text[i];
			if (ch >= 'a' && ch <= 'z')
			{
				ch = ((ch - 'a' + key)% 26) + 'a';
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

		for (int i = 0; i < lenght; i++)
		{
			ch = text[i];
			if (ch >= 'a' && ch <= 'z')
			{
				ch = ((ch - 'a' + (26 - key))% 26) + 'a';
			}

			text[i] = ch;
		}
		printf("Decrypted using caesar cipher: %s \n", text);
	}

	void transposition()
	{
		for(int i = 0; i < lenght - 1; i += 2)
		{
			char ch2;
			ch2 = text[i];
			text[i] = text[i+1];
			text[i+1] = ch2;
			
		}
			printf("Encrypted using transposition cipher: %s \n", text);
	}

	void RsaKeyGen()
	{
		srand(time(NULL));
		int x = rand()%24;
		int p = primeNumbers[x];
		int q = primeNumbers[x+1];
		int n = p*q;
		int phi = (p-1)*(q-1);
		int e = 2;
		int d = 2;
		while(e < phi)
		{
			if(euklides(e, phi) == 1)
				break;
			else
				e++;
		}
		while(d*e%phi != 1)
		{
			d++;
		}
		this -> n = n;
		this -> d = d;
		this -> e = e;
	}
	int euklides(int a, int b)
	{	
		while (a != b)
		{
			if (a < b)
				b -= a;
			else
				a -= b;
		}
		return a;
	}

	void printRsa()
	{
		cout << "public key " << "n: " <<  n << " " << "e: " << e << endl;
		cout << "private key " << "n: " << n << " " << "d: " << d << endl;
	}

	int powMod ( int a, int w, int n )
	{
		int pow, res, q;

		pow = a; 
		res = 1;

		for( q = w; q > 0; q /= 2 )
		{
			if( q % 2 ) res = ( res * pow ) % n;
			pow = ( pow * pow ) % n; 
		}

		return res;
	}

	void rsaCoding()
	{
		int msg, result, e, n;
		cout << "Write a number that you want to encrypt: ";
		cin >> msg;
		cout << "Write e: ";
		cin >> e;
		cout << "write n: ";
		cin >> n;
		cout << "encrypted message: " << powMod(msg, e, n) << endl; 
	}

	void rsaDecoding()
	{
		int msg, result, d, n;
		cout << "Write a number that you want to encrypt: ";
		cin >> msg;
		cout << "Write d: ";
		cin >> d;
		cout << "write n: ";
		cin >> n;
		cout << "decrypted message: " << int(pow(msg, d))%n; 
	}

};

int main()
{
	int cipherChoice;
	Cipher obj;
	obj.read();
	cout << "What do you want to do? \n";
	cout <<	"1. Encrypt in caesar cipher \n";
	cout <<	"2. Decrypt caesar cipher \n"; 
	cout <<	"3. Encrypt/decrypt in transposition cipher \n"; 
	cout <<	"4. Encrypt in both \n";
	cout << "5. Generate RSA keys \n";
	cout << "6. Encrypt int using rsa \n";
	cout << "7. Decrypt int using rsa \n";
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
		case 5:
			obj.RsaKeyGen();
			obj.printRsa();
			break;
		case 6:
			obj.RsaKeyGen();
			obj.printRsa();
			obj.rsaCoding();
			break;
		case 7:
			obj.rsaDecoding();
		default: 
			cout << "Invalid number!\n";
			return 0;
	}
}


