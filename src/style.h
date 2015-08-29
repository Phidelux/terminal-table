#include <string>

namespace bornageek {
  namespace utils {
    namespace termtab {
      enum Alignment {
        LEFT, RIGHT, CENTER
      };

      class Style {
        private:
          std::string mBorderX = "-";
          std::string mBorderY = "|";
          std::string mBorderE = "+";

          std::uint16_t mPaddingLeft = 1;
          std::uint16_t mPaddingRight = 1;

          Alignment mAlign = Alignment::LEFT;

          std::uint16_t mWidth = 0;

        public:
          Style();
          Style(const Style &s);

          const std::string& borderX() const;
          void borderX(const std::string &borderStyle);

          const std::string& borderY() const;
          void borderY(const std::string &borderStyle);

          const std::string& borderE() const;
          void borderE(const std::string &borderStyle);

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
