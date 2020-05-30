#pragma once

#include <sh/Function.hpp>

namespace sh {
	class ByteFile final {
	private:
		FunctionInfos m_FunctionInfos;
		Functions m_Functions;

	public:
		ByteFile() noexcept = default;
		ByteFile(ByteFile&& byteFile) noexcept;
		~ByteFile();

	public:
		ByteFile& operator=(ByteFile&& byteFile) noexcept;
		bool operator==(const ByteFile&) = delete;
		bool operator!=(const ByteFile&) = delete;

	public:
		void Clear() noexcept;

		void AddFunctionInfo(FunctionInfo&& functionInfo);
	};
}