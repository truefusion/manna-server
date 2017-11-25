#include "manna-server.h"

#include <nghttp2/asio_http2_server.h>

#include "manna-api.h"
#include "manna-connection.h"

manna::server::server(std::string host, int port)
	: lib(new nghttp2::asio_http2::server::http2())
	, Host(host)
	, Port(port)
{
	this->lib->handle("*", [this](const nghttp2::asio_http2::server::request & req, const nghttp2::asio_http2::server::response & rsp) {
		std::string path   = req.uri().path;
		std::string method = req.method();

		if (this->Api) {
			connection conn(req, rsp);
			handler h = this->Api->getHandler(method, path);
			if (h) h(conn);
		}
	});
}

manna::server::~server() {
	delete this->lib;
	delete this->Api;
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

void manna::server::stop() {
	this->lib->join();
}
