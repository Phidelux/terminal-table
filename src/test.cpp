#include <iostream>
#include <vector>
#include <string>

#include "table.h"
#include "style.h"

namespace termtab = bornageek::utils::termtab;

class TableTest {
  public:
    TableTest() {
      std::cout << "Starting table test ..." << std::endl << std::endl;
    }

    ~TableTest() {
      std::cout << std::endl << "Stopping table test ..." << std::endl;
    }

    void run() {
      std::vector<std::vector<std::string>> rows{
        {"Lorem", "ipsum", "dolor"},
        {"Sit", "amet", "consectetur"},
        {"Adipiscing", "elit", "sed"},
        {"Do", "ex", ""}
      };

      termtab::Style style;
      style.paddingLeft(2);
      style.paddingRight(3);
      style.borderY(":");

      termtab::Table table(style, rows);
      table.alignColumn(2, termtab::Alignment::RIGHT);
      std::cout << table;
    }
};

int main(int argc, const char* argv[]) {
  TableTest test;
  test.run();
}
