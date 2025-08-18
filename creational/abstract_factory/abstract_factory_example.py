from abc import ABC, abstractmethod

# Abstract products
class Button(ABC):
  @abstractmethod
  def click(self):
    pass

class Container(ABC):
  @abstractmethod
  def display(self):
    pass


# Concrete products
class DarkButton(Button):
  def click(self):
    print('clicked dark button')

class LightButton(Button):
  def click(self):
    print('clicked light button')

class DarkContainer(Container):
  def display(self):
    print('Displayed dark container')

class LightContainer(Container):
  def display(self):
    print('Displayed light container')


# Abstract factory
class Factory(ABC):
  @abstractmethod
  def createButton(self) -> Button:
    pass

  @abstractmethod
  def createContainer(self) -> Container:
    pass


# Concrete factories
class DarkFactory(Factory ):
  def createButton(self) -> Button:
    return DarkButton()

  def createContainer(self) -> Container:
    return DarkContainer()

class LightFactory(Factory ):
  def createButton(self) -> Button:
    return LightButton()

  def createContainer(self) -> Container:
    return LightContainer()
  

def get_factory(name: str) -> Factory:
  if name == 'dark': return DarkFactory()
  elif name == 'light': return LightFactory()
  
def main():
  factory = get_factory('dark')

  button = factory.createButton()
  button.click()

  container = factory.createContainer()
  container.display()

if __name__ == '__main__':
  main()