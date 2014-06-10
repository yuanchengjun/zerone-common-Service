#ifndef ZERONE_COMMON_SERVICE_H
#define ZERONE_COMMON_SERVICE_H

#include <zerone/common/service/TServiceTupleReader.h>
#include <zerone/common/service/TServiceFunctionInvoker.h>

#include <string>
#include <functional>
#include <iostream>
#include <map>
#include <tuple>
#include <type_traits>
#include <istream>

namespace zerone {
namespace common {


class TService {
private:
	::std::map<::std::string, ::std::function<void(::std::istream &, ::std::ostream &)> > mIOFunctionMap;

public:
	template<class I, class C, class R, class ... P>
	void bind(const ::std::string & name, R (I::*function)(P ...), C & object) {
		mIOFunctionMap[name] = [this, function, & object](::std::istream & is, ::std::ostream & os) {
			using params_tuple = ::std::tuple<typename ::std::remove_const<typename ::std::remove_reference<P>::type>::type ...>;
			using params_reader = ::zerone::common::TServiceTupleReader<::std::tuple_size<params_tuple>::value>;
			using invoker = ::zerone::common::TServiceFunctionInvoker<::std::tuple_size<params_tuple>::value>;

			params_tuple params;
			params_reader::read(is, params);
			os << invoker::invoke(function, object, params);
		};
	}

};

}
}

#endif
