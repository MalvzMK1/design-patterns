#include <iostream>

class Request {
private:
  bool isAuthenticated_;
  bool hasRequiredRole_;
  bool isAdmin_;
public:
  Request(bool isAuthenticated, bool hasRequiredRole, bool isAdmin)
    : isAuthenticated_(isAuthenticated),
      hasRequiredRole_(hasRequiredRole),
      isAdmin_(isAdmin) {}

  bool isAuthenticated() const { return isAuthenticated_; };
  bool isAdmin() const { return isAdmin_; };
  bool hasRequiredRole() const { return hasRequiredRole_; };
};

class Handler {
protected:
  Handler* next_;
public:
  virtual ~Handler() = default;
  virtual bool execute(const Request& request) = 0;
  void setNext(Handler* next) {
    next_ = next;
  }
};

class AuthenticationHandler : public Handler {
public:
  bool execute(const Request& request) override {
    if (!request.isAuthenticated()) return false;

    if (next_) {
      return next_->execute(request);
    }

    return false;
  }
};

class RoleHandler : public Handler {
public:
  bool execute(const Request& request) override {
    if (request.isAdmin()) return true;

    if (next_) {
      return next_->execute(request);
    }

    return false;
  }
};

class PermissionHandler : public Handler {
public:
  bool execute(const Request& request) override {
    if (request.hasRequiredRole()) return true;

    if (next_) {
      return next_->execute(request);
    }

    return false;
  }
};

int main() {
  AuthenticationHandler authHandler;
  RoleHandler roleHandler;
  PermissionHandler permissionHandler;

  roleHandler.setNext(&permissionHandler);
  authHandler.setNext(&roleHandler);

  Request request(true, true, false);

  const char* firstResponse = authHandler.execute(request) ? "Is valid" : "Not valid";

  std::cout << "Request: authenticated, has required role, is not an admin.\nResponse: "
            << firstResponse
            << "\n"
            << std::endl;

  Request secondRequest(
    true,
    false,
    true
  );

  const char* secondResponse = authHandler.execute(secondRequest) ? "Is valid" : "Not valid";

  std::cout << "Request: authenticated, does not have required role, is an admin.\nResponse: "
            << secondResponse
            << "\n"
            << std::endl;

  Request thirdRequest(
    false,
    true,
    true 
  );

  const char* thirdResponse = authHandler.execute(request) ? "Is valid" : "Not valid";

  std::cout << "Request: not authenticated, has required role, is an admin.\nResponse: "
            << thirdResponse
            << std::endl;

  return 0;
}
