#include "manna-response.h"

#include "nghttp2/asio_http2_server.h"

manna::response::response(const nghttp2::asio_http2::server::response &rsp)
	: impl(rsp)
{
}

void manna::response::flush() {
	this->impl.write_head(this->Status);
	this->impl.end(this->Body);
}
