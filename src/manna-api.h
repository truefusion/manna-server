#ifndef MANNAAPII_H
#define MANNAAPII_H

#include "manna-connection.h"
#include "manna-handler.h"

namespace manna {
	class api_interface
	{
		public:
			virtual handle getHandler(std::string,std::string)=0;
	};
}

#endif // MANNAAPII_H
