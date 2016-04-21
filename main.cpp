#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <cmath>
#include <stdlib.h>

using namespace std;



void write_num(const char digit_1[]);
void unity(char a);
void tens(char b , char a);
void ten(char c);
void hundreds(char d);

int digit(long long int x ,int position);
bool check_number(long long int number);


int main(int argc, char const *argv[])
{
	if(argc <2)
	{
		cout << "za malo parametrow wywolania"<< endl;
		return 1;
	}
	long long int n ,k = 1;
	n = atoi(argv[1]);
	cout << n << endl;
	for( ;    ; ++k)
	{
		if(check_number(n*k))
		{
			cout << "znalazłem k równe:" << k << endl;
			cout << n<<" * "<<k << " = "<<n*k<< endl;
			
			write_num(to_string(k).c_str());
			return 0;
		}
	}
	return 0;
}

int digit(long long int x ,int position)
{
	return (x%(long long int)pow(10,position))/(long long int)pow(10, position - 1);
}

bool check_number(long long int number)
{
	int length = log10(number) +1;
	for(int i = 1 ; i <= length ; ++i)
	{
		if(digit(number , i) > 1) 
			return false;
	}
	return true;
}


void write_num(const char digit_3[])
{
	char digit_1[8]= {0};
	char digit_2[8];
	int sum = 0;

	for(int i = 0 ; i < 8; ++i) //wypelnianie tablicy zerami
		{
			digit_1[i] = digit_3[i];
			if(digit_3[i] == 0) break;
		}

	for(int i = 0 ; i < 8; ++i) //wypelnianie tablicy zerami
		digit_2[i] = 0 ;


	 //uzypelnianie tablicy cyframi

	for(int i = 7 ; i >= 0 ; --i) //przepisywanie tablicy w porzadanej kolejnosci
		{	
			if(digit_1[i] != 0)
				digit_2[strlen(digit_1) - i - 1] = digit_1[i];
		}
	//for(int i = 0 ; i < 8; ++i) //wypisywanie tablicy
		// cout << digit_2[i];
	for(int i = 0 ; i < 7; ++i) //sumowanie cyfr tablcicy
		 sum += digit_2[i] - '0';
	if (digit_2[6] > '1' || (digit_2[6] == '1' && sum > 1) ) //sprawdzanie czy liczba misci sie w zakresie
		{
			cout << "za duża liczba" << endl;
			return ;
		}
	if (digit_2[6] == '1' && sum == 1) // sprawdzanie czy zadana liczba to milion
		{
			cout << "milion" << endl;
			return ;
		}
	

//tens(digit_2[1] , digit_2[0]);
//unity(digit_2[0]);
//hundreds(digit_2[2]);

		if(digit_2[5] != '0' && digit_2[5] != 0) // sprawdzanie czy są setki tysiecy
		{
			hundreds(digit_2[5]);
		
			if(digit_2[3] == '0' || digit_2[4] == '1' )//spradzanie czy nie ma jednosci i czysą nascie
			{
				
				tens(digit_2[4] , digit_2[3]);
				cout << " tysięcy " ;

			}
			else if(digit_2[4] == '0' && digit_2[3] != '0') // nie ma dzisiątek tysiecy ale są jedności
			{
				if(digit_2[3] == '2' || digit_2[3] == '3' || digit_2[3] == '4') // sprawdzani czy sa liczby dla których jest inna odmiana
				{
					unity(digit_2[3]);
					cout << " tysiące ";
				}
				else 
				{
					unity(digit_2[3]);
					cout << " tysięcy ";
				}
			}
			else if(digit_2[4] != '0' && digit_2[3] != '0')
			{
				tens(digit_2[4] , digit_2[3]);
			 		if(digit_2[4] != '1' && (digit_2[3] == '2' || digit_2[3] == '3' || digit_2[3] == '4'))
					{
						unity(digit_2[3]);
						cout << " tysiące ";
					}
					else 
					{
						if(digit_2[4] != '1')
							unity(digit_2[3]);
						cout << " tysięcy "; // jakis blad
					}
			}
		}
		else if(digit_2[4] != '0' && digit_2[3] != '0' &&  digit_2[4] != 0 && digit_2[3] != 0 ) // spradzanie czy sa zwykle kilkadzisiat pare tysiecy
			 	{
			 		tens(digit_2[4] , digit_2[3]);
			 		if(digit_2[4] != '1' && (digit_2[3] == '2' || digit_2[3] == '3' || digit_2[3] == '4'))
					{
						unity(digit_2[3]);
						cout << " tysiące ";
					}
					else 
					{
						if(digit_2[4] != '1')
							unity(digit_2[3]);
						cout << " tysięcy "; // jakis blad
					}
				}
		
		else if(digit_2[5] == 0 && digit_2[4] == 0 && digit_2[3] != 0 && digit_2[3] != '0' ) // bez setek i dziesiątek
			{
				if(digit_2[3] == '1')
					cout << " tysiąc ";

				else if(digit_2[3] == '2' || digit_2[3] == '3' || digit_2[3] == '4')
					{
						unity(digit_2[3]);
						cout << " tysiące ";
					}
				else  
					{
						unity(digit_2[3]);
						cout << " tysięcy ";
					}

			}

			




// KONIEC TYSIECY=========================================================================

	if(digit_2[2] != '0' && digit_2[2] != 0 )
	{
		hundreds(digit_2[2]);
		if(digit_2[1] != '0' )//spradzanie czy nie ma jednosci i czysą nascie
			tens(digit_2[1] , digit_2[0]);
		if(digit_2[0] != '0' && digit_2[1] != '1' )
			unity(digit_2[0]);
	}

	else if(digit_2[1] != '0' && digit_2[1] != 0 )
	{
		
		if(digit_2[1] != '0' )//spradzanie czy nie ma jednosci i czysą nascie
			tens(digit_2[1] , digit_2[0]);
		if(digit_2[0] != '0' && digit_2[1] != '1' )
			unity(digit_2[0]);
	}
	else if(digit_2[0] != '0' && digit_2[0] != 0 )
		unity(digit_2[0]);





cout << endl;
return ;

	

}

