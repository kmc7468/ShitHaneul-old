#pragma once
#include <sh/Memory.hpp>

#include <algorithm>
#include <cstdint>
#include <iterator>

namespace sh {
#ifdef SH_LITTLE
	constexpr Endian GetEndian() noexcept {
		return Endian::Little;
	}
#endif

	template<typename T>
	T ReverseEndian(const T& value) noexcept {
		union Transformer {
			std::uint8_t Bytes[sizeof(value)];
		} temp;
		temp = reinterpret_cast<const Transformer&>(value);
		std::reverse(std::begin(temp.Bytes), std::end(temp.Bytes));
		return reinterpret_cast<T&>(temp);
	}
}