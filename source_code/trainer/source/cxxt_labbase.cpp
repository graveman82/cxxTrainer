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
		for (uint32_t i = 0; i < kMaxCases; ++i)
		{
			m_iCases[i] = false;
		}
	}

	TestBase::~TestBase()
	{

	}

	int32_t TestBase::addCase(uint32_t caseIndex)
	{
		if (caseIndex >= kMaxCases)
			return kTooBigCaseIndex;
		m_iCases[caseIndex] = true;
		return kOk;
	}

	std::ostream& TestBase::printFullName(std::ostream& ostr)
	{
		ostr << "Test(" << m_iPack << ", " << m_index << ", " << m_iCurrentCase << ", \"" << getName() << "\")";
		return ostr;
	}

	int32_t TestBase::run(uint32_t caseIndex)
	{
		if (caseIndex >= kMaxCases)
			return kTooBigCaseIndex;

		if (!m_iCases[caseIndex])
			return cxxt::kCaseNotFound;
		
		m_iCurrentCase = caseIndex;

		outputHeader();
		int32_t retVal = runImpl();
		outputFooter();
		return retVal;
	}

	void TestBase::outputHeader()
	{
		std::cout << "*********************************************************************\n";
		printFullName(std::cout) << " was started.\n";
		std::cout << "Desc:" << getDesc() << "\n";
		std::cout << "*********************************************************************\n";
		std::cout << std::endl;
	}

	void TestBase::outputFooter()
	{
		std::cout << "*********************************************************************\n";
		printFullName(std::cout) << " was finished.\n";
		std::cout << "*********************************************************************\n";
		std::cout << std::endl;
	}
} // eof cxxt