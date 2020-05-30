#pragma once

#include <sh/Constant.hpp>

#include <cstddef>
#include <vector>

namespace sh {
	class ConstantTable final {
	private:
		std::vector<ConstantVariant> m_Table;

	public:
		ConstantTable() noexcept = default;
		ConstantTable(ConstantTable&& constantTable) noexcept;
		~ConstantTable() = default;

	public:
		ConstantTable& operator=(ConstantTable&& constantTable) noexcept;
		bool operator==(const ConstantTable&) = delete;
		bool operator!=(const ConstantTable&) = delete;
		const ConstantVariant& operator[](std::size_t index) const noexcept;

	public:
		void AddConstant(const ConstantVariant& constant);
		void AddConstant(ConstantVariant&& constant);
	};
}