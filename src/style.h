#ifndef STYLE_H
#define STYLE_H

#include <string>

namespace bornageek {
  namespace utils {
    namespace termtab {
      enum Alignment {
        LEFT, RIGHT, CENTER
      };

      class Style {
        private:
          std::string mBorderTop = "\u2500";
          std::string mBorderTopMid = "\u252C";
          std::string mBorderTopLeft = "\u250C";
          std::string mBorderTopRight = "\u2510";

          std::string mBorderBottom = "\u2500";
          std::string mBorderBottomMid = "\u2534";
          std::string mBorderBottomLeft = "\u2514";
          std::string mBorderBottomRight = "\u2518";

          std::string mBorderLeft = "\u2502";
          std::string mBorderLeftMid = "\u251c";

          std::string mBorderMid = "\u2500";
          std::string mBorderMidMid = "\u253C";

          std::string mBorderRight = "\u2502";
          std::string mBorderRightMid = "\u2524";

          std::string mBorderMiddle = "\u2502";

          std::uint16_t mPaddingLeft = 1;
          std::uint16_t mPaddingRight = 1;

          Alignment mAlign = Alignment::LEFT;

          std::uint16_t mWidth = 0;

        public:
          Style();
          Style(const Style &s);

          const std::string& borderTop() const;
          void borerTop(const std::string &borderStyle);

          const std::string& borderTopMid() const;
          void borderTopMid(const std::string &borderStyle);

          const std::string& borderTopLeft() const;
          void borderTopLeft(const std::string &borderStyle);

          const std::string& borderTopRight() const;
          void borderTopRight(const std::string &borderStyle);

          const std::string& borderBottom() const;
          void borderBottom(const std::string &borderStyle);

          const std::string& borderBottomMid() const;
          void borderBottomMid(const std::string &borderStyle);

          const std::string& borderBottomLeft() const;
          void borderBottomLeft(const std::string &borderStyle);

          const std::string& borderBottomRight() const;
          void borderBottomRight(const std::string &borderStyle);

          const std::string& borderLeft() const;
          void borderLeft(const std::string &borderStyle);

          const std::string& borderLeftMid() const;
          void borderLeftMid(const std::string &borderStyle);

          const std::string& borderMid() const;
          void borderMid(const std::string &borderStyle);

          const std::string& borderMidMid() const;
          void borderMidMid(const std::string &borderStyle);

          const std::string& borderRight() const;
          void borderRight(const std::string &borderStyle);

          const std::string& borderRightMid() const;
          void borderRightMid(const std::string &borderStyle);

          const std::string& borderMiddle() const;
          void borderMiddle(const std::string &borderStyle);

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
