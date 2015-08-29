#include <string>
#include <vector>

#include "style.h"

namespace bornageek {
  namespace utils {
    namespace termtab {
      class Table {
        Style mStyle;
        std::string mTitle;
        std::vector<std::string> mHeadings;
        std::vector<std::vector<std::string>> mRows;

        Table();
        Table(const Style &style, std::vector<std::vector<std::string>> &rows);

        void alignColumn(const Alignment &align);
        void addRow(const std::vector<std::string> &row);

        std::uint16_t cellSpacing() const;
        std::uint16_t cellPadding() const;

        const std::vector<string>& column(std::uint16_t n) const;
        const std::vector<std::vector<std::string>>& columns() const;
        const std::uint16_t columnWidth(std::uint16_t n) const;
        const std::uint16_t numColumns();

        const Style style() const;
        void style(const Styl &style);

        const std::string title() const;
        void title(const std::string & title);

        const std::vector<std::string> headings() const;
        void headings(const std::vector<string> &headings);

        const std::vector<std::vector<std::string>> rows() const;
        void rows(const vector<std::vector<std::string>> &rows);

        void render();
      };
    }
  }
}
