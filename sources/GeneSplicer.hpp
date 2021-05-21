#include "Player.hpp"
namespace pandemic
{
    class GeneSplicer : public Player
    {
    public:
       GeneSplicer(Board& b, City c): Player(b, c, "GS") {}
       Player& discover_cure(Color c) override;
       string role() override;
    };

}

