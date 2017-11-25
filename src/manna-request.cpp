#include "manna-request.h"

#include <nghttp2/asio_http2_server.h>

manna::request::request(const nghttp2::asio_http2::server::request &req)
	: impl(std::move(req))
{
}
