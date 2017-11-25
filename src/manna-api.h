#ifndef MANNAAPII_H
#define MANNAAPII_H

#include "manna-connection.h"

namespace manna {
	class api_interface
	{
		public:
			virtual handler getHandler(std::string,std::string)=0;
	};
}

#endif // MANNAAPII_H
