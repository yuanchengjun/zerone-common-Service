#ifndef ZERONE_COMMON_SERVICESTREAM_H
#define ZERONE_COMMON_SERVICESTREAM_H

namespace zerone {
namespace common {

template<class IS>
class ServiceInputStream {
public:
	using self = ServiceInputStream;

private:
	IS & is;

public:
	ServiceInputStream(IS & is) :
			is(is) {
	}

public:
	self & operator >>(char & value) {
		is >> value;
		return *this;
	}

	self & operator >>(signed char & value) {
		is >> value;
		return *this;
	}

	self & operator >>(unsigned char & value) {
		is >> value;
		return *this;
	}

	self & operator >>(short & value) {
		is >> value;
		return *this;
	}

	self & operator >>(unsigned short & value) {
		is >> value;
		return *this;
	}

	self & operator >>(int & value) {
		is >> value;
		return *this;
	}

	self & operator >>(unsigned int & value) {
		is >> value;
		return *this;
	}

	self & operator >>(long & value) {
		is >> value;
		return *this;
	}

	self & operator >>(unsigned long & value) {
		is >> value;
		return *this;
	}

	self & operator >>(long long & value) {
		is >> value;
		return *this;
	}

	self & operator >>(unsigned long long & value) {
		is >> value;
		return *this;
	}

	self & operator >>(float & value) {
		is >> value;
		return *this;
	}

	self & operator >>(double & value) {
		is >> value;
		return *this;
	}

	self & operator >>(bool & value) {
		is >> value;
		return *this;
	}

	self & operator >>(wchar_t & value) {
		is >> value;
		return *this;
	}

	self & operator >>(::std::string & value) {
		is >> value;
		return *this;
	}

};

}
}

#endif
