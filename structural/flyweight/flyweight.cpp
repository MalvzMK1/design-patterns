#include <iostream>
#include <string>
#include <vector>
#include <memory>

// intrisic constant data
class Particle {
protected:
  const int color_;
  const int brightness_;
  const std::string texture_;

public:
  Particle(
    const int color,
    const int brightness,
    const std::string& texture
  )
    : color_(color), brightness_(brightness), texture_(texture) {}

  int color() const {
    return color_;
  }

  int brightness() const {
    return brightness_;
  }

  const std::string& texture() const {
    return texture_;
  }
};

// extrinsic data
class MovingParticle {
private:
  int x_;
  int y_;
  int velocity_;
  short direction_;
  std::shared_ptr<Particle> props_;
public:
  MovingParticle(
    int x,
    int y,
    int velocity,
    short direction,
    std::shared_ptr<Particle> particle
  )
    : x_(x), y_(y), velocity_(velocity), direction_(direction), props_(particle) {}

  int x() const {
    return x_;
  }

  int y() const {
    return y_;
  }

  int velocity() const {
    return velocity_;
  }

  short direction() const {
    return direction_;
  }

  void draw() {
    std::cout << "Drawing particle at (" << x_ << "," << y_ << ") "
      << "velocity=" << velocity_ << " dir=" << direction_
      << " | color=" << props_->color()
      << " brightness=" << props_->brightness()
      << " texture=" << props_->texture()
      << " | props address=" << props_.get()
      << "\n";
  }
};

// flyweight factory with cached particles
class ParticleFactory {
private:
  static std::vector<std::shared_ptr<Particle>> cache_;
public:
  static std::shared_ptr<Particle> getParticle(
    const int color,
    const int brightness,
    const std::string& texture
  ) {
    for (auto& p : cache_) {
      if (
        p->brightness() == brightness
        && p->color() == color
        && p->texture() == texture
      ) return p;
    }

    auto particle = std::make_shared<Particle>(
      color,
      brightness,
      texture
    );

    cache_.push_back(std::make_shared<Particle>(color, brightness, texture));
    return cache_.back();
  }

  static size_t getCacheSize() {
    return cache_.size();
  }
};

class Game {
private:
  std::vector<MovingParticle> particles_;
public:
  void addParticle(
    const int color,
    const int brightness,
    const std::string& texture,
    int x,
    int y,
    int velocity,
    short direction
  ) {
    auto particle = ParticleFactory::getParticle(
      color,
      brightness,
      texture
    );

    MovingParticle movingParticle(
      x,
      y,
      velocity,
      direction,
      particle
    );

    particles_.push_back(movingParticle);
  }

  void draw() {
    for (auto& mp : particles_) {
      mp.draw();
    }
  }
};

std::vector<std::shared_ptr<Particle>> ParticleFactory::cache_;

int main() {
  srand(time(nullptr));
  Game game;

  for (int i = 0; i < 1000; i++) {
    if (i % 2 == 0) {
      game.addParticle(255, 100, "sparkle.png",
        rand() % 100, rand() % 100, rand() % 10 + 1, rand() % 8);
    } else {
      game.addParticle(0, 200, "smoke.png",
        rand() % 100, rand() % 100, rand() % 10 + 1, rand() % 8);
    }
  }

  std::cout << "\n--- Drawing first 10 particles ---\n";
  for (int i = 0; i < 10; i++) {
    game.draw();
  }

  std::cout << "\nFlyweights criados em cache: "
            << ParticleFactory::getCacheSize() << "\n";
}

