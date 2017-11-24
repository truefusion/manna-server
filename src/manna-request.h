#ifndef MANNAREQUEST_H
#define MANNAREQUEST_H

#include "nghttp2/asio_http2_server.h"

namespace manna {
	class request
	{
		public:
			request(const nghttp2::asio_http2::server::request &);

			const nghttp2::asio_http2::server::request & impl;
	};
}

#endif // MANNAREQUEST_H
