#include <string>

#include "style.h"

namespace bornageek {
  namespace utils {
    namespace termtab {
      Style::Style() {}

      Style::Style(const Style &s) 
        : mBorderX(s.mBorderX), mBorderY(s.mBorderY), mBorderE(s.mBorderE),
        mPaddingLeft(s.mPaddingLeft), mPaddingRight(s.mPaddingRight),
        mAlign(s.mAlign), mWidth(s.mWidth)
      {}
      
      const std::string& Style::borderX() const {
        return this->mBorderX;
      }

      void Style::borderX(const std::string  &borderStyle) {
        this->mBorderX = borderStyle;
      }

      const std::string& Style::borderY() const {
        return this->mBorderY;
      }

      void Style::borderY(const std::string &borderStyle) {
        this->mBorderY = borderStyle;
      }

      const std::string& Style::borderE() const {
        return this->mBorderE;
      }

      void Style::borderE(const std::string &borderStyle) {
        this->mBorderE = borderStyle;
      }

      const std::uint16_t Style::paddingLeft() const {
        return this->mPaddingLeft;
      }

      void Style::paddingLeft(const std::uint16_t &padding) {
        this->mPaddingLeft = padding;
      }

      const std::uint16_t Style::paddingRight() const {
        return this->mPaddingRight;
      }

      void Style::paddingRight(const std::uint16_t &padding) {
        this->mPaddingRight = padding;
      }

      const Alignment Style::alignment() const {
        return this->mAlign;
      }

      void Style::alignment(const Alignment &align) {
        this->mAlign = align;
      }

      const std::uint16_t Style::width() const {
        return this->mWidth;
      }

      void Style::width(const std::uint16_t &width) {
        this->mWidth = width;
      }
    }
  }
}
