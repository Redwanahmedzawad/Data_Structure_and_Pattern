#pragma once
#include <stdexcept>
#include <algorithm>
template<typename T>
class TernaryTreePrefixIterator;
template<typename T>
class TernaryTree
{
public:
	using TTree = TernaryTree<T>;
	using TSubTree = TTree*;
private:
	T fKey;
	TSubTree fSubTrees[3];
	// private default constructor used for declaration of NIL
	TernaryTree() :
		fKey(T())
	{
		for (size_t i = 0; i < 3; i++)
		{
			fSubTrees[i] = &NIL;
		}
	}
public:
	using Iterator = TernaryTreePrefixIterator<T>;
	static TTree NIL; // sentinel
	// getters for subtrees
	const TTree& getLeft() const { return *fSubTrees[0]; }
	const TTree& getMiddle() const { return *fSubTrees[1]; }
	const TTree& getRight() const { return *fSubTrees[2]; }
	// add a subtree
	void addLeft(const TTree& aTTree) { addSubTree(0, aTTree); }
	void addMiddle(const TTree& aTTree) { addSubTree(1, aTTree); }
	void addRight(const TTree& aTTree) { addSubTree(2, aTTree); }
	// remove a subtree, may through a domain error
	const TTree& removeLeft() { return removeSubTree(0); }
	const TTree& removeMiddle() { return removeSubTree(1); }
	const TTree& removeRight() { return removeSubTree(2); }
	// Problem 1: TernaryTree Basic Infrastructure
private:
	// remove a subtree, may throw a domain error [22]
	const TTree& removeSubTree(size_t aSubtreeIndex)
	{
		if (fSubTrees[aSubtreeIndex] == &NIL)
		{
			throw domain_error("Your Domain is in error");
		}
		const TTree& lref = const_cast<TTree&>(*fSubTrees[aSubtreeIndex]);
		fSubTrees[aSubtreeIndex] = &NIL;
		return lref;
	}
	// add a subtree; must avoid memory leaks; may throw domain error [18]
	void addSubTree(size_t aSubtreeIndex, const TTree& aTTree)
	{
		if (aSubtreeIndex > 2)
		{
			throw domain_error("Array Overflow");
		}
		if (fSubTrees[aSubtreeIndex] != &NIL)
		{
			throw domain_error("Node is not empty");
		}
		fSubTrees[aSubtreeIndex] = const_cast<TTree*>(&aTTree);
	}
public:
	// TernaryTree l-value constructor [10]
	TernaryTree(const T& aKey):
		fKey(aKey)
	{
		for (size_t i = 0; i < 3; i++)
		{
			fSubTrees[i] = &NIL;
		}
	}
	// destructor (free sub-trees, must not free empty trees) [14]
	~TernaryTree()
	{
		if (!empty())
		{

			for (size_t i = 0; i < 3; i++)
			{
				if (!fSubTrees[i]->empty()) {
					delete fSubTrees[i];
				}
			}
		}
	}
	// return key value, may throw domain_error if empty [6]
	const T& operator*() const
	{
		if (empty())
		{
			throw domain_error("Key is null");
		}
		return fKey;
	}
	// returns true if this ternary tree is empty [4]
	bool empty() const
	{
		return this == &NIL;
	}
	// returns true if this ternary tree is a leaf [10]
	bool leaf() const
	{
		for (size_t i = 0; i < 3; i++)
		{
			if (fSubTrees[i] != &NIL)
			{
				return false;
			}
		}
		return true;
	}
	// return height of ternary tree, may throw domain_error if empty [48]
	size_t height() const
	{
		if (empty())
		{
			throw domain_error("Empty tree");
		}
		if (leaf())
		{
			return 0;
		}
		size_t maxSubtree = 0;
		for (int i = 0; i < 3; ++i)
		{
			if (fSubTrees[i])
			{
				size_t subtreeHeight = fSubTrees[i]->height();
				maxSubtree = std::max(maxSubtree, subtreeHeight);
			}
		}
		return 1 + maxSubtree;

	}
	/////////////////////////////////////////////////////////////////////////
	// Problem 2: TernaryTree Copy Semantics
	// copy constructor, must not copy empty ternary tree [10]
	TernaryTree(const TTree& aOtherTTree)
	{
		if (!aOtherTTree.empty())
		{
			
			for (size_t i = 0; i < 3; i++)
			{
				
					fSubTrees[i] =&NIL;
				
			}
			*this = aOtherTTree;
		}
	}
	// copy assignment operator, must not copy empty ternary tree
	// may throw a domain error on attempts to copy NIL [36]
	TTree& operator=(const TTree& aOtherTTree)
	{
		if (this != &aOtherTTree)
		{
			if (!aOtherTTree.empty())
			{
				this->~TernaryTree();
				fKey = aOtherTTree.fKey;
				for (size_t i = 0; i < 3; i++)
				{
					if (!aOtherTTree.fSubTrees[i]->empty())
					{
						fSubTrees[i] = aOtherTTree.fSubTrees[i]->clone();
					}
					else {
						fSubTrees[i] = &NIL;
					}
				}
			}
			else {
				throw domain_error("Empty");
			}
		}
		return *this;

	}
	// clone ternary tree, must not copy empty trees [10]
	TSubTree clone() const
	{
		if (empty())
		{
			throw domain_error("Empty");
		}
		return new TTree(*this);
	}
	/////////////////////////////////////////////////////////////////////////
	// Problem 3: TernaryTree Move Semantics
	// TTree r-value constructor [12]
	TernaryTree(T&& aKey) :
		fKey(std ::move( aKey))
	{
		for (size_t i = 0; i < 3; i++)
		{
			fSubTrees[i] = &NIL;
		}
	}
	



	// move constructor, must not copy empty ternary tree [12]
	TernaryTree(TTree&& aOtherTTree)
	{

	
				for (size_t i = 0; i < 3; i++)
				{
					fSubTrees[i] = &NIL;
				}
				*this = move(aOtherTTree);

	}
	// move assignment operator, must not copy empty ternary tree [36]
	TTree& operator=(TTree&& aOtherTTree)
	{
		if (this != &aOtherTTree)
		{
			if (!aOtherTTree.empty())
			{
				this->~TernaryTree();
				fKey = std::move(aOtherTTree.fKey);
				for (size_t i = 0; i < 3; i++)
				{
					if (!aOtherTTree.fSubTrees[i]->empty())
					{
						fSubTrees[i] = const_cast<TSubTree>(&aOtherTTree.removeSubTree(i));
					}
					else {
						fSubTrees[i] = &NIL;
					}
				}
			}
			else
			{
				throw domain_error("NIL");
			}
		}
	}
	/////////////////////////////////////////////////////////////////////////
	// Problem 4: TernaryTree Prefix Iterator
	// return ternary tree prefix iterator positioned at start [4]
	Iterator begin() const
	{
		return Iterator(this).begin();
	}
	// return ternary prefix iterator positioned at end [6]
	Iterator end() const
	{
		return Iterator(this).end();
	}
};
template<typename T>
TernaryTree<T> TernaryTree<T>::NIL;