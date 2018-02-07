#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	string key, message;

	cout << "Your message: " << endl;
	getline(cin, message);
	cout << "Your key: " << endl;
	getline(cin, key);

	int keyLength = key.length();
	for (int i = keyLength; i < message.length(); i++)
	{
		key += key[i % keyLength];
	}
	cout << "Your key: " << key << endl;

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

	string encrypted;
	for (int i = 0; i < key.length(); i++)
	{
		int column, row;
		for (int j = 0; j < sizeof(vigenereSquare[0]); j++)
		{
			if (vigenereSquare[0][j] == message.at(i))
			{
				column = j;
			}
			if (vigenereSquare[0][j] == key.at(i))
			{
				row = j;
			}
		}
		encrypted += vigenereSquare[row][column];
	}
	cout << "Your encrypted: " << encrypted << endl;

	string deciphered;
	for (int i = 0; i < key.length(); i++)
	{
		for (int j = 0; j < sizeof(vigenereSquare[0]); j++)
		{
			if (vigenereSquare[j][0] == key.at(i))
			{
				for (int k = 0; k < sizeof(vigenereSquare[0]); k++)
				{
					if (vigenereSquare[j][k] == encrypted.at(i))
					{
						deciphered += vigenereSquare[0][k];
					}
				}
			}
		}
	}
	cout << "Your deciphered: " << deciphered << endl;

	system("pause");
}