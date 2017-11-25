#ifndef MANNAREQUEST_H
#define MANNAREQUEST_H

namespace nghttp2 {
	namespace asio_http2 {
		namespace server {
			class request;
			class response;
		}
	}
}

namespace manna {
	class request
	{
		public:
			request(const nghttp2::asio_http2::server::request &);

			const nghttp2::asio_http2::server::request & impl;
	};
}

#endif // MANNAREQUEST_H
