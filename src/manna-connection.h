#ifndef CONNECTION_H
#define CONNECTION_H

#include <functional>

#include "manna-request.h"
#include "manna-response.h"

namespace manna {
	class request;
	class response;

	class connection
	{
		public:
			connection(const nghttp2::asio_http2::server::request &, const nghttp2::asio_http2::server::response &);

			request  Request;
			response Response;
	};

	typedef std::function<void(connection &)> handler;
}

#endif // CONNECTION_H
