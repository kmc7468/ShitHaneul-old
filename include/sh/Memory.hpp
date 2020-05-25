#pragma once

#include <sh/Predefined.hpp>

namespace sh {
	enum class Endian {
		Little,
		Big,
	};

#ifdef SH_LITTLE
	constexpr Endian GetEndian() noexcept;
#else
	Endian GetEndian() noexcept;
#endif

	template<typename T>
	T ReverseEndian(const T& value) noexcept;
}

#include "detail/impl/Memory.hpp"