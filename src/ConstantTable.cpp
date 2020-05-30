#include <sh/ConstantTable.hpp>

#include <utility>

namespace sh {
	ConstantTable::ConstantTable(ConstantTable&& constantTable) noexcept
		: m_Table(std::move(constantTable.m_Table)) {}

	ConstantTable& ConstantTable::operator=(ConstantTable&& constantTable) noexcept {
		m_Table = std::move(constantTable.m_Table);
		return *this;
	}
	const ConstantVariant& ConstantTable::operator[](std::size_t index) const noexcept {
		return m_Table[index];
	}

	void ConstantTable::AddConstant(const ConstantVariant& constant) {
		m_Table.push_back(constant);
	}
	void ConstantTable::AddConstant(ConstantVariant&& constant) {
		m_Table.push_back(std::move(constant));
	}
}