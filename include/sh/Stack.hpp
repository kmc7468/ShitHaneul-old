#pragma once

#include <sh/Constant.hpp>

#include <cstddef>
#include <cstdint>
#include <optional>
#include <vector>

namespace sh {
	class Stack final {
	private:
		std::vector<std::uint8_t> m_Data;
		std::size_t m_Used = 0;

	public:
		Stack() noexcept = default;
		explicit Stack(std::size_t size);
		Stack(Stack&& stack) noexcept;
		~Stack() = default;

	public:
		Stack& operator=(Stack&& stack) noexcept;
		bool operator==(const Stack&) = delete;
		bool operator!=(const Stack&) = delete;

	public:
		void Allocate(std::size_t size);
		std::size_t GetSize() const noexcept;
		std::size_t GetUsedSize() const noexcept;
		std::size_t GetFreeSize() const noexcept;

		template<typename T>
		bool Push(T&& value) noexcept;
		template<typename T>
		std::optional<T> Pop() noexcept;
		template<typename T>
		const T* GetTop() const noexcept;
		const Type* GetTopType() const noexcept;

	private:
		template<typename T>
		const T* Get(std::size_t offset) const noexcept;
		template<typename T>
		T* Get(std::size_t offset) noexcept;
	};
}

#include "detail/impl/Stack.hpp"