#include <string>

#include "styleable.h"

namespace bornageek {
  namespace utils {
    namespace termtab {
      const std::string& Styleable::borderX() const {
        return this->mBorderX;
      }

      void Styleable::borderX(std::string const &borderStyleable) {
        this->mBorderX = borderStyleable;
      }

      const std::string& Styleable::borderY() const {
        return this->mBorderY;
      }

      void Styleable::borderY(std::string const &borderStyleable) {
        this->mBorderY = borderStyleable;
      }

      const std::string& Styleable::borderE() const {
        return this->mBorderE;
      }

      void Styleable::borderE(std::string const &borderStyleable) {
        this->mBorderE = borderStyleable;
      }

      const std::uint16_t Styleable::paddingLeft() const {
        return this->mPaddingLeft;
      }

      void Styleable::paddingLeft(std::uint16_t const &padding) {
        this->mPaddingLeft = padding;
      }

      const std::uint16_t Styleable::paddingRight() const {
        return this->mPaddingRight;
      }

      void Styleable::paddingRight(std::uint16_t const &padding) {
        this->mPaddingRight = padding;
      }

      const Alignment Styleable::alignment() const {
        return this->mAlign;
      }

      void Styleable::alignment(Alignment const &align) {
        this->mAlign = align;
      }

      const std::uint16_t Styleable::width() const {
        return this->mWidth;
      }

      void Styleable::width(std::uint16_t const &width) {
        this->mWidth = width;
      }
    }
  }
}
