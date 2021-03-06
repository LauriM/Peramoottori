#ifndef TEXTRESOURCE_H
#define TEXTRESOURCE_H

#include <resources\Resource.h>

namespace pm
{
	class TextResource : public Resource
	{
	public:
		TextResource();
		TextResource(std::string data);

		std::string getTextData();


		~TextResource();
	private:
		std::string textData;
	};
}
#endif //!TEXTRESOURCE_H

