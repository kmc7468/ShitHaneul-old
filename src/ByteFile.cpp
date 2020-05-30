#include <sh/ByteFile.hpp>

#include <utility>

namespace sh {
	ByteFile::ByteFile(ByteFile&& byteFile) noexcept
		: m_FunctionInfos(std::move(byteFile.m_FunctionInfos)), m_Functions(std::move(byteFile.m_Functions)) {}
	ByteFile::~ByteFile() {
		Clear();
	}

	ByteFile& ByteFile::operator=(ByteFile&& byteFile) noexcept {
		Clear();

		m_FunctionInfos = std::move(byteFile.m_FunctionInfos);
		m_Functions = std::move(byteFile.m_Functions);
		return *this;
	}

	void ByteFile::Clear() noexcept {
		for (FunctionInfo* const functionInfo : m_FunctionInfos) {
			delete functionInfo;
		}
		for (Function* const function : m_Functions) {
			delete function;
		}
	}

	void ByteFile::AddFunctionInfo(FunctionInfo&& functionInfo) {
		m_FunctionInfos.push_back(new FunctionInfo(std::move(functionInfo)));
	}
}