#pragma once

#include "function_detail.hh"

#include <memory>

namespace presentation {

// Primary template
template<typename Sig>
class function;

// Unwrapping specialization
template<typename Ret, typename... Args>
class function<Ret(Args...)>
{
private:
	using WrapperIfaceType = detail::wrapper_iface<Ret, Args...>;
	std::unique_ptr<WrapperIfaceType> wrapper_;
	
public:

	function()
	{
	}
	
	function(const function& other)
	{
	}
	
	function(function&& other)
	{
	}
	
	template<typename Ftor>
	function(Ftor f)
	{
		using WrapperType = detail::functor_wrapper<Ftor, Ret, Args...>;
		
		wrapper_ = std::make_unique<WrapperType>(f);
	}
	
	Ret operator()(Args... args)
	{
		return Ret{};
	}
	
};
	
}