#ifndef MANNAREQUEST_H
#define MANNAREQUEST_H

#include <string>

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

			std::string getPath() const;
			std::string getQuery() const;

		private:
			const nghttp2::asio_http2::server::request &impl;
	};
}

#endif // MANNAREQUEST_H
