from abc import ABC, abstractmethod
from copy import deepcopy

class Prototype(ABC):
    @abstractmethod
    def clone(self):
        pass

class ConcretePrototype(Prototype):
    def __init__(self, value: int) -> None:
        self.value = value
        self.data = [1, 2, 3]
    
    def clone(self):
        return deepcopy(self)

def main():
    original = ConcretePrototype(123)
    
    clone = original.clone()
    
    print(f"Original value: {original.value}, data: {original.data}")
    print(f"Clone value: {clone.value}, data: {clone.data}")
    print(f"Same object? {original is clone}")

if __name__ == '__main__':
    main()
