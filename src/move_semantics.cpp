#include <iostream>
#include <algorithm>
#include <vector>

class A
{
    size_t mLength;
    int *mData;

public:
    // simple constructor that initializes the resource.
    explicit A(size_t length) : mLength(length), mData(new int[length])
    {
        std::cout << "A(size_t).length = " << mLength << "." << std::endl;
    }

    // Destructor
    ~A()
    {
        std::cout << "~A().length = " << mLength << ".";
        if (mData != nullptr)
        {
            std::cout << "Deleting resource.";
            delete[] mData;
        }
        std::cout << std::endl;
    }

    // Copy constructor
    A &operator=(const A &other)
    {
        std::cout << "operator=(const A&).length = " << other.mLength << ". Copying resource." << std::endl;
        if (this != &other)
        {
            delete[] mData; // Free he existing resource.
            mLength = other.mLength;
            mData = new int[mLength];
            std::copy(other.mData, other.mData + mLength, mData);
        }
        return *this;
    }

    // Move constructor
    A(A &&other) : mData(nullptr), mLength(0)
    {
        std::cout << "A(A&&).length = " << other.mLength << ". Moving resource." << std::endl;
        // Copy the data pointer and its length from the source object.
        mData = other.mData;
        mLength = other.mLength;

        // Release the data pointer from the source object so that the destructor does not free the memory multiple times.
        other.mData = nullptr;
        other.mLength = 0;
    }

    // Move assignment operator
    A &operator=(A &&other)
    {
        std::cout << "operator=(A&&).length = " << other.mLength << "." << std::endl;
        if (this != &other)
        {
            // Free the existing resource
            delete[] mData;
            // Copy the data pointer and its length from the source object.
            mData = other.mData;
            mLength = other.mLength;

            // Release the data pointer and its length from the source object.
            other.mData = nullptr;
            other.mLength = 0;
        }
        return *this;
    }
    size_t Length() const
    {
        return mLength;
    }

    void swap(A &other)
    {
        A temp = std::move(other);
        other = std::move(*this);
        *this = std::move(temp);
    }

    int *get_mData()
    {
        return mData;
    }

    size_t getLength() { return mLength; }
};

int main()
{
    A a(11), b(22);
    std::cout << a.getLength() << " " << b.getLength() << std::endl;
    std::cout << a.get_mData() << " " << b.get_mData() << std::endl;
    a.swap(b);
    std::cout << a.getLength() << " " << b.getLength() << std::endl;
    std::cout << a.get_mData() << " " << b.get_mData() << std::endl;
    return 0;
}