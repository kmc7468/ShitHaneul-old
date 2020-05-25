#include <sh/Constant.hpp>

namespace sh {
	Constant::Constant(Type type) noexcept
		: m_Type(type) {}
	Constant::Constant(const Constant& constant) noexcept
		: m_Type(constant.m_Type) {}

	Constant& Constant::operator=(const Constant& constant) noexcept {
		m_Type = constant.m_Type;
		return *this;
	}

	Type Constant::GetType() const noexcept {
		return m_Type;
	}
}

namespace sh {
	IntegerConstant::IntegerConstant(std::int64_t value) noexcept
		: Constant(Type::Integer), Value(value) {}
	IntegerConstant::IntegerConstant(const IntegerConstant& constant) noexcept
		: Constant(Type::Integer), Value(constant.Value) {}

	IntegerConstant& IntegerConstant::operator=(const IntegerConstant& constant) noexcept {
		Constant::operator=(constant);

		Value = constant.Value;
		return *this;
	}
}

namespace sh {
	RealConstant::RealConstant(double value) noexcept
		: Constant(Type::Real), Value(value) {}
	RealConstant::RealConstant(const RealConstant& constant) noexcept
		: Constant(Type::Real), Value(constant.Value) {}

	RealConstant& RealConstant::operator=(const RealConstant& constant) noexcept {
		Constant::operator=(constant);

		Value = constant.Value;
		return *this;
	}
}

namespace sh {
	BooleanConstant::BooleanConstant(bool value) noexcept
		: Constant(Type::Boolean), Value(value) {}
	BooleanConstant::BooleanConstant(const BooleanConstant& constant) noexcept
		: Constant(Type::Boolean), Value(constant.Value) {}

	BooleanConstant& BooleanConstant::operator=(const BooleanConstant& constant) noexcept {
		Constant::operator=(constant);

		Value = constant.Value;
		return *this;
	}
}

namespace sh {
	CharacterConstant::CharacterConstant(char32_t value) noexcept
		: Constant(Type::Character), Value(value) {}
	CharacterConstant::CharacterConstant(const CharacterConstant& constant) noexcept
		: Constant(Type::Character), Value(constant.Value) {}

	CharacterConstant& CharacterConstant::operator=(const CharacterConstant& constant) noexcept {
		Constant::operator=(constant);

		Value = constant.Value;
		return *this;
	}
}

namespace sh {
	FunctionConstant::FunctionConstant(Function* value) noexcept
		: Constant(Type::Function), Value(value) {}
	FunctionConstant::FunctionConstant(const FunctionConstant& constant) noexcept
		: Constant(Type::Function), Value(constant.Value) {}

	FunctionConstant& FunctionConstant::operator=(const FunctionConstant& constant) noexcept {
		Constant::operator=(constant);

		Value = constant.Value;
		return *this;
	}
}