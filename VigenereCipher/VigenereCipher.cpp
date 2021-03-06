#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string encryption(char vigenereSquare[90][90], string key, string message)
{
	string encryptedMsg;
	for (int i = 0; i < key.length(); i++)
	{
		for (int row = 0; row < sizeof(vigenereSquare[0]); row++)
		{
			for (int column = 0; column < sizeof(vigenereSquare[0]); column++)
			{
				if (vigenereSquare[0][column] == message.at(i) && vigenereSquare[row][0] == key.at(i))
				{
					encryptedMsg += vigenereSquare[row][column];
				}
			}
		}
	}
	return encryptedMsg;
}

string decryption(char vigenereSquare[90][90], string key, string encryptedMsg)
{
	string decryptedMsg;
	for (int i = 0; i < key.length(); i++)
	{
		for (int row = 0; row < sizeof(vigenereSquare[0]); row++)
		{
			for (int column = 0; column < sizeof(vigenereSquare[0]); column++)
			{
				if (vigenereSquare[row][0] == key.at(i) && vigenereSquare[row][column] == encryptedMsg.at(i))
				{
					decryptedMsg += vigenereSquare[0][column];
				}
			}
		}
	}
	return decryptedMsg;
}

string keyUpdater (string key, int messageLength)
{
	int keyLength = key.length();
	if (keyLength > messageLength)
	{
		for (int i = keyLength; i > messageLength; i--)
		{
			key.pop_back();
		}
		return key;
	}
	else
	{
		for (int i = keyLength; i < messageLength; i++)
		{
			key += key[i % keyLength];
		}
		return key;
	}
}

void main()
{
	string key, message;

	cout << "Your message: " << endl;
	getline(cin, message);
	cout << "Your key: " << endl;
	getline(cin, key);

	key = keyUpdater(key, message.length());
	cout << "Your full key: " << key << endl;

	char vigenereSquare[90][90];
	for (int i = 0; i < 90; i++)
	{
		for (int j = 0; j < 90; j++)
		{
			vigenereSquare[i][j] = ' ' + (i + j) % 90;
			cout << vigenereSquare[i][j] << " ";
		}
		cout << endl;
	}
	 
	string encryptedMsg = encryption(vigenereSquare, key, message);
	cout << "Your encrypted: " << encryptedMsg << endl;

	string decryptedMsg = decryption(vigenereSquare, key, encryptedMsg);
	cout << "Your deciphered: " << decryptedMsg << endl;

	system("pause");
}