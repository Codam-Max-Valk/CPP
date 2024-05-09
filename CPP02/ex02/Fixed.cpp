#include "Fixed.hpp"

Fixed::Fixed() : _value(0){
	// std::cout << "Default constructor called" << std::endl;
	
}

Fixed::Fixed(const Fixed &fixed){
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int value){
	// std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value){
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed){
	// std::cout << "Assignation operator called" << std::endl;

	if (this != &fixed)
		_value = fixed.getRawBits();
	return *this;
}

void	Fixed::setRawBits(int const raw){
	_value = raw;
}

int		Fixed::getRawBits(void) const{
	return _value;
}

float	Fixed::toFloat(void) const{
	return (float)_value / (1 << _fractionalBits);
}

int		Fixed::toInt(void) const{
	return _value >> _fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

bool	Fixed::operator>(const Fixed &fixed) const{
	return _value > fixed.getRawBits();
}

bool	Fixed::operator<(const Fixed &fixed) const{
	return _value < fixed.getRawBits();
}

bool	Fixed::operator>=(const Fixed &fixed) const{
	return _value >= fixed.getRawBits();
}

bool	Fixed::operator<=(const Fixed &fixed) const{
	return _value <= fixed.getRawBits();
}

bool	Fixed::operator==(const Fixed &fixed) const{
	return _value == fixed.getRawBits();
}

bool	Fixed::operator!=(const Fixed &fixed) const{
	return _value != fixed.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &fixed) const{
	Fixed result;

	result.setRawBits(_value + fixed.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed &fixed) const{
	Fixed result;

	result.setRawBits(_value - fixed.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed &fixed) const{
	Fixed result;

	result.setRawBits((_value * fixed.getRawBits()) >> _fractionalBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed &fixed) const{
	Fixed result;

	result.setRawBits((_value << _fractionalBits) / fixed.getRawBits());
	return result;
}

Fixed	Fixed::operator++(int){
	Fixed result(*this);

	_value++;
	return result;
}

Fixed	Fixed::operator++(){
	_value++;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed result(*this);

	_value--;
	return result;
}

Fixed	Fixed::operator--(){
	_value--;
	return *this;
}

