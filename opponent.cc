#include "opponent.h"
#include <vector>
#include "cpputils/graphics/image.h"
#include "game.h"
#include "game_element.h"
//implementing some animation ( testing ) 
void Opponent::Draw(graphics::Image &image) {
  if (toggleSwitch) {
    opponentImage.Load("opponent.bmp");
    Helper(opponentImage, image);
    toggleSwitch = false;
  } else {
    opponentImage2.Load("practice.bmp");
    Helper(opponentImage2, image);
    toggleSwitch = true;
  }
}
void Opponent::Helper( graphics::Image& opponentImage,graphics::Image& image){
     graphics::Color doNotDraw(255,255,255); 
  for (int i = 0; i < opponentImage.GetWidth(); i++) {
      for (int j = 0; j < opponentImage.GetHeight(); j++) {
        if ( opponentImage.GetColor(i, j) != doNotDraw) {
        int left = i + (GetX() - opponentImage.GetWidth() / 2);
        int top = j + (GetY() - opponentImage.GetHeight() / 2);
        image.SetColor(left, top, opponentImage.GetColor(i, j));
        }
      }
    }
}
 
 
std::unique_ptr<OpponentProjectile>
Opponent::LaunchProjectile() {  // not sure check later
 
  if (counter == 10) {
    std::unique_ptr<OpponentProjectile> unique_oppProjectile =
        std::make_unique<OpponentProjectile>(Opponent::GetX(),
                                             Opponent::GetY());
    counter = 0;
    return unique_oppProjectile;
  } else {
    counter++;
    return nullptr;
  }
}
 
void Opponent::Move(const graphics::Image &image) {
  if (!IsOutOfBounds(image)) {
    SetY(GetY() + 3);
    SetX(GetX() + 3);
  } else {
    SetIsActive(false);
  }
}
 
void OpponentProjectile::Draw(graphics::Image &image) {
  graphics::Image opponentPImage(10, 10);
  opponentPImage.Load("opponent_projectile.bmp");
  graphics::Color doNotDraw(255,255,255);
 
  for (int i = 0; i < opponentPImage.GetWidth(); i++) {
    for (int j = 0; j < opponentPImage.GetHeight(); j++) {
      if (opponentPImage.GetColor(i,j) != doNotDraw) {
      image.SetColor(GetX() + i, GetY() + j, opponentPImage.GetColor(i, j));
    }
  }
  }
}
 
void OpponentProjectile::Move(const graphics::Image &image) {
  if (!IsOutOfBounds(image)) {
    SetY(GetY() - 3);
    SetX(GetX() - 3);
  } else {
    SetIsActive(false);
  }
}
