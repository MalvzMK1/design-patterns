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

// definição do cache estático
std::vector<std::shared_ptr<Particle>> ParticleFactory::cache_;

int main() {
    Game game;

    // Criando várias partículas com os mesmos dados intrínsecos
    game.addParticle(255, 100, "sparkle.png", 10, 20, 5, 1);
    game.addParticle(255, 100, "sparkle.png", 15, 25, 6, 2);
    game.addParticle(255, 100, "sparkle.png", 20, 30, 7, 3);

    // Criando partículas diferentes
    game.addParticle(0, 200, "smoke.png", 30, 40, 3, 4);
    game.addParticle(0, 200, "smoke.png", 35, 45, 4, 5);

    // Desenhando todas as partículas
    game.draw();

    return 0;
}

