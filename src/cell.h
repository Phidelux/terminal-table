#ifndef CELL_H
#define CELL_H

#include <string>
#include <ostream>

#include "style.h"

namespace bornageek {
  namespace utils {
    namespace termtab {
      class Table;

      class Cell {
        private:
          Table* mTable = nullptr;
          std::string mValue = "";
          Alignment mAlign = Alignment::LEFT;
          std::uint16_t mColSpan = 1;
          std::uint16_t mWidth = 0;

        public:
          Cell();

          Cell(Table* table, const std::string &val = "", 
              const std::uint16_t &colSpan = 1);

          const std::string& value() const;
          void value(const std::string &val);

          const Alignment& alignment() const;
          void alignment(const Alignment &align);

          const std::uint16_t colSpan() const;
          void colSpan(const std::uint16_t &colSpan);

          const std::uint16_t width(const std::uint16_t col) const;
          const std::uint16_t height() const;

          const std::uint16_t maxLineWidth() const;

          const std::string line(const std::uint16_t idx) const;
          void trimLine(std::string &line) const;

          const std::string render(const std::uint16_t line, const std::uint16_t col) const;
      };
    }
  }
}

#endif
