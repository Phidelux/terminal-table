#include "table.h"

#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <functional>

namespace bornageek {
  namespace utils {
    namespace termtab {
       
      Table::Table() {
      }

      Table::Table(const Style &style, const std::vector<std::vector<std::string>> &rows) 
      : mStyle(style) {
        this->rows(rows);
      }

      void Table::alignColumn(const std::uint16_t n, const Alignment &align) {
        if(n > this->numColumns()) {
          throw std::out_of_range("The table just has " 
                + std::to_string(this->numColumns()) + " columns.");
        }

        std::for_each(this->mRows.begin(), this->mRows.end(), 
          [n, align](Row &row){ 
            if(row.numCells() > n) {
              row.cells()[n].alignment(align);
            }
          });
      }

      void Table::addRow(const std::vector<std::string> &row) {
        this->mRows.push_back(Row(this, row));
      }

      const std::uint16_t Table::cellSpacing() const {
        return this->cellPadding() + 1;
      }

      const std::uint16_t Table::cellPadding() const {
        return this->mStyle.paddingLeft() + this->mStyle.paddingRight();
      }

      const std::vector<Cell> Table::column(const std::uint16_t n) const {
        if(n > this->numColumns()) {
          throw std::out_of_range("The table just has " 
                + std::to_string(this->numColumns()) + " columns.");
        }

        std::vector<Cell> column(this->mRows.size());

        std::transform(this->mRows.begin(), this->mRows.end(), column.begin(),
          [n](Row row){ return row.cells()[n]; });

        return column;
      }

      const std::uint16_t Table::columnWidth(const std::uint16_t n) const {
        if(n > this->numColumns()) {
          throw std::out_of_range("The table just has " 
                + std::to_string(this->numColumns()) + " columns.");
        }

        std::uint16_t max = 0;

        std::vector<Row> rows = this->rowsWithHeadings();
        std::for_each(rows.begin(), rows.end(),
          [&max, n](const Row &row) { 
            if(n < row.numCells() && row.cellWidth(n) > max) {
              max = row.cellWidth(n);
            } 
          });

        return max;
      }

      const std::uint16_t Table::numColumns() const {
        std::uint16_t max = 0;
        std::vector<Row> rows = this->rowsWithHeadings();
        std::for_each(rows.begin(), rows.end(),
          [&max](const Row &row) {
            if(row.numCells() > max) {
              max = row.numCells();
            }
          });

        return max;
      }

      const Style Table::style() const {
        return this->mStyle;
      }

      void Table::style(const Style &style) {
        this->mStyle = style;
      }

      const std::string Table::title() const {
        return this->mTitle;
      }

      void Table::title(const std::string & title) {
        this->mTitle = title;
      }

      const Row Table::headings() const {
        return this->mHeadings;
      }

      void Table::headings(const std::vector<std::string> &headings) {
        this->mHeadings = Row(this, headings);
      }

      Row& Table::row(const std::uint16_t n) {
        if(n >= this->mRows.size()) {
          throw std::out_of_range("The table just has " 
                + std::to_string(this->mRows.size()) + " rows.");
        }

        return this->mRows[n];
      }

      const std::vector<Row> Table::rows() const {
        return this->mRows;
      }

      void Table::rows(const std::vector<std::vector<std::string>> &rows) {
        this->mRows = std::vector<Row>();
        for_each(rows.begin(), rows.end(), 
          [this](const std::vector<std::string> &row) { 
            mRows.push_back(Row(this, row)); });
      }

      const std::vector<Row> Table::rowsWithHeadings() const {
        std::vector<Row> rows = this->rows();

        if(this->mHeadings.numCells() > 0) {
          rows.insert(rows.begin(), this->headings());
        }

        return rows;
      }

      const std::string Table::renderSeparator(
            const char left, const char mid, 
            const char right, const char sep) const {
        std::stringstream ss;

        ss << left;

        for(std::size_t i = 0; i < this->numColumns(); i++) {
          std::uint16_t width = this->columnWidth(i) 
                  + this->mStyle.paddingLeft() + this->mStyle.paddingRight();

          for(std::size_t j = 0 ; j < width; j++ ) { 
            ss << sep;
          }

          if(i+1 < this->numColumns()) {
            ss << mid;
          } else {
            ss << right;
          }
        }

        ss << std::endl;

        return ss.str();
      }

      const std::string Table::render() const {
        std::stringstream ss;

        std::vector<Row> rowsWithHeadings = this->rowsWithHeadings();
        
        std::string sep = this->renderSeparator(
          this->mStyle.borderLeftMid(), this->mStyle.borderMidMid(), 
          this->mStyle.borderRightMid(), this->mStyle.borderMid());

        if(this->mTitle.length() > 0) {
          std::uint16_t innerWidth = (this->numColumns() - 1) 
              * this->cellSpacing() + this->cellPadding();

          for(std::uint16_t c = 0; c < this->numColumns(); c++) {
            innerWidth += this->columnWidth(c);
          }

          std::uint16_t spaceLeft = innerWidth / 2 - mTitle.length() / 2;

          ss << this->mStyle.borderTopLeft() 
             << std::string(innerWidth, this->mStyle.borderTop())
             << this->mStyle.borderTopRight() << std::endl; 
          ss << this->mStyle.borderLeft() 
             << std::string(spaceLeft, ' ') << std::left 
             << std::setw(innerWidth - spaceLeft) << std::setfill(' ') 
             << this->mTitle; 
          ss << this->mStyle.borderRight() << std::endl << sep;
        } else {
          ss << this->renderSeparator(
            this->mStyle.borderTopLeft(), this->mStyle.borderTopMid(), 
            this->mStyle.borderTopRight(), this->mStyle.borderTop());
        }

        std::for_each(rowsWithHeadings.begin(), --rowsWithHeadings.end(),
          [&ss, sep, rowsWithHeadings](Row row){ 
            if(row.cells().size() > 0) {
              ss << row << sep; 
            }
          });

        if( rowsWithHeadings.size() > 0) {
          ss << rowsWithHeadings.back() << this->renderSeparator(
            this->mStyle.borderBottomLeft(), this->mStyle.borderBottomMid(), 
            this->mStyle.borderBottomRight(), this->mStyle.borderBottom());
        }

        return ss.str();
      }
    }
  }
}
