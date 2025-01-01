#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixed) {
//	std::cout << "Int constructor called" << std::endl;
	_value = fixed << _fractionalBits;
}

Fixed::Fixed(const float fixed) {
//	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(fixed * (1 << _fractionalBits) + (fixed >= 0 ? 0.5 : -0.5));
}

Fixed::Fixed(const Fixed& fixed) {
//	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
//	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		_value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
//	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
//	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat(void) const {
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _value >> _fractionalBits;
}


bool Fixed::operator>(const Fixed& fixed) const {
	return _value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed& fixed) const {
	return _value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed& fixed) const {
	return _value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed& fixed) const {
	return _value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed& fixed) const {
	return _value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed& fixed) const {
	return _value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed& fixed) const {
	return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed) const {
	return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed) const {
	return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) const {
	return Fixed(toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator++(void) {
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed& Fixed::operator--(void) {
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return a > b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return a < b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return a > b ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
