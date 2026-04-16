#pragma once

#include "model.hxx"

class View
{
public:
    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set, ge211::Posn<int> mouse_posn, bool show);

private:
    Model const& model_;
    ge211::Font sans28_{"sans.ttf", 28};
    ge211::Rectangle_sprite const brick_sprite;
    ge211::Rectangle_sprite const select_brick_sprite;
    ge211::Rectangle_sprite const red_brick_sprite;
    ge211::Rectangle_sprite const green_brick_sprite;
    ge211::Rectangle_sprite const background_brick_sprite;
    ge211::Rectangle_sprite const vert_brick_sprite;
    ge211::Rectangle_sprite const horz_brick_sprite;
    ge211::Text_sprite const one_sprite;
    ge211::Text_sprite const two_sprite;
    ge211::Text_sprite const three_sprite;
    ge211::Text_sprite const four_sprite;
    ge211::Text_sprite const five_sprite;
    ge211::Text_sprite const six_sprite;
    ge211::Text_sprite const seven_sprite;
    ge211::Text_sprite const eight_sprite;
    ge211::Text_sprite const nine_sprite;
};
