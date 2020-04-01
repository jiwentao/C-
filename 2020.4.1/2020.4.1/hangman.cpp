#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
const int NUM = 26;
const string wordlist[NUM] = { "apiary","beetle","cereal",
	"danger","ensign","florid","garage","health","insult",
	"jackal","keeper","loaner","manage","nonce","onset",
	"plaid","quilt","remote","stolid","train","useful",
	"valid","whence","xenon","yearn","zippy"};
int main()
{
	srand(time(0));
	char play;
	cout << "Will you paly a word game? <y/n> ";
	cin >> play;
	play = tolower(play);
	while(play == 'y')
	{
		string target = wordlist[rand() % NUM];
		int lenth = target.length();
		string attempt(lenth,'-');
		string badchars;
		int guesses = 6;
		cout << "Guesses my secret word. It has " << lenth
			<< " letters, and you guess\n"
		    << "one letter at a time.You get " << guesses
			<< " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while(guesses > 0 && target != attempt)
		{
			char letter;
			cout << "Guesses a letter: ";
			cin >> letter;
			if(badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos)
			{
				cout << "You already guesses that. Try again!\n";
				continue;
			}
			int loc = attempt.find(letter);
			if(loc == string::npos)
			{
				cout << "Oh, bad guesses!\n";
				guesses--;
				badchars += letter;
			}
			else
			{
				cout << "Good guesses!\n";
				attempt[loc] = letter;
				loc = target.find(letter,loc+1);
				while(loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter,loc+1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if(attempt != target)
			{
				if(badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl; 
				cout << guesses << " bad guesses left\n";
			}
		}
		if(guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";
		cout << "Will you play another? <y/n> ";
		cin >> play;
		tolower(play);
	}
	cout << "Bye\n";
	return 0;
}