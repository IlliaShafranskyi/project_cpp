#include <iostream>
#include "l_zesp.h"

void add_attr(LZESPOLONA &obj) {
		obj.pierwsza_klamerka = '(';
		obj.druga_klamerka = ')';
		obj.i = 'i';
}
void check_znack(LZESPOLONA &obj) {
		if(obj.znak == '-') {
			obj.b = -obj.b;
		}
}

void change_znack(LZESPOLONA &main_obj, LZESPOLONA &obj1, LZESPOLONA &obj2) {
		if(obj1.b < obj2.b) {
				main_obj.znak = ' ';
		}
		else {
				main_obj.znak = obj1.znak;
		}
}

std::ostream& operator<<(std::ostream &out, const LZESPOLONA &obj) {
		out << obj.pierwsza_klamerka << obj.a << obj.znak <<  obj.b << obj.i << obj.druga_klamerka;
		return out;
}

std::istream& operator>>(std::istream &in, LZESPOLONA &obj) {
		in >> obj.pierwsza_klamerka;
		in >> obj.a;
		in >> obj.znak;
		in >> obj.b;
		in >> obj.i;
		in >> obj.druga_klamerka;

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

		check_znack(obj1);
		check_znack(obj2);
		change_znack(tmp_obj, obj1, obj2);

		tmp_obj.a = obj1.a-obj2.a;
		tmp_obj.b = obj1.b-obj2.b;

		add_attr(tmp_obj);
		return tmp_obj;
}

LZESPOLONA operator+(LZESPOLONA &obj1, LZESPOLONA &obj2) {
		LZESPOLONA tmp_obj;

		check_znack(obj1);
		check_znack(obj2);
		change_znack(tmp_obj, obj1, obj2);

		tmp_obj.a = obj1.a+obj2.a;
		tmp_obj.b = obj1.b+obj2.b;

		add_attr(tmp_obj);
		return tmp_obj;
}

LZESPOLONA operator*(LZESPOLONA &obj1, LZESPOLONA &obj2) {
		LZESPOLONA tmp_obj;

		check_znack(obj1);
		check_znack(obj2);
		change_znack(tmp_obj, obj1, obj2);

		tmp_obj.a = obj1.a*obj2.a;
		tmp_obj.b = obj1.b*obj2.b;

		add_attr(tmp_obj);
		return tmp_obj;
}

LZESPOLONA operator/(LZESPOLONA &obj1, LZESPOLONA &obj2) {
		LZESPOLONA tmp_obj;

		check_znack(obj1);
		check_znack(obj2);
		change_znack(tmp_obj, obj1, obj2);

		tmp_obj.a = obj1.a/obj2.a;
		tmp_obj.b = obj1.b/obj2.b;

		add_attr(tmp_obj);
		return tmp_obj;
}


