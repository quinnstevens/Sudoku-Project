#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();

protected:
    void draw(ge211::Sprite_set& set) override;
    void on_mouse_move(ge211::Posn<int> position) override;
    void on_key(ge211::Key key) override;
    ge211::Dims<int> initial_window_dimensions() const override;

private:
    Model model_;
    View view_;
    ge211::Posn<int> mouse;
    bool show;
};
