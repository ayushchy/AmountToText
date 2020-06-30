#include <iostream>
#include <math.h>
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


string onesHindi[] = {"", "एक ", "दो ", "तीन ", "चार ", "पाँच ", "छह ", "सात ", "आठ ", "नौ ", "दस ", 
    "ग्यारह ", "बारह ", "तेरह ", "चौदह  ", "पन्द्रह ", "सोलह ", "सत्रह ", "अठारह ", "उन्नीस ", "बीस ", 
    "इक्कीस ", "बाईस ", "तेईस ", "चौबीस ", "पच्चीस ", "छब्बीस ", "सत्ताईस ", "अट्ठाईस ", "उनतीस ", "तीस ", 
    "इकतीस ", "बत्तीस ", "तैंतीस ", "चौंतीस ", "पैंतीस ", "छत्तीस ", "सैंतीस ", "अड़तीस ", "उनतालीस ", "चालीस ", 
    "इकतालीस ", "बयालीस ", "तैंतालीस ", "चौवालीस ", "पैंतालीस ", "छियालीस ", "सैंतालीस ", "अड़तालीस ", "उनचास ", "पचास ", 
    "इक्यावन ", "बावन ", "तिरेपन ", "चौवन ", "पचपन ", "छप्पन ", "सत्तावन ", "अट्ठावन ", "उनसठ ", "साठ ", 
    "इकसठ ", "बासठ ", "तिरेसठ ", "चौंसठ ", "पैंसठ ", "छियासठ ", "सड़सठ ", "अड़सठ ", "उनहत्तर ", "सत्तर ", 
    "इकहत्तर ", "बहत्तर ", "तिहत्तर ", "चौहत्तर ", "पचहत्तर ", "छिहत्तर ", "सतहत्तर ", "अठहत्तर ", "उनासी ", "अस्सी ",
    "इक्यासी ", "बयासी ", "तिरासी ", "चौरासी ", "पचासी ", "छियासी ", "सत्तासी ", "अट्ठासी ", "नवासी ", "नब्बे ",
    "इक्यानबे ", "बानबे ", "तिरानबे ", "चौरानबे ", "पंचानबे ", "छियानबे ", "सत्तानबे ", "अट्ठानबे ", "निन्यानबे "};


string numconverterHindi(int n, string s)
{
	string arr = "";

	if (n > 99)
		arr += onesHindi[n / 10] + onesHindi[n % 10];
	else
		arr += onesHindi[n];


	if (n)
		arr += s;

	return arr;
}



string wordconverterHindi(long n)
{

	string say;


	say += numconverterHindi((n / 10000000), "करोड़ ");


	say += numconverterHindi(((n / 100000) % 100), "लाख ");


	say += numconverterHindi(((n / 1000) % 100), "हज़ार ");


	say += numconverterHindi(((n / 100) % 10), "सौ ");

	if (n > 100 && n % 100)
		say += "";


	say += numconverterHindi((n % 100), "");

	return say;
}

int main()
{

	long double n;
	char again;
	char x;

q:	cout<<"\nEnter the amount (max 9 digit)"<<endl<<"\t";
	cin>>n;

pt: cout<<"Enter Language (h)Hindi (e)English";
	cin>>x;
	if (x == 'h' || x == 'H')
	{
		cout<<wordconverterHindi(n);
		double x = n;
		double y = fmod(x,1);
		if(y!=0)
			cout<<y*100<<"/100";
	}

	else if (x == 'e' || x == 'E')
	{
		cout<<wordconverter(n);
		double x = n;
		double y = fmod(x,1);
		if(y!=0)
			cout<<y*100<<"/100";
	}

	else 
	{
		cout<<"Wrong input ";
		goto pt;
	}

	cout<<"\nWant to try for another amount ? (Y/N)"<<endl;
	cin>>again;

	if(again=='Y' || again=='y')
	{
	    cout<<"\n___________________________________________________";
	    goto q;
	}

	else if(again=='N' || again=='n')
	{
	  cout<<"\n___________________________Thank You_________________________"<<endl;
	}

	else
	{

	   cout<<"\nWrong input by user";
	   exit (0);
    }


	return 0;
}
