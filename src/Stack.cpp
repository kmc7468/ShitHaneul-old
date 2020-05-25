#include <sh/Stack.hpp>

#include <cassert>

namespace sh {
	Stack::Stack(std::size_t size) {
		Allocate(size);
	}
	Stack::Stack(Stack&& stack) noexcept
		: m_Data(std::move(stack.m_Data)), m_Used(stack.m_Used) {}

	Stack& Stack::operator=(Stack&& stack) noexcept {
		m_Data = std::move(stack.m_Data);
		m_Used = stack.m_Used;
		return *this;
	}

	void Stack::Allocate(std::size_t size) {
		assert(m_Data.empty());

		m_Data.resize(size);
		m_Used = 0;
	}
	void Stack::Reallocate(std::size_t size) {
		assert(!m_Data.empty());
		assert(size > GetSize());

		m_Data.resize(size);
	}
	std::size_t Stack::GetSize() const noexcept {
		return m_Data.size();
	}
	std::size_t Stack::GetUsedSize() const noexcept {
		return m_Used;
	}
	std::size_t Stack::GetFreeSize() const noexcept {
		return GetSize() - GetUsedSize();
	}

	const Type* Stack::GetTopType() const noexcept {
		return GetTop<Type>();
	}
}