#include "Serializer.hpp"

int main()
{
	Data data;
	data.test = 42;

	uintptr_t serializedData = Serializer::serialize(&data);
	cout << "ptr address: " << serializedData << endl; 

	Data *deserializedData = Serializer::deserialize(serializedData);
	cout << "data value: " << deserializedData->test << endl;

	return 0;
}