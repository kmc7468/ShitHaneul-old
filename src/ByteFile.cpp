#include <sh/ByteFile.hpp>

#include <cassert>

namespace sh {
	ByteFile::ByteFile(FunctionInfos&& functionInfos) noexcept
		: m_FunctionInfos(std::move(functionInfos)) {}
	ByteFile::ByteFile(ByteFile&& byteFile) noexcept
		: m_FunctionInfos(std::move(byteFile.m_FunctionInfos)), m_Functions(std::move(byteFile.m_Functions)) {}
	ByteFile::~ByteFile() {
		for (FunctionInfo* const functionInfo : m_FunctionInfos) {
			delete functionInfo;
		}
		for (Function* const function : m_Functions) {
			delete function;
		}
	}

	ByteFile& ByteFile::operator=(ByteFile&& byteFile) noexcept {
		ByteFile::~ByteFile();

		m_FunctionInfos = std::move(byteFile.m_FunctionInfos);
		m_Functions = std::move(byteFile.m_Functions);
		return *this;
	}

	FunctionInfo* ByteFile::AddFunctionInfo() {
		return m_FunctionInfos.emplace_back(new FunctionInfo);
	}
	void ByteFile::ReserveFunctionInfos(std::size_t size) {
		assert(size > m_FunctionInfos.size());

		m_FunctionInfos.reserve(size);
	}
}