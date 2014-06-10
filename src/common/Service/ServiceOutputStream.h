#ifndef ZERONE_COMMON_SERVICEOUTPUTSTREAM_H
#define ZERONE_COMMON_SERVICEOUTPUTSTREAM_H

namespace zerone {
namespace common {

template<class OS>
class TServiceOutputStream {
public:
	using self = TServiceOutputStream;

private:
	OS & os;

public:
	TServiceOutputStream(OS & os) :
			os(os) {
	}

public:
	self & operator <<(char value) {
		os << value;
		return *this;
	}

	self & operator <<(signed char value) {
		os << value;
		return *this;
	}

	self & operator <<(unsigned char value) {
		os << value;
		return *this;
	}

	self & operator <<(short value) {
		os << value;
		return *this;
	}

	self & operator <<(unsigned short value) {
		os << value;
		return *this;
	}

	self & operator <<(int value) {
		os << value;
		return *this;
	}

	self & operator <<(unsigned int value) {
		os << value;
		return *this;
	}

	self & operator <<(long value) {
		os << value;
		return *this;
	}

	self & operator <<(unsigned long value) {
		os << value;
		return *this;
	}

	self & operator <<(long long value) {
		os << value;
		return *this;
	}

	self & operator <<(unsigned long long value) {
		os << value;
		return *this;
	}

	self & operator <<(float value) {
		os << value;
		return *this;
	}

	self & operator <<(double value) {
		os << value;
		return *this;
	}

	self & operator <<(bool value) {
		os << value;
		return *this;
	}

	self & operator <<(wchar_t value) {
		os << value;
		return *this;
	}

	self & operator <<(const ::std::string & value) {
		os << value;
		return *this;
	}

	self & operator <<(const char * value) {
		os << value;
		return *this;
	}

};

}
}

#endif
