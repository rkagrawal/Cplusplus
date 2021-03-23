#include <iostream>
#include <charconv> // from_chars, to_chars
#include <string>

int main()
{
    const std::string str { "A12345678" };
    int value = 0;
    const auto res = std::from_chars(str.data(),
                                     str.data() + str.size(),
                                     value);


    if (res.ec == std::errc())
    {
        std::cout << "value: " << value << ", distance: " << res.ptr - str.data() << '\n';
    }
    else if (res.ec == std::errc::invalid_argument)
    {
        std::cout << "invalid argument!\n";
    }
    else if (res.ec == std::errc::result_out_of_range)
    {
        std::cout << "out of range! res.ptr distance: " << res.ptr - str.data() << '\n';
    }


	double value2 = 0.0;
	const std::string str2 { "1234.567" };
	 auto fmt = std::chars_format::general;

	const auto res2 = std::from_chars(str2.data(),
                                 str2.data() + str2.size(),
                                 value2,
                                 fmt);

	std::cout << "Converted to double " << value2 << std::endl;
}


