#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#pragma comment(lib, "urlmon.lib")
using namespace std;

int main()
{
	setlocale(0, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	// the URL to download from 
	string srcURL2 = "https://api.privatbank.ua/p24api/pubinfo?exchange&coursid=5";
	string srcURL3 = "https://bank.gov.ua/NBUStatService/v1/statdirectory/exchange?json";
	// the destination file 
	string destFile = "National Bank.txt";
	//// URLDownloadToFile returns S_OK on success 
	if (S_OK == URLDownloadToFileA(NULL, srcURL3.c_str(), destFile.c_str(), 0, NULL))
	{
		cout << "Saved to " << destFile << "\n";
	}
	else cout << "Mistake\n";
	fstream File_ex;
	File_ex.open("National Bank.txt");
	string buf;
	while (true)
	{
		if (File_ex.eof())
			break;
		else
		{
			getline(File_ex, buf);
			if (buf.find(":978") != -1)
			{
				cout << "Evro: ";
				for (int i = buf.find(":978") + 29; buf[i] != ','; i++)
					cout << buf[i];
				cout << " grn" << endl;
			}
			if (buf.find(":840") != -1)
			{
				cout << "Dollars: ";
				for (int i = buf.find(":840") + 38; buf[i] != ','; i++)
					cout << buf[i];
				cout << " grs" << endl;
			}

		}
	}
	File_ex.close();
	string dest2File = "Privatbank24.txt";
	if (S_OK == URLDownloadToFileA(NULL, srcURL2.c_str(), dest2File.c_str(), 0, NULL))
	{
		cout << "\nSaved to " << dest2File << "\n";
	}
	else cout << "Mistake!\n";
	File_ex.open("Privatbank24.txt");
	while (true)
	{
		if (File_ex.eof())
			break;
		else
		{
			getline(File_ex, buf);
			if (buf.find("EUR") != -1)
			{
				cout << "Evro:Buy = ";
				for (int i = buf.find("EUR") + 29; buf[i + 1] != ','; i++)
					cout << buf[i];
				cout << "grn;";
				cout << " sell = ";
				for (int i = buf.find("EUR") + 29; buf[i + 1] != ','; i++)
					cout << buf[i];
				cout << " grn" << endl;
			}
			if (buf.find("USD") != -1)
			{
				cout << "Dollar:Buy = ";
				for (int i = buf.find("USD") + 29; buf[i + 1] != ','; i++)
					cout << buf[i];
				cout << "grn;";
				cout << " sell = ";
				for (int i = buf.find("USD") + 29; buf[i + 1] != ','; i++)
					cout << buf[i];
				cout << "grn" << endl;
			}
		}
	}
}