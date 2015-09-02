#include "separator.h"
#include "table.h"
#include "style.h"
#include "cell.h"

#include <iostream>
#include <sstream>

namespace bornageek {
  namespace utils {
    namespace termtab {
      Separator::Separator(Table* table) 
        : Row(table) {
      }

      const std::string Separator::render() const {
        std::stringstream ss;

        Style style = this->mTable->style();
        ss << style.borderLeftMid();

        for(std::size_t i = 0; i < this->mTable->numColumns(); i++) {
          std::uint16_t width = this->mTable->columnWidth(i) 
                  + style.paddingLeft() + style.paddingRight();

          for(std::size_t j = 0 ; j < width; j++ ) { 
            ss << style.borderMid();
          }

          if(i+1 < this->mTable->numColumns()) {
            ss << style.borderMidMid();
          } else {
            ss << style.borderRightMid();
          }
        }

        ss << std::endl;

        return ss.str();
      }
    }
  }
}
