#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
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
	return _rawBits;
}

void Fixed::setRawBits (const int raw) {
	_rawBits = raw;
}
