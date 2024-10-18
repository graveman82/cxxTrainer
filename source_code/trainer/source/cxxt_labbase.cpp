#include "trainer/include/cxxt_labbase.h"

// standard headers
#include <iostream>

namespace cxxt
{
	TestBase::TestBase(const char* name,
		const char* desc)
		: m_name(name)
		, m_desc(desc)
	{

	}

	TestBase::~TestBase()
	{

	}

	int32_t TestBase::run()
	{
		outputHeader();
		int32_t retVal = runImpl();
		outputFooter();
		return retVal;
	}

	std::ostream& TestBase::printNameAsPrefix()
	{
		std::cout << "Test(case " << m_iCase << ")  \"" << getName() << "\": ";
		return std::cout;

	}

	void TestBase::outputHeader()
	{
		std::cout << "*********************************************************************\n";
		std::cout << "Test(case " << m_iCase << ")  \"" << getName() << "\" was started.\n";
		std::cout << "Desc:" << getDesc() << "\n";
		std::cout << "*********************************************************************\n";
		std::cout << std::endl;
	}

	void TestBase::outputFooter()
	{
		std::cout << "*********************************************************************\n";
		std::cout << "Test(case " << m_iCase << ")  \"" << getName() << "\" was finished.\n";
		std::cout << "*********************************************************************\n";
		std::cout << std::endl;
	}
} // eof cxxt