#ifndef IMAGERESOURCE_H
#define IMAGERESOURCE_H

#include <resources\Resource.h>
#include <vector>

namespace pm
{
	class ImageResource : public Resource
	{
	public:
		ImageResource();
		ImageResource(std::vector<unsigned char> pixels);

		std::vector <unsigned char> getImageData();

		~ImageResource();
	private:
		std::vector <unsigned char> imageData;
	};
}
#endif //!IMAGERESOURCE_H

