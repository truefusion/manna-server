#ifndef HANDLER_H
#define HANDLER_H

#include <functional>

namespace manna {
    class connection;

    typedef std::function<void(connection &)> handle;

    class handler
    {
        public:
          explicit handler(std::string, std::string, handle);

          handle operator()();
          operator bool() const {
              return true;
          };
          bool matches(std::string, std::string);

        private:
            std::string method;
            std::string pattern;
            handle h;

    };
}

#endif // HANDLER_H
