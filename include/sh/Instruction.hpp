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

	class Instruction final {
	public:
		sh::OpCode OpCode;
		std::variant<std::monostate, std::uint32_t, std::vector<std::size_t>,
			std::vector<std::pair<bool, std::size_t>>> Operand;

	public:
		Instruction() noexcept = default;
		explicit Instruction(sh::OpCode opCode) noexcept;
		Instruction(sh::OpCode opCode, std::uint32_t operand) noexcept;
		Instruction(sh::OpCode opCode, std::vector<std::size_t>&& operand) noexcept;
		Instruction(sh::OpCode opCode, std::vector<std::pair<bool, std::size_t>>&& operand) noexcept;
		Instruction(Instruction&& instruction) noexcept;
		~Instruction() = default;

	public:
		Instruction& operator=(Instruction&& instruction) noexcept;
		bool operator==(const Instruction&) = delete;
		bool operator!=(const Instruction&) = delete;
	};

	using Instructions = std::vector<Instruction>;
}