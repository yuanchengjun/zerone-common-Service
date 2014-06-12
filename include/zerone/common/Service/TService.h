#ifndef ZERONE_COMMON_SERVICE_H
#define ZERONE_COMMON_SERVICE_H

#include <zerone/common/service/TServiceTupleReader.h>
#include <zerone/common/service/TServiceFunctionInvoker.h>

#include <string>
#include <functional>
#include <map>
#include <tuple>
#include <type_traits>
#include <istream>

namespace zerone {
namespace common {

template<class ISTREAM, class OSTREAM>
class TService {
public:
	using IoFunction = ::std::function<void(ISTREAM &, OSTREAM &)>;
	using IoFunctionMap = ::std::map<::std::string, IoFunction>;

private:
	IoFunctionMap mIoFunctionMap;

public:
	template<class I, class C, class R, class ... P>
	void bind(const ::std::string & name, R (I::*function)(P ...), C & object) {
		mIoFunctionMap[name] =
				[this, function, & object](ISTREAM & is, OSTREAM & os) {
					using ParamsTuple = ::std::tuple<typename ::std::remove_const<typename ::std::remove_reference<P>::type>::type ...>;
					using ParamsReader = ::zerone::common::TServiceTupleReader<::std::tuple_size<ParamsTuple>::value>;
					using Invoker = ::zerone::common::TServiceFunctionInvoker<::std::tuple_size<ParamsTuple>::value>;
					ParamsTuple params;
					ParamsReader::read(is, params);
					os << Invoker::invoke(function, object, params);
				};
	}

	void run(ISTREAM & is, OSTREAM & os) {
		::std::string cmd;
		is >> cmd;
		mIoFunctionMap[cmd](is, os);
	}
};

}
}

#endif
