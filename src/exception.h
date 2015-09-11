#ifndef TERMTAB_EXCEPTION_H
#define TERMTAB_EXCEPTION_H

#include <stdexcept>

namespace bornageek {
  namespace utils {
    namespace termtab {
      class TermtabException : public std::logic_error {
        public:
          using std::logic_error::logic_error;
      };
    }
  }
}

#endif
