#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

class Hangman
{
	string progress[64];
	string problem;
	string answer;
	string guessed;

	int nTries;
	const int maxTries = 7;

	void load(const char* progName = "HangmanProgress.txt")
	{
		ifstream fs(progName);
		if (fs)
		{
			getline(fs, progress[0]);	
			for (int i = 0; i < 64; i++)
				getline(fs, progress[i]);
		}
	}

	void print() 
	{
		system("cls");
		cout << "     <Hangman Game>\n";
		for (int i = 0; i < 8; i++)
			cout << '\t' << progress[nTries * 8 + i] << endl;
		cout << "\n\t" << answer;
		cout << "\n\n " << guessed;
	}

	int countMatched(char ch) 
	{
		int nMatched = 0;
		for (int pos = -1; ; )
		{
			pos = problem.find(ch, pos + 1);
			if (pos < 0) break;
			answer[pos] = ch;	
			nMatched++;
		}
		return nMatched;
	}

	void guess() 
	{
		char ch = _getch();
		if (ch >= 'a' && ch <= 'z') {
			int pos = guessed.find(ch);
			if (pos < 0) 
			{			
				guessed[ch - 'a'] = ch;	
				if (countMatched(ch) == 0) nTries++; 
			}
		}
	}

	public:

	void play(string prob) 
	{
		load();
		problem = prob;
		answer = string(problem.length(), '-');
		guessed = string(24, '.');			
		nTries = 0;
		while (nTries < maxTries && answer != problem) 
		{
			print();
			guess();
		}
		print();
		cout << "\n\t" << ((nTries == maxTries) ? "실패" : "정답") << endl;
	}
};