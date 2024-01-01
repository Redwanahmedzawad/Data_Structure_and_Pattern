#pragma once

#include <ostream>

class DSPString
{
private:

    // 3a
    char* fContents;
    size_t fSize;

public:

    DSPString(const char* aContents = "\0");

    ~DSPString();

    // copy semantics
    DSPString(const DSPString& aOther);
    DSPString& operator=(const DSPString& aOther);

    // move semantics
    DSPString(DSPString&& aOther) noexcept;
    DSPString& operator=(DSPString&& aOther) noexcept;

    // 3b
    size_t size() const noexcept;
    char operator[](size_t aIndex) const noexcept;

    bool operator==(const DSPString& aOther) const noexcept;

    friend std::ostream& operator<<(std::ostream& aOStream,
        const DSPString& aObject);
};