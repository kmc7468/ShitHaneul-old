#include <sh/Instruction.hpp>

namespace sh {
	Instruction::Instruction(sh::OpCode opCode) noexcept
		: OpCode(opCode) {}
	Instruction::Instruction(sh::OpCode opCode, std::uint32_t operand) noexcept
		: OpCode(opCode), Operand(operand) {}
	Instruction::Instruction(sh::OpCode opCode, std::vector<std::size_t>&& operand) noexcept
		: OpCode(opCode), Operand(std::move(operand)) {}
	Instruction::Instruction(sh::OpCode opCode, std::vector<std::pair<bool, std::size_t>>&& operand) noexcept
		: OpCode(opCode), Operand(std::move(operand)) {}
	Instruction::Instruction(Instruction&& instruction) noexcept
		: OpCode(instruction.OpCode), Operand(std::move(instruction.Operand)) {}

	Instruction& Instruction::operator=(Instruction&& instruction) noexcept {
		OpCode = instruction.OpCode;
		Operand = std::move(instruction.Operand);
		return *this;
	}
}