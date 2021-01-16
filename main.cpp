#include <iostream>
#include <fstream>
#include "l_zesp.h"

void start_test();
void test_wyrazenia();
void test_liczby();
void show_menu();

int main() {
		using namespace std;
		start_test();
}

void start_test() {
		using namespace std;
		char choice;
		void (*result)();

		while(true) {
				show_menu();
				cout << "Twoj wybor - ";
				cin >> choice;
				if(choice == 'k') break;
				else if(choice == 'l') {
						result = test_liczby;
						break;
				}
				else if(choice == 'w') {
						result = test_wyrazenia;
						break;
				}
				else if(choice == 'm') continue;
				else cout << "Bledna opcja menu." << endl;
		}
		result();

}

void show_menu() {
		using namespace std;

		cout << "w - Uruchom test wyswietlajacy wyrazenia zespolone" << endl <<
				"l - Uruchom test wyswietlajacy liczby zespolone" << endl <<
				"m - Wyswietl menu" <<endl <<
				"k - Koniec dzialania programu" << endl;

}
void test_wyrazenia() {
		using namespace std;
		int good_points = 0;
		int bad_points = 0;

		ifstream input_file;
		input_file.open("file_test.txt");

		if(input_file.is_open()) {
				while(!input_file.eof()) {
						LZESPOLONA liczba1;
						LZESPOLONA liczba2;
						LZESPOLONA result;
						LZESPOLONA input_result;
						char znak;

						input_file >> liczba1 >> znak >> liczba2;

						cout << ":? Podaj wynik operacji: " << liczba1 << znak << liczba2 << " = " << endl;

						if(znak == '+') {
								result = liczba1 + liczba2;
						}
						else if(znak == '-') {
								result = liczba1 - liczba2;
						}
						else if(znak == '*') {
								result = liczba1 * liczba2;
						}
						else if(znak == '/') {
								result = liczba1 / liczba2;
						}

						cout << "   Twoja odpowiedz: ";
						cin >> input_result;

						if(input_result != result) {
								cout << "Blad. Prawidlowym wynikiem jest: " << result << endl;
								cout << endl;
								bad_points += 1;
						} 
						else {
								cout << ":) Odpowiedz poprawna" << endl;
								cout << endl;
								good_points += 1;
								continue;
						}
				}

		}
		else {
				cout << "failed" << endl;
		}
		input_file.close();
		cout << endl;
		cout << "Koniec testu" << endl;
		cout << "Ilosc poprawnych odpowiedzi: " << good_points << endl;
		cout << "Ilosc blednych odpowiedzi: " << bad_points << endl;
		cout << endl;

		start_test();
}




void test_liczby() {
		using namespace std;
		int good_points = 0;
		int bad_points = 0;

		ifstream input_file;
		input_file.open("liczb_test.txt");

		if(input_file.is_open()) {
				while(!input_file.eof()) {
						int good_points = 0;
						int bad_points = 0;
						LZESPOLONA liczba;
						LZESPOLONA in_liczba1;
						LZESPOLONA in_liczba2;
						LZESPOLONA result;
						char znak;

						input_file >> liczba;

						cout << ":? Podaj wyrazenie wynikiem ktorej jest: " << liczba << endl;
						cout << "   Twoja odpowiedz: ";
						cin >> in_liczba1 >> znak >> in_liczba2;
						if(znak == '+') {
								result = in_liczba1 + in_liczba2;
						}
						else if(znak == '-') {
								result = in_liczba1 - in_liczba2;
						}
						else if(znak == '*') {
								result = in_liczba1 * in_liczba2;
						}
						else if(znak == '/') {
								result = in_liczba1 / in_liczba2;
						}


						if(result == liczba) {
								cout << ":) Poprawna odpowiedz!";
								cout << endl;
								good_points += 1;
								continue;
						}
						else {
								cout << ":( Bledna odpowiedz!";
								cout << endl;
								bad_points += 1;
						}
				}
		}
}
	
