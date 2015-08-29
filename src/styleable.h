#include <string>

namespace bornageek {
  namespace utils {
    namespace termtab {
      enum Alignment {
        LEFT, RIGHT, CENTER
      };

      class Styleable {
        private:
          std::string mBorderX = "-";
          std::string mBorderY = "|";
          std::string mBorderE = "+";

          std::uint16_t mPaddingLeft = 1;
          std::uint16_t mPaddingRight = 1;

          Alignment mAlign = Alignment::LEFT;

          std::uint16_t mWidth = 0;

        public:
          Styleable();

          const std::string& borderX() const;
          void borderX(std::string const &borderStyle);

          const std::string& borderY() const;
          void borderY(std::string const &borderStyle);

          const std::string& borderE() const;
          void borderE(std::string const &borderStyle);

          const std::uint16_t paddingLeft() const;
          void paddingLeft(std::uint16_t const &padding);

          const std::uint16_t paddingRight() const;
          void paddingRight(std::uint16_t const &padding);

          const Alignment alignment() const;
          void alignment(Alignment const &align);

          const std::uint16_t width() const;
          void width(std::uint16_t const &width);
      };
    }
  }
}
