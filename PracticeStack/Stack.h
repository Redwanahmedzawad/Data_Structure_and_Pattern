
// COS30008: Tutorial 9, 2023

#pragma once

#include <optional>
#include <cassert>

template<typename T>
class Stack
{
private:
    T* fElements;
    size_t fStackPointer;
    size_t fCurrentSize;

	    
    void resize(size_t aNewSize)
    {
        assert(fStackPointer <= aNewSize);
        T* lNewElements = new T [aNewSize];
        for (size_t i = 0; i < fCurrentSize; i++)
        {
            lNewElements[i] = std::move(fElements[i]);
        }
        delete[]fElements;
        fElements = lNewElements;
        fCurrentSize = aNewSize;
    }
    void ensure_capacity() {
        if (fStackPointer == fCurrentSize)
        {
            resize(fCurrentSize * 2);
        }
    }
    void adjust_capacity()
    {
        if (fStackPointer <= (fCurrentSize / 4))
        {
            resize(fCurrentSize / 2);
        }
    }


    
public:

	
    Stack() :
        fElements(new T[1]),
        fStackPointer(0),
        fCurrentSize(1)
    {};
    ~Stack() {
        delete[]fElements;
    }



	
    Stack(const Stack& aOther):
        fElements(new T[aOther.fCurrentSize]),
        fStackPointer(aOther.fStackPointer),
        fCurrentSize(aOther.fCurrentSize)
    {
        assert(fStackPointer <= fCurrentSize);
        for (size_t i = 0; i < aOther.fCurrentSize; i++)
        {
            fElements[i] = aOther.fElements[i];
        }

    }
    
    Stack& operator=(const Stack<T>& aOther)
    {
        if (this != &aOther)
        {
            this->~Stack();
            new (this) Stack(aOther);
        }
        return *this;
    }


    Stack(Stack<T>&& aOther) noexcept:
        Stack()
    {
        swap(aOther);
    }
    
    Stack& operator=(Stack<T>&& aOther) noexcept
    {
        if (this != &aOther)
        {
            swap(aOther);
        }
        return *this;
    }

    void swap(Stack& aOther) noexcept
    {
        std::swap(fElements, aOther.fElements);
        std::swap(fStackPointer, aOther.fStackPointer);
        std::swap(fCurrentSize, aOther.fCurrentSize);
    }

	  
    size_t size() const noexcept
    {
        return fStackPointer;
    }
    
    std::optional<T> top() noexcept
    {
        if (fStackPointer > 0)
        {
            return std::optional<T>(fElements[fStackPointer-1]);
        }
        else {
            return std::optional<T>();
        }
    }

    void push(const T& aValue)
    {
        ensure_capacity();
        fElements[fStackPointer++] = aValue;
        
    }

	
    template<typename... Args>
    void emplace(Args&&... args)
    {
        ensure_capacity();
        fElements[fStackPointer].~T();
        new(&fElements[fStackPointer++])T(std::forward<Args>(args)...);
    }


	
    void pop()
    {
        assert(fStackPointer > 0);
            fStackPointer--;
            adjust_capacity();
        
    }
	

};
