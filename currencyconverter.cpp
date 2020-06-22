#include <iostream>
using namespace std;

string ones[] = { "", "one ", "two ", "three ", "four ",
				"five ", "six ", "seven ", "eight ",
				"nine ", "ten ", "eleven ", "twelve ",
				"thirteen ", "fourteen ", "fifteen ",
				"sixteen ", "seventeen ", "eighteen ",
				"nineteen " };


string tens[] = { "", "", "twenty ", "thirty ", "forty ",
				"fifty ", "sixty ", "seventy ", "eighty ",
				"ninety " };


string numconverter(int n, string s)
{
	string arr = "";

	if (n > 19)
		arr += tens[n / 10] + ones[n % 10];
	else
		arr += ones[n];


	if (n)
		arr += s;

	return arr;
}



string wordconverter(long n)
{

	string say;


	say += numconverter((n / 10000000), "crore ");


	say += numconverter(((n / 100000) % 100), "lakh ");


	say += numconverter(((n / 1000) % 100), "thousand ");


	say += numconverter(((n / 100) % 10), "hundred ");

	if (n > 100 && n % 100)
		say += "and ";


	say += numconverter((n % 100), "");

	return say;
}

int main()
{

	long n;
	char again;

q:	cout<<"\nEnter the amount (max 9 digit)"<<endl<<"\t";
	cin>>n;

	cout<<wordconverter(n);

	cout<<"\nWant to try for another amount ? (Y/N)"<<endl;
	cin>>again;

	if(again=='Y' || again=='y')
	{
	   goto q;
	}

	else if(again=='N' || again=='n')
	{
	  cout<<"\n\t *Thank You*"<<endl;
	}

	else
	{

	   cout<<"\nWrong input by user";
	   exit (0);
    }


	return 0;
}