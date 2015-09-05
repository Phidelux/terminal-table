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
        {"Karl Kangaroo", "13. Sep 1988", "jumping"},
        {"Austin Ape", "24. Jul 2000", "climbing, jumping"},
        {"Bertha Bear", "3. Feb 1976", "sleeping", "Sherwood Forest"},
        {"Paul Penguin", "6. Oct 1954"}
      };

      termtab::Style style;
      style.paddingLeft(2);
      style.paddingRight(3);

      termtab::Table table(style, rows);
      table.headings({"Name", "Birthday", "Tags","Adress"});
      table.alignColumn(2, termtab::Alignment::RIGHT);
      std::cout << table;
    }
};

int main(int argc, const char* argv[]) {
  TableTest test;
  test.run();
}
