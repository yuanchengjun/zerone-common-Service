#ifndef ZERONE_COMMON_T_SERVICE_TUPLE_READER_H
#define ZERONE_COMMON_T_SERVICE_TUPLE_READER_H

#include <tuple>

namespace zerone {
namespace common {

template<size_t INDEX>
class TServiceTupleReader {
public:
	template<class TP, class ISTREAM>
	static int read(ISTREAM & is, TP & tp) {
		TServiceTupleReader<INDEX - 1>::read(is, tp);
		is >> ::std::get<INDEX - 1>(tp);
		return 1;
	}
};

template<>
class TServiceTupleReader<1> {
public:
	template<class TP, class ISTREAM>
	static int read(ISTREAM & is, TP & tp) {
		is >> ::std::get<0>(tp);
		return 1;
	}
};

}
}

#endif
