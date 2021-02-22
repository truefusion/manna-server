#include "manna-server.h"

#include <iostream>
#include <memory>
#include <nghttp2/asio_http2_server.h>

#include "manna-api.h"
#include "manna-connection.h"

manna::server::server(std::string host, int port, std::string pkFile, std::string crtFile)
	: lib(new nghttp2::asio_http2::server::http2())
	, Host(host)
	, Port(port)
	, PrivateKey(pkFile)
	, Certificate(crtFile)
{
	// "/" root path allows us to handle all paths!
	this->lib->handle("/", [this](const nghttp2::asio_http2::server::request & req, const nghttp2::asio_http2::server::response & rsp) {
		std::string path   = req.uri().path;
		std::string method = req.method();

		if (this->Api) {
			connection conn(req, rsp);
			handle h = this->Api->getHandler(method, path);
			if (h) {
                h(conn);
            } else {
				rsp.write_head(404);
				rsp.end();
			}
		}
	});
}

manna::server::~server() {
	delete this->lib;
	delete this->Api;
}

bool manna::server::run() {
	std::cout << "Listening on " << this->Host << ":" << this->Port << std::endl;

	boost::system::error_code ec;
    boost::asio::ssl::context tls(boost::asio::ssl::context::sslv23);

    tls.use_private_key_file(this->PrivateKey, boost::asio::ssl::context::pem);
    tls.use_certificate_chain_file(this->Certificate);

    nghttp2::asio_http2::server::configure_tls_context_easy(ec, tls);

    bool r = !((bool) this->lib->listen_and_serve(
		ec,
		tls,
		this->Host,
		std::to_string(this->Port),
		true
	));
	if (!r) std::cerr << "error: " << ec.message() << std::endl;
	return r;
}

void manna::server::stop() {
	this->lib->join();
}
