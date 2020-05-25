#pragma once

#include <sh/ByteFile.hpp>

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace sh {
	class Parser final {
	private:
		std::vector<std::uint8_t> m_Data;
		std::size_t m_Cursor = 0;

	public:
		Parser() noexcept = default;
		Parser(Parser&& parser) noexcept;
		~Parser() = default;

	public:
		Parser& operator=(Parser&& parser) noexcept;
		bool operator==(const Parser&) = delete;
		bool operator!=(const Parser&) = delete;

	public:
		void Load(const std::string& path);
		ByteFile Parse();
	};
}