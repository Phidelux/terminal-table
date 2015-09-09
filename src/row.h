#ifndef ROW_H
#define ROW_H

#include <string>
#include <vector>
#include <ostream>

namespace bornageek {
  namespace utils {
    namespace termtab {
      class Table;
      class Cell;

      class Row {
        protected:
          Table* mTable = nullptr;
          std::vector<Cell> mCells;

        public:
          Row();

          Row(Table* table, const std::vector<std::string> &cells = std::vector<std::string>());

          const Table* table() const;
          
          std::vector<Cell>& cells();
          void cells(const std::vector<std::string> &cells);

          const std::uint16_t numCells() const;
          const std::uint16_t cellWidth(const std::uint16_t idx) const;
          void cellColSpan(const std::uint16_t idx, std::uint16_t span);

          void cell(const std::string &value);
          Cell& cell(const std::uint16_t idx);

          const std::uint16_t height() const;

          const std::string render() const;
      };

      inline std::ostream& operator<<(std::ostream& stream, const Row &row) {
        return stream << row.render();
      }
    }
  }
}

#endif
