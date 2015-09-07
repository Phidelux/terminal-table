#include "cell.h"
#include "table.h"

#include <iostream>

#include <limits>
#include <sstream>
#include <iomanip>
#include <algorithm>

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

      const std::uint16_t Cell::height() const {
        return std::count(this->mValue.begin(), this->mValue.end(), '\n') + 1;
      }

      const std::uint16_t Cell::maxLineWidth() const {
        std::uint16_t max = 0;
        std::string line;

        std::istringstream stream(this->mValue);
        while(std::getline(stream, line)) {
          if(line.length() > max) {
            max = line.length();
          }
        }

        return max;
      }

      const std::string Cell::line(std::uint16_t idx) const {
        if(idx < this->height()) {
          std::istringstream stream(this->mValue);
          std::string line;
          line.reserve(4048);    
        
          for(int i = 0; i < idx; ++i) {
            std::getline(stream, line);
          }

          std::getline(stream, line);

          this->trimLine(line);

          return line;
        }
        
        return "";
      }

      void Cell::trimLine(std::string &line) const {
        line.erase(line.begin(), std::find_if(
          line.begin(), line.end(), std::not1(
            std::ptr_fun<int, int>(std::isspace)
          )));

        line.erase(std::find_if(line.rbegin(), line.rend(), 
          std::not1(std::ptr_fun<int, int>(std::isspace))).base(), line.end());
      }

      const std::string Cell::render(std::uint16_t lineIdx) const {
        std::stringstream ss;

        std::uint16_t width = this->width();

        std::string left(this->mTable->style().paddingLeft(), ' ');
        std::string right(this->mTable->style().paddingRight(), ' ');

        switch(this->mAlign) {
          case Alignment::LEFT:
            ss << left << std::setw(width) 
              << std::left << std::setfill(' ') << this->line(lineIdx) << right;
            break;
          case Alignment::RIGHT:
            ss << left << std::setw(width) 
              << std::right << std::setfill(' ') << this->line(lineIdx) << right;
            break;
          case Alignment::CENTER:
            ss << left << std::setw(width) 
              << std::setfill(' ') << this->line(lineIdx) << right;
            break;
        }

        return ss.str();
      }
    }
  }
}
