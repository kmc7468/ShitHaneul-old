#pragma once

#include <cstdint>

namespace sh {
	enum class Type {
		None,
		Integer,
		Real,
		Boolean,
		Character,
		Function,
	};

	class Constant {
	private:
		Type m_Type;

	protected:
		explicit Constant(Type type) noexcept;
		Constant(const Constant& constant) noexcept;

	public:
		~Constant() = default;

	protected:
		Constant& operator=(const Constant& constant) noexcept;

	public:
		bool operator==(const Constant&) = delete;
		bool operator!=(const Constant&) = delete;

	public:
		Type GetType() const noexcept;
	};

	class IntegerConstant final : public Constant {
	public:
		std::int64_t Value = 0;

	public:
		IntegerConstant() noexcept = default;
		IntegerConstant(std::int64_t value) noexcept;
		IntegerConstant(const IntegerConstant& constant) noexcept;
		~IntegerConstant() = default;

	public:
		IntegerConstant& operator=(const IntegerConstant& constant) noexcept;
		bool operator==(const IntegerConstant&) = delete;
		bool operator!=(const IntegerConstant&) = delete;
	};

	class RealConstant final : public Constant {
	public:
		double Value = 0;

	public:
		RealConstant() noexcept = default;
		RealConstant(double value) noexcept;
		RealConstant(const RealConstant& constant) noexcept;
		~RealConstant() = default;

	public:
		RealConstant& operator=(const RealConstant& constant) noexcept;
		bool operator==(const RealConstant&) = delete;
		bool operator!=(const RealConstant&) = delete;
	};

	class BooleanConstant final : public Constant {
	public:
		bool Value = 0;

	public:
		BooleanConstant() noexcept = default;
		BooleanConstant(bool value) noexcept;
		BooleanConstant(const BooleanConstant& constant) noexcept;
		~BooleanConstant() = default;

	public:
		BooleanConstant& operator=(const BooleanConstant& constant) noexcept;
		bool operator==(const BooleanConstant&) = delete;
		bool operator!=(const BooleanConstant&) = delete;
	};

	class CharacterConstant final : public Constant {
	public:
		char32_t Value = 0;

	public:
		CharacterConstant() noexcept = default;
		CharacterConstant(char32_t value) noexcept;
		CharacterConstant(const CharacterConstant& constant) noexcept;
		~CharacterConstant() = default;

	public:
		CharacterConstant& operator=(const CharacterConstant& constant) noexcept;
		bool operator==(const CharacterConstant&) = delete;
		bool operator!=(const CharacterConstant&) = delete;
	};
}