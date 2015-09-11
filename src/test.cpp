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
        {"Austin Ape", "24. Jul 2000", "climbing, jumping,\nsurfing"},
        {"..."},
        {"Bertha Bear", "3. Feb 1976", "sleeping", "Sherwood Forest"},
        {"Toni Tiger", "31. Jan 1935", "sleeping, hunting"},
        {"Paul Penguin", "6. Oct 1954"},
        {"Gira Giraffe", "10. Sep 1943", "", "London Zoo"},
        {"To be continued ..."}
      };

      termtab::Style style;
      style.paddingLeft(3);
      style.paddingRight(2);

      style.borderTop('=');
      style.borderTopMid('#');
      style.borderTopLeft('@');
      style.borderTopRight('@');
      style.borderBottom('=');
      style.borderBottomMid('#');
      style.borderBottomLeft('@');
      style.borderBottomRight('@');
      style.borderLeft('[');
      style.borderLeftMid('#');
      style.borderMid('-');
      style.borderMidMid('+');
      style.borderRight(']');
      style.borderRightMid('#');
      style.borderMiddle('|');

      termtab::Table table(style, rows);
      table.title("A simple Test-Table");
      table.headings({"Name", "Birthday", "Tags", "Adress"});
      table.alignColumn(1, termtab::Alignment::RIGHT);
      table.alignColumn(2, termtab::Alignment::CENTER);
      table.row(2).cell(0).colSpan(4);
      table.row(7).cell(0).colSpan(3);

      try {
        table.alignColumn(5, termtab::Alignment::RIGHT);
      } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
      }

      std::cout << table;
    }
};

int main(int argc, const char* argv[]) {
  TableTest test;
  test.run();
}
