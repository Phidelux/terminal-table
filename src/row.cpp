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
        this->mCells = std::vector<Cell>();
        this->mCellIndex = 0;
        std::for_each(cells.begin(), cells.end(), 
          [this](std::string value) { 
            Cell cell(mTable, mCellIndex, value);     
            mCells.push_back(cell);
            mCellIndex += cell.colSpan();
          });
      }

      const std::uint16_t Row::numCells() const {
        return this->mCells.size();
      }

      void Row::cell(const std::string &value) {
        Cell cell(mTable, mCellIndex, value);
        mCells.push_back(cell);
        mCellIndex += cell.colSpan();
      }

      Cell& Row::cell(const std::uint16_t idx) {
        return this->mCells[idx];
      }

      const std::string Row::render() const {
        std::stringstream ss;

        Style style = this->mTable->style();
        ss << style.borderLeft();

        for(std::uint16_t i = 0; i < mTable->numColumns(); i++) {
          if(i < mCells.size() - 1 && i < mTable->numColumns() - 1) {
            ss << mCells[i] << style.borderMiddle();
          } else if(i == mCells.size() - 1 && i == mTable->numColumns() - 1) {
            ss << mCells[i] << style.borderRight();
          } else {
            std::uint16_t space = mTable->columnWidth(i) 
              + mTable->style().paddingLeft() + mTable->style().paddingRight();
            
            if(i < mTable->numColumns() - 1) {
              ss << std::string(space, ' ') << style.borderMiddle();
            } else {
              ss << std::string(space, ' ') << style.borderRight();
            }
          }
        }

        ss << std::endl;

        return ss.str();
      }
    }
  }
}
