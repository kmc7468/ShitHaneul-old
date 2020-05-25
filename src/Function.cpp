#include <sh/Function.hpp>

namespace sh {
	FunctionInfo::FunctionInfo(std::vector<Constant*>&& globalTable, sh::ConstantTable&& constantTable,
		sh::Instructions&& instructions, std::size_t localCount) noexcept
		: GlobalTable(std::move(globalTable)), ConstantTable(std::move(constantTable)),
		Instructions(std::move(instructions)), LocalCount(localCount) {}
	FunctionInfo::FunctionInfo(FunctionInfo&& functionInfo) noexcept
		: GlobalTable(std::move(functionInfo.GlobalTable)), ConstantTable(std::move(functionInfo.ConstantTable)),
		Instructions(std::move(functionInfo.Instructions)), LocalCount(functionInfo.LocalCount) {}

	FunctionInfo& FunctionInfo::operator=(FunctionInfo&& functionInfo) noexcept {
		GlobalTable = std::move(functionInfo.GlobalTable);
		ConstantTable = std::move(functionInfo.ConstantTable);
		Instructions = std::move(functionInfo.Instructions);
		LocalCount = functionInfo.LocalCount;
		return *this;
	}
}

namespace sh {
	Function::Function(const FunctionInfo* functionInfo) noexcept
		: Info(functionInfo) {}
	Function::Function(Function&& function) noexcept
		: Info(function.Info), JosaTable(std::move(function.JosaTable)),
		FreeTable(std::move(function.FreeTable)) {}

	Function& Function::operator=(Function&& function) noexcept {
		Info = function.Info;
		JosaTable = std::move(function.JosaTable);
		FreeTable = std::move(function.FreeTable);
		return  *this;
	}
}