#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>
#include <cmath>

class Fixed
{
	private:
	 int _rawBits;
	 static const int _kFractionalBits = 8;

	public:
	 Fixed();
	 Fixed(const int &raw);
	 Fixed(const float &raw);
	 ~Fixed();
	 Fixed(const Fixed &other);
	 Fixed& operator=(const Fixed &other);

	 int getRawBits (void) const;
	 void setRawBits (const int raw);
	 float toFloat(void) const;
	 int toInt(void) const;

	 bool operator>(const Fixed &other) const;
     bool operator<(const Fixed &other) const;
     bool operator>=(const Fixed &other) const;
     bool operator<=(const Fixed &other) const;
     bool operator==(const Fixed &other) const;
     bool operator!=(const Fixed &other) const;

	 Fixed operator+(const Fixed& other) const;
     Fixed operator-(const Fixed& other) const;
     Fixed operator*(const Fixed& other) const;
     Fixed operator/(const Fixed& other) const;

     Fixed& operator++();
     Fixed operator++(int);
     Fixed& operator--();
	 Fixed operator--(int);

	 static Fixed &min(Fixed &a, Fixed &b);
	 static Fixed const &min(Fixed const &a, Fixed const &b);
	 static Fixed &max(Fixed &a, Fixed &b);
	 static Fixed const &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif // _FIXED_H_
