// Sheershak Agarwal, 1662387
// HW 7
// June 2, 2019

#include  "Rational.h"

namespace rational374 {

	// ----------- HELPER FUNCTIONS ----------
	int gcf(int num, int den);

	// ----------- CONSTRUCTORS -----------
	// Construct Rational 0/1
	Rational::Rational() {
	  numer_ = 0;
	  denom_ = 1;
	}

	// Construct Rational n/1
	Rational::Rational(int n) {
	  numer_ = n;
	  denom_ = 1;
	}

	// Construct Rational n/d
	Rational::Rational(int n, int d) {
	  numer_ = n;
	  denom_ = d;
	}

	// ----------- ACCESSORS -----------
	// Return the numererator of the Rational.
	// Results are in lowest terms.
	// denominaator cannot be negative
	int Rational::n() const {
	  if (denom_ == 0) {
	    return numer_;
	  } else if (denom_ < 0) {
	    return -1 * (numer_ / gcf(numer_, denom_));
	  } else {
	    return numer_ / gcf(numer_, denom_);
	  }
	}

	// Return the denominator of the Rational.
	// Results are in lowest terms
	// denominaator cannot be negative
	int Rational::d() const {
	  if (denom_ == 0) {
	    return denom_;
	  } else if (denom_ < 0) {
	    return -1 * (denom_ / gcf(numer_, denom_));
	  } else {
	    return denom_ / gcf(numer_, denom_);
	  }
	}

	// finds the greatest common factor of two numbers
	int gcf(int num, int den) {
		int n = num < 0 ? -num : num;
		int largest = n > den ? n : den;
		int result = 1;
		for (int i = largest; i > 1; i--) {
			if (n % i == 0 && den % i == 0) {
				result = i;
				break;
			}
		}
		return result;
	}

	// ----------- ARITHMETIC -----------
	// Return a new Rational that results from combining this Rational
	// with another.  Neither operand is changed.

	// = this + other
	Rational Rational::plus(Rational other) const {
	  int num = (numer_ * other.denom_) + (denom_ * other.numer_);
	  int den = denom_ * other.denom_;
	  return Rational(num, den);
	}

	// = this - other
	Rational Rational::minus(Rational other) const {
	  int num = (numer_ * other.denom_) - (denom_ * other.numer_);
	  int den = denom_ * other.denom_;
	  return Rational(num, den);
	}

	// = this * other
	Rational Rational::times(Rational other) const {
	  int num = numer_ * other.numer_;
	  int den = denom_ * other.denom_;
	  return Rational(num, den);
	}

	// = this / other
	Rational Rational::div(Rational other) const {
	  int num = numer_ * other.denom_;
	  int den = denom_ * other.numer_;
	  return Rational(num, den);
	}
}