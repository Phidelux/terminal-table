#include "table.h"

#include <sstream>
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
        std::for_each(this->mRows.begin(), this->mRows.end(), 
          [n, align](Row &row){ row.cells()[n].alignment(align); });
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
        std::vector<Cell> column(this->mRows.size());

        std::transform(this->mRows.begin(), this->mRows.end(), column.begin(),
          [n](Row row){ return row.cells()[n]; });

        return column;
      }

      const std::uint16_t Table::columnWidth(const std::uint16_t n) const {
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

      Row& Table::row(std::uint16_t idx) {
        return this->mRows[idx];
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
        if( this->mHeadings.numCells() > 0 ) {
          std::vector<Row> rows = this->rows();
          rows.insert(rows.begin(), this->headings());
          return rows;
        }

        return this->rows();
      }

      const std::string Table::renderSeparator(
                      char left, char mid, char right, char sep) const {
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

        std::string sep = this->renderSeparator(
          this->mStyle.borderLeftMid(), this->mStyle.borderMidMid(), 
          this->mStyle.borderRightMid(), this->mStyle.borderMid());

        ss << this->renderSeparator(
          this->mStyle.borderTopLeft(), this->mStyle.borderTopMid(), 
          this->mStyle.borderTopRight(), this->mStyle.borderTop());
        std::vector<Row> rowsWithHeadings = this->rowsWithHeadings();
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
