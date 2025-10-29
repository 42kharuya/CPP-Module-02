#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &raw) {
	std::cout << "Default constructor called" << std::endl;
	_rawBits = num << _kFractionalBits;
}

static int round_to_int(float f) {
    if (f >= 0.0f) {
        return static_cast<int>(std::floor(f + 0.5f));
    } else {
        return static_cast<int>(std::ceil(f - 0.5f));
    }
}

Fixed::Fixed(const float &raw) {
	std::cout << "Default constructor called" << std::endl;
	_rawBits = round_to_int(raw * (1 << _numOfFractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
		this->_rawBits = other.getRawBits();
	}
    return *this;
}

int Fixed::getRawBits (void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits (const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}
