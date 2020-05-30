#pragma once

#include <cstddef>
#include <cstdint>
#include <utility>
#include <variant>
#include <vector>

namespace sh {
	enum class OpCode : std::uint8_t {
		Push,
		Pop,
		LoadLocal,
		StoreLocal,
		LoadDeref,
		StoreGlobal,
		LoadGlobal,
		Call,
		Jmp,
		PopJmpIfFalse,
		FreeVar,
		Add,
		Subtract,
		Multiply,
		Divide,
		Mod,
		Equal,
		LessThan,
		GreaterThan,
		Negate,
	};

	using IntegerOperand = std::uint32_t;
	using JosaListOperand = std::vector<std::size_t>;
	using FreeListOperand = std::vector<std::pair<bool, std::size_t>>;
	using Operand = std::variant<std::monostate, IntegerOperand, JosaListOperand, FreeListOperand>;

	class Instruction final {
	public:
		sh::OpCode OpCode;
		sh::Operand Operand;

	public:
		Instruction() noexcept = default;
		Instruction(Instruction&& instruction) noexcept;
		~Instruction() = default;

	public:
		Instruction& operator=(Instruction&& instruction) noexcept;
		bool operator==(const Instruction&) = delete;
		bool operator!=(const Instruction&) = delete;
	};

	using Instructions = std::vector<Instruction>;
}