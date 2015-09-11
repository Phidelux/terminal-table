#include "table.h"
#include "style.h"
#include "cell.h"
#include "row.h"

#include <sstream>
#include <algorithm>
#include <functional>

namespace bornageek {
  namespace utils {
    namespace termtab {
      Row::Row() {
      }

      Row::Row(Table* table, const std::vector<std::string> &cells) 
      : mTable(table) {
        std::for_each(cells.begin(), cells.end(), 
          std::bind(static_cast<void(Row::*)(const std::string&)>(&Row::cell), 
            this, std::placeholders::_1));
      }

      const Table* Row::table() const {
        return this->mTable;
      }

      std::vector<Cell>& Row::cells() {
        return this->mCells;
      }

      void Row::cells(const std::vector<std::string> &cells) {
        std::for_each(cells.begin(), cells.end(), 
          std::bind(static_cast<void(Row::*)(const std::string&)>(&Row::cell), 
            this, std::placeholders::_1));
      }

      const std::uint16_t Row::numCells() const {
        return this->mCells.size();
      }

      const std::uint16_t Row::cellWidth(const std::uint16_t idx) const {
        if(idx < this->numCells()) {
          return this->mCells[idx].maxLineWidth();
        }

        return 0;
      }

      void Row::cellColSpan(const std::uint16_t idx, const std::uint16_t span) {
        if(span > 0 && idx < this->numCells()) {
          this->mCells[idx].colSpan(span);
        }
      }

      void Row::cell(const std::string &value) {
        Cell cell(mTable, value);
        mCells.push_back(cell);
      }

      Cell& Row::cell(const std::uint16_t idx) {
        return this->mCells[idx];
      }

      const std::uint16_t Row::height() const {
        std::uint16_t max = 1;

        std::for_each(mCells.begin(), mCells.end(),
          [&max](const Cell &cell){
            if(cell.height() > max) {
              max = cell.height();
            }
          });

        return max;
      }

      const std::string Row::render() const {
        std::uint16_t numColumns = mTable->numColumns();
        std::uint16_t numLines = this->height();

        std::stringstream ss;

        Style style = this->mTable->style();

        for(std::uint16_t l = 0; l < numLines; l++) {
          ss << style.borderLeft();

          for(std::uint16_t c = 0; c < numColumns; c++) {
            if(c < mCells.size() && mCells[c].colSpan() > 1) {
              ss << mCells[c].render(l, c); 
              c += mCells[c].colSpan() - 1;
            } else if(c < mCells.size()) {
              ss << mCells[c].render(l, c);
            } else {
              ss << std::string(mTable->columnWidth(c) 
                + mTable->style().paddingLeft() + mTable->style().paddingRight(),
                ' ');
            }

            if(c < numColumns - 1) {
              ss << style.borderMiddle();
            }
          }

          ss << style.borderRight() << std:: endl;
        }

        return ss.str();
      }
    }
  }
}
