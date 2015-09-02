#ifndef SEPARATOR_H
#define SEPARATOR_H

#include "row.h"

namespace bornageek {
  namespace utils {
    namespace termtab {
      class Separator : public Row {
        public:
          Separator(Table* table);
          const std::string render() const;
      };

      inline std::ostream& operator<<(std::ostream& stream, const Separator &s) {
        return stream << s.render();
      }
    }
  }
}

#endif
