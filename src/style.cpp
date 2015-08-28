#include <string>

#include "style.h"

namespace bornageek {
  namespace utils {
    namespace termtab {
      const std::string& Style::borderX() const {
        return this->mBorderX;
      }

      void Style::borderX(std::string const &borderStyle) {
        this->mBorderX = borderStyle;
      }

      const std::string& Style::borderY() const {
        return this->mBorderY;
      }

      void Style::borderY(std::string const &borderStyle) {
        this->mBorderY = borderStyle;
      }

      const std::string& Style::borderE() const {
        return this->mBorderE;
      }

      void Style::borderE(std::string const &borderStyle) {
        this->mBorderE = borderStyle;
      }

      const std::uint16_t Style::paddingLeft() const {
        return this->mPaddingLeft;
      }

      void Style::paddingLeft(std::uint16_t const &padding) {
        this->mPaddingLeft = padding;
      }

      const std::uint16_t Style::paddingRight() const {
        return this->mPaddingRight;
      }

      void Style::paddingRight(std::uint16_t const &padding) {
        this->mPaddingRight = padding;
      }

      const std::uint16_t Style::width() const {
        return this->mWidth;
      }

      void Style::width(std::uint16_t const &width) {
        this->mWidth = width;
      }
    }
  }
}
