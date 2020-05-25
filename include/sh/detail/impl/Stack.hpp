#pragma once
#include <sh/Stack.hpp>

#include <utility>

namespace sh {
	template<typename T>
	bool Stack::Push(T&& value) noexcept {
		if (GetFreeSize() < sizeof(value)) return false;
		else return *Get<T>(m_Used += sizeof(value)) = std::forward<T>(value), true;
	}
	template<typename T>
	std::optional<T> Stack::Pop() noexcept {
		const T* const result = GetTop<T>();
		if (!result) return std::nullopt;
		else return m_Used -= sizeof(*result), *result;
	}
	template<typename T>
	const T* Stack::GetTop() const noexcept {
		return Get<T>(m_Used);
	}

	template<typename T>
	const T* Stack::Get(std::size_t offset) const noexcept {
		if (m_Used < sizeof(T) || m_Used < offset) return nullptr;
		else return reinterpret_cast<const T*>(&*(m_Data.rbegin() + offset - 1));
	}
	template<typename T>
	T* Stack::Get(std::size_t offset) noexcept {
		if (m_Used < sizeof(T) || m_Used < offset) return nullptr;
		else return reinterpret_cast<T*>(&*(m_Data.rbegin() + offset - 1));
	}
}