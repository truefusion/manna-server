#include "manna-request.h"

manna::request::request(const nghttp2::asio_http2::server::request &req)
	: impl(std::move(req))
{
}
