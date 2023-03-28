#include<iostream>
#include<string>
#include<functional>
#include <utility>


//using CallBack =  std::function<void (void)>;


//template<typename... Args> void CallBack( Args... args );
template<typename... Args>
using CallBack = std::function<void(Args...)>;


template<typename... Args>
class AF
{
  protected:
      std::string filename_;
      //std::function<void(Args...)> call_back_;
    CallBack<Args...> call_back_;

  public:
    AF(const std::string& filename) : filename_(filename)
      {
      }

    virtual ~AF();

      virtual void reload() = 0;

      std::string name() const { return filename_; }
      void register_callback(CallBack<Args...> call_back) { call_back_ = call_back; }
    void invoke_callback( Args... a) { call_back_( std::forward<Args>(a)...); }
};


template<typename... Args>
AF<Args...>::~AF() {}


template<typename... CallbackArgs>
class MT : public AF<CallbackArgs...> {

  public:
    MT(const std::string& fn ): AF<CallbackArgs...>(fn) {}
   ~MT() {}

    void reload() {
      std::cout << "MT:Reload called\n";
    }
};

template<>
class MT<void>: public AF<> {
  public:
    MT(const std::string& fn ): AF<>(fn) {}
   ~MT() {}

    void reload() {
      std::cout << "MT:Reload called\n";
    }
};


class User {
  public:
    User( MT<int>& mt ) : mt_(mt) {
      mt_.reload();
      auto myfunc = [this](int i ) { std::cout << " In callback2 " << i << "\n"; };
      mt.register_callback(myfunc);
    }

  private:
    MT<int>& mt_;
};

class User2 {
  public:
    User2( MT<int,float>& mt ) : mt_(mt) {
      mt_.reload();
      auto myfunc = [this](int i, float f ) { std::cout << "In the call back first arg:" << i << " second arg: " << f << "\n"; };
      mt.register_callback(myfunc);
    }

  private:
    MT<int,float>& mt_;
};

class User3 {
  public:
    User3( MT<void>& mt ) : mt_(mt) {
      mt_.reload();
      auto myfunc = [this]() { std::cout << "In the call back no args:\n"; };
      mt.register_callback(myfunc);
    }

  private:
    MT<void>& mt_;
};


int main() {
  MT<int> mt("abc");
  User u(mt);
  int i=5;
  mt.invoke_callback(i);

  MT<int,float> mt2("abc");
  User2 user2(mt2);
  mt2.invoke_callback(20, 50.5);

  MT<void> mt3("abc");
  User3 user3(mt3);
  mt3.invoke_callback();
}

