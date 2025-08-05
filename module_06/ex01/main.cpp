#include "Serializer.hpp"
#include <cassert>

int main()
{
	Data data = {42};
	assert(&data == Serializer::deserialize(Serializer::serialize(&data)));
}
