#include "manna-handler.h"

#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>

using namespace boost::algorithm;

manna::handler::handler(std::string method, std::string pattern, handle h)
    : method(method)
    , pattern(pattern)
    , h(h)
{
}

bool manna::handler::matches(std::string method, std::string path) {
    boost::regex expr{"^" + this->pattern + "$"};
    return boost::regex_match(path, expr) && to_lower_copy(method) == to_lower_copy(this->method);
}

manna::handle manna::handler::operator()() {
    return this->h;
}