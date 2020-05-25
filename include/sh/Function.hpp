#pragma once

#include <sh/Constant.hpp>
#include <sh/ConstantTable.hpp>
#include <sh/Instruction.hpp>

#include <cstddef>
#include <vector>

namespace sh {
	class FunctionInfo final {
	public:
		std::vector<Constant*> GlobalTable;
		sh::ConstantTable ConstantTable;
		sh::Instructions Instructions;
		std::size_t LocalCount = 0;

	public:
		FunctionInfo() noexcept = default;
		FunctionInfo(std::vector<Constant*>&& globalTable, sh::ConstantTable&& constantTable,
			sh::Instructions&& instructions, std::size_t localCount) noexcept;
		FunctionInfo(FunctionInfo&& functionInfo) noexcept;
		~FunctionInfo() = default;

	public:
		FunctionInfo& operator=(FunctionInfo&& functionInfo) noexcept;
		bool operator==(const FunctionInfo&) = delete;
		bool operator!=(const FunctionInfo&) = delete;
	};

	class Function final {
	public:
		const FunctionInfo* Info = nullptr;
		std::vector<ConstantVariant> FreeTable;

	public:
		Function() noexcept = default;
		explicit Function(const FunctionInfo* functionInfo) noexcept;
		Function(Function&& function) noexcept;
		~Function() = default;

	public:
		Function& operator=(Function&& function) noexcept;
		bool operator==(const Function&) = delete;
		bool operator!=(const Function&) = delete;
	};
}