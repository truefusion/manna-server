#include "manna-response.h"

manna::response::response(const nghttp2::asio_http2::server::response &rsp)
    : impl(std::move(rsp))
{
}
