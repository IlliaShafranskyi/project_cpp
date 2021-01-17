#include <iostream>
#include <fstream>
#include "l_zesp.h"

void start_test();


void show_menu() {
		using namespace std;

		cout << "w - Uruchom test wyswietlajacy wyrazenia zespolone" << endl <<
				"l - Uruchom test wyswietlajacy liczby zespolone" << endl <<
				"m - Wyswietl menu" <<endl <<
				"k - Koniec dzialania programu" << endl;

}
void test_wyrazenia() {
		//Test na wyrazenia zespolone

		using namespace std;
		int good_points = 0;
		int bad_points = 0;
		int percent_result;

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
		percent_result = (100/(good_points+bad_points)*good_points);
		cout << endl;
		cout << "Koniec testu" << endl;
		cout << "Ilosc poprawnych odpowiedzi: " << good_points << endl;
		cout << "Ilosc blednych odpowiedzi: " << bad_points << endl;
		cout << endl;
		cout << "Wynik procentowy poprawnych odpowiedzi: " << percent_result << "%" << endl;
		cout << endl;

		start_test();
}




void test_liczby() {
		//Test na liczby zespolone
		using namespace std;
		int good_points = 0;
		int bad_points = 0;
		int percent_result;

		ifstream input_file;
		input_file.open("liczb_test.txt");

		if(input_file.is_open()) {
				while(!input_file.eof()) {
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
								good_points += 1;
								cout << ":) Poprawna odpowiedz!";
								cout << endl;
								continue;
						}
						else {
								bad_points += 1;
								cout << ":( Bledna odpowiedz!";
								cout << endl;
						}
				}
		}
		input_file.close();
		
		percent_result = (100/(good_points+bad_points))*good_points;

		cout << endl;
		cout << "Koniec testu" << endl;
		cout << "Ilosc poprawnych odpowiedzi: " << good_points << endl;
		cout << "Ilosc blednych odpowiedzi: " << bad_points << endl;
		cout << endl;
		cout << "Procentowy wynik dobrych odpowiedzi: " << percent_result << "%" << endl;
		cout << endl;

		start_test();
}
	

void start_test() {
		//Start testu

		using namespace std;
		char choice;

		cout << "WITAM" << endl;
		cout << endl;
		while(true) {
				show_menu();
				cout << "Twoj wybor - ";
				cin >> choice;
				if(choice == 'k') break;
				else if(choice == 'l') {
						test_liczby();
						break;
				}
				else if(choice == 'w') {
						test_wyrazenia();
						break;
				}
				else if(choice == 'm') continue;
				else cout << "Bledna opcja menu." << endl;
		}

}
