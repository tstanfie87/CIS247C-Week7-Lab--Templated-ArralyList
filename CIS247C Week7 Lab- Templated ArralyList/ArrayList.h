#pragma once

template <class T>
class ArrayList
{
private:
	// attributes
	const static int DEFAULT_SIZE = 5;	// constant for the initial size
	T* list;							// pointer to the array
	int count;							// number of items in the list
	int capacity;						// current size in memory

public:
	// constructors
	ArrayList(void)
	{
		this->list = new T[DEFAULT_SIZE];
		this->capacity = DEFAULT_SIZE;
		this->count = 0;
	}

	ArrayList(int initialCapacity)
	{
		this->list = new T[initialCapacity];
		this->capacity = initialCapacity;
		this->count = 0;
	}

	// destructor
	~ArrayList(void)
	{
		if (this->list != nullptr)
		{
			delete[] this->list;
			this->list = nullptr;
		}
	}

	/// Determine if the Arraylist is empty
	bool isEmpty(void)
	{
		return count == 0;		// array is empty if it has zero items
	}

	/// Get the item at the given position
	T get(int position)
	{
		if (position < count)
			return list[position];
		else
			return NULL;
		
	}

	/// Add an item to the ArrayList
	void add(T data)
	{
		if (count==capacity)
		{
			// create bigger array
			capacity = 2 * capacity;
			T* temp = new T[capacity];

			// copy items from current array to bigger array
			for (int i = 0; i < count; i++)
			{
				temp[i] = list[i];
			}

			// delete the current array
			delete[] list;

			// rename the bigger array to the current array name
			list = temp;
		}

		// add the data item to the array
		list[count] = data;

		// increment the count
		count++;
	}

	/// Remove item at the given position
	void removeAt(int position)
	{
		// replace every item from theat position on the next item
		for (int i = position; i < count; i++)	// notice "count - 1" to copy last item to next to last position
		{
			list[i] = list[i + 1];
		}

		// decrease the item count
		count--;
	}

	/// Get the count of items in the ArrayList
	int getCount(void)
	{
		return count;
	}

	/// Get the ArrayList current capacity
	int getCapacity()
		{
			return capacity;
		}
	

};
