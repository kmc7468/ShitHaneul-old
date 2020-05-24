#pragma once

#include <cstdint>

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
}