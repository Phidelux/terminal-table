#ifndef STYLE_H
#define STYLE_H

#include <cstdint>

namespace bornageek {
  namespace utils {
    namespace termtab {
      enum Alignment {
        LEFT, RIGHT, CENTER
      };

      class Style {
        private:
          char mBorderTop = '=';
          char mBorderTopMid = '#';
          char mBorderTopLeft = '@';
          char mBorderTopRight = '@';

          char mBorderBottom = '=';
          char mBorderBottomMid = '#';
          char mBorderBottomLeft = '@';
          char mBorderBottomRight = '@';

          char mBorderLeft = '[';
          char mBorderLeftMid = '#';

          char mBorderMid = '-';
          char mBorderMidMid = '+';

          char mBorderRight = ']';
          char mBorderRightMid = '#';

          char mBorderMiddle = '|';

          std::uint16_t mPaddingLeft = 1;
          std::uint16_t mPaddingRight = 1;

          Alignment mAlign = Alignment::LEFT;

          std::uint16_t mWidth = 0;

        public:
          Style();
          Style(const Style &s);

          const char& borderTop() const;
          void borerTop(const char &borderStyle);

          const char& borderTopMid() const;
          void borderTopMid(const char &borderStyle);

          const char& borderTopLeft() const;
          void borderTopLeft(const char &borderStyle);

          const char& borderTopRight() const;
          void borderTopRight(const char &borderStyle);

          const char& borderBottom() const;
          void borderBottom(const char &borderStyle);

          const char& borderBottomMid() const;
          void borderBottomMid(const char &borderStyle);

          const char& borderBottomLeft() const;
          void borderBottomLeft(const char &borderStyle);

          const char& borderBottomRight() const;
          void borderBottomRight(const char &borderStyle);

          const char& borderLeft() const;
          void borderLeft(const char &borderStyle);

          const char& borderLeftMid() const;
          void borderLeftMid(const char &borderStyle);

          const char& borderMid() const;
          void borderMid(const char &borderStyle);

          const char& borderMidMid() const;
          void borderMidMid(const char &borderStyle);

          const char& borderRight() const;
          void borderRight(const char &borderStyle);

          const char& borderRightMid() const;
          void borderRightMid(const char &borderStyle);

          const char& borderMiddle() const;
          void borderMiddle(const char &borderStyle);

          const std::uint16_t paddingLeft() const;
          void paddingLeft(const std::uint16_t &padding);

          const std::uint16_t paddingRight() const;
          void paddingRight(const std::uint16_t &padding);

          const Alignment alignment() const;
          void alignment(const Alignment &align);

          const std::uint16_t width() const;
          void width(const std::uint16_t &width);
      };
    }
  }
}

#endif
