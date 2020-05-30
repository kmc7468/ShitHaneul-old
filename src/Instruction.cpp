#include <sh/Instruction.hpp>

namespace sh {
	Instruction::Instruction(Instruction&& instruction) noexcept
		: OpCode(instruction.OpCode), Operand(std::move(instruction.Operand)) {}

	Instruction& Instruction::operator=(Instruction&& instruction) noexcept {
		OpCode = instruction.OpCode;
		Operand = std::move(instruction.Operand);
		return *this;
	}
}