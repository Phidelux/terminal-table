#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include <ostream>

#include "style.h"
#include "cell.h"
#include "row.h"

namespace bornageek {
  namespace utils {
    namespace termtab {

      class Table {
        private:      
          Style mStyle;
          std::string mTitle;
          Row mHeadings;
          std::vector<Row> mRows;

        public:
          Table();
          Table(const Style &style, const std::vector<std::vector<std::string>> &rows = std::vector<std::vector<std::string>>());

          void alignColumn(const std::uint16_t n, const Alignment &align);
          void addRow(const std::vector<std::string> &row);

          const std::uint16_t cellSpacing() const;
          const std::uint16_t cellPadding() const;

          const std::vector<Cell> column(const std::uint16_t n) const;
          const std::uint16_t columnWidth(const std::uint16_t n) const;
          const std::uint16_t numColumns() const;

          const Style style() const;
          void style(const Style &style);

          const std::string title() const;
          void title(const std::string &title);

          const Row headings() const;
          void headings(const std::vector<std::string> &headings);

          Row& row(const std::uint16_t n);
          const std::vector<Row> rows() const;
          void rows(const std::vector<std::vector<std::string>> &rows);

          const std::vector<Row> rowsWithHeadings() const;

          const std::string renderSeparator(
              const char left, const char mid, 
              const char right, const char sep) const;
          const std::string render() const;
      };

      inline std::ostream& operator<<(std::ostream &stream, Table &table) {
        return stream << table.render();
      }
    }
  }
}

#endif
