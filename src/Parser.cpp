#include <sh/Parser.hpp>

#include <cassert>
#include <fstream>
#include <ios>
#include <stdexcept>
#include <utility>

namespace sh {
	Parser::Parser(Parser&& parser) noexcept
		: m_Data(std::move(parser.m_Data)), m_Cursor(parser.m_Cursor) {}

	Parser& Parser::operator=(Parser&& parser) noexcept {
		m_Data = std::move(parser.m_Data);
		m_Cursor = parser.m_Cursor;
		return *this;
	}

	void Parser::Load(const std::string& path) {
		std::ifstream stream(path, std::ifstream::binary);
		if (!stream) throw std::runtime_error("Failed to open the file.");

		stream.seekg(0, std::ifstream::end);
		const std::streamsize length = stream.tellg();
		stream.seekg(0, std::ifstream::beg);

		m_Data.clear();
		m_Cursor = 0;

		if (length) {
			std::vector<std::uint8_t> bytes(static_cast<std::size_t>(length));
			stream.read(reinterpret_cast<char*>(bytes.data()), length);
			if (stream.gcount() != length) throw std::runtime_error("Failed to read the file.");

			m_Data = std::move(bytes);
		}
	}
	ByteFile Parser::Parse() {
		assert(!m_Data.empty());

		ByteFile result;
		// TODO

		return result;
	}
}