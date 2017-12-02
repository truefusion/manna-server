#include "manna-request.h"

#include <nghttp2/asio_http2_server.h>

manna::request::request(const nghttp2::asio_http2::server::request &req)
	: impl(req)
{
}

std::string manna::request::getPath() const {
	return this->impl.uri().path;
}

std::string manna::request::getQuery() const {
	return this->impl.uri().raw_query;
}
