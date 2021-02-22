#ifndef MANNASERVER_H
#define MANNASERVER_H

#include <unordered_map>

namespace nghttp2 {
	namespace asio_http2 {
		namespace server {
			class http2;
		}
	}
}

namespace manna {
	class api_interface;

	class server
	{
		public:
			server(std::string = "localhost", int = 80, std::string = "server.key", std::string = "server.crt");
			~server();

			bool run();
			void stop();

			api_interface * Api = 0;
			std::string Certificate;
			std::string Host = "localhost";
			std::string PrivateKey;
			int Port = 80;

		private:
			nghttp2::asio_http2::server::http2 * lib = 0;
	};
}

#endif // MANNASERVER_H
