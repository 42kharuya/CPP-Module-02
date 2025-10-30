#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &raw) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = raw << _kFractionalBits;
}

static int roundToInt(float f) {
    if (f >= 0.0f) {
        return static_cast<int>(std::floor(f + 0.5f));
    } else {
        return static_cast<int>(std::ceil(f - 0.5f));
    }
}

Fixed::Fixed(const float &raw) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundToInt(raw * (1 << _kFractionalBits));
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

float Fixed::toFloat(void) const {
	return static_cast<float>(_rawBits) / (1 << _kFractionalBits);
}

int Fixed::toInt(void) const {
	float tmp = toFloat();
	return roundToInt(tmp);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed) {
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &other) const {
    return _rawBits > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
    return _rawBits < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
    return _rawBits >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    return _rawBits <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
    return _rawBits == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    return !(*this == other);
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toInt() + other.toInt());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toInt() - other.toInt());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toInt() / other.toInt());
}

Fixed& Fixed::operator++() {
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    _rawBits++;
    return tmp;
}

Fixed& Fixed::operator--() {
	_rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
	_rawBits--;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
    return (a > b) ? a : b;
}
