#include "style.h"

namespace bornageek {
  namespace utils {
    namespace termtab {
      Style::Style() {}

      Style::Style(const Style &s) 
        : mBorderTop(s.mBorderTop), mBorderTopMid(s.mBorderTopMid),
        mBorderTopLeft(s.mBorderTopLeft), mBorderTopRight(s.mBorderTopRight),
        mBorderBottom(s.mBorderBottom), mBorderBottomMid(s.mBorderBottomMid),
        mBorderBottomLeft(s.mBorderBottomLeft), mBorderBottomRight(s.mBorderBottomRight),
        mBorderLeft(s.mBorderLeft), mBorderLeftMid(s.mBorderLeftMid),
        mBorderMid(s.mBorderMid), mBorderMidMid(s.mBorderMidMid),
        mBorderRight(s.mBorderRight), mBorderRightMid(s.mBorderRightMid),
        mBorderMiddle(s.mBorderMiddle), mPaddingLeft(s.mPaddingLeft),
        mPaddingRight(s.mPaddingRight), mAlign(s.mAlign), mWidth(s.mWidth)
      {}
      
      const char& Style::borderTop() const {
        return this->mBorderTop;
      }

      void Style::borerTop(const char &borderStyle) {
        this->mBorderTop = borderStyle;
      }

      const char& Style::borderTopMid() const {
        return this->mBorderTopMid;
      }

      void Style::borderTopMid(const char &borderStyle) {
        this->mBorderTopMid = borderStyle;
      }

      const char& Style::borderTopLeft() const {
        return this->mBorderTopLeft;
      }

      void Style::borderTopLeft(const char &borderStyle) {
        this->mBorderTopLeft = borderStyle;
      }

      const char& Style::borderTopRight() const {
        return this->mBorderTopRight;
      }

      void Style::borderTopRight(const char &borderStyle) {
        this->mBorderTopRight = borderStyle;
      }

      const char& Style::borderBottom() const {
        return this->mBorderBottom;
      }

      void Style::borderBottom(const char &borderStyle) {
        this->mBorderBottom = borderStyle;
      }

      const char& Style::borderBottomMid() const {
        return this->mBorderBottomMid;
      }

      void Style::borderBottomMid(const char &borderStyle) {
        this->mBorderBottomMid = borderStyle;
      }

      const char& Style::borderBottomLeft() const {
        return this->mBorderBottomLeft;
      }

      void Style::borderBottomLeft(const char &borderStyle) {
        this->mBorderBottomLeft = borderStyle;
      }

      const char& Style::borderBottomRight() const {
        return this->mBorderBottomRight;
      }

      void Style::borderBottomRight(const char &borderStyle) {
        this->mBorderBottomRight = borderStyle;
      }

      const char& Style::borderLeft() const {
        return this->mBorderLeft;
      }

      void Style::borderLeft(const char &borderStyle) {
        this->mBorderLeft = borderStyle;
      }

      const char& Style::borderLeftMid() const {
        return this->mBorderLeftMid;
      }

      void Style::borderLeftMid(const char &borderStyle) {
        this->mBorderLeftMid = borderStyle;
      }

      const char& Style::borderMid() const {
        return this->mBorderMid;
      }

      void Style::borderMid(const char &borderStyle) {
        this->mBorderMid = borderStyle;
      }

      const char& Style::borderMidMid() const {
        return this->mBorderMidMid;
      }

      void Style::borderMidMid(const char &borderStyle) {
        this->mBorderMidMid = borderStyle;
      }

      const char& Style::borderRight() const {
        return this->mBorderRight;
      }

      void Style::borderRight(const char &borderStyle) {
        this->mBorderRight = borderStyle;
      }

      const char& Style::borderRightMid() const {
        return this->mBorderRightMid;
      }

      void Style::borderRightMid(const char &borderStyle) {
        this->mBorderRightMid = borderStyle;
      }

      const char& Style::borderMiddle() const {
        return this->mBorderMiddle;
      }

      void Style::borderMiddle(const char &borderStyle) {
        this->mBorderMiddle = borderStyle;
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
