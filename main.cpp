#include <iostream>

template <typename T>
class GenericArray {
	private:
		T *data;
		int length;
	public:
		//making the array constructor and deconstructor
		GenericArray()
		{
			data = nullptr;
			length = 0;
		}

		~GenericArray()
		{
			delete[] data;
		}

		//making the array and populating the data
		void addElement(T param)
		{
			T *result = new T[length + 1];
				for(int i = 0;i < length;i++)
				{
					result[i] = data[i];
				}
			result[length] = param;
			delete[] data;
			data = result;
			length++;
		}

		//making sure the paramaters is not out of bounds
		T at(int param)
		{
			if( param < 0 || param >= length)
			{
				std::cout << "ERROR" << std::endl;
				return 0;
			}
			return data[param];

		}

		//returns size
		int size()
		{
			return length;
		}

		//returns sum
		T sum()
		{
			T total = 0;
			for(int i = 0; i < length;i++)
			{
				total += data[i];
			}
			return total;
		}

		//returns max
		T max()
		{
			T largest = data[0];
				for(int i = 0;i < length;i++)
				{
					if(data[i] > largest)
					{
						largest = data[i];
					}
				}
			return largest;
		}

		//returns min
		T min()
		{
			T smallest = data[0];
			for(int i = 0;i < length;i++)
			{
				if(data[i] < smallest)
				{
					smallest = data[i];
				}
			}
			return smallest;
		}

		//making that slice and error for wrong size and bound check
		T *slice(int begin, int end)
		{
			if(begin < 0 || end >= length || begin > end)
			{
				std::cout << "ERROR" << std::endl;
					return nullptr;
			}
			int newSize = end - begin + 1;
			T *result = new T[newSize];
				for(int i = 0;i < newSize;i++)
				{
					result[i] = data[begin + i];
				}
			return result;
		}
};

int main()
{
	//populating the array with data
	GenericArray<int> int_array;
	for(int i = 0;i < 11;i++)
	{
		int_array.addElement(i*16);
	}

	//outputing the data
	std::cout << "Size is: " << int_array.size() << std::endl;
	std::cout << "Sum is: " << int_array.sum() << std::endl;
	std::cout << "Maximum is: " << int_array.max() << std::endl;
	std::cout << "Minimum is: " << int_array.min() << std::endl;

	//printing the sliced array
	int *sliced_array = int_array.slice(5,10);
	std::cout << "Sliced is: ";
	for(int i = 0;i < 6;i++)
	{
		std::cout << sliced_array[i] << " ";
	}
	std::cout << std::endl;

	delete[] sliced_array;
	return 0;
}
