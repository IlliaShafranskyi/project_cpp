#include <iostream>
#include "l_zesp.h"

void add_attr(LZESPOLONA &obj) {
		//dodaje do koncowego objekta nawiasy i "i"
		obj.pierwszy_nawias= '(';
		obj.drugi_nawias = ')';
		obj.i = 'i';
}

//Przeciazenia operatorow
//
//

std::ostream& operator<<(std::ostream &out, const LZESPOLONA &obj) {
		out << obj.pierwszy_nawias << obj.a << obj.znak <<  obj.b << obj.i << obj.drugi_nawias;
		return out;
}

std::istream& operator>>(std::istream &in, LZESPOLONA &obj) {
		in >> obj.pierwszy_nawias;
		in >> obj.a;
		in >> obj.znak;
		in >> obj.b;
		in >> obj.i;
		in >> obj.drugi_nawias;

		return in;
}

bool operator==(LZESPOLONA &obj1, LZESPOLONA &obj2) { 
	return(obj1.a == obj2.a && obj1.b == obj2.b);
}
bool operator!=(LZESPOLONA &obj1, LZESPOLONA &obj2) {
		return !(obj1 == obj2);
}

		

LZESPOLONA operator-(LZESPOLONA &obj1, LZESPOLONA &obj2) {
		LZESPOLONA tmp_obj;

		tmp_obj.a = obj1.a-obj2.a;
		tmp_obj.b = obj1.b-obj2.b;

		//Sprawdzam znaki w obj1 i obj2, bo od tego zalezy wykonana operacja i wynik koncowy
		if(obj1.b < obj2.b && obj1.znak == '-' && obj2.znak == '-') {
				tmp_obj.znak == '+';
				tmp_obj.b = obj2.b-obj1.b;
		}
		else if(obj1.b < obj2.b && obj1.znak == '-') {
				tmp_obj.znak == '-';
				tmp_obj.b = obj1.b+obj2.b;
		}
		else if(obj1.b < obj2.b && obj2.znak == '-') {
				tmp_obj.znak == '+';
				tmp_obj.b = obj1.b+obj2.b;
		}
		else if(obj1.b > obj2.b && obj1.znak == '-' && obj2.znak == '-') {
				tmp_obj.znak == '-';
				tmp_obj.b = obj1.b-obj2.b;
		}
		else if(obj1.b > obj2.b && obj2.znak == '-') {
				tmp_obj.znak == '+';
				tmp_obj.b = obj1.b+obj2.b;
		}
		else if(obj1.b > obj2.b && obj1.znak == '-') {
				tmp_obj.znak == '-';
				tmp_obj.b = obj1.b+obj2.b;
		}
		else if(obj1.b < obj2.b) {
				tmp_obj.znak = '-';
				tmp_obj.b = obj2.b-obj1.b;
		}
		
	

		add_attr(tmp_obj);
		return tmp_obj;
}

LZESPOLONA operator+(LZESPOLONA &obj1, LZESPOLONA &obj2) {
		LZESPOLONA tmp_obj;

		tmp_obj.a = obj1.a+obj2.a;

		//Sprawdzam znaki w obj1 i obj2, bo od tego zalezy wykonana operacja i wynik koncowy
		if(obj1.b > obj2.b && obj1.znak == '-' && obj2.znak == '-') {
				tmp_obj.znak = '-';
				tmp_obj.b = obj1.b + obj2.b;
		}
		else if(obj1.b < obj2.b && obj1.znak == '-' && obj2.znak == '-') {
				tmp_obj.znak == '-';
				tmp_obj.b = obj1.b + obj2.b;
		}
		else if(obj1.b < obj2.b && obj1.znak == '-' ) {
				tmp_obj.znak == '+';
				tmp_obj.b = obj2.b - obj1.b; 

		}
		else if(obj1.b < obj2.b && obj2.znak == '-') {
				tmp_obj.znak == '-';
				tmp_obj.b = obj2.b - obj1.b;
		}
		else if(obj1.b > obj2.b && obj2.znak == '-') {
				tmp_obj.znak == '+';
				tmp_obj.b = obj1.b - obj2.b;
				
		}
		else {
				tmp_obj.b = obj1.b+obj2.b;
		}


		add_attr(tmp_obj);

		return tmp_obj;
}

LZESPOLONA operator*(LZESPOLONA &obj1, LZESPOLONA &obj2) {
		LZESPOLONA tmp_obj;


		tmp_obj.a = obj1.a*obj2.a;
		tmp_obj.b = obj1.b*obj2.b;

		add_attr(tmp_obj);
		return tmp_obj;
}

LZESPOLONA operator/(LZESPOLONA &obj1, LZESPOLONA &obj2) {
		LZESPOLONA tmp_obj;


		tmp_obj.a = obj1.a/obj2.a;
		tmp_obj.b = obj1.b/obj2.b;

		add_attr(tmp_obj);
		return tmp_obj;
}


