#ifndef MANNARESPONSE_H
#define MANNARESPONSE_H

#include "nghttp2/asio_http2_server.h"

namespace manna {
	class response
	{
		public:
			response(const nghttp2::asio_http2::server::response &);

			const nghttp2::asio_http2::server::response & impl;
	};
}

#endif // MANNARESPONSE_H
