#include <iostream>
#include <ostream>
#ifndef LZESPOLONA_H
#define LZESPOLONA_H


class LZESPOLONA {
		private:
				// zapis liczby zespołonej: a+bi, znak to +, -, *
				char pierwszy_nawias;
				int a;
			    char znak;
				int b;
				char i;
				char drugi_nawias;


		public:
				friend std::ostream& operator<<(std::ostream &out, const LZESPOLONA &obj);
				friend std::istream& operator>>(std::istream &in, LZESPOLONA &obj);
				
				friend LZESPOLONA operator+(LZESPOLONA &obj1, LZESPOLONA &obj2);
				friend LZESPOLONA operator-(LZESPOLONA &obj1, LZESPOLONA &obj2);
				friend LZESPOLONA operator*(LZESPOLONA &obj1, LZESPOLONA &obj2);
				friend LZESPOLONA operator/(LZESPOLONA &obj1, LZESPOLONA &obj2);
				friend bool operator!=(LZESPOLONA &obj1, LZESPOLONA &obj2);
				friend bool operator==(LZESPOLONA &obj1, LZESPOLONA &obj2);

				friend void add_attr(LZESPOLONA &obj);
				
};

#endif
