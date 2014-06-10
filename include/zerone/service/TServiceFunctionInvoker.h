#ifndef ZERONE_COMMON_T_SERVICE_FUNCTION_INVOKER_H
#define ZERONE_COMMON_T_SERVICE_FUNCTION_INVOKER_H

namespace zerone {
namespace common {

template<size_t INDEX>
class TServiceFunctionInvoker {
public:
	template<class I, class C, class R, class TP, class ... P, class ... ARGS>
	static R invoke(R (I::*function)(P...), C & object, TP & tp,
			ARGS ... args) {
		return TServiceFunctionInvoker<INDEX - 1>::invoke(function, object, tp,
				::std::get<INDEX - 1>(tp), args ...);
	}
};

template<>
class TServiceFunctionInvoker<0> {
public:
	template<class I, class C, class R, class TP, class ... P, class ... ARGS>
	static R invoke(R (I::*function)(P...), C & object, TP & tp,
			ARGS ... args) {
		return (object.*function)(args ...);
	}
};

}
}

#endif
