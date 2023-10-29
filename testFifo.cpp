#include "fifo.h"
using namespace std;

int main()
{

	arrayFifo<uint8_t> my_fifo(3, 3);  // initialises read pointer and write pointer to the 3rd element in the array

	for (int i = 0; i < MAX_FIFO_SIZE; i++)
	{
		cout << "current count = " << my_fifo.size() << endl;
		cout << "read pointer position = " << my_fifo.getRPtr() << endl;
		cout << "write pointer position = " << my_fifo.getWPtr() << endl;
		my_fifo.push_back(uint8_t(i));
	}
	cout << "final count = " << my_fifo.size() << endl;
	cout << "final fifo full = " << my_fifo.isFull() << endl;
	cout << endl;

	for (int i = 0; i < MAX_FIFO_SIZE; i++)
	{
		cout << "read pointer position = " << my_fifo.getRPtr() << endl;
		cout << "write pointer position = " << my_fifo.getWPtr() << endl;
		my_fifo.incrementReadPointer();
	}
	cout << "fifo size should now be 0 as rPtr should equal wPtr " << endl;
	cout << "final count = " << my_fifo.size() << endl;
	bool empty = true ? my_fifo.size() == 0 : false;
	cout << "final fifo empty = " << empty << endl;
	cout << "if I increment the read pointer by 1 once more, the fifo should be full" << endl;
	my_fifo.incrementReadPointer();
	cout << "final fifo full = " << my_fifo.isFull() << endl;

}
