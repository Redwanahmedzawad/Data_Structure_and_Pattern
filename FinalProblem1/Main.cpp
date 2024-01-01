
// COS30008, Final Exam, 2023

#include <iostream>

//#define P1
//#define P2
#define P3
//#define P4

#ifdef P1

#include "List.h"

void testP1()
{
    using StringList = List<std::string>;

    StringList lList;

    std::cout << "Test list Destructor:" << std::endl;

    lList.push_back( "DDDD" );
    lList.push_front( "CCCC" );
    lList.push_back( "EEEE" );
    lList.push_front( "BBBB" );
    lList.push_back( "FFFF" );
    lList.push_front( "AAAA" );

    for ( auto& item : lList )
    {
        std::cout << item << std::endl;
    }

    std::cout << "End of scope, free lList:" << std::endl;
}

#endif

#ifdef P2

#include "TernaryTree.h"
#include <string>

void testP2()
{
    using TTree = TernaryTree<std::string>;
    using TTreeNode = typename TTree::Node;

    std::cout << "Test TTree:" << std::endl;

    std::string lB( "B" );

    TTreeNode nA = TTree::makeNode( "A" );
    TTreeNode nB = TTree::makeNode( lB );
    TTreeNode nC = TTree::makeNode( std::string( "C" ) );
    TTreeNode nD = TTree::makeNode( "D" );

    nC->add( 2, nD );
    nB->add( 0, nC );
    nA->add( 1, nB );

    if ( !nC )
    {
        std::cout << "Ownership control sound." << std::endl;
    }
    else
    {
        std::cout << "Ownership control broken." << std::endl;
    }

    TTreeNode& root = nA;

    std::cout << "root:\t\t" << **root << std::endl;
    std::cout << "root[1]:\t" << *(*root)[1] << std::endl;
    std::cout << "root[1][0]:\t" << *(*root)[1][0] << std::endl;
    std::cout << "root[1][0][2]:\t" << *(*root)[1][0][2] << std::endl;

    std::cout << "height of root: " << root->height() << std::endl;
    (*root)[1][0].remove( 2 );
    std::cout << "height of root: " << root->height() << std::endl;

    std::cout << "TTree test complete." << std::endl;
}

#endif

#ifdef P3

#include "DSPString.h"

void testP3()
{
    std::cout << "Test DSPString:" << std::endl;

    DSPString lS1;
    DSPString lS2( "Problem 3" );

    std::cout << "S1: \'" << lS1 << "\'" << std::endl;
    std::cout << "S2: \'" << lS2 << "\'" << std::endl;

    DSPString lS3 = lS2;
    lS1 = lS2;

    std::cout << "S1: \'" << lS1 << "\'" << std::endl;
    std::cout << "S3: \'" << lS3 << "\'" << std::endl;

    DSPString lS4 = std::move( lS2 );
    lS1 = std::move( lS3 );

    std::cout << "S1: \'" << lS1 << "\'" << std::endl;
    std::cout << "S4: \'" << lS4 << "\'" << std::endl;

    if ( !(lS3 == lS4) || lS4 == lS2 )
    {
        std::cout << "There is something wrong." << std::endl;
    }
    else
    {
        std::cout << "String comparison correct." << std::endl;
    }

    std::cout << "DSPString test complete." << std::endl;
}

#endif

#ifdef P4

#include "DSPStringIterator.h"

void testP4()
{
    std::cout << "Test DSPString iterator:" << std::endl;

    DSPString lString( "Glenelg" );

    std::cout << "Forward iteration: ";

    for ( char c : DSPStringIterator( lString ) )
    {
        std::cout << c;
    }

    std::cout << std::endl;


    std::cout << "Backwards iteration: ";

    DSPStringIterator iter = DSPStringIterator( lString ).rbegin();

    for ( ; iter != iter.rend(); --iter )
    {
        std::cout << *iter;
    }

    std::cout << std::endl;

    std::cout << "DSPString complete test complete." << std::endl;
}

#endif

int main()
{
#ifdef P1

	testP1();

#endif

#ifdef P2

    testP2();

#endif

#ifdef P3

    testP3();

#endif

#ifdef P4

    testP4();

#endif

	return 0;
}
