#ifndef ROW_H
#define ROW_H

#include <string>
#include <vector>

namespace bornageek {
  namespace utils {
    namespace termtab {
      class Table;
      class Cell;

      class Row {
        private:
          Table* mTable = nullptr;
          std::uint16_t mCellIndex = 0;
          std::vector<Cell> mCells;

        public:
          Row();

          Row(Table* table, const std::vector<std::string> &cells = std::vector<std::string>());

          const Table* table() const;
          
          std::vector<Cell>& cells();
          void cells(const std::vector<std::string> &cells);

          void cell(const std::string &value);
          Cell& cell(const std::uint16_t idx);

          const std::string render() const;
      };
    }
  }
}

#endif
