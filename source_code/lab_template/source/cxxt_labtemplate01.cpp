// cxxt headers
#include "lab_template/include/cxxt_labtemplate01.h"

// standard headers
#include <iostream>

namespace cxxt_labtmpl01
{
	namespace pack1
	{
		class Test1 : public cxxt::TestBase
		{
		public:
			Test1(const char* name = nullptr,
				const char* desc = nullptr)
				: TestBase(name, desc)
			{
;				setIndex(1);
				setPack(1);
			}

			virtual ~Test1() {}

			int32_t runImpl() override
			{
				printFullName(std::cout) << ": Hello from lab tmpl 01" << std::endl;
				return cxxt::kOk;
			}
		};
	} // eof pack1

	int32_t Lab::run(uint32_t packIndex, uint32_t testIndex, uint32_t caseIndex)
	{
		if (1 == packIndex)
		{
			if (1 == testIndex)
			{
				pack1::Test1 test("lab templ 01 hello test", "no details for this test");
				// add cases
				int32_t retVal = test.addCase(17);
				if (retVal != cxxt::kOk)
					return retVal;
				// launch test
				return test.run(caseIndex);
			}
			return cxxt::kTestNotFound;
		}
		return cxxt::kPackNotFound;
	}
	
} // eof cxxt_labtmpl01