void unity(char a)
{
	
	switch(a)
		{
			case '1':
				cout << "jeden";
			 	break;
			 case '2':
				cout << "dwa";
			 	break;
			 case '3':
				cout << "trzy";
			 	break;
			 case '4':
				cout << "cztery";
			 	break;
			 case '5':
				cout << "pięć";
			 	break;
			 case '6':
				cout << "sześć";
			 	break;
			 case '7':
				cout << "siedem";
			 	break;
			 case '8':
				cout << "osiem";
			 	break;
			 case '9':
				cout << "dziewięć";
			 	break;
		}
}

void ten(char c)
{
	switch (c)
		{
			case '1':
				cout << " jedenaście";
				break;
			case '2':
				cout << " dwanaście";
				break;
			case '3':
				cout << " trzynaście";
				break;
			case '4':
				cout << " czternaście";
				break;
			case '5':
				cout << " piętnaście";
				break;
			case '6':
				cout << " szesnaście";
				break;
			case '7':
				cout << " siedemnaście";
				break;
			case '8':
				cout << " osiemnaście";
				break;
			case '9':
				cout << " dziewiętnaście";
				break;
		}

															
}

void tens(char b , char a )
{
	switch(b)
		{
			case '1':	
				if(a == '0')
					cout << "dziesięć ";
				else
					ten(a);
			 	break;
			 case '2':
				cout << "dwadzieścia ";
			 	break;
			 case '3':
				cout << "trzydzieści ";
			 	break;
			 case '4':
				cout << "czterdzieści ";
			 	break;
			 case '5':
				cout << " pięćdziesiąt ";
			 	break;
			 case '6':
				cout << "sześćdziesiąt ";
			 	break;
			 case '7':
				cout << "siedemdziesiąt ";
			 	break;
			 case '8':
				cout << "osiemdziesiąt ";
			 	break;
			 case '9':
				cout << "dziewięćdziesiąt ";
			 	break;
		 }

}

void hundreds(char d)
{
	switch(d)
		{
			case '1':
				cout << "sto ";
			 	break;
			 case '2':
				cout << "dwieście ";
			 	break;
			 case '3':
				cout << "trzysta ";
			 	break;
			 case '4':
				cout << "czterysta ";
			 	break;
			 case '5':
				cout << "pięćset ";
			 	break;
			 case '6':
				cout << "sześćset ";
			 	break;
			 case '7':
				cout << "siedemset ";
			 	break;
			 case '8':
				cout << "osiemset ";
			 	break;
			 case '9':
				cout << "dziewięśet ";
			 	break;
		}
}