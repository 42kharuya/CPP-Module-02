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
};

#endif // _FIXED_H_
