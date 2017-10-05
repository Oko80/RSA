#include<iostream>
#include<math.h>
#include<string>
#include<stdlib.h>
#include<ctime>
#include<fstream>

using namespace std;



long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;

string msg;

string input = "";

int prime(long int);

int PrimeOnown(long int);

void ce();



long int cd(long int);

void encrypt();

void decrypt();

int prime(long int pr)

{

	int i;

	j = sqrt(pr);

	for (i = 2; i <= j; i++)

	{

		if (pr % i == 0)

			return 0;

	}

	return 1;

}

int PrimeOnown(long int pr)

{

	int i;
	int count = 0;
	j = sqrt(pr);

	for (i = 2; i <= j; i++)

	{

		if (pr % i == 0)

			count++;

	}
	if (count == 0) {
		
		

		return 1;
		
	}

	else {
		
		return PrimeOnown(pr + 1);
	}
	

}

int main()

{
	
	cout << "Welcome to RSA Encryption Algorithm Service!" << endl;
	cout << "Do you need any prime numbers ?" << endl;
	cout << "Write yes or no for answer."<< endl;
	cin >> input;
	if (input == "no"|| input== "NO") {
		cout << "\nENTER FIRST PRIME NUMBER\n";

		cin >> p;
		flag = prime(p);
		while (flag == 0) {




			cout << "\nWRONG INPUT!!\n";

			cout << "Try again!! "
				"\nENTER FIRST PRIME NUMBER\n" << endl;
			cin >> p;
			flag = prime(p);


		}

		cout << "\nENTER ANOTHER PRIME NUMBER\n";

		cin >> q;

		flag = prime(q);

		while (flag == 0) {




			cout << "\nWRONG INPUT!!\n";

			cout << "Try again!! "
				"\nENTER ANOTHER PRIME NUMBER\n" << endl;
			cin >> p;
			flag = prime(p);


		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nENTER MESSAGE\n";

		getline(cin, msg);

		

		for (i = 0; msg[i] != NULL ; i++)

			m[i] = msg[i];

		n = p * q;

		t = (p - 1) * (q - 1);

		ce();

		cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";

		for (i = 0; i < j - 1; i++)

			cout << e[i] << "\t" << d[i] << "\n";

		encrypt();

		decrypt();

		
	}
	else if(input == "yes" || input=="YES"){
		int p = 0;
		int q = 0;
		
		
			p = (rand()%255);
			 PrimeOnown(p);
			q = (rand() % 255);
			 PrimeOnown(q);
			 

			 cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			 cout << "\nENTER MESSAGE\n";

			 getline(cin, msg);

			 for (i = 0; msg[i] != NULL; i++)

				 m[i] = msg[i];

			 n = p * q;

			 t = (p - 1) * (q - 1);

			 ce();

			 cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";

			 for (i = 0; i < j - 1; i++)

				 cout << e[i] << "\t" << d[i] << "\n";

			 encrypt();

			 decrypt();

			 
			 
		
	}
	system("pause");
	return 0;
}

void ce()

{

	int k;

	k = 0;
	srand(time(0));
	int o=0;
	for (i = 2; i < t; i++)// o yerine i dersek, en kucuk q ve p olmayan asal sayiyi alir, random olursa t den kucuk ve gereklilikleri saglayan bir 'random' sayi alir.

	{
		o = (2+rand() % t);
		if (t % o == 0)

			continue;

		else {
			flag = prime(o);
		}
		if (flag == 1 && o != p && o != q)

		{

			e[k] = o;

			flag = cd(e[k]);

			if (flag > 0)

			{

				d[k] = flag;

				k++;

			}

			if (k == 99)

				break;

		}

	}

}

long int cd(long int x)

{

	long int k = 1;

	while (1)

	{

		k = k + t;

		if (k % x == 0)

			return (k / x);

	}

}

void encrypt()

{

	long int pt, ct, key = e[0], k, len;

	i = 0;

	len = msg.length();

	while (i != len)

	{

		pt = m[i];

		pt = pt - 96;

		k = 1;

		for (j = 0; j < key; j++)

		{

			k = k * pt;

			k = k % n;

		}

		temp[i] = k;

		ct = k + 96;

		en[i] = ct;

	
		i++;

	}

	en[i] = -1;

	cout << "\nTHE ENCRYPTED MESSAGE IS\n";

	for (i = 0; en[i] != -1; i++)

		printf("%c", en[i]);

}

void decrypt()

{

	long int pt, ct, key = d[0], k;

	i = 0;
	

	while (en[i] != -1)

	{

		ct = temp[i];

		k = 1;

		for (j = 0; j < key; j++)

		{

			k = k * ct;

			k = k % n;

		}

		pt = k + 96;

		m[i] = pt;

		

		i++;

	}

	m[i] = -1;

	cout << "\nTHE DECRYPTED MESSAGE IS\n";

	for (i = 0; m[i] != -1; i++)

		printf("%c", m[i]);

}