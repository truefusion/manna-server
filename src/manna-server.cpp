#include "manna-server.h"
#include "manna-connection.h"

#include <boost/regex.hpp>

manna::server::server(std::string host = "localhost", int port = 80)
	: lib(new nghttp2::asio_http2::server::http2())
	, Host(host)
	, Port(port)
{
	this->lib->handle("*", [this](const nghttp2::asio_http2::server::request & req, const nghttp2::asio_http2::server::response & rsp) {
		std::string path = req.uri().path;
		for (auto it: this->handlers) {
			boost::regex pattern{it.first};
			if (boost::regex_match(path, pattern)) {
				connection conn(req, rsp);

				auto h = it.second;
				h(conn);
				break;
			}
		}
	});
}

void manna::server::handle(std::string pattern, handler h) {
	this->handlers[pattern] = h;
}

bool manna::server::run() {
	boost::system::error_code ec;
	return !((bool) this->lib->listen_and_serve(
		ec
	,	this->Host
	,	std::to_string(this->Port)
	,	true
	));
}
