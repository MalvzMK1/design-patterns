from typing import Any
from threading import Lock, Thread


class SingletonMeta(type):
    # Dictionary to store singleton instances
    _instances = {}
    # Lock object for thread synchronization
    _lock: Lock = Lock()

    def __call__(self, *args: Any, **kwargs: Any) -> Any:
        # Thread-safe singleton creation using context manager
        with self._lock:
            # Check if instance exists, create if not
            if self not in self._instances:
                instance = super().__call__(*args, **kwargs)
                self._instances[self] = instance
        # Return existing or newly created instance
        return self._instances[self]


class Singleton(metaclass=SingletonMeta):
    # Class variable shared across all instances
    value: str = None

    def __init__(self, value) -> None:
        # Instance initialization - only runs once per singleton
        self.value = value


def test_singleton(value: str) -> None:
    # Function to test singleton in separate threads
    singleton = Singleton(value)
    print(singleton.value)


if __name__ == '__main__':
    # Create two threads trying to instantiate singleton with different values
    # Due to singleton pattern, both will reference same instance
    process1 = Thread(target=test_singleton, args=("FOO",))
    process2 = Thread(target=test_singleton, args=("BAR",))
    # Start threads concurrently to test thread safety
    process1.start()
    process2.start()
