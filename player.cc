#include "player.h"
#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"

void Player::Draw4(graphics::Image& image) {

   graphics::Image playerImage(50,50);
   graphics::Color doNotDraw(255,255,255);
   graphics::Color green(11,87,63);

    playerImage.Load("naruto.bmp");
    for (int i = 0; i < playerImage.GetWidth(); i++) {
    for (int j = 0; j < playerImage.GetHeight(); j++) {
      if (playerImage.GetColor(i,j) != doNotDraw && playerImage.GetColor(i,j) != green) {
      image.SetColor(GetX() + i, GetY() + j, playerImage.GetColor(i, j));
    }
    }
  }
}

// void Player::Draw3(graphics::Image& image) {
//    graphics::Image playerImage(50,50);
//    graphics::Color doNotDraw(255,255,255);
//    graphics::Color green(11,87,63);
//     playerImage.Load("gaara.bmp");
//     for (int i = 0; i < playerImage.GetWidth(); i++) {
//     for (int j = 0; j < playerImage.GetHeight(); j++) {
//       if (playerImage.GetColor(i,j) != doNotDraw && playerImage.GetColor(i,j) != green) {
//       image.SetColor(GetX() + i, GetY() + j, playerImage.GetColor(i, j));
//     }
//     }
//   }
// }

// void Player::Draw1(graphics::Image& image) {
//    graphics::Image playerImage(50,50);
//    graphics::Color doNotDraw(255,255,255);
//     playerImage.Load("rockLee.bmp");

//     for (int i = 0; i < playerImage.GetWidth(); i++) {
//     for (int j = 0; j < playerImage.GetHeight(); j++) {
//       if (playerImage.GetColor(i,j) != doNotDraw) {
//       image.SetColor(GetX() + i, GetY() + j, playerImage.GetColor(i, j));
//     }
//     }
// }
// }

void Player::Draw2(graphics::Image& image) {
   if (toggleSwitch) {
    playerImage.Load("gaara.bmp");
    Helper(playerImage, image);
    toggleSwitch = false;
  } else {
    playerImage2.Load("gaara2.bmp");
    Helper(playerImage2, image);
    toggleSwitch = true;
  }
}

void Player::Draw1(graphics::Image& image) {
   if (toggleSwitch) {
    playerImage.Load("rockLee.bmp");
    Helper(playerImage, image);
    toggleSwitch = false;
  } else {
    playerImage2.Load("rockLee2.bmp");
    Helper(playerImage2, image);
    toggleSwitch = true;
  }
}

void Player::Draw(graphics::Image& image) {
  graphics::Image playerImage(50, 50);
  graphics::Color doNotDraw(255,255,255);
  playerImage.Load("player.bmp");
  for (int i = 0; i < playerImage.GetWidth(); i++) {
    for (int j = 0; j < playerImage.GetHeight(); j++) {
       if (playerImage.GetColor(i,j) != doNotDraw) {
      image.SetColor(GetX() + i, GetY() + j, playerImage.GetColor(i, j));
    }
  }
 }
}
 

void Player::Helper(graphics::Image& playerImage,graphics::Image& image) {
     graphics::Color doNotDraw(255,255,255); 
  for (int i = 0; i < playerImage.GetWidth(); i++) {
      for (int j = 0; j < playerImage.GetHeight(); j++) {
        if ( playerImage.GetColor(i, j) != doNotDraw) {
        int left = i + (GetX() - playerImage.GetWidth() / 2);
        int top = j + (GetY() - playerImage.GetHeight() / 2);
        image.SetColor(left, top, playerImage.GetColor(i, j));
        }
      }
    }
}
 
void PlayerProjectile::Draw(graphics::Image& image) {
  graphics::Image playerProjectileImage(10, 10);
  graphics::Color doNotDraw(255,255,255);
  
  playerProjectileImage.Load("player_projectile.bmp");
  for (int i = 0; i < playerProjectileImage.GetWidth(); i++) {
    for (int j = 0; j < playerProjectileImage.GetHeight(); j++) {
    if (playerProjectileImage.GetColor(i,j) != doNotDraw) {
      image.SetColor(GetX() + i, GetY() + j,
                     playerProjectileImage.GetColor(i, j));
    }
    }
  }
}
 
void Player::Move(const graphics::Image& image) {}
 
void PlayerProjectile::Move(const graphics::Image& image) {
  if (!IsOutOfBounds(image)) {
    SetY(GetY() - 3);
  } else {
    SetIsActive(false);
  }
}
 
