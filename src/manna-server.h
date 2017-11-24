#ifndef MANNASERVER_H
#define MANNASERVER_H

#include <unordered_map>

#include "manna-connection.h"

namespace manna {
	class server
	{
		public:
			server(std::string, int);

			void handle(std::string, handler);
			bool run();

			std::string Host = "localhost";
			int Port = 80;

		private:
			std::unordered_map<std::string, handler> handlers;
			nghttp2::asio_http2::server::http2 * lib = 0;
	};
}

#endif // MANNASERVER_H
