#include "fifo.h"
using namespace std;

int main()
{

	arrayFifo<uint8_t> my_fifo(3, 3);  // initialises read pointer and write pointer to the 3rd element in the array

	for (int i = 0; i < MAX_FIFO_SIZE; i++)
	{
		cout << "current count = " << uint32_t(my_fifo.size()) << endl;
		cout << "read pointer position = " << uint32_t(my_fifo.getRPtr()) << endl;
		cout << "write pointer position = " << uint32_t(my_fifo.getWPtr()) << endl;
		my_fifo.push_back(uint8_t(i));
	}
	cout << "final count = " << uint32_t(my_fifo.size()) << endl;
	cout << "final array full = " << my_fifo.isFull() << endl;
	cout << endl;

	for (int i = 0; i < MAX_FIFO_SIZE + 1; i++)
	{
		cout << "read pointer position = " << uint32_t(my_fifo.getRPtr()) << endl;
		cout << "write pointer position = " << uint32_t(my_fifo.getWPtr()) << endl;
		my_fifo.incrementReadPointer();
	}
	cout << "array size should now be 0 as rPtr should equal wPtr " << endl;
	cout << "final count = " << uint32_t(my_fifo.size()) << endl;
	bool empty = true ? uint32_t(my_fifo.size()) == 0 : false;
	cout << empty << endl;

}
