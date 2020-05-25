#pragma once

#include <sh/Function.hpp>

#include <vector>

namespace sh {
	class ByteFile final {
	private:
		FunctionInfos m_FunctionInfos;
		Functions m_Functions;

	public:
		ByteFile() noexcept = default;
		ByteFile(FunctionInfos&& functionInfos) noexcept;
		ByteFile(ByteFile&& byteFile) noexcept;
		~ByteFile();

	public:
		ByteFile& operator=(ByteFile&& byteFile) noexcept;
		bool operator==(const ByteFile&) = delete;
		bool operator!=(const ByteFile&) = delete;

	public:
		FunctionInfo* AddFunctionInfo();
		void ReserveFunctionInfos(std::size_t size);
	};
}