class Target:
    def request(self) -> str:
        return "Target: Default behavior"


class Adaptee:
    def specific_request(self) -> str:
        return "Adaptee: Some strange behavior"


class Adapter(Target, Adaptee):
    def request(self) -> str:
        return f"Adapter: (TRANSLATED) {self.specific_request()}"


def client_code(target: Target) -> None:
    print(target.request())

def main() -> None:
    # THE CLIENT CODE ONLY KNOWS HOW TO DEAL WITH THE TARGET INTERFACE
    target = Target()
    client_code(target)

    # THIS WILL THROW AN ERROR
    # adaptee = Adaptee()
    # client_code(adaptee)

    # NOW THIS WORKS
    adapter = Adapter()
    client_code(adapter)

if __name__ == '__main__':
    main()
