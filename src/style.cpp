#include <string>

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
      
      const std::string& Style::borderTop() const {
        return this->mBorderTop;
      }

      void Style::borerTop(const std::string &borderStyle) {
        this->mBorderTop = borderStyle;
      }

      const std::string& Style::borderTopMid() const {
        return this->mBorderTopMid;
      }

      void Style::borderTopMid(const std::string &borderStyle) {
        this->mBorderTopMid = borderStyle;
      }

      const std::string& Style::borderTopLeft() const {
        return this->mBorderTopLeft;
      }

      void Style::borderTopLeft(const std::string &borderStyle) {
        this->mBorderTopLeft = borderStyle;
      }

      const std::string& Style::borderTopRight() const {
        return this->mBorderTopRight;
      }

      void Style::borderTopRight(const std::string &borderStyle) {
        this->mBorderTopRight = borderStyle;
      }

      const std::string& Style::borderBottom() const {
        return this->mBorderBottom;
      }

      void Style::borderBottom(const std::string &borderStyle) {
        this->mBorderBottom = borderStyle;
      }

      const std::string& Style::borderBottomMid() const {
        return this->mBorderBottomMid;
      }

      void Style::borderBottomMid(const std::string &borderStyle) {
        this->mBorderBottomMid = borderStyle;
      }

      const std::string& Style::borderBottomLeft() const {
        return this->mBorderBottomLeft;
      }

      void Style::borderBottomLeft(const std::string &borderStyle) {
        this->mBorderBottomLeft = borderStyle;
      }

      const std::string& Style::borderBottomRight() const {
        return this->mBorderBottomRight;
      }

      void Style::borderBottomRight(const std::string &borderStyle) {
        this->mBorderBottomRight = borderStyle;
      }

      const std::string& Style::borderLeft() const {
        return this->mBorderLeft;
      }

      void Style::borderLeft(const std::string &borderStyle) {
        this->mBorderLeft = borderStyle;
      }

      const std::string& Style::borderLeftMid() const {
        return this->mBorderLeftMid;
      }

      void Style::borderLeftMid(const std::string &borderStyle) {
        this->mBorderLeftMid = borderStyle;
      }

      const std::string& Style::borderMid() const {
        return this->mBorderMid;
      }

      void Style::borderMid(const std::string &borderStyle) {
        this->mBorderMid = borderStyle;
      }

      const std::string& Style::borderMidMid() const {
        return this->mBorderMidMid;
      }

      void Style::borderMidMid(const std::string &borderStyle) {
        this->mBorderMidMid = borderStyle;
      }

      const std::string& Style::borderRight() const {
        return this->mBorderRight;
      }

      void Style::borderRight(const std::string &borderStyle) {
        this->mBorderRight = borderStyle;
      }

      const std::string& Style::borderRightMid() const {
        return this->mBorderRightMid;
      }

      void Style::borderRightMid(const std::string &borderStyle) {
        this->mBorderRightMid = borderStyle;
      }

      const std::string& Style::borderMiddle() const {
        return this->mBorderMiddle;
      }

      void Style::borderMiddle(const std::string &borderStyle) {
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
