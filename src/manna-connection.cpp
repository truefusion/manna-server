#include "manna-connection.h"

manna::connection::connection(const nghttp2::asio_http2::server::request & req, const nghttp2::asio_http2::server::response & rsp)
	: Request(req)
	, Response(rsp)
{
}
