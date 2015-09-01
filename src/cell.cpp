#include "cell.h"
#include "table.h"

#include <iostream>
#include <iomanip>

namespace bornageek {
  namespace utils {
    namespace termtab {
      Cell::Cell() {
      }

      Cell::Cell(Table* table, const std::uint16_t &idx, 
        const std::string &val, const std::uint16_t &colSpan) 
      : mTable(table), mIndex(idx), mValue(val), mColSpan(colSpan) {
        this->mWidth = val.length();
      }

      const std::string& Cell::value() const {
        return this->mValue;
      }

      void Cell::value(const std::string &val) {
        this->mValue = val;
      }

      const Alignment& Cell::alignment() const {
        return this->mAlign;
      }

      void Cell::alignment(const Alignment &align) {
        this->mAlign = align;
      }

      const std::uint16_t Cell::colSpan() const {
        return this->mColSpan;
      }

      void Cell::colSpan(const std::uint16_t &colSpan) {
        this->mColSpan = colSpan;
      }

      const std::uint16_t Cell::width() const {
        std::uint16_t padding = (mColSpan - 1) * mTable->cellSpacing();
        std::uint16_t innerWidth = 0;

        for(std::size_t i = 1; i <= mColSpan; i++) {
          innerWidth += this->mTable->columnWidth(this->mIndex + i - 1);
        }
        
        return innerWidth + padding;
      }

      void Cell::render() const {
        std::string left(this->mTable->style().paddingLeft(), ' ');
        std::string right(this->mTable->style().paddingRight(), ' ');

        switch(this->mAlign) {
          case Alignment::LEFT:
            std::cout << left << std::setw(this->width()) 
              << std::left << std::setfill(' ') << mValue << right;
            break;
          case Alignment::RIGHT:
            std::cout << left << std::setw(this->width()) 
              << std::right << std::setfill(' ') << mValue << right;
            break;
          case Alignment::CENTER:
            std::cout << left << std::setw(this->width()) 
              << std::setfill(' ') << mValue << right;
            break;
        }
      }
    }
  }
}
