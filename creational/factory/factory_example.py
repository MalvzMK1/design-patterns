from abc import ABC, abstractmethod

# Interface
class Vehicle(ABC):
  @abstractmethod
  def accelerate(self) -> None:
    pass

  @abstractmethod
  def brake(self) -> None:
    pass


# Implementations
class Car(Vehicle):
  def accelerate(self):
    print('The car is accelerating')

  def brake(self): 
    print('The car is braking')

class Bike(Vehicle):
  def accelerate(self): 
    print('The bike is accelerating')

  def brake(self): 
    print('The bike is braking')


# Creator class definition
class VehicleFactory:
  @staticmethod
  def create(vehicle_type: 'car' or 'bike') -> Vehicle:
    if vehicle_type == 'car':
      return Car()
    elif vehicle_type == 'bike':
      return Bike()
    else:
      raise ValueError('Unknown vehicle type')


# ----- Demo -----

def main() -> None:
  vehicle_type = input('Vehicle type (car/bike): ')
  print()

  vehicle = VehicleFactory.create(vehicle_type)

  vehicle.accelerate()
  vehicle.brake()

if __name__ == '__main__':
  main()
